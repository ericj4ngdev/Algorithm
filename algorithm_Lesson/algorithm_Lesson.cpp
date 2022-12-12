#include <iostream>
#include <vector>
using namespace std;


int R() {
	int N = 10;
	return  rand() % N;
}

int main()
{
	int M = 20;
	vector<int> mini(20, 0);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < M; i++)
		mini[i] = min(R(), R(), R());

	return 0;
}