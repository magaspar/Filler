/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 15:43:00 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 15:13:52 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int			del_stock(t_printf *stock, int nbr)
{
	if (stock->length)
		free(stock->length);
	free(stock);
	return (nbr);
}

t_printf	*creat_stock(void)
{
	t_printf		*stock;

	stock = (t_printf*)malloc(sizeof(t_printf));
	stock->f_diez = 0;
	stock->f_zero = 0;
	stock->f_minus = 0;
	stock->f_plus = 0;
	stock->f_space = 0;
	stock->width = 0;
	stock->pres = -1;
	stock->length = NULL;
	stock->conversion = 0;
	return (stock);
}

int			go_args(char **str, va_list ap)
{
	t_printf		*stock;
	char			c;

	stock = creat_stock();
	(*str)++;
	while (1)
	{
		if (*str == '\0')
			return (del_stock(stock, 0));
		if (!(check_flags(str, stock)))
			return (del_stock(stock, 0));
		if (!check_width(str, stock))
			return (del_stock(stock, 0));
		if (!check_pres(str, stock))
			return (del_stock(stock, 0));
		if (!check_len(str, stock))
			return (del_stock(stock, 0));
		if (!check_conv(str, &c, stock))
			return (del_stock(stock, 0));
		if ((c != '#') && (c != '0') && (c != '-') && (c != '+') &&
				(c != ' ') && !((c >= 48) && (c <= 57)) && (c != '.') &&
				(c != 'h') && (c != 'l') && (c != 'j') && (c != 'z'))
			break ;
	}
	return (del_stock(stock, treat(stock, ap)));
}

int			go_solve(char *str, va_list ap, int bytes)
{
	char		*tmp;
	int			count;

	if (*str == '\0')
		return (bytes);
	tmp = ft_strchr(str, '%');
	if (!tmp)
	{
		ft_putstr(str);
		return (bytes + ft_strlen(str));
	}
	else if (tmp > str)
	{
		ft_putnstr(str, tmp - str);
		return (go_solve(tmp, ap, bytes + (tmp - str)));
	}
	else
	{
		if ((count = go_args(&str, ap)) == -1)
			return (0);
		else
			return (go_solve(str, ap, bytes + count));
	}
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;

	if (!format)
		return (0);
	va_start(ap, format);
	count = go_solve((char*)format, ap, 0);
	va_end(ap);
	return (count);
}
