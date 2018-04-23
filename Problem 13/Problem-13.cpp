#include <iostream>
#include <string.h>
#include <stdio.h>
#include <limits.h>

using namespace std;

#define MAX_ARRAY_SIZE	4096
/*
Problem 13
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
37107287533902102798797998220837590246510135740250
46376937677490009712648124896970078050417018260538
74324986199524741059474233309513058123726617309629
91942213363574161572522430563301811072406154908250
23067588207539346171171980310421047513778063246676
89261670696623633820136378418383684178734361726757
28112879812849979408065481931592621691275889832738
44274228917432520321923589422876796487670272189318
47451445736001306439091167216856844588711603153276
70386486105843025439939619828917593665686757934951
62176457141856560629502157223196586755079324193331
64906352462741904929101432445813822663347944758178
92575867718337217661963751590579239728245598838407
58203565325359399008402633568948830189458628227828
80181199384826282014278194139940567587151170094390
35398664372827112653829987240784473053190104293586
86515506006295864861532075273371959191420517255829
71693888707715466499115593487603532921714970056938
54370070576826684624621495650076471787294438377604
53282654108756828443191190634694037855217779295145
36123272525000296071075082563815656710885258350721
45876576172410976447339110607218265236877223636045
17423706905851860660448207621209813287860733969412
81142660418086830619328460811191061556940512689692
51934325451728388641918047049293215058642563049483
62467221648435076201727918039944693004732956340691
15732444386908125794514089057706229429197107928209
55037687525678773091862540744969844508330393682126
18336384825330154686196124348767681297534375946515
80386287592878490201521685554828717201219257766954
78182833757993103614740356856449095527097864797581
16726320100436897842553539920931837441497806860984
48403098129077791799088218795327364475675590848030
87086987551392711854517078544161852424320693150332
59959406895756536782107074926966537676326235447210
69793950679652694742597709739166693763042633987085
41052684708299085211399427365734116182760315001271
65378607361501080857009149939512557028198746004375
35829035317434717326932123578154982629742552737307
94953759765105305946966067683156574377167401875275
88902802571733229619176668713819931811048770190271
25267680276078003013678680992525463401061632866526
36270218540497705585629946580636237993140746255962
24074486908231174977792365466257246923322810917141
91430288197103288597806669760892938638285025333403
34413065578016127815921815005561868836468420090470
23053081172816430487623791969842487255036638784583
11487696932154902810424020138335124462181441773470
63783299490636259666498587618221225225512486764533
67720186971698544312419572409913959008952310058822
95548255300263520781532296796249481641953868218774
76085327132285723110424803456124867697064507995236
37774242535411291684276865538926205024910326572967
23701913275725675285653248258265463092207058596522
29798860272258331913126375147341994889534765745501
18495701454879288984856827726077713721403798879715
38298203783031473527721580348144513491373226651381
34829543829199918180278916522431027392251122869539
40957953066405232632538044100059654939159879593635
29746152185502371307642255121183693803580388584903
41698116222072977186158236678424689157993532961922
62467957194401269043877107275048102390895523597457
23189706772547915061505504953922979530901129967519
86188088225875314529584099251203829009407770775672
11306739708304724483816533873502340845647058077308
82959174767140363198008187129011875491310547126581
97623331044818386269515456334926366572897563400500
42846280183517070527831839425882145521227251250327
55121603546981200581762165212827652751691296897789
32238195734329339946437501907836945765883352399886
75506164965184775180738168837861091527357929701337
62177842752192623401942399639168044983993173312731
32924185707147349566916674687634660915035914677504
99518671430235219628894890102423325116913619626622
73267460800591547471830798392868535206946944540724
76841822524674417161514036427982273348055556214818
97142617910342598647204516893989422179826088076852
87783646182799346313767754307809363333018982642090
10848802521674670883215120185883543223812876952786
71329612474782464538636993009049310363619763878039
62184073572399794223406235393808339651327408011116
66627891981488087797941876876144230030984490851411
60661826293682836764744779239180335110989069790714
85786944089552990653640447425576083659976645795096
66024396409905389607120198219976047599490197230297
64913982680032973156037120041377903785566085089252
16730939319872750275468906903707539413042652315011
94809377245048795150954100921645863754710598436791
78639167021187492431995700641917969777599028300699
15368713711936614952811305876380278410754449733078
40789923115535562561142322423255033685442488917353
44889911501440648020369068063960672322193204149535
41503128880339536053299340368006977710650566631954
81234880673210146739058568557934581403627822703280
82616570773948327592232845941706525094512325230608
22918802058777319719839450180888072429661980811197
77158542502016545090413245809786882778948721859617
72107838435069186155435662884062257473692284509516
20849603980134001723930671666823555245252804609722
53503534226472524250874054075591789781264330331690
*/

