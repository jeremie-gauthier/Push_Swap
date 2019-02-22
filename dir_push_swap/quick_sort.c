#include "../includes/push_swap.h"

// static void	ft_push_back_to_origin(t_stack **stack, t_stack **opposite_stack,
// 					unsigned int size, t_stack **instruct_set, int state)
// {
// 	unsigned int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		ft_push_stack(opposite_stack, stack);
// 		if (state == 0)
// 			ft_stack_push_back(instruct_set, ft_stack_new(9)); // sortir le new de la
// 		else
// 			ft_stack_push_back(instruct_set, ft_stack_new(10));
// 		i++;
// 	}
// }

static void	ft_stack_sort(t_stack **stack, unsigned int size, int state, t_stack **instruct_set)
{
	int	top;
	int	mid;
	int	bot;

	ft_printf("{blue}-----BEGIN SORT-----\nstate = %i\nsize = %i\n", state, size);
	ft_stack_print(*stack);
	ft_printf("{reset}");
	// if (size == 1)
	// {
	// 	if ((*stack)->nb > (*stack)->next->nb)
	// 	{
	// 		ft_stack_rotate(stack);
	// 		ft_stack_push_back(instruct_set, ft_stack_new(3));
	// 	}
	// }
	if (size == 2)
	{
		// ft_printf("STACK AVANT SORT\n");
		// ft_stack_print(*stack);
		if (state == 0)
		{
			if ((*stack)->nb > (*stack)->next->nb)
			{
				ft_stack_swap_top(stack);
				ft_stack_push_back(instruct_set, ft_stack_new(0));
			}
		}
		else if (state == -1)
		{
			if ((*stack)->nb < (*stack)->next->nb)
			{
				ft_stack_swap_top(stack);
				ft_stack_push_back(instruct_set, ft_stack_new(1));
			}
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
			ft_printf("ICI\n");
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
					ft_stack_swap_top(stack);
				}
				if ((*stack)->nb < (*stack)->next->nb)
				{
					ft_stack_push_back(instruct_set, ft_stack_new(3));
					have_rotate = 1;
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
	ft_printf("{cyan}-----SORT DONE-----\nstate = %i\nsize = %i\n", state, size);
	ft_stack_print(*stack);
	ft_printf("{reset}");
}

// static void	ft_stack_split(unsigned int size, t_stack **stack,
// 					t_stack **opposite_stack, int state, t_stack **instruct_set, int debug)
// {
// 		int				median;
// 		unsigned int	reste;
// 		unsigned int	i;
// 		int	new_size;

// 		// int		tmp;
// 	ft_printf("----------\nRECURSION = %i\n\nSplit\nSize = %u\n\nSTATE of STACKS at entry\n", debug, size);
// 	if (state == 0)
// 		ft_putendl("STACK_A");
// 	else
// 		ft_putendl("STACK_B");
// 	ft_stack_print(*stack);
// 	if (state == 0)
// 		ft_putendl("STACK_B");
// 	else
// 		ft_putendl("STACK_A");
// 	ft_stack_print(*opposite_stack);
// 		new_size = 0;
// 		median = 0;
// 		if (size > 3)
// 		{
// 			median = (size / 2) + ((size % 2 == 1) ? 1 : 0); // pas une mediane, revoir. Il s'agit seulement de la moitie.
// 			reste = size - median;
// 	ft_printf("\nNEW_SIZE = %i\nRESTE = %i\nMEDIAN = %i\nSTATE of STACKS when split\n", new_size, reste, median, debug, size);
// 			i = 0;
// 			while (new_size < median) // NON : Trouver les 'median' min ou max values
// 			{
// 				if (state == 0 && (*stack)->nb <= median)
// 				{
// 					// tmp = ft_stack_find(*stack, ft_stack_min(*stack));
// 					// while (tmp)
// 					// {
// 					// 	ft_stack_rotate(stack);
// 					// 	tmp--;
// 					// }
// 					// ft_push_stack(stack, opposite_stack);
// 					// new_size++;
// 					ft_push_stack(stack, opposite_stack);
// 					ft_stack_push_back(instruct_set, ft_stack_new(10));
// 					new_size++;
// 				}
// 				else if (state == -1 && (*stack)->nb >= median) // > ou >= ??
// 				{
// 					// tmp = ft_stack_find(*stack, ft_stack_max(*stack));
// 					// while (tmp)
// 					// {
// 					// 	ft_stack_rotate(stack);
// 					// 	tmp--;
// 					// }
// 					// ft_push_stack(stack, opposite_stack);
// 					// new_size++;
// 					ft_push_stack(stack, opposite_stack);
// 					ft_stack_push_back(instruct_set, ft_stack_new(9));
// 					new_size++;
// 				}
// 				else
// 				{
// 					ft_stack_rotate(stack);
// 					ft_stack_push_back(instruct_set, ft_stack_new((state == 0) ? 3 : 4));
// 				}
// 				i++;
// 			}
// 	ft_printf("\nRESTE = %i\nMEDIAN = %i\n\nSTATE of STACKS after split\n", reste, median, debug, size);
// 	if (state == 0)
// 		ft_putendl("STACK_A");
// 	else
// 		ft_putendl("STACK_B");
// 	ft_stack_print(*stack);
// 	if (state == 0)
// 		ft_putendl("STACK_B");
// 	else
// 		ft_putendl("STACK_A");
// 	ft_stack_print(*opposite_stack);

// 			ft_stack_split(new_size, opposite_stack, stack, ~state, instruct_set, debug + 1);
// 	ft_printf("\nRETOUR RECURSION = %i\n", debug);
// 			if (reste > 3)
// 			{
// 				ft_stack_split(new_size, stack, opposite_stack, state, instruct_set, debug + 1);
// 				ft_printf("\nRETOUR RECURSION = %i\n", debug);
// 			}
// 		}
// 		if (new_size == 0)
// 			new_size = size;
// 	ft_printf("Split\nSize = %u\nNew_size = %u\n", size, new_size);
// 	ft_printf("\n\nSTATE of STACKS before sort\n", debug, size);
// 	if (state == 0)
// 		ft_putendl("STACK_A");
// 	else
// 		ft_putendl("STACK_B");
// 	ft_stack_print(*stack);
// 	if (state == 0)
// 		ft_putendl("STACK_B");
// 	else
// 		ft_putendl("STACK_A");
// 	ft_stack_print(*opposite_stack);

// 		ft_stack_sort(stack, size - median, state, instruct_set);

// 	ft_printf("\n\nSTATE of STACKS after sort\n", debug, size);
// 	if (state == 0)
// 		ft_putendl("STACK_A");
// 	else
// 		ft_putendl("STACK_B");
// 	ft_stack_print(*stack);
// 	if (state == 0)
// 		ft_putendl("STACK_B");
// 	else
// 		ft_putendl("STACK_A");
// 	ft_stack_print(*opposite_stack);

// 		if (size > 3)
// 			ft_push_back_to_origin(stack, opposite_stack, new_size, instruct_set, state);
// }

static void	ft_back_to_stack_a(t_stack **stack_a, t_stack **stack_b, unsigned int size, t_stack **instr_set)
{
	unsigned int	i;

	i = 0;
	while (i < size && *stack_b)
	{
		ft_printf("Push back to A\n");
		ft_push_stack(stack_b, stack_a);
		ft_stack_push_back(instr_set, ft_stack_new(9));
		i++;
	}
	while (i)
	{
		ft_stack_rotate(stack_a);
		ft_stack_push_back(instr_set, ft_stack_new(3));
		i--;
	}
}

static void	ft_st_split2(t_stack **st, t_stack **opp_st, t_stack **instr_set, unsigned int size, int state)
{
	int				pivot;
	unsigned int	rotations;
	unsigned int	pushs;

	while (size > 3)
	{
		pivot = (*st)->nb;
		rotations = 0;
		pushs = 0;
		ft_push_stack(st, opp_st);
		ft_stack_push_back(instr_set, ft_stack_new((state == 0) ? 10 : 9));
		size--;
		pushs++;
		while (ft_stack_cmp(*st, pivot, ft_nb_is_lower))
		{
			if ((*st)->nb < pivot)
			{
				ft_push_stack(st, opp_st);
				ft_stack_push_back(instr_set, ft_stack_new((state == 0) ? 10 : 9));
				size--;
				pushs++;
			}
			else
			{
				ft_stack_rotate(st);
				ft_stack_push_back(instr_set, ft_stack_new((state == 0) ? 3 : 4));
				rotations++;
			}
		}
		while (rotations)
		{
			ft_stack_rev_rotate(st);
			ft_stack_push_back(instr_set, ft_stack_new((state == 0) ? 6 : 7));
			rotations--;
		}
		ft_putendl("STATE STACK A");
		ft_stack_print((state == 0) ? *st : *opp_st);
		ft_putendl("STATE STACK B");
		ft_stack_print((state == 0) ? *opp_st : *st);
		ft_st_split2(opp_st, st, instr_set, pushs, ~state);
	}
	ft_printf("{yellow}DEEPER SORT SEQUENCE{reset}\n");
	ft_stack_sort(st, size, state, instr_set);
	if (state == 0)
		ft_back_to_stack_a(st, opp_st, size, instr_set);
	else
		ft_back_to_stack_a(opp_st, st, size, instr_set);
	while (size)
	{
		ft_stack_rotate(st);
		ft_stack_push_back(instr_set, ft_stack_new(3));
		size--;
	}
	ft_putendl("STATE STACK A");
	ft_stack_print((state == 0) ? *st : *opp_st);
	ft_putendl("STATE STACK B");
	ft_stack_print((state == 0) ? *opp_st : *st);
}

// static void	ft_st_split(t_stack **st, t_stack **opp_st, t_stack **instr_set, t_data *datas, int state)
// {
// 	int				pivot;
// 	unsigned int	rotations;
// 	unsigned int	pushs;
// 	unsigned int	reste;

// 	datas->depth++;
// 	// state = ~state;
// 	ft_printf("\n\n-----NEW RECURSION-----\nDATAS:\n{green}size = %u\n{green}state = %i\ndepth = %i{reset}\n\n", datas->size, state, datas->depth);
// 	reste = 0;
// 	if (datas->size > 3)
// 	{
// 		pivot = (*st)->nb;
// 		rotations = 0;
// 		pushs = 0;
// 		ft_push_stack(st, opp_st);
// 		ft_stack_push_back(instr_set, ft_stack_new((state == 0) ? 10 : 9));
// 		datas->size--;
// 		pushs++;
// 		while (ft_stack_cmp(*st, pivot, ft_nb_is_lower))
// 		{
// 			if ((*st)->nb < pivot)
// 			{
// 				ft_push_stack(st, opp_st);
// 				ft_stack_push_back(instr_set, ft_stack_new((state == 0) ? 10 : 9));
// 				datas->size--;
// 				pushs++;
// 			}
// 			else
// 			{
// 				ft_stack_rotate(st);
// 				ft_stack_push_back(instr_set, ft_stack_new((state == 0) ? 3 : 4));
// 				rotations++;
// 			}
// 		}
// 		while (rotations)
// 		{
// 			ft_stack_rev_rotate(st);
// 			ft_stack_push_back(instr_set, ft_stack_new((state == 0) ? 6 : 7));
// 			rotations--;
// 		}
// 		ft_putendl("STATE STACK A");
// 		ft_stack_print((state == 0) ? *st : *opp_st);
// 		ft_putendl("STATE STACK B");
// 		ft_stack_print((state == 0) ? *opp_st : *st);
// 		reste = datas->size;
// 		// while (reste > 3)
// 		datas->reste = datas->size;
// 		datas->size = pushs;
// 		ft_st_split(opp_st, st, instr_set, datas, ~state); // mettre dans un while "(ft_stack_cmp(*st, pivot, ft_nb_is_lower))"
// 	ft_printf("\n\n-----RETURN TO A LOWER RECURSION-----\nDATAS:\n{green}size = %u\n{green}state = %i\ndepth = %i{reset}\n\n", datas->size, state, datas->depth);
// 		datas->depth--;
// 		if (reste > 3)
// 		{
// 			ft_st_split(st, opp_st, instr_set, datas, state);
// 			datas->depth--;
// 		}
// 	}
// 	if (datas->size <= 3 && reste == 0)
// 	{
// 		ft_printf("{yellow}DEEPER SORT SEQUENCE{reset}\n");
// 		ft_stack_sort(st, datas->size, state, instr_set); // prevoir le push back to origin.
// 		// peut etre faire une nouvelle variable au lieu de decrementer size --> voir stack_split
// 		if (state == 0)
// 			ft_back_to_stack_a(st, opp_st, datas->size, instr_set);
// 		else
// 			ft_back_to_stack_a(opp_st, st, datas->size, instr_set);
// 		ft_putendl("STATE STACK A");
// 		ft_stack_print((state == 0) ? *st : *opp_st);
// 		ft_putendl("STATE STACK B");
// 		ft_stack_print((state == 0) ? *opp_st : *st);
// 	}
// 	else if (reste <= 3)
// 	{
// 		ft_printf("{yellow}HIGHER SORT SEQUENCE{reset}\n{green}reste = %u{reset}\n\n", reste);
// 		ft_stack_sort(st, reste, state, instr_set); // prevoir le push back to origin.
// 		// peut etre faire une nouvelle variable au lieu de decrementer size --> voir stack_split
// 		if (reste > 1)
// 		{
// 			if (state == 0)
// 				ft_back_to_stack_a(st, opp_st, reste, instr_set);
// 			else
// 				ft_back_to_stack_a(opp_st, st, reste, instr_set);
// 		}
// 		while (reste)
// 		{
// 			ft_stack_rotate(st);
// 			ft_stack_push_back(instr_set, ft_stack_new(3));
// 			reste--;
// 		}
// 		ft_putendl("STATE STACK A");
// 		ft_stack_print((state == 0) ? *st : *opp_st);
// 		ft_putendl("STATE STACK B");
// 		ft_stack_print((state == 0) ? *opp_st : *st);
// 	}
// }

t_stack		*ft_quick_sort(t_stack **stack_a, unsigned int size)
{
	t_stack	*instruct_set;
	t_stack	*stack_b;
	t_data	*datas;

	if (!(datas = init_data(size)))
		return (NULL);
	instruct_set = NULL;
	stack_b = NULL;
	// ft_stack_split(size, stack_a, &stack_b, 0, &instruct_set, 0);
	// ft_st_split(stack_a, &stack_b, &instruct_set, datas, 0);
	ft_st_split2(stack_a, &stack_b, &instruct_set, size, 0);
	ft_putendl("\n\nFINAL RESULT");
	ft_stack_print(*stack_a);
	return (instruct_set);
}