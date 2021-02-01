#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    /* Задание 1*/
    int a = 1;
    long aa = 1;
    short aaa = 1;
    unsigned int aaaa = -1;
    float b = 1.0;
    double bb = 1.0;
    char c = 'c';
    cout << " Задание 1" << endl;
    cout << a << " is int" << " size = " << sizeof(a) << endl;
    cout << aa << " is long int" << " size = " << sizeof(aa) << endl;
    cout << aaa << " is short int" << " size = " << sizeof(aaa) << endl;
    cout << aaaa << " is unsigned int" << " size = " << sizeof(aaaa) << endl;
    cout << b << " is float" << " size = " << sizeof(b) << endl;
    cout << bb << " is double" << " size = " << sizeof(bb) << endl;
    cout << c << " is char" << " size = " << sizeof(c) << endl;

    /**< Задание 2 */
    cout << "\n Задание 2\n" << endl;

    typedef enum symbol {O, X, blank} CURSOR;
    CURSOR flag;
    flag = O;
    cout << flag << endl;
    flag = X;
    cout << flag << endl;
    flag = blank;         // должен быть символ пустого поля. каким его обзначить ума не приложу
    cout << flag << endl;

   /*
    а ткое присвоение у меня вызвало ошибку,
    хотя в методичке указано, что такое присвоение допустимо
    flag = 0;
    cout << flag << endl;
    flag = 1;
    cout << flag << endl;
    */

    /**< Задание 3 */
    cout << "\n Задание 3\n" << endl;

    int matrix [3][3] = {blank};

    /**< Задание 4 */
    cout << "\n Задание 4\n" << endl;
    //объявим новый тип структуры
   typedef struct Tic_tac_toe_field
    {
        int row;        //номер строки
        int column;     //номер столбца
        char Symbol;    //символ в ячейке

    } cell;

    /**< Задание 5 */
    cout << "\n Задание 5\n" << endl;
    //объявим новый тип объединения
    typedef union type_of_symbol
    {
        int character_number;
        char character;
    } tofs;
    //проинициализируем объединение
    tofs Character;
    Character.character_number = 2;
    Character.character = ' ';

    //объявим новый тип структуры с флагами на значения внутри объединения
   typedef struct complex_Character
    {
        tofs Val_Character;
        int isInt   :1;     //если 1 то int, если 0 то не int
        int isChar  :1;     //если 1 то char, если 0 то не char
    } coChar;

    coChar M; // объявим переменную с новым типом структуры coChar
    M = {2, 1, 0};  //инициализируем структуру

    //зададим другие значения для структуры с флагами
    M.Val_Character.character = ' ';
    M.isInt = 0;
    M.isChar = 1;




    return 0;
}
