#include <stdio.h>
#include "libft/libft.h"
#include "fillit.h"
#include "tetra.h"
#include "plane_iter.h"

int main(int argc, const char **argv)
{
	t_tetra **tetras;
	int size;

	CHECK0RET1(tetras = read_tetraminos(argv[1]));
	size = solve(tetras);
	printf("%s\n", tetras[0]->data[0]);
	printf("%s\n", tetras[0]->data[1]);
	printf("%s\n", tetras[0]->data[2]);
	printf("%s\n", tetras[0]->data[3]);
	printf("%s\n", "End tetr");
	printf("%s\n", tetras[1]->data[0]);
	printf("%s\n", tetras[1]->data[1]);
	printf("%s\n", tetras[1]->data[2]);
	printf("%s\n", tetras[1]->data[3]);
	printf("%s\n", "End tetr");
	printf("%s\n", tetras[2]->data[0]);
	printf("%s\n", tetras[2]->data[1]);
	printf("%s\n", tetras[2]->data[2]);
	printf("%s\n", tetras[2]->data[3]);
	printf("%s\n", "Solution is: ");
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
