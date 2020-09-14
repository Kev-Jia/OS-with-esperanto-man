#include "config.hpp"

#include "vga.hpp"

TextBuffer::TextBuffer(String name) {
    m_name = name;
}

void TextBuffer::setChar(int x, int y, char ch) {
    m_buffer[y * VGA_WIDTH + x] = ch;
}

void TextBuffer::scroll() {

}

void TextBuffer::printChar(char ch) {
    if (ch == '\n') {
        m_x = 0;
        m_y++;
    } else {
        m_buffer[m_y * VGA_WIDTH + m_x] = ch;
        m_x++;
        if (m_x > VGA_WIDTH) {
            m_x = 0;
            m_y++;
            if (m_y > VGA_HEIGHT) {
                scroll();
                m_y = 0;
            }
        }
    }
}

void TextBuffer::printString(String string) {
    for (size_t i = 0; i < string.length(); i++) {
        printChar(string[i]);
    }
}

void TextBuffer::display() {
    // Display name on top line.
    for (int i = 0; i < VGA_WIDTH * 2; i++) {
        m_vga_memory[i * 2] = m_name[i];
        m_vga_memory[i * 2 + 1] = VGA_INFORMATION_COLOUR;
    }

    // Display contents.
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        // VGA_WIDTH * 2 is added here to offset by one line.
        m_vga_memory[VGA_WIDTH * 2 + i * 2] = m_buffer[i];
        m_vga_memory[VGA_WIDTH * 2 + i * 2 + 1] = VGA_TEXT_COLOUR;
    }
}