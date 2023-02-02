#include <fstream>
#include "student.h"
#include <string>
#include<sstream>

/*
* computes average of this student's grades and return it.
*/
float Student::computeAverage()
{
    float sum = 0.0;
    for (int i = 0; i < coursese.size(); i++) {
        sum += coursese[i].grade;
    }

    return sum / coursese.size();
}

/*
* Opens the text file with name filename and imports grades for each student. Each line
* in the file corresponds to one student. The format of the line is the following:
* studentname id coursename grade coursename grade .....
*
*/
std::vector<Student> Student::createStudentList(std::string filename)
{
    auto studs = std::vector<Student>();
    std::ifstream fs(filename);
    if (fs.is_open())
    {
        // read line by line  and print it.
        // THenuse the line to create a Student object 
        // based on the format of the file explained above. 
        // Finally add the student to studs

        std::string line;
        while (std::getline(fs, line)) {
            std::stringstream ss(line);
            std::string name;
            int id;
            ss >> name >> id;
            Student student(name, id);

            for (int i = 0; i < 5; ++i) {
                std::string courseName;
                float grade;
                ss >> courseName >> grade;
                Course course = { courseName, grade };
                student.coursese.push_back(course);
            }
            studs.push_back(student);
        }
        
    }
    fs.close();

    return studs;
}
