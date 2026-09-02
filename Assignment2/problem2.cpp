#include <iostream>
#include <string>

using namespace std;

class Patient {
private:
    int patientId;
    string name;
    int age;
    string ward;
    const string bloodGroup; 

public:
    Patient() 
        : patientId(0), name("Unknown"), age(0), ward("General"), bloodGroup("O+") {
        cout << "[Constructor] Default patient registered." << endl;
    }

   
    Patient(int id, const string& name) 
        : patientId(id), name(name), age(0), ward("Emergency"), bloodGroup("Unknown") {
        cout << "[Constructor] Emergency: " << this->name << endl;
    }

    Patient(int id, const string& name, int age, const string& ward, const string& bg) 
        : patientId(id), name(name), age(age), ward(ward), bloodGroup(bg) {
        cout << "[Constructor] Full admission: " << this->name << endl;
    }

    ~Patient() {
        cout << "[Destructor] Patient " << name << " discharged." << endl;
    }

    void displayRecord() const {
        cout << "\nPatient Record:" << endl;
        cout << "  ID        : " << patientId << endl;
        cout << "  Name      : " << name << endl;
        cout << "  Age       : " << age << endl;
        cout << "  Ward      : " << ward << endl;
        cout << "  Blood Grp : " << bloodGroup << endl;
    }

    void transferWard(const string& newWard) {
        cout << "\nWard Transfer: " << name << " -> " << newWard << endl;
        ward = newWard;
    }
};

int main() {
  
    cout << "--- Creating Stack Patients ---" << endl;
    Patient p1(1001, "Meera Joshi", 34, "Cardiology", "B+"); 
    Patient p2(1002, "Raj Patel");                          
    Patient p3;                                        

    cout << "\n--- Creating Heap Array of 4 Patients ---" << endl;
    Patient* wardPatients = new Patient[4];


    cout << "\n--- Displaying Dynamic Patients ---" << endl;
    for (int i = 0; i < 4; ++i) {
        wardPatients[i].displayRecord();
    }

    p1.displayRecord();


    p2.transferWard("ICU");

    cout << "\n--- Deleting Heap Array ---" << endl;
    delete[] wardPatients;

    return 0;
}