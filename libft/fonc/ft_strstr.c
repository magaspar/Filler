/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 18:06:49 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 18:06:49 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (needle[i] != '\0')
		i++;
	if (i == 0)
		return ((char *)haystack);
	while (haystack[j] != '\0')
	{
		while (needle[k] == haystack[k + j])
		{
			if (k == i - 1)
				return ((char*)haystack + j);
			k++;
		}
		k = 0;
		j++;
	}
	return (NULL);
}
