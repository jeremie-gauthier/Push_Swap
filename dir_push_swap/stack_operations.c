#include "../includes/push_swap.h"

int		ft_swap_and_write(t_st *lst, int state)
{
	t_stack	**st;
	t_stack	*tmp;

	st = (state == 0) ? &lst->st_a : &lst->st_b;
	ft_stack_swap_top(st);
	if (!(tmp = ft_stack_new((state == 0) ? 0 : 1)))
		return (0);
	ft_stack_push_back(&lst->st_instruct, tmp);
	return (1);
}

int		ft_rotate_and_write(t_st *lst, int state)
{
	t_stack	**st;
	t_stack	*tmp;

	st = (state == 0) ? &lst->st_a : &lst->st_b;
	ft_stack_rotate(st);
	if (!(tmp = ft_stack_new((state == 0) ? 3 : 4)))
		return (0);
	ft_stack_push_back(&lst->st_instruct, tmp);
	return (1);
}

int		ft_rev_rotate_and_write(t_st *lst, int state)
{
	t_stack	**st;
	t_stack	*tmp;

	st = (state == 0) ? &lst->st_a : &lst->st_b;
	ft_stack_rev_rotate(st);
	if (!(tmp = ft_stack_new((state == 0) ? 6 : 7)))
		return (0);
	ft_stack_push_back(&lst->st_instruct, tmp);
	return (1);
}

int		ft_push_stack_and_write(t_st *lst, int state)
{
	t_stack	**st;
	t_stack	**opp_st;
	t_stack	*tmp;

	st = (state == 0) ? &lst->st_a : &lst->st_b;
	opp_st = (state == 0) ? &lst->st_b : &lst->st_a;
	if (*st != NULL)
	{
		tmp = *st;
		*st = (*st)->next;
		tmp->next = *opp_st;
		*opp_st = tmp;
	}
	if (!(tmp = ft_stack_new((state == 0) ? 10 : 9)))
		return (0);
	ft_stack_push_back(&lst->st_instruct, tmp);
	return (1);
}

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

/*
**	After ensuring that the number contains in *str can be converted to an int
**	without overflow.
**	We check that this is not a duplicate number.
**	Then we add it back to the stack.
*/

int		ft_stack_append(char *str, t_stack **stack_a)
{
	t_stack	*new;
	long	nb;

	nb = ft_atol_base(str, 10);
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	if (ft_stack_find(*stack_a, (int)nb))
		return (0);
	if (!(new = ft_stack_new((int)nb)))
		return (0);
	ft_stack_push_back(stack_a, new);
	return (1);
}
