NAME = libft.a

HEADER = libft.h

C_FILES = ft_atoi.c       ft_lstiter.c    ft_putchar_fd.c ft_strdup.c     ft_strnequ.c\
		ft_bzero.c      ft_lstlen.c     ft_putendl.c    ft_strequ.c     ft_strnew.c\
		ft_isalnum.c    ft_lstmap.c     ft_putendl_fd.c ft_strisplit.c  ft_strnstr.c\
		ft_isalpha.c    ft_lstnew.c     ft_putnbr.c     ft_striter.c    ft_strrchr.c\
		ft_isascii.c    ft_memalloc.c   ft_putnbr_fd.c  ft_striteri.c   ft_strreplace.c\
		ft_isdigit.c    ft_memccpy.c    ft_putstr.c     ft_strjoin.c    ft_strsplit.c\
		ft_isprint.c    ft_memchr.c     ft_putstr_fd.c  ft_strlcat.c    ft_strstr.c\
		ft_itoa.c       ft_memcmp.c     ft_strcat.c     ft_strlen.c     ft_strsub.c\
		ft_lstadd.c     ft_memcpy.c     ft_strchr.c     ft_strmap.c     ft_strtrim.c\
		ft_lstdel.c     ft_memdel.c     ft_strclr.c     ft_strmapi.c    ft_tolower.c\
		ft_lstdelone.c  ft_memmove.c    ft_strcmp.c     ft_strncat.c    ft_toupper.c\
		ft_lstidel.c    ft_memset.c     ft_strcpy.c     ft_strncmp.c    ft_malloc.c\
		ft_lstinsert.c  ft_putchar.c    ft_strdel.c     ft_strncpy.c	get_next_line.c\
		ft_read_line.c   p_malloc.c
O_FILES = ft_atoi.o       ft_lstiter.o    ft_putchar_fd.o ft_strdup.o     ft_strnequ.o\
		ft_bzero.o      ft_lstlen.o     ft_putendl.o    ft_strequ.o     ft_strnew.o\
		ft_isalnum.o    ft_lstmap.o     ft_putendl_fd.o ft_strisplit.o  ft_strnstr.o\
		ft_isalpha.o    ft_lstnew.o     ft_putnbr.o     ft_striter.o    ft_strrchr.o\
		ft_isascii.o    ft_memalloc.o   ft_putnbr_fd.o  ft_striteri.o   ft_strreplace.o\
		ft_isdigit.o    ft_memccpy.o    ft_putstr.o     ft_strjoin.o    ft_strsplit.o\
		ft_isprint.o    ft_memchr.o     ft_putstr_fd.o  ft_strlcat.o    ft_strstr.o\
		ft_itoa.o       ft_memcmp.o     ft_strcat.o     ft_strlen.o     ft_strsub.o\
		ft_lstadd.o     ft_memcpy.o     ft_strchr.o     ft_strmap.o     ft_strtrim.o\
		ft_lstdel.o     ft_memdel.o     ft_strclr.o     ft_strmapi.o    ft_tolower.o\
		ft_lstdelone.o  ft_memmove.o    ft_strcmp.o     ft_strncat.o    ft_toupper.o\
		ft_lstidel.o    ft_memset.o     ft_strcpy.o     ft_strncmp.o    ft_malloc.o\
		ft_lstinsert.o  ft_putchar.o    ft_strdel.o     ft_strncpy.o	get_next_line.o\
		ft_read_line.o  p_malloc.o

all: $(NAME)
$(NAME): $(O_FILES)
	ar rc $(NAME) $(O_FILES)

$(O_FILES) : %.o : %.c $(HEADER)
	gcc -c -Wall -Wextra -Werror $<
clean:
	rm -rf $(O_FILES)

fclean: clean
	rm -rf $(NAME)
re: fclean $(NAME)
