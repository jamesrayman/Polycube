# Polycube
A solver of polycube packing puzzles, such as the one below:

\[INSERT IMAGE HERE\]

## Usage

```
polycube [-c] [-n SOLUTIONLIMIT] [-p PRINTLIMIT] PUZZLE
```

where `PUZZLE` is the file containing the puzzle specification.

### Flags

`-c`: output solutions with color

`-n SOLUTIONLIMIT`: stop counting solutions at `SOLUTIONLIMIT`, default is infinity

`-p PRINTLIMIT`: print no more than `PRINTLIMIT` solutions, default is 10

## Puzzle Specification

For examples of puzzle specifications, see `./dat/` and `./test/`.

File which are used to specify polycubes or puzzles should end in `.cube`. Such files are divided by hashtags (`#`) into sections.

The first section is imports. Each line should be a file name, leading to another puzzle specification. From each file, import the first two sections (imports and polycubes). Imports are recursive, and no file is imported twice.

The second section is polycubes. Each polycube begins with a line containing the name, which must be alphanumeric. Following is the 3D representation of the polycube (where `.` means empty and every other non-whitespace character means full) and a blank line. The left-most layer in the representation is the top layer.

The third section is the board specification: 3 integers specifying the length, depth, and height of the puzzle, in that order.

The fourth section specifies the polycubes used in the puzzle: a whitespace separated list of polycube names. If a polycube name is immediately followed by `!` (such as in `5QQ!`), it is not allowed to horizontally slide off the board unless some part of it sits on the bottom layer.

Files which are imported must have at least 2 sections, while puzzle files must have at least 4.
