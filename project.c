/* ENGGEN131, Semester Two, 2017 */

/* PROJECT SOLUTION BY:  << Hong Shi ID:314381442 >> */

#include "project.h"

/* HELPER FUNCTIONS */
/* If you have defined any "helper" functions, which you call from the required */
/* functions, you should place them here, at the top of the source file.  This will */
/* make it easier for the markers to locate them.  You should also include a */
/* comment at the top of each of the "helper" functions you define which clearly */
/* describes their purpose, and which of the tasks they support. */

/* The DifferenceAndDirection function finds the absolute difference of 2 numbers

   This function is called in Connecttwo and helps finds the row difference and the
   direction in which the columns should move (i.e 1 means east -1 means west)
   so that it knows how many times it has to travel diagonally until it reaches
   the same column. This is done by comparing the numbers to see if one number is
   bigger than the other. This will result in the bigger number always getting 
   subtracted by the smaller number hence finding the absolute difference.
 */

int DifferenceAndDirection(int endCols, int startCols, int *direction)
{
	int difference;

	if (endCols > startCols)
	{
		difference = endCols - startCols;
		*direction = 1;
	}
	else if (endCols == startCols)
	{

		difference = 0;
		*direction = 0;
	}
	else
	{
		difference = startCols - endCols;
		*direction = -1;
	}
	return difference;
}

/* The SmallestNumber function finds the largest of the 3 numbers. This function takes 
   3 different numbers as input and returns the smallest number of the 3.
   
   This helper function is called in DivisorOfThree and works by using many if statements.
   Each number is compared with another and set to variable min if it is the lowest of 
   the three numbers which is then returned.  
*/
int SmallestNumber(int a, int b, int c)
{
	int min;
	if (a < b && a < c)
	{
		min = a;
	}
	else if (b < a && b < c)
	{
		min = b;
	}
	else
	{
		min = c;
	}
	return min;
}
/* REQUIRED FUNCTIONS */
/* Implement each of the required functions below.  The code that is provided initially */
/* for each function is incorrect - you should correct this! */

/* The DivisorOfThree functions finds the greatest common divider of three different
   numbers. The inputs that are taken are 3 different numbers and the output is the 
   greatest common divider of the three numbers
   
   This function works by first finding the smallest number of the 3 by calling the SmallestNumber
   function as the greatest divider cannot exceed the smallest number. Then a for loop is made 
   up to the smallest number as the condition and if all three numbers divided by that number has 
   no remainder then the variable GCD gets updated to that number. The loop then continues to run 
   until the condition has been met and then returns the GCD.  
*/
int DivisorOfThree(int a, int b, int c)
{
	int i, min, GCD;
	GCD = 0;
	min = SmallestNumber(a, b, c);
	for (i = 1; i < min; i++)
	{
		if (a % i == 0 && b % i == 0 && c % i == 0) /* Condition to check if remainders are equal to 0 */
		{
			GCD = i;
		}
	}
	if (a <= 0 || b <= 0 || c <= 0)
	{
		GCD = -1;
	}
	return GCD;
}

/* The Averagesheep function finds the average amount of sheep per hour. This function takes 1 
   input which is the array of values and 1 output which is the average number of sheep.

   This function works by looping through each element in the array, while the number in that element
   is smaller than the special value 9999 then it continues. i is the counter which finds how many elements
   that the for loop needs to run. The for loop sums each number in the array unless it equals to -1 by 
   accessing each element in the array. the k variable finds the number of hours to ignore from the calculation.
   the average is then found as a double value by using the sum and dividing it by the (j-k) j which is the 
   total hours and k is the amount of hours to ignore.
*/
double AverageSheep(int *counts)
{
	int i, j, k, sum;
	i = 0;
	k = 0;
	sum = 0;
	while (counts[i] < 9999)
	{
		i++; /* finds the number of numbers before 9999 */
	}
	if (i == 0)
	{
		return 0;
	}
	else
	{
		for (j = 0; j < i; j++)
		{
			if (counts[j] == -1)
			{
				k++;
			}
			else
			{
				sum += counts[j];
			}
		}
		if (i == k)
		{
			return 0;
		}
		else
		{
			return (double)sum / (j - k);
		}
	}
}

/* The Emphasise function finds a string that is between two '_' and capitalizes the letters.
   This function takes one input which is a string of characters.
   
  This function works by first finding the positions of both the '_' characters by looping from
  the first letter and storing that value and looping from the end letter and storing that value.
  The characters to the right hand side of the first underscore and the left hand side of the second
  underscore are shifted to the left by one using a for loop. The characters on the right hand side 
  of the second underscore are then moved by 2 spaces to the left. Then a for loop and a if statement
  is used to make all characters that are withing 'a' and 'z' to be capitalized by subtracting 32 as
  that is the decimal value for the ascii code.  
 */
