#include <iostream>
using namespace std;

struct node{
    struct node* left;
    int value;
    struct node* right;
};

struct node* Insert(struct node* tree,int num){
    if(tree==NULL){
        tree=new struct node;
        tree->value=num;
        tree->left=tree->right=NULL;
    }else{
        if(num<tree->value){
            tree->left=Insert(tree->left,num);
        }else if(num>tree->value){
            tree->right=Insert(tree->right,num);
        }
    }
    return tree;
}

void Preorder(struct node* tree){
    if(tree==NULL){
        return;
    }else{
        cout<< tree->value << " ";
        Preorder(tree->left);
        Preorder(tree->right);
    }
    return;
}

void Inorder(struct node* tree){
    if(tree==NULL){
        return;
    }else{
        Inorder(tree->left);
        cout<< tree->value << " ";
        Inorder(tree->right);
    }
    return;
}

void Postorder(struct node* tree){
    if(tree==NULL){
        return;
    }else{

        Postorder(tree->left);
        Postorder(tree->right);
        cout<< tree->value << " ";
    }
    return;
}

char menu(){
    char ch;
    cout << "=======================" << endl;
    cout << "\t Menu" << endl;
    cout << "=======================" << endl;
    cout << "1) Insert " << endl;
    cout << "2) Print Preorder, Inorder, Postorder" << endl;
    cout << "3) Exit" << endl;
    cout << "Please choose >  ";
    cin >> ch;
    return ch;
}

int main(){
    char ch;
    int num;
    struct node* tree=NULL;
    while(ch!='3'){
        ch=menu();
        if(ch=='1'){
            cout << "Insert : ";
            cin >> num;
            tree=Insert(tree,num);
            cout << "Success" << endl << endl;
        }else if(ch=='2'){
            if(tree==NULL){
                cout << "Tree Empty!!!" << endl;
                continue;
            }
            cout << endl << "Preorder  : ";
            Preorder(tree);
            cout << endl << "Inorder   : ";
            Inorder(tree);
            cout << endl << "Postorder : ";
            Postorder(tree);
            cout << endl << endl;
        }
    }
    return 0;
}
/*
ให้ทดลอง insert  5  2  10  1  7  11

ถ้าเลือกข้อ 2
Preorder :  5  2  1  10  7  11
Inorder	 :  1  2  5  7  10  11
Postorder:  1  2  7  11 10  5

1 5 1 2 1 10 1 1 1 7 1 11
*/
