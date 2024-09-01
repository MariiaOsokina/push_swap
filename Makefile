NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Werror -Wextra
SRC_PATH = src/
OBJ_PATH = obj/
SRC     = apply_best_oper_2.c ft_split.c   oper_re_rotate.c  parse_args_2.c\
			sort_from_a_to_b.c stack_utils_2.c apply_best_oper.c ft_substr.c\
			oper_rotate.c  parse_args.c sort_from_b_to_a_2.c stack_utils.c\
			best_nbr_result.c    oper_push.c\
			oper_swap.c push_swap.c     sort_from_b_to_a.c
SRCS    = $(addprefix $(SRC_PATH), $(SRC))
OBJ     = $(SRC:.c=.o)
OBJS    = $(addprefix $(OBJ_PATH), $(OBJ))
all: $(OBJ_PATH) $(NAME) 
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean:
	@rm -rf $(OBJ_PATH)
fclean: clean
	@rm -f $(NAME)
re: fclean all
test2:              $(NAME) 
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l
test3:              $(NAME) 
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l
test5:              $(NAME) 
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l
test100:            $(NAME) 
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l
test500:            $(NAME) 
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l
.PHONY: all clean fclean re test2 test3 test5 test100 test500

