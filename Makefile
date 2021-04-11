C_FILES = reader.c  follow_flow.c generate_group.c enqueue_paths.c get_path_copy.c extend_first_path2.c extend_first_path.c \
		 ft_queue.c init_queue.c launch_bfs_corrector.c launch_bfs.c pick_right_paths.c add_child_head.c add_paths.c \
		 pass_ants.c prepare_queue.c put_instructions2.c extend_first_path3.c path_length.c  connect_funcs.c \
		 follow_flow1.c reader1.c reader2.c

C_OBJS = $(C_FILES:.c=.o)

C_FILE_LIM_IN = lim_in.c

O_FILE_LIM_IN = lim_in.o

HEADER = lim_in.h

LIB = libft.a

LIB_PATH = libft

NAME = lem-in

CC = gcc

C_FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(LIB_PATH)/$(LIB) $(C_OBJS) $(O_FILE_LIM_IN)
	$(CC) -o $(NAME) $(C_OBJS) $(O_FILE_LIM_IN) $(LIB_PATH)/$(LIB)


$(C_OBJS) : %.o : %.c $(HEADER)
	$(CC) $(C_FLAGS) -c $< -o $@

$(O_FILE_LIM_IN) : %.o : %.c $(HEADER)
	$(CC) $(C_FLAGS) -c $< -o $@

$(LIB_PATH)/$(LIB):
	make -C $(LIB_PATH)

clean :
	make clean -C $(LIB_PATH)
	rm -rf $(C_OBJS) $(O_FILE_LIM_IN)

fclean : clean
	make fclean -C $(LIB_PATH)
	rm -rf $(NAME)

re : fclean all	
