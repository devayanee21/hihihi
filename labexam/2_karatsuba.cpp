/*2)	Write a program to implement Karatsuba’s algorithm for multiplying large integers. 
Display the number of recursive calls, multiplications, 
and additions are required to implement this method.
Even more optimized multiplication for large numbers
(It is based on Gauss
1️⃣ Break numbers into two parts
2️⃣ Compute only:

ac = karatsuba(x1, y1)
bd = karatsuba(x0, y0)
mid = karatsuba(x1 + x0, y1 + y0) - ac - bd

3️⃣ Final Answer:

result = ac*100 + mid*10 + bd
“Karatsuba is a faster divide-and-conquer multiplication


*/



#include <iostream>
using namespace std;

int rec2 = 0, mul2 = 0, add2 = 0;

int karatsuba(int x, int y) {
    rec2++;

    if (x < 10 && y < 10) {
        mul2++;
        return x * y;
    }

    int a = x / 10;
    int b = x % 10;
    int c = y / 10;
    int d = y % 10;

    int ac = karatsuba(a, c);
    int bd = karatsuba(b, d);
    int adbc = karatsuba(a + b, c + d) - ac - bd;

    add2 += 4;
    return (ac * 100) + (adbc * 10) + bd;
}

int main() {
    int x, y;
    cin >> x >> y;

    int res = karatsuba(x, y);

    cout << "Result = " << res << endl;
    cout << "Recursive Calls = " << rec2 << endl;
    cout << "Multiplications = " << mul2 << endl;
    cout << "Additions = " << add2 << endl;
}


/*Logic Explanation

Uses formula:

(x1*10 + x0)(y1*10 + y0)
= ac*100 + (ad + bc)*10 + bd


Calculates (a+b)(c+d) so no separate ad and bc multiplications
➡ Only 3 multiplications recursively
➡ Faster than Gauss*/