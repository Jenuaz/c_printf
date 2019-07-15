#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <strings.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <wchar.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>

#define	 BUFFER 10
#define  BUFFER_P 512

#define  FLAGS(x) x == '0' || x == '+' || x == '-' \
               || x == ' ' || x == '#'

#define  SIZE(x) x == 'h' || x == 'l' || x == 'j' || x == 'z'

#define  SIZE_F(x) x != 'h' && x != 'l' && x != 'j' && x != 'z'

#define  SPEC(x)  x == 'i' \
               || x == 'D' || x == 'C' || x == 'O'|| x == 'X' || x == 'S' \
               || x == 'd' || x == 'c' ||x == 'o' || x == 'x' || x == 's' \
               || x == 'u' || x == 'U'  \
               || x == '%' || x == 'p'  \
               || x == 'f'

#define  TYPESTO(x) x != 's' && x != 'c' && x != 'o' && x != 'x' && x != 'u' && x != 'd' &&  x != 'i' && x != 'p'  \
                 && x != 'S' && x != 'C' && x != 'O' && x != 'X' && x != 'U' && x != 'D' && x != '\n' && x != '%'  \
                 && x != 'f'

/*
** ----------------------------------------- Masks ---------------------------------------------------------
*/

# define    F_SHARP		 (1 << 0)               //  #
# define    F_SPACE		 (1 << 1)               //  sp
# define    F_PLUS		 (1 << 2)               //  +
# define    F_MINUS		 (1 << 3)               //  -
# define    F_ZERO	     (1 << 4)               //  0

/*------------------------------------------ SIZES --------------------------------------------------------*/
/*                                                          d i                   u o x X                   */
# define    F_LONG		 (1 << 5)               //  l     (long int)         (unsigned long int)       32
# define    F_LONG2		 (1 << 6)               //  ll    (long long int)    (unsigned long long int)  64
# define    F_SHORT	     (1 << 7)               //  h     (short  int)                                 128
# define    F_SHORT2     (1 << 8)               //  hh    (signed char)                                256
# define    F_INTMAX     (1 << 9)               //  j     (intmax_t)                                   512
# define    F_SIZE_T     (1 << 10)              //  z     (size_t)                                     1024

/*-------------------------------------- Specifier -----------------------------------------------------*/

#define     S_INT        (1 << 0)               //  integer or digit
#define     S_UINT       (1 << 1)               //  unsigned int
#define     S_HEX        (1 << 2)               //  heximal
#define     S_OCT        (1 << 3)               //  octal
#define     S_CHR        (1 << 4)               //  char
#define     S_STR        (1 << 5)               //  string
#define     S_PRC        (1 << 6)               //  percent
#define     S_PTR        (1 << 7)               //  pointer

/*-------------------------------------- COLOR MASKS -----------------------------------------------------*/

# define    RED         "\33[0;31m"	//Red
# define    B_RED       "\33[1;31m"	//Bold Red
# define    GREEN       "\33[0;32m"	//Green
# define    B_GREEN     "\33[1;32m"	//Bold Green
# define    YELLOW      "\33[0;33m"	//Yellow
# define    B_YELLOW    "\33[01;33m"//Bold Yellow
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

typedef struct		    s_printf
{
/*----- section for $ line manipulation -----*/
    va_list	        	first_arg;
    va_list		        itera_arg;
/*-------------------------------------------*/
	short	        	flag;
	short		        length;
	int	                width;
	int	                precision;                   // boolean
    int                 skip;
	int                 x;
    int                 check_point;
    int                 check_point_two;
	char                *m_content;
    int                 heigh;
	int                 nbr_wd_len;                 // length of word or nbr
	int                 negnum;
    int	                warg;                       // $
    int                 sizeReturn;
    int                 size_teml;
	char                specifier;
	int                 buffer_p_counter;
	char                str[BUFFER_P];
}			            t_printf;

/*----------------------------------------- Key value --------------------------------------------------------*/

typedef union   fldd
{
    float       f;
    double      d;
    long double ld;
}               fldd;

typedef struct          s_custom_f
{
    fldd                src;
    int                 sign : 1;
    int                 width_exp;
    int                 exponent;
    int                 mantisa;
    int                 mantisa_length;
}                       t_custom_f;


