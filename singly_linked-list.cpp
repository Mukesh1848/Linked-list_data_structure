#include <iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;
    
    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
void insertAtHead(Node* &head , int d){
    
    Node* temp = new Node(d);
    
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head ,Node* &tail, int position , int d){
    
     //insert at Start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

void deleteNode(int position , Node* &head){
    
   //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else{
         //deleting any middle node or last node
         Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;
    }
}

int main() {
    
    // creation of a Node
    Node *node1 = new Node(10);
    //  cout<<node1-> data<<endl;
    //  cout<<node1->next<<endl;
     
    // Head and Tail pointed to node1
    Node* head = node1;
    Node* tail = node1;

   // print linked  list
     print(head);

  // insertAtHead of singly linked list 
      insertAtHead(head,20);
      print(head);
      insertAtHead(head,30);
      print(head);
      
    //  insertion of tali in singly linked list 
    
     insertAtTail(tail, 50);
     print(head);
     insertAtTail(tail, 70);
     print(head);
    
    // insertion of linked list in middle(position)
    insertAtPosition(head, tail ,3 ,100);
    print(head);
     insertAtPosition(head, tail ,1,200);
    print(head);
     insertAtPosition(head, tail , 7,500);
    print(head);
    
     cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;
    
    // deletion of singly linked list
    deleteNode(3,head);
    print(head);
    return 0;
}
