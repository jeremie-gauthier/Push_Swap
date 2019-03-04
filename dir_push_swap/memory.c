/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:22:25 by jergauth          #+#    #+#             */
/*   Updated: 2019/03/03 13:22:26 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_options	*init_options(void)
{
	t_options	*new;

	if (!(new = (t_options*)malloc(sizeof(*new))))
		return (NULL);
	new->pathname = NULL;
	new->counter = 0;
	new->visu = 0;
	new->count = 0;
	new->time = 500;
	return (new);
}

t_st		*init_stacks(void)
{
	t_st	*new;

	if (!(new = (t_st*)malloc(sizeof(*new))))
		return (NULL);
	if (!(new->opt_fl = init_options()))
	{
		ft_memdel((void*)&new);
		return (NULL);
	}
	new->st_a = NULL;
	new->st_b = NULL;
	new->st_instruct = NULL;
	new->sorted = 0;
	return (new);
}

void		st_del(t_st **lst)
{
	ft_stack_del(&(*lst)->st_a);
	ft_stack_del(&(*lst)->st_b);
	ft_stack_del(&(*lst)->st_instruct);
	ft_strdel(&(*lst)->opt_fl->pathname);
	ft_memdel((void*)&(*lst)->opt_fl);
	ft_memdel((void*)lst);
}
