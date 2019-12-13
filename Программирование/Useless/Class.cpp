#include <iostream>
#include <cmath>

class Complex{  //объявление класса
	private:    //приватные данные и методы (программа к ним не может обращаться)
		double Real, Imagine;
	
	public:		//публичные данные и методы (программа к ним может обращаться)
		Complex (double a, double b); //конструктор класса
		double Re() const;
		double Im() const;
		double abs() const;
		
};
Complex::Complex(double a, double b){
	x = a;
	y = b;
}
/*Complex::Complex(double a, double b): x(a), y(b) {
} почти тоже самое, что предыдущая функция (но не совсем). используется чаще*/
double Complex::abs() const{
	return sqrt(Real*Real + Imagine*Imagine);
}

double Complex::Re() const/*это const не меняет значкения полей*/{
	return Real;
}

double Complex::Im() const{
	return Imagine;
}

Complex operator - (const Complex& z){  //перегрузка унарного минуса
	return Complex (- z.Re(), -z.Im());
} 

Complex operator + (const Complex& z1, const Complex& z2){  //перегрузка бинарного плюса
	return Complex (z1.Re() + z2.Re(), z1.Im() + z2.Im());
}

std::ostream& operator << (std::ostream out, const Complex& z){
	std::cout<<z.Re()<<'+'<<z.Im()<<'i';
	return out;	
}


int main(){
	Complex y = Complex(5, 3);
	Complex z (3, 2);
}
