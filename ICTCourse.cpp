// Name: Parthkumar Patel              Date:August 2nd/2016
#include "ICTCourse.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
namespace sict{

ICTCourse::ICTCourse()
{
	strncpy(computerSystem__, "matrix",7);
}

ICTCourse::ICTCourse(const char* courseC, const char * courseT, int cred, int studyL, const char * computerS ): Course(courseC , courseT, cred, studyL)
{
	strncpy(computerSystem__, computerS,7);
	
}


const char * ICTCourse::getComputerSystem() const
{
	return computerSystem__;
}

void ICTCourse::setComputerSystem(const char * compSys)
{
    
	strcpy(computerSystem__, compSys);

}
ostream& ICTCourse::display(std::ostream & py) const
{
    Course::display(py);
    py  << computerSystem__ << '|'  << setw(9) << setfill(' ')   << setw(14) << '|'      << endl;
    return(py);
}

std::ostream& operator<<(std::ostream& out, const ICTCourse& B)
{
    B.display(out);
    return out;
}

std::fstream& ICTCourse::store(fstream& fileStream, bool addNewLine)const
{
    
    fileStream << TYPE_ICT << ',';
    
    Course::store(fileStream,false);
    
    fileStream << getComputerSystem() ;
    
    if(addNewLine == true)
    {
        fileStream << '\n';
    }
    
    return fileStream;
    
    
}

std::fstream& ICTCourse::load(std::fstream& fileStream)
{

    Course::load(fileStream);
    char compSys[6+1];
    
 
    fileStream.get(compSys,6+1,'\n');

	fileStream.ignore();    
  
    setComputerSystem(compSys);
    

        return fileStream;
}

std::istream& ICTCourse::read(istream& is)
{
    Course::read(is);
    char* compSys = nullptr;
   
    char compSystem[6+1];
    
    if(is.fail() == false)
    {
        
        cout << "Computer System: ";
        is >> compSystem;
        compSys = (char*)compSystem;
        setComputerSystem(compSys);
    }
    return is;
    
}
    
};
