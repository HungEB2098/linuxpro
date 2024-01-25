.PHONY: all clear staticlib sharedlib objs linkstatic linkshared install

SHARED_LIB_NAME := libcalculate.so;
STATIC_LIB_NAME := libcalculate.a;
CUR_DIR = .


objs:
	gcc -c main.c -o objs/main.o
#static
	gcc -c src/substract.c -o objs/substract.o 
	gcc -c src/add.c -o objs/add.o
#shared
	gcc -c -fPIC src/substract.c -o objs/substract.o 
	gcc -c -fPIC src/add.c -o objs/add.o

clear:
	rm -rf objs/*
	rm -rf libs/static/libcalculate.a
	rm -rf libs/shared/libcalculate.so
	rm -f bin/statically-linked
	rm -f bin/use-shared-library

#use static-lib
staticlib:
	ar rcs libs/static/libcalculate.a objs/add.o objs/substract.o

linkstatic:
	gcc   objs/main.o  -Llibs/static -lcalculate -o bin/statically-linked
#	./libs/static/statically-linked

#use shared-lib
sharedlib:
	gcc -shared objs/add.o objs/substract.o -o libs/shared/libcalculate.so

linkshared:
	gcc  objs/main.o -Llibs/shared -lcalculate -o bin/use-shared-library
#./bin/use-shared-library

install:
	cp -f libs/shared/libcalculate.so /usr/lib 
	cp -f libs/static/libcalculate.a /usr/lib