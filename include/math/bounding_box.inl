#include <common.h>
#include <math/bounding_box.h>

namespace rtech
{
namespace math
{
API inline BoundingBox& BoundingBox::operator*=(const Matrix& matrix)
{
    transform(matrix);
    return *this;
}

API inline const BoundingBox operator*(const Matrix& matrix, const BoundingBox& box)
{
    BoundingBox b(box);
    b.transform(matrix);
    return b;
}

}
}