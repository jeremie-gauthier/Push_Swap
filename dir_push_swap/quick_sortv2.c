#include "../includes/push_swap.h"

static void	ft_stack_print_fd(int fd, t_stack *current)
{
	if (current != NULL)
	{
		while (current)
		{
            ft_dprintf(fd, "%i\n", current->nb);
			current = current->next;
		}
	}
}

static int	ft_sort_substack(t_stack **st, t_stack **opp_st, unsigned int size, int state, t_stack **instr_set, int fd)
{
	t_stack	*new;
	int		i;
	int		elem_on_opp_st;

	if (DEBUG)
	{
		ft_dprintf(fd, "{yellow}-----SORT BEGIN-----\nsize = %u\nstate = %i{reset}\n\n", size, state);
		ft_dprintf(fd, "{magenta}STATE STACK A\n");
		ft_stack_print_fd(fd, (state == 0) ? *st : *opp_st);
		ft_dprintf(fd, "STATE STACK B\n");
		ft_stack_print_fd(fd, (state == 0) ? *opp_st : *st);
		ft_dprintf(fd, "{reset}");
	}
	if (ft_stack_is_sort(*st, 0) == 1 && (*opp_st) == NULL)
		return (1);
	elem_on_opp_st = 0;
	i = 0;
	if (size == 1)
	{
		if (state == -1)
		{
			ft_push_stack(st, opp_st);
			if (!(new = ft_stack_new(9)))
				return (0);
			ft_stack_push_back(instr_set, new);
			ft_stack_rotate(opp_st);
			if (!(new = ft_stack_new(3)))
				return (0);
			ft_stack_push_back(instr_set, new);
		}
		else
		{
			ft_stack_rotate(st);
			if (!(new = ft_stack_new(3)))
				return (0);
			ft_stack_push_back(instr_set, new);			
		}
	}
	else if (size == 2)
	{
		if (state == 0)
		{
			if ((*st)->nb > (*st)->next->nb)
			{
				ft_stack_swap_top(st);
				if (!(new = ft_stack_new(0)))
					return (0);
				ft_stack_push_back(instr_set, new);
			}
			while (i < 2)
			{
				ft_stack_rotate(st);
				if (!(new = ft_stack_new(3)))
					return (0);
				ft_stack_push_back(instr_set, new);
				i++;
			}
		}
		else
		{
			if ((*st)->nb < (*st)->next->nb)
			{
				while (i < 2)
				{
					ft_push_stack(st, opp_st);
					if (!(new = ft_stack_new(9)))
						return (0);
					ft_stack_push_back(instr_set, new);
					ft_stack_rotate(opp_st);
					if (!(new = ft_stack_new(3)))
						return (0);
					ft_stack_push_back(instr_set, new);
					i++;
				}
			}
			else
			{
				while (i < 2)
				{
					ft_push_stack(st, opp_st);
					if (!(new = ft_stack_new(9)))
						return (0);
					ft_stack_push_back(instr_set, new);
					i++;
				}
				i = 0;
				while (i < 2)
				{
					ft_stack_rotate(opp_st);
					if (!(new = ft_stack_new(3)))
						return (0);
					ft_stack_push_back(instr_set, new);
					i++;
				}
			}
		}
		
	}
	else if (size == 3)
	{
		if ((*st)->next->next->next == NULL)
		{
			if (state == 0)
			{
				if ((*st)->next->nb > (*st)->nb && (*st)->next->nb > (*st)->next->next->nb)
				{
					ft_stack_push_back(instr_set, ft_stack_new(6));
					ft_stack_rev_rotate(st);
				}
				if ((*st)->nb > (*st)->next->nb && (*st)->nb > (*st)->next->next->nb)
				{
					ft_stack_push_back(instr_set, ft_stack_new(3));
					ft_stack_rotate(st);
				}
				if ((*st)->nb > (*st)->next->nb)
				{
					ft_stack_push_back(instr_set, ft_stack_new(0));
					ft_stack_swap_top(st);
				}
			}
			else
			{
				while (size)
				{
					if ((*st)->nb == ft_stack_nmin(*st, size))
					{
						ft_push_stack(st, opp_st);
						if (!(new = ft_stack_new(9)))
							return (0);
						ft_stack_push_back(instr_set, new);
						ft_stack_rotate(opp_st);
						if (!(new = ft_stack_new(3)))
							return (0);
						ft_stack_push_back(instr_set, new);
						size--;
					}
					else if ((*st)->next->nb == ft_stack_nmin(*st, size))
					{
						while (i < 2)
						{
							ft_push_stack(st, opp_st);
							if (!(new = ft_stack_new(9)))
								return (0);
							ft_stack_push_back(instr_set, new);
							i++;
						}
						ft_stack_rotate(opp_st);
						if (!(new = ft_stack_new(3)))
							return (0);
						ft_stack_push_back(instr_set, new);
						size--;
						if ((*st)->nb < (*opp_st)->nb)
						{
							ft_push_stack(st, opp_st);
							if (!(new = ft_stack_new(9)))
								return (0);
							ft_stack_push_back(instr_set, new);
							ft_stack_rotate(opp_st);
							if (!(new = ft_stack_new(3)))
								return (0);
							ft_stack_push_back(instr_set, new);
							size--;
						}
						else
						{
							ft_stack_rotate(opp_st);
							if (!(new = ft_stack_new(3)))
								return (0);
							ft_stack_push_back(instr_set, new);
							size--;
							ft_push_stack(st, opp_st);
							if (!(new = ft_stack_new(9)))
								return (0);
							ft_stack_push_back(instr_set, new);
						}
						ft_stack_rotate(opp_st);
						if (!(new = ft_stack_new(3)))
								return (0);
						ft_stack_push_back(instr_set, new);
						size--;
					}
					else
					{
						while (i < 3)
						{
							ft_push_stack(st, opp_st);
							if (!(new = ft_stack_new(9)))
								return (0);
							ft_stack_push_back(instr_set, new);
							i++;
						}
						ft_stack_rotate(opp_st);
						if (!(new = ft_stack_new(3)))
							return (0);
						ft_stack_push_back(instr_set, new);
						size--;
						if ((*opp_st)->nb > (*opp_st)->next->nb)
						{
							ft_stack_swap_top(st);
							if (!(new = ft_stack_new(0)))
								return (0);
							ft_stack_push_back(instr_set, new);
						}
						i = 0;
						while (i < 2)
						{
							ft_stack_rotate(st);
							if (!(new = ft_stack_new(3)))
								return (0);
							ft_stack_push_back(instr_set, new);
							size--;
							i++;
						}
					}
				}
			}
		}
		else
		{
			if (state == 0)
			{
				// top > (mid && bot)
				if ((*st)->nb < (*st)->next->nb && (*st)->nb < (*st)->next->next->nb)
				{
					ft_stack_rotate(st);
					if (!(new = ft_stack_new(3)))
						return (0);
					ft_stack_push_back(instr_set, new);
					if ((*st)->nb > (*st)->next->nb)
					{
						ft_stack_swap_top(st);
						if (!(new = ft_stack_new(0)))
							return (0);
						ft_stack_push_back(instr_set, new);
					}
					while (i < 2)
					{
						ft_stack_rotate(st);
						if (!(new = ft_stack_new(3)))
							return (0);
						ft_stack_push_back(instr_set, new);
						i++;
					}
				}
				//top > mid && top < bot
				else if ((*st)->nb > (*st)->next->nb && (*st)->nb < (*st)->next->next->nb)
				{
					ft_stack_swap_top(st);
					if (!(new = ft_stack_new(0)))
						return (0);
					ft_stack_push_back(instr_set, new);
					while (i < 3)
					{
						ft_stack_rotate(st);
						if (!(new = ft_stack_new(3)))
							return (0);
						ft_stack_push_back(instr_set, new);
						i++;
					}
				}
				//bot > mid && bot < top
				else if ((*st)->next->next->nb > (*st)->next->nb && (*st)->next->next->nb < (*st)->nb)
				{
					while (i < 2)
					{
						ft_stack_swap_top(st);
						if (!(new = ft_stack_new(0)))
							return (0);
						ft_stack_push_back(instr_set, new);
						ft_stack_rotate(st);
						if (!(new = ft_stack_new(3)))
							return (0);
						ft_stack_push_back(instr_set, new);
						i++;
					}
					ft_stack_rotate(st);
					if (!(new = ft_stack_new(3)))
						return (0);
					ft_stack_push_back(instr_set, new);					
				}
				else
				{
					ft_push_stack(st, opp_st);
					if (!(new = ft_stack_new(10)))
						return (0);
					ft_stack_push_back(instr_set, new);
					ft_stack_swap_top(st);
					if (!(new = ft_stack_new(0)))
						return (0);
					ft_stack_push_back(instr_set, new);
					ft_stack_rotate(st);
					if (!(new = ft_stack_new(3)))
						return (0);
					ft_stack_push_back(instr_set, new);
					if ((*st)->nb > (*opp_st)->nb)
					{
						ft_push_stack(opp_st, st);
						if (!(new = ft_stack_new(9)))
							return (0);
						ft_stack_push_back(instr_set, new);
						while (i < 2)
						{
							ft_stack_rotate(st);
							if (!(new = ft_stack_new(3)))
								return (0);
							ft_stack_push_back(instr_set, new);
							i++;
						}
					}
					else
					{
						ft_stack_rotate(st);
						if (!(new = ft_stack_new(3)))
							return (0);
						ft_stack_push_back(instr_set, new);
						ft_push_stack(opp_st, st);
						if (!(new = ft_stack_new(9)))
							return (0);
						ft_stack_push_back(instr_set, new);
						ft_stack_rotate(st);
						if (!(new = ft_stack_new(3)))
							return (0);
						ft_stack_push_back(instr_set, new);
					}	
				}				
			}
			else
			{
				while (size)
				{
					if ((*st)->nb == ft_stack_nmin(*st, size))
					{
						ft_push_stack(st, opp_st);
						if (!(new = ft_stack_new(9)))
							return (0);
						ft_stack_push_back(instr_set, new);
						ft_stack_rotate(opp_st);
						if (!(new = ft_stack_new(3)))
							return (0);
						ft_stack_push_back(instr_set, new);
						size--;
					}
					else if ((*st)->next->nb == ft_stack_nmin(*st, size))
					{

						while (i < 2)
						{
							ft_push_stack(st, opp_st);
							if (!(new = ft_stack_new(9)))
								return (0);
							ft_stack_push_back(instr_set, new);
							i++;
						}
						ft_stack_rotate(opp_st);
						if (!(new = ft_stack_new(3)))
							return (0);
						ft_stack_push_back(instr_set, new);
						size--;
						if ((*st)->nb < (*opp_st)->nb)
						{
							ft_push_stack(st, opp_st);
							if (!(new = ft_stack_new(9)))
								return (0);
							ft_stack_push_back(instr_set, new);
							ft_stack_rotate(opp_st);
							if (!(new = ft_stack_new(3)))
								return (0);
							ft_stack_push_back(instr_set, new);
							size--;
						}
						else
						{
							ft_stack_rotate(opp_st);
							if (!(new = ft_stack_new(3)))
								return (0);
							ft_stack_push_back(instr_set, new);
							size--;
							ft_push_stack(st, opp_st);
							if (!(new = ft_stack_new(9)))
								return (0);
							ft_stack_push_back(instr_set, new);
						}
						ft_stack_rotate(opp_st);
						if (!(new = ft_stack_new(3)))
								return (0);
						ft_stack_push_back(instr_set, new);
						size--;
					}
					else
					{
						while (i < 3)
						{
							ft_push_stack(st, opp_st);
							if (!(new = ft_stack_new(9)))
								return (0);
							ft_stack_push_back(instr_set, new);
							i++;
						}
						ft_stack_rotate(opp_st);
						if (!(new = ft_stack_new(3)))
							return (0);
						ft_stack_push_back(instr_set, new);
						size--;
						if ((*opp_st)->nb > (*opp_st)->next->nb)
						{
							ft_stack_swap_top(opp_st);
							if (!(new = ft_stack_new(0)))
								return (0);
							ft_stack_push_back(instr_set, new);
						}
						i = 0;
						while (i < 2)
						{
							ft_stack_rotate(opp_st);
							if (!(new = ft_stack_new(3)))
								return (0);
							ft_stack_push_back(instr_set, new);
							size--;
							i++;
						}
					}
				}
			}
		}
	}
	return (1);
}

