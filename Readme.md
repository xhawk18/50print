# What's this

c++20 std::format/print implemented by 50 lines.

# Usage

## print formated string

```
void mini_print(const std::string &fmt, const Args &...args);
```

## format string

```
std::string mini_format(const std::string &fmt, const Args &...args);
```

## log out

```
/* Pseudocode, MINI_LOG is a macro */
void MINI_LOG(const std::string &fmt, const Args &...args);
```

## format customer types

override operator<<() on the customer type for ostream is OK.
```
inline std::ostream &operator<<(std::ostream &os, const T &t) {
    return os << "some_string_here";
}
```

# The example
```
#include "mini_format.h"

struct T {
    int n;
};

inline std::ostream &operator<<(std::ostream &os, const T &t) {
    return os << mini_format("T({})", t.n);
}


int main() {
    T t{1024};
    
    std::string str = mini_format("xyz is {}", 999);

    mini_print("tom = {}, jerry = {}\n", "abcd", 1234);
    mini_print("float = {}, string = {}, t = {}\n", 3.14159, str, t);

    MINI_LOG("tom = {}, jerry = {}\n", "abcd", 1234);
    MINI_LOG("double = {}, string = {}\n", 3.14159, str);
    return 0;
}


/* The code outputs :
tom = abcd, jerry = 1234
float = 3.14159, string = xyz is 999, t = T(1024)
[2022-01-25_21:44:46] [test.cpp:20] tom = abcd, jerry = 1234
[2022-01-25_21:44:46] [test.cpp:21] double = 3.14159, string = xyz is 999
*/
```
