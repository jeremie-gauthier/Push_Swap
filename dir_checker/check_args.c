/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:42:46 by jergauth          #+#    #+#             */
/*   Updated: 2019/02/13 15:42:48 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_clean_abort(char **tab, size_t len)
{
	ft_tabdel((void*)tab, len);
	return (0);
}

static int	ft_check_args(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		if (!(ft_str_is_numeric(argv[i])) && argv[i][0] != '-'
				&& !ft_strchr(argv[i], ' '))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_depack_args(char *args, t_stack **stack_a)
{
	char	**tab;
	size_t	len;
	size_t	i;
 
	if (!(tab = ft_strsplit(args, ' ')))
		return (0);
	len = ft_arrlen((void*)tab);
	i = 0;
	while (i < len)
	{
		if (!(ft_check_args(tab)))
			return (ft_clean_abort(tab, len));
		if (!(ft_stack_append(tab[i], stack_a)))
			return (ft_clean_abort(tab, len));
		i++;
	}
	ft_tabdel((void*)tab, len);
	return (1);
}

static int	ft_build_stack(t_st *lst, char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "") == 0)
			return (0);
		if (ft_strchr(argv[i], ' ') != NULL)
		{
			if (!(ft_depack_args(argv[i], &lst->st_a)))
				return (0);
		}
		else
		{
			if (!(ft_stack_append(argv[i], &lst->st_a)))
				return (0);
		}
		i++;
	}
	return (1);
}

int			ft_check_args_and_build_stack(t_st *lst, char **argv)
{
	while (!ft_strcmp(*argv, "-v") || !ft_strcmp(*argv, "-t") || !ft_strcmp(*argv, "-l") || !ft_strcmp(*argv, "-f"))
	{
		if (ft_strcmp(*argv, "-v") == 0)
		{
			lst->opt_fl->visu = 1;
			argv++;
		}
		if (ft_strcmp(*argv, "-t") == 0)
		{
			argv++;
			lst->opt_fl->time = ft_atoi(*argv);
			if (lst->opt_fl->time > 5000)
				lst->opt_fl->time = 5000;
			argv++;
		}
		if (ft_strcmp(*argv, "-l") == 0)
		{
			lst->opt_fl->count = 1;
			argv++;
		}
		if (ft_strcmp(*argv, "-f") == 0)
		{
			argv++;
			if (!(lst->opt_fl->pathname = ft_strdup(*argv)))
				return (0);
			argv++;
		}
	}
	if (!(ft_check_args(argv)))
		return (0);
	if (!(ft_build_stack(lst, argv)))
		return (0);
	return (1);
}
