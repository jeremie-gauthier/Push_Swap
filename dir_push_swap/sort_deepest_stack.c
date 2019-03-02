#include "../includes/push_swap.h"

int	ft_sort_substack(t_stack **st, t_stack **opp_st, unsigned int size, int state, t_stack **instr_set)
{
	t_stack	*new;
	int		i;
	int		elem_on_opp_st;

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
							ft_stack_swap_top(opp_st);
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
				// top < (mid && bot)
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

int	ft_sort_deepest_stack(t_st *lst, unsigned int size, int state)
{
	int		i;

	if (ft_stack_is_sort((state == 0) ? lst->st_a : lst->st_b, 0) == 1
				&& ((state == 0) ? lst->st_a : lst->st_b) == NULL)
		return (1);
	i = 0;
	if (size == 1)
	{
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
	}
	else if (size == 2)
	{
		if (state == 0)
		{
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
		}
		else
		{
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
				i = 0;
				while (i < 2)
				{
					if (!(ft_rotate_and_write(lst, 0)))
						return (0);
					i++;
				}
			}
		}
		
	}
	else if (size == 3)
	{
		if (((state == 0) ? lst->st_a : lst->st_b)->next->next->next == NULL)
		{
			if (state == 0)
			{
				if (lst->st_a->next->nb > lst->st_a->nb && lst->st_a->next->nb > lst->st_a->next->next->nb)
				{
					if (!(ft_rev_rotate_and_write(lst, 0)))
						return (0);
				}
				if (lst->st_a->nb > lst->st_a->next->nb && lst->st_a->nb > lst->st_a->next->next->nb)
				{
					if (!(ft_rotate_and_write(lst, 0)))
						return (0);
				}
				if (lst->st_a->nb > lst->st_a->next->nb)
				{
					if (!(ft_swap_and_write(lst, 0)))
						return (0);
				}
			}
			else
			{
				while (size)
				{
					if (lst->st_b->nb == ft_stack_nmin(lst->st_b, size))
					{
						if (!(ft_push_stack_and_write(lst, -1)))
							return (0);
						if (!(ft_rotate_and_write(lst, 0)))
							return (0);
						size--;
					}
					else if (lst->st_b->next->nb == ft_stack_nmin(lst->st_b, size))
					{
						while (i < 2)
						{
							if (!(ft_push_stack_and_write(lst, -1)))
								return (0);
							i++;
						}
						if (!(ft_rotate_and_write(lst, 0)))
							return (0);
						size--;
						if (lst->st_b->nb < lst->st_a->nb)
						{
							if (!(ft_push_stack_and_write(lst, -1)))
								return (0);
							if (!(ft_rotate_and_write(lst, 0)))
								return (0);
							size--;
						}
						else
						{
							if (!(ft_rotate_and_write(lst, 0)))
								return (0);
							size--;
							if (!(ft_push_stack_and_write(lst, -1)))
								return (0);
						}
						if (!(ft_rotate_and_write(lst, 0)))
							return (0);
						size--;
					}
					else
					{
						while (i < 3)
						{
							if (!(ft_push_stack_and_write(lst, -1)))
								return (0);
							i++;
						}
						if (!(ft_rotate_and_write(lst, 0)))
							return (0);
						size--;
						if (lst->st_a->nb > lst->st_a->next->nb)
						{
							if (!(ft_swap_and_write(lst, 0)))
								return (0);
						}
						i = 0;
						while (i < 2)
						{
							if (!(ft_rotate_and_write(lst, 0)))
								return (0);
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
				// top < (mid && bot)
				if (lst->st_a->nb < lst->st_a->next->nb && lst->st_a->nb < lst->st_a->next->next->nb)
				{
					if (!(ft_rotate_and_write(lst, 0)))
						return (0);
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
				}
				//top > mid && top < bot
				else if (lst->st_a->nb > lst->st_a->next->nb && lst->st_a->nb < lst->st_a->next->next->nb)
				{
					if (!(ft_swap_and_write(lst, 0)))
						return (0);
					while (i < 3)
					{
						if (!(ft_rotate_and_write(lst, 0)))
							return (0);
						i++;
					}
				}
				//bot > mid && bot < top
				else if (lst->st_a->next->next->nb > lst->st_a->next->nb && lst->st_a->next->next->nb < lst->st_a->nb)
				{
					while (i < 2)
					{
						if (!(ft_swap_and_write(lst, 0)))
							return (0);
						if (!(ft_rotate_and_write(lst, 0)))
							return (0);
						i++;
					}
					if (!(ft_rotate_and_write(lst, 0)))
						return (0);
				}
				else
				{
					if (!(ft_push_stack_and_write(lst, 0)))
						return (0);
					if (!(ft_swap_and_write(lst, 0)))
						return (0);
					if (!(ft_rotate_and_write(lst, 0)))
						return (0);
					if (lst->st_a->nb > lst->st_b->nb)
					{
						if (!(ft_push_stack_and_write(lst, -1)))
							return (0);
						while (i < 2)
						{
							if (!(ft_rotate_and_write(lst, 0)))
								return (0);
							i++;
						}
					}
					else
					{
						if (!(ft_rotate_and_write(lst, 0)))
							return (0);
						if (!(ft_push_stack_and_write(lst, -1)))
							return (0);
						if (!(ft_rotate_and_write(lst, 0)))
							return (0);
					}	
				}				
			}
			else
			{
				while (size)
				{
					if (lst->st_b->nb == ft_stack_nmin(lst->st_b, size))
					{
						if (!(ft_push_stack_and_write(lst, -1)))
							return (0);
						if (!(ft_rotate_and_write(lst, 0)))
							return (0);
						size--;
					}
					else if (lst->st_b->next->nb == ft_stack_nmin(lst->st_b, size))
					{

						while (i < 2)
						{
							if (!(ft_push_stack_and_write(lst, -1)))
								return (0);
							i++;
						}
						if (!(ft_rotate_and_write(lst, 0)))
							return (0);
						size--;
						if (lst->st_b->nb < lst->st_a->nb)
						{
							if (!(ft_push_stack_and_write(lst, -1)))
								return (0);
							if (!(ft_rotate_and_write(lst, 0)))
								return (0);
							size--;
						}
						else
						{
							if (!(ft_rotate_and_write(lst, 0)))
								return (0);
							size--;
							if (!(ft_push_stack_and_write(lst, -1)))
								return (0);
						}
						if (!(ft_rotate_and_write(lst, 0)))
							return (0);
						size--;
					}
					else
					{
						while (i < 3)
						{
							if (!(ft_push_stack_and_write(lst, -1)))
								return (0);
							i++;
						}
						if (!(ft_rotate_and_write(lst, 0)))
							return (0);
						size--;
						if (lst->st_a->nb > lst->st_a->next->nb)
						{
							if (!(ft_swap_and_write(lst, 0)))
								return (0);
						}
						i = 0;
						while (i < 2)
						{
							if (!(ft_rotate_and_write(lst, 0)))
								return (0);
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
