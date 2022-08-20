/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:00:24 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/20 20:00:26 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	basic_cases(t_stacks *stacks)
{
	if (is_successful(*stacks))
		return (1);
	if (stacks->len_a == 2)
	{
		swap_a(stacks, 1);
		return (1);
	}
	return (0);
}

t_num	*get_last_of_stack(t_num *stack)
{
	while (stack->below_num)
		stack = stack->below_num;
	return (stack);
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

void	sort_stack_a(t_ps *ps)
{
	if (basic_cases(&ps->stacks))
		return ;
	separate_stack_a_med(&ps->stacks);
}
