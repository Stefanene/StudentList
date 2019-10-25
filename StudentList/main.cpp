//This program is StudentList
// by Stefan Ene
//   vector commands learned from https://www.geeksforgeeks.org/vector-in-cpp-stl/
//   vector iteraton command from https://stackoverflow.com/questions/36826165/iterating-through-a-vector-of-pointers-and-printing-out-values
//   help from Sethu Eapen on ADD function
//   help from Cal Epstin on rounding GPA to two places 
//Date finished: 10/25/2019

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//student structure
struct stud {
  char Fname[81];
  char Lname[81];
  int id;
  float gpa;
};

//function
stud* ADD();
void PRINT(vector<stud*> sList);
void DELETE(vector<stud*>* sList, int id);

int main() {
  char input[7];
  bool go = true;
  vector<stud*> sList;
  cout << "This is Student List." << endl;
  while (go) {
    cout << "Four commands: ADD, PRINT, DELETE, and QUIT." << endl;
    cin >> input;
    //if input is ADD or add
    if ((input[0] == 'A' && input[1] == 'D' && input[2] == 'D') ||
	(input[0] == 'a' && input[1] == 'd' && input[2] == 'd')) {
      cout << "You chose to create a new student." << endl;
      go = true;
      //run ADD function
      sList.push_back(ADD());
    }
    //if input is PRINT or print
    else if ((input[0] == 'P' && input[1] == 'R' && input[2] == 'I'
	     && input[3] == 'N' && input[4] == 'T') ||
	     (input[0] == 'p' && input [1] == 'r' && input[2] == 'i'
	     && input[3] == 'n' && input[4] == 't')) {
      cout << "You chose to see all the students." << endl;
      go = true;
      //run PRINT function
      PRINT(sList);
    }
    //if input is DELETE or delete
    else if ((input[0] == 'D' && input[1] == 'E' && input[2] == 'L' &&
	      input[3] == 'E' && input[4] == 'T' && input[5] == 'E') ||
	     (input[0] == 'd' && input[1] == 'e' && input[2] == 'l' &&
	      input[3] == 'e' && input[4] == 't' && input[5] == 'e')) {
      cout << "You chose to remove a student." << endl;
      cout << "Enter a student ID: " << endl;
      int idIn;
      cin >> idIn;
      go = true;
      //run DELETE function
      DELETE(&sList, idIn);
    }
    //if input is QUIT or quit
    else if ((input[0] == 'Q' && input[1] == 'U' && input[2] == 'I' && input[3] == 'T') ||
	     (input[0] == 'q' && input[1] == 'u' && input[2] == 'i' && input[3] == 't')) {
      cout << "Program will terminate. Thank you for using it!" << endl;
      go = false;
    }
    //else, wrong input
    else {    
      cout << "Invalid input. Please try again: " << endl;
      go = true;
    }
  }
  
  
  return 0;
}

//ADD function
stud* ADD() {
  stud* newStud = new stud();
  cout << "Enter first name: " << endl;
  cin >> newStud->Fname;
  cin.clear();
  cin.ignore(81,'\n');
  cout << "Enter last name: " << endl;
  cin >> newStud->Lname;
  cin.clear();
  cin.ignore(81,'\n');
  cout << "Enter ID: " << endl;
  cin >> newStud->id;
  cin.clear();
  cin.ignore(81,'\n');
  cout << "Enter GPA: " << endl;
  float idVal;
  cin >> newStud->gpa;
  cin.clear();
  cin.ignore(81, '\n');
  //return new student pointer
  return newStud;
}

//PRINT function
void PRINT(vector<stud*> sList) {
  //call iterator
  vector<stud*>::iterator iter;
  for (iter = sList.begin(); iter != sList.end(); ++iter) {
    cout << (*iter)->Fname << " " << (*iter)->Lname << ", ";
    cout << (*iter)->id << ", ";
    //round gpa to two decimals
    cout << fixed << setprecision(2) << (*iter)->gpa << endl;
  }
}

//DELETE function
void DELETE(vector<stud*>* sList, int id) {
  vector<stud*>::iterator iter;
  for(iter = sList->begin(); iter != sList->end(); ++iter) {
    if((*iter)->id == id) {
      cout << "Deleted student id# : " << id << endl;
      delete *iter;
      sList->erase(iter);
      //if student is found
      return;
    }
  }
  //if student not found
  cout << "Invalid ID." << endl;
}

