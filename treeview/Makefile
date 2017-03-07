CC=gcc
CFLAGS=`pkg-config --cflags --libs gtk+-2.0`
OBJS=treeview.o
%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS)

a.out:$(OBJS)
	$(CC) $< -o $@ $(CFLAGS)

.PHONY:
clean:
	rm *.o a.out -rf
