#include "stdafx.h"
#include "ANEOpuzzleExercise.h"

using namespace std;

ANEOpuzzleExercise::ANEOpuzzleExercise(std::string fileName)
{
	ifstream inputFile(fileName);
	filebuf* inputbuf = inputFile.rdbuf();
	cin.clear();
	auto cinbuffer = cin.rdbuf(inputFile.rdbuf());
}

ANEOpuzzleExercise::~ANEOpuzzleExercise()
{
}

//, std::allocator<float>
//, std::allocator<int>

bool ANEOpuzzleExercise::CheckIfTheIthTrafficLightIsGreen(std::vector<float>& arrivalTimes, std::vector<int>& durations,unsigned int i)
{
	// questo metodo deve ritornare true solo se il tempo di arrivo NON è compreso in uno
	// degli intervalli di tempo
	// da 0 a duration, da 2 * duration a 3* duration, da 4 * duration a 5 * duration
	int last_interval_to_check = 0;
	while (arrivalTimes[i] > last_interval_to_check *durations[durations.size() - 1 - i])
	{
		last_interval_to_check += 1;
	}
	if (last_interval_to_check % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}
void ANEOpuzzleExercise::Execute() {
	// loading data...
	int speed;
	cin >> speed; cin.ignore();
	int lightCount;
	cin >> lightCount; cin.ignore();
	std::vector<int> distances;
	std::vector<int> durations;

	for (int i = 0; i < lightCount; i++) {
		int distance;
		int duration;
		cin >> distance >> duration; cin.ignore();
		distances.push_back(distance);
		durations.push_back(duration);
	}
	//speed unit conversion ( meters per second)
	float speed_mpersec = speed / 3.6f;

	bool found_max_speed = false;
	int lowest_speed = 3;

	while (!found_max_speed && speed >= lowest_speed) {


		//calculate arrival times
		std::vector<float> arrivalTimes;
		for (std::vector<int>::reverse_iterator itDists = distances.rbegin(); itDists != distances.crend(); ++itDists) {

			float arrivalTime = (*itDists) / speed_mpersec;
			arrivalTimes.push_back(arrivalTime);
		}

		//compare arrival times with durations
		//arrival times are stored in reverse order, from the last traffic light one to the first t.l. one
		//so the first one is compared with the last duration
		bool speed_has_been_reduced=false;
		for (unsigned int i = 0; i < arrivalTimes.size(); i++) {
			//arrivalTimes[i] > durations[durations.size() - 1 - i]
			if (CheckIfTheIthTrafficLightIsGreen(arrivalTimes, durations, i))
			{
				speed--;
				speed_mpersec = speed / 3.6f;
				speed_has_been_reduced = true;
				break;
			}
			/*
			if (arrivalTimes[i] > durations[durations.size() - 1 - i])
			{
				int reduction_factor = 2;
				float speed_mpersec_new= speed_mpersec+0.2f;
				while (speed_mpersec_new >= speed_mpersec)
				{
					speed_mpersec_new = (float) distances[durations.size() - 1 - i] / (reduction_factor *durations[durations.size() - 1 - i]);
					reduction_factor += 2;
				}
				speed_mpersec = speed_mpersec_new;
				speed = (int) (speed_mpersec *3.6f);
				speed_has_been_reduced = true;
				break;	
			}
			*/
		}

		if (!speed_has_been_reduced)
		{
			found_max_speed = true;
		}
	}
	std::string answer;
	if (found_max_speed) 
	{
		answer.append("the maximum speed is " + to_string(speed_mpersec)+ " m/s approximated by " + to_string(speed)+" km/h ");
	}
	else 
	{
		answer.append("speed not found because it is too low: " + to_string(speed_mpersec) + " m/s approximated by " + to_string(speed) + " km/h ");

	}

	/*
	è necessario
	1) calcolare il tempo impiegato dalla macchina a raggiungere ciascuna delle distanze, in secondi, usando la velocità massima

	2) se questo tempo è minore del tempo impiegato dal semaforo a far scattare il rosso, allora si passa al semaforo successivo
	3) altrimenti si calcola una nuova velocità
	4) la nuova velocità è calcolata raddoppiando il tempo di arrivo al semaforo che non viene raggiunto in tempo
	*/
	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;

	std::cout << answer << std::endl;
}
