/*
 * Arduino clock sketch written for Spring 2015 NCSU ENG 331 instructions project
 */

#include <stdio.h>
// Arduino time library
#include "Time.h"

/* Define pin moduli for segments
 *
 * The modulus is defined as the digital pin on the arduino that the segment is connected to.
 *
 * The predefied values would have the following numbering for segments
 *   0
 *  ---
 * |   |
 * |3  |4
 * |   |
 *   1
 *  ---
 * |   |
 * |5  |6
 * |   |
 *   2
 *  --- 
 */
#define SEGMENT_MODULUS_TOP 0
#define SEGMENT_MODULUS_MIDDLE 1
#define SEGMENT_MODULUS_BOTTOM 2
#define SEGMENT_MODULUS_UPPER_LEFT 3
#define SEGMENT_MODULUS_UPPER_RIGHT 4
#define SEGMENT_MODULUS_LOWER_LEFT 5
#define SEGMENT_MODULUS_LOWER_RIGHT 6

/*
 * Define the starting pin number for each clock number and separator
 */
#define CLOCK_HOUR_FIRST_PIN 1
#define CLOCK_HOUR_SECOND_PIN 8
#define CLOCK_MINUTE_FIRST_PIN 15
#define CLOCK_MINUTE_SECOND_PIN 22
#define SEPARATOR_PIN 29

/*
 * enum for segments to easily turn a given segment on or off. These values when cast as an
 * int should be the same as the modulus of that segment
 */
enum NumberSegment
{
	SEGMENT_TOP = SEGMENT_MODULUS_TOP,
	SEGMENT_MIDDLE = SEGMENT_MODULUS_MIDDLE,
	SEGMENT_BOTTOM = SEGMENT_MODULUS_BOTTOM,
	SEGMENT_UPPER_LEFT = SEGMENT_MODULUS_UPPER_LEFT,
	SEGMENT_UPPER_RIGHT = SEGMENT_MODULUS_UPPER_RIGHT,
	SEGMENT_LOWER_LEFT = SEGMENT_MODULUS_LOWER_LEFT,
	SEGMENT_LOWER_RIGHT = SEGMENT_MODULUS_LOWER_RIGHT
};

/*
 * enum for what each number represents in clock. The values when cast as an int should be the
 * digital pin the LED segments for the number start on.
 */
enum ClockNumber
{
	CLOCK_HOUR_FIRST = CLOCK_HOUR_FIRST_PIN,
	CLOCK_HOUR_SECOND = CLOCK_HOUR_SECOND_PIN,
	CLOCK_MINUTE_FIRST = CLOCK_MINUTE_FIRST_PIN,
	CLOCK_MINUTE_SECOND = CLOCK_MINUTE_SECOND_PIN
};

/*
 * enum for segment status
 */
enum SegmentStatus
{
	SEGMENT_OFF, // 0
	SEGMENT_ON   // 1
};

/*
 * Toggle Number segment
 */
void setNumberSegment(ClockNumber position, NumberSegment segment, SegmentStatus setting)
{
	if(setting)
		digitalWritei((int)position +  (int)segment, HIGH);
	else
		digitalWrite((int)position + (int)segment, LOW);
}

/*
 * Set all LEDs for position
 */
void setAllSegments(ClockNumber position, SegmentStatus setting)
{
	for(int segment = 1; segment < 8; segment++)
		setNumberSegment(position, (NumberSegment)segment, setting);
}

/*
 * Set all numbers
 */
void setAllNumbers(SegmentStatus setting)
{
	setAllSegments(CLOCK_HOUR_FIRST, setting);
	setAllSegments(CLOCK_HOUR_SECOND, setting);
	setAllSegments(CLOCK_MINUTE_FIRST, setting);
	setAllSegments(CLOCK_MINUTE_SECOND, setting);
}

/*
 * Display a number on segment
 */
void displayNumber(ClockNumber position, unsigned int number)
{
	switch(number)
	{
		default:
			setAllSegments(position, SEGMENT_OFF);
		case 0:
			setNumberSegment(position, SEGMENT_TOP, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_BOTTOM, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_UPPER_LEFT, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_UPPER_RIGHT, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_LOWER_LEFT, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_LOWER_RIGHT, SEGMENT_ON);
			break;
		case 1:
			setNumberSegment(position, SEGMENT_UPPER_RIGHT, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_LOWER_RIGHT, SEGMENT_ON);
			break;
		case 2:
			setNumberSegment(position, SEGMENT_TOP, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_UPPER_RIGHT, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_MIDDLE, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_LOWER_LEFT, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_BOTTOM, SEGMENT_ON);
			break;
		case 3:
			setNumberSegment(position, SEGMENT_TOP, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_UPPER_RIGHT, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_MIDDLE, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_LOWER_RIGHT, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_BOTTOM, SEGMENT_ON);
			break;
		case 4:
			setNumberSegment(position, SEGMENT_UPPER_LEFT, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_UPPER_RIGHT, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_MIDDLE, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_LOWER_RIGHT, SEGMENT_ON);
			break;
		case 5:
			setNumberSegment(position, SEGMENT_TOP, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_UPPER_LEFT, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_MIDDLE, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_LOWER_RIGHT, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_BOTTOM, SEGMENT_ON);
			break;
		case 6:
			setNumberSegment(position, SEGMENT_TOP, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_UPPER_LEFT, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_MIDDLE, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_LOWER_RIGHT, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_BOTTOM, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_LOWER_LEFT, SEGMENT_ON);
			break;
		case 7:
			setNumberSegment(position, SEGMENT_TOP, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_UPPER_RIGHT, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_LOWER_RIGHT, SEGMENT_ON);
			break;
		case 8:
			setNumberSegment(position, SEGMENT_TOP, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_MIDDLE, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_BOTTOM, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_UPPER_LEFT, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_UPPER_RIGHT, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_LOWER_LEFT, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_LOWER_RIGHT, SEGMENT_ON);
			break;
		case 9:
			setNumberSegment(position, SEGMENT_TOP, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_MIDDLE, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_BOTTOM, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_UPPER_LEFT, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_UPPER_RIGHT, SEGMENT_ON);
			setNumberSegment(position, SEGMENT_LOWER_RIGHT, SEGMENT_ON);
			break;
	}
}

/*
 * Setup arduino
 */
void setup()
{
	// Initialize LED pins
	for(int pin = 1; pin < 30; pin++)
		pinMode(pin, OUTPUT);

	// Turn on Separator Pin
	digitalWrite(SEPARATOR_PIN, HIGH);

	// Test LEDs by blinking
	setAllNumbers(SEGMENT_ON);
	delay(250);
}

/*
 * Arduino loop. Sets numbers for time on each loop iteration
 */
void loop()
{
	// Get 12-hour hour and separate into digits
	int hour_whole = hourFormat12();
	char hour_str[2];
	sprintf(hour_str, "%d", hour_whole);
	unsigned int hour[2];
	hour[0] = hour_str[0] - '0';
	hour[1] = hour_str[1] - '0';

	// Get minute and separate into digits
	int minute_whole = minute();
	char minute_str[2];
	sprintf(minute_str, "%d", minute_whole);
	unsigned int minute[2];
	minute[0] = minute_str[0] - '0';
	minute[1] = minute_str[1] - '0';

	displayNumber(CLOCK_HOUR_FIRST, hour[0]);
	displayNumber(CLOCK_HOUR_SECOND, hour[1]);
	displayNumber(CLOCK_MINUTE_FIRST, minute[0]);
	displayNumber(CLOCK_MINUTE_SECOND, minute[1]);
}
