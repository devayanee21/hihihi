/*1)	Write a program to implement Gauss’s multiplication method. 
Display the number of recursive calls, multiplications, and additions are required to 
implement this method.
1️⃣ Split numbers into:

upper digit & lower digit → x1, x0, y1, y0
2️⃣ Compute three recursive values:

p = x1 * y1
q = x0 * y0
r = (x1 + x0) * (y1 + y0)


3️⃣ Final answer using Gauss Formula:

result = p*100 + (r - p - q)*10 + q


4️⃣ Counters track:

Recursive calls

Multiplications

Additions

*/


#include <iostream>
using namespace std;

int rec = 0, mul = 0, addi = 0;

int gauss(int x, int y) {
    rec++;

    if (x < 10 && y < 10) { // Base case
        mul++;
        return x * y;
    }

    int x1 = x / 10;
    int x0 = x % 10;
    int y1 = y / 10;
    int y0 = y % 10;

    int p = gauss(x1, y1);
    int q = gauss(x0, y0);

    addi += 2;
    int r = gauss(x1 + x0, y1 + y0);

    addi += 3;
    return (p * 100) + ((r - p - q) * 10) + q;
}

int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    int ans = gauss(x, y);

    cout << "\nResult = " << ans << endl;
    cout << "Recursive Calls = " << rec << endl;
    cout << "Multiplications = " << mul << endl;
    cout << "Additions = " << addi << endl;
}


/*
Split numbers (high digit & low digit)

Recursive calls:

p = x1*y1

q = x0*y0

r = (x1+x0)*(y1+y0)

Use Gauss formula:

xy = p*100 + (r - p - q)*10 + q
*/