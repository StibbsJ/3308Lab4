#include <iostream>

using namespace std;

struct int_node{
    int value;
    struct int_node *next;
};

void print_int_list(int_node *n){
    int_node *temp = n;
    while(temp->next != NULL){
        cout<<temp->value<<endl;
        temp = temp->next;
    }
    cout<<temp->value<<endl;
}

int main(){
    int_node a;
    int_node b;
    int_node c;
    int_node d;
    a.value = 0;
    a.next = &b;
    b.value = 1;
    b.next = &c;
    c.value = 2;
    c.next = &d;
    d.value = 3;
    d.next = NULL;
    print_int_list(&a);
}
