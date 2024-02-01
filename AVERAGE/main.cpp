#include "header.h"

using namespace std;
int main(){
	Student student[numOfStudents];

	ReadStudentInfo(student);
	CalcAverage(student);
	WriteAvgScore(student);

	system("pause");
	return (0);
}
