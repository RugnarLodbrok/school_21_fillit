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

#include <stdio.h>
#include "libft/libft.h"
#include "fillit.h"
#include "tetra.h"
#include "plane_iter.h"

int	ft_open_file(const char *f_name)
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

int	main(int argc, const char **argv)
{
	t_tetra	**tetras;
	int		size;
	int		fd;

	if (argc != 2)
		write(1, "usage: fillit input file\n", 25);
	else
	{
		fd = ft_open_file(argv[1]);
		if ((tetras = read_tetraminos(fd, 0, 0, 1)) == NULL)
		{
			(write(1, "error\n", 6));
			return (1);
		}
		size = solve(tetras);
		draw_solution(size, tetras);
	}
	return (0);
}
