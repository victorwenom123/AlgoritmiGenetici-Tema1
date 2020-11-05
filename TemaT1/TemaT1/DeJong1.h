#pragma once
class DeJong1
{
double a, b;
int n, nrbiti, d, zece_la_d;
double x_valori[10001];
bool v[100001], vc[100001], vn[100001], best[100001];
public:
	DeJong1();
	DeJong1(int dim);
	void Initializare(bool sir[]);
	double DeJong1Functie();
	void Decodificare(bool sir[]);
	void Random_v();
	void HillClimbingFirst();
	void HillClimbingBest();
	void SimulatedAnnealing();
	void Afisare();
};

