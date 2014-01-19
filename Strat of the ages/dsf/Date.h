#pragma once
#include <string>
using namespace std;



struct Date{
	int Year;
	int YearMod;
	int Month;
	int Day;
	int MonthLengths[12];
	string MonthNames[12];

	Date(){
		Year = 0;
		YearMod = 1702;
		Month = 0;
		Day = 0;
		MonthLengths[0] = 31;
		MonthLengths[1] = 29;
		MonthLengths[2] = 31;
		MonthLengths[3] = 30;
		MonthLengths[4] = 31;
		MonthLengths[5] = 30;
		MonthLengths[6] = 31;
		MonthLengths[7] = 31;
		MonthLengths[8] = 30;
		MonthLengths[9] = 31;
		MonthLengths[10] = 30;
		MonthLengths[11] = 31;
		MonthNames[0] = "Jan";
		MonthNames[1] = "Feb";
		MonthNames[2] = "Mar";
		MonthNames[3] = "Apr";
		MonthNames[4] = "May";
		MonthNames[5] = "June";
		MonthNames[6] = "July";
		MonthNames[7] = "Agst";
		MonthNames[8] = "Sept";
		MonthNames[9] = "Oct";
		MonthNames[10] = "Nov";
		MonthNames[11] = "Dec";
	}

	string PrintDate(){
		string Hld;
		char Buf[5];
		Hld.append(MonthNames[Month]);
		Hld.append(",");
		ltoa(Day+1,Buf,10);
		Hld.append(Buf);
		Hld.append(",");
		ltoa(Year+YearMod,Buf,10);
		Hld.append(Buf);
		return Hld;
	}

	bool Increment(){
		bool Hld = false;
		Day++;
		if(Day == MonthLengths[Month]){
			Day = 0;
			Month++;
			Hld = true;

		}
		if(Year%4 != 0){
			if(Month == 2 && Day == 28)
			{
				Month++;
				Day = 0;
			}
		}
		if(Month == 12){
			Year++;
			Month = 0;
		}
		return Hld;
	}

	void operator+= (int a_i){
		for(int i = 0; i < a_i;i++){
			Increment();
		}
	}

	bool operator== (const Date other)const{
		if(Year == other.Year && Month == other.Month && Day == other.Day)
			return true;
		return false;
	}

	bool operator< (const Date other)const{
		if(Year < other.Year)
			return true;
		if(Year > other.Year)
			return false;
		if(Month < other.Month)
			return true;
		if(Month > other.Month)
			return false;
		if(Day < other.Day)
			return true;
		if(Day > other.Day)
			return false;
		return false;
	}
	bool operator> (const Date other)const{
		if(Year < other.Year)
			return false;
		if(Year > other.Year)
			return true;
		if(Month < other.Month)
			return false;
		if(Month > other.Month)
			return true;
		if(Day < other.Day)
			return false;
		if(Day > other.Day)
			return true;
		return false;
	}
};