#include <iostream>

using namespace std;

float float_one_point_round(float value)
{
        return ((float)((int)(value * 1000))) / 1000;
}

int main() {
    float n; cin >> n;
    cout << float_one_point_round(n);
}