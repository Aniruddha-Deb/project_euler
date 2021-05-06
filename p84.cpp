#include <bits/stdc++.h>
using namespace std;

#define JAIL 10
#define GO 0
#define C1 11
#define E3 24
#define H2 39
#define R1 5
#define RN -10
#define UN -20
#define BACK_3 -3
#define NON -1

#define CC1 2
#define CC2 17
#define CC3 33

#define CH1 7
#define CH2 22
#define CH3 36

static random_device rd;
static mt19937 rng{rd()}; 

int dice() {
	static uniform_int_distribution<int> uid(1,4);
	return uid(rng);
}

int main() {
	
	vector<int> P(40,0);

	for (int i=0; i<10; i++) {
		cout << dice() << endl;
	}

	deque<int> CC;
	deque<int> CH;

	for (int i=0; i<14; i++) {
		CC.push_front(NON);
	}
	CC.push_front(JAIL);
	CC.push_front(GO);

	for (int i=0; i<6; i++) {
		CH.push_front(NON);
	}
	CH.push_front(JAIL);
	CH.push_front(GO);
	CH.push_front(C1);
	CH.push_front(E3);
	CH.push_front(H2);
	CH.push_front(R1);
	CH.push_front(RN);
	CH.push_front(RN);
	CH.push_front(UN);
	CH.push_front(BACK_3);

	for (int i : CH) cout << i << endl;
	random_shuffle(CH.begin(), CH.end());
	for (int i : CH) cout << i << endl;
	random_shuffle(CC.begin(), CC.end());

	bool pd = false;
	bool ppd = false;
	int cpos = 0;
	for (int i=0; i<2000000; i++) {
		int d1 = dice();
		int d2 = dice();
		if (d1 == d2) {
			if (pd) {
				if (ppd) {
					P[JAIL]++;
					cpos = JAIL;
					continue;
				}
				else ppd = pd;
			}
			else pd = true;
		}
		else {
			pd = false;
			ppd = false;
		}
		
		int tcpos = (cpos+d1+d2)%40;
		if (tcpos == CC1 || tcpos == CC2 || tcpos == CC3) {
			int cc = CC.front();
			if (cc != NON) tcpos = cc;
			CC.pop_front();
			CC.push_back(cc);
		}
		else if (tcpos == CH1 || tcpos == CH2 || tcpos == CH3) {
			int ch = CH.front();
			if (ch == RN) {
				tcpos = (tcpos/10)*10+5;
				cout << "Going to railway " << tcpos << endl;
			}
			else if (ch == UN) {
				if (tcpos > 28 || tcpos < 12) tcpos = 12;
				else tcpos = 28;
			}
			else if (ch == BACK_3) {
				tcpos -= 3;
				if (tcpos < 0) tcpos += 40;
			}
			else if (ch != NON) {
				tcpos = ch;
			}
			CH.pop_front();
			CH.push_back(ch);
		}
		else if (tcpos == 30) {
			// go to jail
			tcpos = JAIL;
		}
		
		cpos = tcpos;
		P[cpos]++;
		if (i%1000 == 0) cout << ".";
		if (i%10000 == 0) cout << endl;
	}

	for (int i=0; i<40; i++) {
		cout << i << ":" << P[i] << endl;
	}

	return 0;
}
