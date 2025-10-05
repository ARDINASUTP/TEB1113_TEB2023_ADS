#include <iostream>
using namespace std;

struct Student{
  int student_id;
  string student_name;
  string student_email;
};

int main()
{
    Student student[5];
  
  for (int i=0; i<3; i++){
    cout << "Enter Student ID: ";
    cin >> student[i].student_id;
    
    cout << "Enter Student Name: ";
    cin >> student[i].student_name;
    
    cout << "Enter Student Email: ";
    cin >> student[i].student_email;
    cout << "\n";
  }
 
  cout << "Student List:\n";
  for (int i=0; i<3; i++){
    cout << i+1 << ") \n" ;
    cout << "ID: " << student[i].student_id << "\nName: " << student[i].student_name << "\nEmail: " << student[i].student_email << "\n\n";
  }
  
}