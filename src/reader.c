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

void		error_exit()
{
	ft_putendl("error");
	exit(1);
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

int			ft_validate_tetriminos(char **data)
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

int			ft_validate_lines(char **data, int row, int col)
{
	int	num_of_pieces;
	int	total_str_len;

	num_of_pieces = 0;
	total_str_len = 0;
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
		error_exit();
	ft_validate_tetriminos(data);
	return (1);
}

t_tetra		**read_tetraminos2(int fd, int row_num,
					int tetr_num, int read_end)
{
	t_tetra	**ret;
	char	**data;

	CHECK0RET0(ret = (t_tetra **)malloc(sizeof(t_tetra) * 27));
	CHECK0RET0(data = (char **)malloc(sizeof(char *) * 5));
	while (read_end != 0)
	{
		read_end = get_next_line(fd, &data[row_num]);
		row_num++;
		if (row_num == 5 && read_end != 0)
		{
			ft_validate_lines(data, 0, 0);
			ret[tetr_num] = tetra_new(data);
			CHECK0RET0(data = malloc(sizeof(char *) * 5));
			row_num = 0;
			tetr_num++;
		}
		if ((row_num != 5 && row_num != 0) && read_end == 0)
			return (NULL);
		if (row_num == 5 && read_end == 0)
			return (NULL);
	}
	ret[tetr_num] = 0;
	return (ret);
}

t_tetra		*next_tetra(int fd)
{
	int i;
	int status;
	char **data;

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

t_tetra		**read_tetraminos(int fd)
{
	t_tetra	**tetras;
	t_tetra *t;
	int i;

	CHECK0RET0(tetras = (t_tetra **)malloc(sizeof(t_tetra) * 27));
	i = 0;
	while ((t = next_tetra(fd)))
		tetras[i++] = t;
	tetras[i] = 0;
	return (tetras);
}
