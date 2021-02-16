#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //6.1
    char buffer1 [50] = "Привет всем!";
    ofstream myfout1 ("file1.txt"); //создаём первый файл
    myfout1 << buffer1; // запись данных в файл
    myfout1.close();

    char buffer2 [50] = "Привет всем ёщё раз!";
    ofstream myfout2 ("file2.txt"); //создаём второй файл
    myfout2 << buffer2; // запись данных в файл
    myfout2.close();

    //6.2
    ifstream myF1 ("file1.txt");
    ifstream myF2 ("file2.txt");
    ofstream myF3 ("file3.txt");

   // string file1, file2;
    char buffFile1 [50];
    char buffFile2 [50];

    if (myF1.is_open())
    {
        myF1.getline (buffFile1, 50);
        myF3 << buffFile1 << endl;
        myF1.close();
    } else
    {
        cout << "file1.txt  not found" << endl;
    }

    if (myF2.is_open())
    {
        myF2.getline (buffFile2, 50);
        myF3 << buffFile2 << endl;
        myF2.close();
    } else
    {
        cout << "file2.txt  not found" << endl;
    }



    myF3.close();



    return 0;
}
