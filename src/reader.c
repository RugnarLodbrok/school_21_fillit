/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrowzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:45:31 by edrowzee          #+#    #+#             */
/*   Updated: 2019/09/23 16:14:40 by edrowzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "tetra.h"
#include "fillit.h"

static int		ft_connects_counter(char **data, int row, int col)
{
	int result;

	result = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (data[row][col] == T_FULL)
			{
				if (row > 0 && data[row - 1][col] == T_FULL)
					result++;
				if (row < 3 && data[row + 1][col] == T_FULL)
					result++;
				if (col > 0 && data[row][col - 1] == T_FULL)
					result++;
				if (col < 3 && data[row][col + 1] == T_FULL)
					result++;
			}
			col++;
		}
		row++;
	}
	return (result);
}

static int		ft_validate_tetriminos(char **data)
{
	int		connects;

	connects = ft_connects_counter(data, 0, 0);
	if (connects == 6 || connects == 8)
		return (1);
	else
	{
		write(1, "error\n", 6);
		exit(1);
	}
}

static int		ft_validate_lines(char **data, int i, int j)
{
	int	num_of_pieces;

	num_of_pieces = 0;
	while (i < 4)
	{
		j = 0;
		while (data[i][j] != '\0')
		{
			if (j > 3)
				error_exit();
			if (data[i][j] == T_FULL)
				num_of_pieces++;
			else if (data[i][j] != T_EMPTY)
				error_exit();
			j++;
		}
		if (j < 4)
			error_exit();
		i++;
	}
	if (num_of_pieces != 4)
		error_exit();
	ft_validate_tetriminos(data);
	return (1);
}

static t_tetra	*next_tetra(int fd)
{
	int		i;
	int		status;
	char	**data;

	i = 0;
	data = malloc(sizeof(char*) * 5);
	while (i < 5)
	{
		status = get_next_line(fd, data + i);
		if (status < 0)
			error_exit();
		if (!status && i == 0)
			return (0);
		if (!status)
			error_exit();
		i++;
	}
	if (ft_strcmp("", data[4]))
		error_exit();
	data[4] = 0;
	ft_validate_lines(data, 0, 0);
	return (tetra_new(data));
}

t_tetra			**read_tetraminos(int fd)
{
	t_tetra	**tetras;
	t_tetra	*t;
	int		i;

	CHECK0RET0(tetras = (t_tetra **)malloc(sizeof(t_tetra) * 27));
	i = 0;
	while ((t = next_tetra(fd)))
		tetras[i++] = t;
	tetras[i] = 0;
	return (tetras);
}
