#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <iterator>
#include <string>
#include <stack>
using namespace std;

char singleDigitPreprocees(int n)
{
    if (n < 10) return n + '0';
    else if (n >= 10) {
        return 'A' + (n - 10);
    }
}
string decimalTo(int decimal, int base)
{
    stack<char> remainders;
    if (decimal == 0) return "0";
    while (decimal > 0)
    {
        char rem = singleDigitPreprocees(decimal % base);
        decimal = decimal / base;
        remainders.push(rem);
    }
    string any_base = "";
    while (!remainders.empty())
    {
        any_base += remainders.top();
        remainders.pop();
    }
    return any_base;
}
int toDigit(char _char)
{
    map<char, int> numbersMap= {{'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},
                                {'7',7},{'8',8},{'9',9},{'A',10},{'B',11},{'C',12}};

    return numbersMap[_char];
}

int toSum(string _str) 
{
    int sumNumbers = 0;
    list<char> numbers;

    for (int i = 0; i < 6; ++i)
    {
        if(_str[i] != '0')
            numbers.push_back(_str[i]);
    }

    for (auto const& i : numbers) {
        sumNumbers += toDigit(i);
    }
    

    return sumNumbers;
}

int main()
{

    /*
    copy(firstSixNumbers.begin(), firstSixNumbers.end(), 
        ostream_iterator<char>(cout, ""));
    cout << endl;
    */
    int count = 0;
    for (int i = 0; i < 4826809; ++i)
    {
        for (int j = i; j < 4826809; ++j)
        {
            string firstString = string(6 - decimalTo(i, 13).length(), '0') + decimalTo(i, 13);
            string secondString = string(6 - decimalTo(j, 13).length(), '0') + decimalTo(j, 13);
            if (toSum(firstString) == toSum(secondString))
                ++count;
            cout << firstString <<"  "<< secondString  <<endl;
        }
    }


    cout << count << endl;

    
    
    return 0;
}