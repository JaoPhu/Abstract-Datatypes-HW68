#include <iostream>
using namespace std;

struct record{
    int value;
    struct record *next;
};
struct record *tail=nullptr;
typedef record *Queue;

Queue CreateQueue(){
    Queue head=new struct record;
    head->next=nullptr;
    tail=head;
    return head;
}

void Push(int i,Queue head){
    if(head->next==nullptr){
        head->value=i;
        head->next=head;
    }else{
        Queue Node=new record{i,head};
        tail->next=Node;
        tail=Node;
    }
}

void Pop(Queue p){
    Queue tmp=p->next;
    p->next=p->next->next;
    delete(tmp);
}

int Eliminate(Queue p){
    return p->next->value;
}

int Win(Queue p){
    return p->next->value;
}

int main(){
    Queue head=CreateQueue();
    int n;
    int m;
    cout << "Input N = ";
    cin >> n;
    cout << "Input M = ";
    cin >> m;
    for(int i=1;i<=n;i++){
        Push(i,head);
    }
    cout << "Eliminate : ";
    Queue p=tail;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m;j++){
            p=p->next;
        }
        cout << Eliminate(p) << " ";
        Pop(p);
    }
    cout << "\nWinner : " << Win(p);
}
