/*
* SplayTree_econ.cpp
*
*  Created on: Jan 6, 2013
*      Author: shuo
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 130011;

struct Node {
	// ch[0]: left child; ch[1]: right child
	Node *ch[2], *p;
	int v, size;
	bool rvs;
	Node () : v(0), size(0){}

	/* Static */
	bool R() {return this == p->ch[1];}

	/* Static */
	void setch (bool c, Node *x) {
		ch[c] = x;
		x->p = this;
	}

	/* Task specific */
	void push_down () {
		if (rvs) {
			swap (ch[0], ch[1]);
			ch[0]->rvs ^= 1;
			ch[1]->rvs ^= 1;
			rvs = false;
		}
	}

	/* Task specific */
	void update () {
		size = ch[0]->size + ch[1]->size + 1;
	}
}memo[N];

Node *snt, *root;
int n, mpt = 0;

/* Static */
void rotate (Node *x) {
	Node *f = x->p;
	int c = x->R();
	f->push_down (); x->push_down (); // is it necessary for x ?
	f->setch (c, x->ch[!c]);
	f->p->setch (f->R(), x);
	x->setch (!c, f);
	f->update ();
	if (f == root) root = x;

}

/* Static */
void splay (Node *x, Node *t) {
	for (x->push_down (); x->p != t; ) {
		if (x->p->p == t)
			rotate (x);
		else
			(x->R() == x->p->R()) ? (rotate (x->p), rotate (x)) : (rotate (x), rotate(x));
	}
	x->update ();
}


/* Task specific */
Node* newNode (int val) {
	Node* u = &memo[mpt++];
	u->v = val;
	u->p = u->ch[0] = u->ch[1] = snt;
	u->size = 1; u->rvs = false;
	return u;
}

/* Task specific: probably interval operation */
Node* build (int l, int r) {
	if (l > r) return snt;

	int mid = (l + r) / 2;
	Node *u = newNode (mid);
	if (l < r) {
		u->setch (0, build (l, mid - 1));
		u->setch (1, build (mid + 1, r));
	}
	u->update ();
	return u;
}

Node* select (int rk) {
	Node *u = root;
	while (true) {
		u->push_down (); // cannot be delayed
		int j = u->ch[0]->size + 1;
		if (rk == j) return u;
		else if (rk > j) {
			u = u->ch[1];
			rk -= j;
		}
		else u = u -> ch[0];

	}
	return u;
}

void init () {
	snt = &memo[mpt++];
	root = build (0, n + 1);
	snt->setch (0, root);
}

void reverse (int l, int r) {
	Node *a = select (l);
	Node *b = select (r + 2);
	splay (a, snt);  splay (b, a);
	b->ch[0]->rvs ^= 1;
	splay (b->ch[0], snt); // still got AC if removed
}


void go (Node *u) {
	if (u == snt) return;
	u->push_down ();
	go (u->ch[0]);
	if (u->v != 0 && u->v != n + 1)
		printf ("%d ", u->v);
	go (u->ch[1]);
}
void output () {
	go (root);
	printf ("\n");
}

int main () {
	int i, j, m;
	//freopen ("in.txt", "r", stdin);
	scanf ("%d%d", &n, &m);
	init ();
	for (; m; m--) {
		scanf ("%d%d", &i, &j);
		reverse (i, j);
	}
	output ();
	return 0;
}







