/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 04:30:17 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/11 09:48:06 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	init_ch_data(t_ch *ch, int argc, char const **argv)
{
	ch->stacks.a = 0;
	ch->stacks.b = 0;
	return (check_args(&ch->stacks, argc, argv));
}

int	main(int argc, char const **argv)
{
	t_ch	ch;

	if (argc <= 1)
		return (0);
	if (!init_ch_data(&ch, argc, argv))
		return (ft_perror());
	if (KDEBUG)
		print_stacks(ch.stacks);
	if (is_successful(ch.stacks))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(ch.stacks);
	return (0);
}
