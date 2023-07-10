#include "func.h"

int main(int argc, char *argv[])
{
    cJSON *students_array, *student_item, *root;
    Student_t students[50];
    size_t file_len;
    char *buffer, *file = argv[1];
    FILE *file_ptr = fopen(file, "r");
    if (file_ptr == NULL) {
        puts("Error reading file");
        exit(EXIT_FAILURE);
    }
    fseek(file_ptr, 0, SEEK_END);
    file_len = ftell(file_ptr);
    fseek(file_ptr, 0, SEEK_SET);
    buffer = malloc(sizeof(char) * file_len);
    fread(buffer, sizeof(char), file_len, file_ptr);
    fclose(file_ptr);

    /* Parse the entire JSO data */
    root = cJSON_Parse(buffer);
    students_array = cJSON_GetObjectItem(root, "students");
    if (students_array == NULL) {
        printf("Error parsing students array: %s", cJSON_GetErrorPtr());
        return 1;
    }

    add_db(students_array, student_item);

    cJSON_Delete(root);
    free(buffer);
    return 0;
}
