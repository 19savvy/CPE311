#include "header.h"

using namespace std;

void ReadStudentInfo(Student student[]){
	ifstream inputFile("StudentInfo.txt");

	if (!inputFile){
		cerr << "Error opening StudentInfo.txt" << endl;
		exit(1); // i used exit(1) to show there was an error since i cant use return because my function return type is void
	}
	for (int i = 0; i < numOfStudents ; i++){
		inputFile.getline(student[i].Name, 50);
		inputFile >> student[i].Score1 >> student[i].Score2 >> student[i].Score3 >> student[i].Score4;
		inputFile.ignore();
	}
	inputFile.close();
};

void CalcAverage(Student student[]){
	for (int i = 0; i < numOfStudents; i++){
		student[i].AvgScore = (student[i].Score1 + student[i].Score2 + student[i].Score3 + student[i].Score4)/4.0;
	}
};

void WriteAvgScore(Student student[]){
	ofstream outputFile("AvgScoreFile.txt");

	if (!outputFile){
		cerr << "Error creating AvgScoreFile.txt" << endl;
		exit(1); // i used exit(1) to show there was an error since i cant use return because my function return type is void
	}
	for (int i = 0; i < numOfStudents; i++){
		outputFile << student[i].Name << " " << student[i].AvgScore << endl;
	}
	outputFile.close();
}
