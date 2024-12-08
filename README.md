
<p align="center">
  <img src="./assets/logo_no_background.png" width="400"/>
<br>

# Advent of Code 2024 Solutions

This year, out of boredom, curiosity and because i thought it would be fun, I decided to try to solve all the problems from the Advent of Code.
 
Here are my solutions and some personal impressions for each problem:
- Day 1: [Part 1](./solutions/day1/part1.cpp), [Part 2](./solutions/day1/part2.cpp)
  - pretty basic problem involving sortings for part 1 and maps for part 2
- Day 2: [Part 1](./solutions/day2/part1.cpp), [Part 2](./solutions/day2/part2.cpp)
  - solved part 1 quickly in O(n), got stuck while trying to solve part 2 in O(n) too, ended up using the same logic as in part 1 and reached O(n^2) time complexity
- Day 3: [Part 1](./solutions/day3/part1.cpp), [Part 2](./solutions/day3/part2.cpp)
  - a problem involving lots of parsing, i honestly hated it
  - also after researching a bit about regex i came up with the following solution: [Part 2 w/ regex](./solutions/day3/part2_regex.cpp) which imo is much more elegant
- Day 4: [Part 1](./solutions/day4/part1.cpp), [Part 2](./solutions/day4/part2.cpp)
  - finally a decent problem, the solutions are pretty straightforward, just counting occurences of "XMAX" along any direction for part 1, and check for each 3x3 square if it contains an X-MAS for part 2
- Day 5: [Part 1](./solutions/day5/part1.cpp), [Part 2](./solutions/day5/part2.cpp)
  - again a problem with weird parsing, a cool observation is that there are ordering rules between any two numbers so you can just sort them according to the rules
- Day 6: [Part 1](./solutions/day6/part1.cpp), [Part 2](./solutions/day6/part2.cpp)
  - part 1 was easy, part 2 took me way too long to figure out that it's best just to use bruteforce
- Day 7: [Part 1](./solutions/day7/part1.cpp), [Part 2](./solutions/day7/part2.cpp)
  - took me a while to realise that the evaluation is left-to-right, other than that it was just a backtracking problem
- Day 8: [Part 1](./solutions/day8/part1.cpp), [Part 2](./solutions/day8/part2.cpp)
  - actually a decent problem

Here's a sentence with a footnote. [^1]

[^1]: This is the footnote.