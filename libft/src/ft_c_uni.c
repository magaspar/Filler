/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_c_uni.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 15:31:21 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/12 16:44:06 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int			ft_count_unicode(wchar_t c)
{
	if ((c >> 16) != 0)
		return (4);
	else if ((c >> 11) != 0)
		return (3);
	else if ((c >> 7) != 0)
		return (2);
	else
		return (1);
}

int			ft_count_multiple_unicode(wchar_t *str)
{
	int			i;
	int			count;

	i = -1;
	count = 0;
	while (str[++i])
		count += ft_count_unicode(str[i]);
	return (count);
}

void		ft_unicode(unsigned int c)
{
	if ((c >> 16) != 0)
		four_bytes(c);
	else if ((c >> 11) != 0)
		three_bytes(c);
	else if ((c >> 7) != 0)
		two_bytes(c);
	else
		ft_putchar(c);
}

int			ft_cwl(wint_t c, t_printf *stock)
{
	int		count;

	if (stock->width)
	{
		if (ft_count_unicode(c) > 1)
			count = stock->width - ft_count_unicode(c);
		else
			count = stock->width - 1;
		if (stock->f_minus)
			ft_unicode(c);
		while (count-- > 0)
			ft_putchar(' ');
		if (!stock->f_minus)
			ft_unicode(c);
	}
	else
		ft_unicode(c);
	count = ft_count_unicode(c);
	if (stock->width > count)
		return (stock->width);
	return (count);
}

int			ft_c(int c, t_printf *stock)
{
	int				count;
	unsigned char	cha;

	count = 0;
	cha = c & 255;
	if (stock->width)
	{
		count = stock->width;
		if (stock->f_minus)
			ft_putchar(cha);
		if (stock->f_zero)
			while (--count)
				ft_putchar('0');
		else
			while (--count)
				ft_putchar(' ');
		if (!stock->f_minus)
			ft_putchar(cha);
		return (stock->width);
	}
	ft_putchar(cha);
	return (1);
}
