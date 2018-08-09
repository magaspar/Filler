/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 18:06:41 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 18:06:41 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*s1;
	unsigned char		*s2;

	i = 0;
	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	if (dest != NULL && src != NULL)
	{
		while (i < n)
		{
			s1[i] = s2[i];
			if (s2[i] == c)
				return (&s1[i + 1]);
			i++;
		}
	}
	return (NULL);
}
