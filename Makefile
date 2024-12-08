NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_atoi.c\
		ft_memset.c\
		ft_put_unsigned_nbr_fd.c\
		ft_putchar_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_strlen.c\
		character_conversion.c\
		hexadecimal_conversion.c\
		hexadecimal_conversion_bis.c\
		pointer_conversion.c\
		pointer_conversion_bis.c\
		string_conversion.c\
		unsigned_conversion.c\
		integer_conversion.c\
		integer_conversion_bis.c\
		process_conversions.c\
		process_flags.c\
		check_count.c\
		check_conversion_format.c\
		ft_printf.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(?)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus : all

clean : 
	rm -f $(OBJS) $(OBJSB)

fclean : clean
	rm -f $(NAME)

re : fclean all
