/*************************************************************************
 CLASS INFORMATION
 -----------------
   Program Name: program09
   Programmer:   Ian Mason
   Instructor:   Mr. Plain for CS 214-1, C Programming
   Date Due:     11/18/2021

 DOCUMENTATION
 -------------
   This program will list the type of characters in a file based on the user input.
 ************************************************************************/
#include <stdio.h>
#include <ctype.h>

#define ALL_OPTION  1
#define ALPHA_CHARS 2
#define DIGIT_CHARS 3
#define PUNCT_CHARS 4
#define SPACE_CHARS 5
#define QUIT        6

void printInstructions();
void printMenu        ();
int  getMenuChoice    ();
int  processFile      (int choice);
void printResult      (int choice, int result);
void printGoodbye     ();

int main()
{
   int charCount,
       menuChoice;
  
   printInstructions();
   printMenu();
  
   menuChoice = getMenuChoice();
   
   while(menuChoice != QUIT)
   {
      switch (menuChoice)
      {
         case ALPHA_CHARS:
         case DIGIT_CHARS:
         case PUNCT_CHARS:
         case SPACE_CHARS:
            charCount = processFile(menuChoice);
            printResult(menuChoice, charCount);
            break;
         case ALL_OPTION:
            charCount = processFile(ALPHA_CHARS);
            printResult(ALPHA_CHARS, charCount);

            charCount = processFile(DIGIT_CHARS);
            printResult(DIGIT_CHARS, charCount);

            charCount = processFile(PUNCT_CHARS);
            printResult(PUNCT_CHARS, charCount);

            charCount = processFile(SPACE_CHARS);
            printResult(SPACE_CHARS, charCount);
            break;  
         default:
            printf("Unknown choice.");
            break;
      }
      printMenu();
      menuChoice = getMenuChoice();
   }
  
   printGoodbye();
  
   return 0;
}

/*************************************************************************
this function prints the instructions.
 ************************************************************************/
void printInstructions()
{
   printf("This program counts the characters in a file based on the type of character\n\n");

   return;
}

/*************************************************************************
This function prints the menu to the user.
 ************************************************************************/
void printMenu()
{
   printf("------------------------\n");
   printf("%d – All Results\n", ALL_OPTION);
   printf("%d – Alphabetic Characters\n", ALPHA_CHARS);
   printf("%d – Digit Characters\n", DIGIT_CHARS);
   printf("%d – Punctuation Characters\n", PUNCT_CHARS);
   printf("%d – Whitespace Characters\n", SPACE_CHARS);
   printf("%d - Quit\n", QUIT);

   return;
}

/*************************************************************************
 This function gets the menu choice from the user.
 ************************************************************************/
int  getMenuChoice()
{
   int menu;
   scanf(" %d", &menu);
   while (menu < ALL_OPTION || menu > QUIT)
      {
        printf("please enter a valid option\n");
        scanf(" %d", &menu);
      }

   return menu;
}
/*************************************************************************
This function sorts out each character by type.
 ************************************************************************/
int  processFile (int choice)
{
   int count = 0;
   char fileChar;
   FILE* input09;
   input09 = fopen("input09.txt", "r");

   if(input09 == NULL)
   {
     printf("error opening file\n\n");
     return 0;
   }
   while((fileChar = fgetc(input09))!= EOF)
   {
      if(choice == ALPHA_CHARS && isalpha(fileChar))
      {
         count++;
      }
      else if(choice == DIGIT_CHARS && isdigit(fileChar))
      {
         count++;
      }
      else if(choice == PUNCT_CHARS && ispunct(fileChar))
      {
         count++;
      }
      else if(choice == SPACE_CHARS && isspace(fileChar))
      {
         count++;
      }
   }
   fclose(input09);

   return count;
}

/*************************************************************************
This function prints out the number of characters per type.
 ************************************************************************/
void printResult(int choice, int result)
{
   if(choice == ALPHA_CHARS)
   {
      printf("Total alphabetic characters = %d\n", result);
   }
   else if(choice == DIGIT_CHARS)
   {
      printf("Total digit characters = %d\n", result);
   }
   else if(choice == PUNCT_CHARS)
   {
      printf("Total punctuation characters = %d\n", result);
   }
   else if(choice == SPACE_CHARS)
   {
      printf("Total whitespace characters = %d\n", result);
   }

  return;
}

/*************************************************************************
This function prints a goodbye message to the user
 ************************************************************************/
void printGoodbye()
{
   printf("Thank you for using this program.");

   return;
}
