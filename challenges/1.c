#include <stdio.h>

int main() {
  const int MIN_GRADE_A = 90;
  const int MIN_GRADE_B = 80;
  const int MIN_GRADE_C = 70;
  const int MIN_GRADE_D = 60;
  // F grade is anything below

  int score;
  printf("Enter student's score:\n");
  scanf("%d", &score);

  char grade;
  if (score >= MIN_GRADE_A) {
    grade = 'A';
  } else if (score >= MIN_GRADE_B) {
    grade = 'B';
  } else if (score >= MIN_GRADE_C) {
    grade = 'C';
  } else if (score >= MIN_GRADE_D) {
    grade = 'D';
  } else {
    grade = 'F';
  }

  printf("Student's score was %d and grade is %c.\n", score, grade);
  printf("File size of score is %lu bytes.", (unsigned long) sizeof(score));
}
