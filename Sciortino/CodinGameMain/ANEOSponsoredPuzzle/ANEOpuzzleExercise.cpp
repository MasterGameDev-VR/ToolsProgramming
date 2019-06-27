#include "stdafx.h"
#include "ANEOpuzzleExercise.h"

using namespace std;

ANEOpuzzleExercise::ANEOpuzzleExercise(std::string fileName)
{
	// loading data...
	ifstream inputFile;
	inputFile.open(fileName);
	filebuf* inputbuf = inputFile.rdbuf();
	streambuf* cinbuffer = cin.rdbuf(inputFile.rdbuf());
	cin >> speed;
	cin.ignore();
	cin >> lightCount; cin.ignore();


	for (int i = 0; i < lightCount; i++) {
		int distance;
		int duration;
		cin >> distance >> duration; cin.ignore();
		distances.push_back(distance);
		durations.push_back(duration);
	}
}

ANEOpuzzleExercise::~ANEOpuzzleExercise()
{
}

//, std::allocator<float>
//, std::allocator<int>

bool ANEOpuzzleExercise::CheckIfTheIthTrafficLightIsRed(const int distance,  const int duration,const int speed)
{
	// questo metodo deve ritornare true solo se il tempo di arrivo NON è compreso in uno
	// degli intervalli di tempo
	// da 0 a duration, da 2 * duration a 3* duration, da 4 * duration a 5 * duration
	
	//distance /( speed /(18/5)) = distance / speed_in_mpersec = arrivaltime
	//condizione da inserire:  si divide per il doppio della durata del verde e si considera il resto
	// (18* distance ) / (5 * speed ) % (2 * duration ) <= duration
	//per evitare confronti tra float si moltiplica tutto per (5* speed)

	if ((18 * distance) % (2 * duration * (5 * speed)) < duration * (5 * speed))
	{
		return false;
	}
	else
	{
		return true;
	}
	
	
}
void ANEOpuzzleExercise::Execute() {
	
	//speed unit conversion ( meters per second)
	float speed_mpersec = speed / 3.6f;
	
	bool found_max_speed = false;
	int lowest_speed = 3;

	while (!found_max_speed && speed >= lowest_speed) {
		/*
		std::cout << speed << "   "; std::cout << speed_mpersec << std::endl;
		std::cout << std::endl << std::endl;
		*/
		/*
		//calculate arrival times
		std::vector<float> arrivalTimes;
		for (std::vector<int>::reverse_iterator itDists = distances.rbegin(); itDists != distances.crend(); ++itDists) {

			float arrivalTime = (*itDists) / speed_mpersec;
			arrivalTimes.push_back(arrivalTime);
		}
		for (unsigned int i = 0; i < arrivalTimes.size(); i++) {
			std::cout << arrivalTimes[i] << "  ";
		}*/
		
		//compare arrival times with durations
		//arrival times are stored in reverse order, from the last traffic light one to the first t.l. one
		//so the first one is compared with the last duration
		bool speed_has_been_reduced=false;
		for (unsigned int i = 0; i < distances.size(); i++) {
			if (CheckIfTheIthTrafficLightIsRed(distances[i], durations[i], speed))
			{
				speed--;
				speed_mpersec = speed / 3.6f;
				speed_has_been_reduced = true;
				break;
			}
			
		}

		if (!speed_has_been_reduced)
		{
			found_max_speed = true;
		}
	}
	std::string answer;
	if (found_max_speed) 
	{
		answer.append("the maximum speed is " + to_string(speed_mpersec)+ " m/s equivalent to " + to_string(speed)+" km/h ");
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
