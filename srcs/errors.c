/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milvintsiss <milvintsiss@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:27:15 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/17 03:23:35 by milvintsiss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int	ft_perror(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void	exception_exit(t_stacks stacks)
{
	free_stacks(stacks);
	exit(ft_perror());
}
