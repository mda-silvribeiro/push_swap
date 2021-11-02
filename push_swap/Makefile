NAME =	pushswap

LIB =	./includes/

D_SRCS =		srcs/

D_OBJS =		./

SRC  =  push_swap.c \
		utils/utils.c \
		utils/free.c \
		utils/aux.c \
		utils/tools.c \
		utils/sort.c \
		utils/error.c \
		utils/big_sort.c \
		operations/swap.c \
		operations/push.c \
		operations/rotation.c \
		operations/rev_rotation.c

GCC =			gcc

SANITIZE =		-fsanitize=address

FLAGS =			-Wall -Wextra -Werror

RM =			rm -rf
				
SRCS =			$(addprefix $(D_SRCS), $(SRC))

COMPIL =		$(SANITIZE) $(FLAGS)

OBJS =			$(SRCS:.c=.o)

all:			$(NAME)

$(NAME) :		$(OBJS)
				@make -C ./libft
				@cp ./libft/libft.a libft.a
				$(GCC) $(COMPIL) -I $(LIB) $(OBJS) -o $(NAME)

%.o: %.c
				@gcc $(FLAGS) -I $(LIB) -c $< -o $@

bonus:

norm:
				norminette $(D_SRCS)
				norminette $(LIB)

clean:
				$(RM) $(OBJS)

fclean:			clean
				@make fclean -C ./libft/
				$(RM) libft.a
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all, clean, fclean, re, bonus
