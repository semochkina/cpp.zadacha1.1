#include <iostream>
#include "DynamicArray.h"

DynamicArray::DynamicArray() {
    init(100, 0);
}

DynamicArray::DynamicArray(int size) {
    init(size, 0);
}

DynamicArray::DynamicArray(int size, int n) {
    init(size, n);
}

DynamicArray::DynamicArray(const DynamicArray &other) {
    init(other.size, 0);
    for (int i = 0; i < size; i++) mas[i] = other.mas[i];
}


DynamicArray::DynamicArray(DynamicArray &&other) {
    mas = other.mas;
    size = other.size;
    other.size = 0;
}


DynamicArray::~DynamicArray() {
    clear();
}

void DynamicArray::init(int size, int n) {
    this->size = size;
    mas = new int[size];
    for (int i = 0; i < size; i++) mas[i] = n;
}

void DynamicArray::clear() {
    if (size != 0) delete[] mas;
    size = 0;
}

int DynamicArray::getSize() {
    return size;
}

int &DynamicArray::operator[](int i) {
    return mas[i];
}

void DynamicArray::resize(int newSize) {
    int *masOld = mas;
    int sizeOld = size;
    init(newSize, 0);
    for (int i = 0; i < std::min(sizeOld, newSize); i++) mas[i] = masOld[i];
//    std::copy(masOld, masOld + std::min(sizeOld, newSize), mas);
    delete[] masOld;
}

DynamicArray &DynamicArray::operator=(const DynamicArray &other) {
   // if (this != &other) {
        // kopiruem
        clear();
        init(other.size, 0);
        for (int i = 0; i < size; i++) mas[i] = other.mas[i];
    //}
    return *this;
}

DynamicArray &DynamicArray::operator=(DynamicArray &&other) {
   // if (this != &other) {
        // peremeshenie
        clear();
        mas = other.mas;
        size = other.size;
        other.size = 0;
   // }
    return *this;
}


bool DynamicArray::operator==(const DynamicArray &other) const {
    if (size != other.size) throw "Error size";
    for (int i = 0; i < size; i++) {
        if (mas[i] != other.mas[i]) return false;
    }
    return true;
}

bool DynamicArray::operator!=(const DynamicArray &other) const {
    return !(other == *this);
}

bool DynamicArray::operator<(const DynamicArray &other) const {
    if (mas < other.mas)
        return true;
    if (other.mas < mas)
        return false;
    return size < other.size;
}

bool DynamicArray::operator>(const DynamicArray &other) const {
    return other < *this;
}

bool DynamicArray::operator<=(const DynamicArray &other) const {
    return !(other < *this);
}

bool DynamicArray::operator>=(const DynamicArray &other) const {
    return !(*this < other);
}

void DynamicArray::operator+(const DynamicArray &other) {
    int sizeMem = size;
    resize(size + other.size);
    for (int i = 0; i < other.size; i++) mas[i + sizeMem] = other.mas[i];
}

std::ostream &operator<<(std::ostream &os, const DynamicArray &array) {
    os << " size: " << array.size;
    for (int i = 0; i < array.size; i++) os << (i == 0 ? " value=" : ", ") << array.mas[i];
    return os;
}
