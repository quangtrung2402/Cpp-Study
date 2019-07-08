#include<iostream>
#if 0
#define VIRTUAL virtual
#else
#define VIRTUAL
#endif
using namespace std;

class A{
public:
    A(){cout << "create A" << endl;}
    VIRTUAL ~A(){cout << "destroying A" << endl;}
};

class B : public A{
public:
    B(){cout << "create B" << endl;}
    VIRTUAL ~B(){cout << "destroying B" << endl;}
};

class C : public B{
public:
    C(){cout << "create C" << endl;}
    VIRTUAL ~C(){cout << "destroying C" << endl;}
};

int main()
{
    A *a = new C();
    delete a;
    return 0;
}
