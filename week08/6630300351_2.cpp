#include <iostream>
using namespace std;

struct Node{
    struct record* adr;
    struct Node* next;
};

struct record{
    struct record* left;
    string albs;
    struct record* right;
};

typedef Node* Stack;

Stack CreateStack(){
    Stack S=new Node{NULL,NULL};
    return S;
}

bool IsEmpty(Stack S){
    return S->next==NULL;
}

void Push(struct record* tree,Stack S){
    Stack tmp=new Node;
    tmp->adr=tree;
    tmp->next=S->next;
    S->next=tmp;
}

void Pop(Stack S){
    Stack p=S->next;
    S->next=S->next->next;
    delete(p);
}

struct record* Top(Stack S){
    if(IsEmpty(S)) return NULL;
    return S->next->adr;
}

void Preorder(struct record* tree){
    if(tree==NULL){
        return;
    }else{
        cout<< tree->albs << " ";
        Preorder(tree->left);
        Preorder(tree->right);
    }
    return;
}

void Inorder(struct record* tree){
    if(tree==NULL){
        return;
    }else{
        Inorder(tree->left);
        cout<< tree->albs << " ";
        Inorder(tree->right);
    }
    return;
}

void Postorder(struct record* tree){
    if(tree==NULL){
        return;
    }else{
        Postorder(tree->left);
        Postorder(tree->right);
        cout<< tree->albs << " ";
    }
    return;
}

int main(){
    string s;
    Stack S=CreateStack();
    cout << "Input : ";
    while(cin >> s){
        if(s=="."){
            break;
        }else if(s=="+"||s=="-"||s=="*"||s=="/"){
            struct record* tree=new record;
            tree->albs=s;
            tree->right=Top(S);
            Pop(S);
            tree->left=Top(S);
            Pop(S);
            Push(tree,S);
        }else{
            struct record* tree=new record{NULL,s,NULL};
            Push(tree,S);
        }
    }
    cout << "Preorder : " ;
    Preorder(S->next->adr);
    cout << endl;
    cout << "Inorder : " ;
    Inorder(S->next->adr);
    cout << endl;
    cout << "Postorder : " ;
    Postorder(S->next->adr);
    cout << endl;
}
