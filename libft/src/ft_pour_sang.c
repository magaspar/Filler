/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pour_sang.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 15:42:04 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/12 16:44:17 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int			with_width_percent(t_printf *stock)
{
	int		count;

	count = stock->width - 1;
	if (stock->f_minus)
	{
		ft_putchar('%');
		while (count-- > 0)
			ft_putchar(' ');
	}
	else if (stock->f_zero)
	{
		while (count-- > 0)
			ft_putchar('0');
		ft_putchar('%');
	}
	else
	{
		while (count-- > 0)
			ft_putchar(' ');
		ft_putchar('%');
	}
	return (stock->width);
}

int			ft_percent(t_printf *stock)
{
	int		count;

	count = 0;
	if (stock->width)
		count = with_width_percent(stock);
	else
	{
		ft_putchar('%');
		count++;
	}
	return (count);
}
