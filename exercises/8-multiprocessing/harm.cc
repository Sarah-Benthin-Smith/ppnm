#include "harm.h"

void harm(data& args)
{
    int a = args.a;
    int b = args.b;

    double sum = 0.0;

    for(int i = a; i < b; i++)
        sum += 1.0 / i;

    args.sum = sum;
}