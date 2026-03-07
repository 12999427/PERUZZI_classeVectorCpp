//
// Created by 12999427 on 02/03/2026.
//

#include "MyVector.h"

#include <algorithm>
#include <cstdlib>
#include <stdexcept>
#include <cmath>

MyVectorInt::MyVectorInt() {
    size = 0;
    capacity = 0;
    data = new int[0];
}

MyVectorInt::MyVectorInt(int numElementsToZero) {
    size = numElementsToZero;
    capacity = numElementsToZero;
    data = new int[size];

    for (int i = 0; i<size; i++)
    {
        data[i] = 0;
    }
}
MyVectorInt::MyVectorInt(const MyVectorInt& other) {
    size = other.GetSize();
    capacity = other.GetCapacity();
    data = new int[capacity];

    for (int i = 0; i<size; i++)
    {
        data[i] = other.At(i);
    }
}
MyVectorInt::~MyVectorInt() {
    delete[] data;
}

int MyVectorInt::GetSize() const {
    return size;
}
int MyVectorInt::GetCapacity() const {
    return capacity;
}
bool MyVectorInt::IsEmpty() const {
    return size == 0;
}
int& MyVectorInt::At(int index) {
    if (index >= 0 && index < size)
    {
        return data[index];
    }
    throw std::out_of_range("Index out");
}
const int& MyVectorInt::At (int index) const {
    if (index >= 0 && index < size)
    {
        return data[index];
    }
    throw std::out_of_range("Index out");
}
int& MyVectorInt::operator[](int index) {
    return data[index];
}
const int& MyVectorInt::operator[](int index) const {
    return data[index];
}

void MyVectorInt::SetElement(int index, int element) {
    At(index) = element;
}
void MyVectorInt::Push_Back(int value) {
    if ( (capacity) <= size)
    {
        Reserve(std::max(capacity*2, capacity+1));
    }
    size++;
    data[size-1] = value;

    //e non At(size++) = value;
}
int MyVectorInt::Pop_Back() {

    //non deve riallocare

    if (size == 0)
        throw std::underflow_error("problema");

    size--;

    return data[size];
}
void MyVectorInt::Clear() {
    size = 0;
}

void MyVectorInt::Resize(int newSize) {
    if (capacity < newSize)
    {
        Reserve(std::max(capacity*2, capacity+1));
    }
    for (int i = size; i<newSize; i++)
    {
        data[i] = 0;
    }
    size = newSize;
}


void MyVectorInt::Reserve(int newCapacity) {
    if (newCapacity <= capacity)
        return;

    int * old_data = data;

    data = new int [newCapacity];
    for (int i = 0; i< std::min(size, newCapacity); i++)
    {
        data[i] = old_data[i];
    }

    capacity = newCapacity;

    delete [] old_data;
}
MyVectorInt & MyVectorInt::operator= (const MyVectorInt & other) {
    if (this == &other)
        return *this;

    delete[] data;

    size = other.size;
    capacity = other.capacity;

    data = new int[capacity];

    for (int i = 0; i < size; i++)
        data[i] = other.data[i];

    return *this;

    //https://www.geeksforgeeks.org/cpp/cpp-assignment-operator-overloading/
    // e chat
}

void MyVectorInt::Sort()
{
    Sort(true);
}
void MyVectorInt::Sort(bool ascending)
{
    //BUBBLE SSOR

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            bool condition;

            if (ascending)
                condition = data[j] > data[j+1];
            else
                condition = data[j] < data[j+1];

            if (condition)
            {
                int tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
            }
        }
    }
}
void MyVectorInt::Reverse()
{
                    //arrotonda per dif size/2
    for (int i = 0; i<size/2; i++)
    {
        int temp = data[i];
        data[i] = data[size-1-i];
        data[size-1-i] = temp;
    }
}
int MyVectorInt::Find(int value) const
{
    for (int i = 0; i<size; i++)
    {
        if (data[i] == value)
        {
            return i;
        }
    }
    return -1;
}
bool MyVectorInt::Contains(int value) const
{
    return Find(value) != -1;
}

//friend per stampare
std::ostream& operator<<(std::ostream& os, const MyVectorInt& v)
{
    os << "CustomVector<int> {";
    for (int i = 0; i<v.size; i++)
    {
        os << v.data[i] << ", ";
    }
    os << "}";
    return os; // Restituisce os per il concatenamento

    //https://learn.microsoft.com/it-it/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170
}

//facoltativi
void MyVectorInt::Insert(int pos, int value)
{
    if (size+1 > capacity)
    {
        Reserve(std::max(capacity*2, capacity+1));
    }
    for (int i = size; i>pos; i--)
    {
        data[i] = data[i-1];

    }
    data[pos] = value;
    size++;
}
void MyVectorInt::Erease (int pos)
{
    for (int i = pos; i<size; i++)
    {
        data[i] = data[i+1];
    }

    size--;
}
bool MyVectorInt::operator==(const MyVectorInt & altro) const
{
    if (size != altro.size)
        return false;

    for (int i = 0; i<size; i++)
    {
        if (At(i) != altro.At(i))
        {
            return false;
        }
    }

    return true;
}