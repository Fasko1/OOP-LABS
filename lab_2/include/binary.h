#pragma once

#include <initializer_list>
#include <string>
#include <stdexcept>
class Binary
{
public:
    Binary();
    Binary(const size_t &n, unsigned char value);
    Binary(const std::initializer_list<unsigned char> &values);
    Binary(const std::string &str);
    Binary(const Binary &other);
    Binary(Binary &&other) noexcept;
    ~Binary() noexcept;

    Binary &add(const Binary &other);
    Binary &sub(const Binary &other);

    bool eq(const Binary &other) const;
    bool ge(const Binary &other) const;
    bool le(const Binary &other) const;

    size_t getSize() const;
    unsigned char *getData() const;

private:
    size_t _size;
    unsigned char *_data;

    void validateBit(unsigned char digit);
};