#include <iostream>
#include <vector>

using namespace std;
//https://bit.ly/3URZnst
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



**// delete the Specific Element in The LInkedlist**
        //https://leetcode.com/problems/delete-node-in-a-linked-list/description/
void deleteNode(Node*& head, int value) {
    if (head == nullptr) return;
    // Handle the case where the head needs to be deleted
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* current = head;
    Node* prev = nullptr;
    // Traverse the list to find the node to delete
    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->next;
    }
    // If the node was not found, do nothing
    if (current == nullptr) return;
    // Unlink the node from the list and delete it
    prev->next = current->next;
    delete current;
}


// Insert At a end of the linkedlist 
https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=linked-list-insertion
Node* insertAtEnd(Node* head, int value) {
    Node* y = new Node(value);
    
    if (head == nullptr) {
        // If the list is empty, the new node becomes the head
        return y;
    }
    
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    
    // Set the next of the last node to the new node
    curr->next = y;
    
    return head;
}

// conuting  the Length Of the Linkedlist 
https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-nodes-of-linked-list
int getCount(struct Node* head) {
          int cnt=1;
          while(head->next!=nullptr){
              cnt++;
              head=head->next;
          }
          return cnt;
        // Code here
    }

// Searching the element in the Linkedlist 

//https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-in-linked-list-1664434326
 bool searchKey(int n, struct Node* head, int key) {
        // Code here
        while(head->next!=nullptr){
            if(head->data==key){
                return true;
            }
            head=head->next;
        }
        return 0;
    }


int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    Node* head = convertall(v);
    printList(head);
    deleteList(head);
    return 0;
}
