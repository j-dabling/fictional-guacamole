# Overview

The idea for this project is to have a tool that will play through a text file, turning it into a choose-your-own-adventure type story. This is done through a special syntax written out in the text file. The parser *(main.cpp)* will then read and interpret the syntax into user-prompts, and story branches.

### Syntax Legend
Each of the following characters must be placed at the beginning of the line.
`*` Indicates a user prompt. The parser will output this line to the console and wait for user input before continuing. eg. `*Would you like to [walk] or [run]?` will display to the user as: `Would you like to [walk] or [run]? ` and wait for an answer.
`#` Indicates a story-branch. This can be used to list possible results of a user choice. eg. `#walk` means that the following lines are referenced from the `walk` choice in a branch. 
    *Note: User input is not case sensitive, but makes no other adjustments to user input. Make sure the options are made obvious enough to the user to type them in correctly.*

`#!` can be used as a default option. This will be activated if no other previously listed options match.

`@` indicates a line-jump. This can be used for skipping forward or back to a given line, for example when you would like to return to a previous branch. eg `@21` will skip to line 21 of the file.

WagonTrip.story is included here for example and reference for the syntax.

{Provide a link to your YouTube demonstration.  It should be a 4-5 minute demo of the software running and a walkthrough of the code.  Focus should be on sharing what you learned about the language syntax.}

[Software Demo Video](http://youtube.link.goes.here)

# Development Environment

{Describe the tools that you used to develop the software}

{Describe the programming language that you used and any libraries.}

# Useful Websites

{Make a list of websites that you found helpful in this project}
* [Web Site Name](http://url.link.goes.here)
* [Web Site Name](http://url.link.goes.here)

# Future Work

{Make a list of things that you need to fix, improve, and add in the future.}
* Item 1
* Item 2
* Item 3