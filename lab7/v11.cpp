#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y) {
    return (1 - pow(y, 2)) / (1+pow(x, 2));
}

int main() {

    double X, Y, n, h, K1, K2, K3, K4;

    cout << "Введите значение X:" << endl;
    cin >> X; // 1

    cout << "Введите значение Y:" << endl;
    cin >> Y; // 2

    cout << "Введите значение точности:" << endl;
    cin >> n;

    h = 1 / n;
    cout << endl;
    for (int i = 0; i <= n; i++) {
        cout << X << " | " << Y << " | " << Y << endl;
        K1 = f(X, Y) * h;
        X += h / 2;
        K2 = f(X, Y + K1 / 2) * h;
        K3 = f(X, Y + K2 / 2) * h;
        X += h / 2;
        K4 = f(X, Y + K3) * h;
        Y += (K1 + 2 * K2 + 2 * K3 + K4) / 6;
    }

    return 0;
}
