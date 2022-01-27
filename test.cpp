#include "mini_format.h"

struct T {
    int n;
};

inline std::ostream &operator<<(std::ostream &os, const T &t) {
    return os << mini_format("T({})", t.n);
}

template<typename Type>
inline std::ostream &operator<<(std::ostream &os, const std::vector<Type> &ts) {
    os << "vector(";
    for (size_t i = 0; i < ts.size(); ++i) os << (i == 0 ? "" : ",") << ts[i];
    return os << ")";
}


int main() {
    T t{1024};

    // format string
    std::string str = mini_format("xyz is {}", 999);

    // print string
    mini_print("tom = {}, jerry = {}\n", "abcd", 1234);
    mini_print("float = {}, string = {}, t = {}\n", 3.14159, str, t);

    // log output
    MINI_LOG("tom = {}, jerry = {}\n", "abcd", 1234);
    MINI_LOG("double = {}, string = {}\n", 3.14159, str);
	
	// print vector 
    std::vector<double> ts;
    ts.push_back(1.1);
    ts.push_back(2.2);
    ts.push_back(3.3);

    mini_print("{}", ts);	
    return 0;
}
