.PHONY: all clean

OBJ      = build/src/jiznn.o build/src/pol.o 
LINKOBJ  = build/src/jiznn.o build/src/pol.o
FLAG = -Wall -Werror
all : bin/jizn

test : bin/jizn-test

clean: 
	rm -rf $(BIN) build/src/*.o  
clean_test: 
	rm -rf $(BIN) build/test/*.o 
	rm -rf $(BIN) build/test/*.d
bin/jizn-test: build/test/jiznn.o build/test/main.o build/test/test.o
	gcc $(FLAG)   build/test/jiznn.o build/test/main.o build/test/test.o -o bin/jizn-test

bin/jizn: $(OBJ)
	gcc -std=c99 $(LINKOBJ) -o bin/jizn

build/src/jiznn.o: src/jiznn.c  
	gcc $(FLAG)  -std=c99 -c src/jiznn.c -o build/src/jiznn.o 

build/src/pol.o: src/pol.c
	gcc $(FLAG)   -std=c99  -c src/pol.c -o build/src/pol.o 

-include build_test/*.d

bin/main-test: build/test/chess.o build/test/board_print_plain.o build/test/test.o build/test/main.o
	gcc  -std=c99 build/test/chess.o build/test/main.o build/test/board_print_plain.o build/test/test.o -o bin/main-test

build/test/jiznn.o: src/jiznn.c  
	gcc $(FLAG)   -I thirdparty -I src -std=c99 -c src/jiznn.c -MMD  -o build/test/jiznn.o 
build/test/main.o: test/main.c
	gcc $(FLAG)    -I thirdparty -I src -std=c99  -c test/main.c -MMD  -o build/test/main.o 
build/test/test.o: test/test.c
	gcc $(FLAG)   -I thirdparty -I src -std=c99 -c test/test.c -MMD -o build/test/test.o
