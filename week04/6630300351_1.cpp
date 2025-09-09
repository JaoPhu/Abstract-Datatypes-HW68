#include <iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
};

int menu(){
    int choose;
    cout << "=======================" << endl;
    cout << "\t Menu" << endl;
    cout << "=======================" << endl;
    cout << "1) Insert " << endl;
    cout << "2) Delete "<< endl;
    cout << "3) Count "<< endl;
    cout << "4) Print mid to max,max to min "<< endl;
    cout << "5) Print first half and second half "<< endl;
    cout << "6) Exit "<< endl;
    cout << "\tPlease choose >  ";
    cin >> choose;
    return choose;
}

int Count(struct record *head){
    int count_list = 0;
    struct record *tmp;
    tmp=head;

    while(tmp!=NULL){
        tmp=tmp->next;
        count_list++;
    }
    return count_list;
}

void Cout(struct record *head){
    cout << "List = ";
    struct record *tmp;
    tmp=head;
    while(tmp!=NULL){
        cout << tmp->value <<" ";
        tmp=tmp->next;
    }
    cout << "\n\n";
}

void CoutMaxToMin(struct record *head){
    cout << ":";
    struct record *tmp;
    tmp=head;
    while(tmp!=NULL){
        cout << tmp->value <<" ";
        tmp=tmp->next;
    }

    cout << "\n";
    cout << ":";

    int n = Count(head);
    for(int i=n; i>0; i--){
        struct record *tmp2=head;
        for(int j=1; j<i; j++){
            tmp2=tmp2->next;
        }
        cout << tmp2->value <<" ";
    }
    cout << "\n";
}

void Print(struct record *head){
    struct record *p = head;
    int n = Count(head);

    if(head==NULL){
        cout << "List Empty" << endl;

    }else if(n==1){
        cout << "First = : " << p->value;
        cout << "\n";

        cout <<  "Second = ";
        cout << "\n\n";

    }else{
        cout << "First = ";
        for(int i=0; i<n/2; i++){
            cout << p->value << " ";
            p=p->next;
        }
        cout << "\n";

        cout <<  "Second = ";
        for(int i=n/2; i<n; i++){
            cout << p->value << " ";
            p=p->next;
        }
        cout << "\n\n";

    }

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
                if(data<p->next->value){ //insert middle
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

struct record *Delete(struct record *head,int data){
    struct record *tmp,*p;

    if(head==NULL){
        cout << "Empty List!" << endl;
        return head;
    }

    if(head->next==NULL){ //check head next == null  ; node==1
        if(head->value==data){ //delete node have only one
            delete(head);
            head=NULL;
            cout << " Empty List!" << endl;
        }else{
            cout << "Can't delete no " << data << " in List!" << endl;
        }
        return head;
    }

    if(data==head->value){ // delete first
        tmp=head;
        head=head->next;
        delete(tmp);
        Cout(head);
        return head;
    }

    p=head;

    while(p->next!=NULL){
        if(p->next->value==data){ //delete middle and last
            tmp=p->next;
            p->next=p->next->next;
            //case delete middle p next = p next next collect[address]
            //case delete last p next = p next next collect[NULL]
            delete(tmp);
            Cout(head);
            return head;
        }
        p=p->next; //wake pointer p
    }

    cout << "Can't delete no " << data << " in List!" << endl;
    return head;
}

int main(){
    int count_size = 0;
    struct record *head = NULL;
    while(true){
        int data;
        switch(menu()){
            case 1 :
                cout << "Insert : ";
                cin >> data;
                head=Insert(head,data);
                Cout(head);
                break;
            case 2 :
                cout << "Delete : ";
                cin >> data;
                head=Delete(head,data);
                break;
            case 3 :
                cout << "Count = " << Count(head) << endl << endl;
                break;
            case 4 :
                CoutMaxToMin(head);
                cout << "\n" ;
                break;
            case 5 :
                Print(head);
                break;
            case 6 :
                return 0;
        }
    }
    return 0;
}
