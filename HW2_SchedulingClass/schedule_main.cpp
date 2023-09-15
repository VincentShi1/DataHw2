#include <iostream>
#include <vector>
#include <string> 
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "schedule.h"

//Functions

//initialize Schedule Objects that contain each line of the input file.
//Used for easier formatting and clearly determining each lines for output.
Schedule makeSchedule(std::vector<std::string>& oneLine){
    Schedule firstSch(oneLine[0],oneLine[1],oneLine[2],oneLine[3],oneLine[4],oneLine[5],oneLine[6],oneLine[7]);
    return firstSch;
}
//adding spaces to str::string
std::string printSpaces(int num){
    std::string spaces;
    for(int i = 0; i < num; i++){
        spaces += " ";
    }
    return spaces;
}
//adding dashes for formatting
std::string printDashes(int num) {
    std::string dashes;
    for(int i = 0; i < num; i++) {
        dashes += "-";
    }
    return dashes;
}

//last, alpha
bool sortDeptName(Schedule& deptN1, Schedule& deptN2) {
    std::string deptCode1 = deptN1.getDepartCode();
    std::string deptCode2 = deptN2.getDepartCode();
    return deptCode1 < deptCode2;
}

//fourth,   first for dept, numb
 bool sortCourseCode(Schedule& courseC1, Schedule& courseC2){
    std::string courseCode1 = courseC1.getCourseCode();
    std::string courseCode2 = courseC2.getCourseCode();
    int numCourseC1 = std::stoi((courseCode1.substr(0,4) + courseCode1.substr(5,2)));
    int numCourseC2 = std::stoi((courseCode2.substr(0,4) + courseCode2.substr(5,2)));
    //std::cout << sortStartTime(courseC1, courseC2, "dept");
    if(numCourseC1 == numCourseC2){
        return sortDeptName(courseC1, courseC2);
    }
    else{
        return numCourseC1 < numCourseC2;
    }
    std::cout << "Something wrong g w/ course code";
    return 0;
}


//third overall, change  them to int and for PM, add +12
bool sortStartTime(Schedule& startT1, Schedule& startT2){
    std::string startClass1 = startT1.getStartClass();
    std::string startClass2 = startT2.getStartClass();
    int start1 =0, start2 =0;
    if(startClass1.find("12")!=std::string::npos){
        start1 -= 1200;
    }
    if(startClass2.find("12")!=std::string::npos){
        start2 -= 1200;
    }
    if(startClass1.find("PM") != std::string::npos){
        start1+=1200;
    }

    if(startClass2.find("PM") != std::string::npos){start2+=1200;}

    std::string time1, time2 ;

    time1 = startClass1.substr(0,2) + startClass1.substr(3,2);
    time2 = startClass2.substr(0,2) + startClass2.substr(3,2);
    start1 += std::stoi(time1);
    start2 += std::stoi(time2);
    if(start1 == start2) {
        return sortCourseCode(startT1, startT2);
    }
    else{
        return start1 < start2;
    }
}
//second,overall, Monday first so whatever
bool sortDays(Schedule& day1, Schedule& day2){
    std::string weekDays[] = {"M", "T", "W","R","F"};
    int index1 =0 , index2=0;
    for(int i = 0; i < 5; i++) {
        if(day1.getDays() == weekDays[i]){
            index1 = i;
        }
        if(day2.getDays() == weekDays[i]){
            index2 = i;
        }
    }
    if(index1 == index2){
        //return sortStartTime(day1, day2, decider);
        return sortStartTime(day1, day2);
    }
    else {
        return index1 < index2;
    }
}


