#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct book {
  char title[100];
  char author[50];
  int id;
};

//Function to add a book
void addBook() {
  struct book b;
  FILE*file = fopen("library.txt","ab");
  if(!file) {
      printf("error opening file!\n");
      return;
  }
  printf("Enter book id: ");
  scanf("%d",&b.id);
  printf("Enter title: ");
  scanf(" %[^\n]",b.title);
  printf("Enter author: ");
  scanf(" %[^\n]",b.author);
  fwrite(&b,sizeof(b),1,file);
  fclose(file);
  printf("Book added successfully !\n");
}
void displaybooks() {
  struct book b;
  FILE *file = fopen("*library.txt","rb");
  if(!file) {
      printf("No books available! n");
      return;
  }
  printf("\nID\ttitle\tauthor\n");
  while(fread(&b,sizeof(b),1,file)){
      printf("%d\t%s\t%s\t%s\n",b.id,b.title,b.author);
  }
  fclose(file);
}
int main()
{
  int choice;
  while(1) {
    printf("\n1.addbook\n2.viewbook\n3.exit\nenter choice: ");
    scanf("%d",&choice);
    switch(choice) {
      case 1:addBook();break;
      case 2:displaybooks();break;
      case 3:exit(0);
      default:printf("Invaild choice!\n");
    }
  }
  return 0;
}
