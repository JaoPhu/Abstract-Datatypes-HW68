#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Node{
    int value;
    struct Node *next;
};

typedef Node *Stack;

Stack CreateStack(){
    Stack S=new Node{0,nullptr};
    return S;
}

bool IsEmpty(Stack S){
    return S->next==nullptr;
}

void Push(int n,Stack S){
    Stack tmp=new Node{n,S->next};
    S->next=tmp;
}

void Pop(Stack S){
    Stack p=S->next;
    S->next=S->next->next;
    delete(p);
}

int Top(Stack S){
    if(IsEmpty(S)) return 0;
    return S->next->value;
}

bool IsOperator(string s){
    return (s=="-"||s=="+"||s=="*"||s=="/");
}

int main(){
    string s="";
    Stack S=CreateStack();
    cout << "Input : ";
    while(cin >> s){
        if(s=="."){
            break;
        }else if(IsOperator(s)){
            int num2=Top(S);
            Pop(S);
            int num1=Top(S);
            Pop(S);
            int sum;
            if(s=="-"){
                sum=num1-num2;
                Push(sum,S);
                continue;
            }else if(s=="+"){
                sum=num1+num2;
                Push(sum,S);
                continue;
            }else if(s=="*"){
                sum=num1*num2;
                Push(sum,S);
                continue;
            }else if(s=="/"){
                sum=num1/num2;
                Push(sum,S);
                continue;
            }
        }else{
            int num;
            stringstream ss;
            ss<<s;
            ss>>num;
            Push(num,S);
        }
    }
    cout << "Output : " << Top(S);
}
