/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 18:06:45 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 18:06:45 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(const char *s)
{
	int			a;
	char		*str;

	a = 0;
	while (s[a] != '\0')
	{
		a++;
	}
	str = (char *)malloc(sizeof(*s) * (a + 1));
	if (str == NULL)
		return (NULL);
	a = 0;
	while (s[a] != '\0')
	{
		str[a] = s[a];
		a++;
	}
	str[a] = '\0';
	return (str);
}
