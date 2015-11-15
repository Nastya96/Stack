#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

using namespace std;

const int MAX_STACK_SIZE = 100000000;


template <class ValType>
class TStack
{
protected:

	
		ValType *pVector;
		int Size;       // размер стека
		int current;        // индекс последнего элемента
public:
		TStack(int s);	                          //конструктор инициализатор
		TStack(const TStack &v);                //конструктор копирования
		~TStack();                               //деструктор

		bool   IsFull(void);
        bool   IsEmpty(void);

		
		TStack& operator=(const TStack &v);     // присваивание
		
		void Push(const int i);              //добавить элемент
		ValType Del();                      // удалить элемент
		
				
		// ввод-вывод
  friend istream& operator>>(istream &in, TStack &v)
  {
    for (int i = 0; i < v.Size; i++)
      in >> v.pVector[i];
    return in;
  }
  friend ostream& operator<<(ostream &out, const TStack &v)
  {
    for (int i = 0; i < v.current+1; i++)
      out << v.pVector[i] << ' ';
    return out;
  }
};

template <class ValType>
TStack<ValType>::TStack(int s)//конструктор инициализатор
{
	if((s > MAX_STACK_SIZE) || (s < 0))
		throw ("out_of_range"); 
	else
	{
		current=-1;
		Size=s;
		pVector=new ValType[Size];
	}		
} 

template <class ValType> //конструктор копирования
TStack<ValType>::TStack(const TStack<ValType> &v)
{
	Size=v.Size;
	current=v.current;
	pVector=new ValType[Size];
	for (int i=0; i<current; i++)
		pVector[i]=v.pVector[i];
} 

template <class ValType> //деструктор
TStack<ValType>::~TStack()
{
	if(pVector!=NULL)
		delete []pVector;	
}

template <class ValType> // 
bool  TStack<ValType> :: IsFull(void) 
{return (current==Size -1);}
template <class ValType> // 
bool  TStack<ValType> :: IsEmpty(void)
{
if (current= -1) return true;
if (current != -1) return false;

}

template <class ValType> // присваивание
TStack<ValType>& TStack<ValType>::operator=(const TStack &v)
{
	if(this == &v)
		return *this;
	if(Size!=v.Size)
	{
		delete[]pVector;
		pVector=new ValType [v.Size];
		Size=v.Size;
	}
	for (int i=0; i<current; i++)
		pVector[i]=v.pVector[i];
	return *this;
} 

template <class ValType>
void TStack<ValType>:: Push(const int i)//добавить элемент
{
	if (current==Size -1)
		cout << "Full" << endl;
	else
	{
		current++;
		pVector[current]=i;
	}
}
template <class ValType>
ValType TStack<ValType>::Del() // удалить элемент
{
	if(current == (-1))
		cout << "Empty" << endl;
	else
	{
		ValType res;
		res=pVector[current];
		current--;
		return res;
	}
}
#endif
