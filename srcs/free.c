/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:11:17 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/09 18:19:21 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

static void	free_stack(t_num *num)
{
	t_num	*to_free;

	while (num)
	{
		to_free = num;
		num = num->below_num;
		free(to_free);
	}
}

int	free_stacks(t_stacks stacks)
{
	free_stack(stacks.a);
	free_stack(stacks.b);
	return (1);
}
