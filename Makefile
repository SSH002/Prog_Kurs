all: archive clear

archive: build/libkurs.so build/main.o
	gcc -Wall -Werror -o calcFrequency build/main.o -Lbuild -lkurs

build/libkurs.so: build/string.o build/count.o build/file.o build/sort.o
	gcc -shared -o build/libkurs.so build/*.o
	
build/string.o: src/string.c
	gcc -Wall -Werror -fPIC -c src/string.c -o build/string.o
build/count.o: src/count.c
	gcc -Wall -Werror -fPIC -c src/count.c -o build/count.o
build/file.o: src/file.c
	gcc -Wall -Werror -fPIC -c src/file.c -o build/file.o
build/sort.o: src/sort.c
	gcc -Wall -Werror -fPIC -c src/sort.c -o build/sort.o
	
build/main.o: src/main.c
	gcc -Wall -Werror -fPIC -c src/main.c -o build/main.o 

clear:
	rm -rf build/*.o
	LD_LIBRARY_PATH=./build
	export LD_LIBRARY_PATH
