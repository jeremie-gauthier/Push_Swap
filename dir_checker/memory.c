#include "../includes/push_swap.h"

t_options	*init_options(void)
{
	t_options	*new;

	if (!(new = (t_options*)malloc(sizeof(new))))
		return (NULL);
	new->visu = 0;
	new->count = 0;
	return (new);
}
