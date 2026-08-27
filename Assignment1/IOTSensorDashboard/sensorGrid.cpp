#include<iostream>
using namespace std;


int main(){
    double arr[3][3];
    cout << "Enter 9 integers for a 3x3 arr:"<<endl;
    for(int i=0; i<3; i++){
        for(int j=0;j<3; j++){
            cin >> arr[i][j];
        }
    }
   cout << "The entered 3x3 arr is: "<<endl;
    for (int i = 0; i < 3; ++i) {
        cout << "Floor " << (i + 1) << ": ";
        for (int j = 0; j < 3; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    double maxTemp = arr[0][0];
    int maxFloorIdx = 0;
    int maxRoomIdx = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (arr[i][j] > maxTemp) {
                maxTemp = arr[i][j];
                maxFloorIdx = i;
                maxRoomIdx = j;
            }
        }
    }

    cout << "Hottest room: floor " << (maxFloorIdx + 1) << " room " << (maxRoomIdx + 1) << endl;

    double maxAvg = 0.0;
    int hottestFloorIdx = 0;

    for (int i = 0; i < 3; ++i) {
        double floorSum = 0.0;
        for (int j = 0; j < 3; ++j) {
            floorSum += arr[i][j];
        }
        double floorAvg = floorSum / 3.0;
        if (i == 0 || floorAvg > maxAvg) {
            maxAvg = floorAvg;
            hottestFloorIdx = i;
        }
    }

    cout << "Hottest floor: floor " << (hottestFloorIdx + 1)<<"("<< maxAvg<< "C"<< ")" << endl;

    int countAbove30 = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (arr[i][j] >= 30.0) {
                countAbove30++;
            }
        }
    }

    cout << "Rooms at warning or above: " << countAbove30 << endl;

    return 0;
}