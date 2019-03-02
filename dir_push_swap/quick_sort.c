#include "../includes/push_swap.h"

static int	ft_rev_rotate(t_st *lst, unsigned int rotations, int state)
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

static int	ft_split_stack(t_st *lst, unsigned int *size, int pivot, int state)
{
	unsigned int	rotations;
	unsigned int	pushs;

	rotations = 0;
	pushs = 1;
	while (ft_stack_ncmp((state == 0) ? lst->st_a : lst->st_b, pivot, ft_nb_is_lower, *size))
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
			rotations++;
			(*size)--;
		}
	}
	*size += rotations;
	if (!(ft_rev_rotate(lst, rotations, state)))
		return (0);
	if (!(ft_quick_sort(lst, pushs, ~state)))
		return (0);
	return (1);
}

int		ft_quick_sort(t_st *lst, unsigned int size, int state)
{
	int				pivot;

	while (size > 3)
	{
		pivot = ((state == 0) ? lst->st_a : lst->st_b)->nb;
		if (!(ft_push_stack_and_write(lst, state)))
			return (0);
		size--;
		if (!(ft_split_stack(lst, &size, pivot, state)))
			return (0);
	}
	ft_sort_deepest_stack(lst, size, state);
	return (1);
}