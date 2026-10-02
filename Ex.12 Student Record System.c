/*
===============================================================================
                     DATA STRUCTURES LABORATORY
===============================================================================

Experiment : 12
Title      : Student Record System (Structures Application)
Language   : C
Standard   : C11
Status     : Reviewed & Verified

Description:
    Demonstrates practical structured data processing in C using an array
    of structs. Reads student academic profiles (Name, Roll Number, Marks
    in 3 subjects), computes individual aggregate scores, determines the
    top scorer in each subject, and identifies the overall class topper.

Operations:
    1. Input Student Information & Subject Marks
    2. Compute Individual Total Marks
    3. Determine Highest Scorer per Subject
    4. Determine Overall Topper

Complexity:
    Time Complexity  : O(n * m) where n is student count, m is subject count
    Space Complexity : O(n) struct array storage

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NUM_SUBJECTS 3
#define NAME_LEN 30

struct Student {
    char name[NAME_LEN];
    int rollno;
    int sub[NUM_SUBJECTS];
    int total;
};

/* ========================================================================= */

int main(void) {
    int n;
    struct Student st[MAX_STUDENTS];

    printf("========================================\n");
    printf("         STUDENT RECORD SYSTEM\n");
    printf("========================================\n");

    printf("Enter number of students (1-%d): ", MAX_STUDENTS);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_STUDENTS) {
        fprintf(stderr, "Error: Invalid number of students.\n");
        return EXIT_FAILURE;
    }

    /* 1. Read student profiles and marks */
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d Details:\n", i + 1);
        printf("Enter student name: ");
        if (scanf("%29s", st[i].name) != 1) {
            fprintf(stderr, "Error: Invalid name input.\n");
            return EXIT_FAILURE;
        }

        printf("Enter roll number: ");
        if (scanf("%d", &st[i].rollno) != 1) {
            fprintf(stderr, "Error: Invalid roll number.\n");
            return EXIT_FAILURE;
        }

        st[i].total = 0;
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("Enter marks for Subject %d: ", j + 1);
            if (scanf("%d", &st[i].sub[j]) != 1) {
                fprintf(stderr, "Error: Invalid marks entry.\n");
                return EXIT_FAILURE;
            }
            st[i].total += st[i].sub[j];
        }
    }

    /* 2. Display total marks obtained by each student */
    printf("\n========================================\n");
    printf("             STUDENT TOTALS\n");
    printf("========================================\n");
    for (int i = 0; i < n; i++) {
        printf("Roll No: %-8d | Name: %-15s | Total: %d\n",
               st[i].rollno, st[i].name, st[i].total);
    }

    /* 3. Find student with highest marks in each subject */
    printf("\n========================================\n");
    printf("             SUBJECT TOPPERS\n");
    printf("========================================\n");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        int max_marks = -1;
        int topper_idx = 0;

        for (int i = 0; i < n; i++) {
            if (st[i].sub[j] > max_marks) {
                max_marks = st[i].sub[j];
                topper_idx = i;
            }
        }
        printf("Subject %d Topper: %s (Roll No: %d) with %d marks\n",
               j + 1, st[topper_idx].name, st[topper_idx].rollno, max_marks);
    }

    /* 4. Find student with overall highest total */
    int overall_max = -1;
    int overall_topper_idx = 0;

    for (int i = 0; i < n; i++) {
        if (st[i].total > overall_max) {
            overall_max = st[i].total;
            overall_topper_idx = i;
        }
    }

    printf("\n========================================\n");
    printf("             OVERALL TOPPER\n");
    printf("========================================\n");
    printf("Class Topper: %s (Roll No: %d) with Total = %d marks!\n",
           st[overall_topper_idx].name,
           st[overall_topper_idx].rollno,
           overall_max);
    printf("========================================\n");

    return EXIT_SUCCESS;
}

/*
===============================================================================
                               SAMPLE OUTPUT
===============================================================================
========================================
         STUDENT RECORD SYSTEM
========================================
Enter number of students (1-50): 2

Student 1 Details:
Enter student name: ARUN
Enter roll number: 4211101
Enter marks for Subject 1: 78
Enter marks for Subject 2: 98
Enter marks for Subject 3: 67

Student 2 Details:
Enter student name: KUMAR
Enter roll number: 4211102
Enter marks for Subject 1: 78
Enter marks for Subject 2: 55
Enter marks for Subject 3: 57

========================================
             STUDENT TOTALS
========================================
Roll No: 4211101  | Name: ARUN            | Total: 243
Roll No: 4211102  | Name: KUMAR           | Total: 190

========================================
             SUBJECT TOPPERS
========================================
Subject 1 Topper: ARUN (Roll No: 4211101) with 78 marks
Subject 2 Topper: ARUN (Roll No: 4211101) with 98 marks
Subject 3 Topper: ARUN (Roll No: 4211101) with 67 marks

========================================
             OVERALL TOPPER
========================================
Class Topper: ARUN (Roll No: 4211101) with Total = 243 marks!
========================================
===============================================================================
*/