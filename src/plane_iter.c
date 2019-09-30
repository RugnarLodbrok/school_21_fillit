/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrowzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:12:08 by edrowzee          #+#    #+#             */
/*   Updated: 2019/09/25 16:04:45 by edrowzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "plane_iter.h"

t_plane_iter	*plane_iter_init(t_plane_iter *it)
{
	it->r = 0;
	it->i = 0;
	it->j = 0;
	it->x = &(it->i);
	it->y = &(it->j);
	it->first = 1;
	return (it);
}

t_plane_iter	*plane_iter_new(void)
{
	t_plane_iter *it;

	CHECK0RET0(it = malloc(sizeof(t_plane_iter)));
	plane_iter_init(it);
	return (it);
}

t_point			plane_iter_next(t_plane_iter *self)
{
	t_point ret;

	if (self->first)
	{
		self->first = 0;
		ret.x = 0;
		ret.y = 0;
		return (ret);
	}
	if (*(self->x) < self->r)
		(*(self->x))++;
	else if (*(self->y))
		(*(self->y))--;
	else
	{
		self->r++;
		(*(self->x))++;
		ft_swap((void **)&(self->x), (void **)&(self->y));
	}
	ret.x = (int)self->i;
	ret.y = (int)self->j;
	return (ret);
}

t_point			*plane_iter_tab(size_t n)
{
	size_t			i;
	t_point			*ret;
	t_plane_iter	it;

	CHECK0RET0(ret = malloc(sizeof(t_point) * n));
	i = 0;
	plane_iter_init(&it);
	while (i < n)
		ret[i++] = plane_iter_next(&it);
	return (ret);
}

t_point			*plane_iter_tab_2(size_t w, size_t h)
{
	size_t	i;
	size_t	j;
	size_t	k;
	t_point	*ret;

	CHECK0RET0(ret = malloc(sizeof(t_point) * (w * h)));
	k = 0;
	i = 0;
	while (i < w)
	{
		j = 0;
		while (j < h)
		{
			ret[k].x = i;
			ret[k++].y = j++;
		}
		i++;
	}
	return (ret);
}
