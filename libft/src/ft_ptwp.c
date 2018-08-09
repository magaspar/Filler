/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ptwp.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 17:09:51 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 18:35:55 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void		ft_putnbrwp(long nbr, int pres)
{
	short count;

	if (pres > 0)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		count = ft_countnbr(nbr);
		count = pres - count;
		while (count-- > 0)
			ft_putchar('0');
	}
	if (nbr == -9223372036854775807 - 1)
		ft_putstr("-9223372036854775808");
	else if (nbr || pres)
		ft_putnbr(nbr);
}

void		ft_putwchar(wchar_t c)
{
	write(1, &c, 1);
}

void		ft_putstrwp(char *str, int pres)
{
	if ((pres != -1) && ((size_t)pres < ft_strlen(str)))
	{
		while (pres--)
		{
			ft_putchar(*str);
			str++;
		}
	}
	else
		ft_putstr(str);
}
