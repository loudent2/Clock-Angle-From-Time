#include "stdafx.h"
#include <cmath> 



//gets the angle between clock hands based on the hour and the minute	
template<typename T>
auto
ClockHandAngleFromTime(unsigned int hour, unsigned int minute)
{
	//make hour and minute meet valid time values
	hour %= 12;
	minute %= 60;

	//every tick of the clock is 6 degrees
	T baseMinuteHandAngle = static_cast<T>(minute) * 6;
	//every "tick" of the hour hand is 30 degrees (5 minute ticks)
	T baseHourHandAngle = static_cast<T>(hour) * 30;
	//however the hour hand floats between "ticks" based on where
	//the minute hand is. So we need to increase the angle
	//between  hours (30 degrees) by a percentage of minutes
	baseHourHandAngle += (30 * static_cast<T>(minute) / 60);

	//to get the *smallest* angle we need to do a couple of things
	//first get the angle difference based on minute minsu hour
	T AngleDifference = std::abs(baseMinuteHandAngle - baseHourHandAngle);
	//the max angle it can change is 180 
	if (180 < AngleDifference)
	{
		//subtract angle difference from 360
		AngleDifference = 360 - AngleDifference;
	}

	return AngleDifference;
}