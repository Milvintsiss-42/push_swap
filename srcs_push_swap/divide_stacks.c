/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:29:50 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/22 01:12:15 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_but_two_in_b(t_stacks *stacks)
{
	while (stacks->len_a > 2)
		push_b(stacks, 1);
}

void	separate_stack_a_med(t_stacks *stacks)
{
	int	pos;
	int	mid_len;

	if (!find_stack_median(&pos, stacks->a, stacks->len_a))
		exception_exit(*stacks);
	mid_len = stacks->len_a * 0.5;
	if (stacks->len_a % 2)
		mid_len++;
	while (stacks->len_a > mid_len)
	{
		if (stacks->a->v < pos)
			push_b(stacks, 1);
		else
			rotate_a(stacks, 1, 0);
	}
}

void	separate_stack_b_med(t_stacks *stacks)
{
	int	pos;
	int	mid_len;

	if (!find_stack_median(&pos, stacks->b, stacks->len_b))
		exception_exit(*stacks);
	mid_len = stacks->len_b * 0.5;
	if (stacks->len_a % 2)
		mid_len++;
	while (stacks->len_b > mid_len)
	{
		if (stacks->b->v < pos)
			push_a(stacks, 1);
		else
			rotate_b(stacks, 1, 0);
	}
}
