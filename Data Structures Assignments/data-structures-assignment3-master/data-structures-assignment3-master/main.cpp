#include <iostream>
#include <stdlib.h>
#include <vector> // containing keys and values
#include <algorithm> // to sort vectors

// struct of a Btree
struct bTree {
    bTree * parent;
    // vectors make sorting and appending to easy
    std::vector <int> values;
    std::vector <bTree *> children;
};

// insert the value recursively finding the right spot to put it while editing the structure of the Btree if necessary
void insertValue(bTree * head, int value){
  // check if head has children, if it does nothing after this block will execute
  if(head->children.size()>0){
    // iterate through all values in head
    for(int i =0; i<head->values.size(); i++){
      if(head->values[i]>value){
        // add to 'i'th child 
        insertValue(head->children[i], value);
        // stop here, value was added so we don't continue
        return;
      }
      // I decided if value is equal to pass it to predecessor
      if(head->values[i]==value){
        insertValue(head->children[i], value);
        // same as above, stop here
        return;
      }
      /* don't check for greater than value in for loop, I do that for the last key seperately
         4 5 6 
        / / /  \   <-
      I check last one, for loop does first three */
    }
    // check for last key, child path, see above. If so add to furthest right child
    if(head->values.back() < value){
      insertValue(head->children.back(), value);
    }
    // don't add a child to head, stop function
    return;
  }

  // add a value to this bTree node
  head->values.push_back(value);
  // this sorts the vector
  std::sort(head->values.begin(), head->values.end());
  // check if this is a valid Btree, 5 way B tree is the limit
  if(head->values.size()<5){
    return;
  }

  // if the head does have a parent, bump up like this, make sure there is space in the parent to bump back up
  if(head->parent && head->parent->values.size() < 4){
    // need to edit tree if this isn't the case, make this node split appending median child to head.  
    bTree * newRightChild = new bTree();
    
    for(int i = 0; i<2; i++){
      // get last two elements
      newRightChild->values.push_back(head->values.back());
      // remove last two elements from head
      head->values.pop_back();
    }
    // swap values for rightChild, was constructed backwards
    std::swap(newRightChild->values[0], newRightChild->values[1]);
    // connect new node to head's parent
    newRightChild->parent = head->parent;
    
    // move median value (now last) to parent, deleting in current node
    int pushedUpValue = head->values.back();
    head->parent->values.push_back(pushedUpValue);
    head->values.pop_back();
  
    // sort parent values
    std::sort(head->parent->values.begin(), head->parent->values.end());
    // find where sorted pushed value is in parent
    std::vector<int>::iterator it = std::find(head->parent->values.begin(), head->parent->values.end(), pushedUpValue);
    int index = std::distance(head->parent->values.begin(), it);
    // convert integer index to iterator for parent's children
    std::vector<bTree*>::iterator it2 = head->parent->children.begin() + index;
    // push new Btree to parent's children in right spot, gotta add a +1 to iterator for correct children location
    head->parent->children.insert(it2+1, newRightChild);
    
  }else{
    // otherwise a parent doesn't exist, we're in the root/main node, need to spit this into 3 nodes, 2 vals on each side to new children
    
    // create 2 new child nodes
    bTree * rightChild = new bTree();
    bTree * leftChild = new bTree();

    // pop front two vals into left child
    leftChild->values.push_back(head->values[0]);
    leftChild->values.push_back(head->values[1]);

    // pop last two vals into right child, in right order
    rightChild->values.push_back(head->values[3]);
    rightChild->values.push_back(head->values[4]);

    // erase all values except median
    head->values.erase(head->values.begin(), head->values.begin()+2);
    head->values.erase(head->values.end()-2, head->values.end());

    // connect children to head and head to children
    rightChild->parent = head;
    leftChild->parent = head;
    head->children.push_back(leftChild);
    head->children.push_back(rightChild);

  }
}

// helper function for print tree, prints the values in a Btree node
void printValues(bTree * head){
  std::vector tempValues = head->values;
  for(int i = 0; i<tempValues.size(); i++){
    std::cout << tempValues[i] << " ";
  }
}

