/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_l.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 15:33:17 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 14:46:18 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char		check_plus_spacel(long nbr, t_printf *stock)
{
	char	count;

	count = 0;
	if (stock->f_plus && nbr >= 0)
	{
		ft_putchar('+');
		count++;
	}
	else if (stock->f_space && nbr >= 0)
	{
		ft_putchar(' ');
		count++;
	}
	return (count);
}

int			check_complet_charl(long nbr, int count, char le, t_printf *stock)
{
	int		tmp;

	if (ft_countnbr(nbr) < (stock->width + count))
	{
		if (le == ' ' && stock->f_space && stock->f_diez &&
				!stock->f_minus)
			stock->width--;
		if (stock->pres >= ft_countnbr(nbr))
		{
			tmp = stock->width - count - stock->pres;
			if (nbr < 0)
				tmp--;
		}
		else
			tmp = stock->width - count - ft_countnbr(nbr);
		while (tmp-- > 0)
			ft_putchar(le);
		return (stock->width);
	}
	else
		count += ft_countnbr(nbr);
	return (count);
}

int			with_width_zero(long nbr, t_printf *stock)
{
	int		count;

	count = 0;
	if (stock->pres != -1)
		count = check_complet_charl(nbr, count, ' ', stock);
	count += check_plus_spacel(nbr, stock);
	if (nbr < 0)
		ft_putchar('-');
	if (stock->pres == -1)
		count = check_complet_charl(nbr, count, '0', stock);
	if (nbr < 0)
		nbr = -nbr;
	ft_putnbrwp(nbr, stock->pres);
	return (count);
}

int			with_widthl(long nbr, t_printf *stock)
{
	int		count;

	count = 0;
	if (stock->f_minus)
	{
		count += check_plus_spacel(nbr, stock);
		ft_putnbrwp(nbr, stock->pres);
		count = check_complet_charl(nbr, count, ' ', stock);
	}
	else if (stock->f_zero)
		count = with_width_zero(nbr, stock);
	else
	{
		if ((stock->f_plus || stock->f_space) && nbr >= 0)
			count++;
		count = check_complet_charl(nbr, count, ' ', stock);
		count += check_plus_spacel(nbr, stock);
		if ((stock->f_plus || stock->f_minus) && nbr >= 0)
			count--;
		ft_putnbrwp(nbr, stock->pres);
	}
	return (count);
}

int			ft_l(long nbr, t_printf *stock)
{
	long	count;

	if (!nbr && !stock->pres)
	{
		count = stock->width > 0 ? stock->width : 0;
		while (stock->width-- > 0)
			ft_putchar(' ');
		return (count);
	}
	if (stock->width)
		count = with_widthl(nbr, stock);
	else
	{
		count = check_plus_spacel(nbr, stock) + ft_countnbr(nbr);
		ft_putnbrwp(nbr, stock->pres);
		if (stock->pres >= ft_countnbr(nbr))
			count++;
	}
	if (nbr && stock->pres > ft_countnbr(nbr))
	{
		count = (nbr < 0) ? stock->pres + 1 : stock->pres;
		count = (stock->width > stock->pres) ? stock->width : count;
	}
	return (count);
}
