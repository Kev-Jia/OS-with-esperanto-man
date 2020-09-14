CPP = clang --target=i686-elf
CPPFLAGS = -c -O3 -Wall -ffreestanding
ASM = nasm -felf32
ASMFLAGS = -Wall
LD = $(CPP)
LDFLAGS = -Wall -T linker.ld -ffreestanding -nostdlib

CPPOBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
ASMOBJECTS = $(patsubst %.asm, %.o, $(wildcard *.asm))

TARGET = kernel.elf

qemu: all
	qemu-system-i386 -kernel kernel.elf
all: $(TARGET)
clean:
	rm $(TARGET) $(CPPOBJECTS) $(ASMOBJECTS)
$(TARGET): $(ASMOBJECTS) $(CPPOBJECTS)
	$(LD) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -o $@ $^
%.o: %.asm
	$(ASM) $(ASMFLAGS) -o $@ $^
