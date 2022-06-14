#include <iostream>
#include "v11_table_wrapper.cpp"
#include <cmath>

using namespace std;

double first_func(double x) {
    return pow(x, 3) - 0.2 * pow(x, 2) + 0.3 * x - 1.2;
}

double second_func(double x) {
    return 3 * pow(x, 2) - 0.4 * x + 0.3;
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
    int n = 0;
    while ((abs(first_func(x)) / m) > e) {
        x -= (first_func(x) / second_func(x));
        addRowTable(n, x, first_func(x), second_func(x), abs(first_func(x)) / m);
        n++;
    }
    writeTable();
    cout << "Значение корня функции с точностью " << e << " равно " << x << endl;
    cout << "Значение функции f(x) " << first_func(x) << endl;
    return 0;
}
