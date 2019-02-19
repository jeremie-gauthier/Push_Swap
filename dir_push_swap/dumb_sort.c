#include "../includes/push_swap.h"

static void		ft_depush_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
		ft_push_stack(stack_b, stack_a);
}

static void		ft_sort_stack_a(t_stack **stack_a, unsigned int size)
{
	int		min;
	int		max;

	min = ft_stack_min(*stack_a);
	max = ft_stack_max(*stack_a);
	while (ft_stack_is_sort(*stack_a, ft_stack_size(*stack_a)) == 0)
	{
ft_printf("STATE STACK A\n");
ft_stack_print(*stack_a);
		//Si queue > head
		if (ft_stack_at(*stack_a, size) > (*stack_a)->nb) //&& (*stack_a)->nb != min)
		{
			ft_stack_rev_rotate(stack_a);
			ft_stack_swap_top(stack_a);
		}
		//Si head > head->next
		else if ((*stack_a)->nb > (*stack_a)->next->nb)
			ft_stack_swap_top(stack_a);
		else
			ft_stack_rotate(stack_a);
		if (ft_stack_at(*stack_a, size) == min && ft_stack_at(*stack_a, size - 1) == max)
			ft_stack_rev_rotate(stack_a);
		else if ((*stack_a)->nb == max && (ft_stack_find(*stack_a, min) - ft_stack_find(*stack_a, max) == 1))
			ft_stack_rotate(stack_a);
	}
}

t_stack		*ft_dumb_sort(t_stack **stack_a, unsigned int size)
{
	t_stack			*stack_b = NULL;
	t_stack			*instruct_set = NULL;
	unsigned int	midddle_stack;
	unsigned int	size_bis;
	int				min;
	unsigned int	pos;

	if (*stack_a == NULL)
		return (NULL);
	// Cette partie coupe la stack_a en 2 et cree une stack_b deja triee.
	midddle_stack = size / 2;
	while (midddle_stack > 0)
	{
		size_bis = ft_stack_size(*stack_a);
		min = ft_stack_min(*stack_a);
		pos = ft_stack_find(*stack_a, min);
ft_printf("middle_stack = %u\nsize_bis = %u\nsize_bis / 2 = %u\nmin = %i\npos @ = %u\n\n",
				midddle_stack, size_bis, size_bis / 2, min, pos);
ft_printf("STACK A\n");
ft_stack_print(*stack_a);
ft_printf("STACK B\n");
ft_stack_print(stack_b);
		if (pos <= ((size_bis / 2) + 1))
		{
			while (pos > 2)
			{
				ft_putendl("rotate");
				ft_stack_rotate(stack_a);
				pos--;
			}
			if (ft_stack_find(*stack_a, min) != 1)
			{	
				ft_putendl("swap");
				ft_stack_swap_top(stack_a);
			}
		}
		else
		{
			while (pos <= size_bis)
			{
				ft_putendl("rev_rotate");
				ft_stack_rev_rotate(stack_a);
				pos++;
			}
		}
		midddle_stack--;
		ft_push_stack(stack_a, &stack_b);
	}
	ft_printf("FINAL STATE STACK A\n");
	ft_stack_print(*stack_a);
	ft_printf("FINAL STATE STACK B\n");
	ft_stack_print(stack_b);

	ft_printf("START SORT STACK_A PROCEDURE\n");
	ft_sort_stack_a(stack_a, ft_stack_size(*stack_a));


	ft_printf("FINAL STATE STACK A\n");
	ft_stack_print(*stack_a);
	ft_printf("FINAL STATE STACK B\n");
	ft_stack_print(stack_b);

	ft_depush_stack_b(stack_a, &stack_b);
	// if (stack_b)
	ft_printf("FINAL STATE STACK A\n");
	ft_stack_print(*stack_a);
	ft_printf("FINAL STATE STACK B\n");
	ft_stack_print(stack_b);
	// 	ft_stack_del(&stack_b);
	instruct_set = NULL; //
	return (instruct_set);
}