#include "../includes/push_swap.h"

static int	ft_current_is_max(t_st *lst, unsigned int size, const int min)
{
	if (ft_stack_at(lst->st_a, size - 1) == min)
	{
		if (!(ft_rev_rotate_and_write(lst, 0)))
			return (0);
		if (!(ft_swap_and_write(lst, 0)))
			return (0);
	}
	if (!(ft_rotate_and_write(lst, 0)))
		return (0);
	return (1);
}

static int	ft_stack_is_nsorted(t_st *lst, const int max)
{
	if (lst->st_a->nb > lst->st_a->next->nb)
	{
		if (!(ft_swap_and_write(lst, 0)))
			return (0);
	}
	else if (lst->st_a->next->nb > lst->st_a->next->next->nb && lst->st_a->next->nb != max)
	{
		if (!(ft_rotate_and_write(lst, 0)))
			return (0);
	}
	else
	{
		if (!(ft_rev_rotate_and_write(lst, 0)))
			return (0);
	}
	return (1);
}

int     	ft_insertion_sort(t_st *lst, unsigned int size)
{
    int     min;
    int     max;

    min = ft_stack_nmin(lst->st_a, size);
    max = ft_stack_nmax(lst->st_a, size);
    while (ft_stack_is_nsort(lst->st_a, size, 0) == 0)
    {
        if (lst->st_a->nb == max)
			if (!(ft_current_is_max(lst, size, min)))
				return (0);
        if (lst->st_a->nb == min && ft_stack_is_nsort(lst->st_a, size, 0) == 0)
        {
			if (!(ft_push_stack_and_write(lst, 0)))
				return (0);
            size--;
        }
        if (ft_stack_is_nsort(lst->st_a, size, 0) == 0)
			if (!(ft_stack_is_nsorted(lst, max)))
				return (0);
    }
    if (lst->st_b && lst->st_b->nb == min)
		if (!(ft_push_stack_and_write(lst, 1)))
			return (0);
    return (1);
}
