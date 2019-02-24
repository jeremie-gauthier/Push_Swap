#include "../includes/push_swap.h"

static void		ft_depush_stack_b(t_st *lst)
{
	while (lst->st_b)
	{
		ft_push_stack(&lst->st_b, &lst->st_a);
		ft_stack_push_back(&lst->st_instruct, ft_stack_new(9));
	}
}

static void		ft_sort_stack_a(t_st *lst, unsigned int size)
{
	int		min;
	int		max;

	min = ft_stack_min(lst->st_a);
	max = ft_stack_max(lst->st_a);
	while (ft_stack_is_sort(lst->st_a, ft_stack_size(lst->st_a)) == 0)
	{
// ft_printf("STATE STACK A\n");
// ft_stack_print(*stack_a);
		//Si queue > head
		if (ft_stack_at(lst->st_a, size) > lst->st_a->nb) //&& (*stack_a)->nb != min)
		{
			ft_stack_rev_rotate(&lst->st_a);
			ft_stack_push_back(&lst->st_instruct, ft_stack_new(6));
			ft_stack_swap_top(&lst->st_a);
			ft_stack_push_back(&lst->st_instruct, ft_stack_new(0));
		}
		//Si head > head->next
		else if (lst->st_a->nb > lst->st_a->next->nb)
		{
			ft_stack_swap_top(&lst->st_a);
			ft_stack_push_back(&lst->st_instruct, ft_stack_new(0));
		}
		else
		{
			ft_stack_rotate(&lst->st_a);
			ft_stack_push_back(&lst->st_instruct, ft_stack_new(3));
		}
		if (ft_stack_at(lst->st_a, size) == min && ft_stack_at(lst->st_a, size - 1) == max)
		{
			ft_stack_rev_rotate(&lst->st_a);
			ft_stack_push_back(&lst->st_instruct, ft_stack_new(6));
		}
		else if (lst->st_a->nb == max && (ft_stack_find(lst->st_a, min) - ft_stack_find(lst->st_a, max) == 1))
		{
			ft_stack_rotate(&lst->st_a);
			ft_stack_push_back(&lst->st_instruct, ft_stack_new(3));
		}
	}
}

int		ft_dumb_sort(t_st *lst, unsigned int size)
{
	unsigned int	midddle_stack;
	unsigned int	size_bis;
	int				min;
	unsigned int	pos;

	// Cette partie coupe la stack_a en 2 et cree une stack_b deja triee.
	midddle_stack = size / 2;
	while (midddle_stack > 0)
	{
		size_bis = ft_stack_size(lst->st_a);
		min = ft_stack_min(lst->st_a);
		pos = ft_stack_find(lst->st_a, min);
// ft_printf("middle_stack = %u\nsize_bis = %u\nsize_bis / 2 = %u\nmin = %i\npos @ = %u\n\n",
// 				midddle_stack, size_bis, size_bis / 2, min, pos);
// ft_printf("STACK A\n");
// ft_stack_print(*stack_a);
// ft_printf("STACK B\n");
// ft_stack_print(stack_b);
		if (pos <= ((size_bis / 2) + 1))
		{
			while (pos > 2)
			{
				// ft_putendl("rotate");
				ft_stack_rotate(&lst->st_a);
				ft_stack_push_back(&lst->st_instruct, ft_stack_new(3));
				pos--;
			}
			if (ft_stack_find(lst->st_a, min) != 1)
			{	
				// ft_putendl("swap");
				ft_stack_swap_top(&lst->st_a);
				ft_stack_push_back(&lst->st_instruct, ft_stack_new(0));
			}
		}
		else
		{
			while (pos <= size_bis)
			{
				// ft_putendl("rev_rotate");
				ft_stack_rev_rotate(&lst->st_a);
				ft_stack_push_back(&lst->st_instruct, ft_stack_new(6));
				pos++;
			}
		}
		midddle_stack--;
		ft_push_stack(&lst->st_a, &lst->st_b);
		ft_stack_push_back(&lst->st_instruct, ft_stack_new(10));
	}
	// ft_printf("FINAL STATE STACK A\n");
	// ft_stack_print(*stack_a);
	// ft_printf("FINAL STATE STACK B\n");
	// ft_stack_print(stack_b);

	// ft_printf("START SORT STACK_A PROCEDURE\n");
	ft_sort_stack_a(lst, ft_stack_size(lst->st_a));


	// ft_printf("FINAL STATE STACK A\n");
	// ft_stack_print(*stack_a);
	// ft_printf("FINAL STATE STACK B\n");
	// ft_stack_print(stack_b);

	ft_depush_stack_b(lst);
	// if (stack_b)
	// ft_printf("FINAL STATE STACK A\n");
	// ft_stack_print(*stack_a);
	// ft_printf("FINAL STATE STACK B\n");
	// ft_stack_print(stack_b);
	// 	ft_stack_del(&stack_b);
	return (1);
}