/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:22:46 by jergauth          #+#    #+#             */
/*   Updated: 2019/03/03 13:22:47 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_rev_rotate(t_st *lst, unsigned int rotations, const int state)
{
	if (lst->sorted == 0)
		lst->sorted = 1;
	else
	{
		while (rotations)
		{
			if (!(ft_rev_rotate_and_write(lst, state)))
				return (0);
			rotations--;
		}
	}
	return (1);
}

static int	ft_split_again(t_st *lst, unsigned int rotations,
					unsigned int pushs, int state)
{
	if (!(ft_rev_rotate(lst, rotations, state)))
		return (0);
	if (!(ft_quick_sort(lst, pushs, ~state)))
		return (0);
	return (1);
}

static int	ft_split_stack(t_st *lst, unsigned int *size,
					const int pivot, int state)
{
	unsigned int	rotations;
	unsigned int	pushs;

	rotations = 0;
	pushs = 1;
	while (ft_stack_ncmp((state == 0) ? lst->st_a : lst->st_b, pivot,
				ft_nb_is_lower, *size))
	{
		if (((state == 0) ? lst->st_a : lst->st_b)->nb < pivot)
		{
			if (!(ft_push_stack_and_write(lst, state)))
				return (0);
			(*size)--;
			pushs++;
		}
		else
		{
			if (!(ft_rotate_and_write(lst, state)))
				return (0);
			(*size)--;
			rotations++;
		}
	}
	*size += rotations;
	return (ft_split_again(lst, rotations, pushs, state));
}

static int	ft_pivot_top(t_st *lst, unsigned int *size, const int state)
{
	int	pivot;

	pivot = ((state == 0) ? lst->st_a : lst->st_b)->nb;
	if (!(ft_push_stack_and_write(lst, state)))
		return (-1);
	(*size)--;
	return (pivot);
}

int			ft_quick_sort(t_st *lst, unsigned int size, int state)
{
	int	pivot;

	while (size > 3)
	{
		pivot = ft_pivot_top(lst, &size, state);
		if (!(ft_split_stack(lst, &size, pivot, state)))
			return (0);
	}
	ft_sort_deepest_stack(lst, size, state);
	return (1);
}
