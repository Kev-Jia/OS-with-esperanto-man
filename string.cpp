#include "string.hpp"

String::String() {
    
}

String::String(const char *string) {
    m_string = (char *)string;
}

void String::operator=(const char *string) {
  m_string = string;
}

char String::operator[](size_t i)
{
    if (i > length()) {
        return 0;
    } else if (i < 0) {
        return 0;
    }

    return m_string[i];
}

size_t String::length() {
    size_t length = 0;
    while (m_string[length] != 0) {
        length++;
    }
    return length;
}
