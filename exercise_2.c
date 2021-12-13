#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


int main(int argc, char *argv[]) {
	// starting point of time.
	clock_t begin = clock();


	char first_name[20];
	char last_name[20];
	int age;
	long amka;

	char str_file[60];
	int user_slot = 1;
	char answer;


	// Open file to write. (use a mode so we can append whenever we want to add another user).
	FILE *fp;
	fp = fopen("my_file", "a" );

	while (user_slot == 1) {
		// Read the first name
		printf("Type your first name:\n");
		scanf("%s", first_name);

		// Read the last name.
		printf("Type your last name:\n");
		scanf("%s", last_name);

		// Read age
		printf("Type your age:\n");
		scanf("%d", &age);
		
		// Read amka.
		printf("Type your AMKA:\n");
		scanf("%ld", &amka);

		
		// Concatenate all the input values into a string to write on file.
		sprintf(str_file,"%s - %s - %d - %ld\n", first_name, last_name, age, amka);
		fputs(str_file, fp);

		// Ask the user if he would like to add another user.
		printf("Would you like to add another user? (y/n)\n");
		scanf(" %c", &answer);
		
		// if the answer char is 'n' then exit the loop and end the program.
		if (answer == 'n') {
			user_slot = 0;
		}

	}
	// Close the file.
	fclose(fp);

	// ending point of time.
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Execution time: %lf\n", time_spent);

	return 0;
}