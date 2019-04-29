#include "ft_printf.h"

int    out_put_space_or_zero(t_printf *base)
{
    if (base->flag & F_ZERO)
        while (base->width && --base->width)
            ft_put_count('0', base);
    else
        while (base->width && --base->width)
            ft_put_count(' ', base);
    return (1);
}


void    out_put_percent(t_printf *base)
{
    (base->flag & F_MINUS) ? 0 : out_put_space_or_zero(base);
    ft_put_count(*base->m_content, base);
    (base->flag & F_MINUS) ? out_put_space_or_zero(base): 0;
}