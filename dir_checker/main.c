/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:42:52 by jergauth          #+#    #+#             */
/*   Updated: 2019/02/13 15:42:54 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_clean_abort(t_st **lst, const int msg, const int ret)
{
	if (msg == 1)
		ft_dprintf(2, "Error\n");
	if (msg == 2)
		ft_dprintf(2, "{red}[!] Failed to malloc.\n{reset}");
	st_del(lst);
	return (ret);
}

int			main(int argc, char **argv)
{
	t_st	*lst;
	int		ret;

	if (argc >= 2)
	{
		argv++;
		if (!(lst = init_stacks()))
			return (ft_clean_abort(NULL, 2, 1));
		if (!(ft_check_args_and_build_stack(lst, argv)))
			return (ft_clean_abort(&lst, 1, 1));
		if (!(ft_read_stdin(lst)))
			return (ft_clean_abort(&lst, 1, 1));
		ret = ft_start_instructions(lst);
		if (ret == -1)
			return (ft_clean_abort(&lst, 2, 1));
		st_del(&lst);
	}
	return (0);
}
