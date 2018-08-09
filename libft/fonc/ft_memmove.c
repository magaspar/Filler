/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 18:06:42 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 18:06:42 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*s1;
	unsigned char		*s2;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	i = 0;
	if (s1 > s2)
	{
		while (i < n)
		{
			s1[n - 1] = s2[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	return (dest);
}
