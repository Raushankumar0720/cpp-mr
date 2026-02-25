#include <iostream>
#include <stdio.h>

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    
    if (num > 0) {
        printf("The number is Positive\n");
    } else if (num < 0) {
        printf("The number is Negative\n");
    } else {
        printf("The number is Zero\n");
    }

    if (num % 2 == 0) {
        printf("The number is Even\n");
    } else {
        printf("The number is Odd\n");
    }

    return 0;
}


///////////////////  fibonacci   ////////////////////

#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int Position;

    printf("Enter number of Position: ");
    scanf("%d", &Position);

    printf("Fibonacci Series: ");
    for (int i = 0; i < Position; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}


///////////////////  palindrome   ////////////////////


#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len, flag = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}


///////////////////  calculate avg   ////////////////////

#include <stdio.h>

int main() {
    int arr[5];
    int i;
    float sum = 0, avg;

    printf("Enter 5 integers:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    avg = sum / 5;

    printf("Average = %.2f\n", avg);
    printf("Numbers greater than average:\n");
    for (i = 0; i < 5; i++) {
        if (arr[i] > avg) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    return 0;
}



///////////////////  mast task   ////////////////////


#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    int i;

    // --- Fibonacci ---

    int n, f1 = 0, f2 = 1, next;
    printf("Enter number of terms for Fibonacci: ");
    scanf("%d", &n);

    // write 
    fp = fopen("fibonacci.txt", "w");
    fprintf(fp, "Fibonacci series up to %d terms:\n", n);
    for (i = 0; i < n; i++) {
        fprintf(fp, "%d ", f1);
        next = f1 + f2;
        f1 = f2;
        f2 = next;
    }
    fclose(fp);

    //read
    printf("\n--- Reading Fibonacci from file ---\n");
    fp = fopen("fibonacci.txt", "r");
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);

    // --- Palindrome ---

    char word[100];
    printf("\n\nEnter a word to check palindrome: ");
    scanf("%s", word);

    int len = strlen(word), flag = 0;
    for (i = 0; i < len / 2; i++) {
        if (word[i] != word[len - i - 1]) {
            flag = 1;
            break;
        }
    }

    // write
    fp = fopen("palindrome.txt", "w");
    if (flag == 0)
        fprintf(fp, "The word '%s' is a palindrome.\n", word);
    else
        fprintf(fp, "The word '%s' is not a palindrome.\n", word);
    fclose(fp);

    //read
    printf("\n--- Reading Palindrome result from file ---\n");
    fp = fopen("palindrome.txt", "r");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);

    // --- Average of Array ---
    int arr[5];
    float sum = 0, avg;
    printf("\nEnter 5 integers:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    avg = sum / 5;

    //write
    fp = fopen("average.txt", "w");
    fprintf(fp, "Average = %.2f\n", avg);
    fprintf(fp, "Numbers greater than average: ");
    for (i = 0; i < 5; i++) {
        if (arr[i] > avg) {
            fprintf(fp, "%d ", arr[i]);
        }
    }
    fclose(fp);


    //read
    printf("\n--- Reading Average result from file ---\n");
    fp = fopen("average.txt", "r");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);

    return 0;
}


///////////////////////////////////////////////   struct   //////////////////////////////////////////



#include<iostream>
#include<string>

using namespace std;

struct Employee{
    int ID;
    string name;
    int salary;
};


int main(){
    
    int size = 0;
    
    cout<< "enter the size of array:  " << endl;
    cin >> size;
    
    Employee emp[size];
    
    for(int i=0; i<2; i++){
        cout<< "Enter you're id:  " << endl;
        cin >> emp[i].ID;
        cout << "enter you're name:  " << endl;
        cin >> emp[i].name;
        cout<<"enter you valid salary:  " << endl;
        cin >> emp[i].salary;
    }
    
    for(int i=0; i< 2; i++){
        cout<< "current index number is:  " << i << " empyee id is: " << emp[i].ID << " Employee name is: " << emp[i].name << endl;
    }
    
    return 0;
}

