// https://leetcode.com/problems/number-of-recent-calls
// Data Container
typedef struct
{
    int time;
    struct Request *next;
} Request;

// Queue (FIFO)
typedef struct
{
    Request *first;
    Request *last;
    int count;
} RecentCounter;

void push(RecentCounter *rc, int time)
{
    Request *req = (Request *)malloc(sizeof(Request));
    req->time = time;
    req->next = NULL;

    if (rc->last == NULL)
    {
        rc->first = req;
        rc->last = req;
    }
    else
    {
        rc->last->next = req;
        rc->last = req;
    }

    rc->count++;
}

void pop(RecentCounter *rc)
{
    if (rc->last == NULL)
        return;

    Request *temp = rc->first;
    rc->first = rc->first->next;
    if (rc->first == NULL)
        rc->last == NULL;

    free(temp);

    rc->count--;
}

RecentCounter *recentCounterCreate()
{
    RecentCounter *rc = (RecentCounter *)malloc(sizeof(RecentCounter));
    rc->first = NULL;
    rc->last = NULL;
    rc->count = 0;

    return rc;
}

int recentCounterPing(RecentCounter *obj, int t)
{
    push(obj, t);

    while (t - obj->first->time > 3000)
    {
        pop(obj);
    }

    return obj->count;
}

void recentCounterFree(RecentCounter *obj)
{
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);

 * recentCounterFree(obj);
*/