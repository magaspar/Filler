/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 18:06:48 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 18:06:48 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	while (needle[i] != '\0')
		i++;
	if (i == 0)
		return ((char *)haystack);
	while (haystack[j] != '\0' && j <= len)
	{
		while ((needle[k] == haystack[k + j]) && (i + j <= len))
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
