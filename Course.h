// Name: Parthkumar Patel              Date:August 2nd/2016
#ifndef SICT_COURSE_H_
#define SICT_COURSE_H_
#include <iostream>
#include <cstring>
#include <iomanip>
#include "general.h"
#include "Streamable.h"

using namespace std;
namespace sict{
    class Course : public Streamable
{
	char courseCode_[MAX_COURSECODE_LEN + 1];
	char* courseTitle_;
	int credits_;
	int studyLoad_;

public:
	Course();
	Course(const char* courseCode, const char* courseTitle, int credits, int studyload);
    virtual ~Course();
	Course(const Course& src);
	Course& operator=(const Course& one);
	int operator+=(int studyLoad);
    bool operator==(const char* courseC);
	void setCourseCode(const char * courseCode);
	void setCourseTitle(const char* courseTitle);
	void setCredits(int credits);
	void setStudyLoad(int studyLoad);
	const char* getCourseCode() const;
	const char* getCourseTitle() const;
	int getCredits() const;
	int getStudyLoad() const;
	bool isEmpty() const;
    ostream& display(std::ostream& py) const;
   fstream& store(fstream& fileStream, bool addNewLine) const;
       fstream& load(std::fstream& fileStream) ;
            istream& read(istream& is)  ;
    friend class CourseTester;
};

//bool operator==(const Course& lhs, const Course& rhs);
std::ostream& operator<<(ostream& py, const Course& A);

};

#endif
#pragma once
