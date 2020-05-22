
NAME		:= ft_ls
COMPILER	:= gcc
SRC			:= ft_ls.c type_mode_handle.c \
				get_content_name.c additional.c
INCLUDES	:= -I ../ft_printf -I .
LIB			:= ../ft_printf/libftprintf.a

$(NAME):
	$(COMPILER) -o $(NAME) $(SRC) $(INCLUDES) $(LIB) -g

re:fclean $(NAME)

fclean:
	rm -f $(NAME)
