##
## Makefile for make in /home/geiger_a/PSU_2014_my_printf
## 
## Made by anthony geiger
## Login   <geiger_a@epitech.net>
## 
## Started on  Thu Nov 13 19:05:08 2014 anthony geiger
## Last update Tue Jan 13 11:13:38 2015 Anthony Geiger
##

CCLIB	= ar rc

RM      = rm -f

NAME    = ./../libmy.a

CFLAGS  += -Wextra -Wall -Werror
CFLAGS  += -ansi -pedantic
CFLAGS  += -I./include

SRCS    = printf/my_putnbr.c \
	  printf/my_putstr.c \
	  printf/case_l.c \
	  printf/case_printf_aff.c \
	  printf/case_printf_convert.c \
	  printf/case_printf_nb.c \
	  printf/convert_base_16.c \
	  printf/convert_base_8.c \
	  printf/convert_base_deci.c \
	  printf/convert_base_unsigned.c \
	  printf/my_printf.c \
          printf/convert_base_deci.c \
	  printf/my_putchar.c \
	  printf/my_unputnbr.c \
	  str/my_word_in_tab.c \
	  str/my_strlen.c \
	  str/my_strcpy.c \
	  str/my_strdup.c \
	  str/my_strcmp.c \
	  str/my_spe_in_tab.c \
	  str/get_next_line.c \
	  str/my_strncmp.c \
	  str/my_putnstr.c \
	  str/my_strndup.c \
	  str/my_strncpy.c \
	  str/my_strnsdup.c \
	  str/my_strnscpy.c \
	  str/remove_str_in_tab.c \
	  str/my_tablen.c \
	  str/my_strglen.c \
	  str/str_cat.c

OBJS    = $(SRCS:.c=.o)

SRCS	:= $(addprefix src/, $(SRCS))


all: $(NAME)

$(NAME): $(OBJS)
	$(CCLIB) $(NAME) $(OBJS)
	ranlib $(NAME)
	cp include/my.h ../../include/

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