void Emphasise(char *word)
{
	int i, j, k, length;
	length = strlen(word);
	i = 0;
	while (word[i] != '_')
	{
		i++;
	}

	j = length;
	while (word[j] != '_')
	{
		j--;
	}
	for (k = i; k < j; k++)
	{
		word[k] = word[k + 1]; /* shifts characters to the left by 1 */
	}

	for (k = j; k < length; k++)
	{
		word[k - 1] = word[k + 1]; /* shifts characters to the left of the 2nd '_' by 2 */
	}

	for (k = i; k < j; k++)
	{
		if (word[k] >= 'a' && word[k] <= 'z')
		{
			word[k] -= 32;
		}
	}
}

/* The function PrimeFactors finds the number of primefactors that are in a given number.
   This function takes 2 inputs an integer and an array of integers and returns the number
   of primefactors there are.
   
   This function works by first dividing the number by 2 this means the resulting number 
   after will always be an odd. Another loop is then made that divides the numbers by the 
   next prime numbers and a counter is added 'i' which finds how many primefactors there are
   while storing each primefactor number in the array called factors.  
*/
int PrimeFactors(int n, int *factors)
{
	int i, k;
	i = 0;
	while (n % 2 == 0) /* While loop which divided by 2 */
	{
		factors[i] = 2;
		i++;
		n = n / 2;
	}

	for (k = 3; k <= n; k++) /* While loop which divided by the next prime factors */
	{
		while (n % k == 0)
		{
			n = n / k;

			factors[i] = k;
			i++;
		}
	}
	return i;
}

/* The function ConnectTwo prints the number 3 connecting the paths together.
   The paths start at a position which is labeled 1 in a 2D array and end at
   a position that is labeled as 2. This function takes 1 input which is the 
   array maze which is always 10x10. 
   
   This function works by first using a loop to find the starting positions
   both rows and columns and ending positions of the numbers 1 and 2. It then calls 
   a helper function called DifferenceAndDirection which calculates the absolute
   difference between endCols and startCols as well as the direction in which the 
   the locater has to move. Then a if statement is used to check whether it moves vertically up
   or vertically down. Within the if statements there are more conditions to check when the for
   loop stops and whether it has to move diagonally and then horizontally or diagonally and then
   vertically. The loop first changes each array number to be 3 going diagonal until it is in the 
   same column or row as the ending column or row.It then uses the next loop which moves up,down,left
   or right depending on he direction and replaces them with 3s and stops when it hits the 2.
*/
void ConnectTwo(int maze[10][10])
{
	int rows, cols, i;
	int startRow = 0;
	int startCols = 0;
	int endRow = 0, endCols = 0, difference, address;
	int *direction;

	direction = &address; /* points direction to the address variable */

	for (rows = 0; rows < 10; rows++)
	{
		for (cols = 0; cols < 10; cols++)
		{
			if (maze[rows][cols] == 1)
			{
				startRow = rows;
				startCols = cols;
			}
			if (maze[rows][cols] == 2)
			{
				endRow = rows;
				endCols = cols;
			}
		}
	}

	difference = DifferenceAndDirection(endCols, startCols, &address);

	if (startRow != endRow && startRow < endRow) /* this loop is used for going down */
	{
		for (i = startRow + 1; i < startRow + difference + 1; i++) //prints diagonal
		{
			maze[i][startCols + *direction] = 3;
			startCols = startCols + *direction;
			if (i == endRow) // break used so if a 3 is in the same row as 2 it stops the loop
			{
				break;
			}
		}
		if (startCols == endCols) // prints vertical
		{

			for (i = (startRow + difference); i < endRow - 1; i++) // prints the 3s in vertical
			{
				maze[i + 1][endCols] = 3;
			}
		}
		else if (startCols < endCols) // prints horiztonal right
		{
			for (i = startCols; i < endCols; i++)
			{
				maze[endRow][i] = 3;
			}
		}
		else
			for (i = startCols; i > endCols; i--) // prints horizontal left
			{
				maze[endRow][i] = 3;
			}
	}
	else if (startRow != endRow && startRow > endRow)
	/* this loop is used for going up */
	{
		for (i = startRow - 1; i > startRow - difference - 1; i--)
		{
			maze[i][startCols + *direction] = 3;
			startCols = startCols + *direction;
			if (i == endRow) // break used so if a 3 is in the same row as 2 it stops the loop
			{
				break;
			}
		}
		if (startCols < endCols) // prints horizontal right
		{
			for (i = startCols; i < endCols; i++)
			{
				maze[endRow][i] = 3;
			}
		}
		else if (startCols > endCols)
		{
			for (i = startCols; i > endCols; i--)
			{
				maze[endRow][i] = 3;
			}
		}

		else
		{
			for (i = (startRow - difference); i > endRow + 1; i--) /* prints the verticals 3s */
			{
				maze[i - 1][endCols] = 3;
			}
		}
	}
	else
	{
		if (endCols > startCols)
		{
			for (i = startCols; i < endCols - 1; i++) /* loop used for only horizontal movement */
			{
				maze[endRow][i + *direction] = 3;
			}
		}
		else
		{
			for (i = startCols; i > endCols + 1; i--) /* loop used for only horizontal movement */
			{
				maze[endRow][i + *direction] = 3;
			}
		}
	}
}

