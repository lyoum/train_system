#include<stdio.h>
#include<conio.h>
#include<string.h>

//Below function validate whitespace when scanf
validw(char c[100]){
	int i;
	for (i = 0; i < 100; i++){
		fgets(c, 100, stdin);
		if (fgets(c, 100, stdin) == NULL)
			break; break;
	}
	return c;
}
hidepass(){
	char buffer[256] = { 0 };
	char password[] = "password";
	char c;
	int pos = 0;
	printf("%s", "Enter password: ");
	do{
		c = _getch();
		if (isprint(c)){
			buffer[pos++] = c;
			printf("%c", '*');
		}
		else if ((c == '\b') && pos){
			buffer[pos--] = '\0';
			printf("%s", "\b \b");
		}
	} while (c != '\r');
	if (!strcmp(buffer, password))
		printf("\n%s\n", "Logged in successfully!");
	else
		printf("\n%s\n", "Incorrect login!");
}
//User related functions
int user(){
	int j;
	printf("\tUser\n-------------------\n");
	printf("1\tSign up to register your account\n2\tSign in your account\nSelect your choice: ");
	scanf_s("%d", &j, 1);
	if (j == 1){
		signup();
	}
	else if (j == 2){
		signin();
	}
}
struct userdetail{
	char name1[100], email[30], gender[10],username[50],pwd[50];
	int age;
	unsigned long long int ic, hpno;
}b;
int signup(){
	system("cls");
	struct userdetail b;
	int confirm,num;
	char c[100];
	FILE *fptr;
	fptr = fopen("Cprogram.txt", "a+");
	if (fptr != NULL) {
		printf("\tSign up to reserve Train(s).\nPlease follow instructions to fill in your details:\n\nFull name: ");
		validw(b.name1);
		printf("\nGender (Male/Female): ");
		scanf_s("%s", b.gender, 10);
		printf("\nAge: ");
		scanf_s("%d", &b.age, 10);
		printf("\nIC number or Passport number: ");
		scanf("%llu", &b.ic);
		printf("\nEmail: ");
		scanf_s("%s", b.email, 30);
		printf("\nTelephone number: ");
		scanf("%llu", &b.hpno);
		printf("\nUsername: ");
		scanf_s("%s", b.username, 50);
		printf("\nPassword: ");
		scanf_s("%s", b.pwd, 50);
		system("cls");
		sprintf(c,"Full name: %sGender: %s\nAge: %d\nIC number or Passport number: %llu\nEmail: %s\nTelephone number: %011llu\nUsername: %s\nPassword: %s\nConfirm\?\n\n1\tConfirm\n2\tCancel\nEnter your input: ",
			b.name1, b.gender, b.age, b.ic, b.email, b.hpno,b.username,b.pwd);
		printf("%s", c);
		scanf_s("%d", &confirm, 1);
		if (confirm == 1){
			system("cls");
			fprintf(fptr, "Full name: %sGender: %s\nAge: %d\nIC number or Passport number: %llu\nEmail: %s\nTelephone number: %011llu\nUsername: %s\nPassword: %s\n---------------------------------------------------------------------------------------\n",
				b.name1, b.gender, b.age, b.ic, b.email, b.hpno,b.username,b.pwd);
			fclose(fptr);
			printf("Confirmed. Sign in at main menu to proceed at reservation...\n\n");
			return main();
		}
		else if (confirm == 2){
			fclose(fptr);
			system("cls");
			printf("Cancelled. Returning to main menu...\n\n");
			return main();
		}
		else{
			system("cls");
			printf("Invalid input. Returning to main menu...\n\n");
			return main();
		}
	}
};
 signin(){
	 printf("\tSign In\n-------------------\nEnter user credentials\n\n");
	 printf("Username: ");
 }
 //Admin related functions
int admin() {
	int i;
	char name1[50];
	printf("Hi. \nEnter something: ");
	for (i = 0; i < 100; i++){
		fgets(name1, 100, stdin);
		if (fgets(name1, 100, stdin) == NULL){
			break;
		}
		break;
	}
	printf("%s", name1);
}
read(){
	FILE *ptr;
	ptr = fopen("Cprogram.txt", "r");
	_getch;
	fclose(ptr);
	return main();
}
int main(){
	int input1;
tryagain:
	printf("\tWelcome to the Train Reservation System.\n-----------------------------------------------------\nSelect whether you are User or Admin.\n1\tUser\n2\tAdmin\n3\tRead\nSelect your choice: ");
	scanf_s("%d", &input1, 1);
	system("cls");
	switch (input1){
	case 1: user();
		break;
	case 2: admin();
		break;
	case 3: hidepass();
		break;
	default: printf("Invalid input. Please try again.");
		goto tryagain;
	}
}