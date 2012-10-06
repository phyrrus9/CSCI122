all: clean
	@echo "Building big"
	@make library tests
library: big.o
	@echo "Building library"
	@ar rcs big.a *.o
tests: library
	@echo "Building test binary"
	@g++ test.cpp big.a -o test
clean-objects:
	@echo "Cleaning objects"
	@rm -f *.o
	@rm -rf build/
clean: clean-objects
	@echo "Cleaning binaries"
	@rm -f test
big.o:
	@echo "Building objects"
	@g++ -c big.cpp -o big.o
