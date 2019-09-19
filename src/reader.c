#include <stdlib.h>
#include "libft/libft.h"
#include "headers/tetra.h"
#include "headers/fillit.h"

t_tetra **read_tetraminos(const char *f_name)
{
	t_tetra **ret;
	char **data;

	ret = malloc(sizeof(t_tetra*) * 4);
	data = malloc(sizeof(char *) * 5);
	data[0] = ft_strdup("###.");
	data[1] = ft_strdup("#...");
	data[2] = ft_strdup("....");
	data[3] = ft_strdup("....");
	data[4] = 0;
	ret[0] = tetra_new(data);

	data = malloc(sizeof(char *) * 5);
	data[0] = ft_strdup("##..");
	data[1] = ft_strdup("##..");
	data[2] = ft_strdup("....");
	data[3] = ft_strdup("....");
	data[4] = 0;
	ret[1] = tetra_new(data);

	data = malloc(sizeof(char *) * 5);
	data[0] = ft_strdup("#...");
	data[1] = ft_strdup("##..");
	data[2] = ft_strdup(".#..");
	data[3] = ft_strdup("....");
	data[4] = 0;
	ret[2] = tetra_new(data);

	ret[3] = 0;

	return ret;
}
