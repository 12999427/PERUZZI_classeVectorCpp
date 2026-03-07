//
// Created by 12999427 on 02/03/2026.
//

#ifndef PERUZZI_CLASSEVECTORCPP_MYVECTOR_H
#define PERUZZI_CLASSEVECTORCPP_MYVECTOR_H
#include <iosfwd>
#include <iostream>


class MyVectorInt {
private:
    int * data;
    int size;
    int capacity;

public:
    MyVectorInt();
    MyVectorInt(int numElementsToZero);
    MyVectorInt(const MyVectorInt& other);
    ~MyVectorInt();
    int GetSize() const;
    int GetCapacity() const;
    bool IsEmpty() const;
    int& At(int index);
    const int& At (int index) const;
    int& operator[](int index);
    const int& operator[](int index) const;

    void SetElement(int index, int element);
    void Push_Back(int value);
    int Pop_Back();
    void Clear();
    void Resize(int newSize);
    void Reserve(int newCapacity);
    MyVectorInt & operator= (const MyVectorInt & other);

    void Sort();
    void Sort(bool ascending);
    void Reverse();
    int Find(int value) const;
    bool Contains(int value) const;

    //friend per stampare
    friend std::ostream& operator<<(std::ostream& os, const MyVectorInt& v);

    //facoltativi
    void Insert(int pos, int value);
    void Erease (int pos);
    bool operator==(const MyVectorInt & altro) const;
};


#endif //PERUZZI_CLASSEVECTORCPP_MYVECTOR_H