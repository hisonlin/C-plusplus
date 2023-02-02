

#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <ctime>

#include "student.h"

using namespace std;

/*
This function creates a vector of n random integers in range [1, 10] and return it.
*/
std::vector<int> createRandomVector(int n)
{
	std::vector<int> vec(n);
	// implement this function.
	srand(time(0));
	

	for (int i = 0; i < vec.size(); ++i) {
		vec[i] = (rand() % 10) + 1;

	}
	return vec;
}

/*
This function first finds the average of the numbers in vec. Then subtracts each number from the average and save it back in the vector.
For example for vec={2, 7, 8, 11}, the average is avg = (2+7+8+11)/4 = 7. Then the update vec becomes {2-7, 7-7, 8-7, 11-7} which is { -5, 0, 1, 3}
*/
void subtractAverage(std::vector<int>& vec)
{
	// implement this function
	int sum = 0;
	for (int i = 0; i < vec.size(); ++i) {
		sum += vec[i];

	}

	int avg = sum / sizeof(vec);

	for (int i = 0; i < vec.size(); ++i) {
		vec[i] -= avg;

	}
	
}

void printVector(const std::vector<int>& vec)
{
	cout << "vec: ";
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << ", ";

	}
	cout << endl;
	
}


int main()
{
	cout << "Question 1: create a vector of 20 random numbers in range 1 to 10:\n";
	vector<int> theNumbers = createRandomVector(20);

	// print theNumbers bellow:
	printVector(theNumbers);

	cout << "\nQuestion 2: resetting theNumbers with respect to their average:\n";
	subtractAverage(theNumbers);

	printVector(theNumbers);

	cout << "\nQuestion3: Load students data from file studentData.txt and compute " <<
		" each student grade average and print it : \n";

	vector<Student> students = Student::createStudentList("studentData.txt");

	// compute average grads for each student by calling its method computeAverage(). At the end
	// print the average.
	for (int i = 0; i < students.size(); ++i) {
		float avg = students[i].computeAverage();
		cout << "\nstudent " << i+1 << " average grade: " << avg << endl;
	}
	
	

	cout << "End of Midterm Hey!!!!.\n";
	
	string finsih;
	cin >> finsih;
	return 0;
}