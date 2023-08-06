// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
typedef struct Student {
    int favorite;
    struct Student *next;
} Student;

typedef struct {
    Student *first;
    Student *last;
    int preferCircle;
    int preferSquare;
} StudentsQueue;

typedef struct {
    int type;
    struct Sandwich *next;
} Sandwich;

typedef struct {
    Sandwich *top;
} SandwichesStack;

// Push student to end of queue incresing your favorite
// type of sandwich to sentinel counting;
void queuePush(StudentsQueue *sq, int favorite) {
    if (favorite == 1) {
        sq->preferSquare++;
    } else {
        sq->preferCircle++;
    }

    Student *student = (Student*) malloc(sizeof(Student));
    student->favorite = favorite;

    if (sq->first == NULL) {
        sq->first = student;
        sq->last = student;
    } else {
        sq->last->next = student;
        sq->last = student;
    }
}

// Pop student of begin of queue decreasing your favorite
// type of sandwich of sentinel counting
void queuePop(StudentsQueue *sq) {
    if (sq->first->favorite == 1) {
        sq->preferSquare--;
    } else {
        sq->preferCircle--;
    }

    Student *popped = sq->first;
    sq->first = sq->first->next;
    free(popped);
}

// Push sandwich to the stack 
void stackPush(SandwichesStack *ss, int type) {
    Sandwich *sandwich = (Sandwich*) malloc(sizeof(Sandwich));
    sandwich->type = type;

    sandwich->next = ss->top;
    ss->top = sandwich;
}

// Pop sandwich from the stack
void stackPop(SandwichesStack *ss) {
    Sandwich *popped = ss->top;
    ss->top = ss->top->next;
    free(popped);
}

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize){
    StudentsQueue *sq = (StudentsQueue*) malloc(sizeof(StudentsQueue));
    sq->first = NULL;
    sq->last = NULL;
    sq->preferCircle = 0;
    sq->preferSquare = 0;

    for (int i = 0; i < studentsSize; i++) {
        queuePush(sq, students[i]);
    }

    SandwichesStack *ss = (SandwichesStack*) malloc(sizeof(SandwichesStack));
    ss->top = NULL;

    for (int i = 0; i < sandwichesSize; i++) {
        stackPush(ss, sandwiches[i]);
    }

    while (1) {
        if (ss->top->type != sq->first->favorite) {
            queuePush(sq, sq->first->favorite);
            queuePop(sq);
        } else {
            queuePop(sq);
            stackPop(ss);
        }

        if (ss->top == NULL) return 0;
        if (sq->preferCircle == 0 && sq->preferSquare == 0) return 0;
        if (sq->preferSquare == 0 && ss->top->type == 1) return sq->preferCircle;
        if (sq->preferCircle == 0 && ss->top->type == 0) return sq->preferSquare;

    }
        return 0;
}