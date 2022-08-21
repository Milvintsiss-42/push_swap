/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:00:24 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/21 23:30:18 by ple-stra         ###   ########.fr       */
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

void	sort_stack_a(t_ps *ps)
{
	if (basic_cases(&ps->stacks))
		return ;
	separate_stack_a_med(&ps->stacks);
}
