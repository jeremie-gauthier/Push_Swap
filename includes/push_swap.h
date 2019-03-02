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

#include <sys/types.h> //
#include <sys/stat.h> //
#include <fcntl.h> //
#include <stdio.h> //

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
	unsigned int	depth	: 5;
	unsigned int	sorted	: 1;
}				t_st;

t_options		*init_options(void);
t_st			*init_stacks(void);
void			st_del(t_st **lst);
void			ft_push_stack(t_stack **leave, t_stack **receive);
int				ft_push_stack_and_write(t_st *lst, int state);
int				ft_rotate_and_write(t_st *lst, int state);
int				ft_rev_rotate_and_write(t_st *lst, int state);
int				ft_swap_and_write(t_st *lst, int state);

t_stack			*ft_check_args_and_build_stack(t_options *fl, char **argv);
t_stack			*ft_read_stdin(t_options *opt);
int				ft_start_instructions(t_st *lst);
int				ft_dumb_sort(t_st *lst, unsigned int size);
int				ft_quick_sort(t_st *lst, unsigned int size, int state);
int    			ft_insertion_sort(t_st *lst, unsigned int size);
int				ft_stack_append(char *str, t_stack **stack_a);
int				ft_visualizer(t_st *lst, void (*f[3])(t_stack**));
int				ft_sort_deepest_stack(t_st *lst, unsigned int size, int state);
int				change_last_instruction(t_stack *instr_set, int supposed_val, int new_val);

int    			ft_sort_size_one(t_st *lst, int state);
int     		ft_sort_size_one(t_st *lst, int state);
int        		ft_sort_size_three_empty(t_st *lst, int state);
int       	  	ft_sort_size_three_full(t_st *lst, int state);

int	ft_sort_substack(t_stack **st, t_stack **opp_st, unsigned int size, int state, t_stack **instr_set);

#endif
