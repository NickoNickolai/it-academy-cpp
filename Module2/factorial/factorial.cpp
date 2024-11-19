#include "factorial.h"

proc_t Factorial::factorial( proc_t n )
{
    if( n == 1 )
    {
        return 1;
    }

    return n * factorial( n - 1 );
}
