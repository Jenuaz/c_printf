#include "ft_printf.h"

void    extract_exponent_f(t_custom_f *digit, t_printf *base)
{
    int     deep;
    int     tmp_d;

    deep = 0;
    (base->precision > 0 || base->precision == -1) ? (tmp_d = (int)digit->src.f) : (tmp_d = roundcustomf(digit->src.f));
    while (tmp_d > 0)
    {
        (tmp_d % 2 == 1) ? (digit->exponent |= (1 << deep)) : 0;
        tmp_d = tmp_d >> 1;
        deep++;
    }
    deep = 0;
    tmp_d = roundcustomf(digit->src.f);
    while (tmp_d > 0)
    {
        tmp_d = tmp_d / 10;
        deep++;
    }
}

void    extract_exponent_d(t_custom_f *digit, t_printf *base)
{
    int     deep;
    int     tmp_d;

    deep = 0;
    (base->precision > 0 || base->precision == -1) ? (tmp_d = (int)digit->src.d) : (tmp_d = roundcustomd(digit->src.d));
    while (tmp_d > 0)
    {
        (tmp_d % 2 == 1) ? (digit->exponent |= (1 << deep)) : 0;
        tmp_d = tmp_d >> 1;
        deep++;
    }
    deep = 0;
    tmp_d = roundcustomd(digit->src.d);
    while (tmp_d > 0)
    {
        tmp_d = tmp_d / 10;
        deep++;
    }
}

void    extract_exponent_ld(t_custom_f *digit, t_printf *base)
{
    int     deep;
    int     tmp_d;

    deep = 0;
    (base->precision > 0 || base->precision == -1) ? (tmp_d = (int)digit->src.ld) : (tmp_d = roundcustomd(digit->src.ld));
    while (tmp_d > 0)
    {
        (tmp_d % 2 == 1) ? (digit->exponent |= (1 << deep)) : 0;
        tmp_d = tmp_d >> 1;
        deep++;
    }
    deep = 0;
    tmp_d = roundcustomd(digit->src.ld);
    while (tmp_d > 0)
    {
        tmp_d = tmp_d / 10;
        deep++;
    }
}