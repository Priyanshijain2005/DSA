#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        this->data=d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* createTree(node*root){
    cout << "enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data==-1){
        return NULL;
    }

    cout << "enter the left data of " << data << ": " << endl;
    root->left = createTree(root->left);
    cout << "enter the right data of "<<data<<": " << endl;
    root->right = createTree(root->right);
    return root;
}

// void display(node*root){
//     if(root==NULL){
//         return;
//     }
//     display(root->left);
//     cout << root->data << endl;
//     display(root->right);
//     cout << root->data << endl;
// }

int main(){
    node *root = NULL;
    createTree(root);
    

    return 0;
}


/*int getLeftChildNode(int i){
    return (2 * i + 1);
}
int getRightChildNode(int i){
    return (2 * i + 2);
}
int getParentNode(int i){
    return (i - 1) / 2;
}

int main(){
    int tree[7] = {1, 2, 3, 4, 5, 6, 7};


    return 0;
}*/

