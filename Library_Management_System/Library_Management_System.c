#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct
{
	char booktitle[30];
	char issueno[30];
	char bookauthor[30];
	char fieldofbook[30];

} book; //to store new books in library and search
typedef struct
{
	char username[30];
	char password[30];
} user; //to add ,delete& display members
typedef struct
{
	char username[30];
	char booktitle[30];
	char bookauthor[30];
} pendingbook; //to store data of pending books which member wanted but was not available in library
typedef struct
{
	char username[30];
	char booktitle[30];
	char issueno[30];
	char bookauthor[30];
	char fieldofbook[30];
	int day;
	int month;
	int year;
} userbook; //to issue books from library and display them
void welcomepage(void);
void menu(void);
void bookmanagement(void);
void booktransaction(void);
void issuebook(void);
void seeissuedbook(void);
void bookavailability(void);
void cancelreservation(void);
void returnbook(void);
void inventorymanagement(void);
void vendormanagement(void);
void addbookfromvendor(void);
void adbookfrootherlibraries(void);
void member_management(void);
void see_member(void);
void add_member(void);
void delete_member(void);
void notification(void);
int main()
{
	welcomepage();
	menu();
	return 0;
}

void welcomepage()
{
	FILE *fv;
	user u[1], a[1];
	book d[1];
	int search = 1, compare1 = 1, compare2 = 1, y;
	printf("             ######################################################\n");
	printf("             ********** LIBRARY MANAGEMENT PROJECT  ***************\n");
	printf("             **********         IN C                ***************\n");
	printf("             ######################################################\n\n\n");
	FILE *fp;
	fp = fopen("newbooks.txt", "r");
	if (fp == NULL)
	{
		printf("\n"); //if no books are newly added
	}
	else
	{
		printf("Following new books are added to library :\n\n");
	}
	while ((fread(&d[0], sizeof(book), 1, fp)) > 0) //to view newly added books
	{
		printf("Title of book is:\t %s\n", d[0].booktitle);
		printf("Issue number of book is:\t %s\n", d[0].issueno);
		printf("Author of book is :\t%s\n ", d[0].bookauthor);
		printf("Field to which book is related is :\t%s\n", d[0].fieldofbook);
		printf("---------------------------------\n");
	}
	fclose(fp);
	printf("\nEnter The Username:\t");
	y = 0;
	fflush(stdin);
	scanf("%[^\n]%*c", u[0].username);
	printf("\nEnter The Password:\t");
	fflush(stdin);
	scanf("%[^\n]%*c", u[0].password);
	fv = fopen("members.txt", "r"); //to read all users  which are members of library
	while (fread(&a[0], sizeof(user), 1, fv) > 0)
	{
		compare1 = strcmp(a[0].username, u[0].username); //to check if user name is correct
		compare2 = strcmp(a[0].password, u[0].password); //to check if password is correct
		if (compare1 == 0 && compare2 == 0)
		{
			search = 0; //if username and passsword are correct
			printf("\nYou have entered correct credentials :)\n");
			printf("Press Enter to continue\n");
			getchar();
			system("cls||clear");
			rewind(fv);
			fclose(fv);
			menu();
		}
	}
	if (search != 0)
	{
		printf("\nInvalid Username or Password\n");
		printf("\nPress Enter to try again\n");
		getchar();
		system("cls||clear");//used it so that code can run on both windows and ubuntu
		welcomepage();
	}
}

void menu()
{
	char a;
	printf("\n\n|      MAIN MENU     |\n\n");
	printf("Press 1 for Book management\n");
	printf("Press 2 for Book transaction\n");
	printf("Press 3 for Vendor management\n");
	printf("Press 4 for Inventory management\n");
	printf("Press 5 for member management\n");
	printf("Press 6 for to return to welcome page\n");
	printf("Press 7 to exit program\n ");
	printf("---------------------------------\n");
	scanf(" %c", &a);
	getchar();
	printf("\nPress enter\n");
	system("cls||clear");
	switch (a)
	{
	case '1':
		bookmanagement();
		break;
	case '2':
		booktransaction();
		break;
	case '3':
		vendormanagement();
		break;
	case '4':
		inventorymanagement();
		break;
	case '5':
		member_management();
		break;
	case '6':
		welcomepage();
		break;
	case '7':
		exit(1);
		break;
	default:
		printf("try again");
	}
}

