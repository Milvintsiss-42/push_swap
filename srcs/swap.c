/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 01:33:56 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/11 04:21:52 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

static int	swap(t_num **stack)
{
	t_num	*tmp;

	if (!*stack || !(*stack)->below_num)
		return (0);
	tmp = (*stack)->below_num;
	(*stack)->below_num = (*stack)->below_num->below_num;
	(*stack)->below_num->below_num = *stack;
	*stack = tmp;
	return (1);
}

void	swap_a(t_stacks *stacks, int print)
{
	if (!swap(&stacks->a))
		return ;
	if (print)
		write(1, "sa\n", 3);
}

void	swap_b(t_stacks *stacks, int print)
{
	if (!swap(&stacks->b))
		return ;
	if (print)
		write(1, "sb\n", 3);
}

void	swap_ab(t_stacks *stacks, int print)
{
	if (!stacks->a || !stacks->a->below_num
		|| !stacks->b || !stacks->b->below_num)
		return ;
	swap(&stacks->a);
	swap(&stacks->b);
	if (print)
		write(1, "ss\n", 3);
}
