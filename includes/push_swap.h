/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:24:08 by jergauth          #+#    #+#             */
/*   Updated: 2019/02/16 11:24:09 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf/ft_printf.h"

# define INSTRUCTIONS_SET	11

typedef struct	s_options
{
	char			*pathname;
	useconds_t		time;
	unsigned short	counter;
	unsigned short	visu	: 1;
	unsigned short	count	: 1;
}				t_options;

typedef struct	s_st
{
	t_stack			*st_a;
	t_stack			*st_b;
	t_stack			*st_instruct;
	t_options		*opt_fl;
	unsigned int	sorted;
}				t_st;

int				ft_safe_open(const char *pathname);
int				ft_safe_close(const int fd, const char *pathname);
t_options		*init_options(void);
t_st			*init_stacks(void);
void			st_del(t_st **lst);
int				ft_parse_options(t_st *lst, char ***argv);
int				ft_stack_append(char *str, t_stack **stack_a);
int				ft_check_args_and_build_stack(t_st *lst, char **argv);
int				ft_read_stdin(t_st *lst);
int				ft_start_instructions(t_st *lst);
int				ft_print_instructions(t_st *lst);

/*
**	STACK OPERATIONS
*/

void			ft_push_stack(t_stack **leave, t_stack **receive);
int				ft_push_stack_and_write(t_st *lst, int state);
int				ft_rotate_and_write(t_st *lst, int state);
int				ft_rev_rotate_and_write(t_st *lst, int state);
int				ft_swap_and_write(t_st *lst, int state);

/*
**	SORT OPERATIONS
*/

int				ft_quick_sort(t_st *lst, unsigned int size, int state);
int				ft_insertion_sort(t_st *lst, unsigned int size, const int min,
					const int max);
int				ft_visualizer(t_st *lst, void (*f[3])(t_stack**));
int				ft_sort_deepest_stack(t_st *lst, unsigned int size, int state);
int				change_last_instruction(t_stack *instr_set, int supposed_val,
					int new_val);
int				ft_sort_size_one(t_st *lst, int state);
int				ft_sort_size_two(t_st *lst, int state);
int				ft_sort_size_three_empty(t_st *lst, int state);
int				ft_top_is_min(t_st *lst, unsigned int *size);
int				ft_other_cases(t_st *lst, unsigned int *size);
int				ft_mid_is_min(t_st *lst, unsigned int *size);
int				ft_sort_size_three_full(t_st *lst, int state);
int				ft_top_is_min_full(t_st *lst);
int				ft_top_is_median_value(t_st *lst);
int				ft_bot_is_median_value(t_st *lst);
int				ft_other_cases_full(t_st *lst);
int				ft_mid_is_max_full_b(t_st *lst, unsigned int *size);
int				ft_other_cases_full_b(t_st *lst, unsigned int *size);

#endif
