CROSS=arm-none-linux-gnueabi-

all: uart_test

uart_test: uart_test.c
	$(CROSS)gcc -O2 -o uart_test uart_test.c 

clean:
	@rm -vf uart_test *.o *~