class BigNumber
{
private:
	unsigned long int iInitalValue ;
	char* strValue;

	char* subString(char* string,int start,int end)
	{
		char* szBuff = new char[end-start];
		memset(szBuff,'\0',end-start);

		int iCounter = 0 ;

		for(int i = start ; i <= end ; i++)
		{
			szBuff[iCounter] = string[i] ;
			iCounter++ ;
		}
		return szBuff ;
	}
	
	
	int IntChar(char* string,int index)
	{
		short i = (char) string[index];

		if( i == 48 )
			return 0;
		else if( i == 49 )
			return 1 ;
		else if( i == 50 )
			return 2 ;
		else if( i == 51 )
			return 3 ;
		else if( i == 52 )
			return 4 ;
		else if( i == 53 )
			return 5 ;
		else if( i == 54 )
			return 6 ;
		else if( i == 55 )
			return 7 ;
		else if( i == 56 )
			return 8 ;	
		else if( i == 57 )
			return 9 ;
		else
			return 0 ;
	}

	char* ReverseStr(char* szString)
	{
		int len = strlen(szString);
		int iCount = 0 ;
		char* szRev = new char[len];

		memset(szRev,'\0',len);
		
		for(int i = len-1 ; i >= 0 ; i--)
		{
			szRev[iCount] = szString[i]; 
			iCount++ ;
		}

		return szRev ;
	}

	bool exceedRange(unsigned long int n)
	{
		return ( n > 2147483647 ) ? 1 : 0 ;
	}

	char* convertIntToStr(int n)
	{
		char* szBuffer = new char[10];
		//Free ~~~~.....
		memset(szBuffer,'\0',10);
		//Convert the given number to char style with DECIMAL notation.
		itoa(n,szBuffer,10);
		//return the bufffer.
		return szBuffer ;
	}

	int lenFunc(unsigned long int n)
	{
		//MAX UNSIGNED LONG INT		4294967295 10 Bytes, 10 Characters.
		if(n > 2147483647 )
		{
			cout << "ERROR, THE NUMBER EXCEEDING THE INITIAL LIMITS _ LEN FUNC";
			return 0;
		}
		
		char* szBuff = new char[10];
		//Free...
		memset(szBuff,'\0',10);
		//Convert the given number to char style with DECIMAL notation.
		itoa(n,szBuff,10);

		int len = 0 ;
		char tmp = '\0'; 
		tmp = szBuff[0];
		int i = 0 ;
		while( tmp != '\0')
		{
			tmp = szBuff[i];
			len++;
			i++ ;
		}

		return len-1 ;
	}


public:
	void toString()
	{
		if( strValue == NULL)
		{
			cout << "ERROR, NO ASSIGNED VALUE... _ toStr FUNC" << endl;
			return ; 
		}

		char x= strValue[0];
		int iCounter = 0; 

		while(x != '\0')
		{
			if(isdigit(x))
			{
				cout << x ; 
			}
			
			iCounter++;
			x = strValue[iCounter];
		}
		cout << "\n" ;
	}

