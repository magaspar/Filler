/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base_u.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 17:18:45 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 16:16:47 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void		ft_putnstr(char *str, int n)
{
	int		i;

	i = 0;
	while (str[i] && (i < n))
	{
		ft_putchar(str[i]);
		i++;
	}
}

char		*ft_strrev(char *str)
{
	int		i;
	int		b;
	char	c;

	i = 0;
	b = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	i--;
	while (i > b)
	{
		c = str[b];
		str[b] = str[i];
		str[i] = c;
		b++;
		i--;
	}
	return (str);
}

int			ft_countnb(uintmax_t nbr, int baselen)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	else
	{
		while (nbr)
		{
			nbr /= baselen;
			i++;
		}
		return (i);
	}
}

char		*ft_itoabase(uintmax_t nbr, char *base, int baselen)
{
	int		tmp;
	int		i;
	char	*ret;

	tmp = 0;
	i = 0;
	if ((ret = ft_strnew(ft_countnb(nbr, baselen))) == NULL)
		return (NULL);
	while (nbr != 0 || i == 0)
	{
		tmp = nbr % baselen;
		tmp = (tmp < 0) ? -tmp : tmp;
		ret[i] = base[tmp];
		nbr /= baselen;
		i++;
	}
	ret[i] = '\0';
	ft_strrev(ret);
	return (ret);
}
