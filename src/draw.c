#include "unistd_fix.h"
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
