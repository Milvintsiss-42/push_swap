/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 04:59:40 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/20 19:51:19 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

# ifndef KDEBUG
#  define KDEBUG 0
# endif

# define INTMAX		2147483647
# define INTMIN		-2147483648

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
	int		len_a;
	int		len_b;
}	t_stacks;

void		print_stacks(t_stacks stacks);

int			ft_perror(void);
int			free_stacks(t_stacks stacks);
void		exception_exit(t_stacks stacks);

int			init_stacks_data(t_stacks *stacks, int argc, char const **argv);

int			check_args(t_stacks *stacks, int argc, char const **argv);

int			is_successful(t_stacks stacks);
int			is_stack_ordered(t_num *stack);
int			add_num_to_stack(int v, const char *str, t_num **stack);

void		push_a(t_stacks *stacks, int print);
void		push_b(t_stacks *stacks, int print);

void		rotate_a(t_stacks *stacks, int print, int reverse);
void		rotate_b(t_stacks *stacks, int print, int reverse);
void		rotate_ab(t_stacks *stacks, int print, int reverse);

void		swap_a(t_stacks *stacks, int print);
void		swap_b(t_stacks *stacks, int print);
void		swap_ab(t_stacks *stacks, int print);

#endif
