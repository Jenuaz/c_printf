#include "ft_printf.h"
/*---------------- PARSE FROM ARGS DIGIT && INTEGER---------------*/


void	get_int_di(t_printf *base)
{
    intmax_t	n;

    base->negnum = 0;
    if (base->length & F_LONG || base->length & F_LONG2)
        n = (base->length & F_LONG2) ? ((intmax_t)va_arg(base->first_arg, long long)) :
            ((intmax_t)va_arg(base->first_arg, long));
    else if (base->length & F_SHORT || base->length & F_SHORT2)
        n = (base->length & F_SHORT2) ? (intmax_t)((signed char)va_arg(base->first_arg, int)) :
            (intmax_t)((short int)va_arg(base->first_arg, int));
    else if (base->length & F_INTMAX)
        n = (va_arg(base->first_arg, intmax_t));
    else if (base->length & F_SIZE_T)
        n = ((size_t)va_arg(base->first_arg, ssize_t));
    else
        n = ((intmax_t)va_arg(base->first_arg, int));
    if (n < 0) {
        base->negnum = 1;
        n *= (-1);
        base->nbr_wd_len = counthex(n, 10);
    }
    else
        base->nbr_wd_len = counthex(n, 10);
    ft_putnbr_mod(base, n);
}

/*---------------------------------------------------------------*/

/*-------------------------------SIGNED DIGITS-------------------------------*/

void	ft_putnbr_prec(t_printf *base, intmax_t nbr)
{
    int     tmp;

    if (base->precision > base->width && base->precision > base->nbr_wd_len)
    {
        tmp = base->precision - base->nbr_wd_len;
        (base->negnum == 1) ? ft_put_count('-', base) : 0;
        (base->flag & F_PLUS && base->negnum != 1) ? ft_put_count('+', base) : 0;
        while (tmp-- && tmp >= 0)
            ft_put_count('0', base);
        ft_putnbr(nbr, base);
        return ;
    }
    if (base->precision <= base->width && base->precision >= base->nbr_wd_len)
    {
        tmp = base->width - base->precision - ((base->flag & F_PLUS || base->negnum == 1) ? 1 : 0);
        ((base->flag & F_ZERO) && base->flag & F_PLUS && base->negnum == 0) ? ft_put_count('+', base) : 0;
        if (!(base->flag & F_MINUS))
            while (tmp-- && tmp >= 0)
                ft_put_count(' ', base);
        tmp = base->precision - base->nbr_wd_len;
        (base->flag & F_SPACE && (base->width <= base->precision)) ? ft_put_count(' ', base) : 0;
        (base->flag & F_SPACE && (base->flag & F_MINUS) && (base->width > base->precision)) ? ft_put_count(' ', base) : 0;
        (base->flag & F_PLUS && base->negnum == 0) ?  ft_put_count('+', base) : 0;
        (base->negnum == 1) ? ft_put_count('-', base) : 0;
        while (tmp-- && tmp >= 0)
            ft_put_count('0', base);
        ft_putnbr(nbr, base);
        if (base->flag & F_MINUS) {
            tmp = base->width - base->precision - ((base->flag & F_PLUS || base->flag & F_SPACE || base->negnum == 1) ? 1 : 0);
            while (tmp-- && tmp >= 0)
                (base->flag & F_ZERO) ? ft_put_count('0', base) : ft_put_count(' ', base);
        }
        return ;
    }
}

void	ft_putnbr_mod(t_printf *base, unsigned long long int nbr)
{
    int plus;
    plus = (base->flag & F_PLUS) ? 1 : 0;
    (base->flag & F_SPACE) || base->negnum == 1 ? (plus = 0) : 0;
    if (base->nbr_wd_len >= base->precision && base->nbr_wd_len >= base->width)
    {
        base->negnum == 1 ? ft_put_count('-', base) : 0;
        base->negnum == 0 && (base->flag & F_PLUS && base->specifier != 'u' && base->specifier != 'U') ? ft_put_count('+', base) : 0;
        base->negnum == 0 && !(base->flag & F_PLUS) && (base->specifier != 'u' && base->specifier != 'U') && (base->flag & F_SPACE) ? ft_put_count(' ', base) : 0;
        (nbr != 0) ? ft_putnbr(nbr, base) : 0;
        (nbr == 0 && base->precision == -1) ? ft_putnbr(nbr, base) : 0;
    }
    if (base->precision > base->nbr_wd_len)
    {
        ft_putnbr_prec(base, nbr);
        return ;
    }
    if (base->width >= base->nbr_wd_len)
    {
        (nbr == 0) ? base->nbr_wd_len = 0 : 0;
        if (base->width > base->nbr_wd_len)
        {
            (base->nbr_wd_len == 0 && base->precision == -1) ? base->nbr_wd_len = 1 : 0;
            (base->precision >= base->nbr_wd_len) ? (base->width -= base->precision) : 0;
            (base->precision < base->nbr_wd_len) ? base->width -= base->nbr_wd_len : 0;
            (base->width > base->nbr_wd_len && base->width > base->precision && base->flag & F_SPACE) ?
                    base->width -= 1 : 0;
        }
        else
            base->width = base->width - ((base->precision > 1) ? base->precision : 0) - base->nbr_wd_len;
        (base->negnum != 1 && base->flag & F_PLUS && base->specifier != 'u' && base->specifier != 'U') ? ft_put_count('+', base) : 0;
        (base->negnum == 1 && (base->flag & F_ZERO)) ? ft_put_count('-', base) : 0;
        if (base->width > 0 && !(base->flag & F_MINUS))
        {
            base->width -= base->negnum + plus;
            base->negnum == 0 && !(base->flag & F_PLUS && base->specifier != 'u' && base->specifier != 'U') && (base->flag & F_SPACE) ? ft_put_count(' ', base) : 0;
            while (base->width-- && base->width >= 0)
                (base->flag & F_ZERO) ? ft_put_count('0', base) :  ft_put_count(' ', base);
        }
        base->negnum == 1 && !(base->flag & F_ZERO)? ft_put_count('-', base) : 0;
        base->negnum == 0 && (base->flag & F_PLUS && base->specifier != 'u' && base->specifier != 'U') && !(base->flag & F_ZERO)? ft_put_count('+', base) : 0;
        (base->precision == 0 && base->nbr_wd_len <= 1) ? 0 : ft_putnbr(nbr, base);
        if (base->width > 0 && (base->flag & F_MINUS))
        {
            base->width -= base->negnum + plus;
            while (base->width-- && base->width >= 0)
                ft_put_count(' ', base);
        }
    }
}


