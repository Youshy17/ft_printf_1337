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
		ft_put_unsigned_nbr_fd.c\
		check_count.c\
		ft_printf.c

SRCSB = ft_atoi.c\
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
		ft_put_unsigned_nbr_fd.c\
		check_count.c\
		ft_printf_bonus.c

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(?)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus : fclean $(OBJSB)
	ar rcs $(NAME) $(OBJSB)

clean : 
	rm -rf $(OBJS) $(OBJSB)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all re clean fclean
