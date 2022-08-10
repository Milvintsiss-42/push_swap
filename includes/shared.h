/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 04:59:40 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/11 00:12:09 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_num
{
	int			v;
	char const	*str;
	t_num		*below_num;
}	t_num;

typedef struct s_stacks
{
	t_num	*a;
	t_num	*b;
}	t_stacks;

#endif