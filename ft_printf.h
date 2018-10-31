#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <wchar.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>


#define  VALID(x) x == 's' || x == 'S' || x == 'p' || x == 'd' || x == 'D' || x == 'i' || x == 'o' || x == 'O' \
|| x == 'u' || x == 'U' || x == 'x' || x == 'X' || x == 'c' || x == 'C' || x == ' ' || x == 'l' || \
 x == 'h' || x == 'j' || x == 'z' || (x >= '0' && x <= '9') || x == 'h'\
 || x == '.' || x == '$' || x == '+' ||  x == '#' || x == '-' || x == '*'

#define  FLAGS(x) x == '0' || x == '+' || x == '-' \
    || x == ' ' || x == '#'

#define  SIZE(x) x == 'h' || x == 'l' || \
            x == 'j' || x == 'z'

#define  SIZE_F(x) x != 'h' && x != 'l' && x != 'j' && x != 'z'

#define  SPEC(x) x == 'd' || x == 'i' || x == 'c' \
    || x == 's' || x == 'o' || x == 'x' \
    || x == 'X' || x == 'p' || x == 'D' \
    || x == 'u' || x == 'U' || x == 'O' \
    || x == 'C' || x == 'S'

#define  TYPET(x) x == 's' || x == 'S' || x == 'p' || x == 'd' || x == 'D' || x == 'i' || x == 'o' || x == 'O' \
|| x == 'u' || x == 'U' || x == 'x' || x == 'X' || x == 'c' || x == 'C' || x == '\0' || x == '%'

#define  TYPESTO(x) x != 's' && x != 'S' && x != 'p' && x != 'd' && x != 'D' && x != 'i' && x != 'o' && x != 'O' \
&& x != 'u' && x != 'U' && x != 'x' && x != 'X' && x != 'c' && x != 'C' && x != '\n' && x != '%'

#define  VALID_P(x) x == ' ' || x == 'l' || x == 'h' || x == 'j' || x == 'z' || (x >= '0' && x <= '9') || x == 'h'\
 || x == '.' || x == '$' || x == '+' ||  x == '#' || x == '-' || x == '*'

#define CHR_VAL(x) x = (unsigned int)x;

#define MAX_NEGATIVE -9223372036854775808

/*
** ----------------------------------------- Masks ---------------------------------------------------------
*/

# define F_SHARP		(1 << 0)               //  #
# define F_SPACE		(1 << 1)               //  sp
# define F_PLUS			(1 << 2)               //  +
# define F_MINUS		(1 << 3)               //  -
# define F_ZERO			(1 << 4)               //  0

/*----------------------------------------------------------------------------------------------------------*/
/*                                                          d i                   u o x X                   */
# define F_LONG			(1 << 5)               //  l     (long int)           (unsigned long int)          32
# define F_LONG2		(1 << 6)               //  ll    (long long int)      (unsigned long long int)     64
# define F_SHORT		(1 << 7)               //  h     (short  int)                                      128
# define F_SHORT2		(1 << 8)               //  hh    (signed char)                                     256
# define F_INTMAX		(1 << 9)               //  j     (intmax_t)                                        512
# define F_SIZE_T		(1 << 10)              //  z     (size_t)                                          1024


/*-------------------------------------- COLOR MASKS -----------------------------------------------------*/

# define    RED         "\33[0;31m"	//Red
# define    B_RED       "\33[1;31m"	//Bold Red
# define    GREEN       "\33[0;32m"	//Green
# define    B_GREEN     "\33[1;32m"	//Bold Green
# define    YELLOW      "\33[0;33m"	//Yellow
# define    B_YELLOW    "\33[01;33m" //Bold Yellow
# define    BLUE        "\33[0;34m"	//Blue
# define    B_BLUE      "\33[1;34m"	//Bold Blue
# define    MAGENTA     "\33[0;35m"	//Magenta
# define    B_MAGENTA   "\33[1;35m"	//Bold Magenta
# define    CYAN        "\33[0;36m"	//Cyan
# define    B_CYAN      "\33[1;36m"	//Bold Cyan
# define    RESET_COLOR "\33[0m"	    //Reset

/*-------------------------------------- Unicode masks -----------------------------------------------------*/

# define MASK_ZERO      0
# define MASK_ONE       49280                  // 1100000010000000
# define MASK_TWO       14712960
# define MASK_THREE     4034953344

/*----------------------------------------------------------------------------------------------------------*/



# define F_MIN_LEN		(1 << 13)
# define F_APP_PRECI	(1 << 14)
# define F_POINTER		(1 << 15)
# define F_UPCASE		(1 << 16)
# define PF_BUF_SIZE	64

/*-----------------------------------------------------------------------------------------------------------*/

typedef struct		s_printf
{
/*----- section for $ line manipulation -----*/
    va_list		first_arg;
    va_list		itera_arg;
/*-------------------------------------------*/
	short		flag;
	short		length;
	int			width;
	int			precision;                   // boolean
    int         skip;
	int 		x;
    int         check_point;
    int         check_point_two;
	char		*m_content;
    int         heigh;
	int 		nbr_wd_len;                 // length of word or nbr
	int         negnum;

    int			warg;                       // $
    int         sizeReturn;
    int         size_teml;
	char		specifier;
}			t_printf;


int     ft_printf(char *fmt, ...);
int 	parsing(t_printf *base);
void	parse_flags(t_printf *base);
int     ft_strlens(char *str);
size_t		ft_strlen(const char *s);

void    ft_convert(unsigned long long k, int big_spec, t_printf *base);
void    ft_hex(unsigned long long k, int sys, int b, t_printf *base);
int        counthex(long long hex, int sys);

void    ft_hex_out_put(t_printf *base);

void    ft_putstr_count(char *s, t_printf *base);
void    ft_put_count(char a, t_printf *base);
void	ft_putwchar(wchar_t wc);
void	ft_putchar(char c);

void    ft_go_oct(t_printf *base, unsigned long long num);
void    ft_oct_out_put(t_printf *base);


/*----------------OUTPUT CHAR-----------*/
void	out_put_char(t_printf *base);
void    ft_putchar_mod(t_printf *base, unsigned int octet);


int     s_c_bits_lens(unsigned int nbr);

int		ft_padding_space(int times, t_printf *base);
void		ft_padding_zero(int times, t_printf *base);
int        counthex(long long hex, int sys);

/*----------------Digit out put----------*/
void	ft_putnbr(intmax_t n, t_printf *base);

/*-------------------- d i --------------*/
void	ft_putnbr_mod(t_printf *base, intmax_t nbr);
void	ft_putnbr_prec(t_printf *base, intmax_t nbr);


#endif
