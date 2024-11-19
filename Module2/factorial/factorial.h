#ifndef FACTORIAL_H
#define FACTORIAL_H

#ifndef FLOAT_PROC
typedef int proc_t;
#else
typedef float proc_t;
#endif

class Factorial
{
public:
    proc_t factorial( proc_t n );
};

#endif // FACTORIAL_H
