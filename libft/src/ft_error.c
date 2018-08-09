/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 15:34:50 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/12 16:44:03 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int			with_width_invalid(char c, t_printf *stock)
{
	int		count;

	count = stock->width - 1;
	if (stock->f_minus)
	{
		ft_putchar(c);
		while (count-- > 0)
			ft_putchar(' ');
	}
	else if (stock->f_zero)
	{
		while (count-- > 0)
			ft_putchar('0');
		ft_putchar(c);
	}
	else
	{
		while (count-- > 0)
			ft_putchar(' ');
		ft_putchar(c);
	}
	return (stock->width);
}

int			ft_invalid_input(char c, t_printf *stock)
{
	int		count;

	count = 1;
	if (stock->width)
		count = with_width_invalid(c, stock);
	else
		ft_putchar(c);
	return (count);
}