	BigNumber()
	{
		iInitalValue = 0 ;
		//Allocate...
		strValue = new char[MAX_ARRAY_SIZE];
		//Free ~~~~.....
		memset(strValue,'\0',MAX_ARRAY_SIZE);
	}

	BigNumber(char* szNumber)
	{
		//Allocate...
		strValue = new char[MAX_ARRAY_SIZE];
		//Free ~~~~.....
		memset(strValue,'\0',MAX_ARRAY_SIZE);
		//Copy
		strcpy(strValue,szNumber);
	}

	BigNumber(int iValue)
	{
		//MAX UNSIGNED LONG INT		4294967295 10 Bytes, 10 Characters.
		if(iValue > 2147483647 )
		{
			cout << "ERROR, THE NUMBER EXCEEDING THE INITIAL LIMITS _ NON-DEFAULT CONS FUNC";
			return;
		}

		//Allocate...
		strValue = new char[MAX_ARRAY_SIZE];
		//Free ~~~~.....
		memset(strValue,'\0',MAX_ARRAY_SIZE);
		//Convert the given number to char style with DECIMAL notation.
		itoa(iValue,strValue,10);
	}


	//In Case: Default Constructor Has Called...
	void Insert(int initNumber)
	{
		//MAX UNSIGNED LONG INT		4294967295 10 Bytes, 10 Characters.
		if(initNumber > 2147483647 )
		{
			cout << "ERROR, THE NUMBER EXCEEDING THE INITIAL LIMITS _ INSERT FUNC";
			return ;
		}
		else
		{
			//In Case : there was a value...
			if( strValue != NULL )
			{
				memset(strValue,'\0',MAX_ARRAY_SIZE);
			}
			//Convert the given number to char style with DECIMAL notation.
			itoa(initNumber,strValue,10);
		}
	}
	
	//In Case: Default Constructor Has Called...
	void Insert(char* szBuff)
	{
		//MAX UNSIGNED LONG INT		4294967295 10 Bytes, 10 Characters.
		if(szBuff == NULL )
		{
			cout << "ERROR, NULL POINTER _ INSERT FUNC";
			return ;
		}
		else
		{
			//In Case : there was a value...
			memcpy(strValue,szBuff,stringLength(szBuff)+1);
		}
	}
	//Return Precisely the length of given string szBuff
	int stringLength(char* szBuff)
	{
		int iLen = 0 ;
		int i = 0 ; 
		char tmp = szBuff[i] ; 

		while(isdigit(tmp))
		{
			iLen++ ;
			tmp = szBuff[i] ; 
			i++;
		}

		--iLen ; 
		return iLen ;

	}

	void add(unsigned long int num)
	{
		if(num > 2147483647 )
		{
			cout << "ERROR, THE NUMBER EXCEEDING THE INITIAL LIMITS _ ADD FUNC";
			return ;
		}
		//Carried value len...
		int ilenOld = stringLength(strValue);//strlen(strValue);

		//Result....
		char* szFinalRes = new char[MAX_ARRAY_SIZE];
		memset(szFinalRes,'\0',MAX_ARRAY_SIZE);

		//Copy the old value into temp...
		char* szBuffOldNum = new char[MAX_ARRAY_SIZE];
		memset(szBuffOldNum,'\0',MAX_ARRAY_SIZE);
		memcpy(szBuffOldNum,strValue,ilenOld+1);
		
		//----------------------------------------------------
		//Get the length of Given number...
		int ilenGiven = this->lenFunc(num);
		
		//----------------------------------------------------
		//Convert Given Int to String...
		char* szGivenNum = new char[ilenGiven+1];
		memset(szGivenNum,'\0',ilenGiven+1);
		itoa(num,szGivenNum,10); 
		//----------------------------------------------------

		int iresult = 0 ;				//Operation Result....
		int iOldRem = 0, iRem = 0 ;		//Reminder...

		//Decrement it to start specificly from the last index
		ilenGiven--;
		ilenOld--;

		int i = 0 ;
		if(ilenGiven > ilenOld)
			i = ilenGiven ;
		else
			i = ilenOld ;

		for(  ; i >= 0 ; i--)
		{
			if(iRem)
			{
				iresult =  this->IntChar(szBuffOldNum,ilenOld) + this->IntChar(szGivenNum,i) + iRem ;
				iRem = 0 ; 
			}
			else
			{
				iresult =  this->IntChar(szBuffOldNum,ilenOld) + this->IntChar(szGivenNum,i)  ;
			}
			
			
			char szTmpBuf[2] ;
			memset(szTmpBuf,'\0',2);

			if(iresult > 9 )
			{
				iRem = iresult/10 ;
				iOldRem = iresult%10 ;
				itoa(iOldRem,szTmpBuf,10);	
			}
			else
			{
				itoa(iresult,szTmpBuf,10);
			}

			strcat(szFinalRes,szTmpBuf);
			
			if( i == 0 && iRem != 0 )
			{
				memset(szTmpBuf,'\0',2);
				itoa(iRem,szTmpBuf,10);	
				strcat(szFinalRes,szTmpBuf);
			}

			ilenOld--;
		}

		
		strValue = ReverseStr(szFinalRes);
	}

