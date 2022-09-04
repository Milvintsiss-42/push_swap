/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:00:24 by ple-stra          #+#    #+#             */
/*   Updated: 2022/09/04 20:24:55 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	four_or_five_stack(t_stacks *stacks)
{
	int	len_stack;

	len_stack = stacks->len_a;
	while (stacks->len_a > 3 - (len_stack == 4))
	{
		if (stacks->a->v <= 1)
			push_b(stacks, 1);
		else
			rotate_a(stacks, 1, 0);
	}
	if (stacks->b->v == 0)
		swap_b(stacks, 1);
	if (len_stack == 5)
	{
		if (stacks->a->v == 4)
			rotate_a(stacks, 1, 0);
		if (stacks->a->below_num->v == 4)
			rotate_a(stacks, 1, 1);
		if (stacks->a->v == 3)
			swap_a(stacks, 1);
	}
	else if (stacks->a->v == 3)
		swap_a(stacks, 1);
	push_a(stacks, 1);
	push_a(stacks, 1);
}

static int	basic_cases(t_stacks *stacks)
{
	if (is_successful(*stacks))
		return (1);
	if (stacks->len_a == 2)
	{
		swap_a(stacks, 1);
		return (1);
	}
	if (stacks->len_a == 3)
	{
		if (stacks->a->v == 2)
			rotate_a(stacks, 1, 0);
		if (stacks->a->below_num->v == 2)
			rotate_a(stacks, 1, 1);
		if (stacks->a->v == 1)
			swap_a(stacks, 1);
		return (1);
	}
	if (stacks->len_a <= 5)
	{
		four_or_five_stack(stacks);
		return (1);
	}
	return (0);
}

void	sort_stack_a(t_ps *ps)
{
	int	len_stack;

	len_stack = ps->stacks.len_a;
	if (basic_cases(&ps->stacks))
		return ;
	if (len_stack > 5)
		separate_stack_a_med(&ps->stacks);
	push_all_but_med_and_max_in_b(ps, len_stack <= 5);
	while (ps->stacks.len_b > 0)
	{
		apply_rots(find_best_move(ps->stacks), &ps->stacks);
		push_a(&ps->stacks, 1);
	}
	sets_zero_to_top(&ps->stacks);
}
