/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 18:06:41 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 18:06:41 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	unsigned char	*allo;
	size_t			i;

	i = 0;
	allo = malloc(size);
	if (allo)
	{
		while (i < size)
		{
			allo[i] = '\0';
			i++;
		}
		return ((void *)allo);
	}
	else
		return (NULL);
}
