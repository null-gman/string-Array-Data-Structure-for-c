bin = test
headers = -I./headers/
cflages = -Wall $(headers)

$(bin) : objs/test.o objs/arrStr.o objs/input.o objs/str.o
	gcc -o $@ $^

objs/test.o : src/test.c
	gcc -c $(cflages) -o $@ $<

objs/arrStr.o : src/arrStr.c
	gcc -c $(cflages) -o $@ $<

objs/input.o : myLibs/input.c
	gcc -c $(cflages) -o $@ $<


objs/str.o : myLibs/str.c
	gcc -c $(cflages) -o $@ $<

clean :
	rm test
	rm ./objs/*



play :
	@./test

playTest :
	@echo "run the program with valgrind :\n"
	valgrind ./test
