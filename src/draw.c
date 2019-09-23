/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrowzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:10:02 by edrowzee          #+#    #+#             */
/*   Updated: 2019/09/23 15:10:30 by edrowzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/unistd_fix.h"
#include "libft/libft.h"
#include "tetra.h"

void draw_solution(const int size, t_tetra **tetras)
{
	int i;
	int j;
	char res[FIELD_SIZE][FIELD_SIZE];

	i = 0;
	while (i < size)
	{
		ft_memset(res[i], T_EMPTY, size);
		res[i++][size] = 0;
	}
	while (*tetras)
		tetra_draw_letter(*tetras++, res);
	i = 0;
	while (i < size)
		ft_putendl(res[i++]);
}
