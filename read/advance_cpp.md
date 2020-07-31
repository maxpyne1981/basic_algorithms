# C++ notes

algorithms
- std::for_each(v.begin(), v.end(), lambda_fn);
- std::sort(container.begin(), container.end(), lambda_fn);
- std::reverse(container.begin(), container.end());
- int n = std::count(container.begin(), container.end(), value);
- int n = std::count_if(container.begin(), container.end(), lambda_fn);
- auto last = std::unique(v.begin(), v.end()); v.erase(last, v.end());
- std::copy(from_vector.begin(), from_vector.end(), std::back_inserter(to_vector));
