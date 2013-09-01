#include <iostream>
#include <cstdio>

#define LL(x) ((x)<<1)
#define RR(x) ((x)<<1|1)
#define X(rt) seg[(rt)].x
#define Y(rt) seg[(rt)].y
#define S(rt) seg[(rt)].sum
#define D(rt) seg[(rt)].d

using namespace std;

const int N = 100010;

struct node{
	int x, y;
	long long sum, d;
}seg[N<<2];

void build(int rt, int be, int en)
{
	X(rt) = be;
	Y(rt) = en;
	D(rt) = 0;
	if(be == en){
		scanf("%lld",&seg[rt].sum);
//		printf("reading %d %lld\n", be, S(rt));
		return;
	}

	int mid = (be + en) >> 1;
	build(LL(rt), be, mid);
	build(RR(rt), mid + 1, en);
	S(rt) = S(LL(rt)) + S(RR(rt));
}

void insert(int rt, int be, int en, long long inc)
{
	if(be <= X(rt) && en >= Y(rt))
	{
		D(rt) += inc;
		S(rt) += inc * (Y(rt) - X(rt) + 1);
		return;
	}
	if(D(rt)){
		insert(LL(rt), X(rt), Y(rt), D(rt));
		insert(RR(rt), X(rt), Y(rt), D(rt));
		D(rt) = 0;
	}
	int mid = (X(rt) + Y(rt) ) >> 1;
	if(be <= mid)
		insert(LL(rt), be, en, inc);
	if(en > mid)
		insert(RR(rt), be, en, inc);
	S(rt) = S(LL(rt)) + S(RR(rt));
}

long long qry(int rt, int be, int en)
{
	if(be <= X(rt) && en >= Y(rt))
		return S(rt);
	if(D(rt)){
		insert(LL(rt), X(rt), Y(rt), D(rt));
		insert(RR(rt), X(rt), Y(rt), D(rt));
		D(rt) = 0;
	}
	long long ans = 0;
	int mid = (X(rt) + Y(rt)) >> 1;
	if(be <= mid)
		ans += qry(LL(rt), be, en);
	if(en > mid)
		ans += qry(RR(rt), be, en);
	return ans;
}

int main()
{
	int i, j, n, q;
	long long k;
	char ch;

	scanf("%d%d",&n, &q);
	build(1, 1, n);
	for(; q; q--)
	{
		getchar();
		scanf("%c%d%d",&ch, &i, &j);
		if(ch == 'C'){
			scanf("%lld",&k);
			insert(1, i, j, k);
		}
		else
			printf("%lld\n", qry(1, i, j));
	}
	return 0;
}