//DEPT FUNCTION
bool sortStartTimeDept(Schedule& startT1, Schedule& startT2){
    std::string startClass1 = startT1.getStartClass();
    std::string startClass2 = startT2.getStartClass();
    int start1 =0, start2 =0;
    if(startClass1.find("12")!=std::string::npos){
        start1 -= 1200;
    }
    if(startClass2.find("12")!=std::string::npos){
        start2 -= 1200;
    }
    if(startClass1.find("PM") != std::string::npos){
        start1+=1200;
    }

    if(startClass2.find("PM") != std::string::npos){start2+=1200;}

    std::string time1, time2 ;

    time1 = startClass1.substr(0,2) + startClass1.substr(3,2);
    time2 = startClass2.substr(0,2) + startClass2.substr(3,2);
    start1 += std::stoi(time1);
    start2 += std::stoi(time2);
        
    return start1 < start2;
}

bool sortDays1(Schedule& day1, Schedule& day2){
    std::string weekDays[] = {"M", "T", "W","R","F"};
    int index1 =0 , index2=0;
    for(int i = 0; i < 5; i++) {
        if(day1.getDays() == weekDays[i]){
            index1 = i;
        }
        if(day2.getDays() == weekDays[i]){
            index2 = i;
        }
    }
    if(index1 == index2){
        //return sortStartTime(day1, day2, decider);
        return sortStartTime(day1, day2);
    }
    else {
        return index1 < index2;
    }
}

int columnLength(std::vector<Schedule>& schedule, std::string field) {
    int columnSize = 0;
    int scheduleSize = schedule.size();
    if(field == "Class"){
        for(int i = 0; i < scheduleSize; i++){
            int classLength = schedule[i].getCourseName().length();
            if(classLength > columnSize){
                columnSize = classLength;
            }
        }
    }
    if(field == "Day"){
        for(int i = 0 ; i < scheduleSize; i++) {
            std::string weekDay = schedule[i].getDays();
            std::cout << schedule[i].getDays() << std::endl;
            std::cout << "columnSize before: " << columnSize << std::endl;
            if((weekDay.find("M")== std::string::npos)){
                if(columnSize <6) {
                    columnSize = 6;
                }
            }
            if((weekDay.find("T") == std::string::npos)) {
                if(columnSize < 7){
                    columnSize = 7;
                }
            }
            if((weekDay.find("W")) == std::string::npos) {
                if(columnSize < 9){
                    columnSize = 9;
                }
            }
            if((weekDay.find("R")) == std::string::npos) {
                if(columnSize < 8) {
                    columnSize = 8;
                }
            }
            //Monday and Friday have the same length 
            if (weekDay.find("F") == std::string::npos) {
                if(columnSize < 6){
                    columnSize = 6;
                }
            }

            else columnSize = 0;
        }

        std::cout << "columnSize after: " << columnSize << std::endl;

    }

    return columnSize;
}


