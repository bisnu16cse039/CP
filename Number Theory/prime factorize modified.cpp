following list.

sp(2n)=2, sp(3)=3, sp(5)=5, sp(7)=7, sp(9)=3, sp(11)=11, sp(13)=13, sp(15)=3, sp(17)=17, sp(19)=19, sp(21)=3, sp(23)=23, sp(25)=5, sp(27)=3, sp(29)=29.

Then the factorization is very simple. The optimization is needed only once, when the Sieve() function runs.

bool v[MAX];
int len, sp[MAX];

void Sieve(){
	for (int i = 2; i < MAX; i += 2)	sp[i] = 2;//even numbers have smallest prime factor 2
	for (lli i = 3; i < MAX; i += 2){
		if (!v[i]){
			sp[i] = i;
			for (lli j = i; (j*i) < MAX; j += 2){
				if (!v[j*i])	v[j*i] = true, sp[j*i] = i;
			}
		}
	}
}

int main(){
	Sieve();
	for (int i = 0; i < 50; i++)	cout << sp[i] << endl;

    return 0;
}
