#include <strings.h>
#include "ft_printf.h"

int     ft_strlens(char *str)
{
    int     i;

    i = 1;
    while (*str && i++)
        str++;
    return (--i);
}

void    ft_bzero(t_printf *base)
{
    base->specifier = '\0';
    base->nbr_wd_len = 0;
    base->skip = 0;
    base->width = 0;
    base->precision = 0;
    base->flag = 0;
    base->check_point = 0;
    base->check_point_two = 0;
    base->warg = 0;
    base->length = 0;
    base->size_teml = 0;
    base->x = 0;
}


int    ft_compare(t_printf *base, char *comp )
{
    int     i;

    i = 0;
    while (i < 7 && (base->m_content[i] != 'm' && i != 6))
    {
        if (base->m_content[i] != comp[i]) {
            return (0);
        }
        i++;
    }
    base->m_content += i;
    return (1);
}

void    ft_color_base(t_printf *base)
{
    if (ft_compare(base, RED))
        write(1, RED, ft_strlen(RED));
    else if (ft_compare(base, B_RED))
        write(1, B_RED, ft_strlen(B_RED));
    else if (ft_compare(base, GREEN))
        write(1, GREEN, ft_strlen(GREEN));
    else if (ft_compare(base, B_GREEN))
        write(1, B_GREEN, ft_strlen(B_GREEN));
    else if (ft_compare(base, YELLOW))
        write(1, YELLOW, ft_strlen(YELLOW));
    else if (ft_compare(base, B_YELLOW))
        write(1, B_YELLOW, ft_strlen(B_YELLOW));
    else if (ft_compare(base, BLUE))
        write(1, BLUE, ft_strlen(BLUE));
    else if (ft_compare(base, B_BLUE))
        write(1, B_BLUE, ft_strlen(B_BLUE));
    else if (ft_compare(base, MAGENTA))
        write(1, MAGENTA, ft_strlen(MAGENTA));
    else if (ft_compare(base, B_MAGENTA))
        write(1, B_MAGENTA, ft_strlen(B_MAGENTA));
    else if (ft_compare(base, CYAN))
        write(1, CYAN, ft_strlen(CYAN));
    else if (ft_compare(base, B_CYAN))
        write(1, B_CYAN, ft_strlen(B_CYAN));
    else if (ft_compare(base, RESET_COLOR))
        write(1, RESET_COLOR, ft_strlen(RESET_COLOR));
}

void    ft_core(t_printf base) {
    while (*base.m_content) {
        if (*base.m_content == '%') {
            ++base.m_content;
            (!*base.m_content) ? 0 : parsing(&base, base.m_content);
            base.sizeReturn -= (base.skip + 2);
        } else if (*base.m_content == '\33')
            ft_color_base(&base);
        else
            (*base.m_content == '\n') ? ft_put_count(*base.m_content, &base) : 0;
        base.m_content++;
        if (*base.m_content == '%') {
            ft_bzero(&base);
        }
    }
}


int	ft_printf(char *fmt, ...)
{
	t_printf	base;

	bzero(&base, sizeof(t_printf));
	va_start(base.first_arg, fmt);
	va_copy(base.itera_arg ,base.first_arg);
	base.m_content = fmt;
    ft_core(base);
    va_end(base.first_arg);
    va_end(base.itera_arg);
    return(base.sizeReturn);
}
