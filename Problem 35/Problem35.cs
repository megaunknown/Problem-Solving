using System;
using System.Collections;
using System.Text;


namespace Problem35
{
    class Program
    {
        /*
        The number, 197, is called a circular prime because all rotations of the digits:
        197, 971, and 719, are themselves prime.

        There are thirteen such primes below 100:
        2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

        How many circular primes are there below one million?

         */
        static void Main(string[] args)
        {
            int iCounter = 0;
            
            //Get the prime list
           ArrayList arPrimList = getPrimsBelowN(100);
            //Console.WriteLine(arPrimList.Count);
            //Console.Read();
            ArrayList arPrimList = getPrimsBelowN(1000000);

            for (int i = 0; i < arPrimList.Count - 1; i++)
            {
                ArrayList ar = getCircularList(Convert.ToInt32(arPrimList[i]));
                if (isCircularPrime(ar))
                {
                    iCounter++;
                    Console.WriteLine("Cicular prime has added.");
                }
                else
                {
                    //   Console.WriteLine(Convert.ToString(ar[i]) + " is not circular prime .");
                }
            }
            //55
            Console.WriteLine("The number of Cicular primes is :" + iCounter.ToString());
            Console.Read();
        }

        static void printCircular(int N)
        {
            ArrayList ss = getCircularList(N);
            Console.WriteLine("The circular list for " + N.ToString() + " is :");

            for (int i = 0; i < ss.Count; i++)
            {
                Console.WriteLine(ss[i]);
            }
        }

        static string rotateString(string N)
        {
            string strTmp = N;
            if (strTmp.Length == 1)
                return strTmp;


            string p1 = strTmp.Substring(0, 1);
            string p2 = strTmp.Substring(1, strTmp.Length - 1);
            string Ret = p2 + p1;

            return Ret;
        }

        static ArrayList getCircularList(int N)
        {
            string strTmp = Convert.ToString(N);
            ArrayList arList = new ArrayList();
            string rotatedNumer;

            for (int i = 0; i < strTmp.Length; i++)
            {
                if (i == 0)
                {
                    rotatedNumer = rotateString(strTmp);
                    arList.Add(rotatedNumer);
                }
                else
                {
                    rotatedNumer = rotateString(Convert.ToString(arList[i - 1]));
                    arList.Add(rotatedNumer);

                }

            }
            return arList;
        }


        static bool isCircularPrime(ArrayList iInput)
        {
            bool bResult = true;

            for (int i = 0 ; i < iInput.Count - 1; i++)
            {
                if ( isPrime( Convert.ToInt32(iInput[i])) == false)
                {
                    bResult = false;
                    break;
                }
            }
            return bResult;
        }

        static ArrayList getPrimsBelowN(int N)
        {
            ArrayList arList = new ArrayList();
            for (int i = 2; i <= N; i++)
            {
                if (isPrime(i))
                {
                    arList.Add(i);
                }
            }
            return arList;
        }

        static bool isPrime(int number)
        {
            int i;
            for (i = 2; i <= number - 1; i++)
            {
                if (number % i == 0)
                {
                    return false;
                }
            }
            if (i == number)
            {
                return true;
            }
            return false;
 
        }

        static bool IsPrimeX(int candidate)
        {
            bool bRet = false ;
            int temp = candidate & 1;

            Console.WriteLine("Temp"  + temp.ToString());

            if ((candidate & 1) == 0)
            {
                if (candidate == 2)
                {
                    bRet = true;
                }
                else
                {
                    bRet =  false;
                }
            }

            for (int i = 3; (i * i) <= candidate; i += 2)
            {
                if ((candidate % i) == 0)
                {
                    return false;
                }
            }
            return candidate != 1;

            return bRet;
        }
    }
}

     