void bookmanagement()
{
	char a;
	FILE *fp;
	int i, b = 0, l = 0, y;
	book c[1], j[1];
	int compare = 0;
	fp = fopen("books.txt", "r"); //file pointer to file books.txt to read data of all books
	while (fread(&j[0], sizeof(book), 1, fp) > 0)
	{
		l++; //Count number of books in library
	}
	i = l;
	book g[i]; //Arrray allocation as there are l books in library
	l = 0;
	rewind(fp);
	while (fread(&g[l], sizeof(book), 1, fp) > 0)
	{
		l++; //storing data of all books available in books.txt in array of book
	}
	fclose(fp);
	while (1) //infinite loop till we return to mainmenu or exit
	{
		printf("\n\n|      BOOK MANAGEMENT     |\n\n");
		printf("Enter 1 to search book by title(will show all books by same title)\n");
		printf("Enter 2 to search book by issue no\n");
		printf("Enter 3 to search all books by same author\n");
		printf("Enter 4 to search all books related to same field\n");
		printf("Enter 5 to return to main menu\n");
		printf("Enter 6 to exit the program.\n");
		printf("---------------------------------\n");
		scanf(" %c", &a);
		getchar();
		system("cls||clear");
		switch (a)
		{
		case '1':
			b = 0;
			compare = 1;
			printf("Enter the title:\t");
			y = 0;
			fflush(stdin);
			scanf("%[^\n]%*c", c[0].booktitle);

			//    while((c[0].booktitle[y] =getchar()) !='\n')
			//    {
			//    	y++;
			//	}
			//    c[0].booktitle[y]='\0';
			y = 0;		   //store book title in string you want to search
			while (b != i) //loop to read all data stored in array
			{
				if (strcmp(g[b].booktitle, c[0].booktitle) == 0) //if book name you stored exists in library
				{
					compare = 0; // if book you searched  is available
					printf("Title of book is:\t %s\n", g[b].booktitle);
					printf("Issue number of book is:\t %s \n", g[b].issueno);
					printf("Author of book is :\t%s \n", g[b].bookauthor);
					printf("Field to which book is related is :\t%s\n", g[b].fieldofbook);
					printf("---------------------------------\n");
				}
				b++;
			}
			if (compare == 1) //if book you searched doesnot exist in our library
			{
				printf("Book with this title not found .\n");
			}
			b = 0, compare = 0;
			break;
		case '2':
			b = 0, compare = 0;
			printf("Enter the issue number:\t");
			y = 0;
			//    while((c[0].issueno[y] =getchar()) !='\n')
			//    {
			//    	y++;
			//	}
			//    c[0].issueno[y]='\0';
			//    y=0;
			fflush(stdin);
			scanf("%[^\n]%*c", c[0].issueno);
			while (b != i) //loop to check if same issue number exists
			{
				if (strcmp(g[b].issueno, c[0].issueno) == 0)
				{
					compare = 1;
					printf("Title of book is:\t %s\n", g[b].booktitle);
					printf("Issue number of book is:\t %s\n", g[b].issueno);
					printf("Author of book is :\t%s \n", g[b].bookauthor);
					printf("Field to which book is related is :\t%s\n", g[b].fieldofbook);
					printf("---------------------------------\n");
				}
				b++;
			}
			if (compare == 0) //if issue number you entered is not found
			{
				printf("Book with this issue number not found .\n");
			}
			b = 0, compare = 0;
			break;
		case '3':
			b = 0, compare = 0;
			printf("Enter the name of author:\t");
			y = 0;
			//    while((c[0].bookauthor[y] =getchar()) !='\n')
			//    {
			//    	y++;
			//	}
			//    c[0].bookauthor[y]='\0';
			//    y=0;
			fflush(stdin);
			scanf("%[^\n]%*c", c[0].bookauthor);
			while (b != i) //loop to read data stored in array of ur library here i is number of books
			{
				if (strcmp(g[b].bookauthor, c[0].bookauthor) == 0)
				{
					compare = 1; //to compare if book author you searched is available in library
					printf("Title of book is:\t %s\n", g[b].booktitle);
					printf("Issue number of book is:\t %s \n", g[b].issueno);
					printf("Author of book is :\t%s \n", g[b].bookauthor);
					printf("Field to which book is related is :\t%s\n", g[b].fieldofbook);
					printf("---------------------------------\n");
				}
				b++; //increment b
			};
			if (compare == 0) //if the book author you wrote is not found
			{
				printf("Book with this author not found .\n");
			}
			b = 0, compare = 0;
			break;
		case '4':
			b = 0, compare = 0;
			printf("Enter the field to which book is related :\t");
			y = 0;
			//    while((c[0].fieldofbook[y] =getchar()) !='\n')
			//    {
			//    	y++;
			//	}
			//    c[0].fieldofbook[y]='\0';
			y = 0;
			fflush(stdin);
			scanf("%[^\n]%*c", c[0].fieldofbook);
			while (b != i)
			{
				if (strcmp(g[b].fieldofbook, c[0].fieldofbook) == 0)
				{
					compare = 1; // to compare if  books related to fiel you searched are available
					printf("Title of book is:\t %s\n", g[b].booktitle);
					printf("Issue number of book is:\t %s \n", g[b].issueno);
					printf("Author of book is :\t%s \n", g[b].bookauthor);
					printf("Field to which book is related is :\t%s\n", g[b].fieldofbook);
					printf("---------------------------------\n");
				}
				b++;
			};
			if (compare == 0) //if book you searched for is not available
			{
				printf("Book related to this field not found.\n");
			}
			b = 0, compare = 0;
			break;
		case '5':
			menu(); //fuction to return to main menu
			break;
		case '6':
			exit(1); //exit from program
		default:
			printf("try again");
		}
	}
}

void booktransaction()
{
	char a;
	while (1) //infinite loop till we call menu() function or exit
	{
		printf("\n\n|      BOOK TRANSACTION     |\n\n");
		printf("press 1 to issue a book.\n");
		printf("press 2 to check the books  issued by you.\n");
		printf("press 3 to check notificationn if the book you reserved is available.\n");
		printf("press 4 to cancel the pending reservation \n\tto get notification for availability of a book.\n");
		printf("press 5 to return any book you issued .\n");
		printf("press 6 to return to main menu.\n");
		printf("press 7 to exit program .\n");
		printf("---------------------------------\n");
		scanf(" %c", &a);
		getchar();
		system("cls||clear");
		switch (a)
		{
		case '1':
			issuebook();
			break;
		case '2':
			seeissuedbook();
			break;
		case '3':
			bookavailability();
			break;
		case '4':
			cancelreservation();
			break;
		case '5':
			returnbook();
			break;
		case '6':
			menu();
			break;
		case '7':
			exit(1);
			break;
		default:
			printf("Try again");
		}
	}
}

