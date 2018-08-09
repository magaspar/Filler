/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 18:06:41 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 18:06:41 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *momo;

	momo = (t_list *)malloc(sizeof(t_list));
	if (momo == NULL)
		return (NULL);
	if (content != NULL)
	{
		momo->content = malloc(content_size);
		if (content == NULL)
			return (NULL);
		ft_memcpy(momo->content, (void *)content, content_size);
		momo->content_size = content_size;
	}
	else
	{
		momo->content = NULL;
		momo->content_size = 0;
	}
	momo->next = NULL;
	return (momo);
}
