
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <wchar.h>
#include "ft_printf.h"

int		ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

int	ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s != '\0')
		s++;
	if (*s == (char)c)
		return (1);
	return (0);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int        ft_atoi_s(const char *str)
{
	int        ng;
	int        count;

	count = 0;
	while (*str == 32 || *str == '\n' || (*str >= 9  && *str <= 13))
		str++;
	(*str == '-') ? (ng = 1 && *str++) : (ng = 0);
	(*str == '+') ? (*str++) : (count *= 10);
	while (*str && *str >= 48 && *str <= 57)
	{
		count *= 10;
		count += (long long int)(*str - '0');
		str++;
	}
	return ((ng == 1) ? (count * (-1)) : (count));
}

int        ft_atoi(const char *str, int *skip)
{
	int        ng;
	int        count;

	count = 0;
	while (*str == 32 || *str == '\n' || (*str >= 9  && *str <= 13))
		str++;
	(*str == '-') ? (ng = 1 && *str++) : (ng = 0);
	(*str == '+') ? (*str++) : (count *= 10);
	while (*str && *str >= 48 && *str <= 57)
	{
		count *= 10;
		count += (long long int)(*str - '0');
		str++;
		(*skip)++;
	}
	return ((ng == 1) ? (count * (-1)) : (count));
}

int 	uni_dig_fill(char **s)
{
	int     numb;
	int     skip;

	skip = 0;
	numb = ft_atoi(*s, &skip);
	*s += skip;
	return (numb);
}



int ft_review(char **s, t_printf *base)
{
	int     i;

	i = 0;
	if (base->warg == 0)
		base->warg = ft_atoi(*s, &i);
	(*s) = *s + i;
	if (**s == '$') {
		return (0);
	}
	else
		while (i--)
			(*s)--;
	return (1);
}


void	help_fill_recogn(t_printf *base)
{
	if (*base->m_content && TYPESTO(*base->m_content) && SIZE_F(*base->m_content))
	{
		if (((*base->m_content > 48 && *base->m_content <= 57) || (*base->m_content == '*')) && base->precision != 1 && base->width != 1 && ft_review(&base->m_content, base))
			(*base->m_content == '*') ? (base->width = (int)va_arg(base->first_arg, int)) : (base->width = uni_dig_fill(&base->m_content));
        (*base->m_content == 46) ? (base->precision = 1 && (base->check_point = 1)) : 0;
		if (((*base->m_content > 48 && *base->m_content <= 57) || (*base->m_content == '*')) && base->precision == 1)
            (*base->m_content == '*') ? (base->precision = (int)va_arg(base->first_arg, int)) : (base->precision = uni_dig_fill(&base->m_content));
		if (TYPESTO(*base->m_content) && SIZE_F(*base->m_content))
			base->m_content++;
		help_fill_recogn(base);
	}
}

int     ft_str_search_from(t_printf *base, char *what)
{
	int 	j;
	char    *where;

	where = base->m_content;
	while (*where && TYPESTO(*where))
	{
		j = 0;
		while (what[j])
		{
			if (*where == what[j])
			{
				where--;
				if ((base->check_point_two == 1 || (!ft_isdigit(*where)) || (base->flag & F_ZERO && base->width == 0 && base->precision == 0)) && *where != '.')
					return (j);
				where++;
			}
			j++;
		}
		where++;
	}
	return (-1);
}


void	parse_flags(t_printf *base)
{
	while (1)
	{
		if (FLAGS(*base->m_content))
		{
			while (FLAGS(*base->m_content))
			{
				base->flag |= (1 << ft_str_search_from(base, "# +-0"));
				base->m_content++;
			}
			continue ;
		}
		if (ft_isdigit(*base->m_content)) {
			help_fill_recogn(base);
			continue ;
		}
		if (SIZE(*base->m_content)) {
			while ((base->x = (ft_str_search_from(base, "lhjz") + 5)) > -1 && *base->m_content && SIZE(*base->m_content)) {
				if (*base->m_content == 'l' && !(base->length & F_LONG))
					(*(++base->m_content) == 'l') ? (base->length |= (1 << (base->x + 1))) : (base->length |= (1
							<< base->x));
				if (*base->m_content == 'h')
					((*base->m_content == 'h') && !(base->length & F_SHORT)) ? (base->length |= (1 << (base->x + 1)))
																			 : (base->length |= (1 << (base->x + 2)));
				(*base->m_content == 'j') ? (base->length |= (1 << (base->x + 2))) : 0;
				(*base->m_content == 'z') ? (base->length |= (1 << (base->x + 2))) : 0;
				base->m_content++;
			}
			continue ;
		}
		if (SPEC(*base->m_content)) {
			base->specifier = *base->m_content;
		}
		else
		{
				base->width -= 1;
				while (base->width >= 0 && !(base->flag & F_MINUS) && base->width--)
					(base->flag & F_ZERO) ? ft_put_count('0', base) : ft_put_count(' ', base);
				ft_put_count(*base->m_content, base);
				while (base->width-- && base->width >= 0 && (base->flag & F_MINUS))
					ft_put_count(' ', base);
		}
		return ;
		}
}