void issuebook()
{
	FILE *fp, *fd, *fu, *fe, *fh;
	int i, j, k, compare1 = 0, compare = 0, compare2 = 0, l, n, y;
	book p[1], b[1];
	i = 0;
	j = 0;
	user a[1], e[1];
	userbook d[1];
	printf("Enter the user name:\t ");
	y = 0;
	fflush(stdin);
	scanf("%[^\n]%*c", a[0].username);
	y = 0;							//username you enter
	fu = fopen("members.txt", "r"); //file pointer
	while (fread(&e[0], sizeof(user), 1, fu) > 0)
	{
		if (strcmp(a[0].username, e[0].username) == 0)
		{
			compare1 = 1; //if the username you entered is valid
		}
		j++;
	}
	j = 0;
	rewind(fu);
	fclose(fu);
	if (compare1 == 1) //if the username you entered is valid
	{
		fp = fopen("books.txt", "r");

		while (fread(&p[0], sizeof(book), 1, fp) > 0)
		{
			j++;
		}
		rewind(fp); //file pointer at inital position
		i = j;		//i will store number of books available in library to define size of array to store data
		j = 0;
		book c[i]; //array ok book to store
		while (j != i)
		{
			fread(&c[j], sizeof(book), 1, fp);
			j++; //storing data of book in array of size
		}
		fclose(fp);
		j = 0;
		printf("Following books in the library are available for issuing  :\n\n");
		if (i == 0)
		{
			printf("Currently ,no books are available in library.\n");
		}
		while (j != i) //displaying books available
		{
			printf("Title of book is:\t %s\n", c[j].booktitle);
			printf("Issue number of book is:\t %s \n", c[j].issueno);
			printf("Author of book is :\t%s \n", c[j].bookauthor);
			printf("Field to which book is related is :\t%s\n", c[j].fieldofbook);
			printf("---------------------------------\n");
			j++;
		}
		j = 0;
		printf("If book you wanted is not available just enter the name and author of book.\n");
		printf("Please enter the title  of book you want to issue :\t ");
		y = 0;
		fflush(stdin);
		scanf("%[^\n]%*c", b[0].booktitle);
		y = 0; //input book title
		printf("\nPlease enter the author of book you want to isssue:\t");
        fflush(stdin);
		scanf("%[^\n]%*c", b[0].bookauthor);
		while (j != i) //loop till numebr of books stored in array are read
		{
			if ((strcmp(c[j].bookauthor, b[0].bookauthor) == 0) && (strcmp(c[j].booktitle, b[0].booktitle) == 0))
			{
				compare = 1; //if the book title and author match
				l = j;
			};
			j++;
		}
		if (compare == 1) //if titile and author match copy book data,date and username and apped it in a file
		{
			time_t currentdate1;
			time(&currentdate1);
			strcpy(d[0].username, a[0].username);
			strcpy(d[0].booktitle, c[l].booktitle);
			strcpy(d[0].issueno, c[l].issueno);
			strcpy(d[0].bookauthor, c[l].bookauthor);
			strcpy(d[0].fieldofbook, c[l].fieldofbook);
			struct tm *tm = localtime(&currentdate1);
			d[0].day = tm->tm_mday;
			d[0].month = tm->tm_mon + 1;
			d[0].year = tm->tm_year + 1900;
			fe = fopen("userbooks.txt", "a");
			fwrite(&d[0], sizeof(userbook), 1, fe); //append the data if file
			rewind(fe);
			fclose(fe);
			printf("Book issued on your username.\n");
		}
		else
		{ //if book with userame and author not available in library
			printf("Book with this title and author not available.\n");
			printf("Please check notificaton to see if book is available.\n");
			pendingbook q[1]; //variable to copy pending book data and username assciated wtih it
			strcpy(q[0].username, a[0].username);
			strcpy(q[0].bookauthor, b[0].bookauthor);
			strcpy(q[0].booktitle, b[0].booktitle);
			fh = fopen("pendingbook.txt", "a");
			fwrite(&q[0], sizeof(pendingbook), 1, fh); //store username along with its pending book in file
			rewind(fh);
			fclose(fh);
		}
		if (compare == 1)
		{ //if book issued remove that book from our library
			if ((l + 1) == i)
			{
				fp = fopen("books.txt", "w"); //if book is the last one
				while (n != l)
				{
					fwrite(&c[n], sizeof(book), 1, fp);
					n++;
				}
				rewind(fp);
				fclose(fp);
			}
			else
			{
				for (n = l; n < i - 1; n++)
				{
					c[n] = c[n + 1];
				}
				fp = fopen("books.txt", "w"); //write the new data in our file as 1 book is issued
				for (n = 0; n < i - 1; n++)
				{
					fwrite(&c[n], sizeof(book), 1, fp);
				}
				rewind(fp);
				fclose(fp);
			}
		}
	}
	else
	{ //if username is incorrect
		printf("Username you entered is invalid.\n");
		booktransaction();
	}
}

void seeissuedbook()
{
	FILE *fp, *fl;
	user a[1], b[1];
	userbook c[1];
	int i, j = 0, p = 0, compare1 = 0, compare2 = 0;
	printf("Please enter your user name to see the books you issued:\t");
    fflush(stdin);
	scanf("%[^\n]%*c", a[0].username);
	fp = fopen("members.txt", "r"); //open the file where data of all members is stored
	while (fread(&b[0], sizeof(user), 1, fp) > 0)
	{
		if (strcmp(a[0].username, b[0].username) == 0)
		{
			compare1 = 1; //if the username you have input is valid
		}
		j++;
	}
	j = 0;
	rewind(fp); //used to move pointer to its initial position, not necessary
	fclose(fp);
	if (compare1 == 1)
	{
		printf("Following are the books you issued\n(please return the book within 15 days of issue date):\n\n");
		time_t currentdate1;
		time(&currentdate1);
		struct tm *date = localtime(&currentdate1);
		printf("Current date: %d/%d/%d \n\n", date->tm_mday, date->tm_mon + 1, date->tm_year + 1900); //display the current date
		fl = fopen("userbooks.txt", "r");															  //oen file where data of issued books is stored
		int x = 1;
		while (fread(&c[0], sizeof(userbook), 1, fl) > 0)
		{
			if (strcmp(a[0].username, c[0].username) == 0) //if the valid username has any books issued
			{
				compare2 = 1;
				printf("Title of the book you issued: %s \n", c[0].booktitle);
				printf("Issue number of book is: %s\n", c[0].issueno);
				printf("Author of book is : %s\n", c[0].bookauthor);
				printf("Field to which book is related is : %s\n", c[0].fieldofbook);
				printf("Date of isssue of book is : %d/%d/%d\n", c[0].day, c[0].month, c[0].year);
				printf("---------------------------------\n");
			}
			j++;
		}
		fclose(fl);
		if (compare2 == 0)
		{
			printf("You have not issued any book currently.\n");
		}
	}
	else //this else is if the username you entered is not valid
	{
		printf("The username you entered is invalid.\nPlease try again.\n ");
		printf("---------------------------------\n");
	}
}

