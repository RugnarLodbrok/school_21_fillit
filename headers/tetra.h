#ifndef TETRA_H
# define TETRA_H

# define T_EMPTY '.'
# define T_FULL '#'

typedef struct s_tetra
{
	char	letter;
	char	**data;
	t_point	pos;
} t_tetra;

t_tetra *tetra_init(t_tetra *t, char **data);
t_tetra *tetra_new(char **data);
int tetra_intersects(t_tetra *t, int i, int j);
void tetra_draw(t_tetra *t);

#endif
