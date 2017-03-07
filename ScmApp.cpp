// Name: Parthkumar Patel              Date:August 2nd/2016
#include "Course.h"
#include "ScmApp.h"
#include "ICTCourse.h"
#include "GenEdCourse.h"
#include "Streamable.h"
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>


using namespace std;
namespace sict{
void ScmApp::pause() const
{
	
	do{
		cin.ignore();
   cout << '\n' << "Press Enter to continue...";
    
	}while (cin.get() != '\n');
	cout << endl;
}

int ScmApp::menu()
{	
	
	cout << "Seneca Course Management Tool" << endl
		<< "1- List courses." << endl
		<< "2- Display the details of a course." << endl
		<< "3- Add a course." << endl
		<< "4- Change the study load of a course." << endl
		<< "5- Load courses from a file." <<endl
        << "6- Save courses to a file." <<endl
        << "0- Exit Program." << endl
		<< ">";
	
	int inp;
	cin >> inp;
	cout << endl;
	/*while the proper input is not selected. the user will keep getting prompted until valid input is entered*/
	while (inp > 6 || inp < 0)
	{
		
			cout << "===Invalid Selection, try again.===";
			cin >> inp;
		
	}

return inp;
}

void ScmApp::listCourses() const
{
	/*uses forlooop to print out the Courses. It uses i as the index value  also the max limit for the course display is 
	set to either 10 or when noOfCourses reaches its last index*/
	cout<< " Row | Code |               Course Title              | Credits | Study Load |  System |  Lang. Req. |" << endl;
	cout<< "-----|------|-----------------------------------------|---------|------------|---------|-------------|" << endl;
	

    int i=0;
	for (i = 0; i < DISPLAY_LINE && i < noOfCourses_; i++)
	{
		cout<< setw(5) << i ;

		courseList_[i]->display(cout);
		
	}
	
	cout << "------------------------------------------------------------------------------------------------------" << endl ;
    cout << endl;
	

}
/*searches through getcourseCode() to find matching coursecode given by the user. if found it returns i, if not then returns -1*/
int ScmApp::searchACourse(const char* courseCode) const
{
	
	int i;
	for (i = 0; i < noOfCourses_ ; i++)
	{
		if(*courseList_[i] == courseCode)
		{
			return i;
		}
	

	} 

	

			return -1;
		
}

void ScmApp::changeStudyLoad(const char* courseCode)
{
	int search=0;
	/*If searchACourse function returns an index value then the user is prompted input a 
	studyload value and we use the operator += to modify */
	search = searchACourse(courseCode);
	if(search != -1)
	{
	cout << "Please enter the amount of the study load: " ;
	int change = 0;
	cin >> change;
	courseList_[search]->getStudyLoad();
	change+= courseList_[search]->getStudyLoad();
	courseList_[search]->setStudyLoad(change);
	cout << endl;
	}else
	{
		cout << "Not found! \n\n";
	}
	


}

ScmApp::ScmApp(const char* filename)
{

	
	 noOfCourses_= 0;
    if(filename)
    {
        strncpy(filename_,filename,256);
    }
    
    for(int i=0;i<MAX_NO_RECS;i++)
    {
        courseList_[i] = nullptr;
    }
    
}


void ScmApp::addACourse(int opt)
{

		/*char *  courseCd = nullptr;
		char courseCds[101];
		char courseTl[101];

		char* courseTitlep = nullptr;
		int credit;
		int studyLoadL;

		cout << endl << "course code: ";
		cin >> courseCds;
		courseCd = (char*)courseCds;



		cin.ignore();



		cout << "Course Title: ";
		cin.getline(courseTl, 101);

		courseTitlep = (char*)courseTl;





		cout << "Course credit: ";
		cin >> credit;


		cout << "Study Load: ";
		cin >> studyLoadL;

		*/

		if (opt == 1)
		{
			/*cout << "Computer System: ";
			char *  compSys = nullptr;
			char compSystem[101];

			cin >> compSystem;
			compSys = (char*)compSystem;
			cin.ignore();
            courseList_[noOfCourses_] = new ICTCourse(courseCd, courseTitlep,credit,studyLoadL,compSys);
            cout << endl;
            */
            courseList_[noOfCourses_] = new ICTCourse();
            courseList_[noOfCourses_]->read(cin);
 

            
           
		}
		else if (opt== 2)
		{
			/*cout << "Language Requirement: ";
			int langR;
			cin >> langR;
            
            courseList_[noOfCourses_] = new GenEdCourse(courseCd, courseTitlep,credit,studyLoadL,langR);
            cout << endl;
            */
            courseList_[noOfCourses_] = new GenEdCourse();
            courseList_[noOfCourses_]->read(cin);

		}
    
		
		
        noOfCourses_ += 1;
		

}	


ScmApp::~ScmApp()
{
    if(noOfCourses_ > 0)
    {
        for(int n=0; n < noOfCourses_  ; n++)
        {
  
            delete courseList_[n];
    
        }
    }
}

    ScmApp::ScmApp()
    {
        
        for(int i=0; i < MAX_NO_RECS ; i++)
        {
            
                delete courseList_[i];
                courseList_[i] = nullptr;
        
        }
        
        
    }
    
int ScmApp::run()
{
   
	
	int input;
	
	do{
		input=  menu();
		
	if(input == 1)
	{
		listCourses();

	}else if(input == 2)
	{
		


	}else if(input == 3)
	{
        int option;
        do {
            
            cout << "Please enter the course type (1-ICT or 2-GenEd):";
            cin >> option;
            
        }while (option != 1 && option != 2);
        
        
		addACourse(option);
        
        
	}
	else if (input == 4)
	{
		cout << endl;
		char courseCo[MAX_COURSECODE_LEN + 1];
        
        
		cout << "Please enter the course code :"  ;
		cin >> courseCo;
		changeStudyLoad(courseCo);
	}else if (input == 5)
    {
        loadRecs();
    }else if(input == 6)
    {
        saveRecs();
    }
	

	}while(input != 0);
	
	cout << "Goodbye!!";

	return 0;
}
void ScmApp::loadRecs()
{

    int readIndex=0;
    
    char ch;
    
  
    
    dataFile_.open(filename_,ios::in);
    
    if(dataFile_.fail())
    {
        dataFile_.clear();
        dataFile_.close();
       	dataFile_.open(filename_,ios::out);
	dataFile_.close(); 
    }else
    {
        for(int i = 0; i < noOfCourses_; i++)
        {
            delete courseList_[i];
            courseList_[i] = nullptr;
            
        }
        while(!dataFile_.fail())
        {
            dataFile_.get(ch);
            
    
            if(ch == 'I')
            {
                courseList_[readIndex] = new ICTCourse();
        	dataFile_.get();
		courseList_[readIndex]-> load(dataFile_);
		readIndex++;
                
            }else if(ch == 'G')
            {
                courseList_[readIndex] = new GenEdCourse();
               	dataFile_.get();
	       	courseList_[readIndex]-> load(dataFile_);
                readIndex++;
            }
            
        
         
            
            
        }

	noOfCourses_ = readIndex;
        dataFile_.close();
    }
    dataFile_.close();
}
    
void ScmApp::saveRecs()
{
    dataFile_.open(filename_, ios::out);
    
    for(int i = 0; i < noOfCourses_ ; i++)
    {
        courseList_[i]->store(dataFile_,true);
        
    }
 
    dataFile_.close();
    
}
};
