MAKE = make -C
NAME = printf
LIB = src/libft/
CFLAGS = -Wall -Wextra -Werror
CC = clang

#When compiling. you need to add your .a lib
CFILES = $(LIB)/libft.a \
        main.c \
		src/ft_printf.c \
        src/arg_scanner.c \
        src/scanners.c \
		src/handlers.c \
		src/arg_handler.c \
		src/utilities_1.c

#These options are here in case the lib needs to be recompiled.
#LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
LIBM = $(MAKE) $(LIB)
LIBR = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean
OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@$(LIBM)
	@$(CC) $(CFLAGS) -I. -o $(NAME) $(CFILES)
	@echo "PRINTF: Successfull compilation"
	

clean:
	@$(LIBC)
	@/bin/rm -f $(OBJECTS) printf:.o
	@echo "PRINTF: Removed .o files"

fclean:
	@$(LIBF)
	@/bin/rm -f $(OBJECTS) $(NAME)
	@echo "PRINTF: Removed exacutable & .o files"

re: fclean all
