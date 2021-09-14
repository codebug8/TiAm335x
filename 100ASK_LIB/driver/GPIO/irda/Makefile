KERN_DIR = /home/book/100ask-am3358/linux-4.1.18

all:
	make -C $(KERN_DIR) M=`pwd` modules 

clean:
	make -C $(KERN_DIR) M=`pwd` modules clean
	rm -rf modules.order 

obj-m	+= irda_drv.o
obj-m	+= rc-100ask-nec.o
