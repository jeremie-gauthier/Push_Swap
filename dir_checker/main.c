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
					int msg, int ret)
{
	if (msg == 1)
		write(2, "Error\n", 6);
	ft_stack_del(stack_a);
	ft_stack_del(instruc_set);
	return (ret);
}

int			main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*instructions_set;

	if (argc >= 2)
	{
		argv++;
		if (!(stack_a = ft_check_args_and_build_stack(argv)))
			return (ft_clean_abort(NULL, NULL, 1, 1));
		if (ft_stack_is_sort(stack_a, 0))
		{
			write(1, "OK\n", 3);
			ft_stack_del(&stack_a);
			return (0);
		}
		if (!(instructions_set = ft_read_stdin()))
			return (ft_clean_abort(&stack_a, NULL, 1, 1));
		if (!(ft_start_instructions(&stack_a, instructions_set)))
			return (ft_clean_abort(&stack_a, &instructions_set, 0, 1));
		ft_stack_del(&stack_a);
		ft_stack_del(&instructions_set);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
