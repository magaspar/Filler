/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_seeker.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: magaspar <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 15:46:06 by magaspar     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 14:57:48 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char		*check_flags(char **str, t_printf *stock)
{
	if (**str == '#' || **str == ' ' || **str == '+' || **str == '-' ||
			**str == '0')
	{
		if (**str == '#')
			stock->f_diez = 1;
		else if (**str == '0')
			stock->f_zero = 1;
		else if (**str == '-')
			stock->f_minus = 1;
		else if (**str == '+')
			stock->f_plus = 1;
		else if (**str == ' ')
			stock->f_space = 1;
		(*str)++;
		return (check_flags(str, stock));
	}
	else
		return (*str);
}

char		*check_width(char **str, t_printf *stock)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	if (!str || !stock)
		return (NULL);
	if ((**str < 48) || (**str > 57))
		return (*str);
	tmp2 = *str;
	while ((*tmp2 >= 48) && (*tmp2 <= 57))
		tmp2++;
	tmp = (char*)malloc(sizeof(char) * ((tmp2 - *str) + 1));
	i = -1;
	while ((**str >= 48) && (**str <= 57))
	{
		tmp[++i] = **str;
		(*str)++;
	}
	tmp[++i] = '\0';
	stock->width = ft_atoi(tmp);
	free(tmp);
	return (*str);
}

char		*check_pres(char **str, t_printf *stock)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	if (**str != '.')
		return (*str);
	(*str)++;
	stock->pres = 0;
	if ((**str < 48) || (**str > 57))
		return (*str);
	tmp2 = *str;
	while ((*tmp2 >= 48) && (*tmp2 <= 57))
		tmp2++;
	tmp = (char*)malloc(sizeof(char) * ((tmp2 - *str) + 1));
	i = -1;
	while ((**str >= 48) && (**str <= 57))
	{
		tmp[++i] = **str;
		(*str)++;
	}
	tmp[++i] = '\0';
	stock->pres = ft_atoi(tmp);
	free(tmp);
	return (*str);
}

char		*check_len(char **s, t_printf *stock)
{
	char		c;

	c = **s;
	if (stock->length && (stock->length[0] > c))
		(*s)++;
	if (stock->length && (stock->length[0] > c))
		c = 0;
	else if (stock->length && (stock->length[0] < c) && (c == 'h' || c == 'l' ||
				c == 'j' || c == 'z'))
		free(stock->length);
	if (c && (c == 'h' || c == 'l' || c == 'j' || c == 'z'))
	{
		if ((c == 'h' && *(*s + 1) == 'h') || (c == 'l' && *(*s + 1) == 'l'))
			stock->length = ft_strnew(3);
		else
			stock->length = ft_strnew(2);
		stock->length[0] = c;
		if ((c == 'h' && *(*s + 1) == 'h') || (c == 'l' && *(*s + 1) == 'l'))
			stock->length[1] = (c == 'h') ? 'h' : 'l';
		if (stock->length[1] != '\0')
			(*s)++;
		(*s)++;
	}
	return (*s);
}

int			check_conv(char **str, char *cha, t_printf *stock)
{
	char	c;

	c = **str;
	if ((c == 's') || (c == 'S') || (c == 'p') || (c == 'd') || (c == 'D') ||
			(c == 'i') || (c == 'o') || (c == 'O') ||
			(c == 'u') || (c == 'U') || (c == 'x') ||
			(c == 'X') || (c == 'c') || (c == 'C') ||
			(c == '%') || c)
	{
		stock->conversion = **str;
		*cha = **str;
		if ((c != '#') && (c != '0') && (c != '-') && (c != '+') &&
				(c != ' ') && !((c >= '0') && (c <= '9')) && (c != '.') &&
				(c != 'h') && (c != 'l') && (c != 'j') && (c != 'z'))
			(*str)++;
		return (1);
	}
	return (0);
}
