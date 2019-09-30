/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_prepare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:20:17 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/25 16:20:18 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "tetra.h"

static void		loop(void **tab, size_t n)
{
	size_t i;

	i = 0;
	while (i++ < n - 1)
		ft_swap(tab + i - 1, tab + i);
}

static void		loop_str(char *str, size_t n)
{
	size_t i;

	i = 0;
	while (i++ < n - 1)
		ft_swap_char(str + i - 1, str + i);
}

void			tetra_move_to_corner(char **data)
{
	while (data[0][0] == T_EMPTY && data[0][1] == T_EMPTY
			&& data[0][2] == T_EMPTY && data[0][3] == T_EMPTY)
		loop((void **)data, 4);
	while (data[0][0] == T_EMPTY && data[1][0] == T_EMPTY
			&& data[2][0] == T_EMPTY && data[3][0] == T_EMPTY)
	{
		loop_str(data[0], 4);
		loop_str(data[1], 4);
		loop_str(data[2], 4);
		loop_str(data[3], 4);
	}
}
