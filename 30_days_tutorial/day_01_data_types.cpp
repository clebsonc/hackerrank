#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";
    cout << setprecision(1) << fixed;
    int a=0;
    float b=0.0;
    string c;

    cin >> a;
    cin >> b;
    cin.clear();
    cin.ignore(numeric_limits<int>::max(), '\n');
    getline(cin, c);

   
    cout << a+i << "\n";
    cout << d+b << "\n";
    cout << s.append(c);
    return 0;
}
