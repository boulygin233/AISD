#include <iostream>
#include <cmath>

class Complex{  //���������� ������
	private:    //��������� ������ � ������ (��������� � ��� �� ����� ����������)
		double Real, Imagine;
	
	public:		//��������� ������ � ������ (��������� � ��� ����� ����������)
		Complex (double a, double b); //����������� ������
		double Re() const;
		double Im() const;
		double abs() const;
		
};
Complex::Complex(double a, double b){
	x = a;
	y = b;
}
/*Complex::Complex(double a, double b): x(a), y(b) {
} ����� ���� �����, ��� ���������� ������� (�� �� ������). ������������ ����*/
double Complex::abs() const{
	return sqrt(Real*Real + Imagine*Imagine);
}

double Complex::Re() const/*��� const �� ������ ��������� �����*/{
	return Real;
}

double Complex::Im() const{
	return Imagine;
}

Complex operator - (const Complex& z){  //���������� �������� ������
	return Complex (- z.Re(), -z.Im());
} 

Complex operator + (const Complex& z1, const Complex& z2){  //���������� ��������� �����
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
