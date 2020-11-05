#define pi 3.14159
#include "Rastrigin.h"
#include <time.h>
#include <iostream>
#include <random>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
Rastrigin::Rastrigin()
{}
double Rastrigin::RastriginFunctie()
{
	double s;
	s = 10 * n;
	for (int i = 0; i < n; ++i)
		s += x_valori[i] * x_valori[i]-10*cos(2*pi*x_valori[i]);
	return s;
}

Rastrigin::Rastrigin(int dim)
{
	n = dim;
	a = -5.12;
	b = 5.12;
	d = 5;
	zece_la_d = 10000;
	n = dim;
}

void Rastrigin::Random_v()
{
	double N = double((b - a)) * double(zece_la_d);
	nrbiti = ceil(log2(N));
	//srand(time(NULL));
	for (int i = 0; i < nrbiti * n; ++i)
		v[i] = rand() % 2;
}

void Rastrigin::Decodificare(bool sir[])
{
	double xdecimal, xreal;
	for (int i = 0; i < n; ++i)
	{
		xdecimal = 0;
		for (int j = i * nrbiti; j < nrbiti * (i + 1); ++j)
			xdecimal = 2 * xdecimal + sir[j];
		xreal = a + double(double(xdecimal) * double((b - a))) / double(pow(2, nrbiti) - 1);
		x_valori[i] = xreal;
	}

}
void Rastrigin::HillClimbingFirst()
{
	bool local;
	double potentialmin,min;
	for (int iteratii = 0; iteratii < 200; ++iteratii)
	{
		Random_v();
		if (iteratii == 0)
			copy(v, v + n * nrbiti, best);
		copy(v, v + n * nrbiti, vc);
		do
		{copy(vc, vc + n * nrbiti, vn);
			local = 0;
			for (int i = 0; i < n * nrbiti; ++i)
			{
				Decodificare(vc);
				min = RastriginFunctie();
				if (vn[i] == 1)
					vn[i] = 0;
				else
					vn[i] = 1;
				Decodificare(vn);
				if (RastriginFunctie() < min)
				{
					local = 1;
					copy(vn, vn + n * nrbiti, vc);
					break;
				}
				if (vn[i] == 1)
					vn[i] = 0;
				else
					vn[i] = 1;
			}
		} while (local);
		Decodificare(vc);
		potentialmin = RastriginFunctie();
		Decodificare(best);
		if (RastriginFunctie() > potentialmin)
			copy(vc, vc + n * nrbiti, best);
	}
}
void Rastrigin::HillClimbingBest()
{
	bool local;
	double min,potentialmin;
	//double vsave;
	for (int iteratii = 0; iteratii < 200; ++iteratii)
	{
		Random_v();
		Decodificare(v);
		//for (int y = 0; y < n; y++)
			//cout << x_valori[y] << ' ';
		//cout << endl;
		if (iteratii == 0)
			copy(v, v + n * nrbiti, best);
		copy(v, v + n * nrbiti, vc);
		do
		{copy(vc, vc + n * nrbiti, vn);
			local = 0;
			for (int i = 0; i < n * nrbiti; ++i)
			{
				Decodificare(vc);
				min = RastriginFunctie();
				if (vn[i] == 1)
					vn[i] = 0;
				else
					vn[i] = 1;
				Decodificare(vn);
				if (RastriginFunctie() < min)
				{
					local = 1;
					copy(vn, vn + n * nrbiti, vc);
				}
				if (vn[i] == 1)
					vn[i] = 0;
				else
					vn[i] = 1;
			}
		} while (local);
		Decodificare(vc);
		potentialmin = RastriginFunctie();
		Decodificare(best);
		if (RastriginFunctie() > potentialmin)
			copy(vc, vc + n * nrbiti, best);
	}
}
void Rastrigin::SimulatedAnnealing()
{

	double T = 10000;
	bool local;
	//srand(time(NULL));
	Random_v();
	copy(v, v + n * nrbiti, vc);
	copy(v, v + n * nrbiti, best);
	int nrveciniparcursi;
	bool f[10001];
	do
	{nrveciniparcursi = 0;
		for (int param = 0; param < n*nrbiti; param++)
			f[param] = 0;
		do
		{
			local = false;
			int poz = rand() % (n * nrbiti);
			double min, Neighbor, Value;
			copy(vc, vc + n * nrbiti, vn);
			if (vn[poz] == 1)
				vn[poz] = 0;
			else
				vn[poz] = 1;
			Decodificare(vc);
			Value = RastriginFunctie();
			min = Value;
			Decodificare(vn);
			Neighbor = RastriginFunctie();
			if (Neighbor < min)
			{
				local = 1;
				copy(vn, vn + n * nrbiti, vc);
			}
			else
			{
				random_device r_d;
				mt19937 m_t(r_d());
				uniform_real_distribution<> d0(0, 1);
				double prob = d0(m_t);
				if (prob < exp(-abs(Neighbor - Value) / T))
				{
					local = 1;
					copy(vn, vn + n * nrbiti, vc);
				}
			}
			if (!local && !f[poz])
			{
				nrveciniparcursi++;
				f[poz] = 1;

			}
			
		} while (!local && nrveciniparcursi <n*nrbiti); // cand am parcurs toti vecinii sau am gasit un vecin favorabil gasirii minimului
		T = T * 0.91;
	} while (T >= 0.0000000000000000001);
	Decodificare(vc);
	copy(vc, vc + n * nrbiti, best);
	Decodificare(best);
}
void Rastrigin::Afisare()
{
	Decodificare(best);
	for (int i = 0; i < n * nrbiti; ++i)
		cout << best[i];
	cout << '\n';
	for (int i = 0; i < n; i++)
		cout << x_valori[i] << ' ';
	cout << '\n';
	cout << RastriginFunctie() << '\n';
}