CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m4 -mthumb -nostdlib
CPPFLAGS=-DSTM32F411xE \
	-Iplatform/cmsis/CMSIS_5/CMSIS/Core/Include \
	-Iplatform/cmsis/cmsis_device_f4/Include \
	-Iplatform \
	-Ihal/clock \
	-Ihal/display \
	-Ihal/gpio 


LINKER_FILE=platform/linker_script.ld
LDFLAGS=-T $(LINKER_FILE)

all: blink.elf

blink.elf: main.o startup.o system_stm32f4xx.o display.o clock_control.o gpio_control.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o blink.elf

main.o: application/main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c -o $@

startup.o: platform/startup.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c -o $@

system_stm32f4xx.o: platform/cmsis/cmsis_device_f4/Source/Templates/system_stm32f4xx.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c -o $@

display.o: hal/display/display.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c -o $@

clock_control.o: hal/clock/clock_control.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c -o $@

gpio_control.o: hal/gpio/gpio_control.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c -o $@

.PHONY: clean
clean:
	rm -f *.o *.elf

PROGRAMMER=openocd
PROGRAMMER_FLAGS=-f interface/stlink.cfg -f target/stm32f4x.cfg

flash: blink.elf
	$(PROGRAMMER) $(PROGRAMMER_FLAGS) -c "program blink.elf verify reset exit"