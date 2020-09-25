#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


void bounds(){
    vector<int> data{1,2,3,4,5,6,7,9,10,11,12};
    
    int value = 8;
    auto up = upper_bound(data.begin(), data.end(), value);
    auto dn = lower_bound(data.begin(), data.end(), value);
    cout << "upper bound : "<< *up << endl;
    cout << "lower bound : "<< *dn << endl;
}



int main(){
    bounds();

    return 0;
}
