#include "../includes/push_swap.h"

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
