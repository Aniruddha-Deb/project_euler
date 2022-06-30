#include <iostream>
#include <cmath>
#include 
#include <bitset>
#include <algorithm>

using namespace std;

#define N 100000000

bool is_prime(int n) {
	for (int i=2; i<(int)(sqrt(n)+1); i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;

	vector<int> v(n);

	map<int,int> m;

	m
}

int main() {

	cout << "started" << endl;
	
	bitset<N+5> *A = new bitset<N+5>();

	for (int i=2; i*i <= N; i++) {
		for (int j=1; i*i*j <= N; j++) {
			A->set(i*i*j);
		}
	}

	long sum = 0;

	for (int i=2; i <= N; i++) {
		if ((*A)[i] == false && i%2 == 0 && is_prime(i+1)) {
			sum += i;
		}
	}

	cout << sum << endl;

	delete A;
	return 0;
}
