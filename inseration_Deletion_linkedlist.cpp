#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

// Print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Convert vector to linked list and print it
Node* convert(vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    cout << "Linked List created: ";
    printList(head);
    return head;
}

// Delete head node
Node* deleteHead(Node* head) {
    if (head == nullptr) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Delete tail node
Node* deleteTail(Node* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

// Delete kth node
Node* deleteKth(Node* head, int k) {
    if (head == nullptr) return head;
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 1;
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && cnt < k) {
        prev = temp;
        temp = temp->next;
        cnt++;
    }

    if (temp != nullptr && prev != nullptr) {
        prev->next = temp->next;
        delete temp;
    }

    return head;
}

// Insert at head
Node* insertHead(Node* head, int val) {
    Node* temp = new Node(val, head);
    return temp;
}

// Insert at tail
Node* insertTail(Node* head, int val) {
    if (head == nullptr) return new Node(val);
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new Node(val);
    return head;
}

// Insert at kth position
Node* insertKth(Node* head, int el, int k) {
    if (head == nullptr) {
        if (k == 1) return new Node(el);
        else return nullptr;
    }
    if (k == 1) return new Node(el, head);

    int cnt = 1;
    Node* temp = head;
    while (temp != nullptr && cnt < k - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp != nullptr) {
        Node* x = new Node(el, temp->next);
        temp->next = x;
    }
    return head;
}

// Insert before a specific value
Node* insertBeforeVal(Node* head, int el, int val) {
    if (head == nullptr) return nullptr;
    if (head->data == val) return new Node(el, head);

    Node* temp = head;
    while (temp->next != nullptr) {
        if (temp->next->data == val) {
            Node* x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    Node* head = convert(arr);

    head = deleteHead(head);
    cout << "After deleting head: ";
    printList(head);

    head = deleteTail(head);
    cout << "After deleting tail: ";
    printList(head);

    head = deleteKth(head, 2);
    cout << "After deleting 2nd node: ";
    printList(head);

    head = insertHead(head, 100);
    cout << "After inserting at head: ";
    printList(head);

    head = insertTail(head, 200);
    cout << "After inserting at tail: ";
    printList(head);

    head = insertKth(head, 300, 3);
    cout << "After inserting 300 at 3rd position: ";
    printList(head);

    head = insertBeforeVal(head, 150, 200);
    cout << "After inserting 150 before 200: ";
    printList(head);

    return 0;
}
