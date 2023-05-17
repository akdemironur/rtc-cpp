#include "RTCMatrix.h"
namespace RTC
{
bool operator==(const Matrix &a, const Matrix &b)
{
    if (!(a.numColumns() == b.numColumns() && a.numRows() == b.numRows()))
        return false;
    for (auto it1 = a.values().begin(), it2 = b.values().begin(); it1 != a.values().end() && it2 != b.values().end();
         ++it1, ++it2)
    {

        if (!approxEqual(*it1, *it2))
            return false;
    }
    return true;
}
bool operator!=(const Matrix &a, const Matrix &b)
{
    return !(a == b);
}
} // namespace RTC