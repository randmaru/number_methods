#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double custom_func(double x) {
    return x*x*x;
}

// Method Monte-Carlo
int main() {
    setlocale(0, "RU");

    int n;
    double a, b, x, h, s = 0;

    cout << "Введи концы промежутка:" << endl;
    cin >> a >> b;

    cout << "Введите N:" << endl;
    cin >> n;

    h = (b - a) / n;

    for (int i = 0; i < n; i++) {
        x = a + (b - a) * (rand() / (RAND_MAX + 1.0));
        s = s + custom_func(x) * h;
    }

    cout << "Значение интеграла:" << s << endl;


    return 0;
}