CFLAGS=
all: clean
	@echo "Building big"
	@make library tests
debug:
	CFLAGS+=-g
	make all
library: big.o
	@echo "Building library"
	@ar rcs big.a *.o
tests: library
	@echo "Building test binary"
	@g++ test.cpp big.a -o test $(CFLAGS)
clean-objects:
	@echo "Cleaning objects"
	@rm -rf *.o
	@rm -rf build/
clean: clean-objects
	@echo "Cleaning binaries"
	@rm -f test
big.o:
	@echo "Building objects"
	@g++ -c big.cpp -o big.o
include: big.o
	@echo "Building global include library (.so)"
	@g++ -fPIC -g -c -O2 -Wall big.cpp
	@g++ -ggdb -O2 -shared -Wl -o libbig.so.1.0.1 big.o
clean-full: clean
	@rm -rf *.dSYM/ *.a *.out
