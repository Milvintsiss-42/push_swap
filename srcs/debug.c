/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 06:42:01 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/20 20:54:40 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	print_stacks(t_stacks stacks)
{
	ft_printf("----------------------------------\n");
	ft_printf(" %-16s|%16s\n", "Stack A", "Stack B");
	ft_printf("----------------------------------\n");
	while (stacks.a || stacks.b)
	{
		if (stacks.a)
		{
			ft_printf(" %2d: %-12s|", stacks.a->v - INTMIN, stacks.a->str);
			stacks.a = stacks.a->below_num;
		}
		else
			ft_printf(" %-16s|", " ");
		if (stacks.b)
		{
			ft_printf(" %2d: %12s\n", stacks.b->v - INTMIN, stacks.b->str);
			stacks.b = stacks.b->below_num;
		}
		else
			ft_printf("%16s\n", " ");
	}
	ft_printf("----------------------------------\n");
}
