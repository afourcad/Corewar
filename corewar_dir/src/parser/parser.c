/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:56:21 by lde-moul          #+#    #+#             */
/*   Updated: 2017/10/30 16:52:51 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	error(const char *msg)
{
	ft_printf(msg);
	exit(1);
}

static void	parse_dump(int argc, char **argv, int *i, t_vm *vm)
{
	(*i)++;
	if (*i == argc)
		error("Missing argument after -dump\n");
	if (invalid_int(argv[*i]))
		error("Invalid dump cycle\n");
	vm->dump_cycle = ft_atoi(argv[*i]);
}

static void	parse_options(int argc, char **argv, int *i, t_vm *vm)
{
	vm->dump_cycle = -1;
	vm->show_lives = 1;
	vm->visu = 0;
	*i = 1;
	while (*i < argc)
	{
		if (!ft_strcmp(argv[*i], "-dump"))
			parse_dump(argc, argv, i, vm);
		else if (!ft_strcmp(argv[*i], "-v"))
			vm->visu = 1;
		else if (!ft_strcmp(argv[*i], "-s"))
			vm->show_lives = 0;
		else
			return ;
		(*i)++;
	}
}

static void	parse_players(int argc, char **argv, int *i, t_vm *vm)
{
	vm->num_players = 0;
	while (*i < argc)
	{
		vm->players[vm->num_players].number = -vm->num_players - 1;
		if (!ft_strcmp(argv[*i], "-n"))
		{
			if (++(*i) == argc)
				error("Missing argument after -n\n");
			if (invalid_int(argv[*i]))
				error("Invalid player number\n");
			vm->players[vm->num_players].number = ft_atoi(argv[(*i)++]);
			if (*i == argc)
				error("Missing player name\n");
		}
		if (vm->num_players >= MAX_PLAYERS)
			error("Too many champions\n");
		load_player(&vm->players[vm->num_players], argv[*i], vm);
		vm->num_players++;
		(*i)++;
	}
}

void		parse(int argc, char **argv, t_vm *vm)
{
	int	i;

	parse_options(argc, argv, &i, vm);
	parse_players(argc, argv, &i, vm);
	if (!vm->num_players)
	{
		ft_printf("Usage: ./corewar [-v] [-dump nbr_cycles] "
					"[[-n number] champion1.cor] ...");
		exit(1);
	}
}
