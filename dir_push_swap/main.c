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

static int	ft_clean_abort(t_stack **stack_a, int msg, int ret)
{
	if (msg == 1)
		write(2, "Error\n", 6);
	ft_stack_del(stack_a);
	return (ret);
}

int		ft_print_instructions(t_stack *instruct_set)
{
	char	*ret;
	size_t	i;

	if (!(ret = (char*)malloc(sizeof(*ret) * (ft_stack_size(instruct_set) * 3) + 1)))
		return (0);
	i = 0;
	while (instruct_set)
	{
		if (instruct_set->nb >= 0 && instruct_set->nb <= 2)
		{
			ret[i++] = 's';
			if (instruct_set->nb == 0)
				ret[i++] = 'a';
			else if (instruct_set->nb == 0)
				ret[i++] = 'b';
			else
				ret[i++] = 's';
		}
		else if (instruct_set->nb >= 3 && instruct_set->nb <= 5)
		{
			ret[i++] = 'r';
			if (instruct_set->nb == 3)
				ret[i++] = 'a';
			else if (instruct_set->nb == 4)
				ret[i++] = 'b';
			else
				ret[i++] = 'r';
		}
		else if (instruct_set->nb >= 6 && instruct_set->nb <= 8)
		{
			ret[i++] = 'r';
			ret[i++] = 'r';
			if (instruct_set->nb == 6)
				ret[i++] = 'a';
			else if (instruct_set->nb == 7)
				ret[i++] = 'b';
			else
				ret[i++] = 'r';
		}
		else
		{
			ret[i++] = 'p';
			if (instruct_set->nb == 9)
				ret[i++] = 'a';
			else
				ret[i++] = 'b';
		}
		ret[i++] = '\n';
		instruct_set = instruct_set->next;
	}
	ret[i] = '\0';
	ft_putstr(ret);
	ft_strdel(&ret);
	return (1);
}

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*instruct_set;

	instruct_set = NULL;
	if (argc >= 2)
	{
		argv++;
		// if (argc == 2) //parser la string strsplit
		//dans tous les cas ?? ou juste argc =2

		if (!(stack_a = ft_check_args_and_build_stack(argv)))
			return (ft_clean_abort(NULL, 1, 1));
		if (ft_stack_is_sort(stack_a, ft_stack_size(stack_a)))
		{
			ft_stack_del(&stack_a);
			return (0);
		}
	// instruct_set = ft_dumb_sort(&stack_a, ft_stack_size(stack_a));
	instruct_set = ft_quick_sort(&stack_a, ft_stack_size(stack_a));
		ft_print_instructions(instruct_set);
		// ft_stack_print(instruct_set);
		// ft_printf("STACK A\n");
		// ft_stack_print(stack_a);

		ft_stack_del(&stack_a);
		ft_stack_del(&instruct_set);
	}
	// else
	// 	write(2, "Error\n", 6);
	return (0);
}
