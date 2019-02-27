#include "ft_printf/ft_printf/ft_printf.h"

int main(void)
{
	ft_printf("42 -> %u\n-42 -> %i\n{red}12345 -> %u\n-54321 -> %i\n", 42, -42, 12345, -54321);
	return (0);
}
