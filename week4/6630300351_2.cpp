#include <iostream>
using namespace std;

struct record{
    char c;
    struct record *next;
};

char menu(){
    char n;
    cout << "=======================" << endl;
    cout << "\t Menu" << endl;
    cout << "=======================" << endl;
    cout << "1) Input secret code" << endl;
    cout << "2) Decode" << endl;
    cout << "3) Exit" << endl;
    cout << "Please choose >  ";
    cin >> n;
    return n;
}

int count_list(struct record *head){
    int n=0;
    struct record *p=head;
    while(p!=NULL){
        n++;
        p=p->next;
    }
    return n;
}

void decode(struct record *head){
    int size_list=count_list(head);
    struct record *p1=head,*p2=head->next;
    while(p1!=NULL){
        cout << p1->c;
        if(p1->next!=NULL){ //prevent errors case last node already but p still walking
            p1=p1->next->next;
        }else{break;}
    }
    while(p2!=NULL){
        cout << p2->c;
        if(p2->next!=NULL){
            p2=p2->next->next;
        }else{break;}
    }

}

struct record *Insert(struct record *head,string text){
    for(char ch:text){ //loop in string
        struct record *node=new struct record; //create node link new box
        node->c=ch; //node have char now
        node->next=NULL; //set node next = NULL
        //node = 0
        if(head==NULL){ //case at head not have node
            head=node; //head copy address in node
        }else{ //node >=1
            struct record *p=head; //p copy address in head
            while(p->next!=NULL){ //if p next = NULL while will break
                p=p->next; // p stop ; p link last node already
            }
            p->next=node; //last node next = new node
            //new node = last node now
        }
    }
   return head;
}

int main(){
    string text;
    struct record *head=NULL;
    while(true){
        switch(menu()){
        case '1' :
            cout << "Code : ";
            cin >> text;
            head=Insert(head,text);
            cout << "\n";
            break;
        case '2' :
            decode(head);
            cout << "\n\n";
            break;
        case '3' :
            return 0;
        default:
            cout << "Not in the options.\n" << endl;
            break;
        }
    }
}
