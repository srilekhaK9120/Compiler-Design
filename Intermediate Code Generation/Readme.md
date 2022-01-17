COMMANDS TO EXECUTE:

1. bison -o rule.c  -d  parser.y $(-Wno)
2. flex -o lex.c  lexer.l
3. g++ -o trans rule.c lex.c -lfl -lm -w
4. ./trans testcases/testcasefile.c 

NOTE: Please copy and paste the commands for accurate result.
The commands mentioned above are for unix-like Operating Systems only.

After executing, the 3-address codes are also generated as 'output.txt' file.
