#pragma once

namespace rtech
{
    template <typename T>
    class Singleton
    {
        public:
        static T& instance() { 
            static T _instance;
            return _instance;
        }
        Singleton<T>(Singleton<T> const&) = delete;             // Copy construct
        Singleton<T>(Singleton<T>&&) = delete;                  // Move construct
        Singleton<T>& operator=(Singleton<T> const&) = delete;  // Copy assign
        Singleton<T>& operator=(Singleton<T> &&) = delete;      // Move assign

        protected:
        Singleton<T>() {}

        virtual ~Singleton<T>() {}

    };
}