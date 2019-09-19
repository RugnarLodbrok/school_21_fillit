#include "unistd.h"
#include "libft/libft.h"
#include "tetra.h"

char get_letter(int i, int j, t_tetra **tetras)
{
	t_tetra *t;
	while (*tetras)
	{
		t = *tetras;
		if (tetra_intersects(t, i, j))
			return (t->letter);
		tetras++;
	}
	return (T_EMPTY);
}

void draw_solution(const int size, t_tetra **tetras)
{
	int i;
	int j;
	char res[256][256];

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			res[i][j] = get_letter(i, j, tetras);
			j++;
		}
		res[i][size] = 0;
		i++;
	}
	i = 0;
	while (i < size)
		ft_putendl(res[i++]);
}
