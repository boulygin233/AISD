#include <iostream>
#include <cmath>

class Quaternion{
	private:
		double r = 0, i = 0, j = 0, k = 0;
	public:
		Quaternion (double a, double b, double c, double d);
		double Abs(Quaternion& z1) const{
			return sqrt(r*r + i*i + j*j + k*k);
		}
		double Re() const{
			return r;
		}
		double Imi() const{
			return i;
		}
		double Imj() const{
			return j;
		}
		double Imk() const{
			return k;
		}
};
Quaternion::Quaternion(double a, double b, double c, double d): r(a), i(b), j(c), k(d) {
}
std::ostream& operator << (std::ostream out, const Quaternion& z){
	/*bool first = 0;
	if (z.Re() != 0){
		std::cout<<z.Re();
		first = 1;
	}
	if (z.Imi() != 0){
		if (z.Imi() > 0){
			if (first){
				std::cout<<'+'<<z.Imi()<<'i';
			}
			else{
				std::cout<<z.Imi()<<'i';
				first = 1;
			}
		}
		else{
			std::cout<<z.Imi()<<'i';
			first = 1;
		}
	}	
	if (z.Imj() != 0){
		if (z.Imj() > 0){
			if (first){
				std::cout<<'+'<<z.Imj()<<'j';
			}
			else{
				std::cout<<z.Imj()<<'j';
				first = 1;
			}
		}
		else{
			std::cout<<z.Imj()<<'j';
			first = 1;
		}
	}	
	if (z.Imk() != 0){
		if (z.Imk() > 0){
			if (first){
				std::cout<<'+'<<z.Imk()<<'k';
			}
			else{
				std::cout<<z.Imk()<<'k';
				first = 1;
			}
		}
		else{
			std::cout<<z.Imk()<<'k';
			first = 1;
		}
	}	*/
	std::cout<<z.Re()<<'+'<<z.Imi()<<'+'<<z.Imj()<<'+'<<z.Imk();
	return out;	
}
int main(){
	double a, b , c ,d;
	std::cin>>a>>b>>c>>d;
	Quaternion z(a,b,c,d);
	std::cout<<z;
}
