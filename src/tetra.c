#include "libft/libft.h"
#include "tetra.h"

t_tetra *tetra_init(t_tetra *t, char **data)
{
	static char letter = 'A';

	t->data = data;
	t->letter = letter++;
	return (t);
}

t_tetra *tetra_new(char **data)
{
	t_tetra *t;

	CHECK0RET0(t = malloc(sizeof(t_tetra)))
	tetra_init(t, data);
	return (t);
}

void tetra_draw(t_tetra *t)
{
	char **d;

	d = t->data;
	while (*d)
		ft_putendl(*d++);
}
