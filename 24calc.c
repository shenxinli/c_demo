#include <iostream>  
#include <string>  
#include <cmath>  
#include <stdio.h>
#include <vector>

using namespace std;  

typedef vector<string> results;

const double PRECISION = 1E-6;
const int COUNT_OF_NUMBER = 5;
const int NUMBER_TO_BE_CAL = 24;
double number[COUNT_OF_NUMBER];
string expression[COUNT_OF_NUMBER];

void search(int n, results *vrel)
{
    if (n  ==  1)
    {
        if ( fabs(number[0] - NUMBER_TO_BE_CAL) <= PRECISION  ) //对于除法，要小心小数的精确位数
            vrel->push_back(expression[0]);
    }
 
    for(int i=0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double a, b;
            string expa, expb;
 
            a = number[i];
            b = number[j];
            number[j] = number[n - 1]; //递归之后，n比以前小一位，所以可以不停向前赋值

            expa = expression[i];
            expb = expression[j];
            expression[j] = expression[n - 1]; //递归之后，n比以前小一位，所以可以不停向前赋值

            expression[i] = '(' + expa + '+' + expb + ')'; //加法不需要分顺序
            number[i] = a + b;
            search(n-1, vrel);

            expression[i] = '(' + expa + '-' + expb + ')'; //减法应该分顺序，减数以及被减数
            number[i] = a - b;
            search(n-1, vrel);

            expression[i] = '(' + expb + '-' + expa + ')'; //减法应该分顺序，减数以及被减数
            number[i] = b - a;
            search(n-1, vrel);
   
            expression[i] = '(' + expa + '*' + expb + ')'; //乘法不需要分顺序
            number[i] = a * b;
            search(n-1, vrel);
 
            if (b != 0)
            {
                expression[i] = '(' + expa + '/' + expb + ')'; //除法应该分顺序，除数以及被除数
                number[i] = a / b;
                search(n-1, vrel);
            }
            if (a != 0)
            {
                expression[i] = '(' + expb + '/' + expa + ')'; //除法应该分顺序，除数以及被除数
                number[i] = b / a;
                search(n-1, vrel);
            }
 
            number[i] = a;     //这4句语句是为了防止如果上面几种可能都失败了的话,
            number[j] = b;     //就把原来的赋值撤消回去,以无干扰的正确的进入到下一次
            expression[i] = expa;   //for循环队列中。
            expression[j] = expb;   //
        }
    }
}
 

int main()
{
    cout<<"Please input "<< COUNT_OF_NUMBER << " value of Cards:\n";
    
    for (int i = 0; i < COUNT_OF_NUMBER; i++)
    {
        char buffer[20];
        cout<<"The "<<i+1<<"th card:";
        cin >> number[i];
        sprintf(buffer, "%d", (int)number[i]);
        expression[i] = buffer;    
    }
    cout << endl;
    results vrel;
    search(COUNT_OF_NUMBER, &vrel);
    if (vrel.empty())
    {
        cout << "Fail." << endl;
    }
    else
    {
        int i,count = 0;
        for (i = 0; i < vrel.size(); i++)
        {
            ++count;
            cout << vrel[i] << "\t\t";
            if (count % 3 == 0)
                cout << endl;
        }
        cout << "\nSuccess." << endl;
        cout << "The sum of the ways = " << count <<endl;
    }
    return 0;
}
