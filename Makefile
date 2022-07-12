NAME = pipex

.PHONY: all bonus fclean clean re

$(NAME):
	gcc -Wall -Werror -Wextra ft_pipex.c ft_path.c ft_split.c ft_split_utils.c -o $(NAME)

all:	$(NAME)

bonus:
	gcc -Wall -Werror -Wextra ft_bonus.c ft_path.c ft_split.c ft_split_utils.c -o bonus

clean:
	@if [ -f "${NAME}" ]; then\
		rm ${NAME};\
		printf "rm %s\n" "${NAME}";\
	else\
		printf "%s Doesn't Exist so It Cannot Be Removed\n" "${NAME}";\
	fi

fclean:	clean
	@if [ -f "bonus" ]; then\
		rm bonus;\
		printf "rm bonus\n";\
	else\
		printf "bonus Doesn't Exist so It Cannot Be Removed\n";\
	fi

re:		fclean all bonus