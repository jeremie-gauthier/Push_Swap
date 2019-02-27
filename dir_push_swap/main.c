/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:38:15 by jergauth          #+#    #+#             */
/*   Updated: 2019/02/14 20:38:16 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_clean_abort(t_st **lst, int msg, int ret)
{
	if (msg == 1)
		ft_dprintf(2, "{red}Error\n{reset}");
	if (msg == 2)
		ft_dprintf(2, "{red}[!] Failed to malloc.\n{reset}");
	st_del(lst);
	return (ret);
}

int		ft_print_instructions(t_stack *instruct_set)
{
	char	*ret;
	size_t	i;

	// ft_printf("st_size = %u\nsize = %u\ndebut---\n", ft_stack_size(instruct_set), size);
	// ft_stack_print(instruct_set);
	// ft_printf("---fin\n");
	if (!(ret = (char*)malloc(sizeof(*ret)
					* (ft_stack_size(instruct_set) * 4) + 1)))
		return (0);
	i = 0;
	while (instruct_set)
	{
		// ft_printf("hi\n");
		if (instruct_set->nb >= 0 && instruct_set->nb <= 2)
		{
			ret[i++] = 's';
			if (instruct_set->nb == 0)
				ret[i++] = 'a';
			else if (instruct_set->nb == 0)
				ret[i++] = 'b';
			else
				ret[i++] = 's';
			// ft_printf("galere 1\n");
		}
		else if (instruct_set->nb >= 3 && instruct_set->nb <= 5)
		{
			ret[i++] = 'r';
			if (instruct_set->nb == 3)
				ret[i++] = 'a';
			else if (instruct_set->nb == 4)
				ret[i++] = 'b';
			else
				ret[i++] = 'r';
			// ft_printf("galere 2\n");
		}
		else if (instruct_set->nb >= 6 && instruct_set->nb <= 8)
		{
			ret[i++] = 'r';
			ret[i++] = 'r';
			if (instruct_set->nb == 6)
				ret[i++] = 'a';
			else if (instruct_set->nb == 7)
				ret[i++] = 'b';
			else
				ret[i++] = 'r';
			// ft_printf("galere 3\n");
		}
		else
		{
			ret[i++] = 'p';
			if (instruct_set->nb == 9)
				ret[i++] = 'a';
			else
				ret[i++] = 'b';
			// ft_printf("galere 4\n");
		}
		ret[i++] = '\n';
		// ft_printf("galere bonus\n");
		instruct_set = instruct_set->next;
	}
	ret[i] = '\0';
	ft_putstr(ret);
	// ft_printf("ret addr : %p\n", &ret);
	// ft_printf("%s\n", ret);
	// ft_printf("Hello from the otter side\n");
	// ft_printf("avant del ret\n");
	ft_strdel(&ret);
	// ft_printf("apres del ret\n");
	// free(ret);
	return (1);
}

int		main(int argc, char **argv)
{
	t_st			*lst;
	unsigned int	size;

	if (argc >= 2)
	{
		argv++;
		if (!(lst = init_stacks()))
			return (ft_clean_abort(NULL, 2, 1));
		if (!(lst->st_a = ft_check_args_and_build_stack(lst->opt_fl, argv)))
			return (ft_clean_abort(&lst, 1, 1));
		if (ft_stack_is_sort(lst->st_a, 0))
			return (ft_clean_abort(&lst, 0, 0));
		size = ft_stack_size(lst->st_a);
		if (size > 3 && size < 6)
		{
			if (!(ft_insertion_sort(lst, size)))
				return (ft_clean_abort(&lst, 1, 1));
		}
		else
		{
			if (!(ft_quick_sortv3(lst, size)))
				return (ft_clean_abort(&lst, 1, 1));
		}
		ft_print_instructions(lst->st_instruct);
		// if (fl->count == 1)
		// {
		// 	ft_printf("{green}%i\n{reset}", ft_stack_size(instruct_set));
		// }
		// ft_printf("avant del lst\n");
		st_del(&lst);
		
		// ft_printf("apres del lst\n");
	}
	return (0);
}
