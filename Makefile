##
## Makefile for make in /home/geiger_a/Makefile
## 
## Made by anthony geiger
## Login   <geiger_a@epitech.net>
## 
## Started on  Sat Jan  3 12:39:16 2015 anthony geiger
## Last update Thu Jan 15 20:35:43 2015 Anthony Geiger
##

RM	= rm -f

DEBUG	= 0

VERIF	= 0

CC	= gcc

NAME	= mysh

LIBMY   = lib/my/

SRCS	= mysh.c \
	  my_aff_env.c \
	  main_alias.c \
	  tab_fonc.c \
	  env_case.c \
	  my_prompt.c \
	  case_tab.c

SRCS_DIR	= src/

SRCS	:= $(addprefix $(SRCS_DIR), $(SRCS))

OBJS	= $(SRCS:.c=.o)

CFLAGS  = -I./include/
CFLAGS  += -Wall -Wextra -W
CFLAGS  += -pedantic

LDFLAGS = -L./lib/
LDFLAGS += -lmy


ifeq ($(DEBUG), 1)
        CFLAGS  += -g -std=c99
        CC      := clang -Weverything
endif

ifeq ($(VERIF), 1)
        CFLAGS  += -g -std=c99
        LDFLAGS += -lstdc++
        CC      := gcc
endif


all: dependency $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

dependency:
	make -C $(LIBMY)

docs:
	doxygen

re:	fclean all

clean:
	$(RM) $(OBJS)
	make -C $(LIBMY) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBMY) fclean

.PHONY: all clean fclean re dependency docs
