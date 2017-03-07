// Name: Parthkumar Patel              Date:August 2nd/2016
#include "Course.h"
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace sict;


	Course::Course()
	{
		courseCode_[0] = '\0' ;
		courseTitle_ = nullptr;
		credits_ = 0;
		studyLoad_ = 0;


    }

bool Course::operator==(const char* courseC){
    
    if (strcmp(courseC,courseCode_) == 0)
    {
        return true;
    }else
    {
        return false;
    }
    
}

	Course::Course(const char * courseCode, const char * courseTitle, int credits, int studyload)
	{
		strcpy(courseCode_, courseCode);
		courseTitle_ = new char[strlen(courseTitle) + 1];
		strcpy(courseTitle_ , courseTitle);
		credits_ = credits;
		studyLoad_ = studyload;


    }

	Course::~Course()
	{
			delete[] courseTitle_;
    }

	Course::Course(const Course & src)
	{
	
		courseTitle_ = nullptr;
		*this = src;
    }

/*copy constructor*/
	Course& Course::operator=(const Course & one)
	{

		if (this != &one) {
			strcpy(courseCode_, one.courseCode_);
			credits_ = one.credits_;
			studyLoad_ = one.studyLoad_;
			delete[] courseTitle_;

			if (one.courseTitle_ != nullptr)
			{
				courseTitle_ = new char[strlen(one.courseTitle_) + 1];
				strcpy(courseTitle_, one.courseTitle_);

			}
			else
				courseTitle_ = nullptr;

		}
		return *this;
    }
/*overloading the += operator. adding studyLoad which is the value specified by user to studyLoad_ */
	int Course::operator+=(int studyLoad)
	{
		return studyLoad_ += studyLoad;
       
	}

	void Course::setCourseCode(const char *  courseCode)
	{
		strcpy(courseCode_, courseCode);
    }

	void Course::setCourseTitle(const char * courseTitle)
	{
		//strcpy(courseTitle_ , courseTitle);
        
		courseTitle_ = new char[strlen(courseTitle) + 1];
		strcpy(courseTitle_ , courseTitle);
    }

	void Course::setCredits(int credits)
	{
		credits_ = credits;
	}

	void Course::setStudyLoad(int studyLoad)
	{
		studyLoad_ = studyLoad;
    }

	const char*  Course::getCourseCode() const
	{
		return courseCode_;
	}

	const char* Course::getCourseTitle() const
	{
		return courseTitle_;
    }

	int Course::getCredits() const
	{
		return credits_;
	}

	int Course::getStudyLoad() const
	{
		return studyLoad_;
    }

	bool Course::isEmpty() const
	{
		if(courseCode_[0] == '\0' || courseTitle_ == nullptr || courseTitle_[0] == '\0' || credits_ == 0 || credits_ == -1 || studyLoad_ == 0 || studyLoad_== -1 )
		{
			return true;
		}
		return false;
    	}

	



std::ostream & operator<<(std::ostream & py, const Course& A)
	{
		A.display(py);
		return py;
    }


std::ostream& Course::display(std::ostream& py) const
{
        py  << '|' << setw(6) << setfill(' ') << right << courseCode_   << '|' << setw(41) << setfill(' ') << left <<courseTitle_  << '|' << setw(9) << setfill(' ') << right << credits_  <<'|' << setw(12)<< setfill(' ') << right << studyLoad_  << '|'  << setw(9)<< setfill(' ') ;
        
        return(py);
    }

std::fstream& Course::load(std::fstream& fileStream)
{
    char  courseCd[7];
    
    
    char courseTitlep[100];
    
    int credit=0;
    int studyLoadL=0;
    
    
    
    fileStream.get(courseCd, 7, ',');
    fileStream.ignore();
    
    fileStream.get(courseTitlep,100, ',');
    fileStream.ignore();
 
    fileStream >> credit;
    fileStream.ignore();
 
    fileStream >> studyLoadL;
    fileStream.ignore();
 
    
    setCourseCode(courseCd);
    setCourseTitle(courseTitlep);
    setCredits(credit);
    setStudyLoad(studyLoadL);
    
    
    return fileStream;
}
std::istream& Course::read(istream& is)
{
    
    char *  courseCd = nullptr;
    char courseCds[7];
    char* courseTitlep = nullptr;
    char courseTl[101];
    int credit;
    int studyLoadL;

    
    if(is.fail() == false)
    {
        cout << "course code: ";
         is >>  courseCds;
       	is.ignore(2000,'\n');
       	courseCd = (char*)courseCds;
        setCourseCode(courseCd);
        
        
        cout << "Course Title: ";
        is.getline(courseTl, 100,'\n');
        courseTitlep = (char*)courseTl;
        setCourseTitle(courseTitlep);
        
        
        cout << "Course credit: ";
        is >> credit;
        setCredits(credit);
        
        cout << "Study Load: ";
        is >> studyLoadL;
        setStudyLoad(studyLoadL);
        
      
        
        
    }
    return is;
    
}

std::fstream& Course::store(fstream& fileStream, bool addNewLine)const
{

	    fileStream 
		        << getCourseCode() << ','
			    << getCourseTitle() << ','
			        << getCredits() << ','
				    << getStudyLoad() << ',' ;
			
        return fileStream;


}

