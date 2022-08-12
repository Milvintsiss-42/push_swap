/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milvintsiss <milvintsiss@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 08:37:33 by milvintsiss       #+#    #+#             */
/*   Updated: 2022/08/12 08:38:41 by milvintsiss      ###   ########.fr       */
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
