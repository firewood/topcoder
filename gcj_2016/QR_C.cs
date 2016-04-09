// Google Code Jam 2016 Qualification Round
// Problem C. Coin Jam

using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Numerics;

namespace ConsoleApplication1
{
    class Program
    {
        static List<int> gen_primes(int m) {
            List<int> primes = new List<int>();
            primes.Add(2);
            int[] f = new int[m];
            for (int i = 3; i < m; i += 2)
            {
                if (f[i] == 0)
                {
                    primes.Add(i);
                    for (int j = i * 2; j < m; j += i)
                    {
                        f[j] = 1;
                    }
                }
            }
            return primes;
        }

        static BigInteger digitsToInteger(int N, int[] digits, int radix)
        {
            BigInteger n = 0;
            for (int k = 0; k < N; ++k)
            {
                n = n * radix + digits[k];
            }
            return n;
        }

        static bool check(int N, List<int> primes, int[] digits, int[] divisors) {
            for (int j = 2; j <= 10; ++j)
            {
                BigInteger n = digitsToInteger(N, digits, j);
                foreach (int p in primes)
                {
                    if (p >= n)
                    {
                        break;
                    }
                    if ((n % p) == 0)
                    {
                        divisors[j] = p;
                        break;
                    }
                }
                if (divisors[j] == 0)
                {
                    return false;
                }
            }
            return true;
        }

        static void solve(int N, int J)
        {
            List<int> primes = gen_primes(65536);
            HashSet<BigInteger> u = new HashSet<BigInteger>();
            Random rnd = new Random();
            for (int i = 0; i < J; ++i)
            {
                while (true)
                {
                    int[] digits = new int[N];
                    digits[0] = 1;
                    digits[N - 1] = 1;
                    for (int j = 1; j < N - 1; ++j)
                    {
                        digits[j] = rnd.Next(2);
                    }
                    int[] divisors = new int[11];
                    if (check(N, primes, digits, divisors)) {
                        BigInteger n = digitsToInteger(N, digits, 10);
                        if (!u.Contains(n))
                        {
                            u.Add(n);
                            Console.Write("{0}", n);
                            for (int j = 2; j <= 10; ++j)
                            {
                                Console.Write(" {0}", divisors[j]);
                            }
                            Console.WriteLine("");
                            break;
                        }
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            TextReader input = Console.In;
            int T = int.Parse(input.ReadLine());
            for (int t = 1; t <= T; ++t)
            {
                Console.WriteLine("Case #{0}:", t);
                string[] req = input.ReadLine().Split(' ');
                solve(int.Parse(req[0]), int.Parse(req[1]));
            }
        }
    }
}
