## Library_Management_System
I developed a simple library management system using C language.
#### (Will be needed to start program)  Default username = default
#### (Will be needed to start program)  Default password = default
Instructions to run program
No executable file sent, it is a single .c file so directly compile it manually on your machine using gcc.
Note1-  Members have username and password which you require to run program.
 (Will be needed to start program)  Default username = default
 (Will be needed to start program)  Default password = default
Note2- the program is case sensitive(Books with name in same case will only be cosidered same)
Note3- Whenever code asks for press 1 or anything similar to continue press enter after that.
Note4- You need username to issue books ,so you can add username from member management.
Note5- Same username cannot be added ,similarly books with same issue cannot be added to our library
Note6 -Initially 2 books are added with issue number 1,2 respectively and other details .

1. The input files are :-
   members.txt      - to store the data of all the members of the library.(Username , password)
   books.txt        - to store all the books present in the library.(to store books available in library.)
   pendingbooks.txt - to store books which were not when user tried to issue available.(books
   you tried to issue but were not in library.)
   userbook.txt     - to store books issued by user.
   newbooks.txt     - to store new books added in our library.(this will show new books on welcome page.) 

2. The names of all the books,fields and authors are case sensitive.
   Username and password are also case sensitive.

4. When you run the the file, it will prompt you to enter the username and password.
   This page will also show the list of books newly added in the library.(initially it will not show )
   ONLY THE MEMBERS OF THE LIBRARY CAN LOGIN.
   So you will have to use 
   Username - default
   Password - default
   when you are logging in for the FIRST TIME.
   Later on you can add yourself as a member and use the credentials you entered to login.

5. You'll have to add a member before using any functionalities of this program.

6. The next prompt will show you the main menu.
   Although you will be guided on each and every level by appropriate instructions, you can 
   also refer to the points mentioned below.
   After login you will be guided to main mneu.
   MAIN  MENU 
  1) Book Management System Press 1(Press enter after that)
      - Press 1 to search book by name/title.
      - Press 2 to search book by issue number.
      - Press 3 to search all the books by the same author.
      - Press 4 to search all the books related to the same field(civil,mechanical etc).
      - Press 5 to return to main menu 
      - Press 6 to exit  
        (press enter after any character) 
  2) For making any BOOK TANSACTION Press 2.(Press enter after that)
      (For issuing or returning a book you will need a VALID USERNAME).
      (You need valid username for all)
      - Press 1 to issue a book.(You need correct username for it so better  add member or use default 
                                 as username.)
      - Press 2 to check the books issued by you. press enter then (Again you need username)
      - Press 3 to check if book you wanted is available(if same book you tried to issue is added to library it is available)
      - Press 4 cancel reservation (if you have issued book you wanted cancel reservation of that bookso you will
                                     not get botification)
      - Press 5 to return any book you issued.
      
   3) For using Vendor Management System Press 3.
      (You  can ADD BOOKS to the library via this system but the issue number you enter should be DIFFERENT.)
      (You can add a book which is ALREADY PRESENT in the library with different issue number).
      After that 
      - Press 1 to add a book from a vendor.(ADD any book to our library from vendor) 
      - Press 2 to add a book from any other collaborated library.(ADD any book to our library from other libraries  
  
  4) For using Inventory Management System Press 4.
      After that Press 1 to count the number of books of a particular title.
     (Then enter and insite it title of book then enter)
     
   5) For using Member Management System Press 5.(Press enter after that
      After that 
      - Press 1 to see the current members.(After 1 press enter)
      - Press 2 to add a member, enter the username and password.(After 2 press enter)
                (You can only add a member with DIFFERENT USERNAME).
      - Press 3 to delete a member, enter the username and password you want to delete.(After 3 press enter)
                (You cannot delete ALL THE MEMBERS, ATLEAST ONE MEMBER will be there).
      - Press 4 to see the notification of returning the book.(HERE IF 15 DAYS ARE NOT OVER IT WILL SHOW DAYS
                      (After 4 press enter)        ELSE NOTIFICATION OF RETURN BOOK BUT YOU NEED TO WRITE USERNAME)
