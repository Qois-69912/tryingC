#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


bool checkIsThatDatePossible(int date, int maxDate) {
  if (date < 1 || date > maxDate) {
  	return false;
  };

  return true;
}


void calculateDayOfTheWeek(int date, char monthName[], int year) {
  // Documentation for the formula
  // https://artofmemory.com/blog/how-to-calculate-the-day-of-the-week/

  // Formula :
  // (Year Code + Month Code + Century Code + Date Number - Leap Year Code) % 7


  int lastTwoDigitsOfYear = year % 100;
  int yearCode = (lastTwoDigitsOfYear + (lastTwoDigitsOfYear / 4)) % 7;


  // Just to make it more simpler, make the month name to lowercase
  for (int i = 0; monthName[i] != '\0'; i++) {
    monthName[i] = tolower(monthName[i]);
  }

  // Find the Month Code
  // "Mapping Table" Solution instead If-else Solution
  // "Kinda Overkill ngl", said chatgpt
  // Note : if strcmp output 0, that mean two strings equal.

  int monthCode = -1;

  const char *group1[] = {"january", "october"};
  const char *group2[] = {"february", "march", "november"};
  const char *group3[] = {"april", "july"};
  const char *group4[] = {"september", "december"};

  for (int i = 0; i < sizeof(group1) / sizeof(group1[0]); i++) {
    if (strcmp(monthName, group1[i]) == 0) {
  	  monthCode = 0;
  	  break;
    }
  }

  if (monthCode == -1) {
    for (int i = 0; i < sizeof(group2) / sizeof(group2[0]); i++) {
  		if (strcmp(monthName, group2[i]) == 0) {
  			monthCode = 3;
  			break;
  		}
  	}
  }

  if (monthCode == -1) {
  	for (int i = 0; i < sizeof(group3) / sizeof(group3[0]); i++) {
  		if (strcmp(monthName, group3[i]) == 0) {
  			monthCode = 6;
  			break;
  		}
  	}
  }

  if (monthCode == -1) {
  	for (int i = 0; i < sizeof(group4) / sizeof(group4[0]); i++) {
  		if (strcmp(monthName, group4[i]) == 0) {
  			monthCode = 5;
  			break;
  		}
  	}
  }

  if (monthCode == -1) {
  	if (strcmp(monthName, "may") == 0) {
  		monthCode = 1;
  	} else if(strcmp(monthName, "june") == 0) {
  		monthCode = 4;
  	} else if(strcmp(monthName, "august") == 0) {
  		monthCode = 2;
  	} else {
  		printf("'%s' is not a month\n", monthName);
  		return;
  	}
  }


  int centuryCode;

  if (year < 1800) {
  	printf("Year cannot lower than 1800\n");
  	return;
  }

  if (year < 1900) {
  	centuryCode = 2;	// 1800
  } else if (year < 2000) {
  	centuryCode = 0;	// 1900
  } else if (year < 2100) {
  	centuryCode = 6;	// 2000
  } else if (year < 2200) {
  	centuryCode = 4;	// 2100
  } else if (year < 2300) {
  	centuryCode = 2;	// 2200
  } else if (year < 2400) {
  	centuryCode = 2;	// 2300
  } else {
  	printf("Year cannot higher than 2399\n");
  	return;
  }


  int leapYearCode = 0;
  if (year % 4 == 0) {
  	switch (monthName[0]) {
  		case 'j':	// January
  			leapYearCode = 1;
  			break;
  		case 'f': // February
  			leapYearCode = 1;
  			break;
  	}
  }


  int maxDateInMonth;
  char *monthWith30Days[] = {"april", "june", "september", "november"};
  char *monthWith31Days[] = {"january", "march",
 	  "may", "july", "august", "october", "december"};

  for (int i = 0; i < sizeof(monthWith30Days) / sizeof(monthWith30Days[0]); i++) {
  	if (strcmp(monthWith30Days[i], monthName) == 0) {
  		maxDateInMonth = 30;
  	}
  }

  for (int i = 0; i < sizeof(monthWith31Days) / sizeof(monthWith31Days[0]); i++) {
  	if (strcmp(monthWith31Days[i], monthName) == 0) {
  		maxDateInMonth = 31;
  	}
  }

  if (strcmp(monthName, "february") == 0) {
  	switch (leapYearCode) {
  		case 1:
  			maxDateInMonth = 29;
  			break;
  		case 0:
  			maxDateInMonth = 28;
  			break;
  	}
  }

  if (!checkIsThatDatePossible(date, maxDateInMonth)) {
  	printf("The date entered is less or more than the number of days in the month\n");
  	return;
  }


  // (Year Code + Month Code + Century Code + Date Number - Leap Year Code) % 7
  int result = (yearCode + monthCode + centuryCode + date - leapYearCode) % 7;


  const char *dayName[] = {
  	"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
  	"Friday", "Saturday"
  };

  printf("Day : %s\n", dayName[result]);
}



int main() {
  int date;
  char monthName[10];
  int year;

  printf("Calculate The Day of The Week from any Date\n");

  printf("Date : ");
  if (scanf("%d", &date) != 1) {
  	printf("Invalid Input, Expected an number \n");
  	return 0;
  }

  printf("Month : ");
  scanf("%s", monthName);

  printf("Year : ");
  if (scanf("%d", &year) != 1) {
  	printf("Invalid Input, Expected an number \n");
  	return 0;
  };

  calculateDayOfTheWeek(date,  monthName, year);
}
