#include <iostream>
using namespace std;

double calculator()
{
    int a, b;
    cout << "Please enter the two numbers to operate: " << endl;
    cin >> a >> b;
    int choice;
    cout << "\nPlease choose :\n";
    cout << "1 for Addition(+)\n";
    cout << "2 for Subtraction\n";
    cout << "3 for Multiplication\n";
    cout << "4 for Division :" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        return a + b;

    case 2:
        return a - b;

    case 3:
        return a * b;

    case 4:
        if (b != 0)
            return static_cast<double>(a) / b;
        else
        {
            cout << "Division by zero is not allowed!\n";
            return 0.0;
        }

    default:
        cout << "Invalid choice!\n";
        return 0.0;
    }
}
bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
long long factorial(int n)
{
    if (n < 0)

        return -1;

    long long pro = 1;

    for (int i = 2; i <= n; i++)
    {

        pro *= i;
    }
    return pro;
}
double incomeTax(double salary)
{
    if (salary <= 2000)
        return 0;
    else if (salary <= 4000)
        return salary * 0.15 - 300;
    else if (salary <= 7000)
        return salary * 0.20 - 500;
    else if (salary <= 10000)
        return salary * 0.25 - 850;
    else if (salary <= 14000)
        return salary * 0.30 - 1350;
    else if (salary > 14000)
        return salary * 0.35 - 2050;

    return 0;
}
double pension(double salary)
{
    return salary * 0.07;
}
int main()
{

    // double result = calculator();
    // cout << "Result = " << result << endl;
    // cout << boolalpha;
    // cout << isPrime(7) << endl;
    // cout << isPrime(9) << endl;
    // cout << factorial(5) << endl;  // 12
    // cout << factorial(0) << endl;  // 1
    // cout << factorial(1) << endl;  // 1
    // cout << factorial(-3) << endl; // -1
    double salary = 3000;

    cout << "Income tax: " << incomeTax(salary) << endl;
    cout << "Pension: " << pension(salary) << endl;
    cout << "Net salary: "
         << salary - incomeTax(salary) - pension(salary)
         << endl;
    return 0;
}