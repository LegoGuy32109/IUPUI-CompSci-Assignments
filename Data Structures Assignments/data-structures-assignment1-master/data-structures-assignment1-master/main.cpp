#include <iostream>
#include <stack> // for stack data structure
#include <cstring> // for memclear() to clean a userdefined 2D array

//struct to store queen's position on board
struct position_t {
  int xPos;
  int yPos;
};

//function to create new positions easily
position_t newPos(int yPos, int xPos){
  position_t position;
  position.yPos = yPos;
  position.xPos = xPos;
  return position;
}

//stack to store positions
std::stack<position_t> positions;

//boolean function checking if the given position is in the stack, used for printing the grid.
bool isPosInStack(position_t pos){
  // copy values to a temporary stack
  std::stack<position_t> positionsCopy = positions;
  while (!positionsCopy.empty()){
    position_t curPos = positionsCopy.top();
    // if the X and Y coords match, then positions are equal
    if(curPos.xPos == pos.xPos && curPos.yPos == pos.yPos)
      return true;
    // remove position from copy after it's analyzed
    positionsCopy.pop();
  }
  return false;
}

// displays the grid to the user with the given GRIDSIZE
void printGrid(int GRIDSIZE) {
  // prints each column
  for(int i = 0; i<GRIDSIZE; i++){
    // prints each row per column
    for(int j = 0; j<GRIDSIZE; j++){
      position_t curPos;
      curPos.xPos = j;
      curPos.yPos = i;
      std::string space;
      // check if this position is in the stack, then a queen is there and siplay accordingly
      if(isPosInStack(curPos))
        space = "♠ ";
      // if the current position is a white space on the chessboard, display a white square
      else if((j+i)%2==0)
        space = "■ ";
      // the current position isn't a queen or a white space, so it must be a black space
      else
        space = "□ ";
      std::cout << space ;
    }
    std::cout << std::endl;
  }
  std::cout << "\n";
}

// given a position_t and a GRIDSIZE, see if that is a valid position with all queens from the <stack> positions not invalidating it
bool isValid(position_t pos, int GRIDSIZE){
  // create 2D array to calculate if position is valid
  int GRID[GRIDSIZE][GRIDSIZE];
  // fills array with 0s
  memset(GRID, 0, GRIDSIZE*GRIDSIZE*sizeof(int));
  // populate grid with position_t (s) from stack by reading through a copy
  std::stack<position_t> positionsCopy = positions;
  while(!positionsCopy.empty()){
    position_t curStackPos = positionsCopy.top();
    // set spot on GRID to 1 is queen is there
    GRID[curStackPos.yPos][curStackPos.xPos] = 1;
    positionsCopy.pop();
  }

  // it is not necessary to check the row, queens are added to the next row based on the size() of the stack, so a new queen is always started by adding it to the row below the previous queen

  // check column starting at the element vertically at the top above the element being evaluated
  for(int i = 0; i<GRIDSIZE; i++){
    if(GRID[i][pos.xPos]==1){
      return false;
    }
  }

  // check diagonal left right
  int tempPosX = pos.xPos;
  int tempPosY = pos.yPos;
  // find the top left element in the diagonal by decrementing the X and Y coordinate
  while(tempPosX>0 && tempPosY>0){
    tempPosX--;
    tempPosY--;
  }
  // set the iterators to be the coords of the top left element, then increment them both in the for loop as you check the diagonal
  int i = tempPosY;
  int j = tempPosX;
  for(i; i<GRIDSIZE && j<GRIDSIZE; i++, j++){
    if(GRID[i][j]==1){
      return false;
    }
  }

  // check diagonal right left
  tempPosX = pos.xPos;
  tempPosY = pos.yPos;
  // find the top right element in the diagonal by incrementing X coord and decrementing Y coord
  while(tempPosX<GRIDSIZE-1 && tempPosY>0){
    tempPosX++;
    tempPosY--;
  }
  // set the iterators to be the coords of the top right element, then increment the y while decrementing the x as you check the diagonal
  i = tempPosY;
  j = tempPosX;
  for(i; i<GRIDSIZE && j>0; i++, j--){
    if(GRID[i][j]==1){
      return false;
    }
  }

  // all tests passed, this space is valid
  return true;
}

// recursive function to add a queen to the stack, if not given a previous position it sets the beginning position to be a new queen on the row not yet covered by the array. If the position being checked isn't valid, addQueen() calls itself with the previous addition passed to it, but with the xPos incremented down the row.
bool addQueen(int GRIDSIZE, position_t prevPosition = newPos(positions.size(),0)){
  // find the spot for the queen on the current row, if it can't fit on the row you must pop a previous queen
  for(int i = prevPosition.xPos; i<GRIDSIZE; i++){
    // the examined position is valid, push it to the stack
    if(isValid(prevPosition, GRIDSIZE)){ 
      positions.push(prevPosition);
      return true;
    }
    prevPosition.xPos++;
  }
 
  // must pop a previous queen...
  // if the first row queen can't fit on the last grid space, then the solution is impossible, return false
  if(positions.empty())
    return false;
  // overwrite prevPosition with the top queen in stack, need to fix her on next recusion
  prevPosition = positions.top();
  positions.pop();
  //prevPosition needs to moved down row to check if valid on the next recursion
  prevPosition.xPos++;
  return addQueen(GRIDSIZE, prevPosition);
}

int main() {
  int GRIDSIZE;
  // max size for the GRIDSIZE 
  int Nmax = 14;
  do{
    std::cout << "Please enter desired NxN grid size: ";
    std::cin >> GRIDSIZE;
    // stop the user from putting in a solution that's too big, and would take to long to calculate
    if(GRIDSIZE > Nmax){
      std::cout << "Sorry, "<<GRIDSIZE<<" is bigger than the max board size ("<<Nmax<<") for this program.\n";
    }
  } while(GRIDSIZE>Nmax);
 
  // solve the problem by adding queens until the stack.size() is the same as the GRIDSIZE 
  while(positions.size() < GRIDSIZE){
    if(addQueen(GRIDSIZE)){
      printGrid(GRIDSIZE);
    }else{
      std::cout<<"No valid solutions\n";
      break;
    }
  }
  if(positions.size() == GRIDSIZE)
    std::cout << "Valid solution found!\n";
}


