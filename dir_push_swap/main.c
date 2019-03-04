/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:38:15 by jergauth          #+#    #+#             */
/*   Updated: 2019/02/14 20:38:16 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_clean_abort(t_st **lst, const int msg, const int ret)
{
	if (msg == 1)
		ft_dprintf(2, "Error\n");
	else if (msg == 2)
		ft_dprintf(2, "{red}[!] Failed to malloc.\n{reset}");
	else if (msg == 3)
		ft_dprintf(2, "{red}[!] Data set too large.\n{reset}");
	st_del(lst);
	return (ret);
}

static int	ft_select_algo(t_st *lst, const unsigned int size)
{
	if (size > 3 && size < 6)
	{
		if (!(ft_insertion_sort(lst, size)))
			return (0);
	}
	else
	{
		if (!(ft_quick_sort(lst, size, 0)))
			return (0);
	}
	ft_print_instructions(lst);
	return (1);
}

int			main(int argc, char **argv)
{
	t_st	*lst;

	if (argc >= 2)
	{
		argv++;
		if (!(lst = init_stacks()))
			return (ft_clean_abort(NULL, 2, 1));
		if (!(ft_check_args_and_build_stack(lst, argv)))
			return (ft_clean_abort(&lst, 1, 1));
		if (ft_stack_size(lst->st_a) > 5000)
			return (ft_clean_abort(&lst, 3, 1));
		if (ft_stack_is_sort(lst->st_a, 0))
			return (ft_clean_abort(&lst, 0, 0));
		if (!ft_select_algo(lst, ft_stack_size(lst->st_a)))
			return (ft_clean_abort(&lst, 1, 1));
		st_del(&lst);
	}
	return (0);
}
