#include <iostream>
using namespace std;

struct record{
    char value;
    struct record *next;
};

char menu(){
    char n;
    cout << "=======================" << endl;
    cout << "\t Menu" << endl;
    cout << "=======================" << endl;
    cout << "1) Input p1" << endl;
    cout << "2) Input p2" << endl;
    cout << "3) Add" << endl;
    cout << "4) Exit" << endl;
    cout << "Please choose >  ";
    cin >> n;
    return n;
}

void Print(struct record *head){
    struct record *p=head;
    while(p!=NULL){
        cout << p->value;
        p=p->next;
    }
    cout << "\n\n";
}

int Count(struct record *head){
    int n=0;
    struct record *p=head;
    while(p!=NULL){
        n++;
        p=p->next;
    }
    return n;
}

struct record *Insert(struct record *head,string str){
    for(char ch:str){
        struct record *node=new struct record;
        node->value=ch;
        node->next=NULL;
            if(head==NULL){ //don't have node in head
                head=node;
            }else{ //have node in head then >0
                struct record *p=head;
                while(p->next!=NULL){
                    p=p->next;
                }
                p->next=node;
            }
    }
    return head;
}

string AddNumber(struct record *p1,struct record *p2){
    string result="";
    int carry=0;
    int len1=Count(p1);
    int len2=Count(p2);
    while(len1<len2){
        struct record *node=new struct record;
        node->value='0';
        node->next=p1;
        p1=node;
        len1++;
    }
    while(len1>len2){
        struct record *node=new struct record;
        node->value='0';
        node->next=p2;
        p2=node;
        len2++;
    }
    for(int i=len1;i>0;i--){
        struct record *run1=p1,*run2=p2;
        for(int j=1;j<i;j++){
            run1=run1->next;
            run2=run2->next;
        }
        int digit1=(run1->value)-'0';
        int digit2=(run2->value)-'0';

        int sum=digit1+digit2+carry;
        carry=sum/10;
        result=(char)(sum%10+'0')+result;
    }
    if(carry>0){
        result=(char)(carry+'0')+result;
    }
    return result;
}

int main(){
    struct record *p1=NULL,*p2=NULL;
    string str;
    while(true){
        switch(menu()){
        case '1' :
            cout << "Input : ";
            cin >> str;
            cout << "P1 = ";
            p1=Insert(p1,str);
            Print(p1);
            break;
        case '2' :
            cout << "Input : ";
            cin >> str;
            cout << "P2 = ";
            p2=Insert(p2,str);
            Print(p2);
            break;
        case '3' :
            cout << "Output : ";
            cout << AddNumber(p1,p2);
            cout<<"\n\n";
            break;
        case '4' :
            return 0;
        default :
            cout << "Not in the options.\n" << endl;
            break;
        }
    }

}
