# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anjansse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 21:57:22 by anjansse          #+#    #+#              #
#    Updated: 2019/06/17 19:30:39 by anjansse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	ft_ssl
GENERAL		= 	ft_openssl.c process_stdio_cmd.c swap_endian.c error.c
MD5			=	md5.c md5_hash.c md5_utils.c process_functions.c
SHA256		=	sha256.c sha256_hash.c sha256_process_functions.c\
sha256_utils.c
SHA224		=	sha224.c sha224_hash.c
SHA384		=	sha384.c
SHA512		=	sha512.c sha512_hash.c sha512_process_functions.c\
				sha512_utils.c
BASE64		=	base64.c extra.c
DES			=	des.c

SRCS		=	$(addprefix src/, $(GENERAL) $(addprefix md5/, $(MD5))\
				$(addprefix sha256/, $(SHA256)) $(addprefix sha512/,\
				$(SHA512)) $(addprefix sha224/, $(SHA224))\
				$(addprefix sha384/, $(SHA384)) $(addprefix des/, $(DES))\
				$(addprefix base64/, $(BASE64)))

INCLUDES	=	-I include/

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

LLIB		=	libft.a

reprog: fclean all

all: $(NAME)

$(NAME):
	@echo -n 'Compiling DES Program...'
	@cp libft/libft.a .
	@$(CC) $(CFLAGS) $(SRCS) $(INCLUDES) $(LLIB) -o $(NAME)
	@echo "\t\x1b[92m✓✓\x1b[0m\n"
	@sleep 0.1
	@clear
	@echo "\x1b[36m\x1b[1m****************************************************\
**********"
	@echo "*         ____   ____   ______ _   __ _____ _____  __\t     *\n\
*  __/|_ / __ \ / __ \ / ____// | / // ___// ___/ / /   __/|_*\n\
* |    // / / // /_/ // __/  /  |/ / \__ \ \__ \ / /   |    /*\n\
*/_ __|/ /_/ // ____// /___ / /|  / ___/ /___/ // /___/_ __| *\n\
* |/   \____//_/    /_____//_/ |_/ /____//____//_____/ |/    *\n\
**************************************************************\x1b[0m\n"
	@echo "\x1b[1m\x1b[93mMOST FUNCTIONS USAGE: <command> <flag> <optional string | file>\n\x1b[0m"
	@echo "\x1b[1m\x1b[91m\x1b[1mNEED HELP? TYPE \"make help\"\n\x1b[0m"

lib:
	@echo -n 'Compiling libft...'
	@make -C libft/ re
	@cp libft/libft.a .
	@echo "\t\t\x1b[92m✓\x1b[0m\n"

totall: lib all

git:
	@git add .
	@git commit -m "$(C)"
	@git push

clean:
	@rm -rf build

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LLIB)
	@echo "\t\n\x1b[96mSSL \x1b[91mlibrary has been cleaned!\x1b[0m\n"

totfclean: fclean
	@make -C libft/ fclean
	@echo "\x1b[96mLibft has been cleaned.\x1b[0m\t\x1b[91mDon't forget to\
		recompile it...\n\x1b[0m"

re: totfclean totall

help:
	@clear
	@echo "\x1b[36m\x1b[1m****************************************************\
**********"
	@echo "*         ____   ____   ______ _   __ _____ _____  __\t     *\n\
*  __/|_ / __ \ / __ \ / ____// | / // ___// ___/ / /   __/|_*\n\
* |    // / / // /_/ // __/  /  |/ / \__ \ \__ \ / /   |    /*\n\
*/_ __|/ /_/ // ____// /___ / /|  / ___/ /___/ // /___/_ __| *\n\
* |/   \____//_/    /_____//_/ |_/ /____//____//_____/ |/    *\n\
**************************************************************\x1b[0m\n"
	@echo "\x1b[35m\x1b[1m{./ft_ssl\x1b[32m\tmd5\t\x1b[33m-<p(print)/q(quiet)/r(reverse)/s(string)>\x1b[35m}\n\
	{./ft_ssl\t\x1b[32msha224\t\x1b[33m-<p(print)/q(quiet)/r(reverse)/s(string)>\x1b[35m}\n\
	{./ft_ssl\t\x1b[32msha256\t\x1b[33m-<p(print)/q(quiet)/r(reverse)/s(string)>\x1b[35m}\n\
	{./ft_ssl\t\x1b[32msha384\t\x1b[33m-<p(print)/q(quiet)/r(reverse)/s(string)>\x1b[35m}\n\
	{./ft_ssl\t\x1b[32msha512\t\x1b[33m-<p(print)/q(quiet)/r(reverse)/s(string)>\x1b[35m}\n\
	{./ft_ssl\x1b[32m\tbase64\t\x1b[33m-<e(encrypt str)/i(encrypt file)/d(decrypt str)/o(decrypt file)>\x1b[35m}\n"

tot: totfclean totall
