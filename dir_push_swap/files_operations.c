/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:29:23 by jergauth          #+#    #+#             */
/*   Updated: 2019/03/03 13:29:24 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_safe_open(const char *pathname)
{
	int		fd;

	if ((fd = open(pathname, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR)) < 0)
	{
		ft_printf("{red}Fail to open {bold}%s{reset}{red}, \
			write in stdout :{reset}\n", pathname);
		return (1);
	}
	return (fd);
}

int		ft_safe_close(const int fd, const char *pathname)
{
	if (close(fd) < 0)
	{
		ft_printf("{red}Fail to close {bold}%s{reset}\n", pathname);
		return (-1);
	}
	return (1);
}
