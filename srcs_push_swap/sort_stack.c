/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:00:24 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/22 13:51:14 by ple-stra         ###   ########.fr       */
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

void	sort_stack_a(t_ps *ps)
{
	int	len_stack;

	len_stack = ps->stacks.len_a;
	if (basic_cases(&ps->stacks))
		return ;
	separate_stack_a_med(&ps->stacks);
	if (len_stack > 7)
		push_all_but_med_and_max_in_b(ps);
	while (ps->stacks.len_b > 0)
	{
		apply_rots(find_best_move(ps->stacks), &ps->stacks);
		push_a(&ps->stacks, 1);
	}
	sets_zero_to_top(&ps->stacks);
}
