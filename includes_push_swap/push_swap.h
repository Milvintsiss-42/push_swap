/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:01:02 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/20 20:19:05 by ple-stra         ###   ########.fr       */
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

int			*create_stack_cpy_arr(t_num *stack, int stack_len);
void		order_stack_arr(int *stack_arr, int stack_len);
int			sets_values_to_suite(t_stacks stacks);

int			find_stack_relative_pos(int *pos, t_num *stack, int stack_len,
				double pos_r);
int			find_stack_median(int *stack_median, t_num *stack, int stack_len);

void		sort_stack_a(t_ps *ps);

#endif
