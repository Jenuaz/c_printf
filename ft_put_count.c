#include "ft_printf.h"

void      ft_putstr_count(char *s, t_printf *base)
{
    while (*s != '\0')
        ft_put_count(*s++, base);
}

void      ft_put_count(char a, t_printf *base)
{
    base->sizeReturn++;
    ft_putchar(a);
}