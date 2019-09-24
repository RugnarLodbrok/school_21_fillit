/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:39:55 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/23 15:13:59 by edrowzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "tetra.h"

int solve_recur(char field[FIELD_SIZE][FIELD_SIZE],
				t_tetra **tetras, int size)
{
	int k;
	t_point p;

	p.x = -1;
	k = 0;
	while (++p.x < size - (*tetras)->size.x + 1)
	{
		p.y = -1;
		while (++p.y < size - (*tetras)->size.y + 1)
		{
			if (!tetra_put(*tetras, field, p, size))
				continue;
			tetra_draw_letter(*tetras, field);
			if (!*(tetras + 1))
				return (1);
			if (solve_recur(field, tetras + 1, size))
				return (1);
			tetra_draw(*tetras, field, T_EMPTY);
			if (k++ > 2)	// don't ask why
				return (0);
		}
	}
	return (0);
}

int solve_for_size(t_tetra **tetras, int n, int size)
{
	char field[FIELD_SIZE][FIELD_SIZE];
	int i;
	t_point *xy;

	i = 0;
	while (i < size)
		ft_memset(field[i++], T_EMPTY, size);

	return (solve_recur(field, tetras, size));
}

int solve(t_tetra **tetras)
{
	int n;
	int size;
	t_tetra *tetras_backp[28];

	n = ft_len((void *) tetras);
	tetras_backp[n] = 0;
	ft_memcpy(tetras_backp, tetras, n * sizeof(t_tetra *));
	size = ft_sqrt_ceil(n * 4);
	while (!solve_for_size(tetras, n, size))
	{
		ft_memcpy(tetras, tetras_backp, n * sizeof(t_tetra *));
		size++;
	}
	return (size);
}
