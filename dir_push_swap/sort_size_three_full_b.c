/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size_three_full_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:14:20 by jergauth          #+#    #+#             */
/*   Updated: 2019/03/03 15:14:21 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	first_steps(t_st *lst)
{
	unsigned int	i;

	i = 0;
	while (i < 2)
	{
		if (!(ft_push_stack_and_write(lst, -1)))
			return (0);
		i++;
	}
	return (1);
}

int			ft_mid_is_max_full_b(t_st *lst, unsigned int *size)
{
	if (!(first_steps(lst)))
		return (0);
	if (!(ft_rotate_and_write(lst, 0)))
		return (0);
	(*size)--;
	if (lst->st_b->nb < lst->st_a->nb)
	{
		if (!(ft_push_stack_and_write(lst, -1)))
			return (0);
		if (!(ft_rotate_and_write(lst, 0)))
			return (0);
		(*size)--;
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

int			ft_other_cases_full_b(t_st *lst, unsigned int *size)
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
