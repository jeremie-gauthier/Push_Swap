#include "../includes/push_swap.h"

int		ft_visualizer(t_stack **a, t_stack *set, t_stack **b,
			void (*f[3])(t_stack**))
{
	unsigned int	size_a;
	unsigned int	size_b;
	unsigned int	diff;

	size_a = ft_stack_size(*a);
	size_b = ft_stack_size(*b);
	diff = ft_abs(size_a - size_b);
	while (set)
	{
		ft_printf("****************************************\n")
		while (diff > 0)
		{

		}
		set = set->next;
	}
}
