/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milvintsiss <milvintsiss@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:01:02 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/12 07:04:55 by milvintsiss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "shared.h"

typedef struct s_ps
{
	t_stacks	stacks;
}	t_ps;

void		sort_stack_a(t_stacks *stacks);

#endif
