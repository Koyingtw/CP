int read_int() {
    int _n = 0, _f = 0;
    char _c = getchar();
    while (_c < '0' or _c > '9') _f |= _c == '-', _c = getchar();
    while (_c >= '0' and _c <= '9') _n = (_n << 3) + (_n << 1) + (_c ^ 48), _c = getchar();
    return _f ? -_n : _n;
}
