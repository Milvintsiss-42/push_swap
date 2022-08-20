/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_arr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:20:32 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/20 19:21:07 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_stack_cpy_arr(t_num *stack, int stack_len)
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

void	order_stack_arr(int *stack_arr, int stack_len)
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