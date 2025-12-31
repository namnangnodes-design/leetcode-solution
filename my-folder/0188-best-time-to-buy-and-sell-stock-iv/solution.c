#include <limits.h>
#include <stdbool.h>

struct Tran {
    int start;
    int end;
};

int maxProfit(int k, int* prices, int pricesSize) {
    if (pricesSize <= 1 || k <= 0) return 0;

    struct Tran* trans = malloc(sizeof(struct Tran) * (pricesSize / 2 + 1));
    int numOfTrans = 0;
    int start = 0, end = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[i - 1]) {
            end = i;
        } else {
            if (end > start) {
                trans[numOfTrans].start = start;
                trans[numOfTrans].end = end;
                numOfTrans++;
            }
            start = i;
        }
    }
    if (end > start) {
        trans[numOfTrans].start = start;
        trans[numOfTrans].end = end;
        numOfTrans++;
    }

    int curTrans = numOfTrans;
    while (curTrans > k) {
        int minLossDelete = INT_MAX;
        int deleteIndex = -1;

        for (int i = 0; i < numOfTrans; i++) {
            if (trans[i].start == -1) continue;
            int currentProfit = prices[trans[i].end] - prices[trans[i].start];
            if (currentProfit < minLossDelete) {
                minLossDelete = currentProfit;
                deleteIndex = i;
            }
        }

        int minLossMerge = INT_MAX;
        int startIndex = -1;
        int endIndex = -1;

        for (int i = 0; i < numOfTrans; i++) {
            if (trans[i].start == -1) continue;
            int j = -1;
            for (int next = i + 1; next < numOfTrans; next++) {
                if (trans[next].start != -1) {
                    j = next;
                    break;
                }
            }
            if (j != -1) {
                int lossMerge = prices[trans[i].end] - prices[trans[j].start];
                if (lossMerge < minLossMerge) {
                    minLossMerge = lossMerge;
                    startIndex = i;
                    endIndex = j;
                }
            }
        }

        if (startIndex != -1 && minLossMerge <= minLossDelete) {
            trans[startIndex].end = trans[endIndex].end;
            trans[endIndex].start = -1;
        } else if (deleteIndex != -1) {
            trans[deleteIndex].start = -1;
        }
        curTrans--;
    }

    int profit = 0;
    for (int i = 0; i < numOfTrans; i++) {
        if (trans[i].start != -1) {
            profit += prices[trans[i].end] - prices[trans[i].start];
        }
    }
    free(trans);
    return profit;
}
