#include<iostream>
#include<math.h>
using namespace std;
struct Node{
    int value;
    Node *next;
    Node(int v):value(v), next(NULL){}
};
Node* numberToList(int num) {
    if (num == 0) return new Node(0);
    
    Node* head = NULL;
    while (num > 0) {
        int digit = num % 10;
        Node* newNode = new Node(digit);
        newNode->next = head;
        head = newNode;
        num /= 10;
    }
    return head;
}
Node* addTwoNumber(Node* l1, Node* l2){
    Node* dummyHead=new Node(0);
    Node* curr=dummyHead;
    int carry=0; // . Ví dụ 8+4=12 tức carry=1;
    while(l1!=NULL||l2!=NULL||carry!=0){
        int x=l1?l1->value:0;
        int y=l2?l2->value:0;
        int sum=carry+x+y;
        carry=sum/10;
        curr->next=new Node(sum%10);
        curr=curr->next;
        l1=l1?l1->next:NULL;
        l2=l2?l2->next:NULL;
    }
    Node* result=dummyHead->next;
    delete dummyHead;
    return result;
}
void printList(Node* head) {
    while (head != NULL) {
        cout << head->value;
        head = head->next;
    }
    cout << endl;
}
int main(){
    int n1, n2;
    cout << "Nhap so N1: "; cin >> n1;
    cout << "Nhap so N2: "; cin >> n2;

    // Convert integers to linked lists
    Node* l1 = numberToList(n1);
    Node* l2 = numberToList(n2);

    // Add the two numbers
    Node* result = addTwoNumber(l1, l2);

    // Print the result
    cout << "Tong 2 so la: ";
    printList(result);
    return 0;
}