static void	ft_st_split(t_stack **st, t_stack **opp_st, t_stack **instr_set, unsigned int size, int state, int fd)
{
	int				pivot;
	unsigned int	rotations;
	unsigned int	pushs;

	if (DEBUG)
		ft_dprintf(fd, "\n{red}-----NEW RECURSION-----\nsize = %u\nstate = %i{reset}\n", size, state);
	while (size > 3) //&& ft_stack_is_sort(*st, 0) == 0) 
	{
		if (DEBUG)
			ft_dprintf(fd, "{yellow}>>>>>SPLIT SEQUENCE<<<<<{reset}\n");
		pivot = (*st)->nb;
		rotations = 0;
		pushs = 0;
		ft_push_stack(st, opp_st);
		ft_stack_push_back(instr_set, ft_stack_new((state == 0) ? 10 : 9));
		size--;
		pushs++;
		while (ft_stack_ncmp(*st, pivot, ft_nb_is_lower, size))
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
				size--;
			}
		}
		size += rotations;
		// if (state == 0)
		// {
			while (rotations)
			{
				ft_stack_rev_rotate(st);
				ft_stack_push_back(instr_set, ft_stack_new((state == 0) ? 6 : 7));
				rotations--;
			}
		// }
		if (DEBUG)
		{
			ft_dprintf(fd, "STATE STACK A\n");
			ft_stack_print_fd(fd, (state == 0) ? *st : *opp_st);
			ft_dprintf(fd, "STATE STACK B\n");
			ft_stack_print_fd(fd, (state == 0) ? *opp_st : *st);
		}
		ft_st_split(opp_st, st, instr_set, pushs, ~state, fd);
		if (DEBUG)
			ft_dprintf(fd, "{green}-----RETURN TO HIGHER RECURSION-----\nsize = %u\nstate = %i{reset}\n", size, state);
	}
	if (DEBUG)
		ft_dprintf(fd, "{yellow}>>>>>SORT SEQUENCE<<<<<{reset}\n");
	ft_sort_substack(st, opp_st, size, state, instr_set, fd);
	// if (state == 0)
	// 	ft_back_to_stack_a(st, opp_st, size, instr_set);
	// else
	// 	ft_back_to_stack_a(opp_st, st, size, instr_set);
	// while (size)
	// {
	// 	ft_stack_rotate(st);
	// 	ft_stack_push_back(instr_set, ft_stack_new(3));
	// 	size--;
	// }
	if (DEBUG)
	{
		ft_dprintf(fd, "{cyan}STATE STACK A\n");
		ft_stack_print_fd(fd, (state == 0) ? *st : *opp_st);
		ft_dprintf(fd, "STATE STACK B\n");
		ft_stack_print_fd(fd, (state == 0) ? *opp_st : *st);
		ft_dprintf(fd, "{reset}{bg_green}{black}-----END OF SCOPE-----{reset}\n");
	}
}

t_stack		*ft_quick_sortv2(t_stack **stack_a, unsigned int size)
{
	t_stack	*instr_set;
	t_stack	*stack_b;

int	fd;
fd = open("log.txt", O_WRONLY);
	instr_set = NULL;
	stack_b = NULL;
	// ft_stack_split(size, stack_a, &stack_b, 0, &instr_set, 0);
	// ft_st_split(stack_a, &stack_b, &instr_set, datas, 0);
	if (DEBUG || SHOW_NB)
	{
		// ft_putendl_fd("\n\nORIGINAL STACK", fd);
		ft_dprintf(fd, "-----ORIGINAL STACK-----\n");
		ft_stack_print_fd(fd, *stack_a);
	}
	ft_st_split(stack_a, &stack_b, &instr_set, size, 0, fd);
	if (DEBUG || SHOW_NB)
	{
		ft_dprintf(fd, "\n\n-----FINAL RESULT-----\n");
		// ft_putendl("\n\nFINAL RESULT");
		ft_stack_print_fd(fd, *stack_a);
	}
close(fd);
	return (instr_set);
}