/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 04:30:17 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/11 08:03:36 by ple-stra         ###   ########.fr       */
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

	if (!init_ch_data(&ch, argc, argv))
		return (ft_perror());
	if (KDEBUG)
		print_stacks(ch.stacks);
	free_stacks(ch.stacks);
	return (0);
}
