#include <iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;
    Node* prev;
    
    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node* &head) {

     Node* temp  = head ;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
}

int getLength(Node* head){
    Node* temp = head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void insertAtHead(Node* &head , int d , Node* &tail){
    // if list are empty
    if(head==NULL){
         Node* temp = new Node(d);
         head= temp;
         tail = temp;
    }
    else{
            Node* temp = new Node(d);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
}

void insertAtTail(Node* &head , Node* &tail , int d){
//     if list are empty  
      if(head==NULL){
         Node* temp = new Node(d);
         head = temp;
         tail = temp;
      }
      else{
          Node* temp = new Node(d);
          tail->next = temp;
          temp->prev = tail;
          tail = temp;
      }
}

void insertAtPosition(Node* &head , Node* &tail , int position , int d){
    
    //insert at Start/head
    if(position == 1) {
        insertAtHead(head,d,tail);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last/tail Position
    if(temp -> next == NULL) {
        insertAtTail(head,tail,d);
        return ;
    }
    
    //creating a node for d(position)
    Node* nodeToInsert = new Node(d);
    nodeToInsert ->next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

void deleteNode(Node* &head , Node* &tail, int position){
    // delete at first/ head node
    if(position==1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;  //
        temp->next = NULL;
        delete temp;
    }
    else{
            // delete any position or tail/last node
            Node* curr = head;
            Node* prev = NULL;
            
            int cnt =1;
            while(cnt<position){
                prev = curr;
                curr = curr->next;
                cnt++;
            }
           curr->prev = NULL;
           prev ->next = curr->next;
           curr->next =NULL;
           delete curr;
    }
}

int main() {
    
    // creation of a Node
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    
    // length of doubly linked list
    cout<<getLength(head)<<endl;
   
    insertAtHead(head, 20, tail);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    //  cout<<getLength(head)<<endl;
    insertAtHead(head, 50, tail);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    
    insertAtTail(head, tail , 100);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    insertAtTail(head, tail , 300);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    
    insertAtPosition(head,tail,1,500);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    
    insertAtPosition(head,tail,7,800);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    
    insertAtPosition(head,tail,4,1000);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    
    // deletetion of node 
    
    deleteNode(head,tail,8);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    return 0;
}
