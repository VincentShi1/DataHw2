// file: schedule.h
// purpose: header file with declaration of the scheudule class
#include <string>
#ifndef schedule_h
#define schedule_h

class Schedule {
public:
    //Schedule();
    Schedule(std::string aCRN, std::string aDepartCode, std::string aCourseCode, std::string aCourseName, std::string aDay, 
    std::string aStartClass, std::string aEndClass, std::string aRoom);
    // Accessors
    std::string getCRN();
    std::string getDepartCode();
    std::string getCourseCode();
    std::string getCourseName();
    std::string getDays();
    std::string getStartClass();
    std::string getEndClass();
    std::string getRoom();
    std::string getDept();

    // Modifiers
    void setCRN(std::string aCRN);
    void setDepartCode(std::string aDepartCode);
    void setCourseCode(std::string aCourseCode);
    void setCourseName(std::string aCourseName);
    void setDays(std::string aDay);
    void setStartClass(std::string aStartClass);
    void setEndClass(std::string aEndClass);
    void setRoom(std::string aRoom);
    void setDept(std::string aDept);

    //sorters
    bool sortCRN();

//member variables
private: 

    std::string CRN;
    std::string departCode;
    std::string courseCode;
    std::string courseName;
    std::string days;
    std::string startClass;
    std::string endClass;
    std::string room;
    std::string dept;
};

// bool sortDays(Schedule& day1, Schedule& day2, std::string decider);

#endif