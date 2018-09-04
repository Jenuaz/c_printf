#include "ft_printf.h"

void    ft_oct_precision(t_printf *base, unsigned long long num)
{
    int sharp;
    int prec;

    prec = base->precision - counthex(num, 8);
    (base->flag & F_SHARP) ? (sharp = 2) : (sharp = 0);
//    if (base->width >= base->precision)
//    {
//        if (num != 0)
//            base->width -= base->precision + sharp;
//    }
    while (!(base->flag & F_MINUS) && base->width-- && base->width >= 0)
        if (base->width >= base->precision)
            ft_put_count(' ', base);
    (base->flag & F_SHARP) && base->heigh ? ft_putstr_count("0X", base) : 0;
    (base->flag & F_SHARP) && !base->heigh ? ft_putstr_count("0x", base) : 0;
    while (prec-- && prec >= 0)
        ft_put_count('0', base);
    ft_hex(num, 8, base->heigh, base);
    while ((base->flag & F_MINUS) && base->width-- && base->width >= 0)
        ft_put_count(' ', base);
}

void    ft_go_oct(t_printf *base, unsigned long long num)
{
    int count;

    count = counthex(num,8);
    if (base->precision > count)
    {
        ft_oct_precision(base, num);
        return ;
    }
    (base->heigh) ? (base->width -= count + 1) : (base->width -= count);
    if (base->flag & F_ZERO)
    {
        (base->flag & F_SHARP) && base->heigh ? ft_putstr_count("0", base) : 0;
        (base->flag & F_SHARP) && !base->heigh ? ft_putstr_count("0", base) : 0;
    }
    if ( base->width > 0 && !(base->flag & F_MINUS))
        while (base->width-- && base->width >= 0)
            if ((base->flag & F_ZERO))
                ft_put_count('0', base);
            else
                ft_put_count(' ', base);
    if (!(base->flag & F_ZERO) && num != 0)
    {
        (base->flag & F_SHARP) && base->heigh ? ft_putstr_count("0", base) : 0;
        (base->flag & F_SHARP) && !base->heigh ? ft_putstr_count("0", base) : 0;
    }
    ft_hex(num, 8, base->heigh, base);
    if (base->width > 0 && (base->flag & F_MINUS))
        while (base->width-- && base->width >= 0)
            ft_put_count(' ', base);
}

void    ft_oct_out_put(t_printf *base)
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

    ft_go_oct(base, n);
}
