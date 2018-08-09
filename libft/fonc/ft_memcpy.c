/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 18:06:42 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 18:06:42 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, void *src, size_t n)
{
	size_t				i;
	unsigned char		*s1;
	unsigned char		*s2;

	i = 0;
	s1 = dest;
	s2 = src;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dest);
}
