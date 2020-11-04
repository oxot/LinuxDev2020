TRASH = *.o *.so o.* *.out f fFIX

all:	clean lib test out

lib:	libbuf.c libbuf.h
		gcc -shared -fPIC libbuf.c -o libbuf.so

test:	tests.c
		gcc tests.c -L. -lbuf

out:	
		LD_LIBRARY_PATH=`pwd` ./a.out

clean:
	rm -f $(TRASH)