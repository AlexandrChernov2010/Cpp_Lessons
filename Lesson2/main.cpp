#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    /* ������� 1*/
    int a = 1;
    long aa = 1;
    short aaa = 1;
    unsigned int aaaa = -1;
    float b = 1.0;
    double bb = 1.0;
    char c = 'c';
    cout << " ������� 1" << endl;
    cout << a << " is int" << " size = " << sizeof(a) << endl;
    cout << aa << " is long int" << " size = " << sizeof(aa) << endl;
    cout << aaa << " is short int" << " size = " << sizeof(aaa) << endl;
    cout << aaaa << " is unsigned int" << " size = " << sizeof(aaaa) << endl;
    cout << b << " is float" << " size = " << sizeof(b) << endl;
    cout << bb << " is double" << " size = " << sizeof(bb) << endl;
    cout << c << " is char" << " size = " << sizeof(c) << endl;

    /**< ������� 2 */
    cout << "\n ������� 2\n" << endl;

    typedef enum symbol {O, X, blank} CURSOR;
    CURSOR flag;
    flag = O;
    cout << flag << endl;
    flag = X;
    cout << flag << endl;
    flag = blank;         // ������ ���� ������ ������� ����. ����� ��� ��������� ��� �� �������
    cout << flag << endl;

   /*
    � ���� ���������� � ���� ������� ������,
    ���� � ��������� �������, ��� ����� ���������� ���������
    flag = 0;
    cout << flag << endl;
    flag = 1;
    cout << flag << endl;
    */

    /**< ������� 3 */
    cout << "\n ������� 3\n" << endl;

    int matrix [3][3] = {blank};

    /**< ������� 4 */
    cout << "\n ������� 4\n" << endl;
    //������� ����� ��� ���������
   typedef struct Tic_tac_toe_field
    {
        int row;        //����� ������
        int column;     //����� �������
        char Symbol;    //������ � ������

    } cell;

    /**< ������� 5 */
    cout << "\n ������� 5\n" << endl;
    //������� ����� ��� �����������
    typedef union type_of_symbol
    {
        int character_number;
        char character;
    } tofs;
    //����������������� �����������
    tofs Character;
    Character.character_number = 2;
    Character.character = ' ';

    //������� ����� ��� ��������� � ������� �� �������� ������ �����������
   typedef struct complex_Character
    {
        tofs Val_Character;
        int isInt   :1;     //���� 1 �� int, ���� 0 �� �� int
        int isChar  :1;     //���� 1 �� char, ���� 0 �� �� char
    } coChar;

    coChar M; // ������� ���������� � ����� ����� ��������� coChar
    M = {2, 1, 0};  //�������������� ���������

    //������� ������ �������� ��� ��������� � �������
    M.Val_Character.character = ' ';
    M.isInt = 0;
    M.isChar = 1;




    return 0;
}
