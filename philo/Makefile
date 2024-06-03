# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aheitz <aheitz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 11:09:29 by aheitz            #+#    #+#              #
#    Updated: 2024/06/03 21:57:21 by aheitz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	* --------------- The name of the program executable --------------- *	//
NAME		= philo

#	* ------------- Flags and other compilation information ------------- *	//
CFLAGS		= -Wall -Wextra -Werror -pthread -g3
#	? - Variable to prevent information printed when called recursively - ?	//
MAKEFLAGS	+= --no-print-directory
ARGV		= ""

#	* ----------------- Folders and subfolders variable ----------------- *	//
UTILITIES	= ./utilities

#	* ---------------------- Code and binary files ---------------------- *	//
SRCS		= ./main.c \
			./monitoring.c \
			./parameters.c \
			./routine.c \
			./sit.c \
			$(UTILITIES)/allocation.c \
			$(UTILITIES)/print_stderr.c
OBJS		= $(SRCS:.c=.o)

#	* ----- The different color variables for information printing ----- *	//
RESET		= \033[0m
RED			= \033[0;31m
GREEN		= \033[0;32m
BLUE		= \033[0;34m
BRED		= \033[1;31m
BGREEN		= \033[1;32m
UWHITE		= \033[4;37m
ON_RED		= \033[41m

#	* ----------------- Project rules and instructions ----------------- *	//
#	? -------- The main instruction for obtaining the executable -------- ?	//
all: $(NAME)
	@echo "$(BGREEN)Philosophers project ready for launch!$(RESET)"

#	? ---- The rule making the executable, by compiling binary files ---- ?	//
$(NAME): $(OBJS)
	@echo -n "Generation of executable $(UWHITE)$(NAME)$(RESET): "
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(GREEN)done$(RESET)."

#	? ------- The rule for transforming code files into binaries ------- ?	//
%.o: %.c
	@echo -n "Compilation of $(BLUE)$<$(RESET): "
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)done$(RESET)."

#	? ----------- The instruction to delete all binary files ----------- ?	//
clean:
	@echo -n "$(UWHITE)Cleaning up binary files:$(RESET) "
	@$(RM) $(OBJS)
	@echo "$(GREEN)done$(RESET)."

#	? ------- The instruction to delete binaries and executables ------- ?	//
fclean: clean
	@echo -n "$(UWHITE)Cleaning the executable file:$(RESET) "
	@$(RM) $(NAME)
	@echo "$(GREEN)done$(RESET)."

#	? ----- Additional instruction to send to Git more efficiently ----- ?	//
git:
	@$(MAKE) fclean
	@$(MAKE) norminette
	@echo "$(UWHITE)Starting the git upload procedure:$(RESET)"
	@git add ./..
	@git commit
	@git push all main
	@echo "$(GREEN)Done$(RESET)!"

#	? - Additional instruction to check the Norm and its color returns - ?	//
norminette:
	@echo "$(UWHITE)Norm testing launched:$(RESET)" \
	&& norminette \
	| awk '{ \
	if (/Error/) \
		if (/program/) \
			print "$(BRED)" $$0 "$(RESET)"; \
		else \
			print "$(RED)" $$0 "$(RESET)"; \
		else \
			print "$(BGREEN)" $$0 "$(RESET)"; \
	}' > norm.log \
	&& if grep -q "Error" norm.log; then \
		cat norm.log; \
		rm norm.log; \
		echo "$(ON_RED)Norm errors detected, process stopped!$(RESET)"; \
			exit 1; \
	else \
		cat norm.log; \
		echo "$(GREEN)All files are compliant.$(RESET)"; \
		rm norm.log; \
	fi

#	? ------ The instruction to clean up and recompile the project ------ ?	//
re: fclean all

#	? - Additional instruction to check memory leaks within the project - ?	//
valgrind: all
		@echo "$(UWHITE)Launching Valgrind on the project:$(RESET)"
		@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
				./$(NAME) $(ARGV)
		@echo "$(GREEN)Done$(RESET)."

#	? ---- The rule for prioritizing any instruction to the filename ---- ?	//
.PHONY: all, clean, fclean, git, norminette, re, valgrind