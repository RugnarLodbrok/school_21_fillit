#include <stdio.h>
#include "libft/libft.h"
#include "fillit.h"
#include "tetra.h"
#include "plane_iter.h"

int main(int argc, const char **argv)
{
	t_tetra **tetras;
	int size;

	CHECK0RET1(tetras = read_tetraminos(argv[1], 0, 0));
	size = solve(tetras);
	draw_solution(size, tetras);
	return (0);
}

/*
 * Tetraminos example
##.. .##. ..## .... .... .... ##.. .### .... .... ....
#... .#.. ..#. ##.. .##. ..## #... ...# ...# .... .##.
#... .#.. ..#. #... .#.. ..#. #... .... ...# #... .##.
.... .... .... #... .#.. ..#. .... .... ..## ###. ....
 */
