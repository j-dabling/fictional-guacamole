# Overview

The idea for this project is to have a tool that will play through a text file, turning it into a choose-your-own-adventure type story. This is done through a special syntax written out in the text file. The parser *(main.cpp)* will then read and interpret the syntax into user-prompts, and story branches.

I used C++ as an exersise in learning re-familiarizing myself with the language.

# Syntax Legend
Each of the following characters must be placed at the beginning of the line.
 * `*` Indicates a user prompt. The parser will output this line to the console and wait for user input before continuing. eg. `*Would you like to [walk] or [run]?` will display to the user as: `Would you like to [walk] or [run]? ` and wait for an answer.

 * `#` Indicates a story-branch. This can be used to list possible results of a user choice. eg. `#walk` means that the following lines are referenced from the `walk` choice in a branch. 
    *Note: User input is not case sensitive, but makes no other adjustments to user input. Make sure the options are made obvious enough to the user to type them in correctly.*

 * `#!` can be used as a default option. This will be activated if no other previously listed options match.

 * `@` indicates a line-jump. This can be used for skipping forward or back to a given line, for example when you would like to return to a previous branch. eg `@21` will skip to line 21 of the file.

WagonTrip.txt is included here for example and reference for the syntax.

[Video demonstration can be found here.](https://youtu.be/BEl5dIrMbk4)

# Development Environment

C++ 11.3.0
Compiled and tested on Linux 6.06, although I doubt there will be any issues compiling for Windows or other platforms.

# Sites I used for reference and help in development.

* [Stack Overflow](http://stackoverflow.com)
* [cplusplus.com](http://cplusplus.com)

# Future Work

* Edit functions to edit given variables instead of returning a modified copy.
* Add config option to allow branch options to be listed as multiple-choice menu.
* Clean up syntax to be easier to write in.