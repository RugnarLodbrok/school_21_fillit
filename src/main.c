#include <stdio.h>
#include "libft/libft.h"
#include "fillit.h"

int main(void)
{
	int *tetraminos;
	t_point *solution;
	int size;

	CHECK0RET1(tetraminos = read_tetraminos("input.txt"));
	solution = solve(tetraminos, &size);
	draw_solution(size, solution);
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
