#include<iostream>
#include<string>

#define DEMO_CONST_VARIABLE     1
#define DEMO_CONST_REFERENCE    1
#define DEMO_CONST_POITER_1     1
#define DEMO_CONST_POITER_2     1
#define DEMO_CONST_POITER_3     1

using namespace std;

#if DEMO_CONST_VARIABLE //Constant variable
int main()
{
    cout << "Constant variable" << endl;
    const double PI = 3.14;
    const string DESCRIPTION = "This is constant string";

//    PI = 2;   //Cannot assign new value to constant variable
//    DESCRIPTION = "Change value"; //Cannot assign new value to constant variable
    return 0;
}

#elif DEMO_CONST_REFERENCE //Constant reference

int main()
{
    cout << "Constant reference" << endl;
    int x = 10;
    int y = 11;

    const int &ref = x;

//    a = y;  //Cannot change value of reference

    cout << "ref = " << ref << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    cout << "&ref = " << &ref << endl;
    cout << "&x = " << &x << endl;
    cout << "&y = " << &y << endl;
    return 0;
}

#elif DEMO_CONST_POITER_1   //Non-constant poiter to constant value
int main()
{
    cout << "Non-constant poiter to constant value" << endl;
    int x = 10;
    int y = 11;

    const int *p = &x;

//    *p = y;  //Cannot change value of poiter
    p = &y;

    cout << "*p = " << *p << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    cout << "p = " << p << endl;
    cout << "&x = " << &x << endl;
    cout << "&y = " << &y << endl;
    return 0;
}

#elif DEMO_CONST_POITER_2   //Constant poiter to non-const value

int main()
{
    cout << "Constant poiter to non-const value" << endl;
    int x = 10;
    int y = 11;

    int *const p = &x;

    *p = y;
//    p = &y; //Cannot change poiter to point to other location

    cout << "*p = " << *p << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    cout << "p = " << p << endl;
    cout << "&x = " << &x << endl;
    cout << "&y = " << &y << endl;
    return 0;
}

#elif DEMO_CONST_POITER_3   //Constant poiter to const value

int main()
{
    cout << "Constant poiter to const value" << endl;
    int x = 10;
    int y = 11;

    const int *const p = &x;

//    *p = y; //Cannot change value of poiter
//    p = &y; //Cannot change poiter to point to other location
    return 0;
}
#endif
