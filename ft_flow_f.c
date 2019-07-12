#include "ft_printf.h"
#include <stdint.h>
#include <stdio.h>

//void    parse_float(t_custom_f *digit)
//{
//    while ()
//}

void    float_out_put(t_custom_f digit, t_printf *base)
{
    (digit.src.f < 0) ? (digit.sign = -1) : 0;
  //  parse_float(&digit);
    printf("%f", digit.src.f);
}
void    double_out_put(t_custom_f digit, t_printf *base)
{
    (void) base;
    printf("%lf", digit.src.d);
}
void    long_double_out_put(t_custom_f digit, t_printf *base)
{
    (void) base;
    printf("%Lf", digit.src.ld);
}



void    out_put_flow(t_printf *base)
{
    int         i;
    int         etalon;
    t_custom_f  record;
    t_unioner tupo_funcout_put[] =
            {
                    {0 , float_out_put},
                    {F_LONG, double_out_put},
                    {F_LONG2, long_double_out_put}
            };

    i = -1;
    base->negnum = 0;
    if (base->length & F_LONG || base->length & F_LONG2)
        (base->length & F_LONG2) ? (record.src.d = ((double)va_arg(base->first_arg, double))) : \
        (record.src.ld = ((long double)va_arg(base->first_arg,  long double)));
    else
        ((record.src.f = (float)va_arg(base->first_arg, double)));
    etalon = (int)(sizeof(tupo_funcout_put)/ sizeof(tupo_funcout_put[0]));
    while (++i < etalon)
        if (base->length == tupo_funcout_put[i].out_put_function) {
            tupo_funcout_put[i].fn(record, base);
            return ;
        }
}