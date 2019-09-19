#include <stdio.h>
#include "libft/libft.h"
#include "fillit.h"
#include "tetra.h"

int main(void)
{
	t_tetra **tetraminos;
	t_point *solution;
	int size;

	CHECK0RET1(tetraminos = read_tetraminos("input.txt"));

	while (*tetraminos)
	{
		tetra_draw(*tetraminos++);
		ft_putchar('\n');
	}
//	solution = solve(tetraminos, &size);
//	draw_solution(size, solution);

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