/* The function DayTrader finds the best run which has to be in increasing number.
   This function takes 4 inputs the prices in a array the total different prices
   a bestRun array and a bestRunIndex array. 

   This function works by using a nested for loop which compares the prices of the current
   one with the next one if its bigger then the loop continues and the bestrun counter is +1
   if it doesnt fulfill the condition then it breaks the loop and starts at the next element
   and so on. Once it has done all elements another for loop is used to find the biggest number
   in the 'k' array which stores the number of runs. Once it finds the longest run it also stores
   the element position into the variable and the pointer dereferences it and copies the number 
   to bestRun and bestRunIndex. 
*/
void DayTrader(int *prices, int numPrices, int *bestRun, int *bestRunIndex)
{
	int i, j;
	int max, element;
	int k[1000] = {0};

	for (j = 0; j < numPrices; j++)
	{
		for (i = j; i < numPrices - 1; i++)
		{
			if (prices[i + 1] > prices[i])
			{
				k[j] = k[j] + 1;
			}
			else
			{
				break;
			}
		}
	}
	element = 0;
	max = k[0];
	for (j = 1; j < numPrices; j++)
	{
		if (k[j] > max) /* finds the maximum value in 'k' array */
		{
			max = k[j];
			element = j;
		}
	}
	*bestRun = max;
	*bestRunIndex = element;
}

/* The Compress function reduces the amount of information that is stored in
   the array. It creates a new array in which the amount of numbers and the number
   is stored into the array instead of repeats of the same number.
   
   This is done by first finding the length to loop by using a while statement
   and finding how many numbers there are until it reaches -1. It then compares
   the current value with the next value and if they are the same it adds 1 to the 
   counter if not it adds the number 1 meaning only 1 occurrences and then followed 
   by the actual number. After it finds that it isnt the same it moves onto the next 
   number and repeats the cycle until it reaches -1. A counter with +2 is used so that 
   each different number occupies 2 spaces one space for number of occurrences and another
   for the actual number itself.
 */
void Compress(int *input, int *output)
{
	int i, j, k, counter;
	int actualnumber;
	i = 0;
	k = 1;
	counter = 0;
	while (input[i] != -1)
	{
		i++;
	}
	for (j = 0; j < i; j++)
	{
		if (input[j] == input[j + 1])
		{
			actualnumber = input[j];
			k++;
		}
		else
		{
			output[counter] = k;			/* adds the number of occurrences into the output */
			output[counter + 1] = input[j]; /* adds the number into the output */
			counter = counter + 2;
			k = 1;
		}
	}
	output[counter] = -1;
}

/* The Addone function creates a string which if you add 1 it works for very large numbers.
   This is because int type is only limited to 32 bits so the maximum value possible is only
   2147483647. The Addone function makes it so if 1 is added to that number it will produce a 
   string that contains 2147483648 instead of -2147483648. The function takes 2 inputs an array
   of char type that has the input and a output of char type.

   This function works by first finding the length of the string and then finding if the last element
   in the array is equal to '9' and if it isnt it just adds the decimal 1 to the ascii code so its the
   next number in the ascii chart. however if it is it changes the last digit to 0 and then runs a loop
   to check if the previous elements are '9' or not and it follows the same procedure. Then if the first 
   element of the array is 0 another for loop is used to shift everything to the right by one and the at 
   the end a '1' is added into element 0 of the array. The function strcopy then copies the string which 
   is the input exactly into the output.
*/
void AddOne(char *input, char *output)
{
	int i, length;

	length = strlen(input);

	if (input[length - 1] != '9') /* Checks if last element doesnt equal to '9' */
	{
		input[length - 1] = input[length - 1] + 1;
	}
	else
	{
		input[length - 1] = '0';
		for (i = length - 2; i >= 0; i--)
		{
			if (input[i] == '9')
			{
				input[i] = '0'; /* if the element is equal to '9' it changes it to '0' */
			}
			else
			{
				input[i] = input[i] + 1;
				break;
			}
		}
	}
	if (input[0] == '0')
	{
		for (i = 0; i < length; i++)
		{
			input[i + 1] = input[i];
		}
		input[0] = '1';
		strcpy(output, input);
	}
	else
	{
		strcpy(output, input);
	}
}

