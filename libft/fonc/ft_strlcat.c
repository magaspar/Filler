/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 18:06:46 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 18:06:46 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	int			k;

	i = 0;
	j = 0;
	k = 0;
	while (dst[i] && i < size)
		i++;
	k = ft_strlen(src) + i;
	if (i != size)
	{
		while (i < size - 1)
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	return (k);
}
