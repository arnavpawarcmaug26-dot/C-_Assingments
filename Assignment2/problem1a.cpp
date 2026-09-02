#include <iostream>
using namespace std;

class Product{

    int productId;
    string name;
    double price;
    int quantity;

    public:
    void acceptDetails(){
        cout<<"Enter Details: "<<endl;
        cin>>productId>>name>>price>>quantity;
    }


    void displayDetails() const{
        cout << "==========Product Detail==========" << endl;
        cout<<productId<<endl;
        cout<<name<<endl;
        cout<<price<<endl;
        cout<<quantity<<endl;
    }

    double totalValue(double price , int quantity) const{
        return price*quantity;

    }
    bool isLowStock(int threshold) const{
        if(quantity<threshold){
            return true;
        }
        else{
            return false;
        }

    }
    double getPrice() const { 
        return price; 
    }
    int getQuantity() const {
         return quantity;
         }

};

int main(){

    Product p;
    Product prod_arr[5];

    for(int i=0;i<3;i++){
		prod_arr[i].acceptDetails();
	}

	for(int i=0;i<5;i++){
		prod_arr[i].displayDetails();
	}
    double max_total = 0;
    int max_index = 0;

    for (int i = 0; i < 5; i++) {
            
            double current_total = prod_arr[i].totalValue(prod_arr[i].getPrice(), prod_arr[i].getQuantity());

            if (current_total > max_total) {
                max_total = current_total;
                max_index = i;
            }
        }

    cout << "Highest Total Value Product" << endl;
    prod_arr[max_index].displayDetails();
    cout << "Max Total Value: " << max_total << endl;


    int threshold;
    cout << "\nEnter threshold quantity to check for low stock: ";
    cin >> threshold;

    cout << "\n========== Low Stock Products (Quantity < " << threshold << ") ==========" << endl;
    bool foundAny = false;

    for (int i = 0; i < 3; i++) {
        if (prod_arr[i].isLowStock(threshold)) {
            prod_arr[i].displayDetails();
            foundAny = true;
        }
    }

    if (!foundAny) {
        cout << "No products found with quantity less than " << threshold << endl;
    }
    

    return 0;
}