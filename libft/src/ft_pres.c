/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pres.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 15:40:05 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 14:45:53 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void		ft_putp(char *str, t_printf *stock)
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

int			check_complet_charp(char *nbr, char letter, t_printf *stock)
{
	int		tmp;
	int		count;

	if (ft_strlen(nbr) + 2 < (size_t)(stock->width))
	{
		tmp = stock->width - ft_strlen(nbr) - 2;
		while (tmp-- > 0)
			ft_putchar(letter);
		count = stock->width;
	}
	else
		count = ft_strlen(nbr) + 2;
	return (count);
}

int			with_widthp(char *nbr, t_printf *stock)
{
	int		count;

	if (stock->f_minus)
	{
		ft_putstr("0x");
		ft_putp(nbr, stock);
		count = check_complet_charp(nbr, ' ', stock);
	}
	else if (stock->f_zero)
	{
		ft_putstr("0x");
		count = check_complet_charp(nbr, '0', stock);
		ft_putp(nbr, stock);
	}
	else
	{
		count = check_complet_charp(nbr, ' ', stock);
		ft_putstr("0x");
		ft_putp(nbr, stock);
	}
	return (count);
}

int			ft_p(void *address, t_printf *stock)
{
	char	*str;
	int		count;

	str = ft_itoabase((uintmax_t)address, "0123456789abcdef", 16);
	if (str[0] == '0' && ft_strlen(str) == 1 && !stock->pres)
	{
		count = stock->width > 0 ? stock->width : 0;
		while (stock->width-- > 0)
			ft_putchar(' ');
		ft_putstr("0x");
		return (count + 2);
	}
	if (stock->width)
		count = with_widthp(str, stock);
	else
	{
		ft_putstr("0x");
		ft_putp(str, stock);
		count = ft_strlen(str) + 2;
	}
	if ((stock->pres != -1) && ((size_t)stock->pres > ft_strlen(str)))
		count += stock->pres - ft_strlen(str);
	free(str);
	return (count);
}
