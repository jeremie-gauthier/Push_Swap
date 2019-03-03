/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:30:49 by jergauth          #+#    #+#             */
/*   Updated: 2019/03/03 13:30:49 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		ft_clean_abort(char **str, const int ret)
{
	ft_strdel(str);
	return (ret);
}

static size_t	read_swap_and_rotate(char *ret, const int nb)
{
	size_t	i;

	i = 0;
	if (nb >= 0 && nb <= 2)
	{
		ret[i++] = 's';
		if (nb == 0)
			ret[i++] = 'a';
		else if (nb == 0)
			ret[i++] = 'b';
		else
			ret[i++] = 's';
	}
	else if (nb >= 3 && nb <= 5)
	{
		ret[i++] = 'r';
		if (nb == 3)
			ret[i++] = 'a';
		else if (nb == 4)
			ret[i++] = 'b';
		else
			ret[i++] = 'r';
	}
	return (i);
}

static size_t	read_rev_rot_and_push(char *ret, const int nb)
{
	size_t	i;

	i = 0;
	if (nb >= 6 && nb <= 8)
	{
		ret[i++] = 'r';
		ret[i++] = 'r';
		if (nb == 6)
			ret[i++] = 'a';
		else if (nb == 7)
			ret[i++] = 'b';
		else
			ret[i++] = 'r';
	}
	else if (nb >= 9 && nb <= 10)
	{
		ret[i++] = 'p';
		if (nb == 9)
			ret[i++] = 'a';
		else
			ret[i++] = 'b';
	}
	return (i);
}

static int		print_in_file(const t_st *lst, const char *ret)
{
	int	fd;

	if (!(fd = ft_safe_open(lst->opt_fl->pathname)))
		return (0);
	ft_dprintf(fd, "%s", ret);
	if (!(fd = ft_safe_close(fd, lst->opt_fl->pathname)))
		return (0);
	return (1);
}

int				ft_print_instructions(t_st *lst)
{
	char	*ret;
	size_t	i;
	t_stack	*set;

	set = lst->st_instruct;
	if (!(ret = (char*)malloc(sizeof(*ret) * (ft_stack_size(set) * 4) + 1)))
		return (0);
	i = 0;
	while (set)
	{
		i += read_swap_and_rotate(ret + i, set->nb);
		i += read_rev_rot_and_push(ret + i, set->nb);
		ret[i++] = '\n';
		set = set->next;
	}
	ret[i] = '\0';
	if (lst->opt_fl->pathname != NULL)
	{
		if (!print_in_file(lst, ret))
			return (ft_clean_abort(&ret, 0));
	}
	else
		ft_dprintf(1, "%s", ret);
	ft_strdel(&ret);
	return (1);
}
