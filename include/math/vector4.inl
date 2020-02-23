#include <common.h>
#include <math/matrix.h>
#include <math/vector4.h>

namespace rtech
{
namespace math
{
API inline const Vector4 Vector4::operator+(const Vector4& v) const
{
    Vector4 result(*this);
    result.add(v);
    return result;
}

API inline Vector4& Vector4::operator+=(const Vector4& v)
{
    add(v);
    return *this;
}

API inline const Vector4 Vector4::operator-(const Vector4& v) const
{
    Vector4 result(*this);
    result.subtract(v);
    return result;
}

API inline Vector4& Vector4::operator-=(const Vector4& v)
{
    subtract(v);
    return *this;
}

API inline const Vector4 Vector4::operator-() const
{
    Vector4 result(*this);
    result.negate();
    return result;
}

API inline const Vector4 Vector4::operator*(float x) const
{
    Vector4 result(*this);
    result.scale(x);
    return result;
}

API inline Vector4& Vector4::operator*=(float x)
{
    scale(x);
    return *this;
}

API inline const Vector4 Vector4::operator/(const float x) const
{
    return Vector4(this->x / x, this->y / x, this->z / x, this->w / x);
}

API inline bool Vector4::operator<(const Vector4& v) const
{
    if (x == v.x)
    {
        if (y == v.y)
        {
            if (z == v.z)
            {
                return w < v.w;
            }
            return z < v.z;
        }
        return y < v.y;
    }
    return x < v.x;
}

API inline bool Vector4::operator==(const Vector4& v) const
{
    return x==v.x && y==v.y && z==v.z && w==v.w;
}

API inline bool Vector4::operator!=(const Vector4& v) const
{
    return x!=v.x || y!=v.y || z!=v.z || w!=v.w;
}

API inline const Vector4 operator*(float x, const Vector4& v)
{
    Vector4 result(v);
    result.scale(x);
    return result;
}

}
}