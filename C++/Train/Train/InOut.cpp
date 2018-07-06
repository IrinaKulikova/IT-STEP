#pragma once
#include "stdafx.h"


ostream& operator<<(ostream& stream, DataTime& data)
{
	stream << data.GetDay() << "." << data.GetMonth() << "." << data.GetYear() << " " << data.GetHours() << ":" << data.GetMinuts();
	return stream;
}


ostream& operator<<(ostream& stream, Train& train)
{
	stream << "Train number: " << train.Number << endl;
	stream << "Srat Station: " << train.GetStartStation() << endl;
	stream << "Start time: " << train.GetStartTime() << endl;
	stream << "Finish Station: " << train.GetFinishStation() << endl;
	stream << "Finish time: " << train.GetFinishTime() << endl;
	return stream;
}