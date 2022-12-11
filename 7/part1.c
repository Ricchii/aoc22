#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct file {
	char* name;
	long size;
	struct file* next;
};

struct dir {
	char* name;
	struct file* files;
	struct dir* dirs;
	struct dir* parent;
	struct dir* next;
};

struct dir* cd(struct dir* wd, char* name) {
	struct dir* d = wd->dirs;
	while (strcmp(d->name, name) != 0) {
		d = d->next;
	}
	return d;
}

void pc(char* l, struct dir** wd) {
	char t[50];
	sscanf(l, "%s", &t[0]);
	if (strcmp(t, "$") == 0) {
		sscanf(&l[1], "%s", &t[0]);

		if (strcmp(t, "ls") == 0) {
			return;
		}
		if (strcmp(t, "cd") == 0) {
			sscanf(&l[4], "%s", &t[0]);
			if (strcmp(t, "..") == 0) {
				*wd = (*wd)->parent;
			} else {
				*wd = cd(*wd, t);
			}
		}
	} else if (strcmp(t, "dir") == 0) {
		sscanf(&l[strlen(t)], "%s", &t[0]);
		struct dir* d = malloc(sizeof(struct dir));
		d->name = malloc((sizeof(char)*strlen(t))+2);
		strcpy(d->name, t);
		d->files = NULL;
		d->dirs = NULL;
		d->parent = *wd;
		d->next = (*wd)->dirs;
		(*wd)->dirs = d;
	} else if (t[0] >='0' && t[0] <= '9'){
		
		struct file* f = malloc(sizeof(struct file));
		f->size = atoi(t);
		sscanf(&l[strlen(t)], "%s", &t[0]);
		f->name = malloc((sizeof(char)*strlen(t))+2);
		strcpy(f->name, t);
		f->next = (*wd)->files;
		(*wd)->files = f;
	}
}

void addsize(long size, long* sizes) {
	long i=0;
	while (sizes[i] !=0){i++;}
	sizes[i] = size;
}

long dirsize(struct dir* wd, long* sizes) {
	long sum = 0;
	struct file* f = wd->files;
	while (f != NULL) {
		sum += f->size;
		f = f->next;
	}
	struct dir* d = wd->dirs;
	while (d != NULL) {
		sum += dirsize(d, sizes);
		d = d->next;
	}
	addsize(sum, sizes);
	return sum;
}

int main() {
	struct dir* wd = malloc(sizeof(struct dir));
	wd->name = "/";
	char l[50];
	fgets(l, 50, stdin);
	while (fgets(l, 50, stdin) != NULL) {
		pc(l, &wd);
	}
	while (strcmp(wd->name, "/") != 0) {
		wd = wd->parent;
	}
	long sizes[1000];
	for(int i=0;i<1000;i++){sizes[i]=0;}
	long ns = dirsize(wd, &sizes[0]);
	long sum = 0;
	ns = 30000000 - (70000000 - ns);
	long n = 70000000;
	for(int i=0;i<1000;i++){
		if(sizes[i]<=100000){
			sum+=sizes[i];
		}
		if(sizes[i]<=n && sizes[i]>=ns) {
			n = sizes[i];
		}
	}
	printf("%ld\n%ld\n",sum, n);
}
