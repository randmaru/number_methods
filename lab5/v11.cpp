#include <iostream>
#include <clocale>

using namespace std;

double func(double x) { return x*x*x; }

int main() {
    setlocale(0, "RU");
    double a, b, h, s = 0, x = 0;
    int n;
    cout << "Введите концы промежутка:\n";
    cin >> a >> b;
    cout << "N\n";
    cin >> n;
    h = (b - a) / n;
    s = (func(a) - func(b)) / 2;
    for (int i = 1; i <= (n / 2); i++) {
        x = a + 2 * i * h;
        s = s + func(x) + 2 * func(x - h);
    }
    s = s * 2 * h / 3;
    cout << "Значение интеграла " << s << " .\n";
}
