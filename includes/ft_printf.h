#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_print
{
	int	len;
	int	dot;
	int	dot_pos;
	int	minus;
	int	min_pos;
	int	zero;
	int	nb1;
	int	is_neg1;
	int	nb2;
	int	is_neg2;
}	t_print;

void			init_struct(t_print *prt);

int				ft_printf(const char *str, ...);
int				find_conv(const char *str, va_list args, int *i, t_print *prt);
int				is_conv(char l);
int				getFlag(char *flags, t_print *prt, va_list args);
void			redirect(char *flags, va_list args, t_print *prt);
void			redirect_flag(t_print *prt, va_list args, char *flags);

void			ft_putchar(char c, t_print *prt);
void			ft_putnbr(long long int n, t_print *prt);
void			ft_putstr(char *s, t_print *prt);
void			ft_putnstr(char *s, t_print *prt, int n);
void			ft_put_and_free(char *s, t_print *prt, char c);
void			put_itoh(long long n, int maj, t_print *prt);
void			put_doubleD(t_print *prt, char *s, char c);
void			ft_put_if(char *d, t_print *prt, char c, int a);
void			putspaces(char c, va_list args, t_print *prt);
void			ft_putP(long long ptr, t_print *prt);
void			precNUL(va_list args, t_print *prt);

int				absolute(int a, t_print *prt, int n);
int				max(int a, int b);
int				base10(long long int n);
char			*new_itoa(long long int n);
char			*itoh(long long int n, int maj);
long long int	new_atoi(char *str, int *i);

void			flag_MD(va_list args, t_print *prt, char c);
void			flag_MD_int(va_list args, t_print *prt);
void			flag_MD_u(va_list args, t_print *prt);
void			flag_MD_x(va_list args, t_print *prt, char c);
void			flag_2MD(va_list args, t_print *prt);
void			flag_2MD_s(va_list args, t_print *prt);

void			putzero_i(int d, t_print *prt);
void			putzero_u(unsigned int u, t_print *prt);
void			putzero_x(char *x, t_print *prt);

void			flag_minus_int(t_print *prt, va_list args, char c);
void			flag_minus_x(t_print *prt, va_list args, char c);
void			flag_number(t_print *prt, va_list args, char *flags);
void			flag_zero(t_print *prt, va_list args, char c);
void			flag_minus(t_print *prt, va_list args, char c);
void			flag_doubleD(t_print *prt, va_list args, char c);

#endif
