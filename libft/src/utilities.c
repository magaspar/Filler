/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utilities.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 15:03:00 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 15:25:07 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void	ft_putunbr(unsigned long n)
{
	if (n > 9)
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
	else
		ft_putchar((char)(n + 48));
}

void	ft_putzerox(char le)
{
	if (le == 'x')
		ft_putstr("0x");
	else
		ft_putstr("0X");
}

short	ft_countnbr(long nbr)
{
	short	count;

	if (nbr == -9223372036854775807 - 1)
		return (20);
	if (!nbr)
		return (1);
	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	while (nbr)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

short	ft_countunbr(unsigned long nbr)
{
	short	count;

	if (!nbr)
		return (1);
	count = 0;
	while (nbr)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

void	ft_putunbrwp(unsigned long nbr, int pres)
{
	short count;

	if (pres > 0)
	{
		count = ft_countnbr(nbr);
		count = pres - count;
		while (count > 0)
		{
			ft_putchar('0');
			count--;
		}
	}
	if (nbr || pres)
		ft_putunbr(nbr);
}
