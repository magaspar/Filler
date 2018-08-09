/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_tree.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 15:45:10 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 16:20:36 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

unsigned long		cast_lenu(va_list ap, t_printf *stock)
{
	if (!stock->length)
		return (va_arg(ap, unsigned int));
	else if (!ft_strcmp(stock->length, "l") ||
			!ft_strcmp(stock->length, "ll") ||
			!ft_strcmp(stock->length, "j"))
		return (va_arg(ap, unsigned long));
	else if (!ft_strcmp(stock->length, "h"))
		return ((unsigned short)va_arg(ap, unsigned int));
	else if (!ft_strcmp(stock->length, "hh"))
		return ((unsigned char)va_arg(ap, unsigned int));
	else
		return (va_arg(ap, ssize_t));
}

long				cast_len(va_list ap, t_printf *stock)
{
	if (!stock->length)
		return (va_arg(ap, int));
	else if (!ft_strcmp(stock->length, "l"))
		return (va_arg(ap, long));
	else if (!ft_strcmp(stock->length, "ll"))
		return (va_arg(ap, long long));
	else if (!ft_strcmp(stock->length, "j"))
		return (va_arg(ap, intmax_t));
	else if (!ft_strcmp(stock->length, "h"))
		return ((short)va_arg(ap, int));
	else if (!ft_strcmp(stock->length, "hh"))
		return ((char)va_arg(ap, int));
	else
		return (va_arg(ap, size_t));
}

int					treatbis(char c, t_printf *stock, va_list ap)
{
	if (c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' ||
			c == 'X')
	{
		if (c == 'O' || c == 'U')
			return (ft_oux(va_arg(ap, unsigned long), c, stock));
		return (ft_oux(cast_lenu(ap, stock), c, stock));
	}
	else if (c == 'c' || c == 'C')
	{
		if (c == 'C' || (stock->length && !ft_strcmp(stock->length, "l")))
			return (ft_cwl(va_arg(ap, wint_t), stock));
		return (ft_c(va_arg(ap, int), stock));
	}
	else if (c == '%')
		return (ft_percent(stock));
	return (ft_invalid_input(c, stock));
}

int					treat(t_printf *stock, va_list ap)
{
	char c;

	c = stock->conversion;
	if (c == 's' || c == 'S')
	{
		if (c == 'S' || (stock->length && !ft_strcmp(stock->length, "l")))
			return (ft_smaj(va_arg(ap, wchar_t*), stock));
		return (ft_s(va_arg(ap, char*), stock));
	}
	else if (c == 'p')
		return (ft_p(va_arg(ap, void*), stock));
	else if (c == 'd' || c == 'i' || c == 'D')
	{
		if (c == 'D')
			return (ft_l(va_arg(ap, long), stock));
		return (ft_l(cast_len(ap, stock), stock));
	}
	else
		return (treatbis(c, stock, ap));
}