	void add(char* szBuff)
	{
		if(szBuff == NULL )
		{
			cout << "ERROR, NULL POINTER _ ADD FUNC";
			return ;
		}
		//Carried value len...
		int ilenOld = stringLength(strValue);

		//Result....
		char* szFinalRes = new char[MAX_ARRAY_SIZE];
		memset(szFinalRes,'\0',MAX_ARRAY_SIZE);

		//Copy the old value into temp...
		char* szBuffOldNum = new char[MAX_ARRAY_SIZE];
		memset(szBuffOldNum,'\0',MAX_ARRAY_SIZE);
		//I added 1 for '\0' the termination character...
		memcpy(szBuffOldNum,strValue,ilenOld+1);
		
		//----------------------------------------------------
		//Get the length of Given Buffer...
		int ilenGiven = stringLength(szBuff);
		//----------------------------------------------------

		int iresult = 0 ;				//Operation Result....
		int iOldRem = 0, iRem = 0 ;		//Reminder...

		//Decrement it to start specificly from the last index
		ilenGiven--;
		ilenOld--;

		int i = 0 ;
		if(ilenGiven > ilenOld)
			i = ilenGiven ;
		else
			i = ilenOld ;

		for(  ; i >= 0 ; i--)
		{
			if(iRem)
			{
				iresult =  this->IntChar(szBuffOldNum,ilenOld) + this->IntChar(szBuff,ilenGiven) + iRem ;
				iRem = 0 ; 
			}
			else
			{
				iresult =  this->IntChar(szBuffOldNum,ilenOld) + this->IntChar(szBuff,ilenGiven)  ;
			}
			
			
			char szTmpBuf[2] ;
			memset(szTmpBuf,'\0',2);

			if(iresult > 9 )
			{
				iRem = iresult/10 ;
				iOldRem = iresult%10 ;
				itoa(iOldRem,szTmpBuf,10);	
			}
			else
			{
				itoa(iresult,szTmpBuf,10);
			}

			strcat(szFinalRes,szTmpBuf);
			
			if( i == 0 && iRem != 0 )
			{
				memset(szTmpBuf,'\0',2);
				itoa(iRem,szTmpBuf,10);	
				strcat(szFinalRes,szTmpBuf);
			}

			ilenOld--;
			ilenGiven--;
		}

		
		strValue = ReverseStr(szFinalRes);
	}

