#pragma once
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
using namespace std;
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

    
    // daily coding, find perm of phone no.
    void Permute_phNo(){
        map<char, vector<char>> map;
        map['1'] = vector<char>{'a', 'b', 'c'};
        map['2'] = vector<char>{'d', 'e', 'f'};
        map['3'] = vector<char>{'i', 'j', 'k'};

        string ss("123");
        vector<string> res, tmpres;
        for(int i=0; i<(int)ss.length();i++){
            char c = ss[i];
            vector<char> cc = map[c];

            // result is empty
            if(res.empty()) {
                for(auto achar : cc)
                    res.push_back(string(1, achar));
                continue;
            }else{
                for(auto achar : cc)
                    for(auto r : res)
                        tmpres.push_back(string(r) + string(1, achar));
                    
                res = tmpres;
                tmpres.clear();
            }
        }
        cout << "Number of permutations "<< res.size() << endl;
        for(auto s : res) cout << s  << ", ";
        cout << endl;

    }

    // merge intervals problem
    // basically, idea is to merge all intervals and count
    int MergeIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(),
                [](vector<int>& a, vector<int>& b){
                return a.size() < b.size();
                });

        vector<vector<int>> mi; // merged intervals
        for(int i=0; i<intervals.size()-1; i++){
            if(mi.empty()){
                mi.push_back(intervals[i]);
                continue;
            }else{
                // merge
                vector<int>& last = mi.back();
                vector<int> current = intervals[i];

                if(last.size()!=2) continue;
                if(current.size()!=2) continue;
                int lastEnd = last[1];
                int currentStart = current[0];
                int currentEnd   = current[1];
                if(currentStart > lastEnd){
                    mi.push_back(current);
                    continue;
                }else{
                    if(currentEnd > lastEnd)
                        last[1] = currentEnd;
                }

            }

        }
        for(auto a : mi){
            for(auto b : a){
                cout << b << ", ";
            }
            cout << endl;
        }

        return mi.size();
    }
    // keeps only alpha numeric value
    string sanitize(string s){
        string res;
        for( char c : s){
            if(c>='a' && c <='z'){
                res += string(1, c);
            }
            if(c>='A' && c <='Z'){
                res += string(1, c - 'A' + 'a');
            }
            if(c>='0' && c <='9'){
                res += string(1, c);
            }
        }
        return res;
    }



    void Run();
private:
    bool IsPalindrome(std::string str);
    int FindSquaredSumOfDigits(int num);

};



// UNASSIGNED is used for empty cells in sudoku grid  
#define UNASSIGNED 0  
  
// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  
  
class Sudoku{
    public:
    Sudoku(){;}
    ~Sudoku(){;}

    /* Takes a partially filled-in grid and attempts  
       to assign values to all unassigned locations in  
       such a way to meet the requirements for 
       Sudoku solution (non-duplication across rows, 
       columns, and boxes) */
    /* Searches the grid to find an entry that is  
       still unassigned. If found, the reference  
       parameters row, col will be set the location  
       that is unassigned, and true is returned.  
       If no unassigned entries remain, false is returned. */
    bool FindUnassignedLocation(int grid[N][N],  
            int &row, int &col)  
    {  
        for (row = 0; row < N; row++)  
            for (col = 0; col < N; col++)  
                if (grid[row][col] == UNASSIGNED)  
                    return true;  
        return false;  
    }  

    /* Returns a boolean which indicates whether  
       an assigned entry in the specified row matches 
       the given number. */
    bool UsedInRow(int grid[N][N], int row, int num)  
    {  
        for (int col = 0; col < N; col++)  
            if (grid[row][col] == num)  
                return true;  
        return false;  
    }  

    /* Returns a boolean which indicates whether  
       an assigned entry in the specified column 
       matches the given number. */
    bool UsedInCol(int grid[N][N], int col, int num)  
    {  
        for (int row = 0; row < N; row++)  
            if (grid[row][col] == num)  
                return true;  
        return false;  
    }  

    /* Returns a boolean which indicates whether  
       an assigned entry within the specified 3x3 box  
       matches the given number. */
    bool UsedInBox(int grid[N][N], int boxStartRow, 
            int boxStartCol, int num)  
    {  
        for (int row = 0; row < 3; row++)  
            for (int col = 0; col < 3; col++)  
                if (grid[row + boxStartRow] 
                        [col + boxStartCol] == num)  
                    return true;  
        return false;  
    }  

