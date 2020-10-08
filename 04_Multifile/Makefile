GENERATES = prog README prog-a prog-so *.a *.so
TRASH = *.o *~ o.* *.out
CFLAGS = -Wall -fPIC

%.o:	%.c
		cc $(CFLAGS) $< -c -o $@

test:	prog prog-a prog-so
		./prog > p.out 2> er.out
		./prog-a > a.out 2> aer.out
		LD_LIBRARY_PATH=`pwd` ./prog-so > so.out 2> soer.out

		cmp p.out a.out
		cmp p.out so.out

		./prog 7 > p.out 2> er.out
		./prog-a 7 > a.out 2> aer.out
		LD_LIBRARY_PATH=`pwd` ./prog-so 7 > so.out 2> soer.out

		cmp p.out a.out
		cmp p.out so.out
		
		./prog 1 2 3 > p.out 2> er.out
		./prog-a 1 2 3  > a.out 2> aer.out
		LD_LIBRARY_PATH=`pwd` ./prog-so 1 2 3 > so.out 2> soer.out

		cmp p.out a.out
		cmp p.out so.out
		

all:	README prog
fun.o:	outlib.h

prog:	const.o fun.o prog.o

liboutput_static.a:	const.o fun.o
		ar -rcs $@ $^

prog-a: prog.o liboutput_static.a
		cc -L. $< -loutput_static -o $@

liboutput.so:	const.o fun.o
		cc -shared $^ -o $@

prog-so:	prog.o liboutput.so
		cc -L. $< -loutput -o $@


		

README:	prog
		./$< 2> $@

clean:
	rm -f $(TRASH)

distclean:	clean
		rm -rf $(GENERATES)