void bookavailability()
{
	FILE *fp, *fd, *fc;
	user a[1], b[1];
	int compare1 = 0, compare = 0, compare2 = 0;
	pendingbook c[1];
	book d[1];
	printf("Enter your user name to check if book you wanted is available in library:");
    fflush(stdin);
	scanf("%[^\n]%*c", a[0].username);
	fp = fopen("members.txt", "r");
	while (fread(&b[0], sizeof(user), 1, fp) > 0) //read members.txt to check if user exist
	{
		if (strcmp(a[0].username, b[0].username) == 0)
		{
			compare = 1; //if member exist
		}
	}
	rewind(fp);
	fclose(fp);
	if (compare == 1) //if member exist
	{
		fd = fopen("pendingbook.txt", "r");
		fc = fopen("books.txt", "r");
		if (fd == NULL)
		{

			printf("No book  reservation is pending.\n"); //no book reservation of enyone is pending
		}
		else
		{
			while (fread(&c[0], sizeof(pendingbook), 1, fd) > 0) //loop to read all all data from file
			{
				while (fread(&d[0], sizeof(book), 1, fc) > 0) //loop to read if the book is available in library(for each pending booksee all books of our library
				{
					compare2 = 0; //so that we can check for each book
					if ((strcmp(c[0].booktitle, d[0].booktitle) || strcmp(c[0].bookauthor, d[0].bookauthor) || strcmp(c[0].username, a[0].username)) == 0)
					{ //here we have have checked the user which wanted book and the book author and book title
						printf("Book available in library.\n");
						printf("Title of book: %s\n", c[0].booktitle);
						printf("Author of book: %s\n", c[0].bookauthor);
						printf("Please cancel the reservation after issuing this book.\n"); // as we need to manually deleted eservation after the book is issued
						compare2 = 1;														//if book available
					}
				}
				rewind(fc); //after reading data from library move pointer t initial poit so that in next while loop it can read again
				if (strcmp(c[0].username, a[0].username) == 0 && compare2 == 0)
				{
					printf("Book with title %s is not available\n", c[0].booktitle);
					compare1 = 1; //if book is pendng but not available i.e. username you entered has a pending book on its name
				}
			}
			if (compare1 == 0 && compare2 == 0) //no book pending
			{
				printf("Currently you have no book reservation pending.\n");
			}
		}
		fclose(fd); //for pendingbooks.txt
		fclose(fc); //for books.txt
	}
	else //if username you entered did not match
	{
		printf("The username you entered is incorrect.\nPlease try again.\n");
	}
}

void cancelreservation()
{
	user a[1], b[1];
	FILE *fp, *fc, *fd;
	int i, j = 0, k, compare = 0, compare1 = 0, compare2 = 0;
	pendingbook c[1], e[1];
	printf("Enter you username to cancel the pending \nreservation of book which was not available:");
    fflush(stdin);
	scanf("%[^\n]%*c", a[0].username);
	fp = fopen("members.txt", "r"); // read file which has all usernames in it
	while (fread(&b[0], sizeof(user), 1, fp) > 0)
	{
		if (strcmp(a[0].username, b[0].username) == 0)
		{
			compare = 1; //if username is valid
		}
	}
	rewind(fp);
	fclose(fp);
	if (compare == 1) //if username is valid
	{
		printf("You have following books pending in reservation.\n");
		fc = fopen("pendingbook.txt", "r"); //ope file which have stored data of ending books
		while (fread(&c[0], sizeof(pendingbook), 1, fc) > 0)
		{
			if (strcmp(a[0].username, c[0].username) == 0) //if th username matches with username of any pending book
			{
				printf("Name of book: %s \n", c[0].booktitle);
				printf("Author of book: %s \n", c[0].booktitle);
				printf("---------------------------------\n");
				compare1 = 1; //pending book on username found
			}
			j++; //counts total number of pending books
		}
		rewind(fc);
		i = j;
		j = 0;
		pendingbook d[i];									 //determinig the size of array which we need to store books so that no extra space is occupied
		while (fread(&d[j], sizeof(pendingbook), 1, fc) > 0) //store data of pending books in array
		{
			j++;
		}
		fclose(fc);
		j = 0;
		if (compare1 == 1) //if username with pending books found
		{
			printf("Enter the title of book which you want to cancel reservation:");
			fflush(stdin);
			scanf("%[^\n]%*c", e[0].booktitle);

			printf("Enter the author of book which you want to cancel reservation:");
			fflush(stdin);
			scanf("%[^\n]%*c", e[0].bookauthor);
			while (j != i) //loop to read all pending books
			{
				if ((strcmp(a[0].username, d[j].username) || strcmp(e[0].bookauthor, d[j].bookauthor) || strcmp(e[0].booktitle, d[j].booktitle)) == 0)
				//used || as strcmp gives 0 if strings are same
				{
					k = j;		  //to store which element of pendingbooks is deleted
					compare2 = 1; //if  pending book wth this username book author and title found
				}
				j++;
			}
			if (compare2 == 1) //if  pending book wth this username book author and title found
			{
				if (k + 1 == i)
				{
					fd = fopen("pendingbook.txt", "w");
					i = 0;
					while (i != k) //write new array of pendingbooks on file
					{
						fwrite(&d[i], sizeof(pendingbook), 1, fd);
						i++;
					}
					fclose(fd);
					printf("Reservation of book deleted.\n");
				}
				else
				{
					for (j = k; j < i - 1; j++)
					{
						d[j] = d[j + 1]; // delete the reservation from array
					}
					fd = fopen("pendingbook.txt", "w");
					i = 0;
					while (i != j) //write new array of pendingbooks on file
					{
						fwrite(&d[i], sizeof(pendingbook), 1, fd);
						i++;
					}
					fclose(fd);
					printf("Reservation of book deleted.\n");
				}
			}
			else // if username has pending books but book details are invalid
			{
				printf("The details of book yu entered are invalid.\n");
			}
		}
		else //if no books are pending on uername
		{
			printf("You donot have any pending reservation.\n");
		}
	}
	else //if username you entered is invalid
	{
		printf("The username you entered is invalid.\n");
	}
}

