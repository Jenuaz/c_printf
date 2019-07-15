#include "ft_printf.h"

int roundcustomf(float num)
{
    return num < 0 ? num - 0.5 : num + 0.5;
}

int roundcustomd(float num)
{
    return num < 0 ? num - 0.5 : num + 0.5;
}

int    custom_pow(long long int digit, int degree)
{
    if (degree > 1)
        while (--degree)
            digit *= 10;
    return digit;
}
