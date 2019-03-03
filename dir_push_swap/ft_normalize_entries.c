/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_entries.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:38:40 by jergauth          #+#    #+#             */
/*   Updated: 2019/03/03 16:38:41 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		ft_replace_min(t_stack **origin, t_stack *dup,
						const unsigned int size, const int max)
{
	unsigned int	i;
	unsigned int	index;
	int				min;

	i = 1;
	while (i <= size)
	{
		min = ft_stack_min(*origin);
		index = ft_stack_find(*origin, min);
		ft_stack_node_at(*origin, index )->nb = max;
		ft_stack_node_at(dup, index )->nb = i;
		i++;
	}
	return (1);
}

t_stack			*ft_normalize_entries(t_stack **st)
{
	unsigned int	size;
	t_stack			*dup;

	if (!(dup = ft_stack_duplicate(*st)))
		return (NULL);
	size = ft_stack_size(*st);
	if (!(ft_replace_min(st, dup, size, ft_stack_max(*st) + 1)))
		return (NULL);
	ft_stack_del(st);
	return (dup);
}