std::vector<Schedule> sameRoomSort(const std::string& room,std::vector<Schedule>& schedule){
    int scheduleSize = schedule.size();
    std::vector<Schedule> sameRoom;
    for(int i = 0; i < scheduleSize; i++){
        if(room == schedule[i].getRoom()){
            if(schedule[i].getDays().length() > 1) {

                std::string weekDay;
                std::string scheduleDay = schedule[i].getDays();
                if(scheduleDay.find("M") != std::string::npos){
                    weekDay += "M";
                }
                if(scheduleDay.find("T") != std::string::npos) {
                    weekDay += "T";
                }
                if(scheduleDay.find("W") != std::string::npos) {
                    weekDay += "W";
                }
                if(scheduleDay.find("R") != std::string::npos) {
                        weekDay += "R";
                }
                if(scheduleDay.find("F") != std::string::npos) {
                    weekDay += "F";
                }
                std::string firstDay = weekDay.substr(0,1);
                schedule[i].setDays(firstDay);
                sameRoom.push_back(schedule[i]);
                //Schedule newCourse(schedule[i].getCRN(), schedule[i].getDepartCode(), schedule[i].getCourseName(), schedule[i].getCourseCode(), weekDay.substr(1), schedule[i].getStartClass(), schedule[i].getEndClass(), schedule[i].getRoom());
                schedule[i].setDays(weekDay.substr(1,2));
                sameRoom.push_back(schedule[i]);
            }
            else{
                sameRoom.push_back(schedule[i]);
            }
        }
    }
    return sameRoom;
}
std::string outputRoom(const std::string& room, std::vector<Schedule>& schedule) {
    std::string output;
    int scheduleSize = schedule.size();
    if(room.length() > 1) {
        std::vector<Schedule> sameRoomName = sameRoomSort(room, schedule);
        int sameRoomSize = sameRoomName.size();
        std::sort(sameRoomName.begin(), sameRoomName.end(), sortDays);

        if(sameRoomSize == 0){
            return "";
        }
        output += "Room " + room +"\n";
        output += "Dept" + printSpaces(2) + "Coursenum" + printSpaces(2) + "Class Title" + printSpaces(columnLength(schedule, "Class") -9) + "Day" + printSpaces(columnLength(schedule, "Day") - 1) + "Start Time" + printSpaces(2) + "End Time\n" ;
        output += printDashes(4) + printSpaces(2) + printDashes(9) + printSpaces(2) + printDashes(columnLength(schedule,"Class")) + printSpaces(2) + printDashes(columnLength(schedule, "Day")) + printSpaces(2) + printDashes(10) + printSpaces(2) + printDashes(8) +"\n";

        for(int i = 0; i < sameRoomSize; i++){
            std::string sameRoomDays = sameRoomName[i].getDays();
            if(sameRoomDays.find("M") != std::string::npos) {
                sameRoomName[i].setDays("Monday");
            }
            if(sameRoomDays.find("T") != std::string::npos) {
                sameRoomName[i].setDays("Tuesday");
            }
            if(sameRoomDays.find("W") != std::string::npos) {
                sameRoomName[i].setDays("Wednesday");
            }
            if(sameRoomDays.find("R") != std::string::npos) {
                sameRoomName[i].setDays("Thursday");
            }
            if(sameRoomDays.find("F") != std::string::npos) {
                sameRoomName[i].setDays("Friday");
            }

            //formatting for output
            output += sameRoomName[i].getDepartCode() + printSpaces(2) + 
            sameRoomName[i].getCourseCode() + printSpaces(4) +
            sameRoomName[i].getCourseName() + printSpaces(columnLength(schedule, "Class") - sameRoomName[i].getCourseName().length() + 2) +
            sameRoomName[i].getDays() + printSpaces(columnLength(schedule, "Day") - sameRoomName[i].getDays().length()+2) +
            sameRoomName[i].getStartClass() + printSpaces(5) + 
            sameRoomName[i].getEndClass() + printSpaces(2) + "\n";

        }
        output += std::to_string(sameRoomSize) + " entries\n";
        
    }
    else{
        std::vector<std::string> manyRooms;
        std::vector<std::string> lessRooms;
        for(int i = 0; i< scheduleSize; i++) {
            manyRooms.push_back(schedule[i].getRoom());
        }
        int manyRoomNum = manyRooms.size();
        std::sort(manyRooms.begin(), manyRooms.end());
        
        for(int i = 0; i < manyRoomNum; i++) {
            if(i == 0) {
                lessRooms.push_back(manyRooms[i]);
            }
            else{
                if(manyRooms[i-1] != manyRooms[i]) {
                    lessRooms.push_back(manyRooms[i]);
                }
            }
        }
        int roomNum = lessRooms.size();
        std::cout << roomNum;

        for(int i = 0; i < roomNum; i++) {
            std::vector<Schedule> sameRoomSchedule;
            sameRoomSchedule = sameRoomSort(lessRooms[i], schedule);
            std::sort(sameRoomSchedule.begin(), sameRoomSchedule.end(),sortDays);
            int sameRoomSize = sameRoomSchedule.size();

            if(sameRoomSize == 0) {
                output += "";
            }
            else {
                std::cout << std::to_string(columnLength(sameRoomSchedule, "Class")-9) << "   "<< std::to_string(i)<< std::endl;                output += "Room " + lessRooms[i] +"\n";
                output += "Dept" + printSpaces(2) + "Coursenum" + printSpaces(2) + "Class Title" + printSpaces(columnLength(sameRoomSchedule, "Class") -9) + 
                "Day" + printSpaces(columnLength(sameRoomSchedule, "Day") - 1) + "Start Time" + printSpaces(2) + "End Time\n" ;
                output += printDashes(4) + printSpaces(2) + printDashes(9) + printSpaces(2) + printDashes(columnLength(sameRoomSchedule,"Class")) + printSpaces(2) + 
                printDashes(columnLength(sameRoomSchedule, "Day")) + printSpaces(2) + printDashes(10) + printSpaces(2) + printDashes(8) +"\n";
            }

            for(int j = 0; j< sameRoomSize; j++){
                std::string sameRoomDays = sameRoomSchedule[j].getDays();
                if(sameRoomDays.find("M") != std::string::npos) {
                    sameRoomSchedule[j].setDays("Monday");
                }
                if(sameRoomDays.find("T") != std::string::npos) {
                    sameRoomSchedule[j].setDays("Tuesday");
                }
                if(sameRoomDays.find("W") != std::string::npos) {
                    sameRoomSchedule[j].setDays("Wednesday");
                }
                if(sameRoomDays.find("R") != std::string::npos) {
                    sameRoomSchedule[j].setDays("Thursday");
                }
                if(sameRoomDays.find("F") != std::string::npos) {
                    sameRoomSchedule[j].setDays("Friday");
                }

                //formatting for output
                output += sameRoomSchedule[j].getDepartCode() + printSpaces(2) + 
                sameRoomSchedule[j].getCourseCode() + printSpaces(4) +
                sameRoomSchedule[j].getCourseName() + printSpaces(columnLength(sameRoomSchedule, "Class") - sameRoomSchedule[j].getCourseName().length() + 2) +
                sameRoomSchedule[j].getDays() + printSpaces(columnLength(sameRoomSchedule, "Day") - sameRoomSchedule[j].getDays().length()+2) +
                sameRoomSchedule[j].getStartClass() + printSpaces(5) + 
                sameRoomSchedule[j].getEndClass() + printSpaces(2) + "\n";

            }
            
            output += std::to_string(sameRoomSize) + " entries";
            if(i < (roomNum-1)) {
                output+="\n\n";
            }
        }

    }
    return output;
}

