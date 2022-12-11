#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct iteml {
	unsigned long long l;
	struct iteml* next;
};

struct monkey {
	struct iteml* items;
	char op;
	unsigned long long opn;
	unsigned long long testn;
	int tmn;
	int fmn;
};

void appendI (struct iteml** head, unsigned long long n) {
	struct iteml* i = *head;
	if (i == NULL) {
		*head = malloc(sizeof(struct iteml));
		(*head)->l = n;
		(*head)->next = NULL;
	} else {
		while (i->next != NULL) {
			i = i->next;
		}
		struct iteml* nitem = malloc(sizeof(struct iteml));
		nitem->l = n;
		nitem->next = NULL;
		i->next = nitem;
	}
}

unsigned long long divprod = 1ll;

struct monkey* parse() {
	char l[100];
	fgets(l, 100, stdin);
	if (l[0]=='\n') {fgets(l, 100, stdin);}//l = Monkey N
	fgets(l, 100, stdin); //l = Startin...
	int nns = 1;
	for (int i=0;l[i]!='\0';i++) {
		if (l[i] == ',') {nns++;}
	}
	struct monkey* m = malloc(sizeof(struct monkey));
	//item list
	struct iteml* head = malloc(sizeof(struct iteml));
	head->next = NULL;
	sscanf(&l[18], "%llu", &(head->l));
	unsigned long long n;
	for (int i=1;i<nns;i++) {
		sscanf(&l[18+(4*i)], "%llu", &n);
		appendI(&head, n);
	}
	m->items = head;
	//operation
	fgets(l, 100, stdin); //l = Oper...
	char opn[5];
	sscanf(l, "  Operation: new = old %c %s", &(m->op), opn);
	if (opn[0]=='o') {
		m->opn = 0;
	} else {
		sscanf(opn, "%llu", &(m->opn));
	}
	//test
	fgets(l, 100, stdin); //l = Test:...
	sscanf(l, "  Test: divisible by %llu", &(m->testn));
	divprod *= m->testn;
	fgets(l, 100, stdin); //l = If tru...
	sscanf(l, "    If true: throw to monkey %d", &(m->tmn));
	fgets(l, 100, stdin);
	sscanf(l, "    If false: throw to monkey %d", &(m->fmn));

	return m;
}

int popI(struct iteml** itemp) {
	if (*itemp != NULL) {
		unsigned long long item = (*itemp)->l;
		struct iteml* di = *itemp;
		*itemp = di->next;
		free(di);
		return item;
	} else {
		return -1;
	}
}

struct monkey** monkeys;
long* inspects;

void throwshit(struct monkey* monkey, int mn) {
	unsigned long long item;
	int count = 0;
	while ((item = popI(&(monkey->items))) != -1) {
		inspects[mn]++;
		count++;
		unsigned long long opn = monkey->opn;
		if (opn == 0) {opn = item;}
		switch (monkey->op) {
			case '+': item += opn; break;
			case '*': item *= opn; break;
		}
		//item /= 3;
		item %= divprod;
		if (item % monkey->testn == 0) {
			appendI(&monkeys[monkey->tmn]->items, item);
		} else {
			appendI(&monkeys[monkey->fmn]->items, item);
		}
	}
}

int main() {
	int nmonks = 8;
	monkeys = malloc(sizeof(struct monkey*) * nmonks);
	inspects = malloc(sizeof(long) * nmonks);
	for (int i=0;i<nmonks; i++) {
		monkeys[i] = parse();
	}
	
	for (int rounds=10000; rounds>0; rounds--) {
		for (int i=0; i<nmonks; i++) {
			throwshit(monkeys[i], i);
		}
	}
	//imagine having to write insertion sort lmao
	for (int i=0;i<nmonks-1;i++) {
		for (int j=i+1;j<nmonks;j++) {
			if (inspects[j] > inspects[i]) {
				long tmp = inspects[i];
				inspects[i] = inspects[j];
				inspects[j] = tmp;
			}
		}
	}
	printf("%ld\n", inspects[0] * inspects[1]);
}
