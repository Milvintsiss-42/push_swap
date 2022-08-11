/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 04:59:40 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/11 04:40:10 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_num
{
	int				v;
	char const		*str;
	struct s_num	*below_num;
}	t_num;

typedef struct s_stacks
{
	t_num	*a;
	t_num	*b;
}	t_stacks;

int			free_stacks(t_stacks stacks);

void		push_a(t_stacks *stacks, int print);
void		push_b(t_stacks *stacks, int print);
void		push_ab(t_stacks *stacks, int print);

void		rotate_a(t_stacks *stacks, int print, int reverse);
void		rotate_b(t_stacks *stacks, int print, int reverse);
void		rotate_ab(t_stacks *stacks, int print, int reverse);

void		swap_a(t_stacks *stacks, int print);
void		swap_b(t_stacks *stacks, int print);
void		swap_ab(t_stacks *stacks, int print);

#endif
