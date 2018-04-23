
#include <iostream>
#include <assert.h>
using namespace std;

template <class T> 
class ArrayList
{
public:
	//Default constructor...
	ArrayList(int Size);

	//Inserting...
	void insert(const T&);
	void insert_beg(const T&);

	//Move & Return...
	bool getFirst(T&);
	bool getNext(T&);
	bool getPrevious(T&);
	bool getLast(T&);
	
	//Move the cursor...	
	void moveNext();
	void moveFirst();
	void movePrevious();
	void moveLast();

	//Retrive the current element...
	T getElement();
	//bool remove_item(T); 
	int  getIndex(T);
	
	//view all arraylist items...
	void print();
	//look for specific item in the list...	
	bool isExists(T);

	//
	int  getNumofElements();
	int  getPostion();
	bool isEmpty();
	void setPostion(int iPos);
	T getSum();
private:
	T* myArrayList;
	int numOfElem ;
	int cur_pos ;
	int max ;
};

template <class T>
void ArrayList<T>::setPostion(int iPos)
{
	this->cur_pos = iPos ;
}

template <class T>
T ArrayList<T>::getSum()
{
	T temp = 0 ;
	for(int i = 0 ;  i < numOfElem ; i++)
	{
		temp+= this->myArrayList[i];
	}
	return temp ;
}

template <class T>
ArrayList<T>::ArrayList(int Size)
{
	max = Size;

	//Set the size of the ArrayList to 0 initially
	numOfElem = 0 ;
	
	//Set the initial position of Movement Pointer to -1 . 
	cur_pos = -1 ;

	//
	myArrayList= new T[max];
}

template <class T>
void ArrayList<T>::insert(const T& elem)
{
	//Check is the size before inserting the new element will
	//cause overflow.
	assert(numOfElem < max);

	//cout << "Insert  " << elem << endl;
	this->myArrayList[numOfElem] = elem ;
	this->numOfElem++ ;
	this->cur_pos++ ;
}

template <class T>
void ArrayList<T>::insert_beg(const T& elem)
{
	//Check is the size before inserting the new element will
	//cause overflow.
	if(numOfElem < MAX)
		return ;

	if(getNumofElements() == 0)
	{
		insert(elem);
	}
	else
	{
		//cout << "***** Insert at the beginning " << elem << endl;
		//Shift Array Elements to Right
		//Set a[i] = a[i-1];
		for(int i = numOfElem ; i >= 0 ; i--)
		{
			myArrayList[i] = myArrayList[i-1];
		}

		//Set the Beginning of the ArrayList Equal to new Element
		myArrayList[0] = elem ;

		//Incrememt the size of actual elements occupied in the array
		numOfElem++ ;

		//Increment Current Element...
	//	this->cur_pos++ ;
	}
}

template <class T>
T ArrayList<T>::getElement()
{
	return myArrayList[cur_pos] ;
}

template <class T>
bool ArrayList<T>::getPrevious(T& elem)
{
	//Check Current Position am i not at the beginning -> 0
	assert(cur_pos >= 0);

	//Reach to the begining of the ArrayList -> No Next
	if(cur_pos <= 0 )
		return false ;

	cur_pos--;
	elem = myArrayList[cur_pos];
	return true ;
}

template <class T>
void ArrayList<T>::moveNext()
{
	//Check Current Position am i at the beginning -> 0 Or After the first 
	assert(cur_pos >= 0);

	//Reach to the end of the ArrayList -> No Next
	if(cur_pos >= numOfElem - 1)
		return ;

	cur_pos++;
}

template <class T>
void ArrayList<T>::moveFirst()
{
	//No Elements in the ArrayList.
	if(numOfElem == 0 )
		return ;

	cur_pos = 0 ;
}

template <class T>
void ArrayList<T>::moveLast()
{
	//Check Current Position am i not at the beginning -> 0
	assert(this->getNumofElements() > 0);
	cur_pos = this->getNumofElements() - 1 ;
}

template <class T>
void ArrayList<T>::movePrevious()
{
	//Check Current Position am i not at the beginning -> 0
	assert(cur_pos >= 0);

	//Reach to the begining of the ArrayList -> No Next
	if(cur_pos <= 0 )
		return  ;

	cur_pos--;
}

template <class T>
bool ArrayList<T>::getLast(T& elem)
{
	//Check Current Position am i not at the beginning -> 0
	assert(this->getNumofElements() > 0);

	cur_pos = this->getNumofElements() - 1 ;
	elem = myArrayList[cur_pos];
	return true ;
}
template <class T>
bool ArrayList<T>::getNext(T& elem)
{
	//Check Current Position am i at the beginning -> 0
	//Or
	//After the first 
	assert(cur_pos >= 0);

	//Reach to the end of the ArrayList -> No Next
	if(cur_pos >= numOfElem - 1)
		return false ;


	cur_pos++;
	elem = myArrayList[cur_pos];
	return true ;
}

template <class T>
bool ArrayList<T>::getFirst(T& elem)
{
	//No Elements in the ArrayList.
	if(numOfElem == 0 )
		return false ;

	cur_pos = 0 ;
	elem = myArrayList[cur_pos] ;
	return true ;
}

template <class T>
void ArrayList<T>::print()
{
	if(! isEmpty())
	{
		//Store Original Position in the ArrayList.
		int Ori_Pos = getPostion();
		//cout << "ArrayList Traverse..." << endl; 
		T i ;
		bool result= getFirst(i);
		cout << i << " " ;
	
		while(getNext(i))
		{
			cout << i << " " ;
		}
		cout << endl;
		//Return the Original Position to it's Actual Position
		cur_pos = Ori_Pos ;
	}
}
template <class T>
int ArrayList<T>::getNumofElements()
{
	return numOfElem ;
}
template <class T>
int ArrayList<T>::getPostion()
{
	if(getNumofElements())
		return cur_pos;
	return -1 ;
}

template <class T>
bool ArrayList<T>::isExists(T Num)
{
	bool isExists = false ;
	int pos = getPostion();

	if(getNumofElements())
	{
		T var = 0 ; 
		bool ret = getFirst(var);

		if(var == Num)
		{
			isExists = true ;
		}
		else
		{
			while(getNext(var))
			{
				if(	var == Num )
				{
					isExists = true;
					break;
				}
			}
		}
	}

	cur_pos = pos ;
	return isExists;
}

template <class T>
bool ArrayList<T>::isEmpty()
{
	if(getNumofElements())
		return false;
	return true ;
}

template <class T>
int ArrayList<T>::getIndex(T Num)
{
	int item_pos = -1 ;

	if(isExists(Num))
	{
		//Original Pos in the ArrayList
		int  Ori_pos = getPostion() ;
		T  var = 0 ;
		bool ret = getFirst(var) ;

		if(var == Num)
		{
			item_pos = cur_pos ;
			cur_pos = Ori_pos ;
		}
		else
		{
			while(getNext(var))
			{
				if(	var == Num )
				{
					item_pos = cur_pos ;
					cur_pos = Ori_pos ;
					break;
				}
			}
		}
	}
	return item_pos ;
}

