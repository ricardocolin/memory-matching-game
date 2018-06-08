# Memory Matching Game in C++
This is a single C++ file that displays a welcome screen with the ability to select a theme, level of difficulty, and keeps track of cards matched and moves done by the user.

# Example:

WELCOME TO THE MATCHING GAME!!

    SELECT A THEME

1. Animals
2. States
3. Car Brands

Enter your choice (1,2,3): 2


Type E for easy grid: 4x4
Type M for moderate grid: 6x6
Type D for difficult grid: 8x8

Input: e


     1		2		3		4		
   _________________________________
1 |	*		*		*		*		
2 |	*		*		*		*		
3 |	*		*		*		*		
4 |	*		*		*		*		

Cards Matched: 0 Moves: 0

Please insert the FIRST card row and column separated by a comma.(Example: 1,1)
Input: 1,1

Please insert the SECOND card row and column separated by a comma.(Example: 2,2)
Input: 2,2




     1		2		3		4		
   _________________________________
1 |	KS		*		*		*		
2 |	*		MN		*		*		
3 |	*		*		*		*		
4 |	*		*		*		*		

Cards Matched: 0 Moves: 1

Cards did not matched!

Press ENTER to keep going!
