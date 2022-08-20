/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:04:21 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/20 20:04:24 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char const **argv)
{
	t_stacks	stacks;

	if (argc <= 1)
		return (0);
	if (!init_stacks_data(&stacks, argc, argv))
		return (ft_perror());
	if (!exec_instructions(&stacks))
		return (ft_perror());
	if (KDEBUG)
		print_stacks(stacks);
	if (is_successful(stacks))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(stacks);
	return (0);
}
