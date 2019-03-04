/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 10:33:42 by jergauth          #+#    #+#             */
/*   Updated: 2019/02/14 10:33:43 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_final_state_check(t_st *lst)
{
	if (lst->st_b != NULL)
	{
		write(1, "KO\n", 3);
		return (0);
	}
	if (!(ft_stack_is_sort(lst->st_a, 0)))
	{
		write(1, "KO\n", 3);
		return (0);
	}
	if (lst->opt_fl->count == 1)
		ft_printf("{green}Moves : %i{reset}\n", ft_stack_size(lst->st_instruct));
	write(1, "OK\n", 3);
	return (1);
}

/*
**	In the array of pointers to function, the instructions are sort by
**	similarity.
**	Indexes			Functions
**	---------------------------
**	[0; 2]			Swap
**	[3; 5]			Rotate
**	[6; 8]			Reverse Rotate
**	[9; 10]			Push
**	---------------------------
**	So, except for Push ([9; 10]):
**		instr_set->nb / 3 = The function to execute (e.g: 5 / 3 = 1 => Rotate).
**		instr_set->nb % 3 = The argument(s) to send to the function.
*/

static void	ft_execute_instructions(t_st *lst, void (*f[3])(t_stack**))
{
	t_stack	*set;

	set = lst->st_instruct;
	if (f && set && lst->st_a)
	{
		while (set)
		{
			if (set->nb == 9)
				ft_push_stack(&lst->st_b, &lst->st_a);
			else if (set->nb == 10)
				ft_push_stack(&lst->st_a, &lst->st_b);
			else
			{
				if (set->nb % 3 == 0)
					f[set->nb / 3](&lst->st_a);
				else if (set->nb % 3 == 1)
					f[set->nb / 3](&lst->st_b);
				else
				{
					f[set->nb / 3](&lst->st_a);
					f[set->nb / 3](&lst->st_b);
				}
			}
			set = set->next;
		}
	}
}

int			ft_start_instructions(t_st *lst)
{
	void	(*f[3])(t_stack**);

	f[0] = &ft_stack_swap_top;
	f[1] = &ft_stack_rotate;
	f[2] = &ft_stack_rev_rotate;
	if (lst->st_a)
	{
		if (lst->opt_fl->visu == 1)
			ft_visualizer(lst, f);
		else
			ft_execute_instructions(lst, f);
	}
	return (ft_final_state_check(lst));
}
