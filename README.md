Test task: Provide scheduler and node emulators as the test task.
=====================================================

Good news:   
In order to make the task closer to the real life, it was proposed to 
create a node simulator, which will have a set of units and report its free
resources.

Bad news:   
This node simulator is the only result. It's not enough.
Current implementation contains the node simulator, which have an 
identifier and a set of units to be loaded with tasks. As the tasks to be
run on the node simulator two simple, but CPU consuming problems were chosen. 
These tasks are finding a Nth fibonacci number and checking if the given
number is prime.

Sources:   
The repository contains directory for the scheduling task and
directory with unit tests. It was done and tested on Ubuntu 12.04

System requirements and prerequisites:   
To build the source, a test box should have gcc 4.8.1, make, cmake and gtest. 

Building:   
In the root directory of the test task just run:   
$ make

If unit test didn't get compiled correctly, it's required to re-run cmake
tool in tests directory:   
$ cd tests   
$ cmake CMakeLists.txt   


