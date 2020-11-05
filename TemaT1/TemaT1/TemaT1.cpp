#include <iostream>
#include <cstdlib>
#include <math.h>
#include "Rastrigin.h"
#include "Michalewicz.h"
#include "DeJong1.h"
#include "Schwefel.h"
#include <iomanip>
#include <ctime>
#include <random>
#include <chrono>
#include <cstdlib>
double vec[1001],DS=0;
using namespace std;
void MichalewiczHillClimbingFirst(double& MIN, double& min, int iteratii, int n, double &AVG)
{Michalewicz f(n);
srand(time(NULL));
	for (int i = 0; i < iteratii; ++i)
	{
		//cout << "Hillclimbing First:" << '\n';
		f.HillClimbingFirst();
		vec[i] = f.MichalewiczFunctie();
		if (MIN < f.MichalewiczFunctie())
			MIN = f.MichalewiczFunctie();
		if (min > f.MichalewiczFunctie())
			min = f.MichalewiczFunctie();
		AVG += f.MichalewiczFunctie();
	}
	AVG /= iteratii;
	for (int j = 0; j < n; j++)
		DS += (vec[j] - AVG) * (vec[j] - AVG);
	DS /= iteratii;
	DS = double(sqrt(double(DS)));
}
void MichalewiczHillClimbingBest(double &MIN, double &min, int iteratii,  int n, double &AVG)
{
	Michalewicz f(n);
	srand(time(NULL));
	for (int i = 0; i < iteratii; ++i)
	{
		//cout << "Hillclimbing First:" << '\n';
		f.HillClimbingBest();
		vec[i] = f.MichalewiczFunctie();
		if (MIN < f.MichalewiczFunctie())
			MIN = f.MichalewiczFunctie();
		if (min > f.MichalewiczFunctie())
			min = f.MichalewiczFunctie();
		AVG += f.MichalewiczFunctie();
	}
	AVG /= iteratii;
	for (int j = 0; j < n; j++)
		DS += (vec[j] - AVG) * (vec[j] - AVG);
	DS /= iteratii;
	DS = double(sqrt(double(DS)));
}
void MichalewiczSimulatedAnnealing(double& MIN, double& min, int iteratii, int n, double &AVG)
{
	
	Michalewicz f(n);
	srand(time(NULL));
	for (int i = 0; i < iteratii; ++i)
	{
		//cout << "Hillclimbing First:" << '\n';
		f.SimulatedAnnealing();
		vec[i] = f.MichalewiczFunctie();
		if (MIN < f.MichalewiczFunctie())
			MIN = f.MichalewiczFunctie();
		if (min > f.MichalewiczFunctie())
			min = f.MichalewiczFunctie();
		AVG += f.MichalewiczFunctie();
	}
	AVG /= iteratii;
	for (int j = 0; j < n; j++)
		DS += (vec[j] - AVG) * (vec[j] - AVG);
	DS /= iteratii;
	DS = double(sqrt(double(DS)));
}
void DeJong1HillClimbingFirst(double& MIN, double& min, int iteratii, int n, double &AVG)
{
	DeJong1 f(n);
	srand(time(NULL));
	for (int i = 0; i < iteratii; ++i)
	{
		//cout << "Hillclimbing First:" << '\n';
		f.HillClimbingFirst();
		vec[i] = f.DeJong1Functie();
		if (MIN < f.DeJong1Functie())
			MIN = f.DeJong1Functie();
		if (min > f.DeJong1Functie())
			min = f.DeJong1Functie();
		AVG += f.DeJong1Functie();
	}
	AVG /= iteratii;
	for (int j = 0; j < n; j++)
		DS += (vec[j] - AVG) * (vec[j] - AVG);
	DS /= iteratii;
	DS = double(sqrt(double(DS)));
}
void DeJong1HillClimbingBest(double& MIN, double& min, int iteratii, int n, double &AVG)
{
	DeJong1 f(n);
	srand(time(NULL));
	for (int i = 0; i < iteratii; ++i)
	{
		//cout << "Hillclimbing First:" << '\n';
		f.HillClimbingBest();
		vec[i] = f.DeJong1Functie();
		if (MIN < f.DeJong1Functie())
			MIN = f.DeJong1Functie();
		if (min > f.DeJong1Functie())
			min = f.DeJong1Functie();
		AVG += f.DeJong1Functie();
	}
	AVG /= iteratii;
	for (int j = 0; j < n; j++)
		DS += (vec[j] - AVG) * (vec[j] - AVG);
	DS /= iteratii;
	DS = double(sqrt(double(DS)));
}
void DeJong1SimulatedAnnealing(double& MIN, double& min, int iteratii, int n, double &AVG)
{
	DeJong1 f(n);
	srand(time(NULL));
	for (int i = 0; i < iteratii; ++i)
	{
		//cout << "Hillclimbing First:" << '\n';
		f.SimulatedAnnealing();
		vec[i] = f.DeJong1Functie();
		if (MIN < f.DeJong1Functie())
			MIN = f.DeJong1Functie();
		if (min > f.DeJong1Functie())
			min = f.DeJong1Functie();
		AVG += f.DeJong1Functie();
	}
	AVG /= iteratii;
	for (int j = 0; j < n; j++)
		DS += (vec[j] - AVG) * (vec[j] - AVG);
	DS /= iteratii;
	DS = double(sqrt(double(DS)));
}