void	corrector_size(t_printf *base) {
    if (ft_strchr("CSDOU", base->specifier)) {
        (base->length & F_LONG) ? (base->length += base->length) : (base->length |= F_LONG);
        if (base->specifier == 'X')
            base->heigh = 1;
        base->specifier = ft_tolower(base->specifier);
    }
    if (base->specifier == 'X')
    {
            base->heigh = 1;
         base->specifier = ft_tolower(base->specifier);
    }
    if (base->specifier == 'O')
    {
        base->heigh = 1;
        base->specifier = ft_tolower(base->specifier);
    }
}

/*-------------------------  HELP FUNCTION   ----------------------*/


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


int		ft_padding_space(int times)
{
	while (times--)
		write(1, " ", 1);
    return (1);
}

void		ft_padding_zero(int times)
{
	while (times--)
		write(1, "0", 1);
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

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

	static long long int				itoasize(uintmax_t n)
	{
        uintmax_t		i;

		i = 0;
		while (n >= 1)
		{
			n /= 10;
			i++;
		}
		return (i);
	}

	static long long  int		ifnegative(uintmax_t *dig, t_printf *base, int *len)
	{
//		uintmax_t	*newd;

//		if (!(newd = (uintmax_t*)malloc(sizeof(uintmax_t))))
//			return (0);
//		if (*dig < 0)
//		{
//			*chk = 1;
//			*newd = (intmax_t)*dig * -1;
//			*len = itoasize(*newd);
//			*len += 1;
//			return (*newd);
//		}
        if (*dig == 0)
		{
			*len += 1;
			return (*dig);
		}
		else
		{
			*len = itoasize(*dig);
            (base->x == 1) ? (*len += 1) : 0;
			return (*dig);
		}
	}

	char					*ft_itoa(uintmax_t n, t_printf *base)
	{
		char			*str;
		int				lens;
		long long  int	g;
        uintmax_t	d;

		lens = 0;
		d = ifnegative(&n, base,  &lens);
		if (!(str = (char *)malloc(sizeof(char) * (lens + 1))))
			return (NULL);
		str[lens] = '\0';
		while (lens > 0)
		{
			g = d % 10;
			d = d / 10;
			str[--lens] = (char)g + '0';
		}
		if (base->x == 1)
			str[lens] = '-';
		return (str);
	}

void	ft_putnbr(intmax_t n)
{
    uintmax_t	news;
    uintmax_t	pronew;
    uintmax_t   saver;

	if (n < 0)
	{
        (n <= INTMAX_MIN) ? 0 : ft_putchar('-');
		saver = n * (-1);
	}
    saver = (uintmax_t)n;
	if (n == 0 || saver == 0)
	{
		ft_putchar('0');
		return ;
	}
    (saver != 0) ? (pronew = saver) : (pronew = n);
	news = pronew % 10;
	pronew = pronew / 10;
	if (pronew != 0)
		ft_putnbr(pronew);
	ft_putchar((char)news + '0');
}

/*-----------------------------------------------------------------*/


/*------------------------- OUT PUT FUNCTIONS --------------------*/
/*-------------------------    INT_OUT_PUT    --------------------*/


void	ft_putnbr_mod(t_printf *base, intmax_t nbr)
{
	int 	tmpl;
	int 	tmpl_nul;
    int     tmplsv;

    tmplsv = 0;
	(base->precision >= base->nbr_wd_len) ? ((nbr == 0 && base->check_point == 1 && base->precision != 1) ? (tmpl_nul = (base->precision - \
	base->nbr_wd_len) + 1) : ((base->x == 1 && !(base->flag & F_ZERO)) ? (tmpl_nul = (base->precision - base->nbr_wd_len) + 1) : (tmpl_nul = \
	(base->precision - base->nbr_wd_len)))) : (tmpl_nul = 0);                 // how much '0' output
	if (base->width > base->nbr_wd_len && base->precision <= base->nbr_wd_len) {
        (base->check_point == 1 && nbr == 0) ? (tmpl = (base->width - base->nbr_wd_len) + 1) : (base->flag & F_PLUS && base->x != 1) \
 ? (tmpl = (base->width - base->nbr_wd_len) - 1) : (tmpl = base->width - base->nbr_wd_len);
		(((base->flag & F_MINUS) || ((base->flag & F_SPACE) || (base->flag & F_ZERO))) ?  0 : ft_padding_space(tmpl));
		if (base->flag & F_PLUS || base->x == 1)
			(nbr >= 0 && base->x != 1) ? write(1, "+", 1) : write(1, "-", 1);
		((base->flag & F_ZERO) && !(base->flag & F_MINUS)) ? ft_padding_zero(tmpl):0;
		(base->flag & F_SPACE) ? ft_padding_space(1) : 0;
		//ft_putnbr(nbr);
        base->size_teml = base->width;
        while (tmpl_nul--)
            write(1, "0", 1);
        (base->check_point == 1 && nbr == 0) ? 0 : ft_putnbr(nbr);
		(base->flag & F_MINUS) ? (base->flag & F_SPACE) ? ft_padding_space(tmpl-1) : ft_padding_space(tmpl) : 0;
		base->m_content = base->m_content + base->skip;

	}
	else if (base->width > base->nbr_wd_len && base->precision > base->nbr_wd_len && base->precision < base->width)
	{
		tmpl = base->width - base->precision;
        ((base->flag & F_SPACE && (tmpl == 0 || base->flag & F_MINUS)) && (base->width - base->precision - base->nbr_wd_len) > 0) ? ft_padding_space(1) : 0;
        (base->flag & F_MINUS) ? 0 : ft_padding_space((base->flag & F_PLUS || base->x == 1) ? (tmpl - 1) : tmpl);
        // fix in future     FIXANUL BLYA
		if (base->flag & F_PLUS || base->x == 1)
			(nbr >= 0 && base->x != 1) ? write(1, "+", 1) : write(1, "-", 1);
		while (tmpl_nul)
            (tmpl_nul) ? tmplsv++ && write(1, "0", 1) && tmpl_nul-- : 0 ;
        base->size_teml = base->width;
        (base->check_point == 1 && nbr == 0) ? 0 : ft_putnbr(nbr);
	//	ft_putnbr(nbr);
		(base->flag & F_MINUS ) ? ft_padding_space((base->flag & F_PLUS || base->x == 1 || base->flag & F_SPACE) ? (tmpl - 1) : tmpl) : 0; //&& !(base->flag & F_SPACE)
//        (base->flag & F_MINUS ) ? ft_padding_space((base->flag & F_PLUS || base->x == 1) ? (tmpl - 1 - tmplsv) : tmpl - (--tmplsv)) : 0;
//        (base->flag & F_SPACE) ? ft_padding_space(1) : 0;
		base->m_content = base->m_content + base->skip;
	}
	else {
        (base->flag & F_SPACE && !(base->flag & F_ZERO) && !(base->flag & F_PLUS) && (base->x != 1) ) ? (base->sizeReturn += 1) && ft_padding_space(1) : 0;
		((base->flag & F_ZERO) && base->precision == 0) ? (base->nbr_wd_len > base->width)? 0 : ft_padding_zero(1) : 0;
		if (base->flag & F_PLUS || base->x == 1)
			(nbr >= 0 && base->x != 1) ? write(1, "+", 1) && (base->sizeReturn += 1) : write(1, "-", 1) && (base->x != 1) ? (base->sizeReturn += 1) : (base->nbr_wd_len < base->precision) ? (base->sizeReturn += 1) : 0;
		while (tmpl_nul-- )
			write(1, "0", 1);
		base->m_content = base->m_content + base->skip;
        base->size_teml = (base->width < base->precision && base->nbr_wd_len < base->precision) ? base->precision : (base->nbr_wd_len >= base->precision)? base->nbr_wd_len : base->nbr_wd_len + base->precision;
        (base->check_point == 1 && nbr == 0) ? 0 : ft_putnbr(nbr) ;
        ((nbr == 0 || nbr == -0) && (base->precision == 1)) ? base->size_teml-- : 0 ;
	}
}


void	out_put_int(t_printf *base)
{
	intmax_t	n;
    uintmax_t   spec;

    spec = 0;
	if (base->length & F_LONG || base->length & F_LONG2)
		n = (base->length & F_LONG2) ? ((intmax_t)va_arg(base->first_arg, long long)) :
			((intmax_t)va_arg(base->first_arg, long));
	else if (base->length & F_SHORT || base->length & F_SHORT2)
		n = (base->length & F_SHORT2) ? (intmax_t)((signed char)va_arg(base->first_arg, int)) :
			(intmax_t)((short int)va_arg(base->first_arg, int));
	else if (base->length & F_INTMAX)
		n = (va_arg(base->first_arg, intmax_t));
	else if (base->length & F_SIZE_T)
		n = ((intmax_t)va_arg(base->first_arg, ssize_t));
	else
		n = ((intmax_t)va_arg(base->first_arg, int));
	if (n < 0) {
		base->x = 1;
        (n <= INTMAX_MIN) ? (base->nbr_wd_len = ft_strlen(ft_itoa(spec = n * (-1), base))) : (base->nbr_wd_len = ft_strlen(ft_itoa((n *= -1), base)));
	}
	else
		base->nbr_wd_len = ft_strlen(ft_itoa(n, base));
    (spec != 0) ? ft_putnbr_mod(base, spec) : ft_putnbr_mod(base, n);
}



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


void    ft_putchar_mod(t_printf *base, unsigned int octet)
{
    int 	tmpl;
    int 	tmpl_nul;

    tmpl_nul = base->width - base->nbr_wd_len;

    (base->width > base->nbr_wd_len) ? (tmpl = base->width - base->nbr_wd_len) : (tmpl = 0);
        (base->flag & F_MINUS || base->flag & F_ZERO) ? 0 : ft_padding_space(tmpl);
        if (tmpl_nul > 0 && (base->flag & F_ZERO) && !(base->flag & F_MINUS))
            while (tmpl_nul--)
                write(1, "0", 1);
        ft_putwchar(octet);
        (base->flag & F_MINUS && !(base->flag & F_SPACE)) ? ft_padding_space(tmpl) : 0;
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

/*---------------------------------------------------------------*/
/*---------------------------- OUT_PUT_STRING -------------------*/

void    ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

void    ft_putwstr(wchar_t *chare)
{
    while (*chare)
        ft_putwchar(*chare++);
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
    (base->flag & F_MINUS || base->flag & F_ZERO) ? 0 : ft_padding_space(tmpl);
    if (tmpl_nul > 0 && (base->flag & F_ZERO) && !(base->flag & F_MINUS))
        while (tmpl_nul--)
            write(1, "0", 1);
    ft_putwstr(octet);
    (base->flag & F_MINUS && !(base->flag & F_SPACE)) ? ft_padding_space(tmpl) : 0;
    if (base->nbr_wd_len < base->width)
        base->size_teml = base->width;
    if (base->nbr_wd_len > base->width)
        base->size_teml = base->nbr_wd_len;
    base->m_content = base->m_content + base->skip;
}

void    ft_putstring_mod(t_printf *base, char *octet)
{
    int 	tmpl;
    int 	tmpl_nul;

    tmpl_nul = base->width - base->nbr_wd_len;

    (base->width > base->nbr_wd_len) ? (tmpl = base->width - base->nbr_wd_len) : (tmpl = 0);
    (base->flag & F_MINUS || base->flag & F_ZERO) ? 0 : ft_padding_space(tmpl);
    if (tmpl_nul > 0 && (base->flag & F_ZERO) && !(base->flag & F_MINUS))
        while (tmpl_nul--)
            write(1, "0", 1);
    ft_putstr(octet);
    (base->flag & F_MINUS && !(base->flag & F_SPACE)) ? ft_padding_space(tmpl) : 0;
    if (base->nbr_wd_len < base->width)
        base->size_teml = base->width;
    if (base->nbr_wd_len > base->width)
        base->size_teml = base->nbr_wd_len;
    base->m_content = base->m_content + base->skip;
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
    (chr != NULL) ? (base->nbr_wd_len = s_s_bits_lens(chr)) : (base->nbr_wd_len = ft_strlen(chrt));
    (chr != NULL) ? ft_putwstring_mod(base, chr) : ft_putstring_mod(base, chrt);
}

/*---------------------------------------------------------------*/


void	chars_for_skip(char *s, t_printf *base)
{
	while (TYPESTO(*s) && *s && s++)
		++base->skip;
}

void	out_results(t_printf *base)
{
	if (base->specifier == 'i' || base->specifier == 'd')
		out_put_int(base);
    else if (base->specifier == 'x' || base->specifier == 'X')
        ft_hex_out_put(base);
	else if (base->specifier == 'o' || base->specifier == 'O')
		ft_oct_out_put(base);
//    else if (base->specifier == 'c')
//		out_put_char(base);
//	else if (base->specifier == 's')
//		out_put_string(base);
//	else if (new->type == 'p')
//		showptr(new, va);
//	else if (new->type == 'u' || new->type == 'U')
//		show_unint(new, va);
//	rewrite_struct(new);
}

int	parsing(t_printf *base, char *fmt)
{
	base->flag = 0;
	parse_flags(base);
	base->m_content = fmt;
	corrector_size(base);
	out_results(base);
    return (base->size_teml);
}


/* -------------------------------- GIDE IN COUNTING UNICODE ----------------------------------------*/

//
//    size = size_count_bits(chr);
//    void    out_char_partO(wchar_t chr, t_printf *base)
//{
//    unsigned char octet;
//
//    octet = chr;
//    write(1, &octet, 1);
//}
//
//void    out_char_partT(unsigned int val, unsigned char octet, t_printf *base)
//{
//    unsigned char o2 = (val << 26) >> 26; // Восстановление первых 6 бит 110xxxxx 10(xxxxxx)           11000100 00000000 00000000 00000000 => 00000000 00000000 00000000 00110001
//    unsigned char o1 = ((val >> 6) << 27) >> 27; // Восстановление последних 5 бит 110(xxxxx) 10xxxxxx 01110000 00000000 00000000 00000000 => 00000000 00000000 00000000 00001110
//
//
////    octet = (MASK_ONE >> 8) | o1; // Применение первой битовой маски ко первому байту  1100000010000000 >> 8 => 00000000 11000000 => 00000000 11001110
////    write(1, &octet, 1);
////    octet = ((MASK_ONE << 24) >> 24) | o2; // Применение второй битовой маски ко второму байту 11000000 10000000 => 00000000 00000000 00000000 10000000 => 00000000 00000000 00000000 10110001
////    write(1, &octet, 1);
//}
//
//void    out_char_partTH(unsigned int val, unsigned char octet, t_printf *base)
//{
//    unsigned char o3 = (val << 26) >> 26; // Восстановление первых 6 бит 1110xxxx 10xxxxxx 10(xxxxxx)
//    unsigned char o2 = ((val >> 6) << 26) >> 26; // Восстановление вторых 6 бит 1110xxxx 10(xxxxxx) 10xxxxxx
//    unsigned char o1 = ((val >> 12) << 28) >> 28; // Восстановление последних 4 бит 1110(xxxx) 10xxxxxx 10xxxxxx
//
//    octet = (MASK_TWO >> 16) | o1; // Применение первой битовой маски ко первому байту
//    write(1, &octet, 1);
//    octet = ((MASK_TWO << 16) >> 24) | o2; // Применение второй битовой маски ко второму байту
//    write(1, &octet, 1);
//    octet = ((MASK_TWO << 24) >> 24) | o3; // Применение третьей битовой маски ко третьему байту
//    write(1, &octet, 1);
//}
//
//void    out_char_partF(unsigned int val, unsigned char octet, t_printf *base)
//{
//    unsigned char o4 = (val << 26) >> 26; // Восстановление первых 6 11110xxx 10xxxxxx 10xxxxxx 10(xxxxxx)
//    unsigned char o3 = ((val >> 6) << 26) >> 26; // Восстановление вторых 6 бит 11110xxx 10xxxxxx 10(xxxxxx) 10xxxxxx
//    unsigned char o2 = ((val >> 12) << 26) >> 26;  // Восстановление третьих 6 бит bits 11110xxx 10(xxxxxx) 10xxxxxx 10xxxxxx
//    unsigned char o1 = ((val >> 18) << 29) >> 29; // Восстановление последних 3 бита 11110(xxx) 10xxxxxx 10xxxxxx 10xxxxxx
//
//    octet = (MASK_THREE >> 24) | o1; // Применение бит первого байта на первый байт маски
//    write(1, &octet, 1);
//    octet = ((MASK_THREE << 8) >> 24) | o2; // Применение второй битовой маски ко второму байту
//    write(1, &octet, 1);
//    octet = ((MASK_THREE << 16) >> 24) | o3; // Применение третьей битовой маски ко третьему байту
//    write(1, &octet, 1);
//    octet = ((MASK_THREE << 24) >> 24) | o4; // Применение последней битовой маски ко последнему байту
//    write(1, &octet, 1);
//}


