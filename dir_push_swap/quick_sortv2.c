#include "../includes/push_swap.h"

static void	ft_stack_print_fd(int fd, t_stack *current)
{
	if (current != NULL)
	{
		while (current)
		{
			ft_putnbr_fd(current->nb, fd);
			ft_putchar_fd('\n', fd);
			current = current->next;
		}
	}
}

static int	change_last_instruction(t_stack *instr_set, int supposed_val, int new_val)
{
	t_stack	*current;

	current = instr_set;
	if (current)
	{
		while (current->next)
			current = current->next;
		if (current->nb == supposed_val)
		{
			current->nb = new_val;
			return (1);
		}
	}
	return (0);
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
			if (change_last_instruction(*instr_set, 10, 3) == 1)
			{
				ft_push_stack(st, opp_st);
				ft_stack_rotate(opp_st);
			}
			else
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

// static int	ft_choose_pivot(t_stack **st, t_st **lst, unsigned int *size, int state, int fd)
// {
// 	int		max;
// 	while (state == 0 && (*st)->nb == ft_stack_nmin(*st, *size))
// 	{
// 		ft_stack_rotate(st);
// 		ft_stack_push_back(&(*lst)->st_instruct, ft_stack_new(3));
// 		(*size)--;
// 		(*lst)->sorted = 1;
// 	}
// 	max = ft_stack_nmax(*st, *size);
// 	ft_dprintf(fd, "max = %i\n", max);
// 	if (*size > 1)
// 	{
// 		if ((*st)->next && (*st)->nb == max)
// 			return ((*st)->next->nb);
// 	}
// 	return ((*st)->nb);	
// }

static void	ft_st_split(t_st *lst, unsigned int size, int state, int fd)
{
	int				pivot;
	unsigned int	rotations;
	unsigned int	pushs;
	t_stack			**st;
	t_stack			**opp_st;
//essai implementation opti 3
int				min;
int				min_opp_st;

	st = (state == 0) ? &lst->st_a : &lst->st_b;
	opp_st = (state == 0) ? &lst->st_b : &lst->st_a;
	// if (state == 0)
	// {
	// 	if (*opp_st == NULL)
	// 		lst->sorted_b = 0;
	// }
	// else
	// {
	// 	if (*st == NULL)
	// 		lst->sorted_b = 0;
	// }
//essai implementation opti 3
min = ft_stack_nmin(*st, size);
	if (DEBUG)
		ft_dprintf(fd, "\n{red}-----NEW RECURSION-----\nsize = %u\nstate = %i{reset}\n", size, state);
	while (size > 3) //&& ft_stack_is_sort(*st, 0) == 0) 
	{
		if (DEBUG)
			ft_dprintf(fd, "{yellow}>>>>>SPLIT SEQUENCE<<<<<{reset}\n");
		// pivot = ft_choose_pivot(st, &lst, &size, state, fd);
		pivot = (*st)->nb;
		rotations = 0;
		pushs = 0;
		// if ((*st)->nb != pivot)
		// {
		// 	ft_stack_rotate(st);
		// 	ft_stack_push_back(&lst->st_instruct, ft_stack_new((state == 0) ? 3 : 4));
		// 	rotations++;
		// 	size--;
		// }
		ft_push_stack(st, opp_st);
		ft_stack_push_back(&lst->st_instruct, ft_stack_new((state == 0) ? 10 : 9));
		size--;
		pushs++;
		while (ft_stack_ncmp(*st, pivot, ft_nb_is_lower, size))
		{
//essai implementation opti 3
if (state == 0 && (*st)->nb == min && rotations == 0)
{
	ft_stack_rotate(st);
	ft_stack_push_back(&lst->st_instruct, ft_stack_new(3));
	size--;
	min = ft_stack_nmin(*st, size);
	min_opp_st= ft_stack_min(*opp_st);
	min = (min < min_opp_st) ? min : min_opp_st;
	lst->sorted = 1;
}
// else if (state == -1 && (*st)->nb == min)
// {
// 	ft_push_stack(st, opp_st);
// 	ft_stack_push_back(&lst->st_instruct, ft_stack_new(9));
// 	ft_stack_rotate(opp_st);
// 	ft_stack_push_back(&lst->st_instruct, ft_stack_new(3));
// 	size--;
// 	min = ft_stack_nmin(*st, size);
// }
			else if ((*st)->nb < pivot)
			{
				ft_push_stack(st, opp_st);
				ft_stack_push_back(&lst->st_instruct, ft_stack_new((state == 0) ? 10 : 9));
				size--;
				pushs++;
			}
			else
			{
				ft_stack_rotate(st);
				ft_stack_push_back(&lst->st_instruct, ft_stack_new((state == 0) ? 3 : 4));
				rotations++;
				size--;
			}
		}
		size += rotations;
		if (lst->sorted == 0)
			lst->sorted = 1;
		// if ((lst->sorted_a == 1 && state == 0) || (lst->sorted_b == 1 && state == -1))
		else
		{
			while (rotations)
			{
				ft_stack_rev_rotate(st);
				ft_stack_push_back(&lst->st_instruct, ft_stack_new((state == 0) ? 6 : 7));
				rotations--;
			}
		}
		// if (lst->sorted_a == 0 && state == 0)
		// 	lst->sorted_a = 1;
		// else if (lst->sorted_b == 0 && state == -1)
			// lst->sorted_b = 1;
		// if (state == 0)
		// {

		// }
		if (DEBUG)
		{
			ft_dprintf(fd, "STATE STACK A\n");
			ft_stack_print_fd(fd, (state == 0) ? *st : *opp_st);
			ft_dprintf(fd, "STATE STACK B\n");
			ft_stack_print_fd(fd, (state == 0) ? *opp_st : *st);
		}
		ft_st_split(lst, pushs, ~state, fd);
		if (DEBUG)
			ft_dprintf(fd, "{green}-----RETURN TO HIGHER RECURSION-----\nsize = %u\nstate = %i{reset}\n", size, state);
	}
	if (DEBUG)
		ft_dprintf(fd, "{yellow}>>>>>SORT SEQUENCE<<<<<{reset}\n");
	ft_sort_substack(st, opp_st, size, state, &lst->st_instruct, fd);
	if (DEBUG)
	{
		ft_dprintf(fd, "{cyan}STATE STACK A\n");
		ft_stack_print_fd(fd, (state == 0) ? *st : *opp_st);
		ft_dprintf(fd, "STATE STACK B\n");
		ft_stack_print_fd(fd, (state == 0) ? *opp_st : *st);
		ft_dprintf(fd, "{reset}{bg_green}{black}-----END OF SCOPE-----{reset}\n");
	}
}

int		ft_quick_sortv2(t_st *lst, unsigned int size)
{
int	fd;
fd = open("log.txt", O_CREAT | O_WRONLY, S_IRWXU);
	if (DEBUG || SHOW_NB)
	{
		ft_dprintf(fd, "-----ORIGINAL STACK-----\n");
		ft_stack_print_fd(fd, lst->st_a);
	}
	ft_st_split(lst, size, 0, fd);
	if (DEBUG || SHOW_NB)
	{
		ft_dprintf(fd, "\n\n-----FINAL RESULT-----\n");
		// ft_putendl("\n\nFINAL RESULT");
		ft_stack_print_fd(fd, lst->st_a);
	}
close(fd);
	return (1);
}