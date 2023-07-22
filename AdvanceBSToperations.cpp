#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;
 
/* A tree node structure */
struct node {
    int data;
    struct node* left;
    struct node* right;
};


// Utility function to create a new Binary Tree node
struct node* newNode(int data)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
                       
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void printPreorder(struct node* node)
{
    if (node == NULL)
        return;
 
    // First print data of node
    cout << node->data << " " << " -> ";
 
    // Then recur on left subtree
    printPreorder(node->left);
 
    // Now recur on right subtree
    printPreorder(node->right);
}

void printInorder(struct node* node)
{
    if (node == NULL)
        return;
 
    // First recur on left child
    printInorder(node->left);
 
    // Then print the data of node
    cout << node->data << " " << " -> ";
 
    // Now recur on right child
    printInorder(node->right);
}

void printPostorder(struct node* node)
{
    if (node == NULL)
        return;
 
    // First recur on left subtree
    printPostorder(node->left);
 
    // Then recur on right subtree
    printPostorder(node->right);
 
    // Now deal with the node
    cout << node->data << " " << " -> ";
}

void BFT(struct node *root){      //In order traversal
    if(root == NULL){
        cout << "The BST is empty " << endl;  //Validation for an empty tree
        return;
    }

    queue<node*> Q;
    Q.push(root);

    node *Aux;
    while(!Q.empty()){    //Print by lines all the levels on the tree
        Q.push(NULL);

        Aux = Q.front();
        while(Aux != NULL){
            cout << Aux -> data << " ";

            if(Aux -> left != NULL)   //If left son exist, push into the list
                Q.push(Aux -> left);
            if(Aux -> right != NULL)   //If rigth son exist, push into the list
                Q.push(Aux -> right);

            Q.pop();    //Remove first element of the list
            Aux = Q.front();    
        }
        Q.pop();
        
        cout << endl;
    }
};

/* Compute the "maxDepth" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int maxDepth(node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}


// Helper function for getLevel(). It returns level of the
// data if data is present in tree, otherwise returns 0.
int getLevelUtil(struct node* node, int data, int level)
{
    if (node == NULL)
        return 0;
 
    if (node->data == data)
        return level;
 
    int downlevel
        = getLevelUtil(node->left, data, level + 1);
    if (downlevel != 0)
        return downlevel;
 
    downlevel = getLevelUtil(node->right, data, level + 1);
    return downlevel;
}
 
/* Returns level of given data value */
int getLevel(struct node* node, int data)
{
    return getLevelUtil(node, data, 1);
}


bool printAncestors(struct node *root, int target)
{

  /* base cases */
  if (root == NULL)
     return false;
 
  if (root->data == target)
     return true;
 
  /* If target is present in either left or right subtree of this node,
     then print this node */
  if ( printAncestors(root->left, target) ||
       printAncestors(root->right, target) )
  {
    cout << root->data << " ";
    return true;
  }
 
  /* Else return false */
  return false;
}

void visit(struct node *root){
    int choice;

    do{
        cout << "\nChoose way to display the tree: " << endl;
        cout << "1.) Pre-Order " << endl;
        cout << "2.) In-Order " << endl;
        cout << "3.) Post-Order  " << endl;
        cout << "4.) Level by level, BFT " << endl;
        cout << "0.) Exit " << "\n" << endl;
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Pre-Order tree: " << endl;
                printPreorder(root);
                cout << "\n" << endl;
                break;

            case 2:
                cout << "In-Order tree: " << endl;
                printInorder(root);
                cout << "\n" << endl;
                break;

            case 3:
                cout << "Post-Order tree: " << endl;
                printPostorder(root);
                cout << "\n" << endl;
                break;            

            case 4:
                cout << "Level by level tree: " << endl;
                BFT(root);
                cout << "\n" << endl;
                break;

            case 5:
                cout << "Invalid option, try again " << endl;
                cout << "\n" << endl;
                break;            

            case 0:
                break;
        }
    } while(choice != 0);
};

void displayLevel(struct node *root){
    int x, max;

    cout << "\nEnter highest data value in the tree: " << endl;
    cin >> max;

    for (x = 1; x <= max; x++) {
        int level = getLevel(root, x);
        if (level)
            cout << "Level of " << x << " is " << level
                 << endl;
        else
            cout << x << " -1" << endl;
    }    

};

void displayAncestors(struct node *root){
    int target;

    cout << "\nEnter target value: " << endl;
    cin >> target;
    printAncestors(root, target);    

};

// Driver Code
int main()
{
    struct node* root = new struct node;

    // Constructing tree
    root = newNode(47);
    root->left = newNode(22);
    root->right = newNode(60);
    root->right->left = newNode(52);
    root->left->left = newNode(12);
    root->left->right = newNode(41);
    root->left->right->left = newNode(20);
    root->left->left->left = newNode(6);
    root->left->left->right = newNode(13);
    root->left->left->right->right = newNode(16);

    visit(root);

    cout << "\nHeight of tree is: " << maxDepth(root) << " \n ";

    displayLevel(root);

    displayAncestors(root);

    getchar();
    return 0;
}
 