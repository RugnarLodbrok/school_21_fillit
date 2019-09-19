#include "libft/libft.h"
#include "tetra.h"

t_tetra *tetra_init(t_tetra *t, char **data)
{
	static char letter = 'A';

	t->data = data;
	t->letter = letter++;
	t->pos.x = 0;
	t->pos.y = 0;
	return (t);
}

t_tetra *tetra_new(char **data)
{
	t_tetra *t;

	CHECK0RET0(t = malloc(sizeof(t_tetra)))
	tetra_init(t, data);
	return (t);
}

int tetra_intersects(t_tetra *t, int i, int j)
{
	int ii;
	int jj;

	ii = i - t->pos.x;
	jj = j - t->pos.y;
	if (ii > 3 || ii < 0 || jj > 3 || jj < 0)
		return (0);
	return (t->data[ii][jj] == T_FULL);
}

void tetra_draw(t_tetra *t)
{
	char **d;

	d = t->data;
	while (*d)
		ft_putendl(*d++);
}
