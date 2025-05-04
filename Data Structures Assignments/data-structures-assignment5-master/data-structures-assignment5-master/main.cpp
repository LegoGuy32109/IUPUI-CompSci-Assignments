#include <iostream>
#include <fstream> // for file input
#include "TimeInterval.h"

class HashTable {
public:
  HashTable();
  // HashTable(string filename);

  // construction methods
  bool find(const std::string& value);  
  void insert(const std::string& value);
  std::string remove(const std::string& value);
  // diplay methods
  void printTable(void);
  // spellchecker methods
  void takeInput(std::string& value);

private:
  // internal hashFunc
  unsigned int hashFunc(const std::string& value);
  // word similarity  
  float similar (const std::string& str1, const std::string& str2);
  // must be >= 26
  const static unsigned int size_max = 30;
  // table holding all values
  std::string values[size_max][size_max];
};

HashTable::HashTable() {
  // sets whole table to be default strings
  for(int j = 0; j< size_max; j++) {
    for (int i = 0; i < size_max; i++) {
      values[j][i] = std::string();
    }
  }
}

// hash function
unsigned int HashTable::hashFunc(const std::string& k)
{
  unsigned int stringVal = int(k[0]);
  return stringVal % size_max;
}

// display visualization of table to screen
void HashTable::printTable() {
  for (int i = 0; i < size_max; i++) {
    std::cout << "{";
    for(int j = 0; j< size_max; j++) { 
      if (!values[i][j].empty())
        std::cout << values[i][j] << ", ";
    }
    std::cout << "}\n";
  }
}

// insert into table if there is space
void HashTable::insert(const std::string& value) {
  // if you can't find it don't bother looking
  if (!find(value)) {
    int valIndex = hashFunc(value);
    for(int i = 0; i< size_max; i++){
      if(values[valIndex][i].empty()){
        values[valIndex][i] = value;
        return;
      }
    }
    std::cout << "Table is two small to fit " << value << "\n";
    return;
  }

}

// return true if value is in table
bool HashTable::find(const std::string& value) {
  int index = hashFunc(value);
  // if it doesn't exist then it's index = -1
  if (index == -1){
    return false;
  }

  for(int i = 0; i<size_max; i++){
    if(!values[index][i].empty()){
      if(values[index][i] == value){
        return true;
      }
    }
  }
  return false;
}

// remove an element from the table
std::string HashTable::remove(const std::string& value) {
  int index = hashFunc(value);
  if (index == -1){
    return "VALUE NOT FOUND";
  }
  for(int i = 0; i<size_max; i++){
    if(!values[index][i].empty()){
      if(values[index][i] == value){
        values[index][i].clear();
      }
    }
  }
  return value+" removed";
}

void HashTable::takeInput(std::string &value){
  std::string input; // have to have userInput up here
  // convert input to lowercase, reference in main()
  int i = 0;
  while (value[i] != '\0'){
    if(value[i] >= 'A' && value[i] <= 'Z'){
      value[i] += 32;
    }
    i++;
  }
  if(find(value)){
    std::cout << "True\n";
    // can't do nothing with single letter words
    if(value.length() == 1){
      return;
    }
    int index = hashFunc(value);
    for(int i=0; i<size_max; i++){
      // making sure it prints words that share the 1st and 2nd letter, but not printing the same word the user typed in
      if(!values[index][i].empty() && values[index][i] != value && values[index][i][1] == value[1]){
        std::cout << values[index][i] << "\n";
      }
    }

  // can't find input in dictionary, but we can look for similar words
  }else{
    int index = hashFunc(value);
    // check if first letter exists
    if(!values[index][0].empty()){
      // loop through possible words giving score to possible correctness
      int i = 0;
      while(!values[index][i].empty()){
        i++;
      }
      // create array as big as the possible words
      float similarScores[i];
      int scoreSize = i;
      for(int j = 0; j<scoreSize; j++){
        similarScores[j] = float(100);
      }
      i = 0;
      while(!values[index][i].empty()){
        // std::cout << values[index][i] << " is " << similar(value, values[index][i]) << "\n";
        similarScores[i] = similar(value, values[index][i]);
        i++;
      }
      // threshold defined here
      float lowestScore = float(100);
      int lowestScoreIndex = 0;
      for(i = 0; i<scoreSize; i++){
        if(similarScores[i] < lowestScore){
          lowestScore = similarScores[i];
          lowestScoreIndex = i;
        }
      }
      // found most likely word, ask user if they meant that
      do {
        std::cout << "do you mean " << values[index][lowestScoreIndex] << "?\n"; 
        std::cin >> input;
        if(input == "no"){
          std::cout << "False\n";
        }else if(input == "yes"){
          takeInput(values[index][lowestScoreIndex]);
        }else{
          std::cout << "I didn't understand that answer, please type (yes) or (no)\n";
        }
      }while(input != "yes" && input != "no");

    // if first letter is not in dictionary, forget about it
    }else{
      std::cout << "False\n";
    }
  }
}

// to give integer score of who similar the strings are
float HashTable::similar(const std::string& str1, const std::string& str2){
  std::string s1;
  std::string s2;

  // get bigger string on top
  if(str1.length() < str2.length()){
    s1 = str2;
    s2 = str1;
  }else{
    s1 = str1;
    s2 = str2;
  }
  // now s1 is longer than s2
  float ratio = float(s1.length())/float(s2.length());
  float simScore = ratio;
  for(int i = 0; i < s2.length(); i++){
    // check if the letters match
    if(s2[i] != s1[i]){
      simScore += .5;
    }
    // check if current letter is in bigger word
    bool letterIn = false;
    for(int j = 0; j < s1.length(); j++){
      if(s1[j] == s2[i]){
        letterIn = true;
      }
    }
    // if this current letter wasn't in the bigger word, add it to score
    if(!letterIn){
      simScore += .5;
    }
  }

  // compute score, lower the better
  return ratio * simScore;
}

int main() {
  // TimeInterval
  TimeInterval t = TimeInterval();

  HashTable map;
  // file parsing
  std::fstream allWords;
  allWords.open("Dictionary.txt", std::ios::in);
  if(allWords.is_open()){
    std::string curWord;
    while(getline(allWords, curWord)){
      // function copied from https://www.csinfo360.com/2020/04/uppercase-to-lowercase-without-using-inbuilt-function.html to lowercase it, just for America.
      int i = 0;
      while (curWord[i] != '\0'){
        if(curWord[i] >= 'A' && curWord[i] <= 'Z'){
          curWord[i] += 32;
        }
        i++;
      }
      // this line copied from https://www.cplusplus.com/reference/string/string/find_last_not_of/ to remove whitespace
      curWord.erase(curWord.find_last_not_of(" \n\r\t\f\v") + 1);
      map.insert(curWord);
    }
    allWords.close();
  }else{
    std::cout << "Dictionary.txt could not be found\n";
  }
  // method to print table
  // map.printTable();
  t.start();
  std::string userIn;
  std::cout << "look for a word: ";
  std::cin >> userIn;
  // strip whitespace from userIn
  userIn.erase(userIn.find_last_not_of(" \n\r\t\f\v") + 1);
  map.takeInput(userIn);
  
  t.stop();
  std::cout << t.GetInterval()
   << " micro-sec\n";
  return 0;
}
