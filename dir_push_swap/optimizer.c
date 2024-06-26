/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:22:40 by jergauth          #+#    #+#             */
/*   Updated: 2019/03/03 13:22:41 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	change_last_instruction(t_stack *instr_set, int supposed_val, int new_val)
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
