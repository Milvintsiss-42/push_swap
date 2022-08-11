/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:37:55 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/11 07:50:45 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

static int	is_int(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str && ft_isdigit(*str))
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}

static int	custom_atoi(const char *nptr)
{
	int	nb;
	int	nb_prec;
	int	neg;

	nb = 0;
	neg = 1 - (2 * (*nptr == '-'));
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr && ft_isdigit(*nptr))
	{
		nb_prec = nb;
		nb = nb * 10 + *(nptr++) - '0';
		if (nb_prec > nb && nb != -2147483648)
			return (-1 * neg);
	}
	return (nb * neg);
}

static int	is_duplicata(t_stacks stacks, int input_nb)
{
	while (stacks.a && stacks.a->v != input_nb)
		stacks.a = stacks.a->below_num;
	if (stacks.a != 0)
		return (1);
	return (0);
}

static int	parse_input(t_stacks *stacks, int argc, char const **argv)
{
	int		input_nb;
	t_num	*new;

	argv += argc - 1;
	argc--;
	while (argc--)
	{
		if (!is_int(*argv))
			return (free_stacks(*stacks));
		input_nb = custom_atoi(*argv);
		if ((input_nb == -1 && (**argv == '+' || ft_isdigit(**argv)))
			|| (input_nb == 1 && **argv == '-'))
			return (free_stacks(*stacks));
		if (is_duplicata(*stacks, input_nb))
			return (free_stacks(*stacks));
		new = malloc(sizeof(t_num));
		if (!new)
			return (free_stacks(*stacks));
		new->below_num = stacks->a;
		new->str = *argv;
		new->v = input_nb;
		stacks->a = new;
		argv--;
	}
	return (0);
}

int	check_args(t_stacks *stacks, int argc, char const **argv)
{
	if (argc <= 1)
		return (0);
	if (parse_input(stacks, argc, argv))
		return (0);
	return (1);
}
