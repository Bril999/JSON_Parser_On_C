# JSON_Parser_On_C
To parse a file, use the cJSON library (https://github.com/DaveGamble/cJSON ). After that, the students' data must be entered into an array of Student_t structures and display the entire contents of the array in an arbitrary readable format. 

After that, the user gets an input console, where he will need to enter the student ID via Enter. After each input, a pointer to this student is added to the stack data structure (Push operation). You can enter the ID in any sequence, all students must be sent to the stack. 

After all students have been sent to the stack, the pointer to the top of the stack is passed to the stack contents output function, which completely clears the stack, outputting the data of each student with whom the Pop operation is performed in the same arbitrary readable format as after parsing the json file.
