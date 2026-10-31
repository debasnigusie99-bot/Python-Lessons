#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int total = 0;
class Animal
{
public:
    virtual void speak() { cout << "..."; }
};
class Dog : public Animal
{
public:
    void speak() override { cout << "woof\"" << endl; }
};
void add(int n)
{
    static int calls = 0;
    calls++;
    total += n;
    cout << calls << ":" << total << " ";
}

int main()
{
    Animal *p = new Dog();
    p->speak();
    delete p;
    ifstream in("data.txt");
    in.seekg(0, ios::end);
    cout << in.tellg();
    in.seekg(0);
    return 0;
}
