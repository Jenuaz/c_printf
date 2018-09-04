#include "ft_printf.h"

void    ft_hex_precision(t_printf *base, unsigned long long num)
{
    int sharp;
    int prec;

    prec = base->precision - counthex(num, 16);
    (base->flag & F_SHARP) ? (sharp = 2) : (sharp = 0);
    if (base->width >= base->precision)
    {
        base->width -= base->precision + sharp;
    }
    while (!(base->flag & F_MINUS) && base->width-- && base->width >= 0)
        if (base->width >= base->precision)
            ft_put_count(' ', base);
    (base->flag & F_SHARP) && base->heigh ? ft_putstr_count("0X", base) : 0;
    (base->flag & F_SHARP) && !base->heigh ? ft_putstr_count("0x", base) : 0;
    while (prec-- && prec >= 0)
        ft_put_count('0', base);
    ft_hex(num, 16, base->heigh, base);
    while ((base->flag & F_MINUS) && base->width-- && base->width >= 0)
        ft_put_count(' ', base);
}

void    ft_go_hex(t_printf *base, unsigned long long num) {
    int count;

    count = counthex(num, 16);
    if (base->precision > count)
    {
        ft_hex_precision(base, num);
        return ;
    }
    (base->flag & F_SHARP) ? (base->width -= count + 2) : (base->width -= count);
    if (base->flag & F_ZERO)
    {
        (base->flag & F_SHARP) && base->heigh ? ft_putstr_count("0X", base) : 0;
        (base->flag & F_SHARP) && !base->heigh ? ft_putstr_count("0x", base) : 0;
    }
    if ( base->width > 0 && !(base->flag & F_MINUS)) {
        while (base->width-- && base->width >= 0)
            if ((base->flag & F_ZERO)) {
                ft_put_count('0', base);
            } else {
                ft_put_count(' ', base);
            }
    }
    if (!(base->flag & F_ZERO) && num != 0)
    {
        (base->flag & F_SHARP) && base->heigh ? ft_putstr_count("0X", base) : 0;
        (base->flag & F_SHARP) && !base->heigh ? ft_putstr_count("0x", base) : 0;
    }
    ft_hex(num, 16, base->heigh, base);
    if (base->width > 0 && (base->flag & F_MINUS))
        while (base->width-- && base->width >= 0)
            ft_put_count(' ', base);
}

void    ft_hex_out_put(t_printf *base)
{
    unsigned long long 	n;

    if (base->length & F_SIZE_T)
        n = (ssize_t)va_arg(base->first_arg, unsigned long long);
    else if (base->length & F_INTMAX)
        n = (uintmax_t)va_arg(base->first_arg, unsigned long long);
    else if (base->length & F_LONG2)
        n = va_arg(base->first_arg, unsigned long long);
    else if (base->length & F_LONG)
        n = (unsigned long)va_arg(base->first_arg, unsigned long long);
    else if (base->length & F_SHORT)
        n = (unsigned short)va_arg(base->first_arg, unsigned long long);
    else if (base->length & F_SHORT2)
        n = (unsigned char)va_arg(base->first_arg, unsigned long long);
    else
        n = (unsigned int)va_arg(base->first_arg, unsigned long long);

    ft_go_hex(base, n);
}

void    ft_convert(unsigned long long k, int big_spec, t_printf *base)
{
    if (k > 9 && big_spec== 1)
        ft_put_count(k + 55, base);
    else if (k > 9 && big_spec == 0)
        ft_put_count(k + 87, base);
    else
        ft_put_count(k + 48, base);
}

void    ft_hex(unsigned long long k, int sys, int b, t_printf *base)
{
    if (k > (unsigned long long)sys - 1)
        ft_hex(k / (unsigned long long)sys, sys, b, base);
    if (k < (unsigned long long)sys)
        ft_convert(k, b, base);
    else
        ft_convert(k % (unsigned long long)sys, b, base);
}

int        counthex(long long hex, int sys)
{
    int i;

    i = 0;
    while (hex > sys - 1)
    {
        hex = hex / sys;
        i++;
    }
    return (i + 1);
}