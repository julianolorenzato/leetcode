// https://leetcode.com/problems/last-stone-weight
typedef struct {
    int *weights;
    int first;
    int last;
} PriorityQueue;

void push(PriorityQueue *pq, int weight) {
    if (pq->first == -1) {
        pq->weights[0] = weight;
        pq->first = 0;
        pq->last = 0;
    } else {
        int i;
        for (i = pq->first; i <= pq->last; i++) {
            if (pq->weights[i] >= weight) {
                continue;
            }

            for (int j = pq->last; j >= i; j--) {
                pq->weights[j + 1] = pq->weights[j];
            }

            break;
        }
        pq->last++;
        pq->weights[i] = weight;
    }
}

void smash(PriorityQueue *pq) {
    int res = abs(pq->weights[pq->first] - pq->weights[pq->first + 1]);

    pq->first += 2;

    if (pq->first > pq->last) {
        pq->first = -1;
        pq->last = -1;
    }

    if (res != 0) {
        push(pq, res);
    }

}

int lastStoneWeight(int* stones, int stonesSize){
    PriorityQueue *pq = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    pq->weights = malloc(sizeof(int) * stonesSize * 2);
    pq->first = -1;
    pq->last = -1;

    // Fill the priority queue pushing and sorting the stone weights
    for (int i = 0; i < stonesSize; i++) {
        push(pq, stones[i]);
    }

    // Smash the first two stones (two bigger weights) pushing and
    // sorting the rest of the bigger weight stone (if their weight was different)
    while(pq->last - pq->first >= 1) {
        smash(pq);
    }

    if (pq->first == -1) {
        return 0;
    }

    return pq->weights[pq->first];
}