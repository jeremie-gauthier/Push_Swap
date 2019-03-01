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

static int	ft_final_state_check(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b != NULL)
	{
		ft_stack_del(&stack_b);
		write(1, "KO\n", 3);
		return (0);
	}
	if (!(ft_stack_is_sort(stack_a, 0)))
	{
		write(1, "KO\n", 3);
		return (0);
	}
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

static void	ft_execute_instructions(t_stack **stack_a,
				t_stack *instructions_set, t_stack **stack_b,
					void (*f[3])(t_stack**))
{
	if (f && instructions_set && *stack_a)
	{
		while (instructions_set)
		{
			if (instructions_set->nb == 9)
				ft_push_stack(stack_b, stack_a);
			else if (instructions_set->nb == 10)
				ft_push_stack(stack_a, stack_b);
			else
			{
				if (instructions_set->nb % 3 == 0)
					f[instructions_set->nb / 3](stack_a);
				else if (instructions_set->nb % 3 == 1)
					f[instructions_set->nb / 3](stack_b);
				else
				{
					f[instructions_set->nb / 3](stack_a);
					f[instructions_set->nb / 3](stack_b);
				}
			}
			instructions_set = instructions_set->next;
		}
	}
}

int			ft_start_instructions(t_stack **stack_a,
					t_stack *instructions_set, t_options *fl)
{
	t_st	*lst;
	void	(*f[3])(t_stack**);

	f[0] = &ft_stack_swap_top;
	f[1] = &ft_stack_rotate;
	f[2] = &ft_stack_rev_rotate;
	lst = malloc(sizeof(*lst)); //
	if (lst == NULL)
		return (-1);
	lst->st_a = *stack_a;
	lst->st_b = NULL;
	lst->st_instruct = instructions_set;
	lst->opt_fl = fl;
	if (fl->visu == 1)
		ft_visualizer(lst, f);
	else
		ft_execute_instructions(&lst->st_a, lst->st_instruct, &lst->st_b, f);
	return (ft_final_state_check(*stack_a, lst->st_b));
}
