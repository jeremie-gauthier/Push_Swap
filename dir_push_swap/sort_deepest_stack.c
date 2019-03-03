/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_deepest_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:22:51 by jergauth          #+#    #+#             */
/*   Updated: 2019/03/03 13:22:54 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_size_three_case(t_st *lst, const int state)
{
	if (((state == 0) ? lst->st_a : lst->st_b)->next->next->next == NULL)
	{
		if (!(ft_sort_size_three_empty(lst, state)))
			return (0);
	}
	else
	{
		if (!(ft_sort_size_three_full(lst, state)))
			return (0);
	}
	return (1);
}

int			ft_sort_deepest_stack(t_st *lst, unsigned int size, const int state)
{
	int		i;

	if (ft_stack_is_sort((state == 0) ? lst->st_a : lst->st_b, 0) == 1
				&& ((state == 0) ? lst->st_a : lst->st_b) == NULL)
		return (1);
	i = 0;
	if (size == 1)
	{
		if (!(ft_sort_size_one(lst, state)))
			return (0);
	}
	else if (size == 2)
	{
		if (!(ft_sort_size_two(lst, state)))
			return (0);
	}
	else if (size == 3)
	{
		if (!(ft_size_three_case(lst, state)))
			return (0);
	}
	return (1);
}
