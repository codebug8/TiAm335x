需要内核支持：

Device Drivers  ---> 
     <*> Multimedia support  --->
        [*]   Remote Controller support
        [*]   Remote controller decoders (NEW)  --->
        [*]   Remote Controller devices  --->

	Input device support  --->		
		<*>   Event interface
			
打印原始数据，用于制作rc-100ask-nec.c里的映射：
修改内核：drivers/media/rc/ir-nec-decoder.c

183                 } else {
184                         /* Normal NEC */
185                         scancode = address << 8 | command;
186                         //IR_dprintk(1, "NEC scancode 0x%04x\n", scancode);
187                         printk("NEC scancode 0x%04x\n", scancode);
188                 }
		