#include <iostream>
#include "sharedarray.h"

int main()
{
    const int n = 10;
#ifdef USE_MODERN_STANDARD
    auto arr = std::make_shared<int[]>(n);
#else
    std::shared_ptr<int[]> arr(new int[n]);
#endif
    SharedArray::fill(arr, n);
    SharedArray::print(arr, n);
    int mn = 0, mx = 0;
    SharedArray::min_max(arr, n, mn, mx);
    std::cout << "Sum = " << SharedArray::sum(arr, n)
              << ", min = " << mn << ", max = " << mx << std::endl;

    return 0;
}
