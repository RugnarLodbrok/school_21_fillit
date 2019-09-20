#include <stdlib.h>
#include "libft/libft.h"
#include "headers/tetra.h"
#include "headers/fillit.h"

void	ft_data_free(char **data)
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

int ft_connects_counter(char **data, int row, int col)
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

int		ft_validate_tetr(char **data)
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

int		ft_validate_lines(char **data)
{
	int	num_of_pieces;
	int	total_str_len;
	int	row;
	int col;

	num_of_pieces = 0;
	total_str_len = 0;
	row = 0;
	while (row < 4)
	{
		col = 0;
		while(data[row][col] != '\0')
		{
			if (data[row][col] == '#')
				num_of_pieces++;
			total_str_len++;
			col++;
		}
		row++;
	}
	if (data[4][0] != '\n' || num_of_pieces != 4 || total_str_len != 16)
	{
		ft_data_free(data);
		return (-1);
	}
	return (1);
}


t_tetra **read_tetraminos(const char *f_name)
{
	t_tetra	*ret[27];
	char 		**data;
	int			row_num;
	int			tetr_num;
	int			fd;

	tetr_num = 0;
	fd = open(f_name, O_RDONLY);
	while (fd != 0)
	{
		row_num = 0;
		data = malloc(sizeof(char *) * 5);
		while (row_num < 5)
		{
			get_next_line(fd, data + row_num);
			row_num++;
		}
		if (((ft_validate_lines(data)) == -1) || ((ft_validate_tetr(data)) == -1))
			return (NULL);
		else
			ret[tetr_num] = tetra_new(data);
	}
	return (ret);
}
