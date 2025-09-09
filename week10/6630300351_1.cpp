#include <iostream>
using namespace std;

struct node{
    struct node* left;
    int value;
    int height;
    struct node* right;
};

int fheight(struct node* P){
    if(P==NULL){
        return -1;
    }else{
        return P->height;
    }
}

void cheight(struct node* P,int x){
    if(P->value==x){
        cout << P->height << endl;
    }else{
        if(x>=P->value){
            cheight(P->right,x);
        }else{
            cheight(P->left,x);
        }
    }
    return;
}

struct node* srleft(struct node* k2){
    struct node* k1;
    k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    k2->height=max(fheight(k2->left),fheight(k2->right))+1;
    k1->height=max(fheight(k1->left),k2->height)+1;
    return k1;
}

struct node* srright(struct node* k2){
    struct node* k1;
    k1=k2->right;
    k2->right=k1->left;
    k1->left=k2;
    k2->height=max(fheight(k2->left),fheight(k2->right))+1;
    k1->height=max(fheight(k1->right),k2->height)+1;
    return k1;
}

struct node* drleft(struct node* k3){
    k3->left=srright(k3->left);
    return srleft(k3);
}

struct node* drright(struct node* k3){
    k3->right=srleft(k3->right);
    return srright(k3);
}

struct node* Insert(struct node* T,int x){
    if(T==NULL){
        T=new struct node;
        T->value=x;
        T->left=T->right=NULL;
        T->height=0;
    }else{
        if(x<T->value){
            T->left=Insert(T->left,x);
            if(fheight(T->left)-fheight(T->right)==2){
                if(x<T->left->value){
                    T=srleft(T); //LL
                }else{
                    T=drleft(T); //LR
                }
            }
        }else{
            if(x>T->value){
                T->right=Insert(T->right,x);
                if(fheight(T->right)-fheight(T->left)==2){
                    if(x>T->right->value){
                        T=srright(T); //RR
                    }else{
                        T=drright(T); //RL
                    }
                }
            }
        }
    }
    T->height=max(fheight(T->left),fheight(T->right))+1;
    return T;
}

void Inorder(struct node* tree){
    if(tree==NULL){
        return;
    }else{
        Inorder(tree->left);
        cout << tree->value << " ";
        Inorder(tree->right);
    }
    return;
}

char menu(){
    char ch;
    cout << "=======================" << endl;
    cout << "\t Menu" << endl;
    cout << "=======================" << endl;
    cout << "1) Insert " << endl;
    cout << "2) Check height" << endl;
    cout << "3) Print Inorder" << endl;
    cout << "Please choose >  ";
    cin >> ch;
    return ch;
}

int main(){
    char ch;
    int num;
    struct node* tree=NULL;
    while(true){
        ch=menu();
        if(ch=='1'){
            cout << endl << "Insert : ";
            cin >> num;
            tree=Insert(tree,num);
            cout << "Success!" << endl << endl;
        }else if(ch=='2'){
            cout << endl << "Check height : ";
            cin >> num;
            cout << "Height = ";
            cheight(tree,num);
            cout << endl;
        }else if(ch=='3'){
            cout << endl << "Print inorder : ";
            Inorder(tree);
            cout << endl;
        }
    }
    return 0;
}
