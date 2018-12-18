# MathParseC-
Another ultrafast repo I'm using to study for math class in a roundabout way (I don't want to study but I want to program and this is math related. Gonna use it to approximate some fourier series)


## Purpose
The goal of this repo is to grab math expressions containing variables as a string and then evaluate them at different points.

## Functionality
As of last updating the readme, it supports addition, subtraction, multiplication, division, exponentiation (including sqrts), sine, and cosine. The expression grammar is given in `interpreter.h` at the top. The great thing about this program is it's super easy to add any new functionality you want by just extending the lexer to parse it and then the interpreter to evaluate it.

Implicit multiplication (e.g. `2sin(3)x`) is not supported in the current version (should be `2*sin(3)*x`), because I don't really need it. If you want to add it though, just change the grammar and go for it. It works surprisingly well and could definitely be useful to someone, so make it yours.

## How to use
There's a `lexer` class that gets fed in a string and then has a `get_next_token` method that gives you the nice juicy tokens from the string. There's an `interpreter` class that takes in that lexer, grabs all its tokens, and then can evaluate the mathematical expression given some input variables stored in an `unordered_map`. The repo is designed such that you parse the string once with the lexer and then used the parsed data multiple times with the interpreter to speed up execution. Example usage:
```
std::unordered_map<std::string, double> vars;
vars["x"] = 5;
vars["pi"] = 3.14159265359;
vars["e"] = 2.71828182846;
lexer lex("3*sin(pi/2)+e^sin(x)-1/2+5^(1/2)");
interpreter inter;
inter.fetch_tokens(lex);
std::cout << inter.interpret(vars) << std::endl; //5.11937
vars["x"] = 2;
std::cout << inter.interpret(vars) << std::endl; //7.21865
```
Also, make sure to compile with C++11 or higher!
