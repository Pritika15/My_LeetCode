class Solution {
public:
    long modpow(long base, int exp, int modulus) {
  long result = 1;
  for (; exp > 0; exp >>= 1) {
    result = result * (exp & 1 ? base : 1) % modulus;
    base = base * base % modulus;
  }
  return result;
}    

    int maxNiceDivisors(int primeFactors) {
        int n=primeFactors;
        int st[6] = {0, 1, 2, 3, 4, 6}, mod = 1000000007;
    return n < 6 ? st[n] : st[3 + n % 3] * modpow(3, n / 3 - 1, mod) % mod;
    }
};