#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int *p = &a;
    cout << "Nilai yang ditunjuk p: " << *p << endl;
    cout << "Nilai alamat memori p: " << p << endl;
}
