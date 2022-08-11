/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 04:30:17 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/11 09:51:59 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	init_ch_data(t_stacks *stacks, int argc, char const **argv)
{
	stacks->a = 0;
	stacks->b = 0;
	return (check_args(stacks, argc, argv));
}

int	main(int argc, char const **argv)
{
	t_stacks	stacks;

	if (argc <= 1)
		return (0);
	if (!init_data(&stacks, argc, argv))
		return (ft_perror());
	exec_instructions(&stacks);
	if (KDEBUG)
		print_stacks(stacks);
	if (is_successful(stacks))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(stacks);
	return (0);
}
