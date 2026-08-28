#include <iostream>
#include <string>

using namespace std;


int main(int argc, char* argv[]) {
    

    if (argc != 4) {
        cout << "Usage  : " << argv[0] << " <warn_threshold> <critical_threshold> <num_readings>" << endl;
        cout << "Error  : Missing arguments." << endl;
        return 1; 
    }

    double warn_threshold = stod(argv[1]);
    double critical_threshold = stod(argv[2]);
    int num_readings = stoi(argv[3]);

    double arr[3][3];
    cout << "Config: " <<"Warn= "<< warn_threshold <<", Critical= "<< critical_threshold <<", Readings= "<<num_readings<<endl;

    return 0;
}
