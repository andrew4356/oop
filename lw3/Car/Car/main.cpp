#include "stdafx.h"
#include "Car.h"
#include "Car_f.h"

using namespace std;

void CommandAnalysis(string const & comm, stringstream & buffer)
{
	CCar car;
	if (comm == "Info")
	{
		cout << "Answer:\n";
		GetInfo(cout, car);
	}
	else 
		if ((comm == "EngineOn") || (comm == "engineOn") || (comm == "ENGINEON") || (comm == "Engineon")
		|| (comm == "engineon"))
		{
			cout << "Answer:\n";
			EngineOn(cout, car);
		}
		else 
			if ((comm == "EngineOff") || (comm == "engineOff") || (comm == "ENGINEOFF") || (comm == "EngineoFF")
			|| (comm == "engineoff"))
			{
				cout << "Answer:\n";
				EngineOff(cout, car);
			}
		else
			if ((comm == "SetGear") || (comm == "setgear") || (comm == "SETGEAR") || (comm == "Setgear"))
			{
				int value = 0;
				cout << "Answer:\n";
				if (buffer >> value)
				{
					if ((value >= -1) && (value <= 5))
					{
						if (SetGear(car, value))
						{
							cout << "	Gear " << value << " succesfuly set\n";
						}
						else 
							if (!car.IsEngineOn())
							{
								cout << "	Gear can not be set\n"
									<< "	Engine is off\n";
							}
						else 
							if ((car.GetDirection() == Direction::back) && (value > 0) || ((car.GetDirection() == Direction::forward)
							&& (value < 0)))
							{
								cout << "	Gear can not be set\n"
									<< "	Car moves in opposite direction\n";
							}
						else
						{
							cout << "	Gear can not be set\n"
								<< "	Wrong speed\n";
						}
					}
					else
					{
						cout << "	Gear must be -1 to 5\n";
					}
				}
				else
				{
					cout << "	Invalid value\n"
						<< "	Use command: SetGear <value>\n";
				}
			}
	else 
		if ((comm == "SetSpeed") || (comm == "setspeed") || (comm == "Setspeed") || (comm == "setSpeed")
		|| (comm == "SETSPEED"))
		{
			int value = 0;
			cout << "Answer:\n";
			if (buffer >> value)
			{
				if ((value >= 0) && (value <= 150))
				{
					if (SetSpeed(car, value))
					{
						cout << "	Speed " << value << " succesfuly set\n";
					}
					else 
						if (!car.IsEngineOn())
						{
							cout << "	Speed can not be set\n"
								<< "	Engine is off\n";
						}
					else
					{
						cout << "	Speed can not be set\n"
							<< "	Wrong gear\n"
							<< "	Speed must be 0 to 20 on R gear\n"
							<< "	Speed must be 0 on N gear\n"
							<< "	Speed must be 0 to 30 on 1 gear\n"
							<< "	Speed must be 20 to 50 on 2 gear\n"
							<< "	Speed must be 30 to 60 on 3 gear\n"
							<< "	Speed must be 40 to 90 on 4 gear\n"
							<< "	Speed must be 50 to 150 on 5 gear\n";
					}
				}
				else
				{
					cout << "	Value must be 0 to 150\n";
				}
			}
			else
			{
				cout << "	Invalid value\n"
					<< "	Use command: SetSpeed <value>\n";
			}
		}
	else
	{
		cout << "	Unknown command.\n"
			<< "	Use commands: Info\n"
			<< "	SetGear <value>\n"
			<< "	SetSpeed <value>\n"
			<< "	EngineOn\n"
			<< "	EngineOff\n";
	}
}

int main()
{
	
	cout << "Hi, I'm a car. Sit down, let's ride.\n";
	while (!cin.eof())
	{
		cout << "Enter command: ";
		string command;
		getline(cin, command);
		stringstream buffer;
		buffer << command; 
		buffer >> command;
		CommandAnalysis(command, buffer);
	}
	return 0;
}

