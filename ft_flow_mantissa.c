#include "ft_printf.h"

void    zero_precision_f(t_custom_f *digit, t_printf *base)
{
    base->precision = 0;
    (base->nbr_wd_len < base->width) ? ft_padding_space(base->width - base->nbr_wd_len, base) : 0;
    base->width = 0;
    base->precision = -1;
    ft_putnbr_mod(base, digit->exponent);
}

void    zero_precision_d(t_custom_f *digit, t_printf *base)
{
    base->precision = 0;
    (base->nbr_wd_len < base->width) ? ft_padding_space(base->width - base->nbr_wd_len, base) : 0;
    base->width = 0;
    base->precision = -1;
    ft_putnbr_mod(base, digit->exponent);
}

void    zero_precision_ld(t_custom_f *digit, t_printf *base)
{
    base->precision = 0;
    (base->nbr_wd_len < base->width) ? ft_padding_space(base->width - base->nbr_wd_len, base) : 0;
    base->width = 0;
    base->precision = -1;
    ft_putnbr_mod(base, digit->exponent);
}

void    infinity_precision_f(t_custom_f *digit, t_printf *base)
{
    int   tmp;
	float mantissa;
	(void)base;
    mantissa = digit->src.f - (float)digit->exponent;
    (base->flag & F_PLUS) ? (digit->mantisa_length -= 1) : 0;
    digit->mantisa = roundcustomf(mantissa * (float)custom_pow(10, base->precision));
    if (base->nbr_wd_len < base->width && !(base->flag & F_MINUS))
        (base->flag & F_ZERO) ? ft_padding_zero(base->width - base->nbr_wd_len, base) : \
                                ft_padding_space(base->width - base->nbr_wd_len, base);
    tmp = base->width;
    base->width = 0;
    base->precision = -1;
    ft_putnbr_mod(base, digit->exponent);
    (base->flag & F_PLUS) ? (base->flag &= ~F_PLUS) : 0;
    ft_put_count('.', base);
    ft_putnbr_mod(base, digit->mantisa);
    base->width = tmp;
    (base->nbr_wd_len < base->width && (base->flag & F_MINUS)) ? ft_padding_space(base->width - base->nbr_wd_len, base) : 0;
}

void    infinity_precision_d(t_custom_f *digit, t_printf *base)
{
    int   tmp;
    float mantissa;
    (void)base;
    mantissa = digit->src.d - (float)digit->exponent;
    (base->flag & F_PLUS) ? (digit->mantisa_length -= 1) : 0;
    digit->mantisa = roundcustomf(mantissa * (float)custom_pow(10, base->precision));
    if (base->nbr_wd_len < base->width && !(base->flag & F_MINUS))
        (base->flag & F_ZERO) ? ft_padding_zero(base->width - base->nbr_wd_len, base) : \
                                ft_padding_space(base->width - base->nbr_wd_len, base);
    tmp = base->width;
    base->width = 0;
    base->precision = -1;
    ft_putnbr_mod(base, digit->exponent);
    (base->flag & F_PLUS) ? (base->flag &= ~F_PLUS) : 0;
    ft_put_count('.', base);
    ft_putnbr_mod(base, digit->mantisa);
    base->width = tmp;
    (base->nbr_wd_len < base->width && (base->flag & F_MINUS)) ? ft_padding_space(base->width - base->nbr_wd_len, base) : 0;
}

void    infinity_precision_ld(t_custom_f *digit, t_printf *base)
{
    int   tmp;
    float mantissa;
    (void)base;
    mantissa = digit->src.ld - (float)digit->exponent;
    (base->flag & F_PLUS) ? (digit->mantisa_length -= 1) : 0;
    digit->mantisa = roundcustomf(mantissa * (float)custom_pow(10, base->precision));
    if (base->nbr_wd_len < base->width && !(base->flag & F_MINUS))
        (base->flag & F_ZERO) ? ft_padding_zero(base->width - base->nbr_wd_len, base) : \
                                ft_padding_space(base->width - base->nbr_wd_len, base);
    tmp = base->width;
    base->width = 0;
    base->precision = -1;
    ft_putnbr_mod(base, digit->exponent);
    (base->flag & F_PLUS) ? (base->flag &= ~F_PLUS) : 0;
    ft_put_count('.', base);
    ft_putnbr_mod(base, digit->mantisa);
    base->width = tmp;
    (base->nbr_wd_len < base->width && (base->flag & F_MINUS)) ? ft_padding_space(base->width - base->nbr_wd_len, base) : 0;
}


