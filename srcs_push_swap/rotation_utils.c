/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 02:44:12 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/22 02:44:28 by ple-stra         ###   ########.fr       */
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
