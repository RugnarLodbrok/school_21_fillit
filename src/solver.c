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

t_point *solve(int *tetraminos, int *size_ptr)
{
	int n;
	t_point *ret;

	n = 0;
	while (tetraminos[n])
		n++;
	(*size_ptr) = ft_sqrt_ceil(n * 4);
	while (!(ret = solve_for_size(tetraminos, n, *size_ptr)))
		(*size_ptr)++;
	return ret;
}

solve_for_size(int *tetraminos, int n, int size)
{
	CHECK0RET0(ret = malloc(sizeof(t_point) * (n + 1)))
}
