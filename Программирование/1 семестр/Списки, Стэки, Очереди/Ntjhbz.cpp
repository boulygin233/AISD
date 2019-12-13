#include <iostream>
using namespace std;

//динамические структуры данных и адаптеры над ними

          |   Неотсортированный массив    |    отсортированный массив        |        Heap         |
вставка   |           O(1)                |              O(n)                |        O(logn)      |
максимум  |           O(n)                |              O(1)                |        O(logn)      |


//Односвязный список

 //  |_|  --->   |_| --->  |_|  ---> ...
   
	struct Node{
		[type] data;     //данные
		Node* Next;		//указатель на следущий элемент
   };
   
 //  Генерация односвязного списка List
	struct List {
		Node* Head;
		void add(int d);
		List();
		int Length;
	};
	
	List::List(){									//конструктор
		this -> Head = NULLPTR;
		this -> Length = 0;
	}
	
 	void List::add(int d){ 						   //метод  List'a - добавления элемента, обращение : List -> add(x)
   		Node* t = new Node;
   		t -> data = d;
   		t -> Next = this -> Head;
   		List -> Head = t;
   		this -> Length ++;
   		return t;
   }
   
 //двусвязный список

 //  |_|  <--->   |_| <--->  |_|  <---> ...
   
	struct Node{
		[type] data;     //данные
		Node* Next;		//указатель на следущий элемент
		Node* Prev;		//указатель на предыдущий
   };
   
 //  Генерация односвязного списка List
	struct List {
		Node* Head;
		Node* Tail;
		void add(int d);
		int Length;
		List();
	};
	
	List::List(){									//конструктор
		this -> Head = NULLPTR;
		this -> Tail = NULLPTR;
		this -> Length = 0;
	}
	
 	void List::add(int d){ 						   //метод  List'a - добавления элемента, обращение : List -> add(x)
   		Node* t = new Node;
   		t -> data = d;
   		t -> Next = this -> Head;
   		List -> Head = t;
   		this -> Length ++;
   		return t;
   }
   
   
   
   
   
   
   
//адаптеры
	/* 1. Стэк (Stack) (Первый вошел, последний вышел)
	   2. Очередь (Queue) (Первый вошел, первый вышел)
	   3. Дэк (Deque) (Двусторонняя очередь)
	   
	       
