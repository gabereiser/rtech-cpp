#include <common.h>
#include <math/quaternion.h>

namespace rtech
{
namespace math
{
API inline const Quaternion Quaternion::operator*(const Quaternion& q) const
{
    Quaternion result(*this);
    result.multiply(q);
    return result;
}

API inline Quaternion& Quaternion::operator*=(const Quaternion& q)
{
    multiply(q);
    return *this;
}

}
}