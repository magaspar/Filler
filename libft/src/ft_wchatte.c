/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wchatte.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 15:49:40 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 14:45:04 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void		print_wchar(wchar_t *str, int countp)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i] && (countp > j))
	{
		ft_unicode(str[i]);
		j += ft_count_unicode(str[i]);
	}
}

int			count_pres(wchar_t *str, t_printf *stock)
{
	int		count;
	int		i;

	count = 0;
	i = -1;
	while (str[++i] && ((count + ft_count_unicode(str[i])) <= stock->pres))
		count += ft_count_unicode(str[i]);
	return (count);
}

int			w_pres(wchar_t *str, t_printf *stock)
{
	int		i;
	int		countp;

	i = -1;
	countp = count_pres(str, stock);
	if (stock->f_minus)
		print_wchar(str, countp);
	if (stock->width)
	{
		i = stock->width - countp;
		if (stock->f_zero)
			while (i-- > 0)
				ft_putchar('0');
		else
			while (i-- > 0)
				ft_putchar(' ');
		i = -1;
	}
	if (!stock->f_minus)
		print_wchar(str, countp);
	if (stock->width > countp)
		return (stock->width);
	return (countp);
}

void		w_width(wchar_t *str, t_printf *stock)
{
	int	i;
	int	count;

	i = -1;
	if (stock->f_minus)
		while (str[++i])
			ft_unicode(str[i]);
	count = stock->width - ft_count_multiple_unicode(str);
	if (stock->f_zero)
		while (count-- > 0)
			ft_putchar('0');
	else
		while (count-- > 0)
			ft_putchar(' ');
	if (!stock->f_minus)
		while (str[++i])
			ft_unicode(str[i]);
}

int			ft_smaj(wchar_t *str, t_printf *stock)
{
	int			count;
	int			i;

	if (!str)
		return (is_null(stock));
	count = 0;
	i = -1;
	if (stock->pres != -1)
		return (w_pres(str, stock));
	else if (stock->width)
		w_width(str, stock);
	else
		while (str[++i])
			ft_unicode(str[i]);
	count = ft_count_multiple_unicode(str);
	if (stock->width > count)
		return (stock->width);
	return (count);
}
