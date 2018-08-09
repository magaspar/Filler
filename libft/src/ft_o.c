/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_o.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 15:36:11 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 14:46:12 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void		ft_puto(char *str, t_printf *stock)
{
	int		i;

	if ((stock->pres != -1) && ((size_t)stock->pres > ft_strlen(str)))
	{
		i = stock->pres - ft_strlen(str);
		while (i--)
			ft_putchar('0');
	}
	ft_putstr(str);
}

int			check_complet_charo(char *nbr, char letter, t_printf *stock)
{
	int		tmp;
	int		count;

	if (ft_strlen(nbr) < (size_t)(stock->width))
	{
		if ((stock->pres != -1) &&
				((size_t)stock->pres > ft_strlen(nbr)))
			tmp = stock->width - stock->pres;
		else
			tmp = stock->width - ft_strlen(nbr);
		if (stock->f_diez)
			tmp--;
		while (tmp-- > 0)
			ft_putchar(letter);
		if (stock->pres < stock->width)
			count = stock->width;
		else
			count = ft_strlen(nbr);
	}
	else
		count = ft_strlen(nbr);
	return (count);
}

void		putzero_ifsharp(char *nbr, t_printf *stock)
{
	if (stock->f_diez && !(ft_strlen(nbr) == 1 && nbr[0] == '0') &&
			stock->pres < (int)ft_strlen(nbr))
		ft_putchar('0');
}

int			with_widtho(char *nbr, t_printf *stock)
{
	int			count;

	if (stock->f_minus)
	{
		putzero_ifsharp(nbr, stock);
		ft_puto(nbr, stock);
		count = check_complet_charo(nbr, ' ', stock);
	}
	else if (stock->f_zero)
	{
		count = check_complet_charo(nbr, '0', stock);
		putzero_ifsharp(nbr, stock);
		ft_puto(nbr, stock);
	}
	else
	{
		count = check_complet_charo(nbr, ' ', stock);
		putzero_ifsharp(nbr, stock);
		ft_puto(nbr, stock);
	}
	return (count);
}

int			ft_o(unsigned long nbr, t_printf *stock)
{
	char		*str;
	int			count;

	if (!nbr && !stock->pres && !stock->f_diez)
	{
		count = stock->width > 0 ? stock->width : 0;
		while (stock->width-- > 0)
			ft_putchar(' ');
		return (count);
	}
	str = ft_itoabase(nbr, "0123456789abcdef", 8);
	if (stock->width)
		count = with_widtho(str, stock);
	else
	{
		putzero_ifsharp(str, stock);
		ft_puto(str, stock);
		count = ft_strlen(str);
	}
	count = end_o(str, count, stock);
	free(str);
	return (count);
}
