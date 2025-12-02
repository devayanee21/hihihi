/*4)	Write a program to implement a greedy algorithm to solve a real-world
 optimization problem, such as maximizing non-overlapping events in a scheduler
  (activity selection). Represent the logic using pseudo-code and a flowchart. 
  Analyse the algorithm's time complexity (Best, Average, Worst Case)
 using Big-O, Θ, and Ω notations.
 How logic works in code:

1️⃣ Sort activities by finish time
2️⃣ Always pick first finishing activity
3️⃣ Next activity is valid only if:

start_time >= last_selected_finish_time
➡ More space left for next tasks
 
 
 
 */


#include <iostream>
using namespace std;

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = 6;

    cout << "Selected activities:\n";
    int last = 0;
    cout << "Activity 0\n";

    for(int i = 1; i < n; i++) {
        if(start[i] >= finish[last]) {
            cout << "Activity " << i << endl;
            last = i;
        }
    }
}
