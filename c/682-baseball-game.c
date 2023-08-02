// https://leetcode.com/problems/baseball-game
struct Score {
    int value;
    struct Score *next;
};

typedef struct {
    struct Score *top;
    int totalSum;
} Stack;

void push(Stack *s, int value) {
    struct Score *score = (struct Score*) malloc(sizeof(struct Score));
    score->value = value;
    score->next = NULL;

    if (s->top == NULL) {
        s->top = score;
    } else {
        score->next = s->top;
        s->top = score;
    }

    s->totalSum += value;
}

void pop(Stack *s) {
    if (s->top == NULL) return;

    struct Score *temp = s->top;
    s->top = s->top->next;

    s->totalSum -= temp->value;
    free(temp);
}

int calPoints(char ** operations, int operationsSize){
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->totalSum = 0;

    for(int i = 0; i < operationsSize; i++) {
        switch(*operations[i]) {
            case '+':
                push(stack, stack->top->value + stack->top->next->value);
            break;
            case 'D':
                push(stack, stack->top->value * 2);
            break;
            case 'C':
                pop(stack);
            break;
            default:
                push(stack, atoi(operations[i]));
        }
    }

    return stack->totalSum;
}