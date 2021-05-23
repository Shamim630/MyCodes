#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head, *Head;
// struct Node* head1, *head2;

void insertGlobal(int x);
void Insert(struct Node** head, int x);
struct Node* insert(struct Node* head, int x);
void Insert_nth(int data, int n);
struct Node* insert_nth(struct Node* head, int data, int n);
struct Node* insert_end(struct Node* head, int data);

void printGlobal();
void print(struct Node* head);
void print_recursive_reverce(struct Node* head);
void print_recursive(struct Node* head);

struct Node* Reverse(struct Node* head);
struct Node* Reverse_recursive(struct Node* p);

void Delete(int n);
struct Node* delete(struct Node* head, int n);
void delete_NR(struct Node** head, int n);

// ----------------------------------------------------------------------------

int main()
{
    struct Node* head1 = NULL, *head2 = NULL;
    Head=NULL;
    printf("how many numbers? \n");
    int n,i,x;
    scanf("%d",&n);
    for (i = 0; i < n; i++){
        printf("Enter the number \n");
        scanf("%d",&x);
        Insert(&head1, x);
        head2=insert(head2, x);
        insertGlobal(x);
        Head=insert_end(Head, x);
        printGlobal();
        print(Head);
        print(head);
        print(head1);
        print(head2);
    }

    printf("Print lists: \n");
    printf("List is (recursive): ");
    print_recursive(Head);
    printf("\n");
    print_recursive_reverce(Head);
    printf("\n");
    printf("List is (recursive): ");
    print_recursive(head1);
    printf("\n");
    print_recursive_reverce(head1);
    printf("\n");

    printf("Reverce: \n");
    head1=Reverse(head1);
    head2=Reverse_recursive(head2);
    print(head1);
    print(head2);
    head=Reverse(head);
    Head=Reverse_recursive(Head);
    print(head);
    print(Head);

    printf("Insert nth possition: \n");
    Insert_nth(7,3);
    Insert_nth(9,1);
    Insert_nth(8,8);
    print(Head);
    head=insert_nth(head,7,3);
    head=insert_nth(head,9,1);
    head=insert_nth(head,8,8);
    print(head);
    head1=insert_nth(head1,7,3);
    head1=insert_nth(head1,9,1);
    head1=insert_nth(head1,8,8);
    print(head1);

    printf("After deletion: \n");
    Head=delete(Head, 1);
    Head=delete(Head, 5);
    print(Head);
    Delete(1);
    Delete(5);
    print(head);
    print(head2);
    head2=delete(head2, 4);
    head2=delete(head2, 1);
    print(head2);
    printf("\n");
    print(head1);
    delete_NR(&head1, 8);
    delete_NR(&head1, 4);
    delete_NR(&head1, 1);
    print(head1);

    return 0;
}

// -----------------------------------------------------------------------------

void Insert(struct Node** head, int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next =*head;
    *head=temp;
}

struct Node* insert(struct Node* head, int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next =head;
    head=temp;
    return head;
}

void insertGlobal(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next =head;
    head=temp;
}

void Insert_nth(int data, int n){
    struct Node* temp1=(struct Node*)malloc(sizeof(struct Node));
    temp1->data=data;
    temp1->next=NULL;
    if(n==1){
        temp1->next=Head;
        Head=temp1;
        return;
    }
    struct Node* temp2=Head;
    for(int i=0; i<n-2; i++){
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}

struct Node* insert_nth(struct Node* head, int data, int n){
    struct Node* temp1=(struct Node*)malloc(sizeof(struct Node));
    temp1->data=data;
    temp1->next=NULL;
    if(n==1){
        temp1->next=head;
        head=temp1;
        return head;
    }
    struct Node* temp2=head;
    for(int i=0; i<n-2; i++){
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
    return head;
}

struct Node* insert_end(struct Node* head, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next=NULL;
    if(head == NULL) head =temp;
    else{
        struct Node* temp1 = head;
        while (temp1->next != NULL) temp1 =temp1->next;
        temp1->next=temp;
    }
    return head;
}

void printGlobal()
{
    struct Node* temp = head;
    printf("List is: ");
    while (temp != NULL)
    {
        printf(" %d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void print(struct Node* head)
{
    printf("List is: ");
    while (head != NULL)
    {
        printf(" %d",head->data);
        head=head->next;
    }
    printf("\n");
}

void print_recursive_reverce(struct Node* head)
{
    if(head ==NULL) 
    {
        printf("List is (recursive reverce): ");
        return;
    }
    print_recursive_reverce(head->next);
    printf("%d ",head->data);
}

void print_recursive(struct Node* head)
{
    if(head ==NULL) return;
    printf("%d ",head->data);
    print_recursive(head->next);
}

struct Node* Reverse(struct Node* head)
{
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

struct Node* Reverse_recursive(struct Node* p)
{
    if(p->next == NULL) return p;
    struct Node* head;
    head=Reverse_recursive(p->next);
    p->next->next=p;
    p->next=NULL;
    return head;
}

void Delete(int n)
{
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

struct Node* delete(struct Node* head, int n)
{
    struct Node* temp1=head;
    if(n==1){
        head=temp1->next;
        free(temp1);
        return head;
    }
    int i;
    for(i=0; i<n-2; i++){
        temp1=temp1->next;
    }
    struct Node* temp2=temp1->next;
    temp1->next=temp2->next;
    free(temp2);
    return head;
}

void delete_NR(struct Node** head, int n)
{
    struct Node* temp1=*head;
    if(n==1){
        *head=temp1->next;
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


/*
// test input
5
4 5 6 7 8 9


*/