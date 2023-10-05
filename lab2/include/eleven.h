#pragma once

#include <iostream>
#include <string>

class Eleven
{ 
public:
   Eleven();
   Eleven(const unsigned char* array, const int size);
   Eleven(const std::initializer_list< unsigned char> &t);
   Eleven(const std::string &t);
   Eleven(const Eleven& other);
   Eleven(Eleven&& other) noexcept;
   
   Eleven operator +(const Eleven& other);
   Eleven operator -(const Eleven& other);
   bool operator ==(const Eleven& other) const;
   bool operator >(const Eleven& other) const;
   bool operator <(const Eleven& other) const;
   friend std::ostream& operator <<(std::ostream& os, const Eleven& other);

   virtual ~Eleven() noexcept;
private:
    size_t _size;
    unsigned char *_array;
};