#include <iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
    struct record *prev;
};
struct record *tail=NULL;

char menu(){
    char ch;
    cout << "=======================" << endl;
    cout << "\t Menu" << endl;
    cout << "=======================" << endl;
    cout << "1) Insert" << endl;
    cout << "2) Print min to max and max to min" << endl;
    cout << "3) Exit" << endl;
    cout << "Please choose >  ";
    cin >> ch;
    return ch;
}

void Cout(struct record *head){
    cout << "List = ";
    struct record *p;
    p=head;
    while(p!=NULL){
        cout << p->value <<" ";
        p=p->next;
    }
    cout << "\n";
}

struct record *Insert(struct record *head,int data){
    if(head==NULL){ //don't have node
        head=new struct record;
        head->value=data;
        head->next=NULL;
        head->prev=NULL;
        tail=head;
    }else{ //have node >=1
        struct record *node=new struct record;
        node->value=data;
        if(data<head->value){ //insert first node
            node->prev=NULL;
            node->next=head;
            head->prev=node;
            head=node;
        }else{ //insert middle node
            struct record *p=head;
            while(p->next!=NULL){
                if(data<p->next->value){
                    node->next=p->next;
                    p->next->prev=node;
                    node->prev=p;
                    p->next=node;
                    break;
                }
                p=p->next;
            }
            if(data>tail->value){ //insert last node
                node->next=NULL;
                node->prev=tail;
                tail->next=node;
                tail=node;
            }
        }
    }
    return head;
}

void Print(struct record *head){
    struct record *p=head;
    cout << "Min to Max :";
    while(p!=NULL){
        cout << p->value << " ";
        p=p->next;
    }
    cout << "\nMax to Min :";
    p=tail;
    while(p!=NULL){
        cout << p->value << " ";
        p=p->prev;
    }
}

int main(){
    int data;
    struct record *head=NULL;
    while(true){
        switch(menu()){
        case '1' :
            cout << "Insert : ";
            cin >> data;
            head=Insert(head,data);
            Cout(head);
            cout << "\n";
            break;
        case '2' :
            Print(head);
            cout << "\n";
            break;
        case '3' :
            return 0;
        default:
            cout << "Not in the options.\n" << endl;
            break;
        }
    }
}
