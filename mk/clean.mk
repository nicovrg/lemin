# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    clean.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 23:51:03 by nivergne          #+#    #+#              #
#    Updated: 2019/10/20 01:04:01 by nicolasv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# clean_lib:

clean:
	@make -C libft clean
	@/bin/rm -fr obj

fclean: clean
	@make -C libft fclean
	@echo "$(CYAN)$(BOLD)LEMIN			$(BLUE)bin$(END)$(RED)		[delete]$(END)"
	@/bin/rm -f $(NAME)