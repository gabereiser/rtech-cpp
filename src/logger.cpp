#include <common.h>

namespace rtech
{
    extern void rprint(const char* format, ...) { 
            _ASSERT(format);
            va_list argptr;
            va_start(argptr, format);
            vfprintf(stderr, format, argptr);
            va_end(argptr);
    };
Logger::State Logger::_state[3];

Logger::State::State() : logFunctionC(NULL), enabled(true)
{
}

Logger::Logger()
{
}

Logger::~Logger()
{
}

void Logger::log(Level level, const char* message, ...)
{
    State& state = _state[level];
    if (!state.enabled)
        return;

    // Declare a moderately sized buffer on the stack that should be
    // large enough to accommodate most log requests.
    int size = 1024;
    char stackBuffer[1024];
    std::vector<char> dynamicBuffer;
    char* str = stackBuffer;
    for ( ; ; )
    {
        va_list args;
        va_start(args, message);

        // Pass one less than size to leave room for NULL terminator
        int needed = vsnprintf(str, size-1, message, args);

        // NOTE: Some platforms return -1 when vsnprintf runs out of room, while others return
        // the number of characters actually needed to fill the buffer.
        if (needed >= 0 && needed < size)
        {
            // Successfully wrote buffer. Added a NULL terminator in case it wasn't written.
            str[needed] = '\0';
            va_end(args);
            break;
        }

        size = needed > 0 ? (needed + 1) : (size * 2);
        dynamicBuffer.resize(size);
        str = &dynamicBuffer[0];

        va_end(args);
    }

    if (state.logFunctionC)
    {
        // Pass call to registered C log function
        (*state.logFunctionC)(level, str);
    }
    else
    {
        // Log to the default output
        rprint("%s", str);
    }
}

bool Logger::isEnabled(Level level)
{
    return _state[level].enabled;
}

void Logger::setEnabled(Level level, bool enabled)
{
    _state[level].enabled = enabled;
}

void Logger::set(Level level, void (*logFunction) (Level, const char*))
{
    State& state = _state[level];
    state.logFunctionC = logFunction;
}

}
