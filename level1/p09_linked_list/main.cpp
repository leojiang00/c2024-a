#include <iostream>
using namespace std;
typedef struct Node {
    int data;
    Node *next;
}Node;
void creatnode(int data,Node** head) {
    Node *node = (Node *)malloc(sizeof(Node));
    node = *head;
    while(node->next!=NULL) {
        node = node->next;
    }
    Node *newnode = (Node *)malloc(sizeof(Node));
    node->next = newnode;
    newnode->data = data;
    newnode->next = NULL;
}
Node* reverse(Node* head) {
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    while (current->next != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
int main() {
    Node *head = NULL;
    head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    creatnode(1,&head);
    creatnode(2,&head);
    creatnode(3,&head);
    creatnode(4,&head);
    creatnode(5,&head);
    creatnode(6,&head);
    head = reverse(head);
    while(head->next!=NULL) {
        head = head->next;
        cout<<head->data<<endl;
    }
    return 0;
}