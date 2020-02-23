#include <common.h>
#include <math/ray.h>

namespace rtech
{
namespace math
{
API inline Ray& Ray::operator*=(const Matrix& matrix)
{
    transform(matrix);
    return *this;
}

API inline const Ray operator*(const Matrix& matrix, const Ray& ray)
{
    Ray r(ray);
    r.transform(matrix);
    return r;
}

}
}