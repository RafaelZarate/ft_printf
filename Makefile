MAKE = make -C
NAME = libftprintf.a
LIB = src/libft/
CFLAGS = -Wall -Wextra -Werror -c
CC = gcc

#When compiling. you need to add your .a lib
CFILES = src/ft_printf.c \
        src/scanners.c \
		src/handlers_1.c \
		src/handlers_2.c \
		src/handlers_3.c \
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
	@$(CC) $(CFLAGS) $(CFILES)
	@cp src/libft/libft.a $(NAME)
	@ar rcs $(NAME) *.o
	@echo "PRINTF: Successfull compilation"
	

clean:
	@$(LIBC)
	@/bin/rm -f *.o
	@echo "PRINTF: Removed .o files"

fclean: clean
	@$(LIBF)
	@/bin/rm -f $(OBJECTS) $(NAME) *.a
	@echo "PRINTF: Removed exacutable & .o files"

re: fclean all
