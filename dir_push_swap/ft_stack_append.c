/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:26:44 by jergauth          #+#    #+#             */
/*   Updated: 2019/03/03 15:26:45 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	After ensuring that the number contains in *str can be converted to an int
**	without overflow.
**	We check that this is not a duplicate number.
**	Then we add it back to the stack.
*/

int		ft_stack_append(char *str, t_stack **stack_a)
{
	t_stack	*new;
	long	nb;

	nb = ft_atol_base(str, 10);
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	if (ft_stack_find(*stack_a, (int)nb))
		return (0);
	if (!(new = ft_stack_new((int)nb)))
		return (0);
	ft_stack_push_back(stack_a, new);
	return (1);
}
