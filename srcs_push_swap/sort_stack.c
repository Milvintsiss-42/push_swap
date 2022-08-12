/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milvintsiss <milvintsiss@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 07:01:23 by milvintsiss       #+#    #+#             */
/*   Updated: 2022/08/12 08:22:34 by milvintsiss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_a(t_stacks *stacks)
{
	if (is_successful(*stacks))
		return ;
	if (stacks->len_a == 2)
	{
		swap_a(stacks, 1);
		return ;
	}
}
