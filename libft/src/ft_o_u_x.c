/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_o_u_x.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 15:38:02 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 14:46:06 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int		end_o(char *str, int count, t_printf *stock)
{
	if (stock->pres != -1 && (size_t)stock->pres > ft_strlen(str))
		count += stock->pres - ft_strlen(str);
	if (stock->f_diez && str[0] != '0' &&
			stock->pres < (int)ft_strlen(str))
		count++;
	if ((size_t)stock->width > ft_strlen(str) &&
			stock->pres < stock->width)
		count = stock->width;
	return (count);
}

int		check_complet_charu(unsigned long nbr, int i, char l, t_printf *stock)
{
	int		tmp;

	if (ft_countunbr(nbr) < (stock->width + i))
	{
		if (stock->pres > ft_countunbr(nbr))
			tmp = stock->width - i - stock->pres;
		else
			tmp = stock->width - i - ft_countunbr(nbr);
		while (tmp-- > 0)
			ft_putchar(l);
		i = stock->width;
	}
	else
		i += ft_countunbr(nbr);
	return (i);
}

int		with_widthu(unsigned long nbr, t_printf *stock)
{
	int		count;

	count = 0;
	if (stock->f_minus)
	{
		ft_putunbrwp(nbr, stock->pres);
		count = check_complet_charu(nbr, count, ' ', stock);
	}
	else if (stock->f_zero)
	{
		count = check_complet_charu(nbr, count, '0', stock);
		ft_putunbrwp(nbr, stock->pres);
	}
	else
	{
		count += check_complet_charu(nbr, count, ' ', stock);
		ft_putunbrwp(nbr, stock->pres);
	}
	return (count);
}

int		ft_u(unsigned long nbr, t_printf *stock)
{
	int		count;

	count = 0;
	if (!stock->pres && !nbr)
		return (0);
	if (stock->width)
		count = with_widthu(nbr, stock);
	else
	{
		count = ft_countunbr(nbr);
		ft_putunbrwp(nbr, stock->pres);
		if (stock->pres >= ft_countunbr(nbr))
			count++;
	}
	if (stock->pres > ft_countunbr(nbr))
	{
		if (stock->width > stock->pres)
			count = stock->width;
		else
			count = stock->pres;
	}
	return (count);
}

int		ft_oux(unsigned long nbr, char le, t_printf *stock)
{
	if (le == 'o' || le == 'O')
		return (ft_o(nbr, stock));
	else if (le == 'u' || le == 'U')
		return (ft_u(nbr, stock));
	else
		return (ft_x(nbr, le, stock));
	return (0);
}
