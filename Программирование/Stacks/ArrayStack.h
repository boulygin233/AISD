class ArrayStack{
	private:
		int i = 0;
		int *Buffer;
	public:
		ArrayStack(){
			Buffer = new int [10000];
		}
		void push(int Num){
			Buffer[i] = Num;
			++i;
		}
		int pop(){
			--i;
			return Buffer[i + 1];
		}
		int size(){
			return i;
		}
		void clear(){
			i = 0;
		}
};


