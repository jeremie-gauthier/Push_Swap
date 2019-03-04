/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 10:33:30 by jergauth          #+#    #+#             */
/*   Updated: 2019/02/14 10:33:31 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_clean_abort(char **line)
{
	ft_strdel(line);
	return (0);
}

static int	ft_is_a_known_word(char *instruction)
{
	char	*white_list[INSTRUCTIONS_SET];
	size_t	i;

	i = 0;
	white_list[0] = "sa";
	white_list[1] = "sb";
	white_list[2] = "ss";
	white_list[3] = "ra";
	white_list[4] = "rb";
	white_list[5] = "rr";
	white_list[6] = "rra";
	white_list[7] = "rrb";
	white_list[8] = "rrr";
	white_list[9] = "pa";
	white_list[10] = "pb";
	while (i < INSTRUCTIONS_SET)
	{
		if (ft_strcmp(instruction, white_list[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int			ft_read_stdin(t_st *lst)
{
	char	*line;
	int		ret;
	t_stack	*new;
	int		fd;

	fd = 0;
	if (lst->opt_fl->pathname != NULL)
	{
		if ((fd = ft_safe_open(lst->opt_fl->pathname)) == -1)
			return (0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		if ((ret = ft_is_a_known_word(line)) == -1)
			return (ft_clean_abort(&line));
		if (!(new = ft_stack_new(ret)))
			return (ft_clean_abort(&line));
		ft_stack_push_back(&lst->st_instruct, new);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (ft_safe_close(fd, lst->opt_fl->pathname) == -1)
		return (0);
	return (1);
}
