#include <stdio.h>
#include "cJSON-master/cJSON.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int student_id;
    char student_name[15];
    int student_record_number;
    double student_rating;
    int student_attendance;
    char student_login[15];
} Student_t;

struct node {
    Student_t data;
    struct node *next;
};

void add_db(cJSON *students_array, cJSON *student_item);
void print_and_clear_stack(struct node **top);
void push(struct node **top, Student_t data);
