// MOD=2^61-1
i128 t = a * b;
t = (t >> 61) + (t & MOD);

if (t >= MOD) return t - MOD;
return t;
