# Push_Swap

## What's the goal of the project ?
Push Swap is a project by 42. The aim is to sort a stack of numbers, with pre-defined instructions and using as few instructions as possible.

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

<img src="https://miro.medium.com/v2/resize:fit:622/format:webp/1*9I_8_h6j1-n0OMcwBgH6pg.png" alt="C" width="300" height="300" />

-Then, for each number in a, we calculate the number of instructions needed to push the number to b, with the number directly below it at the top of the b stack (for example: if the number for which we want to calculate the number of instructions is 4, we'll try to put the number 3 at the top of the b stack, not 2.

<img src="https://miro.medium.com/v2/resize:fit:622/format:webp/1*zi6IXFB5TQ5eYGjIujuLhA.png" alt="C" width="300" height="300" />

-Then we apply the instructions with the smallest sum. And we repeat until the a stack contains only 3 numbers.

<img src="https://miro.medium.com/v2/resize:fit:750/format:webp/1*_oYIpqiFDQTeZbbgpqFGGQ.png" alt="C" width="300" height="300" />

-Then, with a single instruction, we sort a, then gradually put the numbers from a back into b (as b is sorted, it's simpler).

<img src="https://miro.medium.com/v2/resize:fit:750/format:webp/1*9Fu59uvnnFzh6062ARtSow.png" alt="C" width="300" height="300" />

