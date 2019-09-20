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

int solve_for_size(t_tetra **tetras, int n, int size)
{
	char field[FIELD_SIZE][FIELD_SIZE];
	int i;
	t_point *ij;

	i = 0;
	while (i < size)
		ft_memset(field[i++], T_EMPTY, size);
	ij = plane_iter_tab(size * size);
	while (*tetras)
	{
		i = 0;
		while (!tetra_put(*tetras, field, ij[i], size))
			if (i++ > size * size - 1)
				return (0);
		tetra_draw(*tetras, field);
		tetras++;
	}
	return (1);
}

int solve_for_size_mock(t_tetra **tetras, int n, int size)
{
	int i;

	if (size < 4 * n)
		return (0);
	i = 0;
	while (i < n)
	{
		tetras[i]->pos.x = 4 * i;
		tetras[i]->pos.y = 4 * i;
		i++;
	}
	return (1);
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
