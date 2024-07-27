#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1 = nullptr, Node* prev1 = nullptr) {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node* convertall(const vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
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

void deleteNode(Node*& head, int value) {
    if (head == nullptr) return;

    // Handle the case where the head needs to be deleted
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return;
    }

    Node* current = head;

    // Traverse the list to find the node to delete
    while (current != nullptr && current->data != value) {
        current = current->next;
    }

    // If the node was not found, do nothing
    if (current == nullptr) return;

    // Unlink the node from the list and delete it
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    }
    delete current;
}

Node* insertAtEnd(Node* head, int value) {
    Node* y = new Node(value);

    if (head == nullptr) {
        return y;
    }

    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = y;
    y->prev = curr;

    return head;
}

int getCount(Node* head) {
    int cnt = 0;
    Node* current = head;
    while (current != nullptr) {
        cnt++;
        current = current->next;
    }
    return cnt;
}

bool searchKey(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}


void addNode(Node *head, int pos, int data)
{
   // Your code here
      if(head == NULL) return ;
      int cnt=0;
      Node* curr=head;
      while(cnt!=pos){
          curr=curr->next;
          cnt++;
      }
      Node * y=new Node(data);
      y->next=curr->next;
      curr->next= y;
      y->prev=curr;
}


int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    Node* head = convertall(v);

    cout << "Original list: ";
    printList(head);

    // Insert a node at the end
    head = insertAtEnd(head, 7);
    cout << "List after inserting 7 at the end: ";
    printList(head);

    // Delete a node with value 3
    deleteNode(head, 3);
    cout << "List after deleting 3: ";
    printList(head);

    // Count the number of nodes
    int count = getCount(head);
    cout << "Count of nodes: " << count << endl;

    // Search for a key in the list
    bool found = searchKey(head, 5);
    cout << "Search for key 5: " << (found ? "Found" : "Not Found") << endl;

    deleteList(head);
    return 0;
}
