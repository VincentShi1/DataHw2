#include <iostream>
#include <string>
#include "schedule.h"

Schedule::Schedule(std::string aCRN, std::string aDepartCode, std::string aCourseCode, std::string aCourseName, std::string aDay, 
std::string aStartClass, std::string aEndClass, std::string aRoom){
    CRN = aCRN;
    departCode = aDepartCode;
    courseCode = aCourseCode;
    courseName = aCourseName;
    days = aDay;
    startClass = aStartClass;
    endClass = aEndClass;
    room = aRoom;
    dept = aRoom; //uses the same argument
}

std::string Schedule::getCRN() {
    return CRN;
}

std::string Schedule::getDepartCode() {
    return departCode;
}

std::string Schedule::getCourseCode() {
    return courseCode;
}

std::string Schedule::getCourseName() {
    return courseName;
}

std::string Schedule::getDays() {
    return days;
}

std::string Schedule::getStartClass() {
    return startClass;
}

std::string Schedule::getEndClass() {
    return endClass;
}

std::string Schedule::getRoom() {
    return room;
}

std::string Schedule::getDept(){
    return dept;
}

void Schedule::setCRN(std::string cr) {
    CRN = cr;
}

void Schedule::setDepartCode(std::string dc) {
    departCode = dc;
}

void Schedule::setCourseCode(std::string cc) {
    courseCode = cc;
}

void Schedule::setCourseName(std::string cn) {
    courseName = cn;
}

void Schedule::setDays(std::string aD) {
    days = aD;
}

void Schedule::setStartClass(std::string startC) {
    startClass = startC;
}

void Schedule::setEndClass(std::string endC) {
    endClass = endC;
}

void Schedule::setRoom(std::string ro) {
    room = ro;
}

void Schedule::setDept(std::string dt){
    dept = dt;
}

// bool sortDays(Schedule& day1, Schedule& day2, std::string decider){
//     std::string weekDays[] = {"M", "T", "W","R","F"};
//     int index1 =0 , index2=0;
//     for(int i = 0; i < 5; i++) {
//         if(day1.getDays() == weekDays[i]){
//             index1 = i;
//         }
//         if(day2.getDays() == weekDays[i]){
//             index2 = i;
//         }
//     }
//     if(index1 == index2){
//        // return sortStartTime(day1, day2, decider);
//     }
//     else {
//         return index1 < index2;
//     }
//     std::cout << "SORT DAY IS WRONG";
//     return 0;
// }

