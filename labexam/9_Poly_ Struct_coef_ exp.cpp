#include <iostream>
using namespace std;

struct Term { int coef, exp; };

int main() {
    Term P1[20], P2[20], Sum[40]{}, Mul[40]{};
    int n1, n2;

    cin >> n1;
    for (int i = 0; i < n1; i++) cin >> P1[i].coef >> P1[i].exp;

    cin >> n2;
    for (int i = 0; i < n2; i++) cin >> P2[i].coef >> P2[i].exp;

    int s = 0;
    int i = 0, j = 0;
    while(i < n1 && j < n2) {
        if(P1[i].exp == P2[j].exp)
            Sum[s++] = {P1[i].coef + P2[j].coef, P1[i].exp}, i++, j++;
        else if(P1[i].exp > P2[j].exp)
            Sum[s++] = P1[i++];
        else
            Sum[s++] = P2[j++];
    }

    int k = 0;
    for(int x = 0; x < n1; x++)
        for(int y = 0; y < n2; y++)
            Mul[k++] = {P1[x].coef * P2[y].coef, P1[x].exp + P2[y].exp};

    cout << "\nSum Terms:\n";
    for(int p = 0; p < s; p++)
        cout << Sum[p].coef << " " << Sum[p].exp << endl;

    cout << "\nProduct Terms (unsimplified):\n";
    for(int p = 0; p < k; p++)
        cout << Mul[p].coef << " " << Mul[p].exp << endl;
}
