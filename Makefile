.PHONY: all clean static shared dynamic

all: static shared dynamic

lib/libcalc.a: lib/calc.o calc.h
	ar rcs $@ $<

lib/calc.o: calc.c calc.h
	gcc -c -o $@ $< -I.

lib/libcalc.so: calc.c calc.h
	gcc -fPIC -shared -o $@ $< -I.

static: lib/libcalc.a
	gcc main.c -o main_static -Llib -lcalc -static

shared: lib/libcalc.so
	gcc main.c -o main_shared -Llib -lcalc

dynamic:
	gcc main_dynamic.c -o main_dynamic -ldl

clean:
	rm -f lib/*.o *~ core lib/libcalc.a lib/libcalc.so main_static main_shared main_dynamic
