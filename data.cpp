#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout << "1\n";
    cout << "5\n";
    srand(time(0));
    for(int i = 0; i < 5; i++)
    {
        cout << rand()%32 << ' ';
    }
    cout << '\n';
    for(int i = 0; i < 5; i++)
    {
        cout << rand()%32 << ' ';
    }
    cout << '\n';
    return 0;
}