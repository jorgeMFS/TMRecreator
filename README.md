# Turing Machine Recreator
Turing Machine Recreator 

[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](LICENSE)


## INSTALL
Get TMRecreator and make the project, using:

```bash
git clone https://github.com/jorgeMFS/TMRecreator.git;
cd TMRecreator;
make;
```

## RUN TMCompression
There are two ways to run this program see help for clarification :

```bash
./tm --help;
-----------------------------------------------------------------------------
Turing Machine Recreator
-----------------------------------------------------------------------------

Arguments to set flags:

--stMatrix      Indicates programs to print the StateMatrix of a given TMs

 Optional Arguments:

-v, --version   Outputs the version of the program.

-h, --help      Describes program.

-----------------------------------------------------------------------------
Examples:
-----------------------------------------------------------------------------
Recreate specific tm and print tape after x iterations
-----------------------------------------------------------------------------
echo "StateMatrix alphabetSize numberOfStates numberOfIterations" | ./rtm
echo "120111111111 2 2 31" | ./rtm

-----------------------------------------------------------------------------
Print stMatrix of the tm
echo String | ./rtm --stMatrix
echo "StateMatrix alphabetSize numberOfStates numberOfIterations"| ./rtm
```


## CITE
Please cite the followings, if you use TMRecreator:

```Array.<string>
- Processing...
```
## ISSUES
Please let us know if there is any
[issues](https://github.com/jorgeMFS/TMRecreator/issues).

## LICENSE
TMCompression is under GPL v3 license. For more information, click
[here](http://www.gnu.org/licenses/gpl-3.0.html).
