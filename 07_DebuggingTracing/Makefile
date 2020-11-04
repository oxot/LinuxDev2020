TRASH = *.o *.so o.* *.out f fFIX

all:	wrapper.c
		gcc -shared -fPIC wrapper.c -ldl -o wrapper.so 

test:
		touch f
		touch fFIX
		rm f
		rm fFIX
		touch f
		touch fFIX
		LD_PRELOAD=`pwd`/wrapper.so rm f
		LD_PRELOAD=`pwd`/wrapper.so rm fFIX

clean:
	rm -f $(TRASH)