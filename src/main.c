#include <stdio.h>
#include "libft/libft.h"

int *read_tetraminos(const char *f_name);
t_point *fill_it(int *tetraminos, int *size_ptr);
void draw_solution(int size, t_point *solution);

int main(void)
{
	int *tetraminos;
	t_point *solution;
	int size;

	CHECK0RET1(tetraminos = read_tetraminos("input.txt"));
	solution = fill_it(tetraminos, &size);
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
