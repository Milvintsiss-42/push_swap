/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:01:02 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/22 02:45:02 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "shared.h"

typedef struct s_ps
{
	t_stacks	stacks;
	int			median;
}	t_ps;

typedef struct s_rot
{
	int		n_ra;
	int		n_rb;
	int		n_rr;
	int		n_rra;
	int		n_rrb;
	int		n_rrr;
}	t_rots;

int			*create_stack_cpy_arr(t_num *stack, int stack_len);
void		order_stack_arr(int *stack_arr, int stack_len);
int			sets_values_to_suite(t_stacks stacks);

int			find_stack_relative_pos(int *pos, t_num *stack, int stack_len,
				double pos_r);
int			find_stack_median(int *stack_median, t_num *stack, int stack_len);

void		separate_stack_a_med(t_stacks *stacks);
void		separate_stack_b_med(t_stacks *stacks);
void		push_all_but_two_in_b(t_stacks *stacks);

t_rots		empty_rots_struct(void);
int			total_rots(t_rots rots);

void		sort_stack_a(t_ps *ps);

#endif
