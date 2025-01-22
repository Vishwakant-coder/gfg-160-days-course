//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    struct Node *rev(struct Node *head){
    
        Node *prev = NULL;
        Node*next = NULL;
        Node *current = head;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
    
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
{
    num1 = rev(num1);
    num2 = rev(num2);

    int c = 0, sum = 0;
    Node* head = NULL;
    Node* tail = NULL;

    while (num1 != NULL || num2 != NULL || c != 0) {
        sum = (num1 ? num1->data : 0) + (num2 ? num2->data : 0) + c;
        c = sum / 10;
        // sum %= 10;
        Node* newNode = new Node(sum%10);
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }

        if (num1) num1 = num1->next;
        if (num2) num2 = num2->next;
    }
    Node* temp=rev(head);
    while(temp!=NULL){
        if(temp->data==0){
            temp=temp->next;
        }
        else{
            head=temp;
            break;
        }
        
    }

    return head;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends