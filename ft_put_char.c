#include "ft_printf.h"

int		ft_isascii(int c)
{
    if (c >= 0 && c <= 127)
        return (1);
    return (0);
}

void	ft_putchar(char c)
{
    if (c || ft_isascii(c))
        write(1, &c, 1);
    else
        write(1, &c, 3);
}

void      ft_putw_count(char a, t_printf *base)
{
    base->sizeReturn++;
    ft_putwchar(a);
}

void	ft_putwchar(wchar_t wc)
{
    if (wc <= 127)
        ft_putchar(wc);
    else if (wc <= 2047)
    {
        ft_putchar((wc >> 6) + 0xC0);
        ft_putchar((wc & 0x3F) + 0x80);
    }
    else if (wc <= 65535)
    {
        ft_putchar((wc >> 12) + 0xE0);
        ft_putchar(((wc >> 6) & 0x3F) + 0x80);
        ft_putchar((wc & 0x3F) + 0x80);
    }
    else if (wc <= 1114111)
    {
        ft_putchar((wc >> 18) + 0xF0);
        ft_putchar(((wc >> 12) & 0x3F) + 0x80);
        ft_putchar(((wc >> 6) & 0x3F) + 0x80);
        ft_putchar((wc & 0x3F) + 0x80);
    }
}
