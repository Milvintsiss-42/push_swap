/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 01:41:39 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/07 01:45:16 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(int reverse)
{
	if (reverse)
		write(1, "rra\n", 4);
	else
		write(1, "ra\n", 3);
}

void	rotate_b(int reverse)
{
	if (reverse)
		write(1, "rrb\n", 4);
	else
		write(1, "rb\n", 3);
}

void	rotate_ab(int reverse)
{
	if (reverse)
		write(1, "rrr\n", 4);
	else
		write(1, "rr\n", 3);
}
