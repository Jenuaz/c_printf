#include "ft_printf.h"

/*---------------------------- OUT_PUT_STRING -------------------*/


void    ft_putwstr(wchar_t *chare, t_printf *base)
{
    while (*chare)
        ft_putwchar(*chare++, base);
}

int     s_s_bits_lens(wchar_t *str)
{
    unsigned int    i;
    unsigned int    d;

    d = 0;
    i = 0;
    while (*str)
    {
        i = (unsigned int)*str;
        if ((i < 9 || i > 13) && i != 32)
            d += s_c_bits_lens(i);
        else
            d = d + 1;
        str++;
    }
    return (d);
}

void    ft_putwstring_mod(t_printf *base, wchar_t *octet)
{
    int 	tmpl;
    int 	tmpl_nul;

    tmpl_nul = base->width - base->nbr_wd_len;

    (base->width > base->nbr_wd_len) ? (tmpl = base->width - base->nbr_wd_len) : (tmpl = 0);
    (base->flag & F_MINUS || base->flag & F_ZERO) ? 0 : ft_padding_space(tmpl, base);
    if (tmpl_nul > 0 && (base->flag & F_ZERO) && !(base->flag & F_MINUS))
        while (tmpl_nul--)
            ft_put_count('0', base);
    ft_putwstr(octet, base);
    (base->flag & F_MINUS && !(base->flag & F_SPACE)) ? ft_padding_space(tmpl, base) : 0;
    if (base->nbr_wd_len < base->width)
        base->size_teml = base->width;
    if (base->nbr_wd_len > base->width)
        base->size_teml = base->nbr_wd_len;
    base->m_content = base->m_content + base->skip;
}

void      ft_putstr_count_w(char *s, t_printf *base)
{
    while (*s != '\0' && (base->precision-- && base->nbr_wd_len--))
        ft_put_count(*s++, base);
}


void    ft_putstring_mod(t_printf *base, char *octet)
{
    if ((base->width > base->precision && base->width > base->nbr_wd_len) || !strcmp("(null)", octet))
    {
        base->width -= (base->precision < base->nbr_wd_len && base->precision != -1) ? base->precision : base->nbr_wd_len;
        if (base->precision > base->nbr_wd_len)
            base->precision -= base->nbr_wd_len;
        else if (base->precision == base->nbr_wd_len && base->precision != -1)
            base->nbr_wd_len = base->precision;
        if (!(base->flag & F_MINUS)) {
            while (base->width-- > 0)
                (base->flag & F_ZERO) ? ft_put_count('0', base) : ft_put_count(' ', base);
            while (base->precision > base->nbr_wd_len && base->nbr_wd_len != 0) {
                (base->flag & F_ZERO) ? ft_put_count('0', base) : ft_put_count(' ', base);
                base->precision--;
            }
        }
        ft_putstr_count_w(octet, base);
        if (base->flag & F_MINUS){
            while (base->width-- > 0)
                (base->flag & F_ZERO) ? ft_put_count('0', base) : ft_put_count(' ', base);
            while (base->precision > base->nbr_wd_len && base->nbr_wd_len != 0) {
                (base->flag & F_ZERO) ? ft_put_count('0', base) : ft_put_count(' ', base);
                base->precision--;
            }
        }
    }
    else
    {
        if ((base->precision < base->nbr_wd_len) && (base->precision > 0)) {
            base->width -= base->precision;
            while (base->width-- > 0)
                (base->flag & F_ZERO) ? ft_put_count('0', base) : ft_put_count(' ', base);
            base->nbr_wd_len = base->precision;
        }
        if (base->precision > base->width)
        {
            base->width -= base->nbr_wd_len;
            while (base->width-- > 0)
                (base->flag & F_ZERO) ? ft_put_count('0', base) : ft_put_count(' ', base);
        }
        ft_putstr_count_w(octet, base);
    }
}


void    out_put_string(t_printf *base)
{
    wchar_t *chr;
    char    *chrt;

    chr = NULL;
    chrt = NULL;
    if (base->length & F_LONG)
        chr = va_arg(base->first_arg, wchar_t*);
    else
        chrt = va_arg(base->first_arg, char*);
    if ((chr == NULL) && (chrt == NULL))
        chrt = "(null)";
    (chr != NULL) ? (base->nbr_wd_len = s_s_bits_lens(chr)) : (base->nbr_wd_len = ft_strlen(chrt));
    (chr != NULL) ? ft_putwstring_mod(base, chr) : ft_putstring_mod(base, chrt);
}
