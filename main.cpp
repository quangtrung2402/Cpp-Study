#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout << sizeof(int) << endl;
    double i = 1024.0*1024*1000;
    cout << i << endl;
    do{
        int *tmp = new int();
    } while (--i);
    cout << "End create mem" << endl;
}
