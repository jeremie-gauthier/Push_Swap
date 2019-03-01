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

static void		*ft_clean_abort(t_stack **set, char *line)
{
	ft_stack_del(set);
	ft_strdel(&line);
	return (NULL);
}

static int		ft_safe_open(const char *pathname)
{
	int		fd;

	if ((fd = open(pathname, O_RDONLY)) < 0)
	{
		ft_printf("{red}Fail to open {bold}%s{reset}\n", pathname);
		return (-1);
	}
	if (read(fd, 0, 0) < 0)
	{
		ft_printf("{red}No data found in {bold}%s{reset}\n", pathname);
		return (-1);
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

static int		ft_is_a_known_word(char *instruction)
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

t_stack			*ft_read_stdin(t_options *opt)
{
	char	*line;
	int		ret;
	t_stack	*instructions_set;
	t_stack	*new;
	int		fd;

	fd = 0;
	if (opt->pathname != NULL)
	{
		if ((fd = ft_safe_open(opt->pathname)) == -1)
			return (NULL);
	}
	instructions_set = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if ((ret = ft_is_a_known_word(line)) == -1)
			return (ft_clean_abort(&instructions_set, line));
		if (!(new = ft_stack_new(ret)))
			return (ft_clean_abort(&instructions_set, line));
		ft_stack_push_back(&instructions_set, new);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (ft_safe_close(fd, opt->pathname) == -1)
		return (ft_clean_abort(&instructions_set, NULL));
	return (instructions_set);
}
