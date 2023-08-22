#include <iostream>
#include <math.h>
using namespace std;
class SCIENTIFIC_CALCULATOR;
class SIMPLE_CALCULATOR
{
protected:
    float num1;
    float num2;
    char operation;

public:
    SIMPLE_CALCULATOR() {}
    float result;
    int flag = 1;
    SIMPLE_CALCULATOR(float n1, char op, float n2)
    {
        num1 = n1;
        operation = op;
        num2 = n2;
    }
    SIMPLE_CALCULATOR(float n1, char op)
    {
        num1 = n1;
        operation = op;
    }
    void getInput1()
    {
        cout << "PLEASE ENTER THE FIRST NO:" << endl;
        cin >> num1;
    }
    void getOperation()
    {
        cout << "PLEASE ENTER THE WHICH OPERATION WOULD YOU LIKE TO PERFORM" << endl;
        cin >> operation;
    }
    void getInput2()
    {
        if (operation != 'sqr' || operation != 'sqrt')
        {
            cout << "PLEASE ENTER THE SECOND NO:" << endl;
            cin >> num2;
        }
    }
    int calculation()
    {
        if (operation == '+')
        {
            result = num1 + num2;
        }
        else if (operation == '-')
        {
            result = num1 - num2;
        }
        else if (operation == '*')
        {
            result = num1 * num2;
        }
        else if (operation == '/')
        {
            if (num2 != 0)
            {
                result = num1 / num2;
            }
        }
        else
        {
            flag = 0;
        }
    }
};
class SCIENTIFIC_CALCULATOR : public SIMPLE_CALCULATOR
{
protected:
    float result_sci;
    float num1_sci = num1;
    float num2_sci = num2;
    char operation_sci = operation;
    int flag2 = 1;

public:
    SCIENTIFIC_CALCULATOR() {}
    SCIENTIFIC_CALCULATOR(float n1, char op, float n2)
    {
        num1 = n1;
        operation = op;
        num2 = n2;
    }
    SCIENTIFIC_CALCULATOR(float n1, char op)
    {
        num1 = n1;
        operation = op;
    }
    int calculation_sci()
    {
        if (operation == '^')
        {
            result = pow(num1, num2);
        }
        else if (operation == 'sqr')
        {
            result = pow(num1, 2);
        }
        else if (operation == 'sqrt')
        {
            result = sqrt(num1);
        }
        else
        {
            flag2 = 0;
        }
        result_sci = result;
    }
};
class HYBRID_CALCULATOR : public SCIENTIFIC_CALCULATOR
{
    int flag1 = 1;

public:
    HYBRID_CALCULATOR() {}
    HYBRID_CALCULATOR(float n1, char op, float n2)
    {
        flag1 = 0;
        num1 = n1;
        operation = op;
        num2 = n2;
    }
    HYBRID_CALCULATOR(float n1, char op)
    {
        flag1 = 0;

        num1 = n1;
        operation = op;
    }
    void display_result()
    {
        if (flag || flag2)
        {
            cout << "THE RESULT IS THE :" << result_sci << endl;
        }
        else
        {
            cout << "PLEASE ENTER THE VAILD INPUT :..)" << endl;
        }
    }
    void getStarted()
    {
        if (flag1)
        {
            getInput1();
            getOperation();
            getInput1();
        }

        calculation();
        calculation_sci();
        display_result();
    }
};
int main()
{
    HYBRID_CALCULATOR h1(10, '^', 2);
    h1.getStarted();
}