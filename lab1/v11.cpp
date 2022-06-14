#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

double func(double x) { return x * x * cos(2 * x) + 1; }

int main() {
    setlocale(0, "RU");
    cout << "Введите концы промежутка:\n";
    double a, b, c, e;
    cin >> a >> b;
    cout << "Введите точность:\n";
    cin >> e;
    while (b - a > 2 * e) {
        c = (a + b) / 2;
        if (func(a) * func(c) > 0) {
            a = c;
        } else {
            b = c;
        }
        cout << "[" << a << ", " << b << "]" << endl;
    }
    double x = (a + b) / 2;
    cout << "Значение корня с точностью " << e << " равно " << x << endl;
    cout << "Значение функции при найденном x равно " << func(x) << endl;
    return 0;
}
