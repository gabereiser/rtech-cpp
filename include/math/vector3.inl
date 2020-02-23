#include <common.h>
#include <math/vector3.h>
#include <math/matrix.h>

namespace rtech
{
namespace math
{
API inline const Vector3 Vector3::operator+(const Vector3& v) const
{
    Vector3 result(*this);
    result.add(v);
    return result;
}

API inline Vector3& Vector3::operator+=(const Vector3& v)
{
    add(v);
    return *this;
}

API inline const Vector3 Vector3::operator-(const Vector3& v) const
{
    Vector3 result(*this);
    result.subtract(v);
    return result;
}

API inline Vector3& Vector3::operator-=(const Vector3& v)
{
    subtract(v);
    return *this;
}

API inline const Vector3 Vector3::operator-() const
{
    Vector3 result(*this);
    result.negate();
    return result;
}

API inline const Vector3 Vector3::operator*(float x) const
{
    Vector3 result(*this);
    result.scale(x);
    return result;
}

API inline Vector3& Vector3::operator*=(float x)
{
    scale(x);
    return *this;
}

API inline const Vector3 Vector3::operator/(const float x) const
{
    return Vector3(this->x / x, this->y / x, this->z / x);
}

API inline bool Vector3::operator<(const Vector3& v) const
{
    if (x == v.x)
    {
        if (y == v.y)
        {
            return z < v.z;
        }
        return y < v.y;
    }
    return x < v.x;
}

API inline bool Vector3::operator==(const Vector3& v) const
{
    return x==v.x && y==v.y && z==v.z;
}

API inline bool Vector3::operator!=(const Vector3& v) const
{
    return x!=v.x || y!=v.y || z!=v.z;
}

API inline const Vector3 operator*(float x, const Vector3& v)
{
    Vector3 result(v);
    result.scale(x);
    return result;
}

}
}