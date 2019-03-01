/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:42:46 by jergauth          #+#    #+#             */
/*   Updated: 2019/02/13 15:42:48 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void			*ft_clean_abort(t_stack **head)
{
	ft_stack_del(head);
	return (NULL);
}

static int			ft_check_args(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		if (!(ft_str_is_numeric(argv[i])) && argv[i][0] != '-'
				&& !ft_strchr(argv[i], ' '))
			return (0);
		i++;
	}
	return (1);
}

static int			ft_depack_args(char *args, t_stack **stack_a)
{
	char	**tab;
	size_t	len;
	size_t	i;
 
	if (!(tab = ft_strsplit(args, ' ')))
		return (0);
	len = ft_arrlen((void*)tab);
	i = 0;
	while (i < len)
	{
		if (!(ft_check_args(tab)))
		{
			ft_tabdel((void*)tab, len);
			return (0);
		}
		ft_stack_append(tab[i], stack_a);
		i++;
	}
	ft_tabdel((void*)tab, len);
	return (1);
}

static t_stack		*ft_build_stack(char **argv)
{
	t_stack	*stack_a;
	size_t	i;

	stack_a = NULL;
	i = 0;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "") == 0)
			return (0);
		if (ft_strchr(argv[i], ' ') != NULL)
		{
			if (!(ft_depack_args(argv[i], &stack_a)))
				return (ft_clean_abort(&stack_a));
		}
		else
		{
			if (!(ft_stack_append(argv[i], &stack_a)))
				return (ft_clean_abort(&stack_a));
		}
		i++;
	}
	return (stack_a);
}

t_stack				*ft_check_args_and_build_stack(t_options *fl, char **argv)
{
	t_stack	*stack_a;

	if (ft_strcmp(*argv, "-f") == 0)
	{
		argv++;
		if (!(fl->pathname = ft_strdup(*argv)))
			return (NULL);
		argv++;
	}
	if (!(ft_check_args(argv)))
		return (NULL);
	if (!(stack_a = ft_build_stack(argv)))
		return (NULL);
	return (stack_a);
}
