#include <common.h>
#include <math/plane.h>

namespace rtech
{
namespace math
{
API inline Plane& Plane::operator*=(const Matrix& matrix)
{
    transform(matrix);
    return *this;
}

API inline const Plane operator*(const Matrix& matrix, const Plane& plane)
{
    Plane p(plane);
    p.transform(matrix);
    return p;
}

}
}