#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <limits>

struct Student {
	char Name[50];
	int Score1, Score2, Score3, Score4;
	float AvgScore;
};
int const numOfStudents = 3;
void ReadStudentInfo(Student student[]);
void CalcAverage(Student student[]);
void WriteAvgScore(Student student[]);

#endif /* _HEADER_H_ */
