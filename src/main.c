/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrowzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:10:44 by edrowzee          #+#    #+#             */
/*   Updated: 2019/09/23 15:54:58 by edrowzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft/libft.h"
#include "fillit.h"
#include "tetra.h"

int		ft_open_file(const char *f_name)
{
	int fd;

	fd = open(f_name, O_RDONLY);
	if (fd < 0)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	return (fd);
}

void	clean_up(t_tetra **tetras)
{
	int i;

	i = 0;
	while (tetras[i])
	{
		free(tetras[i]->data[0]);
		free(tetras[i]->data[1]);
		free(tetras[i]->data[2]);
		free(tetras[i]->data[3]);
		free(tetras[i]->data);
		free(tetras[i]);
		i++;
	}
	free(tetras);
}

int		main(int argc, const char **argv)
{
	t_tetra	**tetras;
	int		size;
	int		fd;

	if (argc != 2)
		write(1, "usage: fillit input file\n", 25);
	else
	{
		fd = ft_open_file(argv[1]);
		if ((tetras = read_tetraminos(fd)) == NULL)
		{
			(write(1, "error\n", 6));
			return (1);
		}
		size = solve(tetras);
		draw_solution(size, tetras);
		clean_up(tetras);
	}
	return (0);
}
