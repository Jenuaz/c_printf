/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylisyak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 04:31:32 by ylisyak           #+#    #+#             */
/*   Updated: 2018/11/29 04:49:02 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_abs(int nbr, t_printf *base)
{
	if (nbr < 0)
	{
		base->flag |= F_MINUS;
		nbr *= -1;
	}
	return (nbr);
}

int			ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

int			ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s != '\0')
		s++;
	if (*s == (char)c)
		return (1);
	return (0);
}

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_atoi_s(const char *str)
{
	int		ng;
	int		count;

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

int			ft_atoi(const char *str, int *skip)
{
	int		ng;
	int		count;

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

int 		uni_dig_fill(char **s, t_printf *base)
{
	int     numb;
	int     skip;

	skip = 0;
	numb = ft_atoi(*s, &skip);
	*s += skip;
	if (**s == '*')
	{
		numb = (ft_abs(va_arg(base->first_arg, int), base));
		*s += 1;
	}
	return (numb);
}

int			ft_review(char **s, t_printf *base)
{
	int		i;

	i = 0;
	if (base->warg == 0)
		base->warg = ft_atoi(*s, &i);
	(*s) = *s + i;
	if (**s == '$')
		return (0);
	else
		while (i--)
			(*s)--;
	return (1);
}

void		ft_not_dot(t_printf *base)
{
	if (*(base->m_content) != 46) 
	{
       	if ((ft_isdigit(*base->m_content) || (*base->m_content == '*'))  && ft_review(&base->m_content, base))
			(*base->m_content == '*') ? (base->width = ft_abs(va_arg(base->first_arg, int), base))
    			                     : (base->width = uni_dig_fill(&base->m_content, base));
			(base->m_content != '\0' && *base->m_content == '*') ? (void)(*base->m_content++) : 0;
	}
	if (*(base->m_content) == 46) 
	{
		base->m_content++;
        if ((ft_isdigit(*base->m_content) || (*base->m_content == '*')) && base->precision == -1)
		{
			(*base->m_content == '*') ? (base->precision = (int)va_arg(base->first_arg, int))
                                          : (base->precision = uni_dig_fill(&base->m_content, base));
                (base->m_content != '\0' && *base->m_content == '*') ? (void)(*base->m_content++) : 0;
            }
            else
                base->precision = 0;
    }
}

void		help_fill_recogn(t_printf *base)
{
	if (TYPESTO(*base->m_content) && (ft_isdigit(*base->m_content) || \
	*base->m_content == 46 || *base->m_content == '*') && \
	SIZE_F(*base->m_content))
	{
        ft_not_dot(base);
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
		j = -1;
		while (what[++j])
		{
			if (*where == what[j])
			    return (j);
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
		if (ft_isdigit(*base->m_content) || *base->m_content == '.' || *base->m_content == '*') {
			help_fill_recogn(base);
			continue ;
		}
		if (SIZE(*base->m_content) || *base->m_content == 'L') {
			while ((base->x = (ft_str_search_from(base, "lhjz") + 5)) > -1 && *base->m_content && SIZE(*base->m_content)) {
				if (*base->m_content == 'l' && !(base->length & F_LONG))
					(*(base->m_content + 1) == 'l') ? (base->length |= (1 << (base->x + 1))) : (base->length |= (1 << (base->x)));
				if (*base->m_content == 'h' && !(base->length & F_SHORT2))
                    ((*(base->m_content + 1) == 'h') && !(base->length & F_SHORT)) ? (base->length |= (1 << (base->x + 2))) : (base->length |= (1 << (base->x + 1)));
				(*base->m_content == 'j') ? (base->length |= (1 << (base->x + 2))) : 0;
				(*base->m_content == 'z') ? (base->length |= (1 << (base->x + 2))) : 0;
                (base->length == 64) ? (base->m_content+=2) : (base->m_content++);
			}
            (*base->m_content == 'L' && base->m_content++) ? (base->length |= (1 << 6)) : 0;
		}
		if (SPEC(*base->m_content))
			base->specifier = *base->m_content;
		else
		{
				--base->width;
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
        base->specifier = ft_tolower(base->specifier);
    }
    if (base->specifier == 'X')
    {
         base->heigh = 1;
         base->specifier = ft_tolower(base->specifier);
    }
}

/*-------------------------  HELP FUNCTION   ----------------------*/

int		ft_padding_space(int times, t_printf *base)
{
	while (times--)
        ft_put_count(' ', base);
    return (1);
}

int		ft_padding_zero(int times, t_printf *base)
{
    while (times--)
        ft_put_count('0', base);
    return (1);
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

size_t		ft_strlen_color(const char *s, t_printf *base)
{
	size_t i;

	i = 0;
	while (*s++)
		i++;
	base->sizeReturn += i;
    (void)*base->m_content++;
	return (i);
}

void	ft_putnbr(unsigned long long int n, t_printf *base)
{
	unsigned long long int 	news;
	unsigned long long int	pronew;
	unsigned long long int  saver;

    saver = n;
	if (n == 0 || saver == 0)
	{
		ft_put_count('0', base);
		return ;
	}
    (saver != 0) ? (pronew = saver) : (pronew = n);
	news = pronew % 10;
	pronew = pronew / 10;
	if (pronew != 0)
		ft_putnbr(pronew, base);
	ft_putchar((char)news + '0', base);
	base->sizeReturn++;
}

/*---------------------------- PARSE FROM ARGS UNSIGNED -------------------------------------*/

void    get_unint_u(t_printf *base)
{
    unsigned long long int	n;

    base->negnum = 0;
    if (base->length & F_LONG || base->length & F_LONG2)
        n = (base->length & F_LONG2) ? ((unsigned long long int)va_arg(base->first_arg, unsigned long long int)) :
            ((unsigned long long int)va_arg(base->first_arg, unsigned long long int));
    else if (base->length & F_SHORT || base->length & F_SHORT2)
        n = (base->length & F_SHORT2) ? (uintmax_t)((unsigned char)va_arg(base->first_arg, unsigned int)) :
            (uintmax_t)((unsigned short int)va_arg(base->first_arg, unsigned int));
    else if (base->length & F_INTMAX)
        n = (va_arg(base->first_arg, uintmax_t));
    else if (base->length & F_SIZE_T)
        n = ((size_t)va_arg(base->first_arg, ssize_t));
    else
        n = ((uintmax_t)va_arg(base->first_arg, unsigned int));
        base->nbr_wd_len = counthex(n, 10);
    ft_putnbr_mod(base, n);
}

/*---------------------------------------------------------------*/

int	parsing(t_printf *base)
{
    int                 i;
    int                 etalon;
    t_operators         out_put[] =
            {
                    {'x', ft_hex_out_put},
                    {'o', ft_oct_out_put},
                    {'s', out_put_string},
                    {'p', out_put_pointer},
                    {'i', get_int_di},
                    {'d', get_int_di},
                    {'f', out_put_flow},
                    {'u', get_unint_u},
                    {'c', out_put_char},
                    {'%', out_put_percent}
            };
    i = -1;
	base->flag = 0;
	parse_flags(base);
	corrector_size(base);
    etalon = (int)(sizeof(out_put)/ sizeof(out_put[0]));
    while (++i < etalon)
        if (base->specifier == out_put[i].out_put_function) {
            out_put[i].fn(base);
            break;
        }
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


