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
# define CLEAR	"\e[1;1H\e[2J"

# define DEBUG	0
# define SHOW_NB	0

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
	unsigned int	depth		: 5;
	unsigned int	sorted	: 1;
}				t_st;

t_options		*init_options(void);
t_st			*init_stacks(void);
void			st_del(t_st **lst);
void			ft_push_stack(t_stack **leave, t_stack **receive);
t_stack			*ft_check_args_and_build_stack(t_options *fl, char **argv);
t_stack			*ft_read_stdin(t_options *opt);
int				ft_start_instructions(t_stack **stack_a,
						t_stack *instructions_set, t_options *fl);
int				ft_dumb_sort(t_st *lst, unsigned int size);
int				ft_quick_sort(t_st *lst, unsigned int size);
int    			ft_insertion_sort(t_st *lst, unsigned int size);
int				ft_stack_append(char *str, t_stack **stack_a);
int				ft_visualizer(t_st *lst, void (*f[3])(t_stack**));

#endif
