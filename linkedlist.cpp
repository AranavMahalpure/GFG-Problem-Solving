#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

Node* convertall(const vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    Node* head = convertall(v);
    printList(head);
    deleteList(head);
    return 0;
}
