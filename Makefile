testing = bin/test.exe
headers = -I./headers/
cflages = -Wall -Wextra $(headers)


$(testing) : objs/test.o objs/arrStr.o
	gcc -o $@ $^

objs/test.o : src/test.c
	gcc -c $(cflages) -o $@ $<

objs/arrStr.o : src/arrStr.c
	gcc -c $(cflages) -o $@ $<




clean :
	rm bin/*.exe
	rm objs/*.o

folder:
	mkdir ./objs/ ./bin/

play :
	@bin/test.exe

playTest :
	@echo "run the program with valgrind :\n"
	valgrind bin/test.exe
