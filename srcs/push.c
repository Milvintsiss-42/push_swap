/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 01:40:50 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/11 04:21:44 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

static int	push(t_num **stack_1, t_num **stack_2)
{
	t_num	*tmp;

	if (!*stack_2)
		return (0);
	tmp = (*stack_2)->below_num;
	(*stack_2)->below_num = *stack_1;
	*stack_1 = *stack_2;
	*stack_2 = tmp;
	return (1);
}

void	push_a(t_stacks *stacks, int print)
{
	if (!push(&stacks->a, &stacks->b))
		return ;
	if (print)
		write(1, "pa\n", 3);
}

void	push_b(t_stacks *stacks, int print)
{
	if (!push(&stacks->b, &stacks->a))
		return ;
	if (print)
		write(1, "pb\n", 3);
}
