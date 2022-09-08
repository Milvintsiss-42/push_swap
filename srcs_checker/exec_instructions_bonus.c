/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:04:11 by ple-stra          #+#    #+#             */
/*   Updated: 2022/09/08 15:16:04 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	swap(t_stacks *stacks, char *instruction)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		swap_a(stacks, 0);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		swap_b(stacks, 0);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
		swap_ab(stacks, 0);
	else
		return (0);
	return (1);
}

static int	push(t_stacks *stacks, char *instruction)
{
	if (ft_strncmp(instruction, "pa\n", 3) == 0)
		push_a(stacks, 0);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		push_b(stacks, 0);
	else
		return (0);
	return (1);
}

static int	rotate(t_stacks *stacks, char *instruction)
{
	if (ft_strncmp(instruction, "ra\n", 3) == 0)
		rotate_a(stacks, 0, 0);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		rotate_b(stacks, 0, 0);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		rotate_ab(stacks, 0, 0);
	else if (ft_strncmp(instruction, "rra\n", 3) == 0)
		rotate_a(stacks, 0, 1);
	else if (ft_strncmp(instruction, "rrb\n", 3) == 0)
		rotate_b(stacks, 0, 1);
	else if (ft_strncmp(instruction, "rrr\n", 3) == 0)
		rotate_ab(stacks, 0, 1);
	else
		return (0);
	return (1);
}

int	exec_instructions(t_stacks *stacks)
{
	char	*instruction;
	int		has_error;

	has_error = 0;
	instruction = get_next_line(STDIN_FILENO);
	while (instruction)
	{
		if (!swap(stacks, instruction) && !push(stacks, instruction)
			&& !rotate(stacks, instruction))
			has_error = 1;
		free(instruction);
		instruction = get_next_line(STDIN_FILENO);
	}
	if (has_error)
		return (0);
	return (1);
}