typedef struct          s_operators
{
    int                 out_put_function;
    void                (*fn)(t_printf*);
}                       t_operators;

typedef struct          s_unioner
{
    int                 out_put_function;
    void                (*fn)(t_custom_f, t_printf*);
}                       t_unioner;


int     ft_abs(int nbr, t_printf *base);
int     ft_printf(char *fmt, ...);
int 	parsing(t_printf *base);
void    parse_flags(t_printf *base);
int     ft_strlens(char *str);
size_t  ft_strlen(const char *s);
size_t	ft_strlen_color(const char *s, t_printf *base);

void    ft_convert(unsigned long long k, int big_spec, t_printf *base);
void    ft_hex(unsigned long long k, int sys, int b, t_printf *base);
int     counthex(long long int hex, int sys);

void    ft_hex_out_put(t_printf *base);

void	ft_put_count_buffer(char *str, t_printf *base, int size);
void    ft_putstr_count(char *s, t_printf *base);
void    ft_put_count(char a, t_printf *base);
void	ft_putwchar(wchar_t wc, t_printf *base);
void	ft_putchar(char c, t_printf *base);

void    ft_go_oct(t_printf *base, unsigned long long num);
void    ft_oct_out_put(t_printf *base);


/*----------------OUTPUT CHAR-----------*/
void	out_put_char(t_printf *base);
void    ft_putchar_mod(t_printf *base, unsigned int octet);
int     s_c_bits_lens(unsigned int nbr);
int		ft_padding_space(int times, t_printf *base);
int     ft_padding_zero(int times, t_printf *base);
int     counthex(long long hex, int sys);

/*----------------Digit out put----------*/
void	ft_putnbr(unsigned long long int n, t_printf *base);

/*-------------------- d i --------------*/
void	ft_putnbr_mod(t_printf *base, unsigned long long int nbr);
void	ft_putnbr_prec(t_printf *base, intmax_t nbr);
/*-------------------- f --------------*/
void    out_put_flow(t_printf *base);
/*-------------------- c --------------*/
void    ft_putw_count(char a, t_printf *base);

/*-------------------- p --------------*/
void    out_put_pointer(t_printf *base);
/*-------------------- s --------------*/
void    out_put_string(t_printf *base);

int     out_put_space_or_zero(t_printf *base);
void    ft_hex_precision(t_printf *base, unsigned long long num);
void    out_put_percent(t_printf *base);
/*-------------------- f --------------*/

void	get_int_di(t_printf *base);
/*------------------- Exponent ------------------*/
void    extract_exponent_f(t_custom_f *digit, t_printf *base);
void    extract_exponent_d(t_custom_f *digit, t_printf *base);
/*------------------ Mantissa -------------------*/
void    extract_mantissa_f(t_custom_f *digit, t_printf *base);
void    extract_mantissa_d(t_custom_f *digit, t_printf *base);
/*------------------- math -----------*/
int     roundcustomf(float num);
int     roundcustomd(float num);
int     custom_pow(long long int digit, int degree);

#endif



//#define  VALID(x) x == 's' || x == 'S' || x == 'p' || x == 'd' || x == 'D' || x == 'i' || x == 'o' || x == 'O' \
//|| x == 'u' || x == 'U' || x == 'x' || x == 'X' || x == 'c' || x == 'C' || x == ' ' || x == 'l' || \
// x == 'h' || x == 'j' || x == 'z' || (x >= '0' && x <= '9') || x == 'h'\
// || x == '.' || x == '$' || x == '+' ||  x == '#' || x == '-' || x == '*'
//
//#define  TYPET(x) x == 's' || x == 'S' || x == 'p' || x == 'd' || x == 'D' || x == 'i' || x == 'o' || x == 'O' \
//|| x == 'u' || x == 'U' || x == 'x' || x == 'X' || x == 'c' || x == 'C' || x == '\0' || x == '%'
//
//#define  VALID_P(x) x == ' ' || x == 'l' || x == 'h' || x == 'j' || x == 'z' || (x >= '0' && x <= '9') || x == 'h'\
// || x == '.' || x == '$' || x == '+' ||  x == '#' || x == '-' || x == '*'
//
//#define CHR_VAL(x) x = (unsigned int)x;
//
//#define MAX_NEGATIVE -9223372036854775808
