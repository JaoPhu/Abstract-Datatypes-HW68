#include <iostream>
using namespace std;

struct Node{
    char ch;
    struct Node *next;
};

typedef struct Node *Stack;

Stack CreateStack(){
    Stack S=new struct Node;
    if(S==NULL){
        cout << "Stack OverFlow" << endl;
        return NULL;
    }
    S->next=NULL;
    return S;
}

bool IsEmpty(Stack S){
    return S->next==NULL;
}

void Push(char c,Stack S){
    Stack Tmp=new struct Node;
    if(Tmp==NULL){
        cout << "Stack OverFlow" << endl;
    }else{
        Tmp->ch=c;
        Tmp->next=S->next;
        S->next=Tmp;
    }
}

void Pop(Stack S){
    if(IsEmpty(S)){
        cout << "Stack UnderFlow" << endl;
    }else{
        Stack p=S->next;
        S->next=S->next->next;
        delete(p);
    }
}

char Top(Stack S){
    if(!IsEmpty(S)){
        return S->next->ch;
    }else{
        return '\0';
    }
}

bool OpenSym(char c){
    return (c=='('||c=='['||c=='{');

}

bool CheckMatch(char c,Stack S){
    char ch=Top(S);
    return (ch=='(' && c==')' || ch=='[' && c==']' || ch=='{' && c=='}');
}

int main(){
    char c;
    Stack S=CreateStack();
    cout << "Input : ";
    c=getchar();
    while(c!='\n'){
        if(!OpenSym(c)){
            if(IsEmpty(S)){
               cout << "No open symbol" << endl;
               return 0;
            }else if(CheckMatch(c,S)){
                Pop(S);
            }else{
                cout << "Not match" << endl;
                return 0;
            }
        }else{
            Push(c,S);
        }
        c=getchar();
    }
    if(IsEmpty(S)){
        cout << "Success" << endl;
        return 0;
    }else{
        cout << "Stack is not empty" << endl;
        return 0;
    }
}
