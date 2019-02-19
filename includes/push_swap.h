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

void		ft_push_stack(t_stack **leave, t_stack **receive);
t_stack		*ft_check_args_and_build_stack(char **argv);
t_stack		*ft_read_stdin(void);
int			ft_start_instructions(t_stack **stack_a,
					t_stack *instructions_set);
t_stack		*ft_dumb_sort(t_stack **stack_a, unsigned int size);
t_stack		*ft_quick_sort(t_stack **stack_a, unsigned int size);
int			ft_stack_append(char *str, t_stack **stack_a);

#endif
