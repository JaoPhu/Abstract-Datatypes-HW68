#include <iostream>
using namespace std;

struct Node;
typedef struct Node *Stack;

struct Node{
    int value;
    Stack next;
};

int IsEmpty(Stack S);
Stack CreateStack(void);
void MakeEmpty(Stack S);
void Push(int X,Stack S);
void Pop(Stack S);
void Top(Stack S);

char menu(){
    char n;
    cout << "=======================" << endl;
    cout << "\t Menu" << endl;
    cout << "=======================" << endl;
    cout << "1) Push" << endl;
    cout << "2) Pop" << endl;
    cout << "3) Top" << endl;
    cout << "4) Exit" << endl;
    cout << "Please choose >  ";
    cin >> n;
    return n;
}

int main(){
    int n;
    Stack S=NULL;
    S=CreateStack();
    while(true){
        switch(menu()){
        case '1' :
            cout << "Push : ";
            cin >> n;
            Push(n,S);
            cout <<  "\n";
            break;
        case '2' :
            Pop(S);
            break;
        case '3' :
            Top(S);
            cout <<  "\n";
            break;
        case '4' :
            return 0;
        default :
            cout << "Not in the options.\n" << endl;
            break;
        }
    }

}

Stack CreateStack(void){
    Stack S;
    S=new struct Node;
    if(S==NULL){
        cout << "Out of space!!!"<<endl;
    }
    S->next=NULL;
    return S;
}

void Push(int X,Stack S){
    Stack TmpCell;
    TmpCell=new struct Node;
    if(TmpCell==NULL){
        cout << "Out of space!!!"<<endl;
    }else{
        TmpCell->value=X;
        TmpCell->next=S->next;
        S->next=TmpCell;
        Top(S);
    }
}

void MakeEmpty(Stack S){
    if(S==NULL){
        cout << "Out of space!!!"<<endl;
    }else{
        while(!IsEmpty(S))
            Pop(S);
    }
}

int IsEmpty(Stack S){
    return S->next==NULL;
}

void Top(Stack S){
    if(!IsEmpty(S)){
        cout << "Top = " << S->next->value << endl;
    }else{
        cout << "Empty Stack!!!" << endl;
    }
}

void Pop(Stack S){
    Stack FirstCell;
    if(IsEmpty(S)){
        cout << "Stack Underflow\n" << endl;
    }else{
        Top(S);
        FirstCell=S->next;
        S->next=S->next->next;
        delete(FirstCell);
        cout << "Pop success!\n" << endl;
    }
}