void RastriginHillClimbingFirst(double& MIN, double& min, int iteratii, int n, double &AVG)
{
	srand(time(NULL));
	Rastrigin f(n);
	for (int i = 0; i < iteratii; ++i)
	{
		//cout << "Hillclimbing First:" << '\n';
		f.HillClimbingFirst();
		vec[i] = f.RastriginFunctie();
		if (MIN < f.RastriginFunctie())
			MIN = f.RastriginFunctie();
		if (min > f.RastriginFunctie())
			min = f.RastriginFunctie();
		AVG += f.RastriginFunctie();
	}
	AVG /= iteratii;
	for (int j = 0; j < n; j++)
		DS += (vec[j] - AVG) * (vec[j] - AVG);
	DS /= iteratii;
	DS = double(sqrt(double(DS)));
}
void RastriginHillClimbingBest(double& MIN, double& min, int iteratii, int n, double &AVG)
{
	srand(time(NULL));
	Rastrigin f(n);
	for (int i = 0; i < iteratii; ++i)
	{
		//cout << "Hillclimbing First:" << '\n';
		f.HillClimbingBest();
		vec[i] = f.RastriginFunctie();
		if (MIN < f.RastriginFunctie())
			MIN = f.RastriginFunctie();
		if (min > f.RastriginFunctie())
			min = f.RastriginFunctie();
		AVG += f.RastriginFunctie();
	}
	AVG /= iteratii;
	for (int j = 0; j < n; j++)
		DS += (vec[j] - AVG) * (vec[j] - AVG);
	DS /= iteratii;
	DS = double(sqrt(double(DS)));
}
void RastriginSimulatedAnnealing(double& MIN, double& min, int iteratii, int n, double &AVG)
{
	srand(time(NULL));
	Rastrigin f(n);
	for (int i = 0; i < iteratii; ++i)
	{
		//cout << "Hillclimbing First:" << '\n';
		f.SimulatedAnnealing();
		vec[i] = f.RastriginFunctie();
		if (MIN < f.RastriginFunctie())
			MIN = f.RastriginFunctie();
		if (min > f.RastriginFunctie())
			min = f.RastriginFunctie();
		AVG += f.RastriginFunctie();
	}
	AVG /= iteratii;
	for (int j = 0; j < n; j++)
		DS += (vec[j] - AVG) * (vec[j] - AVG);
	DS /= iteratii;
	DS = double(sqrt(double(DS)));
}
void SchwefelHillClimbingFirst(double& MIN, double& min, int iteratii, int n, double &AVG)
{
	srand(time(NULL));
	Schwefel f(n);
	for (int i = 0; i < iteratii; ++i)
	{
		//cout << "Hillclimbing First:" << '\n';
		f.HillClimbingFirst();
		vec[i] = f.SchwefelFunctie();
		if (MIN < f.SchwefelFunctie())
			MIN = f.SchwefelFunctie();
		if (min > f.SchwefelFunctie())
			min = f.SchwefelFunctie();
		AVG += f.SchwefelFunctie();
	}
	AVG /= iteratii;
	for (int j = 0; j < n; j++)
		DS += (vec[j] - AVG) * (vec[j] - AVG);
	DS /= iteratii;
	DS = double(sqrt(double(DS)));
}
void SchwefelHillClimbingBest(double& MIN, double& min, int iteratii, int n, double &AVG)
{
	srand(time(NULL));
	Schwefel f(n);
	for (int i = 0; i < iteratii; ++i)
	{
		//cout << "Hillclimbing First:" << '\n';
		f.HillClimbingBest();
		vec[i] = f.SchwefelFunctie();
		if (MIN < f.SchwefelFunctie())
			MIN = f.SchwefelFunctie();
		if (min > f.SchwefelFunctie())
			min = f.SchwefelFunctie();
		AVG += f.SchwefelFunctie();
	}
	AVG /= iteratii;
	for (int j = 0; j < n; j++)
		DS += (vec[j] - AVG) * (vec[j] - AVG);
	DS /= iteratii;
	DS = double(sqrt(double(DS)));
}
void SchwefelSimulatedAnnealing(double& MIN, double& min, int iteratii, int n, double &AVG)
{
	srand(time(NULL));
	Schwefel f(n);
	for (int i = 0; i < iteratii; ++i)
	{
		//cout << "Hillclimbing First:" << '\n';
		f.SimulatedAnnealing();
		vec[i] = f.SchwefelFunctie();
		if (MIN < f.SchwefelFunctie())
			MIN = f.SchwefelFunctie();
		if (min > f.SchwefelFunctie())
			min = f.SchwefelFunctie();
		AVG += f.SchwefelFunctie();
	}
	AVG /= iteratii;
	for (int j = 0; j < n; j++)
		DS += (vec[j] - AVG) * (vec[j] - AVG);
	DS /= iteratii;
	DS = double(sqrt(double(DS)));
}

