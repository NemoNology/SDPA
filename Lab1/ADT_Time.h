#pragma once
#include <iostream>
#include <exception>
#include <fstream>


using namespace std;



class Time
{

	
private:						// „P„€„|„‘ „{„|„p„ƒ„ƒ„p - Fields

	// hour (0-23) - „‰„p„ƒ; minute (0-59) - „}„y„~„…„„„p; second (0-59) - „ƒ„u„{„…„~„t„p;

	int hour, minute, second;


public:							// „M„u„„„€„t„ „{„|„p„ƒ„ƒ„p - Methods



	// „K„€„~„ƒ„„„‚„…„{„„„€„‚
	Time(const int& h, const int& m, const int& s) {

		Set_hour(h);
		Set_minute(m);
		Set_second(s);

	}



	// „R„u„„„„„u„‚„ - Setter:



	// „N„p„x„~„p„‰„u„~„y„u „‰„p„ƒ„p - Set hour 
	void Set_hour(const int& h) {

		if (h < 0 || h > 23) {	// „E„ƒ„|„y „x„p„t„p„~„~„€„u „x„~„p„‰„u„~„y„u „~„u„r„u„‚„~„€, „„„€ „r„„t„p„v„} „€„Š„y„q„{„…

			throw invalid_argument("Invalid argument: argument is out of range");

		}
		else {					// „E„ƒ„|„y „x„p„t„p„~„~„€„u „x„~„p„‰„u„~„y„u „{„€„‚„‚„u„{„„„~„€, „„„€ „„‚„y„ƒ„r„p„u„r„p„u„} „€„q„Œ„u„{„„„… „r„u„t„v„~„~„€„u „x„~„p„‰„u„~„y„u

			hour = h;

		}

	}


	// „N„p„x„~„p„‰„u„~„y„u „}„y„~„…„„„ - Set minute
	void Set_minute(const int& m) {

		if (m < 0 || m > 59) {	// „E„ƒ„|„y „x„p„t„p„~„~„€„u „x„~„p„‰„u„~„y„u „~„u„r„u„‚„~„€, „„„€ „r„„t„p„v„} „€„Š„y„q„{„…

			throw invalid_argument("Invalid argument: argument is out of range");

		}
		else {					// „E„ƒ„|„y „x„p„t„p„~„~„€„u „x„~„p„‰„u„~„y„u „{„€„‚„‚„u„{„„„~„€, „„„€ „„‚„y„ƒ„r„p„u„r„p„u„} „€„q„Œ„u„{„„„… „r„u„t„v„~„~„€„u „x„~„p„‰„u„~„y„u

			minute = m;

		}

	}


	// „N„p„x„~„p„‰„u„~„y„u „ƒ„u„{„…„~„t„ - Set second
	void Set_second(const int& s) {

		if (s < 0 || s > 59) {	// „E„ƒ„|„y „x„p„t„p„~„~„€„u „x„~„p„‰„u„~„y„u „~„u„r„u„‚„~„€, „„„€ „r„„t„p„v„} „€„Š„y„q„{„…

			throw invalid_argument("Invalid argument: argument is out of range");

		}
		else {					// „E„ƒ„|„y „x„p„t„p„~„~„€„u „x„~„p„‰„u„~„y„u „{„€„‚„‚„u„{„„„~„€, „„„€ „„‚„y„ƒ„r„p„u„r„p„u„} „€„q„Œ„u„{„„„… „r„u„t„v„~„~„€„u „x„~„p„‰„u„~„y„u

			second = s;

		}

	}



	// „C„u„„„„„u„‚„ - Getters:



	// „P„€„|„…„‰„u„~„y„u „‰„p„ƒ„p - Get hour
	int Get_hour() {

		return hour;

	}


	// „P„€„|„…„‰„u„~„y„u „}„y„~„…„„„ - Get minute
	int Get_minute() {

		return minute;

	}


	// „P„€„|„…„‰„u„~„y„u „ƒ„u„{„…„~„t„ - Get second
	int Get_second() {

		return second;

	}


	// „P„€„|„…„‰„u„~„y„u/„B„„r„€„t „r„‚„u„}„u„~„y „r „{„€„~„ƒ„€„|„
	void Get_time_Console() {
		
		cout << "„X„p„ƒ„€„r:\t" << hour << ",\t„}„y„~„…„„:\t" << minute << ",\t„ƒ„u„{„…„~„t:\t" << second << endl;

	}


	
	// „P„€„|„…„‰„u„~„y„u/„B„„r„€„t „r„‚„u„}„u„~„y „r „„„u„{„ƒ„„„€„r„„z „†„p„z„|
	void Get_time_File(fstream& f) {

		f << "„X„p„ƒ„€„r:\t" << hour << ",\t„}„y„~„…„„:\t" << minute << ",\t„ƒ„u„{„…„~„t:\t" << second << endl;

	}



};

