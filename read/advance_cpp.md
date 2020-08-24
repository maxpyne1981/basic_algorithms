# C++ notes

## algorithms
- std::for_each(v.begin(), v.end(), lambda_fn);
- std::sort(container.begin(), container.end(), lambda_fn);
- std::reverse(container.begin(), container.end());
- int n = std::count(container.begin(), container.end(), value);
- int n = std::count_if(container.begin(), container.end(), lambda_fn);
- auto last = std::unique(v.begin(), v.end()); v.erase(last, v.end());
- std::copy(from_vector.begin(), from_vector.end(), std::back_inserter(to_vector));


## lambda functions
```
[ capture clause ] (parameters) -> return-type  
{   
   definition of method   
}

sort(v.begin(), v.end(), [](const int& a, const int& b) -> bool
    { 
        return a > b; 
    }); 
```
### Syntax
      - [&] : capture all external variable by reference;
      - [=] : capture all external variable by value;
      - [a, &b] : capture a by value and b by reference;
      - A lambda with empty capture clause [ ] can access only those variable which are local to it;
