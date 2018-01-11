
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string str("hello");
    for (auto c : str)
    {
        cout << c << endl;
    }
    return 0;
}