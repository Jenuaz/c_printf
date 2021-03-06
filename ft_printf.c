#include "ft_printf.h"

int    ft_bzero(t_printf *base)
{
    base->specifier = '\0';
    base->nbr_wd_len = 0;
    base->skip = 0;
    base->width = 0;
    base->precision = -1;
    base->flag = 0;
    base->check_point = 0;
    base->check_point_two = 0;
    base->warg = 0;
    base->length = 0;
    base->size_teml = 0;
    base->x = 0;
    return (1);
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
        write(1, RED, ft_strlen_color(RED, base));
    else if (ft_compare(base, B_RED))
        write(1, B_RED, ft_strlen_color(B_RED, base));
    else if (ft_compare(base, GREEN))
        write(1, GREEN, ft_strlen_color(GREEN, base));
    else if (ft_compare(base, B_GREEN))
        write(1, B_GREEN, ft_strlen_color(B_GREEN, base));
    else if (ft_compare(base, YELLOW))
        write(1, YELLOW, ft_strlen_color(YELLOW, base));
    else if (ft_compare(base, B_YELLOW))
        write(1, B_YELLOW, ft_strlen_color(B_YELLOW, base));
    else if (ft_compare(base, BLUE))
        write(1, BLUE, ft_strlen_color(BLUE, base));
    else if (ft_compare(base, B_BLUE))
        write(1, B_BLUE, ft_strlen_color(B_BLUE, base));
    else if (ft_compare(base, MAGENTA))
        write(1, MAGENTA, ft_strlen_color(MAGENTA, base));
    else if (ft_compare(base, B_MAGENTA))
        write(1, B_MAGENTA, ft_strlen_color(B_MAGENTA, base));
    else if (ft_compare(base, CYAN))
        write(1, CYAN, ft_strlen_color(CYAN, base));
    else if (ft_compare(base, B_CYAN))
        write(1, B_CYAN, ft_strlen_color(B_CYAN, base));
    else if (ft_compare(base, RESET_COLOR))
        write(1, RESET_COLOR, ft_strlen_color(RESET_COLOR, base));
}

//todo: 1. But in the buffer everything which is before %

int	ft_buffer_fill(t_printf *base)
{
	int 	counter;
	char	out_put[BUFFER];

	counter = 0;
	bzero(&out_put, BUFFER);
	while(*base->m_content && *base->m_content != '%' \
	&& BUFFER > counter && *base->m_content != '\33')
		out_put[counter++] = *base->m_content++;
	ft_put_count_buffer(out_put, base, counter);
	if (*base->m_content == '\33')
		ft_color_base(base);
	(*base->m_content != '%' && *base->m_content) ? ft_buffer_fill(base) : 0;
	return (1);
}

int	ft_printf(char *fmt, ...)
{
	t_printf	base;

	bzero(&base, sizeof(t_printf));
	va_start(base.first_arg, fmt);
	va_copy(base.itera_arg ,base.first_arg);
	base.m_content = fmt;
    while (*base.m_content) {
        if (ft_buffer_fill(&base) && ft_bzero(&base) && *base.m_content == '%')
            (!*(++base.m_content)) ? 0 : parsing(&base);
        if (base.buffer_p_counter != 0) {
            write(1, base.str, base.buffer_p_counter);
            base.buffer_p_counter = 0;
        }
        (*base.m_content != '\0') ? base.m_content++ : 0;
    }
    va_end(base.first_arg);
    va_end(base.itera_arg);
    return(base.sizeReturn);
}


//int     ft_strlens(char *str)
//{
//    int     i;
//
//    i = 1;
//    while (*str && i++)
//        str++;
//    return (--i);
//}
//void    ft_core(t_printf *base) {
//
//	while (*base->m_content) {
//		ft_buffer_fill(base);
//        if (*base->m_content == '%') {
//            ft_bzero(base);
//            ++base->m_content;
//            (!*base->m_content) ? 0 : parsing(base);
//        }
//		(*base->m_content != '\0') ? base->m_content++ : 0;
//    }
//}