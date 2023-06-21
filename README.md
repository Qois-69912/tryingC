# Things i make while learning C

**BEWARE ⚠️⚠️ Broken English Ahead**

They said that, the best way to learn something is by apply it irl. So i decide, the best way to learn C is by making something.
The hope is that, during the process i learn new things about C and then after made many things, i can master the fundamentals of C.

## List of things i made :
### Calculate the day of the week
- About : Program to calculate the day of the week from any date that user input.
- Point of Interest : i learn something call "mapping value to dictionary"-ish. It basically made if-statement more programmatic?
- Things i learn :
    * Get array length using 'sizeof'. To get array length by divide array's (as whole) bytes, with the first item in array's byte.
    * You need 'strcmp' to compare two strings. If strcmp return '0', that means the strings is same.
    * There is something called "pointer" in C, i'm still confused about this.
    * Strings are char but in an array form.
- To Run it :
    ```
    $ make project=DayOfWeekFromDate
    $ ./DayOfWeekFromDate
    ```
- Reference :
    * Art of Memory. 2023. ["How to Calculate the Day of the Week from Any Date"](https://artofmemory.com/blog/how-to-calculate-the-day-of-the-week/)

### Convert digit to binary and vice versa
- About : Program to convert Digit to binary and vice versa.
- Point of Interest : The program can take command line arguments.
- Things i learn :
    * Learn something about 'typedef struct'. It is similiar to class (in some aspects)
    * Learn how to use 'calloc'. I use it to initialize new empty array.
    * Learn to convert to char into int, with the help of '(int)' and 'atoi'. '(int)' is for single char and 'atoi' for string.
- To Run it :
    ```
    $ make project=DigitToBinary
    $ ./DigitToBinary
    ```
- Reference :
    * Koretskyi, Max. 2016. ["The simple math behind decimal-binary conversion algorithms"](https://indepth.dev/posts/1019/the-simple-math-behind-decimal-binary-conversion-algorithms)
    * Quora. 2022. ["How many bits does it take to represent a number?"](https://www.quora.com/How-many-bits-does-it-take-to-represent-a-number)
    * GeeksforGeeks. 2023. ["Command Line Arguments in C/C++"](https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/)

## Debug Mode
To Debug something, run this command :
```
$ make project=<Project name here> debug=y
```
It will take you into `gdb` environment?, type 'quit' to exit.
