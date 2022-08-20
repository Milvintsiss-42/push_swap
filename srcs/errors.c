/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:05:28 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/20 20:05:29 by ple-stra         ###   ########.fr       */
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
