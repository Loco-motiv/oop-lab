#include "eleven.h"

int chartoint(char b){
    if (b == 'A'){
        return 10;
    }
    else return b - '0';
}

char inttochar(int a){
    if (a == 10){
        return 'A';
    }
    else return a + '0';
}

Eleven::Eleven() : _size(0), _array{nullptr} {}

Eleven::Eleven(const unsigned char* array, const int size){
    _array = new unsigned char[size];
    _size = size;
    for (int i = 0; i < size; i++){
        _array[i] = array[i];
    }
}

Eleven::Eleven(const std::initializer_list<unsigned char> &t)
{
    _array = new unsigned char[t.size()];
    size_t i{0};
    for (auto c : t)
        _array[t.size() - 1 - i++] = c;
    _size = t.size();
}

Eleven::Eleven(const std::string &t)
{
    _array = new unsigned char[t.size()];
    _size  = t.size();

    for(size_t i{0};i<_size;++i) _array[_size - 1 - i] = t[i];
}

Eleven::Eleven(const Eleven &other)
{
    _size  = other._size;
    _array = new unsigned char[_size];

    for(size_t i{0};i<_size;++i) _array[i] = other._array[i];
}

Eleven::Eleven(Eleven &&other) noexcept
{
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}

Eleven& Eleven::operator =(const Eleven& other){
    _size  = other._size;
    _array = new unsigned char[_size];

    for(size_t i{0};i<_size;++i) _array[i] = other._array[i];
    return *this;
}

Eleven& Eleven::operator =(Eleven&& other){
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;

    return *this;
}

Eleven Eleven::operator +(const Eleven &other)
{
    size_t newSize = std::max(this->_size, other._size);
    unsigned char* array1 = new unsigned char[newSize];
    unsigned char* array2 = new unsigned char[newSize];
    if (this->_size < newSize){
        for(int i = this->_size - 1; i >= 0; i--){
            array1[i] = this->_array[i];
        }
        for(int i = newSize - 1; i >= 0; i--){
            array2[i] = other._array[i];
        }
    }
    else {
        for(int i = other._size - 1; i >= 0; i--){
            array1[i] = other._array[i];
        }
        for(int i = newSize - 1; i >= 0; i--){
            array2[i] = this->_array[i];
        }
    }
    int remainder = 0;
    int tmp = 0;
    for (size_t i = 0; i < newSize; i++){
        tmp = chartoint(array1[i]) + chartoint(array2[i]) + remainder;
        remainder = (tmp)/11;
        tmp%=11;
        array1[i] = inttochar(tmp);
    }
    if (remainder){
        newSize++;
        unsigned char* tempArray = new unsigned char[newSize];
        for(int i = newSize - 2; i >= 0; i--){
            tempArray[i] = array1[i];
        }
        tempArray[newSize-1] = inttochar(remainder);
        delete[] array1;
        array1 = tempArray;
    }
    delete[] array2;
    Eleven ans(array1, newSize);
    delete[] array1;
    return ans;   
}

Eleven Eleven::operator -(const Eleven &other)
{

    if(_size<other._size) throw std::logic_error("array can't be negative");
    unsigned char* array = new unsigned char[_size];
    int tmp = 0;
    for (size_t i = 0; i < other._size; i++){
        tmp = chartoint(_array[i]) - chartoint(other._array[i]);
        if (tmp < 0){
            if (i < other._size - 1){
                array[i+1]-=1;
                tmp += 11;
            }
            else{
                throw std::logic_error("array can't be negative");
            }
        }
        array[i] = inttochar(tmp);
    }
    for (size_t i = other._size; i < _size; i++){
        array[i] = _array[i];
    }
    Eleven ans(array, _size);
    delete[] array;
    return ans;     
}

bool Eleven::operator ==(const Eleven &other) const
{
    if (_size != other._size){
        return false;
    }
    for (int i = _size - 1; i >= 0; i--){
        if (other._array[i] != _array[i]){
            return false;
        }
    }
    return true;
}

bool Eleven::operator >(const Eleven &other) const
{
    if (_size > other._size){
        return true;
    }
    else if (_size < other._size){
        return false;
    }
    else {
        for (size_t i = other._size - 1; i >= 0; i--){
            if (chartoint(_array[i]) < chartoint(other._array[i])){
                return false;
            }
            else if (chartoint(_array[i]) > chartoint(other._array[i])){
                return true;
            }
        }
        return false;
    }
}

bool Eleven::operator <(const Eleven &other) const
{
    return other > *this;
}

std::ostream& operator <<(std::ostream &os, const Eleven& other)
{
    for (int i = other._size -1; i >= 0; --i){
        os << other._array[i] << " ";
    }
    return os;
}

Eleven::~Eleven() noexcept
{
    if (_size > 0)
    {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}