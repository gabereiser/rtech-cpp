#include <common.h>
#include <math/math_helper.h>

namespace rtech
{
namespace math
{
void MathHelper::smooth(float* x, float target, float elapsedTime, float responseTime)
{
    ASSERT(x);

    if (elapsedTime > 0)
    {
        *x += (target - *x) * elapsedTime / (elapsedTime + responseTime);
    }
}

void MathHelper::smooth(float* x, float target, float elapsedTime, float riseTime, float fallTime)
{
    ASSERT(x);
    
    if (elapsedTime > 0)
    {
        float delta = target - *x;
        *x += delta * elapsedTime / (elapsedTime + (delta > 0 ? riseTime : fallTime));
    }
}

}
}