//
// Created by 12999427 on 02/03/2026.
//

#include "MyVector.h"

MyVectorInt::MyVectorInt() {

}

MyVectorInt::MyVectorInt(int numElementsToZero) {

}
MyVectorInt::MyVectorInt(const MyVectorInt& other) {

}
MyVectorInt::~MyVectorInt() {

}
int MyVectorInt::GetSize() const {
    return size;
}
int MyVectorInt::GetCapacity() const {

}
bool MyVectorIntIsEmpty() {

}
int& MyVectorInt::At(int index) {

}
const int& MyVectorInt::At (int index) const {

}
int& MyVectorInt::operator[](int index) {

}
const int& MyVectorInt::operator[](int index) const {

}

void MyVectorInt::SetElement(int index, int element) {

}
void MyVectorInt::Push_Back(int value) {

}
int MyVectorInt::Pop_Back() {

}
void MyVectorInt::Clear() {

}
void MyVectorInt::Resize(int newSize) {

}
void MyVectorInt::Reserve(int newCapacity) {

}
void MyVectorInt::operator= (const MyVectorInt & other) {

}

void Sort();
void Sort(bool ascending);
void Reverse();
int Find(int value) const;
bool Contains(int value) const;

//friend per stampare
friend std::ostream& operator<<(std::ostream& os, const MyVectorInt& v);

//facoltativi
void Insert(int pos, int value);
void erease (int pos);
bool operator==(const MyVectorInt &) const;