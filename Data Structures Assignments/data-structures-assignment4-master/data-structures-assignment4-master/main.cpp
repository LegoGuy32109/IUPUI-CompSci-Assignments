#include <iostream>
#include <stack> // for stack keeping track of nodes

struct node {
  int value;
  node * right;
  node * left;
};

void makeRightChild(node * parent, int value){
  node * rightChild = new node();
  rightChild->value = value;
  parent->right = rightChild;
}

void makeLeftChild(node * parent, int value){
  node * leftChild = new node();
  leftChild->value = value;
  parent->left = leftChild;
}

int findDepth(node* curNode, int* curDepth = new int(0)){
  if(curNode->left){
    int thisDepth = *curDepth;
    *curDepth = *curDepth + 1;
    int leftDepth = findDepth(curNode->left, curDepth);
    if(thisDepth > leftDepth){
      return thisDepth;
    }else{
      return leftDepth;
    }
  }
  if(curNode->right){
    int thisDepth = *curDepth;
    *curDepth = *curDepth + 1;
    int rightDepth = findDepth(curNode->right, curDepth);
    if(thisDepth > rightDepth){
      return thisDepth;
    }else{
      return rightDepth;
    }
  }
  return *curDepth;
}

void makeLeftish(node * newNode){

  int rightDepth, leftDepth = 0;
  if(newNode->right){
    rightDepth = findDepth(newNode->right);
  }
  if(newNode->left){
    leftDepth = findDepth(newNode->left);
  }
  if(rightDepth > leftDepth){
    node * tempNode = newNode->right;
    newNode->right = newNode->left;
    newNode->left = tempNode;
  }
}

// this function recursively merges two Heaps
void mergeHeaps(node * leftHead, node * rightHead, std::stack<node*> * stack){
  // store smaller value on stack, then recur on right child of that value
  if(leftHead->value < rightHead->value){
    stack->push(leftHead);
    if(leftHead->right){
      // check if right child exists
      mergeHeaps(leftHead->right, rightHead, stack);
    }else{
      rightHead->right = leftHead;
      node * topHead;
      while(!stack->empty()){
        if(stack->size() == 2){
          node * child = stack->top();
          stack->pop();
          node * parent = stack->top();
          parent->right = child;
          break;
        }
        topHead = stack->top();
        makeLeftish(topHead);
        stack->pop();
      }

    }
  }else{
    stack->push(rightHead);
    if(rightHead->right){
      // check if right child exists
      mergeHeaps(leftHead, rightHead->right, stack);
    }else{
      rightHead->right = leftHead;
      node * topHead;
      while(!stack->empty()){
        if(stack->size() == 2){
          node * child = stack->top();
          stack->pop();
          node * parent = stack->top();
          parent->right = child;
          break;
        }
        topHead = stack->top();
        makeLeftish(topHead);
        stack->pop();
      }
    }
  }

  

}

void justPrintEm(node* head){
  std::cout << head->value << "\n";

  if(head->left){
    justPrintEm(head->left);
  }
  if(head->right){
    justPrintEm(head->right);
  }

}


int main() {
  // creating initiate stack
  std::stack<node*> stack = std::stack<node*>();

  // Left Heap on example (9 elements)
  int left[] = {4,8,12,15,19,20,25,27,43};
  // Right Heap on example (4 elements)
  int right[] = {6,8,7,14};
  
  // construct left heap
  node leftHeap = node();
  leftHeap.value = left[0];
  makeRightChild(&leftHeap, left[1]);
  makeLeftChild(leftHeap.right, left[2]);
  makeLeftChild(leftHeap.right->left, left[3]);
  makeRightChild(leftHeap.right->left, left[4]);
  // right side of this heap done
  makeLeftChild(&leftHeap, left[5]);
  makeRightChild(leftHeap.left, left[6]);
  makeLeftChild(leftHeap.left, left[7]);
  makeLeftChild(leftHeap.left->left, left[8]);
  
  // construct right heap
  node rightHeap = node();
  rightHeap.value = right[0];
  makeRightChild(&rightHeap, right[1]);
  makeLeftChild(&rightHeap, right[2]);
  makeLeftChild(rightHeap.left, right[3]);
  
  


  // merge Heaps
  mergeHeaps(&leftHeap, &rightHeap, &stack);

  // display heap
  justPrintEm(&leftHeap);

}
