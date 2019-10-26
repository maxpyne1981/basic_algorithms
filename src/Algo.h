#pragma once
#include <string>
#include <math.h>
class Algo{
public:
    Algo();
    ~Algo();


    int GCD(int a, int b){
        std::cout << "GCD a b "<< a << ", "<< b << std::endl;
        if( b == 0) return a;
        return GCD(b, a % b);
    }

    void primeFactors(int n)  
    {  
        // Print the number of 2s that divide n  
        while (n % 2 == 0)  
        {  
            std::cout << 2 << " ";  
            n = n/2;  
        }  

        // n must be odd at this point. So we can skip  
        // one element (Note i = i +2)  
        for (int i = 3; i <= std::sqrt(n); i = i + 2)  
        {  
            // While i divides n, print i and divide n  
            while (n % i == 0)  
            {  
                std::cout << i << " ";  
                n = n/i;  
            }  
        }  

        // This condition is to handle the case when n  
        // is a prime number greater than 2  
        if (n > 2)  
            std::cout << n << " ";  
        std::cout << std::endl;
    }


    //C(n, k) = C(n-1, k-1) + C(n-1, k)
    //C(n, 0) = C(n, n) = 1
    int binomial(int n, int k){
        if(k==0 || k == n) return 1;
        return binomial(n-1, k-1) + binomial(n-1, k);
    }

    void Run();
private:
    bool IsPalindrome(std::string str);
    int FindSquaredSumOfDigits(int num);



};
