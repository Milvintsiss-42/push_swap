/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:29:50 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/22 10:54:40 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_but_med_and_max_in_b(t_ps *ps)
{
	while (ps->stacks.len_a > 2)
	{
		if (ps->stacks.a->v == ps->median || ps->stacks.a->v == ps->max)
			rotate_a(&ps->stacks, 1, 0);
		else
			push_b(&ps->stacks, 1);
	}
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
