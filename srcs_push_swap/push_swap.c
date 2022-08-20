/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 00:59:20 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/20 20:18:24 by ple-stra         ###   ########.fr       */
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
	sets_values_to_suite(ps.stacks);
	if (KDEBUG)
		print_stacks(ps.stacks);
	sort_stack_a(&ps);
	if (KDEBUG)
		print_stacks(ps.stacks);
	free_stacks(ps.stacks);
	return (0);
}
