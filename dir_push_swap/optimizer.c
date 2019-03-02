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
