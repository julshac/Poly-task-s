#include <iostream>
#include <string>
using namespace std;

int main() {
	double matrix[][3] = {
	{1, 2, 3}, 
	{2, 1, 2},
	{3, 2, 1}};
	
	int side = sizeof(matrix[0]) / sizeof(matrix[0][0]);
	bool issymetric = true;
	
	//is matrix square?
	issymetric = (side % 2 == 0) ? false : true;
	
	if (issymetric)
		for (int i = 0; i < side; i++)
		  for (int j = 0; j < side; j++)
		    issymetric = issymetric && (matrix[i][j] == matrix[j][i]);
	
	if (issymetric)
		cout << "The matrix is symetric" << endl;
	else
		cout << "The matrix is not symetric" << endl;
	return 0;
}
