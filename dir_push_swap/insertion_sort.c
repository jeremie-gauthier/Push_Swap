#include "../includes/push_swap.h"

int     ft_insertion_sort(t_st *lst, unsigned int size)
{
    int     min;
    int     max;
    t_stack *new;

    min = ft_stack_nmin(lst->st_a, size);
    max = ft_stack_nmax(lst->st_a, size);
    while (ft_stack_is_nsort(lst->st_a, size, 0) == 0)
    {
        if (lst->st_a->nb == max)
        {
            if (ft_stack_at(lst->st_a, size - 1) == min)
            {
                // ft_printf("%i\n", ft_stack_at(lst->st_a, size - 1));
                ft_stack_rev_rotate(&lst->st_a);
                if (!(new = ft_stack_new(6)))
                    return (0);
                ft_stack_push_back(&lst->st_instruct, new);
                ft_stack_swap_top(&lst->st_a);
                if (!(new = ft_stack_new(0)))
                  return (0);
                ft_stack_push_back(&lst->st_instruct, new);
            }
            ft_stack_rotate(&lst->st_a);
            // ft_printf("1 ra\n");
            if (!(new = ft_stack_new(3)))
                return (0);
            ft_stack_push_back(&lst->st_instruct, new);
            // ft_stack_print(lst->st_a);
        }
        if (lst->st_a->nb == min && ft_stack_is_nsort(lst->st_a, size, 0) == 0)
        {
            ft_push_stack(&lst->st_a, &lst->st_b);
            // ft_printf("2 pb\n");
            if (!(new = ft_stack_new(10)))
                return (0);
            ft_stack_push_back(&lst->st_instruct, new);
            size--;
        }
        if (ft_stack_is_nsort(lst->st_a, size, 0) == 0)
        {
            if (lst->st_a->nb > lst->st_a->next->nb)
            {
                ft_stack_swap_top(&lst->st_a);
                // ft_printf("3 sa\n");
                if (!(new = ft_stack_new(0)))
                    return (0);
                ft_stack_push_back(&lst->st_instruct, new);        
            }
            else if (lst->st_a->next->nb > lst->st_a->next->next->nb && lst->st_a->next->nb != max)
            {
                ft_stack_rotate(&lst->st_a);
                // ft_printf("4 ra\n");
                if (!(new = ft_stack_new(3)))
                    return (0);
                ft_stack_push_back(&lst->st_instruct, new);
        
            }
            else
            {
                ft_stack_rev_rotate(&lst->st_a);
                // ft_printf("5 rra\n");
                if (!(new = ft_stack_new(6)))
                    return (0);
                ft_stack_push_back(&lst->st_instruct, new);
            }
        }
    }
    if (lst->st_b && lst->st_b->nb == min)
    {
        ft_push_stack(&lst->st_b, &lst->st_a);
        // ft_printf("6 pa\n");
        if (!(new = ft_stack_new(9)))
            return (0);
        ft_stack_push_back(&lst->st_instruct, new);
    }
    return (1);
}
