/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milvintsiss <milvintsiss@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 00:59:20 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/12 07:07:29 by milvintsiss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_ps_data(t_ps *ps, int argc, char const **argv)
{
	ps->stacks.a = 0;
	ps->stacks.b = 0;
	return (check_args(&ps->stacks, argc, argv));
}

int	main(int argc, char const **argv)
{
	t_ps	ps;

	if (argc <= 1)
		return (0);
	if (!init_ps_data(&ps, argc, argv))
		return (ft_perror());
	if (KDEBUG)
		print_stacks(ps.stacks);
	sort_stack_a(&ps.stacks);
	free_stacks(ps.stacks);
	return (0);
}
