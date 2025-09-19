#include <iostream>
using namespace std;

string answers[] = {
    "-45",
    "101.0111",
    "8",
    "15",
    "T"
};

int main() {
    int x;
    cin >> x;
    cout << answers[x - 1] << endl;
    return 0;
}
