
﻿using System;
using System.Collections;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {

            int max = 0;
            int n = 0;
            int i;

            ArrayList firstCol = new ArrayList();
            ArrayList secondCol = new ArrayList();

            //Load the Columns...
            for (i = 100; i < 1000; i++)
            {
                firstCol.Add(i); secondCol.Add(i);
            }

            for (i = 0; i < firstCol.Count; i++)
            {
                for (int j = 0; j < secondCol.Count; j++)
                {
                    n = Convert.ToInt16(firstCol[i]) * Convert.ToInt16(secondCol[j]);
                    if (IsPalindrome(n.ToString()))
                    {
                        if (n > max)
                            max = n;
                    }
                }
            }
            Console.WriteLine(max);
            Console.Read();
        }

        /// <summary>
        /// Reverse String...
        /// </summary>
        /// <param name="str"></param>
        /// <returns></returns>
        public static string revString(string str)
        {
            string retVal;
            char[] retTemp = new char[str.Length];
            char[] basicValue = new char[str.Length];
            basicValue = str.ToCharArray();

            int counter = 0;
            for (int i = str.Length - 1; i >= 0; i--)
            {
                retTemp[counter] = basicValue[i];
                counter++;
            }
            retVal = new string(retTemp);

            return retVal;
        }

        /// <summary>
        /// Check given string is Palindrome or NOT
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        public static bool IsPalindrome(string value)
        {
            bool bRet = false;

            if (value.Length == 1 || value.Length == 0)
            {
                bRet = true;

            }
            else
            {
                string firstPart;
                string secondPart;

                firstPart = value.Substring(0, value.Length / 2);

                secondPart = value.Substring((value.Length / 2), firstPart.Length);
                secondPart = revString(secondPart);

                if (firstPart == secondPart)
                    bRet = true;

            }

            return bRet;
        }
    }
}
