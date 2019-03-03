/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:23:23 by jergauth          #+#    #+#             */
/*   Updated: 2019/03/03 13:23:24 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_main_stack_a(t_st *lst)
{
	unsigned int i;

	i = 0;
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

static int	ft_main_stack_b_else_case(t_st *lst)
{
	unsigned int	i;

	i = 0;
	while (i < 2)
	{
		if (!(ft_push_stack_and_write(lst, -1)))
			return (0);
		i++;
	}
	while (i < 4)
	{
		if (!(ft_rotate_and_write(lst, 0)))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_main_stack_b(t_st *lst)
{
	unsigned int i;

	i = 0;
	if (lst->st_b->nb < lst->st_b->next->nb)
	{
		while (i < 2)
		{
			if (!(ft_push_stack_and_write(lst, -1)))
				return (0);
			if (!(ft_rotate_and_write(lst, 0)))
				return (0);
			i++;
		}
	}
	else
	{
		if (!(ft_main_stack_b_else_case(lst)))
			return (0);
	}
	return (1);
}

int			ft_sort_size_two(t_st *lst, int state)
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
