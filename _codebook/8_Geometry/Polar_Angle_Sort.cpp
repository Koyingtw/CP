bool cmp(pdd a, pdd b) {
#define is_neg(k) (sign(k.Y) < 0 || (sign(k.Y) == 0 && sign(k.X) < 0))
  int A = is_neg(a), B = is_neg(b);
  if (A != B)
    return A < B;
  if (sign(cross(a, b)) == 0)
    return abs2(a) < abs2(b);
  return sign(cross(a, b)) > 0;
}
