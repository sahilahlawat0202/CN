#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int count = __builtin_popcount(n);
    if (count % 2 == 0)
        cout << "Even parity\n";
    else
        cout << "Odd parity\n";
    return 0;
}