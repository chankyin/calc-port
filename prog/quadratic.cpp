#include <modes/cmplx.h>

using namespace std;

int main(){
	ComplexScalar *inputA = &_A_;
	ComplexScalar *inputB = &_B_;
	ComplexScalar *inputC = &_C_;

	query("A: ", inputA);
	query("B: ", inputB);
	query("C: ", inputC);

	cout << "Solving " << *inputA << " x^2 + " << *inputB << " x + " << *inputC << " = 0 ..." << endl;

	ComplexScalar *delta = &_D_;


	return 0;
}
