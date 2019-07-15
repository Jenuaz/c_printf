#include "ft_printf.h"
#include <stdint.h>
#include <stdio.h>


void    ft_bzero_fldd(t_custom_f *digit)
{
    digit->exponent = 0;
    digit->mantisa = 0;
}

void    float_out_put(t_custom_f digit, t_printf *base)
{
    (digit.src.f < 0) ? (digit.sign = -1) : 0;
    extract_exponent_f(&digit, base);
    base->nbr_wd_len = counthex(digit.exponent, 10);
    (base->precision == -1) ? (digit.mantisa_length = 7) : (digit.mantisa_length = base->precision + 1);
    base->nbr_wd_len += digit.mantisa_length;
    (base->flag & F_PLUS) ? (base->nbr_wd_len++) : 0;
    extract_mantissa_f(&digit, base);
}
void    double_out_put(t_custom_f digit, t_printf *base)
{
    (digit.src.d < 0) ? (digit.sign = -1) : 0;
    extract_exponent_d(&digit, base);
    base->nbr_wd_len = counthex(digit.exponent, 10);
//    extract_exponent();
    printf("%lf", digit.src.d);
}
void    long_double_out_put(t_custom_f digit, t_printf *base)
{
    (digit.src.ld < 0) ? (digit.sign = -1) : 0;
  //  extract_exponent();
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
    ft_bzero_fldd(&record);
    if (base->length & F_LONG || base->length & F_LONG2)
        (base->length & F_LONG) ? (record.src.d = ((double)va_arg(base->first_arg, double))) : \
        (record.src.ld = va_arg(base->first_arg, double));
    else
        ((record.src.f = (float)va_arg(base->first_arg, double)));
    etalon = (int)(sizeof(tupo_funcout_put)/ sizeof(tupo_funcout_put[0]));
    while (++i < etalon)
        if (base->length == tupo_funcout_put[i].out_put_function) {
            tupo_funcout_put[i].fn(record, base);
            return ;
        }
}