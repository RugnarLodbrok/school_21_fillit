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

int		ft_connects_counter(char **data, int row, int col)
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
	int	col;

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
//	printf("%s\n", data[0]);
//	printf("%s\n", data[1]);
//	printf("%s\n", data[2]);
//	printf("%s\n", data[3]);
//	printf("%s\n", "end");
	printf("%d\n", num_of_pieces);
	printf("%d\n", total_str_len);
//	printf("data[4][0] is: %c\n", data[4][0]);
	if (num_of_pieces != 4 || total_str_len != 16)
	{
		ft_data_free(data);
		return (-1);
	}
	return (1);
}


t_tetra **read_tetraminos(const char *f_name)
{
	t_tetra		**ret;
	char 		**data;
	int			row_num;
	int			tetr_num;
	int			fd;

	tetr_num = 0;
	fd = open(f_name, O_RDONLY);
	ret = malloc(sizeof(t_tetra) * 27);
	while (tetr_num < 3)
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
		{
			ret[tetr_num] = tetra_new(data);
		}
		tetr_num++;
	}
	return (ret);
}

t_tetra **read_tetraminos_mock(const char *f_name)
{
	t_tetra **ret;
	char **data;

	ret = malloc(sizeof(t_tetra*) * 4);
	data = malloc(sizeof(char *) * 5);
	data[0] = ft_strdup("....");
	data[1] = ft_strdup("###.");
	data[2] = ft_strdup("#...");
	data[3] = ft_strdup("....");
	data[4] = 0;
	ret[0] = tetra_new(data);

	data = malloc(sizeof(char *) * 5);
	data[0] = ft_strdup(".##.");
	data[1] = ft_strdup(".##.");
	data[2] = ft_strdup("....");
	data[3] = ft_strdup("....");
	data[4] = 0;
	ret[1] = tetra_new(data);

	data = malloc(sizeof(char *) * 5);
	data[0] = ft_strdup("....");
	data[1] = ft_strdup("..#.");
	data[2] = ft_strdup("..##");
	data[3] = ft_strdup("...#");
	data[4] = 0;
	ret[2] = tetra_new(data);

	ret[3] = 0;

	return ret;
}
