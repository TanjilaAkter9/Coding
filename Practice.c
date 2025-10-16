#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Library_Management_System
{
   int id;
   char title[100];
   char author[50];
   int year_published;
   char category[100];
   int price;
} Library_Management_System;

// ---------------- Global Data ----------------

// ✅ Preloaded books now declared globally
Library_Management_System books[100] = {
    {101, "Harry Potter", "J.K. Rowling", 1997, "Fantasy", 500},
    {102, "1984", "George Orwell", 1949, "Dystopian", 300},
    {103, "The Hobbit", "J.R.R. Tolkien", 1937, "Fantasy", 400},
    {104, "The Great Gatsby", "F. Scott Fitzgerald", 1925, "Classic", 350},
    {105, "To Kill a Mockingbird", "Harper Lee", 1960, "Classic", 450}
};

int book_count = 5;

// ---------------- Function Declarations ----------------
void addBook(Library_Management_System books[], int *book_count);
void displayBooks(Library_Management_System books[], int book_count);
void searchBook(Library_Management_System books[], int book_count);
void deleteBook(Library_Management_System books[], int *book_count);
void saveToFile(Library_Management_System books[], int book_count);
void loadFromFile(Library_Management_System books[], int *book_count);

// ---------------- Function Definitions ----------------

void addBook(Library_Management_System books[], int *book_count)
{
   int index = *book_count;

   printf("\nEnter Book Id: ");
   scanf("%d", &books[index].id);
   getchar();

   printf("Enter Book Title: ");
   fgets(books[index].title, 100, stdin);
   books[index].title[strcspn(books[index].title, "\n")] = 0;

   printf("Enter Author Name: ");
   fgets(books[index].author, 50, stdin);
   books[index].author[strcspn(books[index].author, "\n")] = 0;

   printf("Enter Year Published: ");
   scanf("%d", &books[index].year_published);
   getchar();

   printf("Enter Book Category: ");
   fgets(books[index].category, 100, stdin);
   books[index].category[strcspn(books[index].category, "\n")] = 0;

   printf("Enter Book Price: ");
   scanf("%d", &books[index].price);

   (*book_count)++;
   printf("\n✅ Book added successfully!\n");
}

void displayBooks(Library_Management_System books[], int book_count)
{
   if (book_count == 0)
   {
      printf("\nNo books to display.\n");
      return;
   }

   printf("\n===== Library Books =====\n");
   for (int i = 0; i < book_count; i++)
   {
      printf("\nId: %d\nTitle: %s\nAuthor: %s\nYear Published: %d\nCategory: %s\nPrice: %d\n",
             books[i].id, books[i].title, books[i].author,
             books[i].year_published, books[i].category, books[i].price);
   }
}

void searchBook(Library_Management_System books[], int book_count)
{
   int choice;
   printf("\nSearch by:\n1. ID\n2. Title\nEnter choice: ");
   scanf("%d", &choice);
   getchar();

   if (choice == 1)
   {
      int id, found = 0;
      printf("Enter Book ID: ");
      scanf("%d", &id);

      for (int i = 0; i < book_count; i++)
      {
         if (books[i].id == id)
         {
            printf("\nFound Book:\nTitle: %s\nAuthor: %s\nYear: %d\nCategory: %s\nPrice: %d\n",
                   books[i].title, books[i].author, books[i].year_published, books[i].category, books[i].price);
            found = 1;
            break;
         }
      }
      if (!found)
         printf("Book with ID %d not found.\n", id);
   }
   else if (choice == 2)
   {
      char title[100];
      int found = 0;
      printf("Enter Book Title: ");
      fgets(title, 100, stdin);
      title[strcspn(title, "\n")] = 0;

      for (int i = 0; i < book_count; i++)
      {
         if (strcmp(books[i].title, title) == 0)
         {
            printf("\nFound Book:\nID: %d\nAuthor: %s\nYear: %d\nCategory: %s\nPrice: %d\n",
                   books[i].id, books[i].author, books[i].year_published, books[i].category, books[i].price);
            found = 1;
            break;
         }
      }
      if (!found)
         printf("Book not found.\n");
   }
   else
   {
      printf("Invalid choice.\n");
   }
}

void deleteBook(Library_Management_System books[], int *book_count)
{
   int id, found = 0;
   printf("Enter Book ID to delete: ");
   scanf("%d", &id);

   for (int i = 0; i < *book_count; i++)
   {
      if (books[i].id == id)
      {
         found = 1;
         for (int j = i; j < *book_count - 1; j++)
         {
            books[j] = books[j + 1];
         }
         (*book_count)--;
         printf("✅ Book deleted successfully!\n");
         break;
      }
   }

   if (!found)
      printf("Book with ID %d not found.\n", id);
}

void saveToFile(Library_Management_System books[], int book_count)
{
   FILE *fp = fopen("library.txt", "w");
   if (fp == NULL)
   {
      printf("Error opening file!\n");
      return;
   }

   for (int i = 0; i < book_count; i++)
   {
      fprintf(fp, "%d,%s,%s,%d,%s,%d\n",
              books[i].id, books[i].title, books[i].author,
              books[i].year_published, books[i].category, books[i].price);
   }

   fclose(fp);
   printf("💾 Books saved to file successfully!\n");
}

void loadFromFile(Library_Management_System books[], int *book_count)
{
   FILE *fp = fopen("library.txt", "r");
   if (fp == NULL)
   {
      printf("(No previous records found, starting fresh...)\n");
      return;
   }

   *book_count = 0;
   while (fscanf(fp, "%d,%99[^,],%49[^,],%d,%99[^,],%d\n",
                 &books[*book_count].id,
                 books[*book_count].title,
                 books[*book_count].author,
                 &books[*book_count].year_published,
                 books[*book_count].category,
                 &books[*book_count].price) == 6)
   {
      (*book_count)++;
   }

   fclose(fp);
   printf("📂 Books loaded successfully!\n");
}

// ---------------- Main Function ----------------

int main()
{
   loadFromFile(books, &book_count);

   int choice;
   do
   {
      printf("\n===== Library Management System =====\n");
      printf("1. Add Book\n2. Display Books\n3. Search Book\n4. Delete Book\n5. Save & Exit\n");
      printf("Enter choice: ");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         addBook(books, &book_count);
         break;
      case 2:
         displayBooks(books, book_count);
         break;
      case 3:
         searchBook(books, book_count);
         break;
      case 4:
         deleteBook(books, &book_count);
         break;
      case 5:
         saveToFile(books, book_count);
         printf("Exiting program...\n");
         break;
      default:
         printf("Invalid choice! Please try again.\n");
      }

   } while (choice != 5);

   return 0;
}



