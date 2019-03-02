#include "../includes/push_swap.h"

static int	ft_main_stack_a(t_st *lst)
{
    int i;

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

static int	ft_main_stack_b(t_st *lst)
{
    int i;

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
    }
    return (1);
}

int			ft_sort_size_one(t_st *lst, int state)
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
