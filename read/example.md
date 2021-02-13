### sql query examples
1. select product_id from Products where low_fats='Y' and recyclable='Y';


### valid palindrome

```
class Solution {
    string prune(const string& s){
        string ss;
        for(auto c : s){
            if(c >= 'a' && c <= 'z')
                ss += c;
            if(c >= 'A' && c <= 'Z')
                ss += c-'A'+'a';
            if(c >= '0' && c <= '9')
                ss += c;
        }
        return ss;
    }
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        if(s.size()==1) return true;
        
        string ss = prune(s);
        
        int left(0);
        int right(ss.length()-1);
        cout << "pruned: "<< ss << endl;
        while(left < right){
            if(ss[left] != ss[right]){
                cout << "left, right "<< left<<", "<<right<<", "<<ss[left]<<", "<<ss[right]<<endl;
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
```

### remove duplicates
```
class RemoveDuplicates {
 public:
static int remove(vector<int>& arr) {
    int nextNonDuplicate = 1;  // index of the next non-duplicate element
    for (int i = 1; i < arr.size(); i++) {
      if (arr[nextNonDuplicate - 1] != arr[i]) {
        arr[nextNonDuplicate] = arr[i];
        nextNonDuplicate++;
      }
    }

    return nextNonDuplicate;
  }
};
```

### binomial coeffinient
```
int binomialCoeff(int n, int k)  
{  
    // Base Cases  
    if (k == 0 || k == n)  
        return 1;  
  
    // Recur  
    return binomialCoeff(n - 1, k - 1) +  
                binomialCoeff(n - 1, k);  
}  
  
```
