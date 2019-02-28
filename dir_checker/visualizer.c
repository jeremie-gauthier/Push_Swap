#include "../includes/push_swap.h"

int		ft_visualizer(t_st *lst, void (*f[3])(t_stack**))
{
	unsigned int	size_a;
	unsigned int	size_b;
	unsigned int	diff;
	t_stack			*tmp_a;
	t_stack			*tmp_b;
	// int				last_actions;

	while (lst->st_instruct)
	{
		tmp_a = lst->st_a;
		tmp_b = lst->st_b;
		size_a = ft_stack_size(lst->st_a);
		size_b = ft_stack_size(lst->st_b);
		diff = ft_abs(size_a - size_b);
		ft_printf("%s{blue}*****************************************{reset}\n", CLEAR);
		while (diff > 0)
		{
			if (size_a > size_b)
			{
				ft_printf("{blue}|{reset}%10i{blue}%10c%20c{reset}\n", tmp_a->nb, '|', '|');
				tmp_a = tmp_a->next;
			}
			else
			{
				ft_printf("{blue}%c%20c{reset}%10i{blue}%10c{reset}\n", '|', '|', tmp_b->nb, '|');
				tmp_b = tmp_b->next;	
			}
			diff--;
		}
		while (tmp_a && tmp_b)
		{
			ft_printf("{blue}%c{reset}%10i{blue}%10c{reset}%10i{blue}%10c{reset}\n", '|', tmp_a->nb, '|', tmp_b->nb, '|');
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
		}
		ft_printf("{blue}|-------------------|-------------------|\n|{yellow}%13s{blue}%7c{yellow}%13s{blue}%7c\
			\n*****************************************{reset}\n{yellow}Moves : %hu{reset}\n", "STACK A", '|', "STACK B", '|',
					lst->opt_fl->counter);
		if (lst->st_instruct->nb == 9)
			ft_push_stack(&lst->st_b, &lst->st_a);
		else if (lst->st_instruct->nb == 10)
			ft_push_stack(&lst->st_a, &lst->st_b);
		else
		{
			if (lst->st_instruct->nb % 3 == 0)
				f[lst->st_instruct->nb / 3](&lst->st_a);
			else if (lst->st_instruct->nb % 3 == 1)
				f[lst->st_instruct->nb / 3](&lst->st_b);
			else
			{
				f[lst->st_instruct->nb / 3](&lst->st_a);
				f[lst->st_instruct->nb / 3](&lst->st_b);
			}
		}
		lst->st_instruct = lst->st_instruct->next;
		lst->opt_fl->counter++;
		usleep(lst->opt_fl->time * 1000);
	}
	tmp_a = lst->st_a;
	tmp_b = lst->st_b;
	size_a = ft_stack_size(lst->st_a);
	size_b = ft_stack_size(lst->st_b);
	diff = ft_abs(size_a - size_b);
	ft_printf("%s{blue}*****************************************{reset}\n", CLEAR);
	while (diff > 0)
	{
		if (size_a > size_b)
		{
			ft_printf("{blue}|{reset}%10i{blue}%10c%20c{reset}\n", tmp_a->nb, '|', '|');
			tmp_a = tmp_a->next;
		}
		else
		{
			ft_printf("{blue}%c%20c{reset}%10i{blue}%10c{reset}\n", '|', '|', tmp_b->nb, '|');
			tmp_b = tmp_b->next;	
		}
		diff--;
	}
	ft_printf("{blue}|-------------------|-------------------|\n|{yellow}%13s{blue}%7c{yellow}%13s{blue}%7c\
		\n*****************************************{reset}\n{yellow}Moves : %hu{reset}\n", "STACK A", '|', "STACK B", '|',
				lst->opt_fl->counter);
	return (0);
}
