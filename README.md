# Push_Swap

## What's the goal of the project ?
Push Swap is a project by École 42. The aim is to sort a stack of numbers, with pre-defined instructions and using as few instructions as possible.

### Instruction :

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

## What's the algorithme i'm us ?
My algorithm works in several stages:

-We start by ‘pushing’ 2 elements (as a base for b)

![image](https://github.com/user-attachments/assets/e400c1fa-5056-4c60-9b16-491163667b33) =  width=100

-Then, for each number in a, we calculate the number of instructions needed to push the number to b, with the number directly below it at the top of the b stack (for example: if the number for which we want to calculate the number of instructions is 4, we'll try to put the number 3 at the top of the b stack, not 2.

![image](https://github.com/user-attachments/assets/15255779-9e71-40a8-b6b0-8f03b16bc3dd | width=100)

-Then we apply the instructions with the smallest sum. And we repeat until the a stack contains only 3 numbers.

![image](https://github.com/user-attachments/assets/60ca1ddb-3485-4b30-b3c5-cb68b01d14b7 | width=100)

-Then, with a single instruction, we sort a, then gradually put the numbers from a back into b (as b is sorted, it's simpler).

![image](https://github.com/user-attachments/assets/28c81681-6c88-4b7a-9c62-429dcddaf6af | width=100)

