#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
int profit[100];
int weights[100];
int selG[100];
int cap = 0;
int max_val = 0;

void weightAndprofit (int selected[N], int *weight, int *value) {
	int i, w = 0, v = 0;
	for (i = 0; i < N; ++i) {
		if (selected[i]) { 
			w += weights[i];
			v += profit[i];
		}
	}
	*weight = w;
	*value = v;
}

void printTable (int selected[N]) {
	int i;
	int val = 0;
    printf("\nSelected Items:-\n");
	printf("Item No. Weight Profit\n");
	for (i = 0; i < N; ++i) {
		if (selected[i]) {
            printf("   %d\t   %d\t  %d\n", i+1,weights[i], profit[i]);
			val += profit[i];
		}
	}
	printf("Total Profit: \t  %d\n", val);
} 

void knapsack (int selected[N], int i) {
	int curr_w, curr_val;
	weightAndprofit(selected, &curr_w, &curr_val); 
	if (curr_w <= cap) {
		if (curr_val > max_val) {
			memcpy(selG, selected, sizeof(selG));
			max_val = curr_val;
		}
	}
	if (i == N || curr_w >= cap) {
		return;
	}
	int x = weights[i];
	int use[N], no_use[N];
	memcpy(use, selected, sizeof(use));
	memcpy(no_use, selected, sizeof(no_use));
	use[i] = 1;
	no_use[i] = 0;
	knapsack(use, i+1);
	knapsack(no_use, i+1);
}

int main() {
	printf("Items: ");
	scanf(" %d", &N);
	int selected[N];
	int i;
	printf("Weights: ");
	for(i = 0; i < N; i++) {
		scanf(" %d", &weights[i]);
		selected[i] = 0;
	}
	printf("Profit: ");
	for(i = 0; i < N; i++) {
		scanf(" %d", &profit[i]);
	}
	printf("Knapsack capacity: ");
	scanf(" %d", &cap);
	knapsack(selected, 0);
	printTable(selG);
	return 0;
}
// 4
// 2 4 6 9
// 10 10 12 18
// 15