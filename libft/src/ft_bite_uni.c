/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bite_uni.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 15:51:51 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/12 16:44:14 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void		one_byte(char c)
{
	char		nbr;

	nbr = 2;
	nbr = (nbr << 6);
	nbr += c;
	ft_putchar(nbr);
}

void		four_bytes(wchar_t c)
{
	char		nbr;

	nbr = 30;
	nbr = (nbr << 3);
	nbr += (char)(c >> 18);
	c = (c & 65535);
	ft_putchar(nbr);
	nbr = 2;
	nbr = (nbr << 6);
	nbr += (char)(c >> 12);
	c = (c & 4095);
	ft_putchar(nbr);
	nbr = 2;
	nbr = (nbr << 6);
	nbr += (char)(c >> 6);
	c = (c & 63);
	ft_putchar(nbr);
	one_byte(c);
}

void		three_bytes(wchar_t c)
{
	int		nbr;

	nbr = 14;
	nbr = (nbr << 4);
	nbr += (char)(c >> 12);
	c = (c & 4095);
	ft_putchar(nbr);
	nbr = 2;
	nbr = (nbr << 6);
	nbr += (char)(c >> 6);
	c = (c & 63);
	ft_putchar(nbr);
	one_byte(c);
}

void		two_bytes(wchar_t c)
{
	int		nbr;

	nbr = 6;
	nbr = (nbr << 5);
	nbr += (c >> 6);
	c = (c & 63);
	ft_putchar(nbr);
	one_byte(c);
}
