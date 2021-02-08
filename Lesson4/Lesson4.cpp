/** Author Alexander Chernov
 *
 * Created in Code Blocks
 *
 */

#include <iostream>

using namespace std;

int main()
{

    /////////////////////////////////////////////////////
    //4.1
    cout << "Task 4.1" << endl;
    int number1, number2;
    int result;
    cout << "Enter the first number ";
    cin >> number1;
    cout << "Enter the second number ";
    cin >> number2;
    result = number1 + number2;
    if (result >= 10 && result <=20)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    cout << endl;


    ////////////////////////////////////////////////////

    //4.2
    cout << "Task 4.2" << endl;
    int number3 = 0;
    cout << "Enter a number ";
    cin >> number3;
    int i = 1;
    int divisor = 0;
    while (i <= number3)
    {
        if (number3 % i++ == 0 )
        {
            divisor++;
        }

    }
    if (divisor == 2)
    {
        cout << "The number entered " << number3 << " is a prime number." << endl;
    } else
    {
        cout << "The number you entered is not a prime number" << endl;
    }


   /////////////////////////////////////////////////////
    //4.3
    cout << "Task 4.3" << endl;
    if ((number1 == 10 && number2 == 10) || (number1 + number2 == 10))
    {
        cout << "True" << endl;
    } else
    {
        cout << "False" << endl;
    }

    ////////////////////////////////////////////////////

    //4.4
    cout << "Task 4.4" << endl;
    int started = 1;
    int d = started;
    int hundredth = started;
    int four_hundredth = started;
    int counter = started;
    int year = 0;
    cout << "Enter up to what year to count? ";
    cin >> year;

    while (counter <= year)
    {
        if (four_hundredth == 400)
        {
            cout << endl;
            cout << counter << " Every four-hundredth year is a leap year." << endl;
            four_hundredth = started;
            d = started;
            hundredth = started;
            counter++;
            continue;
        }


       //
        if (hundredth == 100)
        {
            cout << endl;
            cout << counter << " Every hundredth year is not a leap year" << endl;
            hundredth = started;
            d = started;
            counter++;
            four_hundredth++;
            continue;
        }

        if (d == 4)
        {
            cout << endl;
            cout << counter << " - It's leap year" << endl;
            d = started;
            counter++;
            hundredth++;
            four_hundredth++;
            continue;
        }


        cout << counter << " ";
        d++;
        counter++;
        hundredth++;
        four_hundredth++;
    }



    return 0;
}
