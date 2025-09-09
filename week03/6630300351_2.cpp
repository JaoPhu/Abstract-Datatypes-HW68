#include <iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
};

int menu(){
    int choose;
    cout << "\n==========Menu========" << endl;
    cout << "    + 1) Insert +" << endl;
    cout << "    + 2) Print + "<< endl;
    cout << "    + 3) Exit + "<< endl;
    cout << "=======================" << endl;
    cout << "   Please choose >  ";
    cin >> choose;
    return choose;
}

struct record *Insert(struct record *head,int data){
    struct record *node,*p;
    if(head==NULL){ //check == null
        head=new struct record;
        head->value=data;
        head->next=NULL;
    }else{
        node=new struct record;
        node->value=data;
        if(data<head->value){ // insert first
            node->next=head;
            head=node;
        }else{
            p=head;
            while(p->next!=NULL){
                if(data<p->next->value){ //insert midble
                    node->next=p->next;
                    p->next=node;
                    break;
                }
                    p=p->next; //wake pointer p
            }
            if(p->next==NULL){ //insert last
                p->next=node;
                node->next=NULL;
            }
        }
    }
    return head;
}

void Print(struct record *head,int count_size){
    struct record *p = head;
    if(head==NULL){
        cout << "List Empty" << endl;

    }else if(count_size==1){
        cout << "Print \t\t : " << p->value;
        cout << "\n";

        cout << "Print first half : " << p->value;
        cout << "\n";

        cout <<  "Print second half: ";
        cout << "\n";

    }else{
        cout << "Print \t\t : ";
        struct record *tmp;
        tmp=head;
        while(tmp!=NULL){
            cout << tmp->value <<" ";
            tmp=tmp->next;
        }
        cout << "\n";

        cout << "Print first half : ";
        for(int i=0; i<count_size/2; i++){
            cout << p->value << " ";
            p=p->next;
        }
        cout << "\n";

        cout <<  "Print second half: ";
        for(int i=count_size/2; i<count_size; i++){
            cout << p->value << " ";
            p=p->next;
        }
        cout << "\n";

    }

}

void Cout(struct record *head){
    cout << "Output = ";
    struct record *tmp;
    tmp=head;
    while(tmp!=NULL){
        cout << tmp->value <<" ";
        tmp=tmp->next;
    }
    cout << "\n";
}

int main(){
    int count_size = 0;
    struct record *head = NULL;
    while(true){
        int data;
        switch(menu()){
            case 1 :
                cout << "Enter : ";
                cin >> data;
                head=Insert(head,data);
                Cout(head);
                count_size++;
                break;
            case 2 :
                Print(head,count_size);
                break;
            case 3 :
                return 0;
            default:
                break;
        }
    }
    return 0;
}
