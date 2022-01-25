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