	void multiply(unsigned long int num = 1)
	{
		if(num > 2147483647 )
		{
			cout << "ERROR, THE NUMBER EXCEEDING THE INITIAL LIMITS _ ADD FUNC";
			return ;
		}
		//Carried value len...
		int ilenOld = stringLength(strValue);//strlen(strValue);

		//Result....
		char* szFinalRes = new char[MAX_ARRAY_SIZE];
		memset(szFinalRes,'\0',MAX_ARRAY_SIZE);

		//Copy the old value into temp...
		char* szBuffOldNum = new char[MAX_ARRAY_SIZE];
		memset(szBuffOldNum,'\0',MAX_ARRAY_SIZE);
		memcpy(szBuffOldNum,strValue,ilenOld+1);
		
		//----------------------------------------------------
		//Get the length of Given number...
		int ilenGiven = this->lenFunc(num);
		
		//----------------------------------------------------
		//Convert Given Int to String...
		char* szGivenNum = new char[ilenGiven+1];
		memset(szGivenNum,'\0',ilenGiven+1);
		itoa(num,szGivenNum,10); 
		//----------------------------------------------------

		int iresult = 0 ;				//Operation Result....
		int iOldRem = 0, iRem = 0 ;		//Reminder...

		//Decrement it to start specificly from the last index
		ilenGiven--;
		ilenOld--;

		int i = 0 ;
		int j = 0 ;

		if(ilenGiven > ilenOld)
		{
			i = ilenGiven ;
			j = ilenOld ;
		}
		else
		{
			i = ilenOld ;
			j = ilenGiven ;
		}
		
		//char* sz
		for(  ; i >= 0 ; i--)
		{
			for( ; j >=0 ; j--)
			{
				if(iRem)
				{
					iresult =  this->IntChar(szBuffOldNum,ilenOld) * this->IntChar(szGivenNum,j) + iRem ;
					iRem = 0 ; 
				}
				else
				{
					iresult =  this->IntChar(szBuffOldNum,ilenOld) * this->IntChar(szGivenNum,j)  ;
				}
			
				
				char szTmpBuf[2] ;
				memset(szTmpBuf,'\0',2);

				if(iresult > 9 )
				{
					iRem = iresult/10 ;
					iOldRem = iresult%10 ;
					itoa(iOldRem,szTmpBuf,10);	
				}
				else
				{
					itoa(iresult,szTmpBuf,10);
				}

				strcat(szFinalRes,szTmpBuf);
				
				if( i == 0 && iRem != 0 )
				{
					memset(szTmpBuf,'\0',2);
					itoa(iRem,szTmpBuf,10);	
					strcat(szFinalRes,szTmpBuf);
				}

				ilenOld--;
			}

		}

		
		strValue = ReverseStr(szFinalRes);
	}
};



