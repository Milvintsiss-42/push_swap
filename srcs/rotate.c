/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 01:41:39 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/10 23:57:18 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_num **stack)
{
	t_num	*bottom;

	if (!*stack || !(*stack)->below_num)
		return (0);
	bottom = *stack;
	while (bottom->below_num)
		bottom = bottom->below_num;
	bottom->below_num = *stack;
	*stack = (*stack)->below_num;
	bottom->below_num->below_num = 0;
	return (1);
}

static int	rrotate(t_num **stack)
{
	t_num	*pre_bottom;

	if (!*stack || !(*stack)->below_num)
		return (0);
	pre_bottom = *stack;
	while (pre_bottom->below_num->below_num)
		pre_bottom = pre_bottom->below_num;
	pre_bottom->below_num->below_num = *stack;
	*stack = pre_bottom->below_num;
	pre_bottom->below_num = 0;
	return (1);
}

void	rotate_a(t_stacks *stacks, int print, int reverse)
{
	if (reverse)
	{
		if (!rrotate(&stacks->a))
			return ;
		if (print)
			write(1, "rra\n", 4);
	}
	else
	{
		if (!rotate(&stacks->a))
			return ;
		if (print)
			write(1, "ra\n", 3);
	}
}

void	rotate_b(t_stacks *stacks, int print, int reverse)
{
	if (reverse)
	{
		if (!rrotate(&stacks->b))
			return ;
		if (print)
			write(1, "rrb\n", 4);
	}
	else
	{
		if (!rotate(&stacks->b))
			return ;
		if (print)
			write(1, "rb\n", 3);
	}
}

void	rotate_ab(t_stacks *stacks, int print, int reverse)
{
	if (!stacks->a || !stacks->a->below_num
		|| !stacks->b || !stacks->b->below_num)
		return ;
	if (reverse)
	{
		rrotate(&stacks->a);
		rrotate(&stacks->b);
		if (print)
			write(1, "rrr\n", 4);
	}
	else
	{
		rotate(&stacks->a);
		rotate(&stacks->b);
		if (print)
			write(1, "rr\n", 3);
	}
}
