
#include <cstdint>
#include <utility>


template<typename...Ts>
void ignore_returnvalues(Ts&...) {}

template<typename ...T>
void go(T &...ts) {
    ignore_returnvalues(++ts...);
}

int main() {
    int a = 0, b = 0;

    printf("was: a=%d, b=%d\n", a, b);

    go(a, b);

    printf("now: a=%d, b=%d\n", a, b);

    return 0;
}


