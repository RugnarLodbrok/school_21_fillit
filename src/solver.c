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
#include "plane_iter.h"
#include <stdio.h>

int solve_recur(char field[FIELD_SIZE][FIELD_SIZE],
				t_tetra **tetras, int size, t_point *xy, int cursor)
{
	int i;
	int j;
	int n;

	i = 0;
	n = ft_len((void **)tetras);
	while (i < n)
	{
		ft_swap((void **)tetras, (void **)(tetras + i++));
		j = cursor;
		while (j < size * size)
		{
			if (!tetra_put(*tetras, field, xy[j++], size))
				continue;
			tetra_draw_letter(*tetras, field);
			if (n == 1)
				return (1);
			if (solve_recur(field, tetras + 1, size, xy, j))
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
	t_point *xy;

//	printf("s: %d\n", size);
	i = 0;
	while (i < size)
		ft_memset(field[i++], T_EMPTY, size);
	xy = plane_iter_tab_2(size, size);

	return (solve_recur(field, tetras, size, xy, 0));
}

int solve(t_tetra **tetras)
{
	int n;
	int size;
	t_tetra *tetras_backp[28];

	n = ft_len((void *)tetras);
	tetras_backp[n] = 0;
	ft_memcpy(tetras_backp, tetras, n * sizeof(t_tetra *));
//	printf("n = %d\n", n);
	size = ft_sqrt_ceil(n * 4);
//	printf("s = %d\n", size);
//	size = 11;
	while (!solve_for_size(tetras, n, size))
	{
		ft_memcpy(tetras, tetras_backp, n * sizeof(t_tetra *));
		size++;
	}
	return (size);
}
