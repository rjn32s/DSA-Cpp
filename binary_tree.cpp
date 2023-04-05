#include<iostream>
using namespace std;
#include<queue>
class node{
    public:
        int data;
        node* left;
        node* right;
    node(int d){
        this ->data = d;
        this ->left = NULL;
        this ->right = NULL;

    }

};
node* buildTree(node* root){
    cout << "Enter the data for the root node"<< endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1){
        return NULL;
    }
    cout << "Enter the data for the Left node of : "<<data<<endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for the right node of :"<< data<< endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        cout << temp->data<<" ";
        q.pop();
        if (temp == NULL){
            cout << endl;
            if (!q.empty()){
                q.push(NULL); 
            }
        }

        if (temp->left){
            q.push(temp->left);
        }
        if (temp->right){
            q.push(temp->right);
        }
    }
}

int main(){
    node* root = NULL;
    // Creating a tree
    buildTree(root);
    levelOrderTraversal(root);
}