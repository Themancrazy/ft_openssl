# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anjansse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 21:57:22 by anjansse          #+#    #+#              #
#    Updated: 2019/06/07 18:37:47 by anjansse         ###   ########.fr        #
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
BASE64		=	base64.c
DES			=	des.c
DES_ECB		=	des_ecb.c
DES_CBC		=	des_cbc.c

SRCS		=	$(addprefix src/, $(GENERAL) $(addprefix md5/, $(MD5))\
				$(addprefix sha256/, $(SHA256)) $(addprefix sha512/,\
				$(SHA512)) $(addprefix sha224/, $(SHA224))\
				$(addprefix sha384/, $(SHA384)) $(addprefix des/, $(DES))\
				$(addprefix des_ecb/, $(DES_ECB)) $(addprefix des_cbc/,\
				$(DES_CBC)) $(addprefix base64/, $(BASE64)))

INCLUDES	=	-I include/

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

LLIB		=	libft.a

lib:
	@echo -n 'Compiling libft...'
	@make -C libft/ re
	@cp libft/libft.a .
	@echo "\t\x1b[92m✓\x1b[0m\n"

all: $(NAME)

$(NAME):
	@echo -n 'Compiling Program...'
	@cp libft/libft.a .
	@$(CC) $(CFLAG) $(SRCS) $(INCLUDES) $(LLIB) -o $(NAME)
	@echo "\t\x1b[92m✓✓\x1b[0m\n"
	@echo "\x1b[36m\x1b[1m****************************************************\
********"
	@echo "         ____   ____   ______ _   __ _____ _____  __\n\
  __/|_ / __ \ / __ \ / ____// | / // ___// ___/ / /   __/|_\n\
 |    // / / // /_/ // __/  /  |/ / \__ \ \__ \ / /   |    /\n\
/_ __|/ /_/ // ____// /___ / /|  / ___/ /___/ // /___/_ __| \n\
 |/   \____//_/    /_____//_/ |_/ /____//____//_____/ |/    \n\
************************************************************\x1b[0m\n"
	@echo "\x1b[1m\x1b[93mHASH FUNCTIONS USAGE: <command> <flag> <optional string | file>\n\x1b[0m"

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

re: fclean all

tot: totfclean totall
