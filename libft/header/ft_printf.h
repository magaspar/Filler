/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 18:50:43 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/22 15:28:59 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../fonc/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFF_SIZE 100

typedef struct		s_printf
{
	char			f_diez;
	char			f_zero;
	char			f_minus;
	char			f_plus;
	char			f_space;
	int				width;
	int				pres;
	char			*length;
	char			conversion;
}					t_printf;

void				one_byte(char c);
void				four_bytes(wchar_t c);
void				three_bytes(wchar_t c);
void				two_bytes(wchar_t c);

int					ft_count_unicode(wchar_t c);
int					ft_count_multiple_unicode(wchar_t *str);
void				ft_unicode(unsigned int c);
int					ft_cwl(wint_t c, t_printf *stock);
int					ft_c(int c, t_printf *stock);

int					with_width_invalid(char c, t_printf *stock);
int					ft_invalid_input(char c, t_printf *stock);

char				check_plus_spacel(long nbr, t_printf *stock);
int					check_complet_charl(long nbr,
		int count, char letter, t_printf *stock);
int					with_width_zero(long nbr, t_printf *stock);
int					with_widthl(long nbr, t_printf *stock);
int					ft_l(long nbr, t_printf *stock);

void				ft_puto(char *str, t_printf *stock);
int					check_complet_charo(char *nbr,
		char letter, t_printf *stock);
void				putzero_ifsharp(char *nbr, t_printf *stock);
int					with_widtho(char *nbr, t_printf *stock);
int					ft_o(unsigned long nbr, t_printf *stock);

int					end_o(char *str, int count, t_printf *stock);
int					check_complet_charu(unsigned long nbr,
		int i, char l, t_printf *stock);
int					with_widthu(unsigned long nbr, t_printf *stock);
int					ft_u(unsigned long nbr, t_printf *stock);
int					ft_oux(unsigned long nbr, char letter, t_printf *stock);

int					with_width_percent(t_printf *stock);
int					ft_percent(t_printf *stock);

void				ft_putp(char *str, t_printf *stock);
int					check_complet_charp(char *nbr,
		char letter, t_printf *stock);
int					with_widthp(char *nbr, t_printf *stock);
int					ft_p(void *address, t_printf *stock);

int					del_stock(t_printf *stock, int nbr);
int					go_args(char **str, va_list ap);
int					go_solve(char *str, va_list ap, int bytes);
int					ft_printf(const char *format, ...);

unsigned long		cast_lenu(va_list ap, t_printf *stock);
long				cast_len(va_list ap, t_printf *stock);
int					treatbis(char c, t_printf *stock, va_list ap);
int					treat(t_printf *stock, va_list ap);

char				*check_flags(char **str, t_printf *stock);
char				*check_width(char **str, t_printf *stock);
char				*check_pres(char **str, t_printf *stock);
char				*check_len(char **s, t_printf *stock);
int					check_conv(char **str, char *cha, t_printf *stock);

int					is_normal(char *str, t_printf *stock);
int					is_null(t_printf *stock);
int					ft_s(char *str, t_printf *stock);

void				print_wchar(wchar_t *str, int countp);
int					count_precision(wchar_t *str, t_printf *stock);
int					w_precision(wchar_t *str, t_printf *stock);
void				w_width(wchar_t *str, t_printf *stock);
int					ft_smaj(wchar_t *str, t_printf *stock);

void				ft_putx(char *str, t_printf *stock);
int					check_complet_charx(char *nbr,
		char letter, t_printf *stock);
int					with_widthx(char *nbr, char letter, t_printf *stock);

short				ft_countnbr(long nbr);
short				ft_countunbr(unsigned long nbr);
void				ft_putunbrwp(unsigned long nbr, int precision);
void				ft_putzerox(char letter);

void				ft_putnbrwp(long nbr, int precision);
void				ft_putwchar(wchar_t c);
void				ft_putstrwp(char *str, int precision);

char				*ft_itoabase(uintmax_t nbr, char *base, int baselen);
char				*res(int i, int n, int *convert);
void				ft_putnstr(char *str, int n);

int					ft_x(unsigned long nbr, char letter, t_printf *stock);

typedef struct		s_save
{
	int				fd;
	char			*buf;
	struct s_save	*next;
}					t_save;

int					get_next_line(const int fd, char **line);

#endif
