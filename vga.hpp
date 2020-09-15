#ifndef VGA_HPP
#define VGA_HPP

#include "string.hpp"

#define VGA_MEMORY 0xb8000
#define VGA_WIDTH 80
// One row less than the actual height of the vga text screen. This is to leave one line at the top to display which text buffer that the user is viewing.
#define VGA_HEIGHT 24

class TextBuffer {
public:
    // The name of the current text buffer is displayed on the top line of the screen.
    TextBuffer(String name);
    // Adds character to buffer.
    void printChar(char ch);
    // Adds string to buffer.
    void printString(String string);
    // Displays the text buffer on the screen.
    void display();

private:
    // Sets the character at the specified x and y coordinates.
    void setChar(int x, int y, char ch);
    // Scrolls screen by one line.
    // NOT IMPLEMENTED
    void scroll();

    // Displayed on the top line of the screen when active.
    String m_name;
    // The VGA buffer needs two bytes for one character: one character byte and one colour byte. Because the colour does not change, m_buffer does not include colour data.
    // We use char[] here because String is immutable
    char m_buffer[VGA_HEIGHT * VGA_WIDTH];
    char *m_vga_memory = (char *)VGA_MEMORY;
    // Current X and Y coordinates of cursor.
    int m_x, m_y = 0;
};

#endif
