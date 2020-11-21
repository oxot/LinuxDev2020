CFLAGS += -Wall

bin_PROGRAMS=guess

%.1:	%
	-$(HELP2MAN) --no-info --output=$@ --name='@PACKAGE_NAME@' ./$<