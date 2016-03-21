#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int N;
int main(int argc, char *argv[])
{
	if(argc < 1)
	{
		cerr << "error" << endl;
		return 1;
	}
	N = atoi(argv[1]);
	cerr << N << endl;

	srand(time(0));
	FILE *topo = fopen("./data/topo.csv", "w");
	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 1; j <= min(8, N); ++j)
		{
			int id, u, v, w;
			id = cnt++;
			u = i;
			v = rand() % (N - 1);
			if(v == i) v = N - 1;
			w = rand() % 20 + 1;

			fprintf(topo, "%d,%d,%d,%d\n", id, u, v, w);
		}
	}
	fclose(topo);
	cerr << cnt << endl;
	
	FILE *demand = fopen("./data/demand.csv", "w");
	fprintf(demand, "%d,%d,%d", 0, N - 1, 1);
	for (int i = 2; i < min(50, N - 1); ++i)
	{
		fprintf(demand, "|%d", i);
	}
	fclose(demand);
	return 0;
}
