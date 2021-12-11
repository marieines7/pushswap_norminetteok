# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
BLUE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
PURPLE:="\033[34;1m"
# ==================



SRCS 	=./srcs/action_push.c \
	  ./srcs/action_reverse_rotate.c \
	  ./srcs/action_rotate.c \
	  ./srcs/action_swap.c \
	  ./srcs/algo_hundreds.c\
	  ./srcs/algo_less_than_5.c \
	  ./srcs/main.c \
	  ./srcs/parsing_get_right_nbs_into_stack.c \

UTILS =	  ./utils/utils_nbs.c \
	  ./utils/utils_parsing.c \
	  ./utils/utils_stack_1.c \
	  ./utils/utils_stack_2.c \

NAME	= push_swap

IDIR = ./includes/
OBJDIR = ./objs
UTILSDIR = ./utils
OBJ = $(OBJDIR)/*.o
RM		= rm -rf
CC		= clang
CFLAGS	= -Wall -Werror -Wextra

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<
				
${NAME}:${OBJ}
		$(CC) ${CFLAGS} -I $(IDIR) ${OBJ} ${UTILS} -o ${NAME}  
		@echo $(BLUE) "./push_swap" $(GREEN)[OK] $(EOF)

$(OBJ) : $(SRCS)
		@$(CC) -c $(CFLAGS) $(SRCS)
		$(RM) ./objs; mkdir ./objs
		mv *.o $(OBJDIR)
		@echo  $(PURPLE)"Creating objects and storing them in ./objs "$(GREEN)[OK] $(EOF)

all		: ${NAME}

clean	:
				${RM} ${OBJ}

fclean	:	clean
				${RM} ${NAME}
				@echo $(PURPLE)"Cleaning objects... "$(GREEN)[OK] $(EOF)

re		:	fclean all

.PHONY : all clean fclean re
