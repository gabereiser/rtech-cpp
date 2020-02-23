#include <common.h>
#include <math/bounding_sphere.h>

namespace rtech
{
namespace math
{
API inline BoundingSphere& BoundingSphere::operator*=(const Matrix& matrix)
{
    transform(matrix);
    return *this;
}

API inline const BoundingSphere operator*(const Matrix& matrix, const BoundingSphere& sphere)
{
    BoundingSphere s(sphere);
    s.transform(matrix);
    return s;
}

}
}