// Name: Parthkumar Patel              Date:August 2nd/2016
#ifndef SICT_GENEDCOURSE_H_
#define SICT_GENEDCOURSE_H_
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Course.h"
#include "Streamable.h"

using namespace std;
namespace sict{
    

class GenEdCourse : public Course
{
	int langLevel_;


public:
	int getLangLevel() const;
	void setLangLevel(int value);
	GenEdCourse();
	GenEdCourse(const char* courseC, const char* courseT, int cred, int studyL , int lang);
	 ostream& display(std::ostream& ge) const;
    friend class GenEdCourseTester;
     fstream& store(fstream& fileStream, bool addNewLine = true) const;
     fstream& load(std::fstream& fileStream) ;
     istream& read(istream& is) ;

};

std::ostream& operator<<(std::ostream& py, const GenEdCourse& A);

};
#endif
#pragma once


