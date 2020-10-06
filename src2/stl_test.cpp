#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


void bounds(){
    //vector<int> data{1,2,3,5,6,7,9,10,11,12};
    //int value = 4;
    vector<int> data{10,20,20,20,30,40,50};
    int value = 20;
    auto up = upper_bound(data.begin(), data.end(), value);
    auto dn = lower_bound(data.begin(), data.end(), value);

    std::cout << "lower_bound at position " << (dn-data.begin()) << '\n';
    std::cout << "upper_bound at position " << (up-data.begin()) << '\n';

    //cout << "upper bound : "<< *up << endl;
    //cout << "lower bound : "<< *dn << endl;
}



int main(){
    bounds();

    return 0;
}
