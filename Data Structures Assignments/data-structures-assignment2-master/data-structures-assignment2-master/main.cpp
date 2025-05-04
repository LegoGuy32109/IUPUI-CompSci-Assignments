#include <iostream>
#include <math.h> // for log() to find height of tree
#include <queue> // to store inOrder traversal

// given numbers in the assignment
int givenNumbers[] = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};

// data structure of the node for the BST
struct node {
  int key;
  node* left;
  node* right;
};

// recursive function to do an inorder traversal adding to a queue reference
void addToStack(node* curNode, std::queue<int> * inOrder){
  if(curNode->left)
    addToStack(curNode->left, inOrder);
  // std::cout << curNode->key << " ";
  inOrder->push(curNode->key);

  if(curNode->right)
    addToStack(curNode->right, inOrder);
}

// creates a queue of an inOrder traversal with the addToStack method and find the element at a certain index
int getElementAt(node* curNode, int index){
  std::queue<int> inOrder;

  // populate stack with tree inOrder
  addToStack(curNode, &inOrder);

  // loop through queue keeping track of index
  int curIndex = 1;
  while(!inOrder.empty()){
    // found the desired element at this index, return the value
    if(curIndex==index)
      // queue uses front to grab first element, same spot that gets popped.
      return inOrder.front();
    inOrder.pop();
    curIndex++;
  }

  // couldn't find element in tree, or more specifically the queue
  return -1;
}

// used to find the height of an element in the tree, used to print the nodes in the right place
int getHeight(node * curNode, int element, int curHeight = 0){
  // in case the node doesn't exist return exit code
  if(curNode==NULL)
    return -1;

  // if we found the value return the height
  if(curNode->key == element)
    return curHeight;

  // if the element we're looking for is greater than the current value, go right
  if(curNode->key < element)
    return getHeight(curNode->right, element, curHeight+1);
  
  // if not greater than, it must be less than, so go left
  return getHeight(curNode->left, element, curHeight+1);
}

// recursive function to add all the givenNumbers into a BST connected by nodes
void makeTree(int startingIndex, int endingIndex, int fullSize,  node * curNode){
  // midpoint is the index of the currentNode in the array
  int midpoint = startingIndex + (endingIndex-startingIndex)/2;
  // set the value to be the givenNumbers element at midpoint
  curNode->key = givenNumbers[midpoint];

  // range of searching is down to less than an element, this subdivision of the array is over
  if(endingIndex - startingIndex <= 1)
    // don't make anymore children we've reached the right length down the tree
    return;
    
  // for left side
  if(midpoint > 0) {
    node * newNode = new node();
    curNode->left = newNode;  
    makeTree(startingIndex, midpoint, fullSize, curNode->left); 
  }
  
  // for right side  
  if(midpoint < fullSize-1) {
    node * newNode = new node();
    curNode->right = newNode;
    makeTree(midpoint+1, endingIndex, fullSize, curNode->right);
  }
  
}

// prints the tree sideways, basically doing an inOrder traversal and segmenting the nodes depending on their height in the tree
void printTree(node * treeHead, node * curNode, double treeSize){
  // have this run first so the first element displayed is the smallest, left most side of tree
  if(curNode->left)
    printTree(treeHead, curNode->left, treeSize);

  // grab the height of the tree using log to calcualte height
  int height = 2+log(treeSize);
  // grab the height of the targeted element, for displaying purposes, make sure siblings and cousins are in same column
  int valueHeight = getHeight(treeHead, curNode->key);
  std::string firstSpace;
  for(int i = 0; i<valueHeight; i++)
    firstSpace += "      ";
  std::cout << firstSpace << curNode->key << "\n";

  // at the end, print the right side of tree so greater values are displayed at the bottom
  if(curNode->right)
    printTree(treeHead, curNode->right, treeSize);
}

int main() {
  // this is to find the number of elements in the given array, and by extension the tree 
  int arrSize = sizeof(givenNumbers)/sizeof(givenNumbers[0]);

  // this will be the tree head
  node * n = new node();

  // calls recusrive function to make tree with a starting index of 0 and an ending index at arrSize from head node n
  makeTree(0, arrSize, arrSize, n);


  // display printed tree
  printTree(n, n, arrSize);

  // store the user's choice of the kth element
  int k;
  do{
    std::cout << "Tree has been constructed, please enter the kth element you'd like to search: ";
    std::cin >> k;
    if(k<1 || k>arrSize){
      std::cout << "Sorry element "<< k << " isn't valid with this tree of 15 elements\n";
    }
  }while(k<1 || k>arrSize);

  // figure out what the kth should display as
  std::string concatination = "th";
  if(k==1)
    concatination = "st";
  else if(k==2)
    concatination = "nd";
  else if(k==3)
    concatination = "rd";

  std::cout << "The " << k << concatination << " smallest element is " << getElementAt(n, k) << "\n";
}
