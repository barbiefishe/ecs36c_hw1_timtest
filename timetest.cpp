#include "CPUTimer.h"
#include "CursorList.h"
vector< CursorNode <int> > cursorSpace(250000);
#include "LinkedList.h"
#include "QueueAr.h"
#include "SkipList.h"
#include "StackAr.h"
#include "StackLi.h"
#include "vector.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;
int getChoice();
void RunList (char* name);
void RunCursorList (char* name);
void RunStackAr (char* name);
void RunStackLi (char* name);
void RunQueueAr (char* name);
void RunSkipList (char* name);
int main(){
  char Name[20];
  int choice = 9;
  cout << "Filename >> ";
  cin >> Name;
  ifstream myfile(Name);
  if (!myfile){
    cout << "error opening file" << endl;
    return 1;
  }
  CPUTimer ct;
  do {
    choice = getChoice();
    ct.reset();
    switch (choice){
      case 1: RunList (Name); break;
      case 2: RunCursorList (Name); break;
      case 3: RunStackAr (Name); break;
      case 4: RunStackLi (Name); break;
      case 5: RunQueueAr (Name); break;
      case 6: RunSkipList (Name); break;
    }
    cout << "CPU time: " << ct.cur_CPUTime() << endl;;
  } while (choice > 0);
  myfile.close();
}
int getChoice(){
  int choice = 0;
  cout << "ADT Menu" << endl << "0. Quit" << endl << "1. LinkedList" << endl << "2. CursorList" << endl;
  cout << "3. StackAr" << endl << "4. StackLi" << endl << "5. QueueAr" << endl << "6. SkipList" << endl << "Your choice >> ";
  cin >> choice;
  return choice;
}

void RunList (char* name){
  List<int> list;
  string word;
  char x;
  int num;
  ListItr<int> position;
  position = list.zeroth();
  ifstream myfile(name);
  while (myfile >> word){
    x = myfile.get();
    while ( x != ' ' ){
        word = word + x;
        x = myfile.get();
    }
    if (word[0] == 'i') {
        word.erase(word.begin());
        num = atoi(word.c_str());
        list.insert(num, position);
    }
    if (word[0] == 'd'){
        list.remove(num);
    }
    position = list.find(num);
    word.clear();
  }
}

void RunCursorList (char* name){
  CursorList<int> cursor(cursorSpace);
  CursorListItr<int> position = cursor.zeroth();
  string word;
  char x;
  int num;
  ifstream myfile(name);
  while (myfile >> word){
    x = myfile.get();
    while ( x != ' ' ){
        word = word + x;
        x = myfile.get();
    }
    if (word[0] == 'i') {
        word.erase(word.begin());
        num = atoi(word.c_str());
        cursor.insert(num,position);
    }
    if (word[0] == 'd'){
        cursor.remove(num);
    }
    position = cursor.find(num);
    word.clear();
  }
}

void RunStackAr (char* name){
  StackAr<int> stackar(500001);
  string word;
  char x;
  int num;
  ifstream myfile(name);
  while (myfile >> word){
    x = myfile.get();
    while ( x != ' ' ){
        word = word + x;
        x = myfile.get();
    }
    if (word[0] == 'i') {
        word.erase(word.begin());
        num = atoi(word.c_str());
        stackar.push(num);
    }
    if (word[0] == 'd'){
        stackar.pop();
    }
    word.clear();
  }
}

void RunStackLi (char* name){
  StackLi<int> stackli;
  string word;
  char x;
  int num;
  ifstream myfile(name);
  while (myfile >> word){
    x = myfile.get();
    while ( x != ' ' ){
      word = word + x;
      x = myfile.get();
    }
    if (word[0] == 'i') {
      word.erase(word.begin());
      num = atoi(word.c_str());
      stackli.push(num);
    }
    if (word[0] == 'd'){
      stackli.pop();
    }
    word.clear();
  }
}

void RunQueueAr (char* name){
  Queue<int> queue(500001);
  string word;
  char x;
  int num;
  ifstream myfile(name);
  while (myfile >> word){
    x = myfile.get();
    while ( x != ' ' ){
      word = word + x;
      x = myfile.get();
    }
    if (word[0] == 'i') {
      word.erase(word.begin());
      num = atoi(word.c_str());
      queue.enqueue(num);
    }
    if (word[0] == 'd'){
      queue.dequeue();
    }
    word.clear();
  }
}

void RunSkipList (char* name){
  SkipList<int> skiplist(-1, 250000);
  string word;
  char x;
  int num;
  ifstream myfile(name);
  while (myfile >> word){
    x = myfile.get();
    while ( x != ' ' ){
      word = word + x;
      x = myfile.get();
    }
    if (word[0] == 'i') {
      word.erase(word.begin());
      num = atoi(word.c_str());
      skiplist.insert(num);
    }
    if (word[0] == 'd'){
      word.erase(word.begin());
      num = atoi(word.c_str());
      skiplist.deleteNode(num);
    }
    word.clear();
  }
}
