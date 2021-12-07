.PHONY: all mkbuild build_test check clean

build/buffer.o: lib/buffer/buffer.c lib/buffer/buffer.h
	gcc -c lib/buffer/buffer.c -o build/buffer.o

build/unity.o: lib/unity/unity.c lib/unity/unity.h lib/unity/unity_internals.h
	gcc -c lib/unity/unity.c -o build/unity.o

build_test: build/buffer.o build/unity.o build/test.o
	gcc -o build/test build/buffer.o build/unity.o build/test.o

build/test.o: test/test.c lib/buffer/buffer.h lib/unity/unity.h
	gcc -c test/test.c -I./lib/unity -I./lib/buffer -o build/test.o

check: mkbuild build_test
	@echo "******************"
	@echo "***Run the test***"
	@echo "******************"
	@./build/test

mkbuild:
	mkdir -p build

clean: 
	rm -rf build