#include "libft.h"

long	ft_stack_sum(t_stack *head)
{
	long	sum;

	sum = 0;
	while (head)
	{
		sum += head->nb;
		head = head->next;
	}
	return (sum);
}
