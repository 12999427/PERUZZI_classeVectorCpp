#include <iostream>
#include "MyVector.h"

//solo il main scritto da chat per testare a fondo ogni caso limite :)

void printState(const MyVectorInt& v, const std::string& name)
{
    std::cout << "---- " << name << " ----\n";
    std::cout << "Size: " << v.GetSize() << "\n";
    std::cout << "Capacity: " << v.GetCapacity() << "\n";
    std::cout << "Content: " << v << "\n";
    std::cout << "IsEmpty: " << (v.IsEmpty() ? "true" : "false") << "\n";
    std::cout << "---------------------\n\n";
}

int main()
{
    std::cout << "===== TEST VECTOR =====\n\n";

    // ---------------------------
    // COSTRUTTORE DEFAULT
    // ---------------------------

    MyVectorInt v1;
    printState(v1, "v1 default");

    // ---------------------------
    // PUSH BACK + REALLOC
    // ---------------------------

    std::cout << "Push back 10 elementi\n";

    for(int i=0;i<10;i++)
        v1.Push_Back(i);

    printState(v1,"v1 dopo push");

    // ---------------------------
    // ACCESSO
    // ---------------------------

    std::cout << "Access test\n";

    std::cout << "v1[3] = " << v1[3] << "\n";
    std::cout << "v1.at(4) = " << v1.At(4) << "\n\n";

    v1[3] = 99;

    printState(v1,"v1 dopo modifica");

    // ---------------------------
    // POP BACK
    // ---------------------------

    std::cout << "Pop back\n";

    v1.Pop_Back();
    v1.Pop_Back();

    printState(v1,"v1 dopo pop");

    // ---------------------------
    // RESIZE
    // ---------------------------

    std::cout << "Resize a 15\n";

    v1.Resize(15);

    printState(v1,"v1 resize 15");

    std::cout << "Resize a 5\n";

    v1.Resize(5);

    printState(v1,"v1 resize 5");

    // ---------------------------
    // RESERVE
    // ---------------------------

    std::cout << "Reserve 50\n";

    v1.Reserve(50);

    printState(v1,"v1 reserve 50");

    // ---------------------------
    // CLEAR
    // ---------------------------

    std::cout << "Clear\n";

    v1.Clear();

    printState(v1,"v1 clear");

    // ---------------------------
    // COSTRUTTORE CON PARAM
    // ---------------------------

    MyVectorInt v2(5);

    printState(v2,"v2 size 5");

    // ---------------------------
    // COPY CONSTRUCTOR
    // ---------------------------

    std::cout << "Copy constructor\n";

    MyVectorInt v3(v2);

    printState(v3,"v3 copia di v2");

    v2[0] = 100;

    std::cout << "modifico v2\n";

    printState(v2,"v2 modificato");
    printState(v3,"v3 (deve rimanere uguale)");

    // ---------------------------
    // OPERATOR =
    // ---------------------------

    std::cout << "Operator=\n";

    MyVectorInt v4;

    v4 = v2;

    printState(v4,"v4 = v2");

    v2[1] = 777;

    std::cout << "modifico v2\n";

    printState(v2,"v2 modificato");
    printState(v4,"v4 deve essere indipendente");

    // ---------------------------
    // SORT
    // ---------------------------

    MyVectorInt v5;

    v5.Push_Back(5);
    v5.Push_Back(1);
    v5.Push_Back(9);
    v5.Push_Back(2);
    v5.Push_Back(7);

    printState(v5,"v5 originale");

    std::cout << "Sort ascending\n";

    v5.Sort(true);

    printState(v5,"v5 sorted");

    std::cout << "Sort descending\n";

    v5.Sort(false);

    printState(v5,"v5 sorted desc");

    // ---------------------------
    // REVERSE
    // ---------------------------

    std::cout << "Reverse\n";

    v5.Reverse();

    printState(v5,"v5 reversed");

    // ---------------------------
    // FIND / CONTAINS
    // ---------------------------

    std::cout << "Find 7 -> " << v5.Find(7) << "\n";
    std::cout << "Contains 9 -> " << v5.Contains(9) << "\n";
    std::cout << "Contains 100 -> " << v5.Contains(100) << "\n\n";

    // ---------------------------
    // INSERT
    // ---------------------------

    std::cout << "Insert 42 in pos 2\n";

    v5.Insert(2,42);

    printState(v5,"v5 dopo insert");

    // ---------------------------
    // ERASE
    // ---------------------------

    std::cout << "Erase pos 3\n";

    v5.Erease(3);

    printState(v5,"v5 dopo erase");

    // ---------------------------
    // OPERATOR ==
    // ---------------------------

    MyVectorInt v6(v5);

    std::cout << "v5 == v6 ? " << (v5 == v6) << "\n";

    v6.Push_Back(999);

    std::cout << "v5 == v6 ? " << (v5 == v6) << "\n\n";

    // ---------------------------
    // ECCEZIONI
    // ---------------------------

    std::cout << "Test eccezioni\n";

    try
    {
        std::cout << v5.At(999) << "\n";
    }
    catch(std::exception& e)
    {
        std::cout << "Eccezione catturata: " << e.what() << "\n";
    }

    try
    {
        MyVectorInt empty;
        empty.Pop_Back();
    }
    catch(std::exception& e)
    {
        std::cout << "Eccezione pop_back: " << e.what() << "\n";
    }

    std::cout << "\n===== FINE TEST =====\n";

    return 0;
}