    /* Returns a boolean which indicates whether  
       it will be legal to assign num to the given  
       row, col location. */
    bool isSafe(int grid[N][N], int row,  
            int col, int num)  
    {  
        /* Check if 'num' is not already placed in  
           current row, current column and current 3x3 box */
        return !UsedInRow(grid, row, num) &&  
            !UsedInCol(grid, col, num) &&  
            !UsedInBox(grid, row - row % 3 ,  
                    col - col % 3, num) &&  
            grid[row][col] == UNASSIGNED;  
    }  
    bool SolveSudoku(int grid[N][N])  
    {  
        int row, col;  

        // If there is no unassigned location, 
        // we are done  
        if (!FindUnassignedLocation(grid, row, col))  
            return true; // success!  

        // consider digits 1 to 9  
        for (int num = 1; num <= 9; num++)  
        {  
            // if looks promising  
            if (isSafe(grid, row, col, num))  
            {  
                // make tentative assignment  
                grid[row][col] = num;  

                // return, if success, yay!  
                if (SolveSudoku(grid))  
                    return true;  

                // failure, unmake & try again  
                grid[row][col] = UNASSIGNED;  
            }  
        }  
        return false; // this triggers backtracking  
    }  


    /* A utility function to print grid */
    void printGrid(int grid[N][N])  
    {  
        for (int row = 0; row < N; row++)  
        {  
            for (int col = 0; col < N; col++)  
                std::cout << grid[row][col] << " ";  
            std::cout << std::endl; 
        }  
    }  


    public:
    // Driver Code 
    int Run()  
    {  
        // 0 means unassigned cells  
        int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
            {5, 2, 0, 0, 0, 0, 0, 0, 0},  
            {0, 8, 7, 0, 0, 0, 0, 3, 1},  
            {0, 0, 3, 0, 1, 0, 0, 8, 0},  
            {9, 0, 0, 8, 6, 3, 0, 0, 5},  
            {0, 5, 0, 0, 9, 0, 6, 0, 0},  
            {1, 3, 0, 0, 0, 0, 2, 5, 0},  
            {0, 0, 0, 0, 0, 0, 0, 7, 4},  
            {0, 0, 5, 2, 0, 6, 3, 0, 0}};  
        if (SolveSudoku(grid) == true)  
            printGrid(grid);  
        else
            std::cout << "No solution exists";  

        return 0;  
    }  
};


class KSRecursive{
    public:


    // A utility function that returns maximum of two integers
    int max(int a, int b) { return (a > b)? a : b; }

    // Returns the maximum value that
    // can be put in a knapsack of capacity W
    int knapSack_r(int W, int wt[], int val[], int n)
    {

        // Base Case
        if (n == 0 || W == 0)
            return 0;

        // If weight of the nth item is more
        // than Knapsack capacity W, then
        // this item cannot be included
        // in the optimal solution
        if (wt[n-1] > W)
            return knapSack_r(W, wt, val, n-1);

        // Return the maximum of two cases:
        // (1) nth item included
        // (2) not included
        else return max( val[n-1] + knapSack_r(W-wt[n-1], wt, val, n-1),
                knapSack_r(W, wt, val, n-1) );
    }
    // Returns the maximum value that can be put in a knapsack of capacity W
    int knapSack_dp(int W, int wt[], int val[], int n)
    {
        int i, w;
        int K[n+1][W+1];

        // Build table K[][] in bottom up manner
        for (i = 0; i <= n; i++)
        {
            for (w = 0; w <= W; w++)
            {
                if (i==0 || w==0)
                    K[i][w] = 0;
                else if (wt[i-1] <= w)
                    K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
                else
                    K[i][w] = K[i-1][w];
            }
        }

        return K[n][W];
    }

    // Driver code
    int Run()
    {
        int val[] = {60, 100, 120};
        int wt[] = {10, 20, 30};
        int W = 50;
        int n = sizeof(val)/sizeof(val[0]);
        std::cout<<knapSack_dp(W, wt, val, n)<<std::endl;
        return 0;
    }

};

/*
You start at index 0 in an array with length 'h'. At each step, you can move to the left, move to the right, or stay in the same place(Note! Stay in the same place also takes one step). How many possible ways are you still at index 0 after you have walked 'n' step?

Example： n = 3
1. right->left->stay
2. right->stay->left
3. stay->right->left
4. stay->stay->stay

Can anyone solve it in n^2
*/

class Steps{
    public:
        /* 
            pos -> current pos, 
            i -> current step count, 
            n -> allowed step
            h -> length of array 
        */
        int solve(int pos, int i, int n, int h) { 
            if (i == n && pos == 0) return 1;   // reached final pos 0 at n steps, done
            if (i == n) return 0;               // exhausted all steps
            if (pos >= h || pos < 0) return 0;  // out of bound 

            int cnt = 0;

            cnt += solve(pos - 1,   i + 1,  n,  h); // move left
            cnt += solve(pos,       i + 1,  n,  h); // stay
            cnt += solve(pos + 1,   i + 1,  n,  h); // move right

            return cnt;
        }

    void Run(){
        std:: cout << "Count steps : "<< solve(0, 0, 3, 4) << std::endl;

    }




};
