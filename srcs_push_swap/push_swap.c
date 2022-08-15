/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milvintsiss <milvintsiss@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 00:59:20 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/16 01:07:36 by milvintsiss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char const **argv)
{
	t_ps	ps;

	if (argc <= 1)
		return (0);
	if (!init_stacks_data(&ps.stacks, argc, argv))
		return (ft_perror());
	if (KDEBUG)
		print_stacks(ps.stacks);
	if (!find_stack_median(&ps.median, ps.stacks.a, ps.stacks.len_a))
	{
		free_stacks(ps.stacks);
		return (ft_perror());
	}
	sort_stack_a(&ps.stacks);
	free_stacks(ps.stacks);
	return (0);
}
