/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:38:10 by jergauth          #+#    #+#             */
/*   Updated: 2019/02/14 20:38:11 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void			*ft_clean_abort(t_stack **head)
{
	ft_stack_del(head);
	return (NULL);
}

static int			ft_check_args(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		if (!(ft_str_is_numeric(argv[i])) && argv[i][0] != '-')
			return (0);
		i++;
	}
	return (1);
}

static t_stack		*ft_build_stack(char **argv)
{
	t_stack	*stack_a;
	t_stack	*new;
	long	nb;
	size_t	i;

	stack_a = NULL;
	i = 0;
	while (argv[i])
	{
		nb = ft_atol_base(argv[i], 10);
		if (nb > 2147483647 || nb < -2147483648)
			return (ft_clean_abort(&stack_a));
		if (ft_stack_find(stack_a, (int)nb))
			return (ft_clean_abort(&stack_a));
		if (!(new = ft_stack_new((int)nb)))
			return (ft_clean_abort(&stack_a));
		ft_stack_push_back(&stack_a, new);
		i++;
	}
	return (stack_a);
}

t_stack				*ft_check_args_and_build_stack(char **argv)
{
	t_stack	*stack_a;

	if (!(ft_check_args(argv)))
		return (NULL);
	if (!(stack_a = ft_build_stack(argv)))
		return (NULL);
	return (stack_a);
}
