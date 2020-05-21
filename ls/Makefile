
NAME		:= ft_ls
COMPILER	:= gcc
SRC			:= ft_ls.c main.c get_name.c type_mode_handle.c
INCLUDES	:= -I ../ft_printf -I .
LIB			:= ../ft_printf/libftprintf.a

$(NAME):
	$(COMPILER) -o $(NAME) $(SRC) $(INCLUDES) $(LIB)

re:fclean $(NAME)

fclean:
	rm -f $(NAME)
