/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_x_movie.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 15:52:57 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 16:06:36 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#define B "0123456789abcdef"
#define BU "0123456789ABCDEF"

void		ft_putx(char *str, t_printf *stock)
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

int			check_complet_charx(char *nbr, char letter, t_printf *stock)
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
			tmp -= 2;
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

int			with_widthx(char *nbr, char letter, t_printf *stock)
{
	int		count;

	if (stock->f_minus)
	{
		if (stock->f_diez && !(ft_strlen(nbr) == 1 && nbr[0] == '0'))
			ft_putzerox(letter);
		ft_putx(nbr, stock);
		count = check_complet_charx(nbr, ' ', stock);
	}
	else if (stock->f_zero)
	{
		if (stock->f_diez && !(ft_strlen(nbr) == 1 && nbr[0] == '0'))
			ft_putzerox(letter);
		count = check_complet_charx(nbr, '0', stock);
		ft_putx(nbr, stock);
	}
	else
	{
		count = check_complet_charx(nbr, ' ', stock);
		if (stock->f_diez && !(ft_strlen(nbr) == 1 && nbr[0] == '0'))
			ft_putzerox(letter);
		ft_putx(nbr, stock);
	}
	return (count);
}

int			without_width(char *str, char letter, t_printf *stock)
{
	if (stock->f_diez && !(ft_strlen(str) == 1 && str[0] == '0'))
		ft_putzerox(letter);
	ft_putx(str, stock);
	return (ft_strlen(str));
}

int			ft_x(unsigned long nbr, char letter, t_printf *stock)
{
	char	*str;
	int		count;

	if (!nbr && !stock->pres)
	{
		count = stock->width;
		while (stock->width-- > 0)
			ft_putchar(' ');
		if (count)
			return (count);
		return (0);
	}
	str = (letter == 'x') ? ft_itoabase(nbr, B, 16) : ft_itoabase(nbr, BU, 16);
	if (stock->width)
		count = with_widthx(str, letter, stock);
	else
		count = without_width(str, letter, stock);
	if ((stock->pres != -1) && ((size_t)stock->pres > ft_strlen(str)))
		count += stock->pres - ft_strlen(str);
	if (stock->f_diez && !(ft_strlen(str) == 1 && str[0] == '0'))
		count += 2;
	if ((size_t)stock->width > ft_strlen(str) && stock->pres < stock->width)
		count = stock->width;
	free(str);
	return (count);
}
