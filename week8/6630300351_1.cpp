#include <iostream>
using namespace std;

struct node{
    struct node* left;
    int value;
    struct node* right;
};

struct node* find(struct node* tree,int num){
    if(tree==NULL){
        return NULL;
    }
    else if(tree->value==num){
        return tree;
    }else if(tree->value>num){
        if(tree->left==NULL){
            return NULL;
        }
        return (find(tree->left,num));
    }else if(tree->value<num){
        if(tree->right==NULL){
            return NULL;
        }
        return (find(tree->right,num));
    }
    return NULL;
}

struct node* find_min(struct node* tree){
    if(tree==NULL){
        return NULL;
    }else{
        if(tree->left==NULL){
            return tree;
        }else{
            return (find_min(tree->left));
        }
    }
}

struct node* find_max(struct node* tree){
    if(tree==NULL){
        return NULL;
    }else{
        if(tree->right==NULL){
            return tree;
        }else{
            return (find_max(tree->right));
        }
    }
}

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

struct node* dTree(struct node* tree,int num){
    struct node* tmpcell,* child;
    if(tree->value>num){
        tree->left=dTree(tree->left,num);
    }else{
        if(tree->value<num){
            tree->right=dTree(tree->right,num);
        }else{
            if(tree->left!=NULL&&tree->right!=NULL){
                tmpcell=find_min(tree->right);
                tree->value=tmpcell->value;
                tree->right=dTree(tree->right,tree->value);
            }else{
                tmpcell=tree;
                if(tree->left==NULL){
                    child=tree->right;
                }
                if(tree->right==NULL){
                    child=tree->left;
                }
                delete(tmpcell);
                return child;
            }
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
    cout << "2) Delete" << endl;
    cout << "3) Print min,max" << endl;
    cout << "4) Preorder,Inorder,Postorder" << endl;
    cout << "5) Find" << endl;
    cout << "6) Exit" << endl;
    cout << "Please choose >  ";
    cin >> ch;
    return ch;
}

int main(){
    char ch;
    int num;
    struct node* tree=NULL;
    while(ch!='6'){
        ch=menu();
        if(ch=='1'){
            cout << endl << "Insert : ";
            cin >> num;
            tree=Insert(tree,num);
            cout << "Success" << endl << endl;
        }else if(ch=='2'){
            cout << endl << "Delete : ";
            cin >> num;
            if(tree!=NULL){
                tree=dTree(tree,num);
                cout << "Success" << endl << endl;
            }else{
                cout << "No Node" << endl << endl;
            }
        }else if(ch=='3'){
            cout << endl << "MIN  : "<< find_min(tree)->value;
            find_min(tree);
            cout << endl << "MAX  : " << find_max(tree)->value;
            cout << endl << endl;
        }else if(ch=='4'){
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
        }else if(ch=='5'){
            cout << endl << "Find : ";
            cin >> num;
            if(find(tree,num)!=NULL){
                cout << "Found!" << endl << endl;
            }else{
                cout << "Not found!"<< endl << endl;
            }
        }else if(ch=='6'){
            continue;
        }
    }
    return 0;
}
