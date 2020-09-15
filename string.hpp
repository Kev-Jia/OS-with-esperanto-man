#ifndef STRING_HPP
#define STRING_HPP

#include <stddef.h>

// Strings are immutable.

class String {
public:
    String();
    String(const char *string);
    // Set string
    void operator=(const char *string);
    // Access character in string
    char operator[](size_t i);
    // Get length of string in bytes (not including terminating null)
    size_t length();

private:
    const char *m_string;
};

#endif
