#include "config.hpp"

#include DISPLAY_DRIVER

// Because C++ compilers change object names (this called 'name mangling' and is required for C++'s function overloading), to be able to find our main() function in our bootstrap.asm code, we must employ 'extern "C"'--which disables name mangling.
extern "C" void main() {
	TextBuffer kernelTextBuffer("Kernel");
	kernelTextBuffer.printString("Hello, kernel!\n\nThis is a test of newlines.");
	kernelTextBuffer.display();
}