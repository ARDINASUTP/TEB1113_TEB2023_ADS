#include <iostream>
using namespace std;

#define MAX 5

class Stack {
private:
  int arr[MAX];
  int top;
  
public:
  Stack(){
    top=-1;
  }
  
  bool isFull(){
    return top == MAX -1;
  }
  
  bool isEmpty(){
    return top == -1;
  }
  
  void push(int x){
    if (isFull()) {
      cout << "\nSTACK OVERFLOW\n";
      return;
    }
    top++;
    arr[top] = x;
    cout << "\n" << x << " pushed into stack.\n";
  }
  
  void pop(){
    if (isEmpty()){
      cout <<"\nSTACK UNDERFLOW\n";
      return;
    }
    top--;
    cout << "\n" << arr[top+1] << " popped out of stack.\n";
  }
  
  void peek(){
    if(isEmpty()){
      cout << "\nSTACK IS EMPTY\n";
      return;
    }
    cout << "\n" << arr[top] << " is the top element of the stack\n";
  }
  
  void display(){
    if(isEmpty()){
      cout << "\nSTACK IS EMPTY\n";
      return;
    }
    cout << "\nStack: \n";
    for(int i = top; i >=0; i--){
      cout << arr[i] << endl;
    }
  }
  };
int main() {
  Stack test;
  int choice, value;
  
  do{
    cout << "\nMenu: \n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek\n";
    cout << "4. Display Stack\n";
    cout << "5. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;
    
      switch(choice){
    case 1:
      cout << "Enter value to push: ";
      cin >> value;
      test.push(value);
      break;
    
    case 2:
      test.pop();
      break;
    
    case 3:
      test.peek();
      break;
    
    case 4:
      test.display();
      break;
      
    case 5:
    cout << "\nExiting program.\n";
    break;
    
    default:
    cout << "\nInvalid Choice\n";
    
  }
  } while(choice !=5);
  

return 0;
}

