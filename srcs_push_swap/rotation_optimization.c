/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_optimization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 02:42:22 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/22 10:52:01 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_rots	get_rots_for_num(t_stacks stacks, int num);
static int		get_closest_sup_num_in_stack(t_num *stack, int num);
static void		optimize_rots(t_rots *rots);

t_rots	find_best_move(t_stacks stacks)
{
	t_rots	best_rotations;
	int		nb_rots;
	t_num	*stack_b;
	t_rots	cur;

	nb_rots = INTMAX;
	stack_b = stacks.b;
	while (stack_b)
	{
		cur = get_rots_for_num(stacks, stack_b->v);
		if (total_rots(cur) < nb_rots)
		{
			nb_rots = total_rots(cur);
			best_rotations = cur;
		}
		stack_b = stack_b->below_num;
	}
	return (best_rotations);
}

static t_rots	get_rots_for_num(t_stacks stacks, int num)
{
	t_rots	rots;
	int		num_pos;

	rots = empty_rots_struct();
	num_pos = get_cur_pos_of_num_in_stack(stacks.b, num);
	rots.n_rb = num_pos;
	rots.n_rrb = stacks.len_b - num_pos;
	num_pos = get_cur_pos_of_num_in_stack(stacks.a,
			get_closest_sup_num_in_stack(stacks.a, num));
	rots.n_ra = num_pos;
	rots.n_rra = stacks.len_a - num_pos;
	optimize_rots(&rots);
	return (rots);
}

int	get_cur_pos_of_num_in_stack(t_num *stack, int num)
{
	int	cur_pos;

	cur_pos = 0;
	while (stack && stack->v != num)
	{
		cur_pos++;
		stack = stack->below_num;
	}
	if (!stack)
		return (-1);
	return (cur_pos);
}

static int	get_closest_sup_num_in_stack(t_num *stack, int num)
{
	int	closest_num;

	closest_num = INTMAX;
	while (stack)
	{
		if (num < stack->v && stack->v < closest_num)
			closest_num = stack->v;
		stack = stack->below_num;
	}
	return (closest_num);
}

static void	optimize_rots(t_rots *rots)
{
	if (rots->n_ra > rots->n_rra)
		rots->n_ra = 0;
	else
		rots->n_rra = 0;
	if (rots->n_rb > rots->n_rrb)
		rots->n_rb = 0;
	else
		rots->n_rrb = 0;
	if (rots->n_rra == 0 && rots->n_rrb == 0)
	{
		rots->n_rr = ft_min(rots->n_ra, rots->n_rb);
		rots->n_ra -= rots->n_rr;
		rots->n_rb -= rots->n_rr;
	}
	else if (rots->n_ra == 0 && rots->n_rb == 0)
	{
		rots->n_rrr = ft_min(rots->n_rra, rots->n_rrb);
		rots->n_rra -= rots->n_rrr;
		rots->n_rrb -= rots->n_rrr;
	}
}
