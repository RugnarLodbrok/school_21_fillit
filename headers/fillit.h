/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:39:45 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/18 17:39:47 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

int *read_tetraminos(const char *f_name);
t_point *solve(int *tetraminos, int *size_ptr);
void draw_solution(int size, t_point *solution);

#endif
