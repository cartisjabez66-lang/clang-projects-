#include <stdio.h>

int main() {
    int adm_no;
    char reg_no[20];
    char name[30];
    int age;
    int sub1, sub2, sub3;
    int total;
    float average;
    char grade;

    printf("Enter Adm No: ");
    scanf("%d", &adm_no);

    printf("Enter Reg No: ");
    scanf("%s", reg_no); // NO & for string - common bug

    printf("Enter Name (no space): ");
    scanf("%s", name);

    printf("Enter Age: ");
    scanf("%d", &age);

    printf("Enter 3 marks separated by space: ");
    scanf("%d %d %d", &sub1, &sub2, &sub3);

    // --- DEBUG CHECK (Remove this before submitting) ---
    // printf("DEBUG: You entered %d %d %d\n", sub1, sub2, sub3);

    total = sub1 + sub2 + sub3;
    average = total / 3.0; // 3.0 not 3 - keeps decimal

    if(average >= 70)
        grade = 'A';
    else if(average >= 60)
        grade = 'B';
    else if(average >= 50)
        grade = 'C';
    else if(average >= 40)
        grade = 'D';
    else
        grade = 'E';

    printf("\n--- RESULT ---\n");
    printf("Adm No: %d\n", adm_no);
    printf("Reg No: %s\n", reg_no);
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Total: %d\n", total);
    printf("Average: %.2f\n", average);
    printf("Grade: %c\n", grade);

    if(average >= 40)
        printf("Status: PASS\n");
    else
        printf("Status: FAIL\n");

    return 0;
}
