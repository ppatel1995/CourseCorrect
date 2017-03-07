// Name: Parthkumar Patel              Date:August 2nd/2016
#include <iostream>
#include <cstring>
#include <iomanip>
#include "GenEdCourse.h"
#pragma GCC diagnostic ignored "-Wwrite-strings"
using namespace std;
namespace sict{

int GenEdCourse::getLangLevel() const
{
	return langLevel_;
}

void GenEdCourse::setLangLevel(int value)
{
	langLevel_ = value;

}

GenEdCourse::GenEdCourse()
{
	langLevel_ = 0;
}

GenEdCourse::GenEdCourse(const char * courseC, const char * courseT, int cred, int studyL, int lang): Course(courseC, courseT, cred, studyL)
{
	langLevel_ = lang;

}

ostream& GenEdCourse::display(std::ostream & py) const
{
	Course::display(py);
    py  <<setw(10) <<setfill(' ') << '|'  << setw(13)<< setfill(' ') << langLevel_ << '|' << endl;
    return(py);
}

std::ostream& operator<<(std::ostream& out, const GenEdCourse& B)
{
	B.display(out);
	return out;
}

std::fstream& GenEdCourse::store(std::fstream& fileStream, bool addNewLine ) const
{
    fileStream << TYPE_GEN << ',';
    
    Course::store(fileStream,false);
    
    fileStream << getLangLevel()  ;
    
    if(addNewLine == true)
    {
        fileStream << '\n';
    }
    
    return fileStream;
}
std::fstream& GenEdCourse::load(std::fstream& fileStream)
    {
        Course::load(fileStream);
        int langL=0;
        
        
        fileStream >> langL;
        fileStream.ignore();
        
 
        setLangLevel(langL);
        

        return fileStream;
    }
std::istream& GenEdCourse::read(istream& is)
{
    
   
    int langL;
    
    if(is.fail() == false)
    {
    
        Course::read(is);
        cout << "Language Requirement: ";
        is >>langL;
        setLangLevel(langL);
        
        
    }
        return is;

}


};
