#!/bin/bash

echo -e "~# Filename Testing #~"

echo -n "Testing no input -"
./maze > tmp
if grep -q "Error: Invalid Filename" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing non-file input -"
./maze abc > tmp
if grep -q "Error: Invalid Filename" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing fake filename -"
./maze notRealFile.csv > tmp
if grep -q "Error: Invalid Filename" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -e "\n~# File Format Testing #~"

echo -n "Testing invalid size maze (too small) -"
./maze mazes/smallMaze.csv > tmp
if grep -q "Error: Maze size is too small (height/width should be at least 5 characters)" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing invalid size maze (too large) -"
./maze mazes/largeMaze.csv > tmp
if grep -q "Error: Maze size is too large (height/widht should be no larger than 100 characters)" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing invalid size maze (non-rectangular) -"
./maze mazes/irregularMaze.csv > tmp
if grep -q "Error: Maze size is irregular (should be rectangular)" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing invalid maze characters (unrecognised characters) -"
./maze mazes/invalidCharMaze.csv > tmp
if grep -q "Error: Maze contains invalid characters" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing invalid maze characters (more than one start space) -"
./maze mazes/multipleStartMaze.csv > tmp
if grep -q "Error: Maze contains more than one start space" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing invalid maze characters (no start space) -"
./maze mazes/noStartMaze.csv > tmp
if grep -q "Error: Maze does not contain a start/end space (S/E characters)" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing invalid maze characters (no end space) -"
./maze mazes/noEndMaze.csv > tmp
if grep -q "Error: Maze does not contain a start/end space (S/E characters)" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing valid maze format -"
./maze mazes/correctTestMaze.csv > tmp
if grep -q "Maze file successfully loaded" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -e "\n~# Incorrect User Input Testing #~"

echo -n "Testing empty user input - "
echo "" | timeout 0.2s ./maze mazes/correctTestMaze.csv > tmp
if grep -q "Error: Invalid movement option" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing invalid user input - "
echo "" | timeout 0.2s ./maze mazes/correctTestMaze.csv > tmp
if grep -q "Error: Invalid movement option" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -e "\n~# Maze Movement Input Testing #~"

echo -n "Testing upward movement - "
echo "w" | timeout 0.2s ./maze mazes/correctTestMaze.csv > tmp
if grep -q "Moved Upward:" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing downward movement - "
echo "s" | timeout 0.2s ./maze mazes/correctTestMaze.csv > tmp
if grep -q "Moved Downward:" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing moving left - "
echo "a" | timeout 0.2s ./maze mazes/correctTestMaze.csv > tmp
if grep -q "Moved Left:" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing moving right - "
echo "d" | timeout 0.2s ./maze mazes/correctTestMaze.csv > tmp
if grep -q "Moved Right:" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing maze collision with # - "
timeout 0.2s ./maze mazes/correctTestMaze.csv < inputs/mazeCollision.in > tmp
if grep -q "Cannot move onto a '#' space!" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing maze completion - "
timeout 0.2s ./maze mazes/correctTestMaze.csv < inputs/mazeCompletion1.in > tmp
if grep -q "Maze Completed!" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing alternate maze completion - "
timeout 0.2s ./maze mazes/correctTestMaze.csv < inputs/mazeCompletion2.in > tmp
if grep -q "Maze Completed!" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

rm -f tmp