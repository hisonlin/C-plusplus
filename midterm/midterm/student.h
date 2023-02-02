#pragma once

#include <string>
#include <vector>
#include <iostream>

struct Course {
	std::string name;
	float grade;
};

class Student {
	std::string name;
	int id;
	std::vector<Course> coursese;

public:
	Student(std::string n, int d) : name(n), id(d)
	{
		std::cout << "Student : (" << name << ", " << id << ") created\n";
	}

	float computeAverage();

	static std::vector<Student> createStudentList(std::string filename);

};