// function to print 3 levels of the tree, I used for debugging
void printTree(bTree * head){
  int findLeftNodes = 0;
  bTree * mostLeftNode = head;
  
  // find how far left the tree goes, helps space out upper levels
  while(!mostLeftNode->children.empty()){
    findLeftNodes++;
    mostLeftNode = mostLeftNode->children[0];
  }
  
  // level 0
  for(int i = 0; i<findLeftNodes; i++){
    std::cout << "            ";
  }
  printValues(head);
  std::cout << "\n";

  // level 1
  for(int i = 0; i<findLeftNodes-1; i++){
    std::cout << "            ";
  }
  for(int i = 0; i<head->children.size(); i++){
    std::cout << "|";
    printValues(head->children[i]);
    std::cout << "|   ";
  }
  std::cout << "\n";

  // level 2
  for(int i = 0; i<findLeftNodes-2; i++){
    std::cout << "            ";
  }
  for(int i = 0; i<head->children.size(); i++){
    for(int j = 0; j<head->children[i]->children.size(); j++){
      std::cout << "|";
      printValues(head->children[i]->children[j]);
      std::cout << "|   ";
    }
    // this indicates when a parent's children for this line finishes, so between ^s are the children of the next parent. Useful for level 2 and below
    if(i<head->children.size()-1){
      std::cout << "^";
    }
  }
  std::cout << "\n";

  // level 3
  for(int i = 0; i<findLeftNodes-3; i++){
    std::cout << "             ";
  }
  for(int i = 0; i<head->children.size(); i++){
    for(int j = 0; j<head->children[i]->children.size(); j++){
      for(int k = 0; k<head->children[i]->children[j]->children.size(); k++){
        std::cout << "|";
        printValues(head->children[i]->children[j]->children[k]);
        std::cout << "|   ";
      }
    }
  }
  std::cout << "\n";

  // probably a better way of writing this display function, I just don't really want to comprehend a solution to this complex pattern
}

// returns true if given value is inside of Btree
bool findValue(bTree * head, int value){
  for(int i = 0; i < head->values.size(); i++){
    // go left
    if(head->values[i] > value){
      if(head->children.size()>0){
        return findValue(head->children[i], value);
      }else{
        return false;
      }
    }
    // found value
    if(head->values[i] == value){
      return true;
    }
  }
  // reached last right key/pointer, go right if it has children
  if(head->children.size()>0){
    return findValue(head->children.back(), value);
  }
  // came back and nothing? not in there then
  return false;
}

int main() {
  // construct root node for tree
  bTree head = bTree();

  // set N to be a number 400 or greater
  int N = 10;
  do{
    std::cout << "Enter N to construct 5-way Btree\n:";
    std::cin >> N;
    if(N<400){
      std::cout << "N must be >= 400\n";
    }
  }while(N<400); 
  // create array of numbers 0...3*N 
  int intList[3*N];
  std::cout << "\n";
  for(int i = 0; i<3*N; i++){
    intList[i] = i;
  }
  // place randomly chosen integers inside of randList, our Btree will be of size N so randList is too
  int randList[N];
  for(int i = 0; i<=N; i++){
    // generate random index to grab next number in range randomly
    int place = rand()%(3*N);
    while(intList[place]<0){
      // skip the spot if in intList[] it's -1, means it was already chosen so no duplicate numbers are used
      if(place>=3*N){
        place=0;
      }else{
        place++;
      }
    }
    randList[i] = intList[place];
    // it's been chosen, set to -1
    intList[place] = -1;
  }
  
  // add all values in randList to Btree 'head'
  for(int i = 0; i<N; i++){
    insertValue(&head, randList[i]);
  }

  // vars to contain foundValues and number of them  
  int foundVals[N];
  int counter = 0;
  // check each int from N-2N if they're in the Btree 'head'
  for(int i = N; i<2*N; i++){
    if(findValue(&head, i)){
      foundVals[counter] = i;
      counter++;
      // display found keys visually along with empty space
      std::cout << i << " ";
    }else{
      std::cout << ". ";
    }
  }
  // indicate percentage of range N-2N covered by keys, mathmatically close to .3333 but I found the deviation interesting
  std::cout << "\n% of range (" << N << " elements) covered by keys: " << counter/float(N) << "\n";

  // Easily readibly list of all keys found in Btree
  std::cout << "Returned keys:\n";
  for(int i = 0; i<counter; i++){
    std::cout << "Key " << foundVals[i] << " returned\n";
  }
  
  return 0;
}
