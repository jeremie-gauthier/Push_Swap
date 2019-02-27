#include "../includes/push_swap.h"

//useless now
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
///

t_options	*init_options(void)
{
	t_options	*new;

	if (!(new = (t_options*)malloc(sizeof(new))))
		return (NULL);
	new->visu = 0;
	new->count = 0;
	return (new);
}

t_st		*init_stacks(void)
{
	t_st	*new;

	if (!(new = (t_st*)malloc(sizeof(*new))))
		return (NULL);
	if (!(new->opt_fl = init_options()))
	{
		ft_memdel((void*)&new);
		return (NULL);
	}
	new->st_a = NULL;
	new->st_b = NULL;
	new->st_instruct = NULL;
	new->depth = 0;
	// new->sorted = 0;
	new->sorted_a = 0;
	new->sorted_b = 0;
	return (new);
}

void		st_del(t_st **lst)
{
	// ft_printf("del a\n");
	ft_stack_del(&(*lst)->st_a);
	// ft_printf("del b\n");
	ft_stack_del(&(*lst)->st_b);
	// ft_printf("del set\n");
	ft_stack_del(&(*lst)->st_instruct);
	// ft_printf("del flags\n");
	ft_memdel((void*)&(*lst)->opt_fl);
	// ft_printf("del lst struct\n");
	ft_memdel((void*)lst);
}
