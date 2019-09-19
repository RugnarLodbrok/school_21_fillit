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

int solve_for_size(t_tetra **tetras, int n, int size)
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

	n = 0;
	while (tetras[n])
		n++;
	size = ft_sqrt_ceil(n * 4);
	while (!solve_for_size(tetras, n, size))
		size++;
	return (size);
}
