/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ss.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 15:48:16 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 14:44:55 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int			is_normal(char *str, t_printf *stock)
{
	int	count;
	int	size;

	if (stock->f_minus)
		ft_putstrwp(str, stock->pres);
	if ((stock->pres != -1) && (size_t)stock->pres < ft_strlen(str))
		size = stock->pres;
	else
		size = ft_strlen(str);
	count = size;
	if (stock->width > size)
		count = stock->width;
	if (stock->f_zero && !stock->f_minus)
		while (stock->width-- > size)
			ft_putchar('0');
	else
		while (stock->width-- > size)
			ft_putchar(' ');
	if (!stock->f_minus)
		ft_putstrwp(str, stock->pres);
	return (count);
}

int			is_null(t_printf *stock)
{
	int		size;

	size = 0;
	if (stock->f_minus)
		ft_putstrwp("(null)", stock->pres);
	if (stock->width > 6 || (stock->width > stock->pres &&
				stock->pres != -1))
	{
		size += stock->width;
		if ((stock->pres != -1) && stock->pres < 6)
			size += 6 - stock->pres;
		while (size-- > 6)
			ft_putchar('0');
	}
	if (!stock->f_minus)
		ft_putstrwp("(null)", stock->pres);
	if (stock->width > 6 || (stock->width > stock->pres &&
				stock->pres != -1))
		return (stock->width);
	if ((stock->pres != -1) && (stock->pres < 6))
		return (stock->pres);
	return (6);
}

int			ft_s(char *str, t_printf *stock)
{
	int		count;

	count = 0;
	if (!str)
		return (is_null(stock));
	else if ((size_t)stock->width > ft_strlen(str) ||
			(stock->width > stock->pres))
		count = is_normal(str, stock);
	else
	{
		ft_putstrwp(str, stock->pres);
		if ((stock->pres != -1) && (size_t)stock->pres < ft_strlen(str))
			count += stock->pres;
		else
			count += ft_strlen(str);
	}
	return (count);
}
