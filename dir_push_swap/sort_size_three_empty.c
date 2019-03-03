/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size_three_empty.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:23:03 by jergauth          #+#    #+#             */
/*   Updated: 2019/03/03 13:23:04 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_main_stack_a(t_st *lst)
{
	if (lst->st_a->next->nb > lst->st_a->nb
				&& lst->st_a->next->nb > lst->st_a->next->next->nb)
	{
		if (!(ft_rev_rotate_and_write(lst, 0)))
			return (0);
	}
	if (lst->st_a->nb > lst->st_a->next->nb
				&& lst->st_a->nb > lst->st_a->next->next->nb)
	{
		if (!(ft_rotate_and_write(lst, 0)))
			return (0);
	}
	if (lst->st_a->nb > lst->st_a->next->nb)
	{
		if (!(ft_swap_and_write(lst, 0)))
			return (0);
	}
	return (1);
}

static int	ft_main_stack_b(t_st *lst)
{
	unsigned int	size;

	size = 3;
	while (size)
	{
		if (lst->st_b->nb == ft_stack_nmin(lst->st_b, size))
		{
			if (!(ft_top_is_min(lst, &size)))
				return (0);
		}
		else if (lst->st_b->next->nb == ft_stack_nmin(lst->st_b, size))
		{
			if (!(ft_mid_is_min(lst, &size)))
				return (0);
		}
		else
		{
			if (!(ft_other_cases(lst, &size)))
				return (0);
		}
	}
	return (1);
}

int			ft_sort_size_three_empty(t_st *lst, int state)
{
	if (state == 0)
	{
		if (!(ft_main_stack_a(lst)))
			return (0);
	}
	else
	{
		if (!(ft_main_stack_b(lst)))
			return (0);
	}
	return (1);
}
