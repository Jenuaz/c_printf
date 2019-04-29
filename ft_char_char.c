#include "ft_printf.h"

void    ft_putchar_mod(t_printf *base, unsigned int octet)
{
    int 	tmpl;
    int 	tmpl_nul;

    tmpl_nul = base->width - base->nbr_wd_len;

    (base->width > base->nbr_wd_len) ? (tmpl = base->width - base->nbr_wd_len) : (tmpl = 0);
    (base->flag & F_MINUS || base->flag & F_ZERO) ? 0 : ft_padding_space(tmpl, base);
    if (tmpl_nul > 0 && (base->flag & F_ZERO) && !(base->flag & F_MINUS))
        while (tmpl_nul--)
            ft_put_count('0', base);
    ft_putw_count(octet, base);
    (base->flag & F_MINUS && !(base->flag & F_SPACE)) ? ft_padding_space(tmpl, base) : 0;
    base->m_content = base->m_content + base->skip;
}


void	out_put_char(t_printf *base) {
    wchar_t chr;

    if (base->length & F_LONG)
        chr = (wchar_t)va_arg(base->first_arg, wint_t);
    else
        chr = (char)va_arg(base->first_arg, int);
    base->nbr_wd_len = s_c_bits_lens(chr);
    ft_putchar_mod(base, chr);
}