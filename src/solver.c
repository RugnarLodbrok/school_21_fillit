/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:39:55 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/18 17:39:56 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "tetra.h"
#include "plane_iter.h"

int solve_recur(char field[FIELD_SIZE][FIELD_SIZE],
				t_tetra **tetras, int n, int size)
{
	int i;
	int j;
	t_point *xy;

	i = 0;
	xy = plane_iter_tab(size * size);
	while (i < n)
	{
		ft_swap((void **) tetras, (void **) (tetras + i++));
		j = 0;
		while (j < size * size)
		{
			if (!tetra_put(*tetras, field, xy[j++], size))
				continue;
			tetra_draw_letter(*tetras, field);
			if (n == 1)
				return (1);
			if (solve_recur(field, tetras + 1, n - 1, size))
				return (1);
			tetra_draw(*tetras, field, T_EMPTY);
		}
	}
	return (0);
}

int solve_for_size(t_tetra **tetras, int n, int size)
{
	char field[FIELD_SIZE][FIELD_SIZE];
	int i;
	t_point *ij;

	i = 0;
	while (i < size)
		ft_memset(field[i++], T_EMPTY, size);
//	ij = plane_iter_tab(size * size);

	return (solve_recur(field, tetras, n, size));
}

int solve(t_tetra **tetras)
{
	int n;
	int size;

	n = ft_len((void *) tetras);
	size = ft_sqrt_ceil(n * 4);
	while (!solve_for_size(tetras, n, size))
		size++;
	return (size);
}
