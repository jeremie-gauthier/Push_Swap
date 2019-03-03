#include "../includes/push_swap.h"

int		ft_safe_open(const char *pathname)
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

int		ft_safe_close(const int fd, const char *pathname)
{
	if (close(fd) < 0)
	{
		ft_printf("{red}Fail to close {bold}%s{reset}\n", pathname);
		return (-1);
	}
	return (1);
}
