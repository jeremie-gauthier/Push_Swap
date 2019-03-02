#include "../includes/push_swap.h"

static int	ft_main_stack_a(t_st *lst)
{
	if (lst->st_a->next->nb > lst->st_a->nb && lst->st_a->next->nb > lst->st_a->next->next->nb)
	{
		if (!(ft_rev_rotate_and_write(lst, 0)))
			return (0);
	}
	if (lst->st_a->nb > lst->st_a->next->nb && lst->st_a->nb > lst->st_a->next->next->nb)
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

static int	ft_mid_is_min(t_st *lst, unsigned int *size)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (!(ft_push_stack_and_write(lst, -1)))
			return (0);
		i++;
	}
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

static int	ft_other_cases(t_st *lst, unsigned int *size)
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

int         ft_sort_size_three_empty(t_st *lst, int state)
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
        while (size)
        {
            if (lst->st_b->nb == ft_stack_nmin(lst->st_b, size))
            {
                if (!(ft_push_stack_and_write(lst, -1)))
                    return (0);
                if (!(ft_rotate_and_write(lst, 0)))
                    return (0);
                size--;
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
    }
	return (1);
}
