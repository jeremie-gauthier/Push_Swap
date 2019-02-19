#include "includes/push_swap.h"

int		main(void)
{
	t_stack	*s1;
	t_stack	*s2;
	t_stack	*s3;

	s1 = ft_stack_new(3);
	s2 = ft_stack_new(2);
	s3 = ft_stack_new(1);
	s1->next = s2;
	s2->next = s3;

	ft_putendl("\nInitial State Stack A:\n");
	ft_stack_push_front(&s1, ft_stack_new(0));
	ft_stack_print(s1);
	
	ft_putendl("\nThen Pop Top :\n");
	ft_stack_pop(&s1, 1);
	ft_stack_print(s1);

	ft_putendl("\nThen Swap Top :\n");
	ft_stack_swap_top(&s1);
	ft_stack_print(s1);

	ft_putendl("\nThen Rev Rotate :\n");
	ft_stack_rev_rotate(&s1);
	ft_stack_print(s1);


	t_stack	*ss1;

	ss1 = ft_stack_duplicate(s1);
	ft_putendl("\nDuplicate Stack A:\n");
	ft_stack_print(ss1);
	// t_stack	*ss2;
	// t_stack	*ss3;

	// ss1 = ft_stack_new(3);
	// ss2 = ft_stack_new(2);
	// ss3 = ft_stack_new(1);
	// ss1->next = ss2;
	// ss2->next = ss3;

	// ft_putendl("\nInitial State Stack B:\n");
	// ft_stack_push_front(&ss1, ft_stack_new(4));
	// ft_stack_print(ss1);

	// ft_putendl("\nThen Rev Rotate :\n");
	// ft_stack_rev_rotate(&ss1);
	// ft_stack_print(ss1);

	// ft_putendl("\nThen Swap Top :\n");
	// ft_stack_swap_top(&ss1);
	// ft_stack_print(ss1);

	// ft_putendl("\nState Stack A:");
	// ft_stack_print(s1);
	// ft_putendl("\nState Stack B:");
	// ft_stack_print(ss1);
	// ft_putendl("\nThen Push from A to B :");
	// ft_push_stack(&s1, &ss1);
	// ft_putendl("\nState Stack A:");
	// ft_stack_print(s1);
	// ft_putendl("\nState Stack B:");
	// ft_stack_print(ss1);

	ft_stack_del(&s1);
	ft_stack_del(&ss1);

	return (0);
}
