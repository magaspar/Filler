/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 18:06:49 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 18:06:49 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;
	char		*str;

	i = 0;
	j = ft_strlen(s) - 1;
	if (!s)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && s[j] != '\0'
			&& j > i)
		j--;
	str = ft_strsub(s, i, (j - i + 1));
	return (str);
}
