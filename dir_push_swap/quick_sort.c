#include "../includes/push_swap.h"

static void	ft_push_back_to_origin(t_stack **stack, t_stack **opposite_stack,
					unsigned int size, t_stack **instruct_set, int state)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		ft_push_stack(opposite_stack, stack);
		if (state == 0)
			ft_stack_push_back(instruct_set, ft_stack_new(9)); // sortir le new de la
		else
			ft_stack_push_back(instruct_set, ft_stack_new(10));
		i++;
	}
}

static void	ft_stack_sort(t_stack **stack, unsigned int size, int state, t_stack **instruct_set)
{
	int	top;
	int	mid;
	int	bot;

	ft_printf("-----BEGIN SORT-----\nstate = %i\nsize = %i\n", state, size);
	if (size == 2)
	{
		// ft_printf("STACK AVANT SORT\n");
		// ft_stack_print(*stack);
		if (state == 0)
		{
			if ((*stack)->nb > (*stack)->next->nb)
					ft_stack_swap_top(stack);
		}
		else if (state == -1)
		{
			if ((*stack)->nb < (*stack)->next->nb)
					ft_stack_swap_top(stack);
		}
		// ft_printf("STACK APRES SORT\n");
		// ft_stack_print(*stack);
		// ft_printf("-------\n");
	}
	else if (size == 3)
	{
		top = (*stack)->nb;
		mid = (*stack)->next->nb;
		bot = (*stack)->next->next->nb;
		ft_printf("var state = %i\n", state);
		if ((*stack)->next->next->next == NULL)
		{
			if (state == 0)
			{
				if ((*stack)->next->nb > (*stack)->nb && (*stack)->next->nb > (*stack)->next->next->nb)
				{
					ft_stack_push_back(instruct_set, ft_stack_new(6));
					ft_stack_rev_rotate(stack);
				}
				if ((*stack)->nb > (*stack)->next->nb && (*stack)->nb > (*stack)->next->next->nb)
				{
					ft_stack_push_back(instruct_set, ft_stack_new(3));
					ft_stack_rotate(stack);
				}
				if ((*stack)->nb > (*stack)->next->nb)
				{
					ft_stack_push_back(instruct_set, ft_stack_new(0));
					ft_stack_swap_top(stack);
				}
			}
			else
			{
				if (((*stack)->nb < (*stack)->next->nb && (*stack)->next->nb < (*stack)->next->next->nb) || (((*stack)->nb > (*stack)->next->next->nb) && ((*stack)->next->nb > (*stack)->nb || (*stack)->next->nb < (*stack)->next->next->nb)))
				{
					ft_stack_push_back(instruct_set, ft_stack_new(1));
					ft_stack_swap_top(stack);
				}
				if ((*stack)->nb < (*stack)->next->next->nb && (*stack)->next->next->nb < (*stack)->nb)
				{
					ft_stack_push_back(instruct_set, ft_stack_new(4));
					ft_stack_rotate(stack);
				}
				if ((*stack)->nb > (*stack)->next->nb && (*stack)->nb < (*stack)->next->next->nb)
				{
					ft_stack_push_back(instruct_set, ft_stack_new(7));
					ft_stack_rev_rotate(stack);
				}
			}
		}
		else
		{
			int	have_rotate = 0;
			if (state == 0)
			{
				if ((*stack)->next->nb > (*stack)->nb && (*stack)->next->nb > (*stack)->next->next->nb)
				{
					ft_stack_push_back(instruct_set, ft_stack_new(3));
					have_rotate = 1;
					ft_stack_rotate(stack);
				}
				if ((*stack)->next->nb < (*stack)->nb)
				{
					ft_stack_push_back(instruct_set, ft_stack_new(0));
					have_rotate = 1;
					ft_stack_swap_top(stack);
				}
				if ((*stack)->nb < (*stack)->next->nb)
				{
					ft_stack_push_back(instruct_set, ft_stack_new(3));
					ft_stack_rotate(stack);
				}
				if ((*stack)->nb > (*stack)->next->nb)
				{
					ft_stack_push_back(instruct_set, ft_stack_new(0));
					ft_stack_swap_top(stack);
				}
				if (have_rotate == 1)
				{
					ft_stack_push_back(instruct_set, ft_stack_new(6));
					ft_stack_rev_rotate(stack);
				}
				if ((*stack)->nb > (*stack)->next->nb)
				{
					ft_stack_push_back(instruct_set, ft_stack_new(0));
					ft_stack_swap_top(stack);
				}
			}
			else
			{
				if ((*stack)->next->nb > (*stack)->nb)
				{
					ft_stack_push_back(instruct_set, ft_stack_new(1));
					ft_stack_swap_top(stack);
				}
				if ((*stack)->next->nb < (*stack)->nb && (*stack)->next->nb < (*stack)->next->next->nb)
				{
					ft_stack_push_back(instruct_set, ft_stack_new(4));
					have_rotate = 1;
					ft_stack_rotate(stack);
				}
				if ((*stack)->nb < (*stack)->next->nb)
				{
					ft_stack_push_back(instruct_set, ft_stack_new(1));
					ft_stack_swap_top(stack);
				}
				if (have_rotate == 1)
				{
					ft_stack_push_back(instruct_set, ft_stack_new(7));
					ft_stack_rev_rotate(stack);
				}
				if ((*stack)->nb < (*stack)->next->nb)
				{
					ft_stack_push_back(instruct_set, ft_stack_new(1));
					ft_stack_swap_top(stack);
				}
			}
		}
	}
}

