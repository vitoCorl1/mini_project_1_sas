#include <stdio.h>
#include <string.h>

int add_book(char title[100][100], char author[100][100], float price[100], int Quantity[100], int count) {
    if (count >= 100) {
        printf("Book storage is full!\n");
        return count;
    }

    printf("Enter book title : ");
    scanf("%s", title[count]);

    printf("Enter author name : ");
    scanf("%s", author[count]);

    printf("Enter Book price : ");
    scanf("%f", &price[count]);

    printf("Enter Quantity in stock : ");
    scanf("%d", &Quantity[count]);

    count++;
    printf("Book added succecfully ! Now total = %d\n", count);

    return count;
}

void view_books(char title[100][100], char author[100][100], float price[100], int Quantity[100], int count) {
    if (count == 0) {
        printf("No books available.\n");
        return;
    }

    printf("\nAvailable Books:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s by %s , price of %0.2f$, and the Quantity %d\n", i + 1, title[i], author[i], price[i], Quantity[i]);
    }
}

void Search_by_title(char title[100][100], char author[100][100], float price[100], int Quantity[100], int count) {
    char Search[100];
    if (count == 0) {
        printf("No books available.\n");
        return;
    }
    
    printf("ESearch for a book by its title : ");
    scanf("%s", Search);
    for(int i = 0; i < count; i++){
        int c = strcmp(Search, title[i]);
        if(c == 0){
            printf("%d. %s by %s , price of %0.2f $, and the Quantity %d\n", i + 1, title[i], author[i], price[i], Quantity[i]);
        }
    }
}

// void Update_quantity( int Quantity[20][100], int count)


int main(){
    int choise;
    int count = 0;
    char title[100][100], Author[100][100];
    float price[100];
    int Quantity[100];
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
        if(choise < 0 || choise > 7){
            printf("\nwrong try (0 - 6) !\n");
        }
        
        switch (choise) {
            case 1:
                count = (add_book(title, Author, price, Quantity , count));
                break;
            case 2:
                view_books(title, Author, price, Quantity , count);
                break;
            case 3:
                Search_by_title(title, Author, price, Quantity , count);
                break;
            case 4:
                break;
        }
    }

}