void returnbook()
{
	user a[1], b[1];
	FILE *fp, *fc, *fd;
	int i, k, compare = 0, compare1 = 0, compare2 = 0;
	userbook c[1], f[1];
	book d[1];
	printf("Enter you username to return the book:\t");
	fflush(stdin);
	scanf("%[^\n]%*c", a[0].username);
	fp = fopen("members.txt", "r");
	while (fread(&b[0], sizeof(user), 1, fp) > 0)
	{
		if (strcmp(a[0].username, b[0].username) == 0)
		{
			compare = 1; //if user is member of library
		}
	}
	rewind(fp);
	fclose(fp);
	if (compare == 1)
	{
		int j = 0;
		fc = fopen("userbooks.txt", "r");
		while (fread(&f[0], sizeof(userbook), 1, fc) > 0)
		{
			if (strcmp(a[0].username, f[0].username) == 0) //if any books are issued on  name of member of library display them
			{
				printf("Title of the book you issued: %s \n", f[0].booktitle);
				printf("Issue number of book is: %s\n", f[0].issueno);
				printf("Author of book is : %s\n", f[0].bookauthor);
				printf("Field to which book is related is : %s\n", f[0].fieldofbook);
				printf("Date of isssue of book is : %d/%d/%d\n", f[0].day, f[0].month, f[0].year);
				printf("---------------------------------\n");
				compare2 = 1;
			}
			j++;
		}
		if (compare2 == 1)
		{
			printf("Enter the issue number of book you want to return:");
			fflush(stdin);
			scanf("%[^\n]%*c", c[0].issueno);
			rewind(fc);
			i = j;
			j = 0;
			userbook e[i];
			while (fread(&e[j], sizeof(userbook), 1, fc) > 0)
			{
				if ((strcmp(e[j].issueno, c[0].issueno) || strcmp(e[j].username, a[0].username)) == 0)
				{
					compare1 = 1; //if the member has book of issue number it gave input
					//copy data to rturn it to books.txt
					strcpy(d[0].booktitle, e[j].booktitle);
					strcpy(d[0].issueno, e[j].issueno);
					strcpy(d[0].bookauthor, e[j].bookauthor);
					strcpy(d[0].fieldofbook, e[j].fieldofbook);
					k = j; //store the number of element to be delete from userbook
				}
				j++;
			}
			j = 0;
			fclose(fc);
			if (compare1 == 1)
			{
				if (k + 1 == i)
				{
					i = 0;
					fc = fopen("userbooks.txt", "w");
					while (i != k)
					{
						fwrite(&e[i], sizeof(userbook), 1, fc);
						i++;
					}
					fclose(fc);
					fd = fopen("books.txt", "a");
					fwrite(&d[0], sizeof(book), 1, fd); //append te book back to our library
					fclose(fd);
					printf("Book successfully returned .");
				}
				else
				{
					for (j = k; j < i - 1; j++)
					{
						e[j] = e[j + 1]; //delete the kth element from userbook
					}
					i = 0;
					fc = fopen("userbooks.txt", "w");
					while (i != j)
					{
						fwrite(&e[i], sizeof(userbook), 1, fc);
						i++;
					}
					fclose(fc);
					fd = fopen("books.txt", "a");
					fwrite(&d[0], sizeof(book), 1, fd); //append te book back to our library
					fclose(fd);
					printf("Book successfully returned .");
				}
			}
			else //if member entered invalid issue number
			{
				printf("There is no such book with this issue number issued on your username.\n");
			}
		}
		else //if member has not issued any book
		{
			printf("You have not issued any book.\n");
		}
	}
	else // if usename entered is not a member of our library
	{
		printf("The username you entered is invalid.\n");
	}
}

void inventorymanagement()
{
	book a[1], c[1];
	char d;
	FILE *fp;
	int i = 0, j, k, l = 0;
	fp = fopen("books.txt", "r");
	while (fread(&c[0], sizeof(book), 1, fp))
	{
		l++; //number of books in library
	}
	i = l;
	l = 0;
	book b[i];	//array of size required to store all books in library
	rewind(fp); //file pointer at initial position
	while (fread(&b[l], sizeof(book), 1, fp))
	{
		l++; //read all books
	}
	fclose(fp);
	while (d != 3)
	{
		printf("\n\n|      INVENTORY MANAGEMENT     |\n\n");
		printf("Enter 1 to count the number of all books of a particular title.\n");
		printf("Enter 2 to return to main menu.\n");
		printf("Enter 3 to exit program.\n");
		printf("---------------------------------\n");
		scanf(" %c", &d);
		getchar();
		system("cls||clear");
		switch (d)
		{
		case '1':
			printf("Write the title of book to get count:\t");
			fflush(stdin);
			scanf("%[^\n]%*c", a[0].booktitle);
			j = 0;
			k = 0;
			while (j != i) //read all books from array b[j]
			{
				if (strcmp(b[j].booktitle, a[0].booktitle) == 0)
				{
					k++; //store total books of same title
				}
				j++;
			}
			printf("The number of books with the title you entered are %d\n", k);
			printf("---------------------------------\n");
			break;
		case '2':
			menu(); //return to menu
			break;
		case '3':
			exit(1);
			break;
		default:
			printf("Try gain\n");
		}
	}
}

void vendormanagement()
{
	char h;
	while (1) //infinite loop tilluser reutrn to main menu or exits
	{
		printf("\n\n|      VENDOR MANAGEMENT     |\n\n");
		printf("NOTE- Enter a dfferent issue number from the number already in use\n\tof storing book data.\n");
		printf("Enter 1 to add any book to our library from a vendor.\n");
		printf("Enter 2 to add any book to our library from collaborated libraries\n\tto our library.\n");
		printf("Enter 3 to return to main menu.\n");
		printf("Enter 4 to exit program.\n");
		printf("---------------------------------\n");
		scanf("%c", &h);
		system("cls||clear");
		getchar();
		switch (h)
		{
		case '1':
			addbookfromvendor();
			break;
		case '2':
			adbookfrootherlibraries();
			break;
		case '3':
			menu();
			break;
		case '4':
			exit(1);
		default:
			printf("Try again.\n");
		}
	}
}

