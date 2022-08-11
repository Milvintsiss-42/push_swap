/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 06:42:01 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/11 07:15:40 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	print_stacks(t_stacks stacks)
{
	ft_printf("----------------------\n");
	ft_printf(" %-12s|%12s\n", "Stack A", "Stack B");
	while (stacks.a || stacks.b)
	{
		if (stacks.a)
		{
			ft_printf(" %-12d|", stacks.a->v);
			stacks.a = stacks.a->below_num;
		}
		else
			ft_printf(" %-12s|", "x");
		if (stacks.b)
		{
			ft_printf("%12d\n", stacks.b->v);
			stacks.b = stacks.b->below_num;
		}
		else
			ft_printf("%12s\n", "x");
	}
	ft_printf("----------------------\n");
}
