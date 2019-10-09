#include <iostream>
#include <bits/stdc++.h>
#include "Algo.h"
using namespace std;

Algo::Algo()
{
    ;
}
Algo::~Algo(){
    ;
}

//////////////////////////////////////////////////
//////////// KARATSBA MULTIPLICATION /////////////
//////////////////////////////////////////////////
//https://drawar.github.io/karatsuba-cpp/
// assumptions that all chars in the string represent digits
#define max(a,b) ((a) > (b) ? (a) : (b))
string add(string lhs, string rhs) {
    int length = max(lhs.size(), rhs.size());
    int carry = 0;
    int sum_col;  // sum of two digits in the same column
    string result;

    // pad the shorter string with zeros
    while (lhs.size() < length) 
      lhs.insert(0,"0");
            
    while (rhs.size() < length) 
      rhs.insert(0,"0");

    // build result string from right to left
    for (int i = length-1; i >= 0; i--) {
      sum_col = (lhs[i]-'0') + (rhs[i]-'0') + carry;
      carry = sum_col/10;
      result.insert(0,to_string(sum_col % 10));
    }
    
    if (carry)
      result.insert(0,to_string(carry));
    
    // remove leading zeros
    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

string subtract(string lhs, string rhs) {
    int length = max(lhs.size(), rhs.size());
    int diff;
    string result;

    while (lhs.size() < length) 
      lhs.insert(0,"0");
            
    while (rhs.size() < length) 
      rhs.insert(0,"0");

    for (int i = length-1; i >= 0; i--) {
        diff = (lhs[i]-'0') - (rhs[i]-'0');
        if (diff >= 0)
            result.insert(0, to_string(diff));
        else {

            // borrow from the previous column
            int j = i - 1;
            while (j >= 0) {
                lhs[j] = ((lhs[j]-'0') - 1) % 10 + '0';
                if (lhs[j] != '9') 
                    break;
                else 
                    j--;
            }
            result.insert(0, to_string(diff+10));
        }
      
    }

    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}
/*
X = (a + b)
Y = (c + d)
X*Y = (a+b)*(c+d)
    = ac + bd + ad + bc


*/
string multiply(string lhs, string rhs) {
    int length = max(lhs.size(), rhs.size());
    
    while (lhs.size() < length) 
      lhs.insert(0,"0");

    while (rhs.size() < length) 
      rhs.insert(0,"0");

    if (length == 1)
        return to_string((lhs[0]-'0')*(rhs[0]-'0'));

    string lhs0 = lhs.substr(0,length/2);
    string lhs1 = lhs.substr(length/2,length-length/2);
    string rhs0 = rhs.substr(0,length/2);
    string rhs1 = rhs.substr(length/2,length-length/2);
    
    string p0 = multiply(lhs0,rhs0);
    string p1 = multiply(lhs1,rhs1);
    string p2 = multiply(add(lhs0,lhs1),add(rhs0,rhs1));
    string p3 = subtract(p2,add(p0,p1));

    for (int i = 0; i < 2*(length-length/2); i++)
        p0.append("0");
    for (int i = 0; i < length-length/2; i++)
        p3.append("0");
        
    string result = add(add(p0,p1),p3);

    return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}
/////////////////////////////////////////
//////////// class functions ////////////
/////////////////////////////////////////
// use Two Pointers
bool Algo::IsPalindrome(string str){
    if(str.empty()) return false;

    int start(0);
    int end(str.size()-1);
    while(start <= end){
        if(str[start++] != str[end--]) 
            return false;
    }
    return true;
}
int Algo::FindSquaredSumOfDigits(int num){
   if(num<0) return 0;
   int sum(0);
   while(num > 0){
        int digit = num % 10;     
        sum += digit*digit;
        num /= 10;
   }
   return sum;
}

/////////////////////////////////////////
//////////// Run tests //////////////////
/////////////////////////////////////////
void Algo::Run(){
    /*string lhs = "3141592653589793238462643383279502884197169399375105820974944592";
    string rhs = "2718281828459045235360287471352662497757247093699959574966967627";
    cout << "Karatsuba multiplication : "<< multiply(lhs, rhs) << endl;*/

    /*string str = "0ABCDCBA";
    cout <<"Is "<< str << " a palindrome  "<< IsPalindrome(str) << endl ;*/
    
    int num = 12345;
    cout<< "FindSquaredSumOfDigits " << num <<" is "<< FindSquaredSumOfDigits(num) << endl;
}


