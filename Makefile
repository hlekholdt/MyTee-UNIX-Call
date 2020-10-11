RED= \033[0;31m
GREEN= \033[0;32m
NC= \033[0m
M= Makefile

all:
	make mytee
	
test: mytee
	make test1
	make test2
	make clean
	@echo "*** ${GREEN}PASSED the test ${NC}***"

mytee: mytee.c
	gcc -o mytee mytee.c

test1: mytee
	./mytee -v 
	
test2: mytee
	cat mytee.c | ./mytee mytee.fout > mytee.out
	diff mytee.fout mytee.c
	diff mytee.c mytee.out

test3: mytee
	dd if=/dev/urandom bs=1 count=4096 of=random.bin
	cat random.bin | ./mytee mytee.fout > mytee.out 
	diff random.bin mytee.fout 
	diff random.bin mytee.out


mytest: mytee
	@echo "student adds tests, for instance,"
	./mytee	
	./mytee -a
clean:
	-rm mytee.fout mytee.out mytee random.bin
