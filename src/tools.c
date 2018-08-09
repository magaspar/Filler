/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/22 15:25:22 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/22 15:26:17 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int			ft_is_placable(t_flr *box, int i, int j)
{
	int	k;
	int	l;
	int	sup;

	sup = 0;
	l = 0;
	while (l < box->piece_y)
	{
		k = 0;
		while (k < box->piece_x)
		{
			if (box->piece[l][k] == '*' && (j + l >= box->map_y || i + k >=
				box->map_x || ft_strchr(box->him, box->map[j + l][i + k])))
				return (0);
			else if (box->piece[l][k] == '*' &&
				ft_strchr(box->me, box->map[j + l][i + k]))
				sup++;
			k++;
		}
		l++;
	}
	if (sup == 1)
		return (1);
	else
		return (0);
}

int			ft_spe_poss(t_flr *box, int i, int j, int x)
{
	if (j - 1 >= 0 && j + 1 < box->map_y && i - 1 >= 0 && j + 1 < box->map_x)
	{
		if (ft_strchr(box->him, box->map[j - 1][i - 1]) &&
			ft_strchr(box->me, box->map[j - 1][i]) && ft_strchr(box->me,
			box->map[j][i - 1]))
			x = 200;
		else if (ft_strchr(box->him, box->map[j - 1][i + 1]) &&
			ft_strchr(box->me, box->map[j - 1][i]) && ft_strchr(box->me,
			box->map[j][i + 1]))
			x = 200;
		else if (ft_strchr(box->him, box->map[j + 1][i - 1]) &&
			ft_strchr(box->me, box->map[j][i - 1]) && ft_strchr(box->me,
			box->map[j + 1][i]))
			x = 200;
		else if (ft_strchr(box->him, box->map[j + 1][i + 1]) &&
			ft_strchr(box->me, box->map[j][i + 1]) && ft_strchr(box->me,
			box->map[j + 1][i]))
			x = 200;
	}
	return (x);
}

static int	ft_nbr_poss1(t_flr *box, int i, int j)
{
	int	ii;
	int	jj;
	int	nb;

	nb = 0;
	jj = -1;
	while (jj < 2 && (ii = -1))
	{
		while (ii < 2)
			if ((abs(ii++) == abs(jj)))
				;
			else if (j + jj < 0 || i + ii - 1 < 0 || j + jj >= box->map_y ||
				i + ii - 1 >= box->map_x)
				nb = nb + 10;
			else if (ft_strchr(box->me, box->map[j + jj][i + ii - 1]))
				nb = nb + ft_spe_poss(box, i + ii - 1, j + jj, 0) + 1;
			else if (ft_strchr(box->him, box->map[j + jj][i + ii - 1]))
				nb = nb + 60;
		jj++;
	}
	return (nb);
}

int			ft_nbr_poss(t_flr *box, int i, int j)
{
	int	nb;
	int	k;
	int	l;

	l = 0;
	nb = 0;
	while (l < box->piece_y && j + l < box->map_y)
	{
		k = 0;
		while (k < box->piece_x && i + k < box->map_x)
		{
			if (box->piece[l][k] == '*')
				nb += ft_nbr_poss1(box, i + k, j + l);
			k++;
		}
		l++;
	}
	return (nb);
}
