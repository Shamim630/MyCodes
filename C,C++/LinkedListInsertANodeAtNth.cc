#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};
struct Node* head; 
void Insert(int data, int x);
struct Node* insert_last(struct Node* head, int data);
void print();
void print(struct Node* head);
void Delete(int n);
struct Node* Reverse(struct Node* head);
struct Node* Reverse_recurtion(struct Node* head);

int main()
{
    // head = NULL;
    struct Node* Head=NULL;
    Head = insert_last(Head, 4);
    Head = insert_last(Head, 2);
    Head = insert_last(Head, 3);
    Head = insert_last(Head, 7);
    Head = insert_last(Head, 8);
    Head = insert_last(Head, 9);
    Head = insert_last(Head, 6);
    print(Head);
    // Insert(2,1);
    // Insert(3,2);
    // Insert(4,1);
    // Insert(6,3);
    // Insert(8,3);
    // print();
    // int n;
    // cout<<"Enter a position : \n";
    // cin>>n;
    // Delete(n);
    // print();
    // head=Reverse(head);
    // print();
    cout<<"\n";
    Head=Reverse_recurtion(Head);
    print(Head);
}
void Insert(int data, int n){
    Node* temp1=new Node();
    temp1->data=data;
    temp1->next=NULL;
    if(n==1){
        temp1->next=head;
        head=temp1;
        return;
    }
    Node* temp2=head;
    for(int i=0; i<n-2; i++){
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}
void print(){
    Node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
void Delete(int n){
    struct Node* temp1=head;
    if(n==1){
        head=temp1->next;
        free(temp1);
        return;
    }
    int i;
    for(i=0; i<n-2; i++){
        temp1=temp1->next;
    }
    struct Node* temp2=temp1->next;
    temp1->next=temp2->next;
    free(temp2);
}
struct Node* Reverse(struct Node* head){
    struct Node* current, *prev,*Next;
    current=head;
    prev=NULL;
    while(current != NULL){
        Next=current->next;
        current->next=prev;
        prev=current;
        current=Next;
    }
    head=prev;
    return head;
}
struct Node* Reverse_recurtion(struct Node* p){
    if(p->next == NULL) return p;
    struct Node* head;
    head=Reverse_recurtion(p->next);
    p->next->next=p;
    p->next=NULL;
    return head;
}
struct Node* insert_last(struct Node* head, int data){
    struct Node* temp = new Node();
    temp->data = data;
    temp->next=NULL;
    if(head == NULL) head =temp;
    else{
        Node* temp1 = head;
        while (temp1->next != NULL) temp1 =temp1->next;
        temp1->next=temp;
    }
    return head;
}
void print(struct Node* head){
    if(head ==NULL) return;
    cout<<head->data<<" ";
    print(head->next);
}