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

static int		ft_safe_open(const char *pathname)
{
	int		fd;

	if ((fd = open(pathname, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR)) < 0)
	{
		ft_printf("{red}Fail to open {bold}%s{reset}{red}, write in stdout :{reset}\n", pathname);
		return (1);
	}
	return (fd);
}

static int		ft_safe_close(const int fd, const char *pathname)
{
	if (close(fd) < 0)
	{
		ft_printf("{red}Fail to close {bold}%s{reset}\n", pathname);
		return (-1);
	}
	return (1);
}

int		ft_print_instructions(t_stack *instruct_set, t_options *fl)
{
	char	*ret;
	size_t	i;
	int		fd;

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
	if (fl->pathname != NULL)
	{
		if (!(fd = ft_safe_open(fl->pathname)))
			return (0);
		ft_dprintf(fd, "%s", ret);
		if (!(fd = ft_safe_close(fd, fl->pathname)))
			return (0);
	}
	else
		ft_dprintf(1, "%s", ret);
	// ft_putstr(ret);
	ft_strdel(&ret);
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
			if (!(ft_quick_sortv2(lst, size)))
				return (ft_clean_abort(&lst, 1, 1));
		}
		ft_print_instructions(lst->st_instruct, lst->opt_fl);
		st_del(&lst);
	}
	return (0);
}
