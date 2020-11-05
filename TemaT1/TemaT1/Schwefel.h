#pragma once
class Schwefel
{
	double a, b;
	int n, nrbiti, d, zece_la_d;
	double x_valori[101];
	bool v[1001], vc[1001], vn[1001], best[1001];
public:
	Schwefel();
	Schwefel(int dim);
	double SchwefelFunctie();
	void Decodificare(bool sir[]);
	void Random_v();
	void HillClimbingFirst();
	void HillClimbingBest();
	void SimulatedAnnealing();
	void Afisare();
};
