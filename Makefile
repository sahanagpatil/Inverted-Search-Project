SRCS = main.c validate.c create_database.c display_database.c save_database.c search_database.c update_database.c

OBJ = $(SRCS:.c=.o)

a.out: $(OBJ)
	gcc -Wall -o $@ $^

%.o: %.c header.h
	gcc -Wall -c $<

clean:
	rm -f *.o a.out