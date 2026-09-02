#include <iostream>
using namespace std;

double reorderCost(int qty, double unitPrice){
    return qty*unitPrice;
}

double reorderCost(double  qty, double unitPrice){
    return qty*unitPrice;

}

double reorderCost(int qty, double unitPrice , double taxRate){
    double total = qty * unitPrice;
    total += total * (taxRate / 100.0);
    return total;
}

double applyDiscount(double price, double discountPercent = 10.0){
    return price - (price * (discountPercent / 100.0));
}



int main(){

    cout << "Reorder cost (int qty): " << reorderCost(5, 20.0) << endl;

    cout << "Reorder cost (fractional qty): " << reorderCost(3.5, 20.0) << endl;

    cout << "Reorder cost (with 5% tax): " << reorderCost(5, 20.0, 5.0) << endl;

    cout << "Discounted price (default 10%): " << applyDiscount(200.0) << endl;

    cout << "Discounted price (custom 25%): " << applyDiscount(200.0, 25.0) << endl;

    return 0;
}