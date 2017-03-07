// Name: Parthkumar Patel              Date:August 2nd/2016
#ifndef SICT_SCMAPP_H_
#define SICT_SCMAPP_H_
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Course.h"
#include "Streamable.h"


using namespace std;
namespace sict{
class ScmApp 
{
    char filename_ [256];
    fstream dataFile_;
    
	Course* courseList_[MAX_NO_RECS];
	int noOfCourses_;
	void pause() const;
	int menu();
	void listCourses()const;
	int searchACourse(const char* courseCode) const;
	void addACourse(int opt);
	void changeStudyLoad(const char* courseCode);
    void loadRecs();
    void saveRecs();
    
    

   
public:
	ScmApp(const char* filename);
	~ScmApp();
	int run();
    ScmApp();
    friend class ScmAppTester;

};
};
#endif
#pragma once
