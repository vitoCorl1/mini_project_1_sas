#include <stdio.h>

int add_book(char title[10][100], char author[10][100], int count) {
    if (count >= 10) {
        printf("Book storage is full!\n");
        return count;
    }

    printf("Enter book title : ");
    scanf("%s", title[count]);

    printf("Enter author name : ");
    scanf("%s", author[count]);

    count++;
    printf("Book added! Now total = %d\n", count);

    return count;
}

void view_books(char title[10][100], char author[10][100], int count) {
    if (count == 0) {
        printf("No books available.\n");
        return;
    }

    printf("\nAvailable Books:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s by %s\n", i + 1, title[i], author[i]);
    }
}


int main(){
    int choise;
    int count = 0;
    char title[10][100], Author[10][100];
    while(1){
        printf("\n//////////// Menu Book Store ///////////////////\n");
        printf("//////// 1 . Add a book to stock. ////////////////\n");
        printf("////// 2 . View all available books. /////////////\n");
        printf("//// 3 . Search for a book by its title. /////////\n");
        printf("//// 4 . Update the quantity of a book. //////////\n");
        printf("////// 5 . Delete a book from stock. /////////////\n");
        printf("// 6 . View the total number of books in stock. //\n");
        printf("/////////////////// 0 . Quit. ////////////////////\n");
        printf("//////////////////////////////////////////////////\n");
        
        printf("Enter your choise : ");
        scanf("%d", &choise);
        for(int i = 0; i < 3; i++){
            if(choise < 0 || choise > 6)
                printf("wrong try (0 - 6) : ");
        }
        switch (choise) {
            case 1:
                count = (add_book(title, Author, count));
                break;
            case 2:
                view_books(title, Author, count);
                break;
        }
    }

}