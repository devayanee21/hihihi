#include <iostream>
using namespace std;

int main() {
    int deg1, deg2;
    int a[50] = {0}, b[50] = {0};

    cin >> deg1;
    for (int i = 0; i <= deg1; i++) cin >> a[i];

    cin >> deg2;
    for (int i = 0; i <= deg2; i++) cin >> b[i];

    int maxD = max(deg1, deg2);
    int sum[100] = {0}, mul[100] = {0};

    for (int i = 0; i <= maxD; i++) sum[i] = a[i] + b[i];

    for (int i = 0; i <= deg1; i++)
        for (int j = 0; j <= deg2; j++)
            mul[i + j] += a[i] * b[j];

    cout << "\nSum coeffs:\n";
    for (int i = 0; i <= maxD; i++)
        cout << sum[i] << " ";

    cout << "\nProduct coeffs:\n";
    for (int i = 0; i <= deg1 + deg2; i++)
        cout << mul[i] << " ";
}
