/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsubf.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 17:07:07 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 17:56:06 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strsubf(char const *s, unsigned int start, size_t len)
{
	char		*sptr;

	if (!s)
		return (NULL);
	sptr = ft_strsub(s, start, len);
	ft_strdel((char **)&s);
	return (sptr);
}
