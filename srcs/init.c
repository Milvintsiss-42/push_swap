/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:05:08 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/20 20:05:10 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int	init_stacks_data(t_stacks *stacks, int argc, char const **argv)
{
	stacks->a = 0;
	stacks->b = 0;
	stacks->len_a = 0;
	stacks->len_b = 0;
	return (check_args(stacks, argc, argv));
}
