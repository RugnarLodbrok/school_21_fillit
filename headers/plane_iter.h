#ifndef PLANE_ITER_H
# define PLANE_ITER_H

#include "libft/libft.h"

typedef struct s_plane_iter
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	*x;
	unsigned int	*y;
	unsigned int	r;
	int				first;
} t_plane_iter;

t_plane_iter	*plane_iter_init(t_plane_iter *it);
t_plane_iter	*plane_iter_new();
t_point			plane_iter_next(t_plane_iter *it);
t_point			*plane_iter_tab(size_t n);

t_point			*plane_iter_tab_2(size_t w, size_t h);

#endif
