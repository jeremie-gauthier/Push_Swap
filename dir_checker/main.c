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

static int	ft_clean_abort(t_stack **stack_a, t_stack **instruc_set,
					t_options **fl, int msg, int ret)
{
	if (msg == 1)
		ft_dprintf(2, "{red}Error\n{reset}");
	if (msg == 2)
		ft_dprintf(2, "{red}[!] Failed to malloc.\n{reset}");
	ft_stack_del(stack_a);
	ft_stack_del(instruc_set);
	ft_memdel((void*)fl);
	return (ret);
}

int			main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*instructions_set;
	t_options	*fl;

	if (argc >= 2)
	{
		argv++;
		if (!(fl = init_options()))
			return (ft_clean_abort(NULL, NULL, NULL, 2, 1));
		if (!(stack_a = ft_check_args_and_build_stack(fl, argv)))
			return (ft_clean_abort(NULL, NULL, &fl, 1, 1));
		if (ft_stack_is_sort(stack_a, 0))
		{
			write(1, "OK\n", 3);
			ft_stack_del(&stack_a);
			return (0);
		}
		if (!(instructions_set = ft_read_stdin()))
			return (ft_clean_abort(&stack_a, NULL, &fl, 1, 1));
		if (!(ft_start_instructions(&stack_a, instructions_set)))
			return (ft_clean_abort(&stack_a, &instructions_set, &fl, 0, 1));
		if (fl->count == 1)
		{
			ft_printf("{green}%i\n{reset}", ft_stack_size(instructions_set));
		}
		ft_stack_del(&stack_a);
		ft_stack_del(&instructions_set);
		ft_memdel((void*)&fl);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
