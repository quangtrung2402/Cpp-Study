#include <iostream>

using namespace std;
void function(){
    cout << "function is called!!!" << endl;
}

int main()
{
    /*Poiter ==> address / reference / variable ==> Value*/
    int a = 5;
    int *p_a = &a;

    cout << "Value kept by variable a is    : " << a << endl;
    cout << "Address of variable a is       : " << &a << endl;

    cout << "Value kept by poiter p_a is    : " << *p_a << endl;
    cout << "Reference kept by poiter p_a is: " << p_a << endl;
    cout << "Address of poiter p_a is       : " << &p_a << endl;

    /*Function, function poiter, functor*/
    function();


}
