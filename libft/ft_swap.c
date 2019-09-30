/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:49:46 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/25 15:49:48 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(void **a, void **b)
{
	void *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_swap_char(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
