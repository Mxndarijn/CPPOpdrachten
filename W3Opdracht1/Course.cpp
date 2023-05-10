#include <iostream>
#include "Course.h"

using namespace std;

Course::Course(const std::string& courseName, int capacity) {
	numberOfStudents = 0;
	this->courseName = courseName;
	this->capacity = capacity;
	students = new std::string[capacity];
}

Course::Course(const Course& course) {
	this->numberOfStudents = course.getNumberOfStudents();
	this->courseName = course.courseName;
	this->capacity = course.capacity;
	
	this->students = new std::string[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->students[i] = course.students[i];
	}
}

Course::~Course() {
	delete[] students;
}

std::string Course::getCourseName() const {
	return courseName;
}

void Course::addStudent(const std::string& name) {
	if (numberOfStudents >= capacity) {
		int newCap = capacity + 1;
		string* newStudents = new string[newCap];

		for (int i = 0; i < capacity; i++) {
			newStudents[i] = students[i];
		}
		delete[] students;

		capacity = newCap;
		students = newStudents;
	}
	students[numberOfStudents] = name;
	numberOfStudents++;

}

void Course::dropStudent(const std::string& name) {
	string* newStudents = new string[capacity];
	int newNumberOfStudents = 0;

	for (int i = 0; i < numberOfStudents; i++) {
		if (students[i] != name) {
			newStudents[newNumberOfStudents] = students[i];
			newNumberOfStudents++;
		}
	}
	delete[] students;

	numberOfStudents = newNumberOfStudents;
	students = newStudents;
}

std::string* Course::getStudents() const {
	return students;
}

int Course::getNumberOfStudents() const {
	return numberOfStudents;
}

void Course::clear() {
	delete[] students;

	students = new string[capacity];
	numberOfStudents = 0;
}

