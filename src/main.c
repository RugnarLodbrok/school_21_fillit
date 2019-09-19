#include <stdio.h>
#include "libft/libft.h"
#include "fillit.h"
#include "tetra.h"

int main(void)
{
	int i;
	t_tetra **tetras;
	int size;

	CHECK0RET1(tetras = read_tetraminos("input.txt"));

	i = 0;
	printf("solve...\n");
	solve(tetras, &size);
	while (tetras[i])
	{
		tetra_draw(tetras[i]);
		printf("solution: %d %d\n", tetras[i]->pos.x, tetras[i]->pos.y);
		ft_putchar('\n');
		i++;
	}
	draw_solution(size, tetras);

	return (0);
}

//##.. .##. ..## .... .... .... ##.. .### .... .... ....
//#... .#.. ..#. ##.. .##. ..## #... ...# ...# .... .##.
//#... .#.. ..#. #... .#.. ..#. #... .... ...# #... .##.
//.... .... .... #... .#.. ..#. .... .... ..## ###. ....

const char a[2][4][4] =
		{
				{
						"##..",
						"#...",
						"#...",
						"...."
				},
				{
						"....",
						".##.",
						".##.",
						"...."
				}
		};
