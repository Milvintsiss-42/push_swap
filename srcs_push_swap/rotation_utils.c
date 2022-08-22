/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2122/08/22 02:44:12 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/22 06:54:52 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_rots	empty_rots_struct(void)
{
	t_rots	rots;

	rots.n_ra = 0;
	rots.n_rb = 0;
	rots.n_rr = 0;
	rots.n_rra = 0;
	rots.n_rrb = 0;
	rots.n_rrr = 0;
	return (rots);
}

int	total_rots(t_rots rots)
{
	return (rots.n_ra + rots.n_rb + rots.n_rr
		+ rots.n_rra + rots.n_rrb + rots.n_rrr);
}

void	apply_rots(t_rots rots, t_stacks *stacks)
{
	while (rots.n_ra--)
		rotate_a(stacks, 1, 0);
	while (rots.n_rb--)
		rotate_b(stacks, 1, 0);
	while (rots.n_rr--)
		rotate_ab(stacks, 1, 0);
	while (rots.n_rra--)
		rotate_a(stacks, 1, 1);
	while (rots.n_rrb--)
		rotate_b(stacks, 1, 1);
	while (rots.n_rrr--)
		rotate_ab(stacks, 1, 1);
}
