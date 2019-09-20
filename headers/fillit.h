/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:39:45 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/20 14:52:45 by edrowzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "tetra.h"
#include <stdio.h>

t_tetra **read_tetraminos(const char *f_name);
int solve(t_tetra **tetras);
void draw_solution(int size, t_tetra **tetras);

#endif
