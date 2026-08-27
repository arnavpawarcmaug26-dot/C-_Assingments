#include<iostream>
using namespace std;

void resetSensorPairV1(int reading1, int reading2){
    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;

}
void resetSensorPairV2(int &reading1, int &reading2){
    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;
    
}
void resetSensorPairV3(int *reading1, int *reading2){
    int temp = *reading1;
    *reading1 = *reading2;
    *reading2 = temp;
}

int main(){
    int r1 = 55;
    int r2 = 12;
    cout<<"V1: Call by Value: "<<endl;
    cout<<"Before: "<<"A: "<<r1<<endl;
    cout<<"Before: "<<"B: "<<r2<<endl;

    resetSensorPairV1(r1,r2);

    cout<<"After: "<<"A: "<<r1<<endl;
    cout<<"After: "<<"B: "<<r2<<endl;

    cout<<"V1: Call by Reference: "<<endl;
    cout<<"Before: "<<"A: "<<r1<<endl;
    cout<<"Before: "<<"B: "<<r2<<endl;

    resetSensorPairV2(r1,r2);

    cout<<"After: "<<"A: "<<r1<<endl;
    cout<<"After: "<<"B: "<<r2<<endl;

    cout<<"V1: Call by Pointer: "<<endl;
    cout<<"Before: "<<"A: "<<r1<<endl;
    cout<<"Before: "<<"B: "<<r2<<endl;

    resetSensorPairV3(&r1,&r2);

    cout<<"After: "<<"A: "<<r1<<endl;
    cout<<"After: "<<"B: "<<r2<<endl;


    

    return 0;
}