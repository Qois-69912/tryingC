#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
  int bits;
  int *value;
} Binary;


Binary digitToBinary(int digit) {
  Binary binary;

  // To calculate the number of bits to represent x in binary required use this formula :
  // (log2 (x)) + 1
  binary.bits = log2(digit) + 1;

  // Formula :
  // https://indepth.dev/posts/1019/the-simple-math-behind-decimal-binary-conversion-algorithms#converting-decimal-integer-to-binary

  binary.value = (int*)calloc(binary.bits, sizeof(int));

  if (binary.value == NULL) {
    printf("Memory allocation failed\n");
    binary.bits = 0;
  }

  int i = binary.bits - 1;  // Weird work around, because turns out the array
                            // size is n + 1

  while (digit > 0) {
    binary.value[i] = digit % 2;
    digit = digit / 2;
    i--;
  }

  return binary;
}


void destroyArr(Binary *binary) {
  if (binary -> value != 0) {
    free(binary -> value);
    binary -> bits = 0;
  }
}


int binaryToDigit(char binaryInputChar[]) {
  int arrLength = strlen(binaryInputChar);
  int binaryInputInt[arrLength];
  int digitResult = 0;

  for (int i = 0; i < arrLength; i++) {
    binaryInputInt[i] = (int)(binaryInputChar[i]) - 48; // Output Ascii, subtract with 48
                                                        // to get the actual value

    // Formula :
    // https://indepth.dev/posts/1019/the-simple-math-behind-decimal-binary-conversion-algorithms#converting-binary-integer-to-decimal
    digitResult = 2 * digitResult + binaryInputInt[i];
  }

  return digitResult;
}


int main(int argc, char *argv[]) {
  char *optionsList[] = {"DigitToBinary", "BinaryToDigit"};
  int optListArrLen = sizeof(optionsList) / sizeof(optionsList[0]);

  if (argc < 2) {
    printf(
        "Please pass Options + Argument \n"
        "\nAvailable options : \n"
        "%s : For Converting Digits to Binary\n"
        "%s : For Converting Binary to Digits\n"
        "\nArgument = Digit or Binary that want to be convert\n"
        "\nExample : \n"
        "./ThisProgramName --%s 123\n",
        optionsList[0], optionsList[1], optionsList[0]
    );
    return 0;
  }

  int selectedOpt;
  for (selectedOpt = 0; selectedOpt < optListArrLen + 1; selectedOpt++) {
    if (strcmp(argv[1], optionsList[selectedOpt]) == 0) {
      break;
    }
  }

  if (selectedOpt > optListArrLen) {
    printf("Cannot use '%s' as options\n", argv[1]);
    return 0;
  }

  if (argc == 2) {
    printf("Expected some argument\n");
    return 0;
  }

  int argLen = strlen(argv[2]);
  int inputInt = atoi(argv[2]);
  if (inputInt == 0 && argLen > 1) {
    printf("Expected a number as argument \n");
    return 0;
  }

  if (argc > 3) {
    printf("Only the first argument the will be converted \n");
  }

  if (selectedOpt == 0) {
    Binary binary = digitToBinary(inputInt);

    if (binary.bits != 0) {
      for (int i = 0; i < binary.bits; i++) {  // Eventhough the array size is n+1
        printf("%d", binary.value[i]);         // But this behaviour is similar to array size
      }                                        // equal to n ?
      printf("\n");
      return 0;
    }

    destroyArr(&binary);
  }

  for (int i = 0; i < argLen; i++) {
    inputInt = (int)argv[2][i] - 48;

    if (inputInt > 1 || inputInt < 0) {
      printf("'%s' is not binary\n", argv[2]);
      return 0;
    }
  }

  if (selectedOpt == 1) {
    printf("%d\n", binaryToDigit(argv[2]));
  }
}
