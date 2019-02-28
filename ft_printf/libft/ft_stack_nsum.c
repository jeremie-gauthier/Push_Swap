#include "libft.h"

long	ft_stack_nsum(t_stack *head, unsigned int limit)
{
	long			sum;
	unsigned int	i;

	sum = 0;
	i = 0;
	while (head && i < limit)
	{
		sum += head->nb;
		head = head->next;
		i++;
	}
	return (sum);
}
