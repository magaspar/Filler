/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/22 15:24:20 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/22 15:24:22 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int	main(void)
{
	t_flr	*box;
	int		stop;

	stop = 0;
	box = NULL;
	while (101)
	{
		box = init_box(box, stop);
		stop = 1;
		if (ft_putable(box) == 101)
		{
			box = freeing_box(box, 1);
			ft_printf("0 0\n");
			exit(1);
		}
		else
		{
			if (box->dodo > 0 || ft_algo2(box))
				ft_put_piece(box, -1, -1, 0);
		}
		box = freeing_box(box, 0);
	}
	return (0);
}
