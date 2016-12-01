#include<stdio.h>
#include<conio.h>
#include<string.h>

struct userdetail{
	char uname[50], pwd[50];
}b;

int recsize = sizeof(b);

int main(){
	int select;
	system("cls");
	printf("\t\tWelcome to Train Reservation System\n");
	printf("1\tUser\n");
	printf("2\tAdmin\n");
	printf("Enter your input: ");
	scanf("%d", &select);
	switch(select){
	case 1:
		user();
		break;
	case 2:
		adminauthen();
		break;
	default:
		printf("Invalid input. Please try again.");
		main();
	}
}
int user(){
	int select;
	system("cls");
	printf("\t\tUser\n");
	printf("1\tSign up\n");
	printf("2\tSign in\n");
	printf("3\tBack\n");
	printf("Enter your choice: ");
	scanf("%d", &select);
	switch (select){
	case 1:
		system("cls");
		signup();
		break;
	case 2:
		system("cls");
		signin();
		break;
	case 3:
		system("cls");
		main();
		break;
	}
}
signup(){
	FILE *ptr;
	int select;

	ptr = fopen("database.txt", "a");
	if (ptr == NULL)
	{
		ptr = fopen("database.txt", "w+");
		if (ptr == NULL)
		{
			printf("Error in opening file : \n");
			return -1;
		}
	}
	printf("\t\tUser Sign Up\n");
	printf("Username: ");
	fflush(stdin);
	scanf("%[^\n]%*c", b.uname);
	printf("Password: ");
	//Starting hide password function
	char buffer[256] = { 0 }, c;
	int pos = 0;
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
	strcpy(b.pwd, buffer);
	printf("\nConfirm?\n1\tYes\n2\tNo\n\nEnter your choice: ");
	scanf("%d", &select);
	if (select == 1){
		system("cls");
		fwrite(&b, recsize, 1, ptr);
		fflush(stdin);
		fclose(ptr);
		printf("Registration confirmed!!\n\nPress any key to continue...\n");
		getch();
		user();
	}
	else
		user();
}
//Will do later...

signin(){
	FILE *ptr;
	int select, flag = 0, select2;
	char uname[50], pwd[50];

	ptr = fopen("database.txt", "r");
	printf("\t\tUser Sign In\n");
	printf("Username: ");
	fflush(stdin);
	scanf("%[^\n]%*c", &uname);
	printf("Password: ");
	fflush(stdin);
	scanf("%[^\n]%*c", &pwd);

	while (fread(&b, recsize, 1, ptr) == 1)
	{
		if (strcmp(uname, b.uname) == 0 && strcmp(pwd, b.pwd) == 0)
		{
			system("cls");
			printf("\t\tWelcome %s\n", b.uname);
			printf("1\tReserve a train\n");
			printf("2\tCancellation\n");
			printf("3\tEdit travelling details\n");
			printf("4\tView all available tickets\n");
			printf("5\tBack\n\n");
			printf("Enter your choice: ");
			scanf("%d", &select2);
			if (select2 == 1)
				user1();
			if (select2 == 2)
				user2();
			if (select2 == 3)
				user3();
			if (select2 == 4)
				user4();
			if (select2 == 5)
				user();
			flag = 1;
			break;
		}
		else{
			;
		}
	}
	if (flag == 0){
		printf("Wrong username or password");
		getch();
		user();
	}
}
user1(){
	printf("\t\tUser Reservation System");
}
user2(){
	printf("Greed is good");
}
user3(){
	printf("Foo bar");
}
user4(){
	printf("Reanimate food");
}
user5(){
	printf("Algorithm required");
}

//admin-related
adminauthen(){
	FILE *ptr;
	int select;
	char uname[50], pwd[50], c;

	system("cls");
	printf("Admin credentials\n");
	printf("========================================\n\n");
	printf("Username: ");
	fflush(stdin);
	scanf("%[^\n]%*c", uname);
	printf("Password: ");
	char buffer[256] = { 0 };
	int pos = 0;
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
	strcpy(pwd, buffer);
	if (strcmp(uname, "admin") == 0 && strcmp(pwd, "admin") == 0)
		admin();
	else{
		printf("Wrong username or password. Press any key to return to main menu... ");
		getch();
	}
}

admin(){
	int select;
	system("cls");
	printf("\t\tWelcome admin! \n");
	printf("1\tNew Train Detail\n");
	printf("2\tModify Train Detail\n");
	printf("3\tCancel Train Detail\n");
	printf("4\tView User Reservation\n");
	printf("5\tView User Cancellation\n");
	printf("6\tView Username List\n");
	printf("7\tCancel\n\n");
	printf("Enter your choice: ");
	scanf("%d", &select);
	if (select == 1)
		newdetail();
	else if (select == 2)
		moddetail();
	else if (select == 3)
		cancdetail();
	else if (select == 4)
		viewreserv();
	else if (select == 5)
		viewcanc();
	else if (select == 6)
		viewlist();
	else if (select == 7)
		main();
	else{
		printf("Invalid choice. Please try again");
		printf("Press any key to continue... ");
		getch();
		admin();
	}
}
newdetail(){
	printf("Invalid choice11. Please try again");
}
moddetail(){
	printf("Invalid choice22. Please try again");
}
cancdetail(){
	printf("Invalid choice333. Please try again");
}
viewreserv(){
	printf("Invalid choice44. Please try again");
}
viewcanc(){
	printf("Invalid choice55. Please try again");
}
viewlist(){
	FILE *ptr;
	
	system("cls");
	ptr = fopen("database.txt", "r");
	printf("================================================================================\n"); 
	printf("List of usernames\t\tPasswords\n");  
	printf("================================================================================"); 
	while (fread(&b, recsize, 1, ptr) == 1) {
		printf("\n%s", b.uname);
		printf("\t\t%s\n", b.pwd);
	}
	printf("\n\nPress any key to return to admin menu... ");
	getch();
	admin();
}
