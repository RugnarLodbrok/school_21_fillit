#include "libft/libft.h"
#include "tetra.h"
#include "plane_iter.h"

#include <stdio.h>

static void loop(void **tab, size_t n)
{
	size_t i;

	i = 0;
	while (i++ < n - 1)
		ft_swap(tab + i - 1, tab + i);
}

static void loop_str(char *str, size_t n)
{
	size_t i;

	i = 0;
	while (i++ < n - 1)
		ft_swap_char(str + i - 1, str + i);
}

t_tetra *tetra_init(t_tetra *t, char **data)
{
	static char letter = 'A';
	int i;

	while (data[0][0] == T_EMPTY && data[0][1] == T_EMPTY
		   && data[0][2] == T_EMPTY && data[0][3] == T_EMPTY)
		loop((void **)data, 4);
	while (data[0][0] == T_EMPTY && data[1][0] == T_EMPTY
		   && data[2][0] == T_EMPTY && data[3][0] == T_EMPTY)
	{
		loop_str(data[0], 4);
		loop_str(data[1], 4);
		loop_str(data[2], 4);
		loop_str(data[3], 4);
	}
	t->data = data;
	t->letter = letter++;
	t->pos.x = 0;
	t->pos.y = 0;
	t->size.x = 0;
	t->size.y = 0;
	t->data_idx_iter = plane_iter_tab(16);
	i = 0;
	while (i < 16)
	{
		if (t->data[t->data_idx_iter[i].x][t->data_idx_iter[i].y] == T_FULL)
		{
			t->size.x = MAX(t->size.x, t->data_idx_iter[i].x + 1);
			t->size.y = MAX(t->size.y, t->data_idx_iter[i].y + 1);
		}
		i++;
	}
	return (t);
}

t_tetra *tetra_new(char **data)
{
	t_tetra *t;

	CHECK0RET0(t = malloc(sizeof(t_tetra)))
	tetra_init(t, data);
	return (t);
}

int tetra_put(t_tetra *t, char field[FIELD_SIZE][FIELD_SIZE],
			  t_point pos, int size)
{
	int i;
	int k;
	t_point p;

	i = -1;
	k = 0;
	if (pos.x > size - t->size.x || pos.y > size - t->size.y)
		return (0);
	while (++i < 16)
	{
		if (t->data[t->data_idx_iter[i].x][t->data_idx_iter[i].y] != T_FULL)
			continue;
		k++;
		p.x = t->data_idx_iter[i].x + pos.x;
		p.y = t->data_idx_iter[i].y + pos.y;
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

void tetra_draw(t_tetra *t, char field[FIELD_SIZE][FIELD_SIZE], char c)
{
	int i;
	int k;
	int x;
	int y;

	i = -1;
	k = 0;
	while (++i < 16)
	{
		x = t->data_idx_iter[i].x;
		y = t->data_idx_iter[i].y;
		if (t->data[x][y] != T_FULL)
			continue;
		field[x + t->pos.x][y + t->pos.y] = c;
		k++;
		if (k >= 4)
			break;
	}
}

void tetra_draw_letter(t_tetra *t, char field[FIELD_SIZE][FIELD_SIZE])
{
	tetra_draw(t, field, t->letter);
}

void tetra_print(t_tetra *t)
{
	char **d;

	d = t->data;
	while (d - t->data < 4)
		printf("%s\n", *d++);
	printf("\n");
}
