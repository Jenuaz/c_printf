#include "ft_printf.h"

/*---------------------------- OUT_PUT_CHAR ---------------------*/

int     s_c_bits_lens(unsigned int nbr)
{
    int     i;

    i = 0;
    while (nbr > 0) {
        nbr /= 2;
        i++;
    }
    if (i<= 7) {
        i = 1;
    } else if (i <= 11) {
        i = 2;
    } else if (i <= 16) {
        i = 3;
    } else {
        i = 4;
    }
    return (i);
}

int		ft_isascii(int c)
{
    if (c >= 0 && c <= 127)
        return (1);
    return (0);
}

void	ft_putchar(char c, t_printf *base)
{
    int     filler;

    filler = base->buffer_p_counter;
    if (filler <= BUFFER_P) {
        base->str[filler++] = c;
        base->buffer_p_counter = filler;
    }
    else
    {
        write(1, &base->str, filler);
        base->buffer_p_counter = 1;
        base->str[0] = c;
    }
//    if (c || ft_isascii(c))
//        write(1, &c, 1);
//    else
//        write(1, &c, 3);
}

void      ft_putw_count(char a, t_printf *base)
{
    base->sizeReturn++;
    ft_putwchar(a, base);
}

void	ft_putwchar(wchar_t wc, t_printf *base)
{
    if (wc <= 127)
        ft_putchar(wc, base);
    else if (wc <= 2047)
    {
        ft_putchar((wc >> 6) + 0xC0, base);
        ft_putchar((wc & 0x3F) + 0x80, base);
    }
    else if (wc <= 65535)
    {
        ft_putchar((wc >> 12) + 0xE0, base);
        ft_putchar(((wc >> 6) & 0x3F) + 0x80, base);
        ft_putchar((wc & 0x3F) + 0x80, base);
    }
    else if (wc <= 1114111)
    {
        ft_putchar((wc >> 18) + 0xF0, base);
        ft_putchar(((wc >> 12) & 0x3F) + 0x80, base);
        ft_putchar(((wc >> 6) & 0x3F) + 0x80, base);
        ft_putchar((wc & 0x3F) + 0x80, base);
    }
}
