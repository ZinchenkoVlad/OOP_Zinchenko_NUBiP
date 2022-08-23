#include <iostream>
using namespace std;

class Array {
private:
  short int lenght; // lenght of array
  int *array;

public:
  Array(int lenght); // Constructor
  ~Array();          // Destructor
  void Show();
  friend void count(Array &obj); // friend  func which have permit to read private vals in class Array
};

Array::Array(int temp) {
  lenght = temp;           // set our lenght
  array = new int[lenght]; // create our dunamic array
  for (int i = 0; i < lenght; i++) {
    if (i % 2 == 0) {
      array[i] = i - 6; // if i is even
    } else {            // if i is odd
      array[i] = i;
    }
  }
  cout << "\nelement1: " << array << "\n";
  Show();
}

Array::~Array() {
  delete[] array; // free memory
  cout << "destructor \t" << array <<  endl;
}

void Array::Show() {
  for (int i = 0; i < lenght; i++) {
    cout << array[i] << endl;
  }
}

void count(Array &obj) { // friend func
  int sum = 0;
  cout << "\nelement: " << obj.array << "\n";
  for (int i = 0; i < obj.lenght; i++) {
    if (obj.array[i] < 0) { // if element of array < 0
      cout << obj.array[i] << " ";
      sum++; // count this numbers
    }
  }
  cout << endl;
  cout << "\n Count = " << sum << endl;
}


int main(void) {
  //
  if (true) {
    Array a(12);
    count(a); 
  }

  return 0;
}