#include "uniquearray.h"

int main()
{
    const int n = 10;
    auto arr = std::make_unique<int[]>(n);
    UniqueArray::fill(arr, n);
    UniqueArray::print(arr, n);

    return 0;
}
