/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_DEBUGGER_COMMANDY_H_INCLUDED
# define YY_YY_DEBUGGER_COMMANDY_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    LOGICAL_OR = 258,              /* LOGICAL_OR  */
    LOGICAL_AND = 259,             /* LOGICAL_AND  */
    COMPARISON = 260,              /* COMPARISON  */
    EQUALITY = 261,                /* EQUALITY  */
    NEGATE = 262,                  /* NEGATE  */
    LSHIFT = 263,                  /* LSHIFT  */
    RSHIFT = 264,                  /* RSHIFT  */
    BASE = 265,                    /* BASE  */
    BREAK = 266,                   /* BREAK  */
    TBREAK = 267,                  /* TBREAK  */
    CLEAR = 268,                   /* CLEAR  */
    COMMANDS = 269,                /* COMMANDS  */
    CONDITION = 270,               /* CONDITION  */
    CONTINUE = 271,                /* CONTINUE  */
    DEBUGGER_DELETE = 272,         /* DEBUGGER_DELETE  */
    DISASSEMBLE = 273,             /* DISASSEMBLE  */
    DEBUGGER_END = 274,            /* DEBUGGER_END  */
    EVENT = 275,                   /* EVENT  */
    EXIT = 276,                    /* EXIT  */
    FINISH = 277,                  /* FINISH  */
    IF = 278,                      /* IF  */
    DEBUGGER_IGNORE = 279,         /* DEBUGGER_IGNORE  */
    NEXT = 280,                    /* NEXT  */
    DEBUGGER_OUT = 281,            /* DEBUGGER_OUT  */
    PORT = 282,                    /* PORT  */
    DEBUGGER_PRINT = 283,          /* DEBUGGER_PRINT  */
    READ = 284,                    /* READ  */
    SET = 285,                     /* SET  */
    STEP = 286,                    /* STEP  */
    TIME = 287,                    /* TIME  */
    WRITE = 288,                   /* WRITE  */
    NUMBER = 289,                  /* NUMBER  */
    STRING = 290,                  /* STRING  */
    VARIABLE = 291,                /* VARIABLE  */
    DEBUGGER_ERROR = 292           /* DEBUGGER_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define LOGICAL_OR 258
#define LOGICAL_AND 259
#define COMPARISON 260
#define EQUALITY 261
#define NEGATE 262
#define LSHIFT 263
#define RSHIFT 264
#define BASE 265
#define BREAK 266
#define TBREAK 267
#define CLEAR 268
#define COMMANDS 269
#define CONDITION 270
#define CONTINUE 271
#define DEBUGGER_DELETE 272
#define DISASSEMBLE 273
#define DEBUGGER_END 274
#define EVENT 275
#define EXIT 276
#define FINISH 277
#define IF 278
#define DEBUGGER_IGNORE 279
#define NEXT 280
#define DEBUGGER_OUT 281
#define PORT 282
#define DEBUGGER_PRINT 283
#define READ 284
#define SET 285
#define STEP 286
#define TIME 287
#define WRITE 288
#define NUMBER 289
#define STRING 290
#define VARIABLE 291
#define DEBUGGER_ERROR 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 46 "debugger/commandy.y"


  int token;

  libspectrum_dword integer;
  char *string;

  debugger_breakpoint_type bptype;
  debugger_breakpoint_life bplife;
  struct { libspectrum_word mask, value; } port;
  struct { int source; int page; int offset; } location;

  debugger_expression* exp;


#line 157 "debugger/commandy.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_DEBUGGER_COMMANDY_H_INCLUDED  */
