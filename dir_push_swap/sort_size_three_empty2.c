/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size_three_empty2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:40:42 by jergauth          #+#    #+#             */
/*   Updated: 2019/03/03 14:40:44 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_mid_comparison_with_opp_st(t_st *lst, unsigned int *size)
{
	if (!(ft_push_stack_and_write(lst, -1)))
		return (0);
	if (!(ft_rotate_and_write(lst, 0)))
		return (0);
	(*size)--;
	return (1);
}

static int	ft_push_top_elem(t_st *lst)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (!(ft_push_stack_and_write(lst, -1)))
			return (0);
		i++;
	}
	return (1);
}

int			ft_mid_is_min(t_st *lst, unsigned int *size)
{
	if (!(ft_push_top_elem(lst)))
		return (0);
	if (!(ft_rotate_and_write(lst, 0)))
		return (0);
	(*size)--;
	if (lst->st_b->nb < lst->st_a->nb)
	{
		if (!(ft_mid_comparison_with_opp_st(lst, size)))
			return (0);
	}
	else
	{
		if (!(ft_rotate_and_write(lst, 0)))
			return (0);
		(*size)--;
		if (!(ft_push_stack_and_write(lst, -1)))
			return (0);
	}
	if (!(ft_rotate_and_write(lst, 0)))
		return (0);
	(*size)--;
	return (1);
}

int			ft_other_cases(t_st *lst, unsigned int *size)
{
	unsigned int	i;

	i = 0;
	while (i < 3)
	{
		if (!(ft_push_stack_and_write(lst, -1)))
			return (0);
		i++;
	}
	if (!(ft_rotate_and_write(lst, 0)))
		return (0);
	(*size)--;
	if (lst->st_a->nb > lst->st_a->next->nb)
	{
		if (!(ft_swap_and_write(lst, 0)))
			return (0);
	}
	while (i < 5)
	{
		if (!(ft_rotate_and_write(lst, 0)))
			return (0);
		(*size)--;
		i++;
	}
	return (1);
}

int			ft_top_is_min(t_st *lst, unsigned int *size)
{
	if (!(ft_push_stack_and_write(lst, -1)))
		return (0);
	if (!(ft_rotate_and_write(lst, 0)))
		return (0);
	(*size)--;
	return (1);
}
