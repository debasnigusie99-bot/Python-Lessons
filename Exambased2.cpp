#include <iostream>

using namespace std;
void myFunction();

int main()
{
    myFunction();
    myFunction();
    myFunction();

    return 0;
}
void myFunction()
{
    static int num;
    int num2 = 9;
    static int count = 2;
    count *= 5;
    num += 4;
    num2 += 2;
    cout << num << " " << count << " " << num2 << " " << endl;
}