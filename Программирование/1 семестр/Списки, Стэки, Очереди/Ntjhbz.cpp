#include <iostream>
using namespace std;

//������������ ��������� ������ � �������� ��� ����

          |   ����������������� ������    |    ��������������� ������        |        Heap         |
�������   |           O(1)                |              O(n)                |        O(logn)      |
��������  |           O(n)                |              O(1)                |        O(logn)      |


//����������� ������

 //  |_|  --->   |_| --->  |_|  ---> ...
   
	struct Node{
		[type] data;     //������
		Node* Next;		//��������� �� �������� �������
   };
   
 //  ��������� ������������ ������ List
	struct List {
		Node* Head;
		void add(int d);
		List();
		int Length;
	};
	
	List::List(){									//�����������
		this -> Head = NULLPTR;
		this -> Length = 0;
	}
	
 	void List::add(int d){ 						   //�����  List'a - ���������� ��������, ��������� : List -> add(x)
   		Node* t = new Node;
   		t -> data = d;
   		t -> Next = this -> Head;
   		List -> Head = t;
   		this -> Length ++;
   		return t;
   }
   
 //���������� ������

 //  |_|  <--->   |_| <--->  |_|  <---> ...
   
	struct Node{
		[type] data;     //������
		Node* Next;		//��������� �� �������� �������
		Node* Prev;		//��������� �� ����������
   };
   
 //  ��������� ������������ ������ List
	struct List {
		Node* Head;
		Node* Tail;
		void add(int d);
		int Length;
		List();
	};
	
	List::List(){									//�����������
		this -> Head = NULLPTR;
		this -> Tail = NULLPTR;
		this -> Length = 0;
	}
	
 	void List::add(int d){ 						   //�����  List'a - ���������� ��������, ��������� : List -> add(x)
   		Node* t = new Node;
   		t -> data = d;
   		t -> Next = this -> Head;
   		List -> Head = t;
   		this -> Length ++;
   		return t;
   }
   
   
   
   
   
   
   
//��������
	/* 1. ���� (Stack) (������ �����, ��������� �����)
	   2. ������� (Queue) (������ �����, ������ �����)
	   3. ��� (Deque) (������������ �������)
	   
	       
