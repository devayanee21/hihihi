#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node *next, *prev;
} *head = NULL, *curr = NULL;

void add(string s) {
    Node* n = new Node();
    n->song = s;
    n->next = NULL;
    n->prev = curr;

    if (!head) head = n;
    else curr->next = n;

    curr = n;
}

void nextSong() {
    if (curr->next) curr = curr->next;
}

void prevSong() {
    if (curr->prev) curr = curr->prev;
}

void del() {
    if (!curr) return;

    Node* temp = curr;

    if (curr->prev) curr->prev->next = curr->next;
    else head = curr->next;

    if (curr->next) curr->next->prev = curr->prev;

    curr = curr->next ? curr->next : head;

    delete temp;
}

void show() {
    cout << "Playlist: ";
    for(Node* t = head; t; t = t->next)
        cout << t->song << " ";
    cout << endl;
}

int main() {
    add("Song1");
    add("Song2");
    add("Song3");

    show();
    nextSong();
    del();
    show();
}



/*Add a new song
Delete a song
Move next / previous
Display playlist

Best data structure: Doubly Linked List
Because we can move forward & backward between songs.
Feature	What happens in Linked List
Add Song	     Create new node → add to end
Delete Song	     Remove current node and reconnect neighbors
Next Song	     Move pointer to next node
Previous Song	 Move pointer to prev node
Display	         Traverse and print all songs
 current pointer always tells which song is playing
 A music playlist keeps changing – add, delete, reorder quickly.
In arrays we must shift elements, but in linked list we only change pointers.
Also linked list size grows dynamically based on songs, no memory wastage.*/