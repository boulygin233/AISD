#include <iostream>
#include <cmath>

class Quaternion{
	private:
		double r = 0, i = 0, j = 0, k = 0;
	public:
		Quaternion (double a, double b, double c, double d);
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
Quaternion operator - (const Quaternion& z){
	return Quaternion (-z.Re(), -z.Imi(), -z.Imj(), -z.Imk());
} 

Quaternion operator + (const Quaternion& z1, const Quaternion& z2){
	return Quaternion (z1.Re() + z2.Re(), z1.Imi() + z2.Imi(), z1.Imj() + z2.Imj(), z1.Imk() + z2.Imk());
}

Quaternion operator - (const Quaternion& z1, const Quaternion& z2){
	return Quaternion (z1.Re() - z2.Re(), z1.Imi() - z2.Imi(), z1.Imj() - z2.Imj(), z1.Imk() - z2.Imk());
}

Quaternion operator * (const Quaternion& z1, const Quaternion& z2){
	double a, b, c, d;
	a = z1.Re() * z2.Re() - z1.Imi() * z2.Imi() - z1.Imj() * z2.Imj() - z1.Imk() * z2.Imk();
	b = z1.Re() * z2.Imi() + z1.Imi() * z2.Re() + z1.Imj() * z2.Imk() - z1.Imk() * z2.Imj();
	c = z1.Re() * z2.Imj() - z1.Imi() * z2.Imk() + z1.Imj() * z2.Re() + z1.Imk() * z2.Imi();
	d = z1.Re() * z2.Imk() + z1.Imi() * z2.Imj() - z1.Imj() * z2.Imi() + z1.Imk() * z2.Re();
	return Quaternion(a,b,c,d);
}
std::ostream& operator << (std::ostream& out, const Quaternion& z){
	bool first = 0;
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
	}	
	return out;	
}

int main(){
	double a, b, c, d;
	double w, x, y, z;
	std::cout<<"Put your numbers. First\nRe: ";
	std::cin>>a;
	std::cout<<"Imi: ";
	std::cin>>b;
	std::cout<<"Imj: ";
	std::cin>>c;
	std::cout<<"Imk: ";
	std::cin>>d;
	std::cout<<"Second\nRe: ";
	std::cin>>w;
	std::cout<<"Imi: ";
	std::cin>>x;
	std::cout<<"Imj: ";
	std::cin>>y;
	std::cout<<"Imk: ";
	std::cin>>z;
	Quaternion z1 = Quaternion(a, b, c, d);
	Quaternion z2 = Quaternion(w, x, y, z);
	std::cout<<"Your numbers:\nz1="<<z1<<"\nz2="<<z2;
	std::cout<<"\n-z1="<<-z1;
	std::cout<<"\n-z2="<<-z2;
	std::cout<<"\nz1+z2="<<z1+z2;
	std::cout<<"\nz1-z2="<<z1-z2;
	std::cout<<"\nz1*z2="<<z1*z2;
	return 0;
}
