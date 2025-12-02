/*3)	Write a program to implement a greedy algorithm to solve a real-world 
optimization problem, such as minimizing currency notes in a digital wallet (coin change). 
write the logic using pseudo-code and a flowchart. Analyse the algorithm's time complexity 
(Best, Average, Worst Case) using Big-O, Θ, and Ω notations.

Finds minimum number of coins for a given amount
(E.g., ATM / UPI / Paytm wallet)
1️⃣ Coins sorted largest → smallest
2️⃣ While coin value ≤ amount
➡ subtract and count it
3️⃣ Repeat till amount becomes 0

Example:
Amount = ₹46
20 + 20 + 5 + 1*/



#include <iostream>
using namespace std;

int main() {
    int coins[] = {2000, 500, 200, 100, 50, 20, 10, 5, 1};
    int n = 9, amount;
    cout << "Enter amount: ";
    cin >> amount;

    int cnt = 0;

    for(int i = 0; i < n; i++) {
        while(amount >= coins[i]) {
            amount -= coins[i];
            cnt++;
        }
    }

    cout << "Minimum coins needed: " << cnt;
}
