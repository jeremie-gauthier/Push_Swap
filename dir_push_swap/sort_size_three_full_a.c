/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size_three_full_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:50:29 by jergauth          #+#    #+#             */
/*   Updated: 2019/03/03 14:50:30 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	top < (mid && bot)
*/

int			ft_top_is_min_full(t_st *lst)
{
	unsigned int	i;

	i = 0;
	if (!(ft_rotate_and_write(lst, 0)))
		return (0);
	if (lst->st_a->nb > lst->st_a->next->nb)
	{
		if (!(ft_swap_and_write(lst, 0)))
			return (0);
	}
	while (i < 2)
	{
		if (!(ft_rotate_and_write(lst, 0)))
			return (0);
		i++;
	}
	return (1);
}

/*
**	top > mid && top < bot
*/

int			ft_top_is_median_value(t_st *lst)
{
	unsigned int	i;

	i = 0;
	if (!(ft_swap_and_write(lst, 0)))
		return (0);
	while (i < 3)
	{
		if (!(ft_rotate_and_write(lst, 0)))
			return (0);
		i++;
	}
	return (1);
}

int			ft_bot_is_median_value(t_st *lst)
{
	unsigned int	i;

	i = 0;
	while (i < 2)
	{
		if (!(ft_swap_and_write(lst, 0)))
			return (0);
		if (!(ft_rotate_and_write(lst, 0)))
			return (0);
		i++;
	}
	if (!(ft_rotate_and_write(lst, 0)))
		return (0);
	return (1);
}

static int	ft_a_sup_b(t_st *lst)
{
	unsigned int	i;

	i = 0;
	if (!(ft_push_stack_and_write(lst, -1)))
		return (0);
	while (i < 2)
	{
		if (!(ft_rotate_and_write(lst, 0)))
			return (0);
		i++;
	}
	return (1);
}

int			ft_other_cases_full(t_st *lst)
{
	if (!(ft_push_stack_and_write(lst, 0)))
		return (0);
	if (!(ft_swap_and_write(lst, 0)))
		return (0);
	if (!(ft_rotate_and_write(lst, 0)))
		return (0);
	if (lst->st_a->nb > lst->st_b->nb)
	{
		if (!(ft_a_sup_b(lst)))
			return (0);
	}
	else
	{
		if (!(ft_rotate_and_write(lst, 0)))
			return (0);
		if (!(ft_push_stack_and_write(lst, -1)))
			return (0);
		if (!(ft_rotate_and_write(lst, 0)))
			return (0);
	}
	return (1);
}
