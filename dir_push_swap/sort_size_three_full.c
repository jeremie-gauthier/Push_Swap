/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size_three_full.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:23:08 by jergauth          #+#    #+#             */
/*   Updated: 2019/03/03 13:23:15 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_main_stack_a(t_st *lst)
{
	if (lst->st_a->nb < lst->st_a->next->nb
				&& lst->st_a->nb < lst->st_a->next->next->nb)
	{
		if (!(ft_top_is_min_full(lst)))
			return (0);
	}
	else if (lst->st_a->nb > lst->st_a->next->nb
				&& lst->st_a->nb < lst->st_a->next->next->nb)
	{
		if (!(ft_top_is_median_value(lst)))
			return (0);
	}
	else if (lst->st_a->next->next->nb > lst->st_a->next->nb
				&& lst->st_a->next->next->nb < lst->st_a->nb)
	{
		if (!(ft_bot_is_median_value(lst)))
			return (0);
	}
	else
	{
		if (!(ft_other_cases_full(lst)))
			return (0);
	}
	return (1);
}

static int	ft_main_stack_b(t_st *lst, unsigned int *size)
{
	while (*size)
	{
		if (lst->st_b->nb == ft_stack_nmin(lst->st_b, *size))
		{
			if (!(ft_push_stack_and_write(lst, -1)))
				return (0);
			if (!(ft_rotate_and_write(lst, 0)))
				return (0);
			(*size)--;
		}
		else if (lst->st_b->next->nb == ft_stack_nmin(lst->st_b, *size))
		{
			if (!(ft_mid_is_max_full_b(lst, size)))
				return (0);
		}
		else
		{
			if (!(ft_other_cases_full_b(lst, size)))
				return (0);
		}
	}
	return (1);
}

int			ft_sort_size_three_full(t_st *lst, int state)
{
	unsigned int	size;

	size = 3;
	if (state == 0)
	{
		if (!(ft_main_stack_a(lst)))
			return (0);
	}
	else
	{
		if (!(ft_main_stack_b(lst, &size)))
			return (0);
	}
	return (1);
}
