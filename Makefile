MAKE = make -C
NAME = printf
LIB = src/libft/
CFLAGS = -Wall -Wextra -Werror
CC = gcc

#When compiling. you need to add your .a lib
CFILES = $(LIB)/libft.a \
        main.c \
		src/ft_printf.c \
        src/arg_scanner.c \
		src/arg_handler.c

#These options are here in case the lib needs to be recompiled.
#LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
LIBM = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean
OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	$(LIBM)
	$(CC) $(CFLAGS) -I. -o $(NAME) $(CFILES)

clean:
	$(LIBC)
	/bin/rm -f $(OBJECTS) printf:.o

fclean:
	$(LIBF)
	/bin/rm -f $(OBJECTS) $(NAME)

re: fclean all