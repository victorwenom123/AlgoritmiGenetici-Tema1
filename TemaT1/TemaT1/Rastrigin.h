#pragma once
class Rastrigin
{
	double a, b;
	int n, nrbiti, d, zece_la_d;
	double x_valori[101];
	bool v[1001], vc[1001], vn[1001], best[1001];
public:
	Rastrigin();
	Rastrigin(int dim);
	double RastriginFunctie();
	void Decodificare(bool sir[]);
	void Random_v();
	void HillClimbingFirst();
	void HillClimbingBest();
	void SimulatedAnnealing();
	void Afisare();
};