void addbookfromvendor()
{
	FILE *fp, *fd, *fc;
	book a[1], c[1];
	int i, j, validissuenumber, l = 0, n = 0, o = 0, p = 0, q = 0, y = 0;
	fc = fopen("books.txt", "r");
	while (fread(&c[0], sizeof(book), 1, fc) > 0)
	{
		l++; //number of books in library
	}
	rewind(fc);
	i = l;
	book b[i];
	l = 0;
	while (fread(&b[l], sizeof(book), 1, fc) > 0)
	{
		l++; //store data of all books so that we can check if issue number of book added is different or not
	}
	fclose(fc);
	j = 0;
	validissuenumber = 1;
	printf("Enter the details of book you want to add in library:\n");
	printf("Enter the title of book:\t");
	fflush(stdin);
	scanf("%[^\n]%*c", a[0].booktitle);

	if (strlen(a[0].booktitle) <= 28)
	{
		n = 1; //to chec if book title is within the rang
	}
	printf("\nEnter the issue number of book :\t");

	fflush(stdin);
	scanf("%[^\n]%*c", a[0].issueno);
	if (strlen(a[0].issueno) <= 28)
	{
		o = 1; //to check if issue number is within the rage
	}
	printf("\nEnter the author name:\t");
	fflush(stdin);
	scanf("%[^\n]%*c", a[0].bookauthor);
	if (strlen(a[0].bookauthor) <= 28)
	{
		p = 1; //to check if book author is within the range
	}
	printf("\nEnter the field of book :\t");
	fflush(stdin);
	scanf("%[^\n]%*c", a[0].fieldofbook);

	if (strlen(a[0].fieldofbook) <= 29)
	{
		q = 1; //to check if field of book is not within the range
	}
	while (j != i)
	{
		if (strcmp(a[0].issueno, b[j].issueno) == 0) //to check if issue number entered already exist or not
		{
			validissuenumber = 0;
			printf("The issue number you enetered already exists.\n");
			printf("Book not added to our library\n");
			printf("Please try again.\n");
		}
		j++;
	}
	if (n == 0)
	{
		printf("The book title you wrote is too long .\n");
		printf("Book not added to our library\n");
	}
	if (o == 0)
	{
		printf("The book title you wrote is too long.\n");
		printf("Book not added to our library\n");
	}
	if (p == 0)
	{
		printf("The book author name  you wrote is too long .\n");
		printf("Book not added to our library\n");
	}
	if (q == 0)
	{
		printf("The book field you wrote is to long .\n");
		printf("Book not added to our library\n");
	}
	if ((validissuenumber == 1) && (n == 1) && (o == 1) && (p == 1) && (q == 1)) //if everything added is within the range
	{
		fp = fopen("newbooks.txt", "a"); //new books added will be displayed on welcome page
		fd = fopen("books.txt", "a");	 //append books in our library
		fwrite(&a[0], sizeof(book), 1, fd);
		fwrite(&a[0], sizeof(book), 1, fp);
		printf("book added to our library.\n");
		fclose(fd);
		fclose(fp);
	}
	else
	{
		printf("Try again.\n\n");
	}
	j = 0;
}

void adbookfrootherlibraries() //here code is same as add book from vendor only title is add book from other libraries hence no cooments needed
{
	FILE *fp, *fd, *fc;
	book a[1], c[1];
	int i, j, validissuenumber, l = 0, n = 0, o = 0, p = 0, q = 0, y = 0;
	fc = fopen("books.txt", "r");
	while (fread(&c[0], sizeof(book), 1, fc) > 0)
	{
		l++;
	}
	rewind(fc);
	i = l;
	l = 0;
	book b[i];
	while (fread(&b[l], sizeof(book), 1, fc) > 0)
	{
		l++;
	}
	fclose(fc);
	j = 0;
	validissuenumber = 1;
	printf("Enter the details of book you want to add to our library.\n");
	printf("Enter the title of book :\t");
	y = 0;
	fflush(stdin);
	scanf("%[^\n]%*c", a[0].booktitle);
	if (strlen(a[0].booktitle) <= 28)
	{
		n = 1;
	}
	printf("Enter the issue number of book:\t");
	y = 0;
	fflush(stdin);
	scanf("%[^\n]%*c", a[0].issueno);
	if (strlen(a[0].issueno) <= 28)
	{
		o = 1;
	}
	printf("Enter the author name :\t");
	fflush(stdin);
	scanf("%[^\n]%*c", a[0].bookauthor);
	if (strlen(a[0].bookauthor) <= 28)
	{
		p = 1;
	}
	printf("Enter the field of book :\t");
	fflush(stdin);
	scanf("%[^\n]%*c", a[0].fieldofbook);
	if (strlen(a[0].fieldofbook) <= 28)
	{
		q = 1;
	}
	while (j != i)
	{
		if (strcmp(a[0].issueno, b[j].issueno) == 0)
		{
			validissuenumber = 0;
			printf("The issue number you enetered already exists.\n");
			printf("Book not added to our library\n");
			printf("Please try again.\n");
		}
		j++;
	}
	if (n == 0)
	{
		printf("The book title you wrote is too long .Write title within 30 characters .\n");
		printf("Book not added to our library\n");
	}
	if (o == 0)
	{
		printf("The book issue number you wrote is too long.\n Write issue number within 5 characters or integer.\n");
		printf("Book not added to our library\n");
	}
	if (p == 0)
	{
		printf("The book author name  you wrote exceeds 30 characters .\n");
		printf("Book not added to our library\n");
	}
	if (q == 0)
	{
		printf("The book field you wrote exceeds 30 characters .\n");
		printf("Book not added to our library\n");
	}
	if ((validissuenumber == 1) && (n == 1) && (o == 1) && (p == 1) && (q == 1))
	{
		fp = fopen("newbooks.txt", "a");
		fd = fopen("books.txt", "a");
		fwrite(&a[0], sizeof(book), 1, fd);
		fwrite(&a[0], sizeof(book), 1, fp);
		printf("book added to our library.\n");
		fclose(fd);
		fclose(fp);
	}
	else
	{
		printf("Try again.\n");
	}
	j = 0;
}

void member_management()
{
	char d;
	while (d != 5) //infinite loop till we return to main menu or exit
	{
		printf("\n\n|      MEMBER MANAGEMENT     |\n\n");
		printf("Press 1) to see the members\n");
		printf("Press 2) to add a member\n");
		printf("Press 3) to delete a member\n");
		printf("press 4) to see notifications about returning book.\n");
		printf("Press 5) to go back to the main menu\n");
		printf("Press 6) to exit program\n");
		printf("---------------------------------\n");
		scanf(" %c", &d);
		getchar();
		system("cls||clear");
		switch (d)
		{
		case '1':
			see_member();
			break;
		case '2':
			add_member();
			break;
		case '3':
			delete_member();
			break;
		case '4':
			notification();
			break;
		case '5':
			menu();
			break;
		case '6':
			exit(1);
			break;
		default:
			printf("Please enter a valid option\n");
		}
	}
}

