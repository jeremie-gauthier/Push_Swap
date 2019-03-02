#include "../includes/push_swap.h"

int     ft_sort_size_one(t_st *lst, int state)
{
	int		i;

    i = 0;
    if (state == -1)
    {
        if (change_last_instruction(lst->st_instruct, 10, 3) == 1)
        {
            ft_push_stack(&lst->st_b, &lst->st_a);
            ft_stack_rotate(&lst->st_a);
        }
        else
        {
            if (!(ft_push_stack_and_write(lst, -1)))
                return (0);
            if (!(ft_rotate_and_write(lst, 0)))
                return (0);
        }
    }
    else
    {
        if (!(ft_rotate_and_write(lst, 0)))
            return (0);
    }
    return (1);
}
