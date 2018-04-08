using System;
using System.Collections;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        

        public static ArrayList PrimeFactor(long num)
        {
            ArrayList ar = new ArrayList();
            long i = 2;

            for ( i = 2 ; i <= num ; )
            {
                if (num % i == 0)
                {
                    ar.Add(i);
                    num = num / i;
                    i = 2;
                }
                else
                {
                    i++;
                }
                
            }

            ar = ConvIntoEx(ar);

            return ar;
        }

        public static ArrayList ConvIntoEx(ArrayList arrLis)
        {
            ArrayList ar = new ArrayList();
            int curItem = 0;
            int exp = 1;

            while (arrLis.Count != 0)
            {
                curItem = Convert.ToInt16(arrLis[0]);

                for (int j =  1; j < arrLis.Count; )
                {
                    if (curItem == Convert.ToInt16(arrLis[j]))
                    {
                        exp++;
                        arrLis.RemoveAt(j);
                    }
                    else
                    {
                        j++;
                    }
                }
                ar.Add(Math.Pow(curItem, exp));
                arrLis.RemoveAt(0);

                exp = 1;
            }
               
            return ar;
        }

        public static void viewArrayList(ArrayList a)
        {
            for (int i = 0; i < a.Count; i++)
            {
                Console.Write(a[i].ToString() + ",");
            }
        }

        static void Main(string[] args)
        {
            ArrayList ar = new ArrayList();
            ar = PrimeFactor(600851475143);
            viewArrayList(ar);
            Console.Read();
        }
    }
}
