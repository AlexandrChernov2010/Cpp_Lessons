#include <iostream>
#include "EXTERN_VAR.cpp"

using namespace std;

extern int v_a;
extern int v_b;
extern int v_c;
extern int v_d;

void save();

int main()
{
    //3.1 задание
    setlocale(LC_ALL, "Russian");
    const int a = 1;
    const int b = 15;
    const int c = 11;
    const int d = 125;
    float result = static_cast<float>(a) * (static_cast<float>(b) + (static_cast<float>(c)/static_cast<float>(d)));
    cout << result << endl;

    //3.2
    int number;
    cout << "Enter an integer: " ;
    cin >> number;
    cout << "The result is: " << ((number > 21) ? ((number - 21) << 1) : (number - 21)) << endl;

    //3.3
    save();
    result = static_cast<float>(v_a) * (static_cast<float>(v_b) + (static_cast<float>(v_c)/static_cast<float>(v_d)));
    cout << result << endl;

    //3.4
    int m[3][3][3] = {0};
    m[1][1][1] = 25;
    int *pm;
    pm = &m[1][1][1];
    cout << *pm << endl;



    return 0;
}
