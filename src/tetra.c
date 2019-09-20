#include "libft/libft.h"
#include "tetra.h"
#include "plane_iter.h"

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

int	tetra_put(t_tetra *t, char field[FIELD_SIZE][FIELD_SIZE],
		t_point pos, int size)
{
	int i;
	int k;
	t_point p;
	t_point *pts;

	pts = plane_iter_tab(16);
	i = -1;
	k = 0;
	while (++i < 16)
	{
		if (t->data[pts[i].x][pts[i].y] != T_FULL)
			continue;
		k++;
		p.x = pts[i].x + pos.x;
		p.y = pts[i].y + pos.y;
		if (p.x < 0 || p.x > size - 1 || p.y < 0 || p.y > size - 1)
			return (0);
		if (field[p.x][p.y] != T_EMPTY)
			return (0);
		if (k >= 4)
			break;
	}
	t->pos = pos;
	return (1);
}

void tetra_draw(t_tetra *t, char field[FIELD_SIZE][FIELD_SIZE])
{
	t_point *pts;
	int i;
	int k;

	pts = plane_iter_tab(16);
	i = -1;
	k = 0;
	while (++i < 16)
	{
		if (t->data[pts[i].x][pts[i].y] != T_FULL)
			continue;
		field[pts[i].x + t->pos.x][pts[i].y + t->pos.y] = t->letter;
		k++;
		if (k >= 4)
			break ;
	}
}