void see_member() //to display member list
{
	user a[1];
	FILE *fptr;
	int see = 1;
	fptr = fopen("members.txt", "r"); //acess members list
	while (fread(&a[0], sizeof(user), 1, fptr) > 0)
	{
		see = 0;
		printf("username:    %s\n", a[0].username); //list only name not passsword
		printf("---------------------------------\n");
	}
	if (see != 0)
	{
		printf("The member list is empty\n");
	}
	fclose(fptr);
}

void add_member()
{
	user a[1], b[1];
	int i = 0, p = 0, y = 0;
	FILE *fptr;
	int add = 1, compare;

	printf("Enter the username of member :\t");
	y = 0;
	fflush(stdin);
	scanf("%[^\n]%*c", a[0].username);

	if (strlen(a[0].username) < 29)
	{
		i = 1; //to check if username f member is not too long
	}

	printf("\nEnter the password of member:\t");
	y = 0;
	fflush(stdin);
	scanf("%[^\n]%*c", a[0].password);

	if (strlen(a[0].password) < 29)
	{
		p = 1; //to check if username f member is not too long
	}

	fptr = fopen("members.txt", "r");
	while (fread(&b[0], sizeof(user), 1, fptr) > 0)
	{
		compare = strcmp(b[0].username, a[0].username);
		if (compare == 0)
		{
			printf("Such an username already exist\n"); //if member with same username exist
			add = 0;
			break;
		}
	}
	fclose(fptr);
	if (i == 0) //if username is not within limits
	{
		printf("The user name you enetered is too long.\n");
		printf("Member not added.\n");
	}
	if (p == 0) //if password is not within limits
	{
		printf("The password you added is too long.\n");
		printf("Member not added.\n");
	}
	if ((add != 0) && (p == 1) && (i == 1)) //add member is username is different and username, password are within limits
	{
		fptr = fopen("members.txt", "a");
		fwrite(&a[0], sizeof(user), 1, fptr);
		fclose(fptr);
		printf("Member is added\n");
	}
}

void delete_member()
{
	int i, j = 0, l = 0, k, m=0, compareusername = 0, comparepassword = 0, y = 0;
	user a[1], c[1];
	FILE *fptr;
	fptr = fopen("members.txt", "r");
	while (fread(&c[0], sizeof(user), 1, fptr) > 0)
	{
		m++; //read the number of members in members.txt
	}
//	printf("%d",m);

	rewind(fptr);
	i = m;
	m = 0;
	user b[i];										//aray of size of the number of members
	while (fread(&b[m], sizeof(user), 1, fptr) > 0) //read data from fptr to our array
	{
		m++;
	}
	fclose(fptr);
	printf("Enter the username of member you want to delete:\t");
	y = 0;
	//    while((a[0].username[y] =getchar()) !='\n')
	//    {
	//    	y++;//enter the username of member you want to delete
	//	}
	//    a[0].username[y]='\0';

	fflush(stdin);
	scanf("%[^\n]%*c", a[0].username);
	y = 0;
	printf("Enter the password of member you want to delete:\t");
	y = 0;
	//    while((a[0].password[y] =getchar()) !='\n')
	//    {
	//    	y++;//enter the password of member you want t delete
	//	}
	//    a[0].password[y]='\0';

	fflush(stdin);
	scanf("%[^\n]%*c", a[0].password);
	y = 0;
	while (j != i)
	{
		if (strcmp(b[j].username, a[0].username) == 0)
		{
			l = j;				 //location in array of member to be deleted
			compareusername = 1; //if username of member you want to delete is correct
		}
		if (strcmp(b[j].password, a[0].password) == 0)
		{
			comparepassword = 1; //if password  of member you want to delete is correct
		}
		j++;
	}
//	printf("%d",j);
	if (j > 1)
	{
		if ((compareusername == 1) && (comparepassword == 1)) //if username and password are correct
		{
			if ((l + 1) == i)
			{
				fptr = fopen("members.txt", "w");
				i = 0;
				while (i != l)
				{
					fwrite(&b[i], sizeof(user), 1, fptr);
					i++;
				}
				fclose(fptr);
				printf("member deleted\n");
			}
			else
			{
				for (k = l; k < i - 1; k++)
				{
					b[k] = b[k + 1];
				}
				fptr = fopen("members.txt", "w");
				i = 0;
				while (i != k)
				{
					fwrite(&b[i], sizeof(user), 1, fptr); //write the new content
					i++;
				}
				fclose(fptr);
				printf("Member deleted.\n");
			}
		}
		else if ((compareusername == 1) && (comparepassword == 0)) //if username correct but password incorrect
		{
			printf("The password you entered is incorrect.\n");
			printf("Try again.\n");
		}
		else if ((compareusername == 0) && (comparepassword == 1)) //if username is incorrect but password is correct
		{
			printf("The username you entered is incorrect.\n");
			printf("Try again.\n");
		}
		else //if both are incorrect
		{
			printf("The username and password you enetered are incorrect.\n");
			printf("Try again.\n");
		}
	}
	else //if only 1 member present in library donot delete members
	{
		printf("You cannot deleted member as at least one member is neccessary for login.\n");
	}
}

