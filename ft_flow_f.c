#include "ft_printf.h"
#include <stdint.h>
#include <stdio.h>

void    float_out_put(fldd digit, t_printf *base)
{
    printf("%f", digit.f);
}
void    double_out_put(fldd digit, t_printf *base)
{
    printf("%f", digit.d);
}
void    long_double_out_put(fldd digit, t_printf *base)
{
    printf("%f", digit.ld);
}


void    out_put_flow(t_printf *base)
{
    int         i;
    int         etalon;
    fldd        record;
    t_unioner tupo_funcout_put[] =
            {
                    {0 , float_out_put},
                    {F_LONG2, double_out_put},
                    {F_LONG2, long_double_out_put}
            };

    i = 0;
    base->negnum = 0;
    if (base->length & F_LONG || base->length & F_LONG2)
        (base->length & F_LONG2) ? (record.d = ((double)va_arg(base->first_arg, double))) : \
        (record.ld = ((long double)va_arg(base->first_arg,  long double)));
    else
        ((record.f = (float)va_arg(base->first_arg, float)));
    etalon = (int)(sizeof(tupo_funcout_put)/ sizeof(tupo_funcout_put[0]));
    while (++i < etalon)
        if (base->length == tupo_funcout_put[i].out_put_function)
            tupo_funcout_put[i].fn(record, base);
}