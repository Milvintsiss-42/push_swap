/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milvintsiss <milvintsiss@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 00:23:42 by milvintsiss       #+#    #+#             */
/*   Updated: 2022/08/16 01:05:43 by milvintsiss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*create_stack_cpy(t_num *stack, int stack_len)
{
	int	*stack_arr;
	int	i;

	stack_arr = malloc(sizeof(int) * stack_len);
	if (!stack_arr)
		return (0);
	i = 0;
	while (stack)
	{
		stack_arr[i++] = stack->v;
		stack = stack->below_num;
	}
	return (stack_arr);
}

static void	order_stack_arr(int *stack_arr, int stack_len)
{
	int	i;
	int	temp;

	i = 0;
	while (i < stack_len - 1)
	{
		if (stack_arr[i] > stack_arr[i + 1])
		{
			temp = stack_arr[i];
			stack_arr[i] = stack_arr[i + 1];
			stack_arr[i + 1] = temp;
			i = i - 2;
			if (i < 0)
				i = -1;
		}
		i++;
	}
}

int	find_stack_median(int *stack_median, t_num *stack, int stack_len)
{
	int	*stack_arr;

	stack_arr = create_stack_cpy(stack, stack_len);
	if (!stack_arr)
		return (0);
	order_stack_arr(stack_arr, stack_len);
	*stack_median = stack_arr[stack_len / 2];
	free(stack_arr);
	return (1);
}
