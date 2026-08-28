#include<iostream>
using namespace std;

int main(){
    int statusReg = 0b10110001;
    int dataReg = 0b11001010;
    const int *regPtr1 = &statusReg;
    
    cout<<*regPtr1<<endl;

    // *regptr1 = dataReg; //wont change value, will result in error. regptr1 is a pointer to const. It provides a read-only window and cannot modify the data.

    int controlReg = 0b00000000;
    int *const regPtr2 = &controlReg;
    int backupReg = 0b00010011;

    cout<<*regPtr2<<endl;
    *regPtr2 = dataReg;

    // regptr2 = &backupReg; //'int* const' is a constant pointer.// The memory address it points to is physically locked at initialization.
            
    cout<<*regPtr2<<endl;

    const int* const regPtr3 = &statusReg;

    cout << *regPtr3 << endl;

    // *regPtr3 = dataReg;
    // ERROR: Pointer points to const int,
    // so the value cannot be modified.

    // regPtr3 = &backupReg;
    // ERROR: Pointer itself is const,
    // so it cannot be repointed.

    return 0;
}