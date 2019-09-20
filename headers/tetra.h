#ifndef TETRA_H
# define TETRA_H

# define T_EMPTY '.'
# define T_FULL '#'
# define FIELD_SIZE 256

typedef struct s_tetra
{
	char	letter;
	char	**data;
	t_point	pos;
	t_point	*data_idx_iter;
} 						t_tetra;

t_tetra	*tetra_init(t_tetra *t, char **data);
t_tetra	*tetra_new(char **data);
int		tetra_put(t_tetra *t, char field[FIELD_SIZE][FIELD_SIZE],
		t_point pos, int size);
void	tetra_draw(t_tetra *t, char field[FIELD_SIZE][FIELD_SIZE], char c);
void	tetra_draw_letter(t_tetra *t, char field[FIELD_SIZE][FIELD_SIZE]);

#endif
