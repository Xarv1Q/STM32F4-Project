CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m4 -mthumb -nostdlib
CPPFLAGS=-DSTM32F411xE \
	-Iplatform/cmsis/CMSIS_5/CMSIS/Core/Include \
	-Iplatform/cmsis/cmsis_device_f4/Include \
	-Idisplay


LINKER_FILE=linker_script.ld
LDFLAGS=-T $(LINKER_FILE)

all: blink.elf

blink.elf: main.o startup.o system_stm32f4xx.o display.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o blink.elf

main.o: main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c -o $@

startup.o: startup.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c -o $@

system_stm32f4xx.o: platform/cmsis/cmsis_device_f4/Source/Templates/system_stm32f4xx.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c -o $@

display.o: display/display.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c -o $@
	
.PHONY: clean
clean:
	rm -f *.o *.elf

PROGRAMMER=openocd
PROGRAMMER_FLAGS=-f interface/stlink.cfg -f target/stm32f4x.cfg

flash: blink.elf
	$(PROGRAMMER) $(PROGRAMMER_FLAGS) -c "program blink.elf verify reset exit"