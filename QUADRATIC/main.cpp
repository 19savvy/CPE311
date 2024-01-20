#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <string>

using namespace std;

struct ComplexRoots{
	complex<double> root1;
	complex<double> root2;
};
struct Coefficient {
	double SecondOrderCoeff;
	double FirstOrderCoeff;
	double ConstantCoeff;
};

class Quadratic{
private:
	double SecondOrderCoeff;
	double FirstOrderCoeff;
	double ConstantCoeff;

	complex<double> CalcDeterminant(){
		return complex<double>(FirstOrderCoeff*FirstOrderCoeff - 4 * SecondOrderCoeff * ConstantCoeff);
	};
public:
	Quadratic(): SecondOrderCoeff(0.0), FirstOrderCoeff(0.0), ConstantCoeff(0.0){};

	Quadratic(double a, double b, double c): SecondOrderCoeff(a), FirstOrderCoeff(b), ConstantCoeff(c){};

	void SetCoefficient(double a, double b, double c){
		SecondOrderCoeff = a;
		FirstOrderCoeff = b;
		ConstantCoeff = c;
	};
	void GetCoefficient(Coefficient* coefficient){
		coefficient->SecondOrderCoeff = SecondOrderCoeff;
		coefficient->FirstOrderCoeff = FirstOrderCoeff;
		coefficient->ConstantCoeff = ConstantCoeff;
	};
	void QuadraticRoots(ComplexRoots *roots){
		complex<double> det = CalcDeterminant();
		complex<double> sqrt_det = sqrt(det);

		roots->root1 = (-FirstOrderCoeff + sqrt_det)/(2 * SecondOrderCoeff);
		roots->root2 = (-FirstOrderCoeff - sqrt_det)/(2 * SecondOrderCoeff);
	};
	void WriteRoots(ComplexRoots *roots) {
    cout << "Root 1: " << roots->root1.real();
    if (roots->root1.imag() != 0.0) {
        cout << " + " << roots->root1.imag() << "i";
    }
    cout << "\t";

    cout << "Root 2: " << roots->root2.real();
    if (roots->root2.imag() != 0.0) {
        cout << " + " << roots->root2.imag() << "i";
    }
    cout << endl;
}

};
int main(void){
	Quadratic quadraticUser, quadraticReal, quadraticSame, quadraticComplex;
	Coefficient coefficient;
	ComplexRoots complex;

	cout << "Enter the Second Order Coefficient(a): ";
	cin >> coefficient.SecondOrderCoeff;
	cout << "Enter the Fisrt Order Coefficient(b): ";
	cin >> coefficient.FirstOrderCoeff;
	cout << "Enter the Constant Coefficient(c): ";
	cin >> coefficient.ConstantCoeff;

	quadraticUser.SetCoefficient(coefficient.SecondOrderCoeff, coefficient.FirstOrderCoeff, coefficient.ConstantCoeff);
	quadraticUser.QuadraticRoots(&complex);
	cout << "Roots for user's input: ";
	quadraticUser.WriteRoots(&complex);
	cout << endl;

	quadraticSame.SetCoefficient(1.0, -4.0, 4.0);
	quadraticSame.QuadraticRoots(&complex);
	cout << "Roots for same roots: ";
	quadraticSame.WriteRoots(&complex);
	cout << endl;

	quadraticReal.SetCoefficient(1.0, -5.0, 6.0);
	quadraticReal.QuadraticRoots(&complex);
	cout << "Roots for real roots: ";
	quadraticReal.WriteRoots(&complex);
	cout << endl;

	quadraticComplex.SetCoefficient(1.0, 2.0, 5.0);
	quadraticComplex.QuadraticRoots(&complex);
	cout << "Roots for complex roots: ";
	quadraticComplex.WriteRoots(&complex);
	cout << endl;
	system("pause");
	return (0);
}
