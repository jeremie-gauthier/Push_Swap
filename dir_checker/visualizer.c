/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:25:06 by jergauth          #+#    #+#             */
/*   Updated: 2019/03/04 18:25:07 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_print_diff(t_stack **tmp_a, t_stack **tmp_b)
{
	unsigned int	size_a;
	unsigned int	size_b;
	unsigned int	diff;

	size_a = ft_stack_size(*tmp_a);
	size_b = ft_stack_size(*tmp_b);
	diff = ft_abs(size_a - size_b);
	while (diff > 0)
	{
		if (size_a > size_b)
		{
			ft_printf("{blue}|{reset}%10i{blue}%10c%20c{reset}\n",
					(*tmp_a)->nb, '|', '|');
			*tmp_a = (*tmp_a)->next;
		}
		else
		{
			ft_printf("{blue}%c%20c{reset}%10i{blue}%10c{reset}\n", '|', '|',
					(*tmp_b)->nb, '|');
			*tmp_b = (*tmp_b)->next;
		}
		diff--;
	}
}

static void	ft_print_current_state(t_st *lst)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = lst->st_a;
	tmp_b = lst->st_b;
	ft_printf("{CLEAR}{blue}*****************************************\
					{reset}\n");
	ft_print_diff(&tmp_a, &tmp_b);
	while (tmp_a && tmp_b)
	{
		ft_printf("{blue}%c{reset}%10i{blue}%10c{reset}%10i{blue}%10c{reset}\n",
					'|', tmp_a->nb, '|', tmp_b->nb, '|');
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
	}
	ft_printf("{blue}|-------------------|-------------------|\n|");
	ft_printf("{yellow}%13s{blue}%7c{yellow}%13s", "STACK A", '|', "STACK B");
	ft_printf("{blue}%7c\n*****************************************", '|');
	ft_printf("{reset}\n{yellow}Moves : %hu{reset}\n", lst->opt_fl->counter);
}

static void	ft_play_instructions(t_st *lst, void (*f[3])(t_stack**))
{
	if (lst->st_instruct->nb == 9)
		ft_push_stack(&lst->st_b, &lst->st_a);
	else if (lst->st_instruct->nb == 10)
		ft_push_stack(&lst->st_a, &lst->st_b);
	else
	{
		if (lst->st_instruct->nb % 3 == 0)
			f[lst->st_instruct->nb / 3](&lst->st_a);
		else if (lst->st_instruct->nb % 3 == 1)
			f[lst->st_instruct->nb / 3](&lst->st_b);
		else
		{
			f[lst->st_instruct->nb / 3](&lst->st_a);
			f[lst->st_instruct->nb / 3](&lst->st_b);
		}
	}
	lst->st_instruct = lst->st_instruct->next;
	lst->opt_fl->counter++;
}

int			ft_visualizer(t_st *lst, void (*f[3])(t_stack**))
{
	t_stack	*set;

	set = lst->st_instruct;
	while (lst->st_instruct)
	{
		ft_print_current_state(lst);
		ft_play_instructions(lst, f);
		usleep(lst->opt_fl->time * 1000);
	}
	ft_print_current_state(lst);
	lst->st_instruct = set;
	return (1);
}
