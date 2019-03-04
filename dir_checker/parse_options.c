/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:19:07 by jergauth          #+#    #+#             */
/*   Updated: 2019/03/04 18:19:07 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_get_time(t_st *lst, char ***argv)
{
	(*argv)++;
	lst->opt_fl->time = ft_atoi(**argv);
	if (lst->opt_fl->time > 5000)
		lst->opt_fl->time = 5000;
	(*argv)++;
}

static int	ft_get_pathname(t_st *lst, char ***argv)
{
	(*argv)++;
	if (!(lst->opt_fl->pathname = ft_strdup(**argv)))
		return (0);
	(*argv)++;
	return (1);
}

int			ft_parse_options(t_st *lst, char ***argv)
{
	while (!ft_strcmp(**argv, "-v") || !ft_strcmp(**argv, "-t")
				|| !ft_strcmp(**argv, "-l") || !ft_strcmp(**argv, "-f"))
	{
		if (ft_strcmp(**argv, "-v") == 0)
		{
			lst->opt_fl->visu = 1;
			(*argv)++;
		}
		if (ft_strcmp(**argv, "-t") == 0)
			ft_get_time(lst, argv);
		if (ft_strcmp(**argv, "-l") == 0)
		{
			lst->opt_fl->count = 1;
			(*argv)++;
		}
		if (ft_strcmp(**argv, "-f") == 0)
			if (!(ft_get_pathname(lst, argv)))
				return (0);
	}
	return (1);
}