std::string outputDept(const std::string& dept, std::vector<Schedule>& schedule) {
    std::string output;
    int scheduleSize = schedule.size();

}

int main(int argc, char* argv[]) {
    std::vector<Schedule> schedule;
    std::vector<std::string> inputFileLines;
    std::string currLine;
    int count = 0;
    if(argc < 3){
        std::cerr << "Please double check you have inputted valid arguments. \n";
        return 1;
    }
    
    if(std::string(argv[2]) == std::string("dept") && argc < 5){
        std::cerr << "MISSING A FOURTH ARGUMENT! \n";
        return 1;
    }
    //initialize Schedule Object
    std::ifstream in_str(argv[1]);
    if(!in_str.good()){
        std::cerr << "Can't open " << argv[1] << " to read.\n";
        return 1;
    }
    std::ofstream out_str(argv[2]);
    if(!out_str.good()){
        std::cerr << "Can't open " << argv[2] << " to write.\n";
        return 1;
    }

    while(in_str >> currLine) {
        if(count >= 7){
            inputFileLines.push_back(currLine);
            schedule.push_back(makeSchedule(inputFileLines));
            inputFileLines.clear();
            count = 0;
        }
        else {
            inputFileLines.push_back(currLine);
            count++;
        }
    }
    in_str.close();

    if(strcmp(argv[3], "room") == 0){
        if(argv[4]){
            std::string output1 = outputRoom(argv[4], schedule);
            std::cout << output1 << std::endl;
            out_str << output1;
        }
        else{
            std::string output1 = outputRoom("", schedule);
            std::cout << outputRoom("", schedule) << std::endl;
            out_str << output1;
            
        }
    }
    else if(strcmp(argv[3], "dept") == 0){
        std::string output;
    }




    return 0;
}