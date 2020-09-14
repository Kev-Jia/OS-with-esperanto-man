multiboot_alignToPages equ 1 << 0
multiboot_provideMemoryMap equ 1 << 1
multiboot_flags equ multiboot_alignToPages | multiboot_provideMemoryMap
multiboot_magic equ 0x1badb002
multiboot_checksum equ -(multiboot_magic + multiboot_flags)

section .multiboot
align 4
multibootHeader:
    dd multiboot_magic
    dd multiboot_flags
    dd multiboot_checksum

section .bss
align 16
stack_bottom:
    resb 16384
stack_top:

section .text
global bootstrap
bootstrap:
    mov ebp, stack_top
    mov esp, ebp
    
    extern main
    call main
.halt:
    cli
    hlt
    jmp .halt