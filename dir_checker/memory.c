#include "../includes/push_swap.h"

t_options	*init_options(void)
{
	t_options	*new;

	if (!(new = (t_options*)malloc(sizeof(new))))
		return (NULL);
	new->counter = 0;
	new->visu = 0;
	new->count = 0;
	new->time = 500;
	return (new);
}
