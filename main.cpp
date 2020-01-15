#include <cstdlib>
#include "StackAr.h"
#include "dsexceptions.h"
#include "LinkedList.h"
#include "CursorList.h"
#include "QueueAr.h"
#include "StackLi.h"
#include "vector.h"
#include "SkipList.h"
#include "CPUTimer.h"

int getChoice();

int main(){
    int choice;
    CPUTimer ct;

    cout << "Filename >> ";

    do
    {
        cout << "     ADT Menu" << endl;
        cout << "0. Quit" << endl;
        cout << "1. LinkedList" << endl;
        cout << "2. CursorList" << endl;
        cout << "3. StackAr" << endl;
        cout << "4. StackLi" << endl;
        cout << "5. QueueAr" << endl;
        cout << "6. SkipList" << endl;
        cout << "Your choice >> ";
        choice = getChoice();
        ct.reset();
        switch (choice)
        {
            case 1: RunList(filename); break;
            case 2: RunCursorList(filename); break;
            case 3: RunStackAr(filename); break;
            case 4: RunStackLi(filename); break;
            case 5: RunQueueAr(filename); break;
            case 6: RunSkipList(filename); break;
        }
        cout << "CPU time: " << ct.cur_CPUTime() << endl;
    } while(choice > 0);
}

int getChoice(){
    int choice;
    cin >> choice;
    return choice;
}