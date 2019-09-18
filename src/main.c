#include <stdio.h>
#include "libft/libft.h"
#include "fillit.h"

int main(void)
{
	int *tetraminos;
	t_point *solution;
	int size;

//	CHECK0RET1(tetraminos = read_tetraminos("input.txt"));
//	solution = solve(tetraminos, &size);
//	draw_solution(size, solution);
	printf("%d\n", ft_sqrt_ceil(25));
	printf("%d\n", ft_sqrt_ceil(26));
	printf("%d\n", ft_sqrt_ceil(27));
	printf("%d\n", ft_sqrt_ceil(28));
	printf("%d\n", ft_sqrt_ceil(29));
	printf("%d\n", ft_sqrt_ceil(30));
	printf("%d\n", ft_sqrt_ceil(31));
	printf("%d\n", ft_sqrt_ceil(32));
	printf("%d\n", ft_sqrt_ceil(33));
	printf("%d\n", ft_sqrt_ceil(34));
	printf("%d\n", ft_sqrt_ceil(35));
	printf("%d\n", ft_sqrt_ceil(36));
	printf("%d\n", ft_sqrt_ceil(37));
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
