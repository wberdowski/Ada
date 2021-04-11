using System;
using System.Collections.Generic;
using System.Linq;

namespace SortowanieLaczenieNaturalne
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            int iter = 4; // liczba iteracji

            List<int> tab = new List<int>(){ // tablica wartości
                1,9,8,7,4,5,7,6,1,4,0,9,8,1,3,4,8,1,7
            };

            int n = tab.Count; // Rozmiar zbioru liczb

            for (int i = 0; i < iter; i++)
            {
                tab = Sort(tab, n);

                foreach (var e in tab)
                {
                    Console.Write(e);
                }

                Console.WriteLine();
            }

            if (tab.SequenceEqual(new List<int>() { 0, 1, 1, 1, 1, 3, 4, 4, 4, 5, 6, 7, 7, 7, 8, 8, 8, 9, 9 }))
            {
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine("OK");
                Console.ResetColor();
            } else
            {
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine("OK");
                Console.ResetColor();
            }
        }

        private static List<int> Sort(List<int> tab, int n)
        {
            List<List<int>> tapeA = new List<List<int>>();
            List<List<int>> tapeB = new List<List<int>>();

            // Znajdź serie
            int tape = 0;

            for (int i = 0; i < n; i++)
            {
                var s = new List<int>();

                s.Add(tab[i]);

                while (i + 1 < n && tab[i + 1] >= tab[i])
                {
                    s.Add(tab[i + 1]);
                    i++;
                }

                if (tape == 0)
                {
                    tapeA.Add(s);
                } else
                {
                    tapeB.Add(s);
                }

                tape = (tape + 1) % 2;
            }

            return Merge(tapeA, tapeB);
        }

        private static List<int> Merge(List<List<int>> tapeA, List<List<int>> tapeB)
        {
            List<List<int>> tapeC = new List<List<int>>();

            int i = 0;

            while (i < tapeA.Count || i < tapeB.Count)
            {
                if (i >= tapeA.Count)
                {
                    tapeC.Add(tapeB[i++]);
                    continue;
                }

                if (i >= tapeB.Count)
                {
                    tapeC.Add(tapeA[i++]);
                    continue;
                }

                int a = 0;
                int b = 0;

                List<int> s = new List<int>();

                while (a < tapeA[i].Count || b < tapeB[i].Count)
                {
                    if (a >= tapeA[i].Count)
                    {
                        s.Add(tapeB[i][b++]);
                        continue;
                    }

                    if (b >= tapeB[i].Count)
                    {
                        s.Add(tapeA[i][a++]);
                        continue;
                    }

                    if (tapeA[i][a] < tapeB[i][b])
                    {
                        s.Add(tapeA[i][a++]);
                    } else
                    {
                        s.Add(tapeB[i][b++]);
                    }
                }

                tapeC.Add(s);

                i++;
            }

            List<int> output = new List<int>();

            foreach (var s in tapeC)
            {
                foreach (var e in s)
                {
                    output.Add(e);
                }
            }

            return output;
        }
    }
}