/*  The Histogram function creates one string in which contains a border outline made of 
	the symbol '*' and a graph using 'X' for height of each bar. This function has 3 inputs
	values which is an array filled with the heights of each bar, result which is where the 
	string is stored and numValues the amount of values in the array values.
	
	This function works by first finding the largest value in the array values and is stored
	in the max variable. Then a loop is created in which creates the top border with '*' which 
	is stored by using a counter 'k++' which goes to the next element in the array result.
	Then the '\n' is added to start the nested loop. The nested loop prints the left hand side
	border if j==0 and also adds the X into the array if the max value is equal to any number
	in the array.If it does equal then that number in that element of the array will decrease by 
	one for the next loop. If none of the elements have the same value as newMax then a ' ' is 
	added into the array. After the first loop is finished another '*' is added which is the 
	right hand side border and another '\n' is added, then the newMax value gets decreased by one
	since the rows go down one as well. After this nested loop another for loop is used as well
	with the counter k++ inside to add the last border (the bottom border line) in the the string
	and then a '\0' is added at the end to end the string.  */
void Histogram(char *result, int *values, int numValues)
{
	int i, j, k, newMax;
	int max = 0;
	k = 0;
	for (i = 0; i < numValues; i++)
	{
		if (values[i] > max)
		{
			max = values[i];
		}
	}
	newMax = max;
	for (i = 0; i <= numValues + 1; i++) /* Adds the top line border */
	{
		result[k] = '*';
		k++;
	}
	result[k] = '\n';
	k++;
	for (i = 0; i < max; i++)
	{
		for (j = 0; j < numValues; j++)
		{
			if (j == 0)
			{
				result[k] = '*'; /* Adds the border on the left hand side */
				k++;
			}
			if (values[j] == newMax)
			{
				result[k] = 'X';
				values[j] = values[j] - 1;
				k++;
			}
			else
			{
				result[k] = ' ';
				k++;
			}
		}
		newMax--;		 /* Decreases newMax so it can look for the next row to draw X */
		result[k] = '*'; /* Adds the border on the right hand side */
		k++;
		result[k] = '\n';
		k++;
	}
	for (i = 0; i <= numValues + 1; i++) /* Adds the bottom line border */
	{
		result[k] = '*';
		k++;
	}
	result[k] = '\0';
}

/* The GoldRush function finds how many gold and pure gold there are in a map.
   Gold is defined as the number 9 while puregold is a 9 surrounded by 8 other
   9s.The other numbers 1-8 are other common minerals.
  
   This function works by using a nested loop with a if condition that if an element
   in the 2D array is equal to 9 it adds one to the variable gold to find how many gold
   there are. Another if statement is added within that statement to find if that piece of 
   gold is surrounded by 8 other pieces of gold. If it is surrounded by 8 other pieces
   that means that the variable puregold will add 1 and count how many puregold there are
   within the map. In the end the variables gold and pure gold are stored in an array called
   results where the first element is gold and 2nd element is puregold.
*/
void GoldRush(int *results, int rows, int cols, int map[MAX_MAP_SIZE][MAX_MAP_SIZE], int bonus)
{
	int i, j, gold, puregold;
	gold = 0;
	puregold = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (map[i][j] == 9)
			{
				gold++;
				if (i != 0 || j != 0 || i != rows - 1 || j != cols - 1) /* Only checks puregold for gold that are not on sides or top/bottom row */
				{
					if (map[i - 1][j - 1] == 9 && map[i - 1][j] == 9 && map[i - 1][j + 1] == 9) /* series of if statements finding whether its puregold */
					{
						if (map[i][j - 1] == 9 && map[i][j + 1] == 9)
						{
							if (map[i + 1][j - 1] == 9 && map[i + 1][j] == 9 && map[i + 1][j + 1] == 9)
							{
								puregold++;
							}
						}
					}
				}
			}
		}
	}
	results[0] = gold;
	results[1] = puregold;
	bonus = 0; /* gets rid of the warning since not used */
}
