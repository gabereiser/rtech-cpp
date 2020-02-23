#include <common.h>
#include <math/vector2.h>

namespace rtech
{
namespace math
{
API inline const Vector2 Vector2::operator+(const Vector2& v) const
{
    Vector2 result(*this);
    result.add(v);
    return result;
}

API inline Vector2& Vector2::operator+=(const Vector2& v)
{
    add(v);
    return *this;
}

API inline const Vector2 Vector2::operator-(const Vector2& v) const
{
    Vector2 result(*this);
    result.subtract(v);
    return result;
}

API inline Vector2& Vector2::operator-=(const Vector2& v)
{
    subtract(v);
    return *this;
}

API inline const Vector2 Vector2::operator-() const
{
    Vector2 result(*this);
    result.negate();
    return result;
}

API inline const Vector2 Vector2::operator*(float x) const
{
    Vector2 result(*this);
    result.scale(x);
    return result;
}

API inline Vector2& Vector2::operator*=(float x)
{
    scale(x);
    return *this;
}

API inline const Vector2 Vector2::operator/(const float x) const
{
    return Vector2(this->x / x, this->y / x);
}

API inline bool Vector2::operator<(const Vector2& v) const
{
    if (x == v.x)
    {
        return y < v.y;
    }
    return x < v.x;
}

API inline bool Vector2::operator==(const Vector2& v) const
{
    return x==v.x && y==v.y;
}

API inline bool Vector2::operator!=(const Vector2& v) const
{
    return x!=v.x || y!=v.y;
}

API inline const Vector2 operator*(float x, const Vector2& v)
{
    Vector2 result(v);
    result.scale(x);
    return result;
}

}
}