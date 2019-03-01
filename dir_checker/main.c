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
		ft_dprintf(2, "{red}Error\n{reset}");
	if (msg == 2)
		ft_dprintf(2, "{red}[!] Failed to malloc.\n{reset}");
	st_del(lst);
	return (ret);
}

int			main(int argc, char **argv)
{
	t_st		*lst;
	int			ret;
	// t_stack		*stack_a;
	// t_stack		*instructions_set;
	// t_options	*fl;

	if (argc >= 2)
	{
		argv++;
		if (!(lst = init_stacks()))
			return (ft_clean_abort(NULL, 2, 1));
		if (!(lst->opt_fl = init_options()))
			return (ft_clean_abort(&lst,  2, 1));
		if (!(lst->st_a = ft_check_args_and_build_stack(lst->opt_fl, argv)))
			return (ft_clean_abort(&lst, 1, 1));
		// ft_stack_print(stack_a);
		if (ft_stack_is_sort(lst->st_a, 0))
			return (ft_clean_abort(&lst, 0, 0));
		if (!(lst->st_instruct = ft_read_stdin(lst->opt_fl)))
			return (ft_clean_abort(&lst, 1, 1));
		ret = ft_start_instructions(&lst->st_a, lst->st_instruct, lst->opt_fl);
		if (ret == -1)
			return (ft_clean_abort(&lst, 2, 1));
		else
			return (ft_clean_abort(&lst, 0, 0));	
		if (lst->opt_fl->count == 1)
		{
			ft_printf("{green}");
			ft_putnbr(ft_stack_size(lst->st_instruct));
			ft_printf("{reset}\n");
		}
		st_del(&lst);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
