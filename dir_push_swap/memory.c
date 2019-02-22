#include "../includes/push_swap.h"

t_data	*init_data(unsigned int size)
{
	t_data	*new;

	if (!(new = (t_data*)malloc(sizeof(*new))))
		return (NULL);
	new->size = size;
	new->reste = 0;
	new->state = -1;
	new->depth = 0;
	return (new);
}
