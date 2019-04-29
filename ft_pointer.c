#include "ft_printf.h"



void    ft_pointer_hex(t_printf *base, unsigned long long num) {
    int count;

    count = counthex(num, 16);
    if (base->precision > count)
    {
        ft_hex_precision(base, num);
        return ;
    }
    if (base->flag & F_SHARP)
        base->width -= count + 2;
    else if (!(base->flag & F_SHARP))
        (base->precision != 0) ? base->width -= count : 0;
    if (base->flag & F_ZERO)
        base->heigh ? ft_putstr_count("0X", base) : ft_putstr_count("0x", base);
    if ( base->width > 0 && !(base->flag & F_MINUS)) {
        while (base->width-- && base->width >= 0)
            if ((base->flag & F_ZERO)) {
                ft_put_count('0', base);
            } else {
                ft_put_count(' ', base);
            }
    }
    if (!(base->flag & F_ZERO))
        base->heigh ? ft_putstr_count("0X", base) : ft_putstr_count("0x", base);
    if (base->precision != 0)
        ft_hex(num, 16, base->heigh, base);
    if (base->width > 0 && (base->flag & F_MINUS))
        while (base->width-- && base->width >= 0)
            ft_put_count(' ', base);
}

void    out_put_pointer(t_printf *base) {

    unsigned long long n;

    base->flag |= F_SHARP;
    n = (unsigned long long) va_arg(base->first_arg, unsigned long long);
    ft_pointer_hex(base, n);

}