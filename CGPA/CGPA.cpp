// pracgpa.cpp : Defines the entry point for the console application.
//

#include "Header.h"
using namespace std;

struct Course {
	string course_code;
	int course_unit;
	char course_grade;
	float course_point;
};

struct Summary {
	int units_taken;
	int units_passed;
	int weighted_score;
	float gpa;
};

// Define the Cgpa class
class Cgpa {
	private:
		int units_taken;
		int units_passed;
		int weighted_score;
		float gpa;

	public:
		// Default constructor
		Cgpa() : units_taken(0), units_passed(0), weighted_score(0), gpa(0.0) {}

		// Parameterized constructor
		Cgpa(int units_taken, int units_passed, int weighted_score, float gpa)
			: units_taken(units_taken), units_passed(units_passed),
			weighted_score(weighted_score), gpa(gpa) {}

		// Member function to calculate parameters
		void CalcParameters(Course courses[], int num_courses) {
			for (int i = 0; i < num_courses; i++) {
				units_taken += courses[i].course_unit;
				if (courses[i].course_point > 0) {
					units_passed += courses[i].course_unit;
					weighted_score += courses[i].course_unit * courses[i].course_point;
				}
			}
			gpa = CalcGpa();
		}

		// Member function to calculate GPA
		float CalcGpa() const {
			return (units_taken > 0) ? static_cast<float>(weighted_score) / units_taken : 0.0;
		}

		// Member function to get summary results
		Summary GetSummaryResults() const {
			Summary result;
			result.units_taken = units_taken;
			result.units_passed = units_passed;
			result.weighted_score = weighted_score;
			result.gpa = gpa;
			return result;
		}

		// Overloaded + operator for cumulative results
		Cgpa operator+(const Cgpa& other) const {
			Cgpa result;
			result.units_taken = units_taken + other.units_taken;
			result.units_passed = units_passed + other.units_passed;
			result.weighted_score = weighted_score + other.weighted_score;
			result.gpa = (result.units_taken > 0) ? static_cast<float>(result.weighted_score) / result.units_taken : 0.0;
			return result;
		}
};

int main() {
	// Instantiate objects
	Cgpa cgpa;
	Summary summary;

	// Preset course objects
	Course courses[3] = {{"EEG331", 2, 'A', 5.0},
		{"GEG311", 3, 'B', 4.0},
		{"CPE311", 2, 'A', 5.0},
	};

	// Call CalcParameters to compute units taken, units passed, and weighted score
	cgpa.CalcParameters(courses, 3);

	// Retrieve results from cgpa object using summary
	summary = cgpa.GetSummaryResults();

	// Display results
	cout << "Units Taken: " << summary.units_taken << endl;
	cout << "Units Passed: " << summary.units_passed << endl;
	cout << "Weighted Score: " << summary.weighted_score << endl;
	cout << "GPA: " << summary.gpa << endl;

	// Create two more Cgpa objects
	Cgpa cumulativeResult(8, 6, 30, 3.75);

	// Add the cumulative result with the semester result
	Cgpa totalResult = cumulativeResult + cgpa;

	// Display results from the cumulative result object
	Summary cumulativeSummary = cumulativeResult.GetSummaryResults();
	cout << "\nCumulative Result:" << std::endl;
	cout << "Units Taken: " << cumulativeSummary.units_taken << endl;
	cout << "Units Passed: " << cumulativeSummary.units_passed << endl;
	cout << "Weighted Score: " << cumulativeSummary.weighted_score << endl;
	cout << "Cumulative GPA: " << cumulativeSummary.gpa << endl;

	// Display results from the total result object
	Summary totalSummary = totalResult.GetSummaryResults();
	cout << "\nTotal Result (Cumulative + Semester):" << endl;
	cout << "Units Taken: " << totalSummary.units_taken << endl;
	cout << "Units Passed: " << totalSummary.units_passed << endl;
	cout << "Weighted Score: " << totalSummary.weighted_score << endl;
	cout << "Total GPA: " << totalSummary.gpa << endl;
	system("pause");

	return 0;
}
