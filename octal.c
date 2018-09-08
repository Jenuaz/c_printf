#include "ft_printf.h"

void    ft_go_oct(t_printf *base, unsigned long long num) {
    int count;
    int flen;

    count = counthex(num, 8);
    flen = count + ((base->precision != -1 && base->precision > count) ? (base->precision - count) : 0);
    if (base->precision > count) {
        if (flen > base->width) {
            base->precision -= count;
            while (base->precision > 0 && base->precision--)
                ft_put_count('0', base);
            ft_hex(num, 8, base->heigh, base);
        } else {
            base->width -= flen;
            base->precision -= count;
            if (!(base->flag & F_MINUS)) {
                while (base->width > 0 && base->width--)
                    ft_put_count(' ', base);
                while (base->precision > 0 && base->precision--)
                    ft_put_count('0', base);
                ft_hex(num, 8, base->heigh, base);
            } else {
                while (base->precision > 0 && base->precision--)
                    ft_put_count('0', base);
                ft_hex(num, 8, base->heigh, base);
                while (base->width > 0 && base->width--)
                    ft_put_count(' ', base);
            }
        }
    } else {
        base->width -= ((base->precision > 0 || base->precision == -1) ? count : 0) + ((base->flag & F_SHARP) ? 1 : 0);
        if (!(base->flag & F_MINUS)) {
            if (base->precision == -1) {
                while (base->width > 0 && base->width--)
                    if (base->flag & F_ZERO)
                        ft_put_count('0', base);
                    else
                        ft_put_count(' ', base);
            } else
                while (base->width > 0 && base->width--)
                    ft_put_count(' ', base);
            (base->flag & F_SHARP) ? ft_put_count('0', base) : 0;
            if (base->precision != 0)
                ft_hex(num, 8, base->heigh, base);
        } else {
            if (base->precision != 0) {
                (base->flag & F_SHARP) ? ft_put_count('0', base) : 0;
                ft_hex(num, 8, base->heigh, base);
            }
            while (base->width > 0 && base->width--)
                ft_put_count(' ', base);
        }

    }
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
