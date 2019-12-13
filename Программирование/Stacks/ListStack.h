#include <iostream>

struct List{
	int a;
	List *Prev;
};

class ListStack{
	private:
		int i = 0;
		List *Last;
	public:
		ListStack(){
			Last = new List;
			Last->a = 0;
			Last->Prev = 0;
		}
		void push(int Num){
			List *pv = new List;
			++i;
			Last->a = Num;
			pv->Prev = Last;
			pv->a = 0;
			Last = pv;
		}
		int pop(){
			if (i != 0){
				List *pv = Last;
				int x = Last->a;
				--i;
				Last = pv->Prev;
				delete pv;
				return x;
			}
			else{
				std::cout<<"Error";
				return;
			}
		}
		int size(){
			return i;
		}
		void clear(){
			while (Last->Prev != 0){
				List *pv = Last;
				Last = pv->Prev;
				--i;
				delete pv;
			}
		}
};
