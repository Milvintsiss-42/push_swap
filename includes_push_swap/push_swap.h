/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milvintsiss <milvintsiss@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:01:02 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/17 03:26:14 by milvintsiss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "shared.h"

typedef struct s_ps
{
	t_stacks	stacks;
	int			median;
}	t_ps;

int			find_stack_relative_pos(int *pos, t_num *stack, int stack_len,
				double pos_r);
int			find_stack_median(int *stack_median, t_num *stack, int stack_len);

void		sort_stack_a(t_stacks *stacks);

#endif