static void	ft_stack_split(unsigned int size, t_stack **stack,
					t_stack **opposite_stack, int state, t_stack **instruct_set, int debug)
{
	int				median;
	unsigned int	reste;
	unsigned int	i;
	int	new_size;

ft_printf("----------\nRECURSION = %i\n\nSplit\nSize = %u\n\nSTATE of STACKS at entry\n", debug, size);
if (state == 0)
	ft_putendl("STACK_A");
else
	ft_putendl("STACK_B");
ft_stack_print(*stack);
if (state == 0)
	ft_putendl("STACK_B");
else
	ft_putendl("STACK_A");
ft_stack_print(*opposite_stack);
	new_size = 0;
	median = 0;
	if (size > 3)
	{
		median = (size / 2) + ((size % 2 == 1) ? 1 : 0); // pas une mediane, revoir. Il s'agit seulement de la moitie.
		reste = size - median;
		i = 0;
		while (new_size < median) // NON : Trouver les 'median' min ou max values
		{
			if (state == 0 && (*stack)->nb <= median)
			{
				ft_push_stack(stack, opposite_stack);
				ft_stack_push_back(instruct_set, ft_stack_new(10));
				new_size++;
			}
			else if (state == -1 && (*stack)->nb >= median) // > ou >= ??
			{
				ft_push_stack(stack, opposite_stack);
				ft_stack_push_back(instruct_set, ft_stack_new(9));
				new_size++;
			}
			else
			{
				ft_stack_rotate(stack);
				ft_stack_push_back(instruct_set, ft_stack_new((state == 0) ? 3 : 4));
			}
			i++;
		}
ft_printf("\nRESTE = %i\nMEDIAN = %i\n\nSTATE of STACKS after split\n", reste, median, debug, size);
if (state == 0)
	ft_putendl("STACK_A");
else
	ft_putendl("STACK_B");
ft_stack_print(*stack);
if (state == 0)
	ft_putendl("STACK_B");
else
	ft_putendl("STACK_A");
ft_stack_print(*opposite_stack);

		ft_stack_split(new_size, opposite_stack, stack, ~state, instruct_set, debug + 1);
ft_printf("\nRETOUR RECURSION = %i\n", debug);
		if (reste > 3)
		{
			ft_stack_split(new_size, stack, opposite_stack, state, instruct_set, debug + 1);
			ft_printf("\nRETOUR RECURSION = %i\n", debug);
		}
	}
	if (new_size == 0)
		new_size = size;
ft_printf("Split\nSize = %u\nNew_size = %u\n", size, new_size);
ft_printf("\n\nSTATE of STACKS before sort\n", debug, size);
if (state == 0)
	ft_putendl("STACK_A");
else
	ft_putendl("STACK_B");
ft_stack_print(*stack);
if (state == 0)
	ft_putendl("STACK_B");
else
	ft_putendl("STACK_A");
ft_stack_print(*opposite_stack);

	ft_stack_sort(stack, size - median, state, instruct_set);

ft_printf("\n\nSTATE of STACKS after sort\n", debug, size);
if (state == 0)
	ft_putendl("STACK_A");
else
	ft_putendl("STACK_B");
ft_stack_print(*stack);
if (state == 0)
	ft_putendl("STACK_B");
else
	ft_putendl("STACK_A");
ft_stack_print(*opposite_stack);

	if (size > 3)
		ft_push_back_to_origin(stack, opposite_stack, new_size, instruct_set, state);
}

t_stack		*ft_quick_sort(t_stack **stack_a, unsigned int size)
{
	t_stack	*instruct_set;
	t_stack	*stack_b;

	instruct_set = NULL;
	stack_b = NULL;
	ft_stack_split(size, stack_a, &stack_b, 0, &instruct_set, 0);
	ft_putendl("\n\nFINAL RESULT");
	ft_stack_print(*stack_a);
	return (instruct_set);
}