void    default_mantissa_value_f(t_custom_f *digit, t_printf *base)
{
    double mantissa_d;

    mantissa_d = (double)digit->src.f - (double)digit->exponent;
    digit->mantisa = roundcustomf(mantissa_d * (double)custom_pow(10, digit->mantisa_length - 1));
    if (base->nbr_wd_len < base->width && !(base->flag & F_MINUS))
        (base->flag & F_ZERO) ? ft_padding_zero(base->width - base->nbr_wd_len, base) : ft_padding_space(base->width - base->nbr_wd_len, base);
    (base->nbr_wd_len > 0 && base->width > base->nbr_wd_len) ? \
    (base->width -= base->nbr_wd_len) : (base->width -= digit->mantisa_length);
    base->precision = -1;
    (digit->sign == -1) ? digit->exponent *= -1 : 0;
    ft_putnbr_mod(base, digit->exponent);
    ft_put_count('.', base);
    if (base->negnum == 1)
        base->negnum = 0;
    ft_putnbr_mod(base, digit->mantisa);
}

void    default_mantissa_value_d(t_custom_f *digit, t_printf *base)
{
    double mantissa_d;

    mantissa_d = (double)digit->src.d - (double)digit->exponent;
    digit->mantisa = roundcustomf(mantissa_d * (double)custom_pow(10, digit->mantisa_length - 1));
    if (base->nbr_wd_len < base->width && !(base->flag & F_MINUS))
        (base->flag & F_ZERO) ? ft_padding_zero(base->width - base->nbr_wd_len, base) : ft_padding_space(base->width - base->nbr_wd_len, base);
    (base->nbr_wd_len > 0 && base->width > base->nbr_wd_len) ? \
    (base->width -= base->nbr_wd_len) : (base->width -= digit->mantisa_length);
    base->precision = -1;
    ft_putnbr_mod(base, digit->exponent);
    ft_put_count('.', base);
    if (base->negnum == 1)
        base->negnum = 0;
    ft_putnbr_mod(base, digit->mantisa);
}

void    default_mantissa_value_ld(t_custom_f *digit, t_printf *base)
{
    double mantissa_d;

    mantissa_d = (double)digit->src.ld - (double)digit->exponent;
    digit->mantisa = roundcustomf(mantissa_d * (double)custom_pow(10, digit->mantisa_length - 1));
    if (base->nbr_wd_len < base->width && !(base->flag & F_MINUS))
        (base->flag & F_ZERO) ? ft_padding_zero(base->width - base->nbr_wd_len, base) : ft_padding_space(base->width - base->nbr_wd_len, base);
    (base->nbr_wd_len > 0 && base->width > base->nbr_wd_len) ? \
    (base->width -= base->nbr_wd_len) : (base->width -= digit->mantisa_length);
    base->precision = -1;
    ft_putnbr_mod(base, digit->exponent);
    ft_put_count('.', base);
    if (base->negnum == 1)
        base->negnum = 0;
    ft_putnbr_mod(base, digit->mantisa);
}

void    extract_mantissa_f(t_custom_f *digit, t_printf *base)
{
    (base->precision < 0) ? default_mantissa_value_f(digit, base) : 0;
    (base->precision == 0) ? zero_precision_f(digit, base) : 0;
    (base->precision > 0) ? infinity_precision_f(digit, base) : 0;
}

void    extract_mantissa_d(t_custom_f *digit, t_printf *base)
{
    (base->precision < 0) ? default_mantissa_value_d(digit, base) : 0;
    (base->precision == 0) ? zero_precision_d(digit, base) : 0;
    (base->precision > 0) ? infinity_precision_d(digit, base) : 0;
}

void    extract_mantissa_ld(t_custom_f *digit, t_printf *base)
{
    (base->precision < 0) ? default_mantissa_value_ld(digit, base) : 0;
    (base->precision == 0) ? zero_precision_ld(digit, base) : 0;
    (base->precision > 0) ? infinity_precision_ld(digit, base) : 0;
}