int main()
{

	int n, iteratii;
	double min = INT_MAX, MIN = INT_MIN, AVG = 0;
	char alegere;
	//cout << "Alegeti functia si algoritmul:\nAlegeri: \nA (DeJong1HCF) \nB (DeJong1HCB) \nC (DeJong1SA) \nD (SchwefelHCF) \nE (SchwefelHCB) \nF (SchwefelSA) \nG (MichalewiczHCF) \nH (MichalewiczHCB) \nI (MichalewiczSA) \nJ (RastriginHCF) \nK (RastriginHCB) \nL (RastriginSA) \n";
	//cin >> alegere;
	cout << "Ati ales functia si metoda!\n";
	cout << "Alegeti dimensiunea functiei:\n";
	cin >> n;
	cout << "Alegeti nr. de rulari:\n";
	cin >> iteratii;
	//switch (alegere) {
	//case 'A':
		auto nr1 = chrono::high_resolution_clock::now();
		RastriginHillClimbingFirst(MIN, min, iteratii, n, AVG);
		//RastriginHillClimbingBest(MIN, min, iteratii, n, AVG);
		//RastriginSimulatedAnnealing(MIN, min, iteratii, n, AVG);
		//SchwefelSimulatedAnnealing(MIN, min, iteratii, n, AVG);
		//RastriginHillClimbingFirst(MIN, min, iteratii, n, AVG);
		//SchwefelHillClimbingBest(MIN, min, iteratii, n, AVG);
		//DeJong1HillClimbingFirst(MIN, min, iteratii, n, AVG);
		//DeJong1HillClimbingBest(MIN, min, iteratii, n, AVG);
		//DeJong1SimulatedAnnealing(MIN, min, iteratii, n, AVG);
		//Schewfel1HillClimbingFirst(MIN, min, iteratii, n, AVG);
		//MichalewiczHillClimbingBest(MIN, min, iteratii, n, AVG);
		//MichalewiczSimulatedAnnealing(MIN, min, iteratii, n, AVG);
		auto nr2 = chrono::high_resolution_clock::now();
		auto dif = nr2 - nr1;
		auto timp = chrono::duration_cast<std::chrono::seconds>(dif).count();
		cout << setprecision(4) << fixed << min << ' ' << MIN << ' ' << AVG << ' ' << DS << ' ' << timp << " secunde";
	//	break;
	//}
	/*switch (alegere) {
	case 'A':
		//auto nr1 = chrono::high_resolution_clock::now();
		DeJong1HillClimbingFirst(MIN, min, iteratii, n, AVG);
		//auto nr2 = chrono::high_resolution_clock::now();
		//auto dif = nr2 - nr1;
		//auto timp = chrono::duration_cast<std::chrono::seconds>(dif).count();
		cout << setprecision(4) << fixed << min << ' ' << MIN << ' ' << AVG << ' ' << DS ; //<< ' ' << timp << " secunde";
		break;
	


	case 'B':
		//auto nr1 = chrono::high_resolution_clock::now();
		DeJong1HillClimbingBest(MIN, min, iteratii, n, AVG);
		//auto nr2 = chrono::high_resolution_clock::now();
		//auto dif = nr2 - nr1;
		//auto timp = chrono::duration_cast<std::chrono::seconds>(dif).count();
		cout << setprecision(4) << fixed << min << ' ' << MIN << ' ' << AVG << ' ' << DS; // << ' ' <<  " secunde";
		break;
}
	case 'C':
		//auto nr1 = chrono::high_resolution_clock::now();
		DeJong1SimulatedAnnealing(MIN, min, iteratii, n, AVG);
		//auto nr2 = chrono::high_resolution_clock::now();
		//auto dif = nr2 - nr1;
		//auto timp = chrono::duration_cast<std::chrono::seconds>(dif).count();
		cout << setprecision(4) << fixed << min << ' ' << MIN << ' ' << AVG << ' ' << DS; // << ' ' << timp << " secunde";
		break;
	case 'D':
		//auto nr1 = chrono::high_resolution_clock::now();
		SchwefelHillClimbingFirst(MIN, min, iteratii, n, AVG);
		//auto nr2 = chrono::high_resolution_clock::now();
		//auto dif = nr2 - nr1;
		//auto timp = chrono::duration_cast<std::chrono::seconds>(dif).count();
		cout << setprecision(4) << fixed << min << ' ' << MIN << ' ' << AVG << ' ' << DS; // << ' ' << timp << " secunde";
		break;
	case 'E':
		//auto nr1 = chrono::high_resolution_clock::now();
		SchwefelHillClimbingBest(MIN, min, iteratii, n, AVG);
		//auto nr2 = chrono::high_resolution_clock::now();
		//auto dif = nr2 - nr1;
		//auto timp = chrono::duration_cast<std::chrono::seconds>(dif).count();
		cout << setprecision(4) << fixed << min << ' ' << MIN << ' ' << AVG << ' ' << DS; // << ' ' << timp << " secunde";
		break;
	case 'F':
		//auto nr1 = chrono::high_resolution_clock::now();
		SchwefelSimulatedAnnealing(MIN, min, iteratii, n, AVG);
		//auto nr2 = chrono::high_resolution_clock::now();
		//auto dif = nr2 - nr1;
		//auto timp = chrono::duration_cast<std::chrono::seconds>(dif).count();
		cout << setprecision(4) << fixed << min << ' ' << MIN << ' ' << AVG << ' ' << DS; // << ' ' << timp << " secunde";
		break;
	case 'G':
		//auto nr1 = chrono::high_resolution_clock::now();
		MichalewiczHillClimbingFirst(MIN, min, iteratii, n, AVG);
		//auto nr2 = chrono::high_resolution_clock::now();
		//auto dif = nr2 - nr1;
		//auto timp = chrono::duration_cast<std::chrono::seconds>(dif).count();
		cout << setprecision(4) << fixed << min << ' ' << MIN << ' ' << AVG << ' ' << DS; //<< ' ' << timp << " secunde";
		break;
	case 'H':
		//auto nr1 = chrono::high_resolution_clock::now();
		MichalewiczHillClimbingBest(MIN, min, iteratii, n, AVG);
		//auto nr2 = chrono::high_resolution_clock::now();
		//auto dif = nr2 - nr1;
		//auto timp = chrono::duration_cast<std::chrono::seconds>(dif).count();
		cout << setprecision(4) << fixed << min << ' ' << MIN << ' ' << AVG << ' ' << DS; // << ' ' << timp << " secunde";
		break;
	case 'I':
		//auto nr1 = chrono::high_resolution_clock::now();
		MichalewiczSimulatedAnnealing(MIN, min, iteratii, n, AVG);
		//auto nr2 = chrono::high_resolution_clock::now();
		//auto dif = nr2 - nr1;
		//auto timp = chrono::duration_cast<std::chrono::seconds>(dif).count();
		cout << setprecision(4) << fixed << min << ' ' << MIN << ' ' << AVG << ' ' << DS; // << ' ' << timp << " secunde";
		break;
	case 'J':
		//auto nr1 = chrono::high_resolution_clock::now();
		RastriginHillClimbingFirst(MIN, min, iteratii, n, AVG);
		//auto nr2 = chrono::high_resolution_clock::now();
		//auto dif = nr2 - nr1;
		//auto timp = chrono::duration_cast<std::chrono::seconds>(dif).count();
		cout << setprecision(4) << fixed << min << ' ' << MIN << ' ' << AVG << ' ' << DS; // << ' ' << timp << " secunde";
		break;
	case 'K':
		//auto nr1 = chrono::high_resolution_clock::now();
		RastriginHillClimbingBest(MIN, min, iteratii, n, AVG);
		//auto nr2 = chrono::high_resolution_clock::now();
		//auto dif = nr2 - nr1;
		//auto timp = chrono::duration_cast<std::chrono::seconds>(dif).count();
		cout << setprecision(4) << fixed << min << ' ' << MIN << ' ' << AVG << ' ' << DS; // << ' ' << timp << " secunde";
		break;
	case 'L':
		//auto nr1 = chrono::high_resolution_clock::now();
		RastriginSimulatedAnnealing(MIN, min, iteratii, n, AVG);
		//auto nr2 = chrono::high_resolution_clock::now();
		//auto dif = nr2 - nr1;
		//auto timp = chrono::duration_cast<std::chrono::seconds>(dif).count();
		cout << setprecision(4) << fixed << min << ' ' << MIN << ' ' << AVG << ' ' << DS; // << ' ' << timp << " secunde";
		break;
	}*/


	return 0;
}