int main()
{
	BigNumber* cls = new BigNumber("37107287533902102798797998220837590246510135740250");
	cls->add("46376937677490009712648124896970078050417018260538");
	cls->add("74324986199524741059474233309513058123726617309629");
	cls->add("91942213363574161572522430563301811072406154908250");
	cls->add("23067588207539346171171980310421047513778063246676");
	cls->add("89261670696623633820136378418383684178734361726757");
	cls->add("28112879812849979408065481931592621691275889832738");
	cls->add("44274228917432520321923589422876796487670272189318");
	cls->add("47451445736001306439091167216856844588711603153276");
	cls->add("70386486105843025439939619828917593665686757934951");
	cls->add("62176457141856560629502157223196586755079324193331");
	cls->add("64906352462741904929101432445813822663347944758178");
	cls->add("92575867718337217661963751590579239728245598838407");
	cls->add("58203565325359399008402633568948830189458628227828");
	cls->add("80181199384826282014278194139940567587151170094390");
	cls->add("35398664372827112653829987240784473053190104293586");
	cls->add("86515506006295864861532075273371959191420517255829");
	cls->add("71693888707715466499115593487603532921714970056938");
	cls->add("54370070576826684624621495650076471787294438377604");
	cls->add("53282654108756828443191190634694037855217779295145");
	cls->add("36123272525000296071075082563815656710885258350721");
	cls->add("45876576172410976447339110607218265236877223636045");
	cls->add("17423706905851860660448207621209813287860733969412");
	cls->add("81142660418086830619328460811191061556940512689692");
	cls->add("51934325451728388641918047049293215058642563049483");
	cls->add("62467221648435076201727918039944693004732956340691");
	cls->add("15732444386908125794514089057706229429197107928209");
	cls->add("55037687525678773091862540744969844508330393682126");
	cls->add("18336384825330154686196124348767681297534375946515");
	cls->add("80386287592878490201521685554828717201219257766954");
	cls->add("78182833757993103614740356856449095527097864797581");
	cls->add("16726320100436897842553539920931837441497806860984");
	cls->add("48403098129077791799088218795327364475675590848030");
	cls->add("87086987551392711854517078544161852424320693150332");
	cls->add("59959406895756536782107074926966537676326235447210");
	cls->add("69793950679652694742597709739166693763042633987085");
	cls->add("41052684708299085211399427365734116182760315001271");
	cls->add("65378607361501080857009149939512557028198746004375");
	cls->add("35829035317434717326932123578154982629742552737307");
	cls->add("94953759765105305946966067683156574377167401875275");
	cls->add("88902802571733229619176668713819931811048770190271");
	cls->add("25267680276078003013678680992525463401061632866526");
	cls->add("36270218540497705585629946580636237993140746255962");
	cls->add("24074486908231174977792365466257246923322810917141");
	cls->add("91430288197103288597806669760892938638285025333403");
	cls->add("34413065578016127815921815005561868836468420090470");
	cls->add("23053081172816430487623791969842487255036638784583");
	cls->add("11487696932154902810424020138335124462181441773470");
	cls->add("63783299490636259666498587618221225225512486764533");
	cls->add("67720186971698544312419572409913959008952310058822");
	cls->add("95548255300263520781532296796249481641953868218774");
	cls->add("76085327132285723110424803456124867697064507995236");
	cls->add("37774242535411291684276865538926205024910326572967");
	cls->add("23701913275725675285653248258265463092207058596522");
	cls->add("29798860272258331913126375147341994889534765745501");
	cls->add("18495701454879288984856827726077713721403798879715");
	cls->add("38298203783031473527721580348144513491373226651381");
	cls->add("34829543829199918180278916522431027392251122869539");
	cls->add("40957953066405232632538044100059654939159879593635");
	cls->add("29746152185502371307642255121183693803580388584903");
	cls->add("41698116222072977186158236678424689157993532961922");
	cls->add("62467957194401269043877107275048102390895523597457");
	cls->add("23189706772547915061505504953922979530901129967519");
	cls->add("86188088225875314529584099251203829009407770775672");
	cls->add("11306739708304724483816533873502340845647058077308");
	cls->add("82959174767140363198008187129011875491310547126581");
	cls->add("97623331044818386269515456334926366572897563400500");
	cls->add("42846280183517070527831839425882145521227251250327");
	cls->add("55121603546981200581762165212827652751691296897789");
	cls->add("32238195734329339946437501907836945765883352399886");
	cls->add("75506164965184775180738168837861091527357929701337");
	cls->add("62177842752192623401942399639168044983993173312731");
	cls->add("32924185707147349566916674687634660915035914677504");
	cls->add("99518671430235219628894890102423325116913619626622");
	cls->add("73267460800591547471830798392868535206946944540724");
	cls->add("76841822524674417161514036427982273348055556214818");
	cls->add("97142617910342598647204516893989422179826088076852");
	cls->add("87783646182799346313767754307809363333018982642090");
	cls->add("10848802521674670883215120185883543223812876952786");
	cls->add("71329612474782464538636993009049310363619763878039");
	cls->add("62184073572399794223406235393808339651327408011116");
	cls->add("66627891981488087797941876876144230030984490851411");
	cls->add("60661826293682836764744779239180335110989069790714");
	cls->add("85786944089552990653640447425576083659976645795096");
	cls->add("66024396409905389607120198219976047599490197230297");
	cls->add("64913982680032973156037120041377903785566085089252");
	cls->add("16730939319872750275468906903707539413042652315011");
	cls->add("94809377245048795150954100921645863754710598436791");
	cls->add("78639167021187492431995700641917969777599028300699");
	cls->add("15368713711936614952811305876380278410754449733078");
	cls->add("40789923115535562561142322423255033685442488917353");
	cls->add("44889911501440648020369068063960672322193204149535");
	cls->add("41503128880339536053299340368006977710650566631954");
	cls->add("81234880673210146739058568557934581403627822703280");
	cls->add("82616570773948327592232845941706525094512325230608");
	cls->add("22918802058777319719839450180888072429661980811197");
	cls->add("77158542502016545090413245809786882778948721859617");
	cls->add("72107838435069186155435662884062257473692284509516");
	cls->add("20849603980134001723930671666823555245252804609722");
	cls->add("53503534226472524250874054075591789781264330331690");


	cls->toString();
	int i = 0;
	cin >> i ; 
	return 0 ;
}
/*

  	void multiply(unsigned long int num)
	{
		if(num > 2147483647 )
		{
			cout << "ERROR, THE NUMBER EXCEEDING THE INITIAL LIMITS _ ADD FUNC";
			return ;
		}
		//Carried value len...
		int ilenOld = stringLength(strValue);//strlen(strValue);

		//Result....
		char* szFinalRes = new char[MAX_ARRAY_SIZE];
		memset(szFinalRes,'\0',MAX_ARRAY_SIZE);

		//Copy the old value into temp...
		char* szBuffOldNum = new char[MAX_ARRAY_SIZE];
		memset(szBuffOldNum,'\0',MAX_ARRAY_SIZE);
		memcpy(szBuffOldNum,strValue,ilenOld+1);
		
		//----------------------------------------------------
		//Get the length of Given number...
		int ilenGiven = this->lenFunc(num);
		
		//----------------------------------------------------
		//Convert Given Int to String...
		char* szGivenNum = new char[ilenGiven+1];
		memset(szGivenNum,'\0',ilenGiven+1);
		itoa(num,szGivenNum,10); 
		//----------------------------------------------------

		int iresult = 0 ;				//Operation Result....
		int iOldRem = 0, iRem = 0 ;		//Reminder...

		//Decrement it to start specificly from the last index
		ilenGiven--;
		ilenOld--;

		int i = 0 ;

		if( ilenGiven > ilenOld )
			i = ilenGiven ;
		else
			i = ilenOld ;

		for(  ; i >= 0 ; i--)
		{
			if(iRem)
			{
				iresult =  this->IntChar(szBuffOldNum,ilenOld) * this->IntChar(szGivenNum,i) + iRem ;
				iRem = 0 ; 
			}
			else
			{
				iresult =  this->IntChar(szBuffOldNum,ilenOld) * this->IntChar(szGivenNum,i)  ;
			}
			
			
			char szTmpBuf[2] ;
			memset(szTmpBuf,'\0',2);

			if(iresult > 9 )
			{
				iRem = iresult/10 ;
				iOldRem = iresult%10 ;
				itoa(iOldRem,szTmpBuf,10);	
			}
			else
			{
				itoa(iresult,szTmpBuf,10);
			}

			strcat(szFinalRes,szTmpBuf);
			
			if( i == 0 && iRem != 0 )
			{
				memset(szTmpBuf,'\0',2);
				itoa(iRem,szTmpBuf,10);	
				strcat(szFinalRes,szTmpBuf);
			}

			ilenOld--;
		}

		
		strValue = ReverseStr(szFinalRes);
	}


char* regularSumForMulti(char* szFirstNum,char* szSecNum)
	{
		int iLenFirst = 0 , iLenSec = 0 ;
		char* szResBuff = new char[4096];
		memset(szResBuff,'\0',4096);
		
		
		iLenFirst = stringLength(szFirstNum);
		iLenSec   = stringLength(szSecNum);
		


		return szResBuff;
	}


*/
