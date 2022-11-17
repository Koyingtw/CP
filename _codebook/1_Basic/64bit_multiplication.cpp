int mul(int a, int b, int p) {
    unsigned int _a(a), _b(b), _p(p), _ans;
    __asm__("mulq %2;divq %3" : "=d"(_ans) : "a"(_a), "m"(_b), "m"(_p));
    return (int)_ans;
}
