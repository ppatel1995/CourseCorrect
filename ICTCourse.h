// Name: Parthkumar Patel              Date:August 2nd/2016
#ifndef SICT_ICTCOURSE_H_
#define SICT_ICTCOURSE_H_
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Course.h"
#include "Streamable.h"

using namespace std;
namespace sict{
class ICTCourse: public Course
{
	char computerSystem__[6 + 1];
	

public:
	ICTCourse();
	ICTCourse(const char * courseC, const char * courseT, int cred, int studyL,const char * computerS);
	const char* getComputerSystem() const;
	void setComputerSystem(const char* compSys);
     ostream& display(std::ostream& ge) const;
    friend class ICTCourseTester;
     fstream& store(fstream& fileStream, bool addNewLine) const ;
     fstream& load(std::fstream& fileStream) ;
     istream& read(istream& is) ;



};
std::ostream& operator<<(std::ostream& py, const ICTCourse& A);
};
#endif
#pragma once

