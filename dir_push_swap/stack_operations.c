/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:23:30 by jergauth          #+#    #+#             */
/*   Updated: 2019/03/03 13:23:31 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_swap_and_write(t_st *lst, int state)
{
	t_stack	**st;
	t_stack	*tmp;

	st = (state == 0) ? &lst->st_a : &lst->st_b;
	ft_stack_swap_top(st);
	if (!(tmp = ft_stack_new((state == 0) ? 0 : 1)))
		return (0);
	ft_stack_push_back(&lst->st_instruct, tmp);
	return (1);
}

int		ft_rotate_and_write(t_st *lst, int state)
{
	t_stack	**st;
	t_stack	*tmp;

	st = (state == 0) ? &lst->st_a : &lst->st_b;
	ft_stack_rotate(st);
	if (!(tmp = ft_stack_new((state == 0) ? 3 : 4)))
		return (0);
	ft_stack_push_back(&lst->st_instruct, tmp);
	return (1);
}

int		ft_rev_rotate_and_write(t_st *lst, int state)
{
	t_stack	**st;
	t_stack	*tmp;

	st = (state == 0) ? &lst->st_a : &lst->st_b;
	ft_stack_rev_rotate(st);
	if (!(tmp = ft_stack_new((state == 0) ? 6 : 7)))
		return (0);
	ft_stack_push_back(&lst->st_instruct, tmp);
	return (1);
}

int		ft_push_stack_and_write(t_st *lst, int state)
{
	t_stack	**st;
	t_stack	**opp_st;
	t_stack	*tmp;

	st = (state == 0) ? &lst->st_a : &lst->st_b;
	opp_st = (state == 0) ? &lst->st_b : &lst->st_a;
	if (*st != NULL)
	{
		tmp = *st;
		*st = (*st)->next;
		tmp->next = *opp_st;
		*opp_st = tmp;
	}
	if (!(tmp = ft_stack_new((state == 0) ? 10 : 9)))
		return (0);
	ft_stack_push_back(&lst->st_instruct, tmp);
	return (1);
}

void	ft_push_stack(t_stack **leave, t_stack **receive)
{
	t_stack	*tmp;

	if (*leave != NULL)
	{
		tmp = *leave;
		*leave = (*leave)->next;
		tmp->next = *receive;
		*receive = tmp;
	}
}
