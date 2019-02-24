# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jergauth <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/26 19:46:18 by jergauth          #+#    #+#              #
#    Updated: 2018/12/26 19:46:20 by jergauth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P1	=	checker
NAME_P2	=	push_swap

CHKR_PATH	=	dir_checker
RESOLV_PATH	=	dir_push_swap

LIB_PATH	=	ft_printf/

HDR_PATH	=	includes

LIB			=	$(LIB_PATH)libftprintf.a

DIR_O		=	temporary
DIR_O_P1	=	$(DIR_O)/tmp_checker
DIR_O_P2	=	$(DIR_O)/tmp_push_swap

SOURCES_P1	=	main.c	\
				stack_operations.c	\
				check_args.c	\
				read_stdin.c	\
				execute_instructions.c	\
				memory.c

SRCS_P1	=	$(addprefix $(CHKR_PATH)/,$(SOURCES_P1))
OBJS_P1	=	$(addprefix $(DIR_O_P1)/,$(SOURCES_P1:.c=.o))

SOURCES_P2	=	main.c	\
				stack_operations.c	\
				check_args.c	\
				dumb_sort.c	\
				quick_sort.c	\
				memory.c	\
				quick_sortv2.c

HDR		=	$(HDR_PATH)/push_swap.h

SRCS_P2	=	$(addprefix $(RESOLV_PATH)/,$(SOURCES_P2))
OBJS_P2	=	$(addprefix $(DIR_O_P2)/,$(SOURCES_P2:.c=.o))

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

CLEAN	=	clean

all		:	$(NAME_P1) $(NAME_P2)

$(LIB)	:
			@make -C $(LIB_PATH)

$(NAME_P1)	:	$(OBJS_P1) $(HDR) $(LIB) Makefile
				@$(CC) $(CFLAGS) $(LIB) -o $(NAME_P1) $(SRCS_P1) -I $(HDR)
				@echo "Push_swap	: checker has been successfully created."

$(NAME_P2)	:	$(OBJS_P2) $(HDR) $(LIB) Makefile
				@$(CC) $(CFLAGS) $(LIB) -o $(NAME_P2) $(SRCS_P2) -I $(HDR)
				@echo "Push_swap	: push_swap has been successfully created."
			

$(DIR_O_P1)/%.o: $(CHKR_PATH)/%.c
		@mkdir -p temporary
		@mkdir -p temporary/tmp_checker
		@$(CC) $(CFLAGS) -I $(HDR) -o $@ -c $<

$(DIR_O_P2)/%.o: $(RESOLV_PATH)/%.c
		@mkdir -p temporary/tmp_push_swap
		@$(CC) $(CFLAGS) -I $(HDR) -o $@ -c $<

clean	:
			@$(RM) $(OBJS_P1) $(OBJS_P2)
			@rm -rf $(DIR_O)
			@make clean -C $(LIB_PATH)
			@echo "Push_swap	: All .o files have been deleted."

fclean	:	clean
			@make fclean -C $(LIB_PATH)
			@$(RM) $(NAME_P1) $(NAME_P2) $(LIB)
			@echo "Push_swap	: exe have been deleted."

re		:	fclean all

.PHONY:	all clean fclean re
