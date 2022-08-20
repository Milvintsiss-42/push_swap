/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:23:12 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/20 20:04:55 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int	is_successful(t_stacks stacks)
{
	if (stacks.b)
		return (0);
	if (!is_stack_ordered(stacks.a))
		return (0);
	return (1);
}

int	is_stack_ordered(t_num *stack)
{
	if (!stack)
		return (0);
	if (!stack->below_num)
		return (1);
	while (stack->below_num)
	{
		if (stack->v > stack->below_num->v)
			return (0);
		stack = stack->below_num;
	}
	return (1);
}

int	add_num_to_stack(int v, const char *str, t_num **stack)
{
	t_num	*new;

	new = malloc(sizeof(t_num));
	if (!new)
		return (0);
	new->below_num = *stack;
	new->str = str;
	new->v = v;
	*stack = new;
	return (1);
}
