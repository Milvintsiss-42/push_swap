/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:03:53 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/20 20:03:55 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// [pos_r] must be between 0.1 and 1.0 included
int	find_stack_relative_pos(int *pos, t_num *stack, int stack_len,
	double pos_r)
{
	int	*stack_arr;

	stack_arr = create_stack_cpy_arr(stack, stack_len);
	if (!stack_arr)
		return (0);
	order_stack_arr(stack_arr, stack_len);
	*pos = stack_arr[(int)(stack_len * pos_r)];
	free(stack_arr);
	return (1);
}

int	find_stack_median(int *stack_median, t_num *stack, int stack_len)
{
	return (find_stack_relative_pos(stack_median, stack, stack_len, 0.5));
}
