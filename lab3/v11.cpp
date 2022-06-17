#include <iostream>
#include "v11_table_wrapper.cpp"
#include <cmath>

using namespace std;

double func(double x) {
    return x / sqrt(1 + x * x) - 0.5;
}

double second_func(double x) {
    return 1 / (sqrt(1 + x * x) * (1 + x * x));
}

int main() {
    setlocale(0, "RU");
    cout << "Введите концы исходного промежутка:" << endl;
    double a, b, m = min(second_func(a), second_func(b)), e, x;
    cin >> a >> b;
    cout << "Введите точность:" << endl;
    cin >> e;
//	cout << "Введите параметр M:" << endl;
//	cin >> m;
    cout << "Введите начальное приближение:" << endl;
    cin >> x;
    if (x = b) {
        b = a;
        a = x;
    }
    int n = 0;
    double fx = 0.0, fxm = 0.0, lx = 0.0;
    do {
        fx = func(x);
        fxm = abs(fx) / m;
        lx = x;
        x -= fx / (fx - func(b)) * (x - b);
        addRowTable(n, lx, fx, fxm);
        n++;
    } while (fxm > e);
    writeTable();
    cout << "Значение корня функции с точностью " << e << " равно " << x << endl;
    cout << "Значение функции f(x) = " << fx << endl;
    return 0;
}
