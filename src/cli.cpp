#include <iostream>

#include "vector.h"
#include "matrix.h"

int main() {
	Vector<3> v;
	v[0] = 2;
	v[1] = 3;
	v[2] = 7;

	auto mat = Matrix<4>::translation(v); 

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << mat[j][i] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}
