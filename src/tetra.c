/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrowzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:09:25 by edrowzee          #+#    #+#             */
/*   Updated: 2019/09/25 16:09:58 by edrowzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "tetra.h"
#include "plane_iter.h"

void			tetra_init_size(t_tetra *t)
{
	int			i;

	i = 0;
	while (i < 16)
	{
		if (t->data[t->data_idx_iter[i].x][t->data_idx_iter[i].y] == T_FULL)
		{
			t->size.x = MAX(t->size.x, t->data_idx_iter[i].x + 1);
			t->size.y = MAX(t->size.y, t->data_idx_iter[i].y + 1);
		}
		i++;
	}
}

t_tetra			*tetra_init(t_tetra *t, char **data)
{
	static char	letter = 'A';

	tetra_move_to_corner(data);
	t->data = data;
	t->letter = letter++;
	t->pos.x = 0;
	t->pos.y = 0;
	t->size.x = 0;
	t->size.y = 0;
	t->data_idx_iter = plane_iter_tab(16);
	tetra_init_size(t);
	return (t);
}

t_tetra			*tetra_new(char **data)
{
	t_tetra *t;

	CHECK0RET0(t = malloc(sizeof(t_tetra)));
	tetra_init(t, data);
	return (t);
}

int				tetra_put(t_tetra *t, char field[FIELD_SIZE][FIELD_SIZE],
				t_point pos)
{
	int		i;
	int		k;
	t_point	p;

	i = -1;
	k = 0;
	while (++i < 16)
	{
		if (t->data[t->data_idx_iter[i].x][t->data_idx_iter[i].y] != T_FULL)
			continue;
		k++;
		p.x = t->data_idx_iter[i].x + pos.x;
		p.y = t->data_idx_iter[i].y + pos.y;
		if (field[p.x][p.y] != T_EMPTY)
			return (0);
		if (k >= 4)
			break ;
	}
	t->pos = pos;
	return (1);
}

void			tetra_draw(t_tetra *t,
				char field[FIELD_SIZE][FIELD_SIZE], char c)
{
	int i;
	int k;
	int x;
	int y;

	i = -1;
	k = 0;
	while (++i < 16)
	{
		x = t->data_idx_iter[i].x;
		y = t->data_idx_iter[i].y;
		if (t->data[x][y] != T_FULL)
			continue;
		field[x + t->pos.x][y + t->pos.y] = c;
		k++;
		if (k >= 4)
			break ;
	}
}
