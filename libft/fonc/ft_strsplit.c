/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 18:06:49 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 18:06:49 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		countword(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*s != '\0')
	{
		if (j == 1 && *s == c)
			j = 0;
		if (j == 0 && *s != c)
		{
			j = 1;
			i++;
		}
		s++;
	}
	return (i);
}

static int		wordsize(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	int			i;
	int			j;

	j = 0;
	i = countword(s, c);
	tab = (char **)malloc(sizeof(*tab) * (countword(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (i--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[j] = ft_strsub(s, 0, wordsize(s, c));
		if (tab[j] == NULL)
			return (NULL);
		s = s + wordsize(s, c);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