void notification()
{
	FILE *fp, *fd;
	user a[1], b[1];
	userbook c[1];
	int i, j = 0, compare1 = 0, compare2 = 0, y = 0;
	printf("Please enter your user name to see notifications:\t");
	y = 0;
	//    while((a[0].username[y] =getchar()) !='\n')
	//    {
	//    	y++;//get username as a string
	//	}
	//    a[0].username[y]='\0';

	fflush(stdin);
	scanf("%[^\n]%*c", a[0].username);
	y = 0;
	fp = fopen("members.txt", "r");
	while (fread(&b[0], sizeof(user), 1, fp) > 0)
	{
		if (strcmp(a[0].username, b[0].username) == 0)
		{
			compare1 = 1; //check if username is correct
		}
		j++;
	}
	j = 0;
	fclose(fp);
	if (compare1 == 1) //if username is correct
	{
		printf("Following are the books you issued(please return the book\n within 15 days of issue date):\n\n");
		time_t currentdate1;
		time(&currentdate1);
		struct tm *date = localtime(&currentdate1);
		printf("Current date: %d/%d/%d \n\n", date->tm_mday, date->tm_mon + 1, date->tm_year + 1900); //display current date
		fd = fopen("userbooks.txt", "r");
		while (fread(&c[0], sizeof(userbook), 1, fd) > 0)
		{
			if (strcmp(a[0].username, c[0].username) == 0) //check if username of member has issued any book and display it
			{
				compare2 = 1; //if member has issued any book
				printf("Title of the book you issued: %s \n", c[0].booktitle);
				printf("Issue number of book is: %s\n", c[0].issueno);
				printf("Author of book is : %s\n", c[0].bookauthor);
				printf("Field to which book is related if : %s\n", c[0].fieldofbook);
				printf("Date of isssue of book is : %d/%d/%d\n\n", c[0].day, c[0].month, c[0].year); //date of  issue of book was stored while issuing
				printf("---------------------------------\n");
				//downward code to show days left out of 15 and if excee 15 return book
				if (((c[0].day) % 4) == 0) //if it is leap year
				{
					if (((c[0].month) == 1) || ((c[0].month) == 3) || ((c[0].month) == 5) || ((c[0].month) == 7) ||
						((c[0].month) == 8) || ((c[0].month) == 10) || ((c[0].month) == 12)) //months with 31 days
					{
						if (((date->tm_mday) - (c[0].day)) >= 0) //implies month has not changed as next day in month will be greater or equal to previous
						{
							if (((date->tm_mday) - (c[0].day) <= 15)) //if current day is less than 15 days of issue
							{
								printf("Days left to return book:%d\n", 15 - ((date->tm_mday) - (c[0].day))); //15-days over
							}
							else
							{
								printf("NOTIFICATION: PLease return the book you issued.\n");
							}
						}
						else //if month has changed
						{
							if ((31 - (c[0].day) + (date->tm_mday)) <= 15) //if 15 days are not over
							{
								printf("Days left to return book: %d\n", 15 - (31 - (c[0].day) + (date->tm_mday))); //15-((31-issueday)+date of nextmonth)
							}
							else
							{
								printf("NOTIFICATION: Please return this book\n");
							}
						}
					}
					else if (((c[0].month) == 4) || ((c[0].month) == 6) || ((c[0].month) == 9) || ((c[0].month) == 11)) //if month is with 30 days
					{																									//other everything same as above only 30 used insted of 31
						if (((date->tm_mday) - (c[0].day)) >= 0)
						{
							if (((date->tm_mday) - (c[0].day) <= 15))
							{
								printf("Days left to return book:%d\n", 15 - ((date->tm_mday) - (c[0].day)));
							}
							else
							{
								printf("NOTIFICATION: PLease return the book you issued.\n");
							}
						}
						else
						{
							if ((30 - (c[0].day) + (date->tm_mday)) <= 15)
							{
								printf("Days left to return book: %d\n", 15 - (30 - (c[0].day) + (date->tm_mday)));
							}
							else
							{
								printf("NOTIFICATION: Please return this book\n");
							}
						}
					}
					else
					{ //all explnantion same butused 29 as last day of month as it is feb and leap year
						if (((date->tm_mday) - (c[0].day)) >= 0)
						{
							if (((date->tm_mday) - (c[0].day) <= 15))
							{
								printf("Days left to return book:%d\n", 15 - ((date->tm_mday) - (c[0].day)));
							}
							else
							{
								printf("NOTIFICATION: PLease return the book you issued.\n");
							}
						}
						else
						{
							if ((29 - (c[0].day) + (date->tm_mday)) <= 15)
							{
								printf("Days left to return book: %d\n", 15 - (29 - (c[0].day) + (date->tm_mday)));
							}
							else
							{
								printf("NOTIFICATION: Please return this book\n");
							}
						}
					}
				}
				else //here everything same as above if only it is not a leap year so last day of feb is 28
				{
					if (((c[0].month) == 1) || ((c[0].month) == 3) || ((c[0].month) == 5) || ((c[0].month) == 7) ||
						((c[0].month) == 8) || ((c[0].month) == 10) || ((c[0].month) == 12))
					{
						if (((date->tm_mday) - (c[0].day)) >= 0)
						{
							if (((date->tm_mday) - (c[0].day) <= 15))
							{
								printf("Days left to return book:%d\n", 15 - ((date->tm_mday) - (c[0].day)));
							}
							else
							{
								printf("NOTIFICATION: PLease return the book you issued.\n");
							}
						}
						else
						{
							if ((31 - (c[0].day) + (date->tm_mday)) <= 15)
							{
								printf("Days left to return book: %d\n", 15 - (31 - (c[0].day) + (date->tm_mday)));
							}
							else
							{
								printf("NOTIFICATION: Please return this book\n");
							}
						}
					}
					else if (((c[0].month) == 4) || ((c[0].month) == 6) || ((c[0].month) == 9) || ((c[0].month) == 11))
					{
						if (((date->tm_mday) - (c[0].day)) >= 0)
						{
							if (((date->tm_mday) - (c[0].day) <= 15))
							{
								printf("Days left to return book:%d\n", 15 - ((date->tm_mday) - (c[0].day)));
							}
							else
							{
								printf("NOTIFICATION: PLease return the book you issued.\n");
							}
						}
						else
						{
							if ((30 - (c[0].day) + (date->tm_mday)) <= 15)
							{
								printf("Days left to return book: %d\n", 15 - (30 - (c[0].day) + (date->tm_mday)));
							}
							else
							{
								printf("NOTIFICATION: Please return this book\n");
							}
						}
					}
					else //if feb
					{
						if (((date->tm_mday) - (c[0].day)) >= 0)
						{
							if (((date->tm_mday) - (c[0].day) <= 15))
							{
								printf("Days left to return book:%d\n", 15 - ((date->tm_mday) - (c[0].day)));
							}
							else
							{
								printf("NOTIFICATION: PLease return the book you issued.\n");
							}
						}
						else
						{
							if ((28 - (c[0].day) + (date->tm_mday)) <= 15)
							{
								printf("Days left to return book: %d\n", 15 - (28 - (c[0].day) + (date->tm_mday)));
							}
							else
							{
								printf("NOTIFICATION: Please return this book\n");
							}
						}
					}
				}
				printf("---------------------------------\n");
			}
			j++;
		}
		fclose(fd);
		if (compare2 == 0)
		{
			printf("You have not issued any book currently.\n");
		}
	}
	else
	{
		printf("The username you entered is invalid.\nPlease try again.\n ");
		printf("---------------------------------\n");
	}
}
