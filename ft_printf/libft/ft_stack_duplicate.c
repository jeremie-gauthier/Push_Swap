#include "libft.h"

t_stack		*ft_stack_duplicate(t_stack *origin)
{
	t_stack	*dup;
	t_stack	*new_elem;

	if (origin == NULL)
		return ((dup = NULL));
	if (!(dup = ft_stack_new(origin->nb)))
		return (NULL);
	origin = origin->next;
	while (origin)
	{
		if (!(new_elem = ft_stack_new(origin->nb)))
		{
			ft_stack_del(&dup);
			return (NULL);
		}
		ft_stack_push_back(&dup, new_elem);
		origin = origin->next;
	}
	return (dup);
}
