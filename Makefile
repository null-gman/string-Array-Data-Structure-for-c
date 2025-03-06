bin = bin/test
headers = -I./headers/
cflages = -Wall -Wextra $(headers)

$(bin) : objs/test.o objs/arrStr.o objs/input.o objs/str.o
	gcc -o $@ $^

objs/test.o : src/test.c
	gcc -c $(cflages) -o $@ $<

objs/arrStr.o : src/arrStr.c
	gcc -c $(cflages) -o $@ $<

objs/input.o :	src/myLibs/input.c
	gcc -c $(cflages) -o $@ $<


objs/str.o : src/myLibs/str.c
	gcc -c $(cflages) -o $@ $<

clean :
	rm bin/*
	rm objs/*



play :
	@bin/test

playTest :
	@echo "run the program with valgrind :\n"
	valgrind bin/test
