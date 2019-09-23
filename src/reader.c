/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrowzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:45:31 by edrowzee          #+#    #+#             */
/*   Updated: 2019/09/20 16:48:00 by edrowzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "headers/tetra.h"
#include "../headers/fillit.h"

void		ft_data_free(char **data)
{
	int i;

	i = 0;
	while (i < 5)
	{
		free(data[i]);
		i++;
	}
	free(data);
}

int			ft_connects_counter(char **data, int row, int col)
{
	int result;

	result = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (data[row][col] == '#')
			{
				if (row > 0 && data[row - 1][col] == '#')
					result++;
				if (row < 3 && data[row + 1][col] == '#')
					result++;
				if (col > 0 && data[row][col - 1] == '#')
					result++;
				if (col < 3 && data[row][col + 1] == '#')
					result++;
			}
			col++;
		}
		row++;
	}
	return (result);
}

int			ft_val_tet(char **data)
{
	int		connects;

	connects = ft_connects_counter(data, 0, 0);
	if (connects == 6 || connects == 8)
		return (1);
	else
	{
		ft_data_free(data);
		return (-1);
	}
}

int			ft_val_ln(char **data, int row, int col)
{
	int	num_of_pieces;
	int	total_str_len;

	num_of_pieces = 0;
	total_str_len = 0;
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (data[row][col] != '\0')
		{
			if (data[row][col] == '#')
				num_of_pieces++;
			total_str_len++;
			col++;
		}
		row++;
	}
	if (num_of_pieces != 4 || total_str_len != 16)
	{
		ft_data_free(data);
		return (-1);
	}
	return (1);
}

t_tetra		**read_tetraminos(const char *f_name, int row_num,
					int tetr_num, int read_end)
{
	t_tetra	**ret;
	char		**data;
	int			fd;

	ret = malloc(sizeof(t_tetra) * 27);
	data = malloc(sizeof(char *) * 5);
	fd = open(f_name, O_RDONLY); //move to another func. Add CHECK0RET0. Add check open file
	while (read_end != 0)
	{
		read_end = get_next_line(fd, &data[row_num]);
		row_num++;
		if (row_num == 5)
		{
			if (((ft_val_ln(data, 0, 0)) == -1) || ((ft_val_tet(data)) == -1))
				return (NULL);
			else
				ret[tetr_num] = tetra_new(data);
			data = malloc(sizeof(char *) * 5);
			row_num = 0;
			tetr_num++;
		}
		if ((row_num != 5 && row_num != 0) && read_end == 0)
			return (NULL);
	}
	ret[tetr_num] = 0;
	return (ret);
}
