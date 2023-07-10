#include "func.h"

void add_db(cJSON *students_array, cJSON *student_item) {
    struct node *top = NULL;
    Student_t student;
    Student_t arr[50];
    int ID;
    puts("First output:\n");
    for (int i = 0; i < cJSON_GetArraySize(students_array); i++) {
        student_item = cJSON_GetArrayItem(students_array, i);

        cJSON *id_item = cJSON_GetObjectItem(student_item, "student_id");
        if (id_item != NULL) {
            arr[i].student_id = id_item->valueint;
        }

        cJSON *name_item = cJSON_GetObjectItem(student_item, "student_name");
        if (name_item != NULL) {
            strncpy(arr[i].student_name, name_item->valuestring, 44);
        }

        cJSON *record_number_item = cJSON_GetObjectItem(student_item, "student_record_number");
        if (record_number_item != NULL) {
            arr[i].student_record_number = record_number_item->valueint;
        }

        cJSON *rating_item = cJSON_GetObjectItem(student_item, "student_rating");
        if (rating_item != NULL) {
            arr[i].student_rating = rating_item->valuedouble;
        }

        cJSON *attendance_item = cJSON_GetObjectItem(student_item, "student_attendance");
        if (attendance_item != NULL) {
            arr[i].student_attendance = attendance_item->valueint;
        }

        cJSON *login_item = cJSON_GetObjectItem(student_item, "student_login");
        if (login_item != NULL) {
            strncpy(arr[i].student_login, login_item->valuestring, 20);
        }

        printf("Student %d: %s (record number %d, rating %.2lf, attendance %d, login %s)\n",
               arr[i].student_id, arr[i].student_name, arr[i].student_record_number, arr[i].student_rating,
               arr[i].student_attendance, arr[i].student_login);
    }
    puts("\nInput students' IDs");
    for (int i = 0; i < cJSON_GetArraySize(students_array); ++i) {
        scanf("%d", &ID);
        for (int j = 0; j < cJSON_GetArraySize(students_array); ++j) {
            if (ID == arr[j].student_id) {
                push(&top, arr[j]);
            }
        }
    }
    puts("\nSecond output:\n");
    print_and_clear_stack(&top);
}

void push(struct node **top, Student_t data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: out of memory.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
}

void print_and_clear_stack(struct node **top) {
    struct node *current = *top;
    struct node *temp;

    while (current != NULL) {
        printf("Student %d: %s (record number %d, rating %.2lf, attendance %d, login %s)\n",
               current->data.student_id, current->data.student_name, current->data.student_record_number,
               current->data.student_rating, current->data.student_attendance, current->data.student_login);
        temp = current;
        current = current->next;
        free(temp);
    }

    *top = NULL;
}