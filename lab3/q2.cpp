    #include<iostream>
    using namespace std;

    class node {
    public:
        int data;
        node* next;

        node(int val) : data(val), next(NULL) {}
    };


    void insert_start(node* &head, int data) {
        node* newnode = new node(data);
        newnode->next = head;
        head = newnode;
    }

    void insert_end(node* &head, int data) {
        if (head == NULL) {
            head = new node(data);
            return;
        }
        node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new node(data);
    }

    void displayLL(node* head) {
        node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void reversing(node* &newHead, node* head) {
        node* current = head;
        while (current != NULL) {
            insert_start(newHead, current->data);
            current = current->next;
        }
    }

    bool checkPalindrome(node* head) {
        // reverse
        node* reversedHead = NULL;
        reversing(reversedHead, head);

        // Compare both
        node* current1 = head;
        node* current2 = reversedHead;
        while (current1 != NULL && current2 != NULL) {
            if (current1->data != current2->data) {
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }
        return true;
    }


    int main() {
        int val;
        node* head = NULL;

        cout << "Enter numbers: (-1 to stop): ";
        cin >> val;
        while (val != -1) {
            insert_end(head, val);
            cin >> val;
        }

        displayLL(head);

        if (checkPalindrome(head)) {
            cout << "The linked list is a palindrome." << endl;
        } else {
            cout << "The linked list is not a palindrome." << endl;
        }

        return 0;
    }
