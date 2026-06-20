/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 26 "debugger/commandy.y"


#include "config.h"

#include <stdio.h>		/* Needed by NetBSD yacc */
#include <stdlib.h>
#include <string.h>

#include "debugger/debugger.h"
#include "debugger/debugger_internals.h"
#include "mempool.h"
#include "ui/ui.h"
#include "z80/z80.h"
#include "z80/z80_macros.h"

#define YYDEBUG 1
#define YYERROR_VERBOSE


#line 91 "debugger/commandy.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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


#line 234 "debugger/commandy.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_DEBUGGER_COMMANDY_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LOGICAL_OR = 3,                 /* LOGICAL_OR  */
  YYSYMBOL_LOGICAL_AND = 4,                /* LOGICAL_AND  */
  YYSYMBOL_COMPARISON = 5,                 /* COMPARISON  */
  YYSYMBOL_EQUALITY = 6,                   /* EQUALITY  */
  YYSYMBOL_NEGATE = 7,                     /* NEGATE  */
  YYSYMBOL_LSHIFT = 8,                     /* LSHIFT  */
  YYSYMBOL_RSHIFT = 9,                     /* RSHIFT  */
  YYSYMBOL_BASE = 10,                      /* BASE  */
  YYSYMBOL_BREAK = 11,                     /* BREAK  */
  YYSYMBOL_TBREAK = 12,                    /* TBREAK  */
  YYSYMBOL_CLEAR = 13,                     /* CLEAR  */
  YYSYMBOL_COMMANDS = 14,                  /* COMMANDS  */
  YYSYMBOL_CONDITION = 15,                 /* CONDITION  */
  YYSYMBOL_CONTINUE = 16,                  /* CONTINUE  */
  YYSYMBOL_DEBUGGER_DELETE = 17,           /* DEBUGGER_DELETE  */
  YYSYMBOL_DISASSEMBLE = 18,               /* DISASSEMBLE  */
  YYSYMBOL_DEBUGGER_END = 19,              /* DEBUGGER_END  */
  YYSYMBOL_EVENT = 20,                     /* EVENT  */
  YYSYMBOL_EXIT = 21,                      /* EXIT  */
  YYSYMBOL_FINISH = 22,                    /* FINISH  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_DEBUGGER_IGNORE = 24,           /* DEBUGGER_IGNORE  */
  YYSYMBOL_NEXT = 25,                      /* NEXT  */
  YYSYMBOL_DEBUGGER_OUT = 26,              /* DEBUGGER_OUT  */
  YYSYMBOL_PORT = 27,                      /* PORT  */
  YYSYMBOL_DEBUGGER_PRINT = 28,            /* DEBUGGER_PRINT  */
  YYSYMBOL_READ = 29,                      /* READ  */
  YYSYMBOL_SET = 30,                       /* SET  */
  YYSYMBOL_STEP = 31,                      /* STEP  */
  YYSYMBOL_TIME = 32,                      /* TIME  */
  YYSYMBOL_WRITE = 33,                     /* WRITE  */
  YYSYMBOL_NUMBER = 34,                    /* NUMBER  */
  YYSYMBOL_STRING = 35,                    /* STRING  */
  YYSYMBOL_VARIABLE = 36,                  /* VARIABLE  */
  YYSYMBOL_DEBUGGER_ERROR = 37,            /* DEBUGGER_ERROR  */
  YYSYMBOL_38_ = 38,                       /* '|'  */
  YYSYMBOL_39_ = 39,                       /* '^'  */
  YYSYMBOL_40_ = 40,                       /* '&'  */
  YYSYMBOL_41_ = 41,                       /* '+'  */
  YYSYMBOL_42_ = 42,                       /* '-'  */
  YYSYMBOL_43_ = 43,                       /* '*'  */
  YYSYMBOL_44_ = 44,                       /* '/'  */
  YYSYMBOL_45_ = 45,                       /* '%'  */
  YYSYMBOL_46_n_ = 46,                     /* '\n'  */
  YYSYMBOL_47_ = 47,                       /* ':'  */
  YYSYMBOL_48_ = 48,                       /* '('  */
  YYSYMBOL_49_ = 49,                       /* ')'  */
  YYSYMBOL_50_ = 50,                       /* '['  */
  YYSYMBOL_51_ = 51,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_input = 53,                     /* input  */
  YYSYMBOL_command = 54,                   /* command  */
  YYSYMBOL_breakpointlife = 55,            /* breakpointlife  */
  YYSYMBOL_breakpointtype = 56,            /* breakpointtype  */
  YYSYMBOL_breakpointport = 57,            /* breakpointport  */
  YYSYMBOL_breakpointlocation = 58,        /* breakpointlocation  */
  YYSYMBOL_portbreakpointtype = 59,        /* portbreakpointtype  */
  YYSYMBOL_optionalcondition = 60,         /* optionalcondition  */
  YYSYMBOL_numberorpc = 61,                /* numberorpc  */
  YYSYMBOL_expressionornull = 62,          /* expressionornull  */
  YYSYMBOL_number = 63,                    /* number  */
  YYSYMBOL_expression = 64,                /* expression  */
  YYSYMBOL_debuggercommands = 65,          /* debuggercommands  */
  YYSYMBOL_debuggercommand = 66            /* debuggercommand  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   316

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      46,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    45,    40,     2,
      48,    49,    43,    41,     2,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   146,   146,   147,   148,   149,   152,   153,   157,   162,
     166,   170,   174,   175,   176,   179,   180,   181,   182,   183,
     184,   185,   188,   189,   190,   191,   192,   193,   194,   197,
     198,   201,   202,   203,   206,   207,   210,   211,   223,   224,
     227,   228,   231,   232,   235,   236,   239,   242,   245,   248,
     251,   252,   256,   257,   261,   265,   269,   273,   277,   281,
     285,   291,   297,   301,   305,   309,   313,   317,   323,   331,
     332,   337
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LOGICAL_OR",
  "LOGICAL_AND", "COMPARISON", "EQUALITY", "NEGATE", "LSHIFT", "RSHIFT",
  "BASE", "BREAK", "TBREAK", "CLEAR", "COMMANDS", "CONDITION", "CONTINUE",
  "DEBUGGER_DELETE", "DISASSEMBLE", "DEBUGGER_END", "EVENT", "EXIT",
  "FINISH", "IF", "DEBUGGER_IGNORE", "NEXT", "DEBUGGER_OUT", "PORT",
  "DEBUGGER_PRINT", "READ", "SET", "STEP", "TIME", "WRITE", "NUMBER",
  "STRING", "VARIABLE", "DEBUGGER_ERROR", "'|'", "'^'", "'&'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'\\n'", "':'", "'('", "')'", "'['", "']'",
  "$accept", "input", "command", "breakpointlife", "breakpointtype",
  "breakpointport", "breakpointlocation", "portbreakpointtype",
  "optionalcondition", "numberorpc", "expressionornull", "number",
  "expression", "debuggercommands", "debuggercommand", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-33)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      75,   -33,    91,   -33,   -33,    91,    91,   -25,   -33,    91,
      91,    91,   -33,   -11,   -33,    91,    91,    38,   -33,     2,
     -33,    -5,    91,   -33,   -27,   -33,    91,    91,    91,    91,
     -33,   175,   -33,   -33,   -20,    91,   -33,   -33,   -33,   175,
      91,    -1,   -33,    91,    -8,    91,   -33,   285,     1,   -23,
     -33,    91,   -33,   124,   -33,     5,   -33,   -33,   107,    26,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,     9,   -33,   -33,   -33,   -33,    12,
     -33,   -33,    48,   -33,   -33,    91,    14,    55,    14,   -33,
     -33,   -33,   -33,   183,   191,   249,    37,   167,   167,   198,
     239,   244,    92,    92,   -33,   -33,   -33,    61,   -14,   -33,
      91,   -32,    14,    62,    91,   -33,   127,   -33,   -33,   -33,
     -33,   -33,    14,    14,   -33,    91,   175,   -27,    70,   -33,
     -33,   -33,    91,   -33
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     4,     0,    29,    30,    42,     0,     0,    15,    16,
       0,    44,    20,     0,    22,     0,     0,     0,    28,     0,
       3,    31,     0,    47,     0,    49,     0,     0,     0,     0,
       6,    46,    12,    43,     0,    44,    17,    18,    19,    45,
       0,     0,    24,     0,     0,     0,     1,     0,     0,     0,
      32,     0,    33,    42,    54,     0,    52,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,    21,    23,    25,     0,
      26,     5,     0,    38,    39,     0,    40,     0,    40,    36,
      48,    50,    51,    68,    67,    63,    62,    60,    61,    66,
      65,    64,    55,    56,    57,    58,    59,     0,     0,    69,
       0,     0,    40,    34,     0,     9,     0,     7,    71,    13,
      70,    27,    40,    40,     8,     0,    41,    48,     0,    10,
      11,    35,     0,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -33,   -33,    72,   -33,   -33,   -33,   -33,   -33,     6,    31,
      85,    -2,   -10,   -33,    16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    19,    20,    21,    53,   112,    88,    85,   115,    32,
      38,    33,    31,   108,   109
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    39,    46,   122,    34,   119,    83,    36,    37,    35,
      84,   123,    54,    41,    42,    48,    56,    57,    58,    59,
      55,   107,    49,    40,    50,    39,    74,    51,    52,    60,
      61,    62,    63,    77,    64,    65,    82,   114,    76,    79,
      90,    78,    62,    80,   107,    64,    65,   110,    47,    86,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    66,    67,    68,    69,    70,    71,
      72,    73,    43,    44,    45,    -2,     1,    92,    69,    70,
      71,    72,    73,   113,    89,     2,     3,     4,     5,     6,
       7,     8,     9,    10,   117,   111,    11,    12,    22,    13,
      14,    15,   116,    16,   126,    17,    18,   118,   121,   125,
      60,    61,    62,    63,   128,    64,    65,   132,   124,    81,
      75,    -2,     0,   131,   120,    23,    24,    25,   129,   130,
     133,    22,    26,    27,    22,    71,    72,    73,     0,    28,
       0,    29,     0,     0,     0,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,     0,    91,     0,    23,    87,
      25,    23,   127,    25,     0,    26,    27,     0,    26,    27,
       0,     0,    28,     0,    29,    28,     0,    29,    60,    61,
      62,    63,     0,    64,    65,     0,     0,    61,    62,    63,
       0,    64,    65,     0,     0,     0,    62,    63,     0,    64,
      65,     0,     0,    62,    63,     0,    64,    65,    69,    70,
      71,    72,    73,    66,    67,    68,    69,    70,    71,    72,
      73,    66,    67,    68,    69,    70,    71,    72,    73,    66,
      67,    68,    69,    70,    71,    72,    73,    67,    68,    69,
      70,    71,    72,    73,    62,    63,     0,    64,    65,    62,
      63,     0,    64,    65,     0,     0,     0,    64,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
      69,    70,    71,    72,    73,    69,    70,    71,    72,    73,
      69,    70,    71,    72,    73,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,     0,    11,    12,     0,    13,
      14,    15,     0,    16,     0,    17,    18
};

static const yytype_int16 yycheck[] =
{
       2,    11,     0,    35,     6,    19,    29,     9,    10,    34,
      33,    43,    22,    15,    16,    20,    26,    27,    28,    29,
      47,    35,    27,    34,    29,    35,    46,    32,    33,     3,
       4,     5,     6,    34,     8,     9,    35,    23,    40,    47,
      35,    43,     5,    45,    35,     8,     9,    35,    46,    51,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    38,    39,    40,    41,    42,    43,
      44,    45,    34,    35,    36,     0,     1,    51,    41,    42,
      43,    44,    45,    85,    53,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    88,    47,    21,    22,     7,    24,
      25,    26,    47,    28,   114,    30,    31,    46,   110,    47,
       3,     4,     5,     6,   116,     8,     9,    47,   112,    47,
      35,    46,    -1,   125,   108,    34,    35,    36,   122,   123,
     132,     7,    41,    42,     7,    43,    44,    45,    -1,    48,
      -1,    50,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    49,    -1,    34,    35,
      36,    34,    35,    36,    -1,    41,    42,    -1,    41,    42,
      -1,    -1,    48,    -1,    50,    48,    -1,    50,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,     5,     6,    -1,     8,
       9,    -1,    -1,     5,     6,    -1,     8,     9,    41,    42,
      43,    44,    45,    38,    39,    40,    41,    42,    43,    44,
      45,    38,    39,    40,    41,    42,    43,    44,    45,    38,
      39,    40,    41,    42,    43,    44,    45,    39,    40,    41,
      42,    43,    44,    45,     5,     6,    -1,     8,     9,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    41,    42,    43,    44,    45,
      41,    42,    43,    44,    45,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    -1,    21,    22,    -1,    24,
      25,    26,    -1,    28,    -1,    30,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    21,    22,    24,    25,    26,    28,    30,    31,    53,
      54,    55,     7,    34,    35,    36,    41,    42,    48,    50,
      63,    64,    61,    63,    63,    34,    63,    63,    62,    64,
      34,    63,    63,    34,    35,    36,     0,    46,    20,    27,
      29,    32,    33,    56,    64,    47,    64,    64,    64,    64,
       3,     4,     5,     6,     8,     9,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    62,    63,    34,    63,    47,
      63,    54,    35,    29,    33,    59,    63,    35,    58,    61,
      35,    49,    51,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    35,    65,    66,
      35,    47,    57,    63,    23,    60,    47,    60,    46,    19,
      66,    63,    35,    43,    60,    47,    64,    35,    63,    60,
      60,    63,    47,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    53,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    55,
      55,    56,    56,    56,    57,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    65,
      65,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     3,     2,     4,     5,     4,
       6,     6,     2,     5,     3,     1,     1,     2,     2,     2,
       1,     3,     1,     3,     2,     3,     3,     5,     1,     1,
       1,     0,     1,     1,     1,     3,     1,     5,     1,     1,
       0,     2,     0,     1,     0,     1,     1,     1,     3,     1,
       3,     3,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 6: /* command: BASE number  */
#line 152 "debugger/commandy.y"
                       { debugger_output_base = (yyvsp[0].integer); }
#line 1403 "debugger/commandy.c"
    break;

  case 7: /* command: breakpointlife breakpointtype breakpointlocation optionalcondition  */
#line 153 "debugger/commandy.y"
                                                                              {
             debugger_breakpoint_add_address( (yyvsp[-2].bptype), (yyvsp[-1].location).source, (yyvsp[-1].location).page, (yyvsp[-1].location).offset,
                                              0, (yyvsp[-3].bplife), (yyvsp[0].exp) );
	   }
#line 1412 "debugger/commandy.c"
    break;

  case 8: /* command: breakpointlife PORT portbreakpointtype breakpointport optionalcondition  */
#line 157 "debugger/commandy.y"
                                                                                   {
	     int mask = (yyvsp[-1].port).mask;
	     if( mask == 0 ) mask = ( (yyvsp[-1].port).value < 0x100 ? 0x00ff : 0xffff );
	     debugger_breakpoint_add_port( (yyvsp[-2].bptype), (yyvsp[-1].port).value, mask, 0, (yyvsp[-4].bplife), (yyvsp[0].exp) );
           }
#line 1422 "debugger/commandy.c"
    break;

  case 9: /* command: breakpointlife TIME number optionalcondition  */
#line 162 "debugger/commandy.y"
                                                        {
	     debugger_breakpoint_add_time( DEBUGGER_BREAKPOINT_TYPE_TIME,
					   (yyvsp[-1].integer), 0, (yyvsp[-3].bplife), (yyvsp[0].exp) );
	   }
#line 1431 "debugger/commandy.c"
    break;

  case 10: /* command: breakpointlife EVENT STRING ':' STRING optionalcondition  */
#line 166 "debugger/commandy.y"
                                                                    {
	     debugger_breakpoint_add_event( DEBUGGER_BREAKPOINT_TYPE_EVENT,
					    (yyvsp[-3].string), (yyvsp[-1].string), 0, (yyvsp[-5].bplife), (yyvsp[0].exp) );
	   }
#line 1440 "debugger/commandy.c"
    break;

  case 11: /* command: breakpointlife EVENT STRING ':' '*' optionalcondition  */
#line 170 "debugger/commandy.y"
                                                                 {
	     debugger_breakpoint_add_event( DEBUGGER_BREAKPOINT_TYPE_EVENT,
					    (yyvsp[-3].string), "*", 0, (yyvsp[-5].bplife), (yyvsp[0].exp) );
	   }
#line 1449 "debugger/commandy.c"
    break;

  case 12: /* command: CLEAR numberorpc  */
#line 174 "debugger/commandy.y"
                            { debugger_breakpoint_clear( (yyvsp[0].integer) ); }
#line 1455 "debugger/commandy.c"
    break;

  case 13: /* command: COMMANDS number '\n' debuggercommands DEBUGGER_END  */
#line 175 "debugger/commandy.y"
                                                              { debugger_breakpoint_set_commands( (yyvsp[-3].integer), (yyvsp[-1].string) ); }
#line 1461 "debugger/commandy.c"
    break;

  case 14: /* command: CONDITION NUMBER expressionornull  */
#line 176 "debugger/commandy.y"
                                             {
	     debugger_breakpoint_set_condition( (yyvsp[-1].integer), (yyvsp[0].exp) );
           }
#line 1469 "debugger/commandy.c"
    break;

  case 15: /* command: CONTINUE  */
#line 179 "debugger/commandy.y"
                    { debugger_run(); }
#line 1475 "debugger/commandy.c"
    break;

  case 16: /* command: DEBUGGER_DELETE  */
#line 180 "debugger/commandy.y"
                           { debugger_breakpoint_remove_all(); }
#line 1481 "debugger/commandy.c"
    break;

  case 17: /* command: DEBUGGER_DELETE number  */
#line 181 "debugger/commandy.y"
                                  { debugger_breakpoint_remove( (yyvsp[0].integer) ); }
#line 1487 "debugger/commandy.c"
    break;

  case 18: /* command: DISASSEMBLE number  */
#line 182 "debugger/commandy.y"
                              { ui_debugger_disassemble( (yyvsp[0].integer) ); }
#line 1493 "debugger/commandy.c"
    break;

  case 19: /* command: EXIT expressionornull  */
#line 183 "debugger/commandy.y"
                                 { debugger_exit_emulator( (yyvsp[0].exp) ); }
#line 1499 "debugger/commandy.c"
    break;

  case 20: /* command: FINISH  */
#line 184 "debugger/commandy.y"
                    { debugger_breakpoint_exit(); }
#line 1505 "debugger/commandy.c"
    break;

  case 21: /* command: DEBUGGER_IGNORE NUMBER number  */
#line 185 "debugger/commandy.y"
                                         {
	     debugger_breakpoint_ignore( (yyvsp[-1].integer), (yyvsp[0].integer) );
	   }
#line 1513 "debugger/commandy.c"
    break;

  case 22: /* command: NEXT  */
#line 188 "debugger/commandy.y"
                    { debugger_next(); }
#line 1519 "debugger/commandy.c"
    break;

  case 23: /* command: DEBUGGER_OUT number NUMBER  */
#line 189 "debugger/commandy.y"
                                      { debugger_port_write( (yyvsp[-1].integer), (yyvsp[0].integer) ); }
#line 1525 "debugger/commandy.c"
    break;

  case 24: /* command: DEBUGGER_PRINT number  */
#line 190 "debugger/commandy.y"
                                 { printf( "0x%x\n", (yyvsp[0].integer) ); }
#line 1531 "debugger/commandy.c"
    break;

  case 25: /* command: SET NUMBER number  */
#line 191 "debugger/commandy.y"
                             { debugger_poke( (yyvsp[-1].integer), (yyvsp[0].integer) ); }
#line 1537 "debugger/commandy.c"
    break;

  case 26: /* command: SET VARIABLE number  */
#line 192 "debugger/commandy.y"
                               { debugger_variable_set( (yyvsp[-1].string), (yyvsp[0].integer) ); }
#line 1543 "debugger/commandy.c"
    break;

  case 27: /* command: SET STRING ':' STRING number  */
#line 193 "debugger/commandy.y"
                                        { debugger_system_variable_set( (yyvsp[-3].string), (yyvsp[-1].string), (yyvsp[0].integer) ); }
#line 1549 "debugger/commandy.c"
    break;

  case 28: /* command: STEP  */
#line 194 "debugger/commandy.y"
                    { debugger_step(); }
#line 1555 "debugger/commandy.c"
    break;

  case 29: /* breakpointlife: BREAK  */
#line 197 "debugger/commandy.y"
                         { (yyval.bplife) = DEBUGGER_BREAKPOINT_LIFE_PERMANENT; }
#line 1561 "debugger/commandy.c"
    break;

  case 30: /* breakpointlife: TBREAK  */
#line 198 "debugger/commandy.y"
                         { (yyval.bplife) = DEBUGGER_BREAKPOINT_LIFE_ONESHOT; }
#line 1567 "debugger/commandy.c"
    break;

  case 31: /* breakpointtype: %empty  */
#line 201 "debugger/commandy.y"
                              { (yyval.bptype) = DEBUGGER_BREAKPOINT_TYPE_EXECUTE; }
#line 1573 "debugger/commandy.c"
    break;

  case 32: /* breakpointtype: READ  */
#line 202 "debugger/commandy.y"
                              { (yyval.bptype) = DEBUGGER_BREAKPOINT_TYPE_READ; }
#line 1579 "debugger/commandy.c"
    break;

  case 33: /* breakpointtype: WRITE  */
#line 203 "debugger/commandy.y"
                              { (yyval.bptype) = DEBUGGER_BREAKPOINT_TYPE_WRITE; }
#line 1585 "debugger/commandy.c"
    break;

  case 34: /* breakpointport: number  */
#line 206 "debugger/commandy.y"
                         { (yyval.port).mask = 0; (yyval.port).value = (yyvsp[0].integer); }
#line 1591 "debugger/commandy.c"
    break;

  case 35: /* breakpointport: number ':' number  */
#line 207 "debugger/commandy.y"
                                    { (yyval.port).mask = (yyvsp[-2].integer); (yyval.port).value = (yyvsp[0].integer); }
#line 1597 "debugger/commandy.c"
    break;

  case 36: /* breakpointlocation: numberorpc  */
#line 210 "debugger/commandy.y"
                                 { (yyval.location).source = memory_source_any; (yyval.location).offset = (yyvsp[0].integer); }
#line 1603 "debugger/commandy.c"
    break;

  case 37: /* breakpointlocation: STRING ':' number ':' number  */
#line 211 "debugger/commandy.y"
                                                   {
                        (yyval.location).source = memory_source_find( (yyvsp[-4].string) );
                        if( (yyval.location).source == -1 ) {
                          char buffer[80];
                          snprintf( buffer, 80, "unknown memory source \"%s\"", (yyvsp[-4].string) );
                          yyerror( buffer );
                          YYERROR;
                        }
                        (yyval.location).page = (yyvsp[-2].integer);
                        (yyval.location).offset = (yyvsp[0].integer);
                      }
#line 1619 "debugger/commandy.c"
    break;

  case 38: /* portbreakpointtype: READ  */
#line 223 "debugger/commandy.y"
                            { (yyval.bptype) = DEBUGGER_BREAKPOINT_TYPE_PORT_READ; }
#line 1625 "debugger/commandy.c"
    break;

  case 39: /* portbreakpointtype: WRITE  */
#line 224 "debugger/commandy.y"
                            { (yyval.bptype) = DEBUGGER_BREAKPOINT_TYPE_PORT_WRITE; }
#line 1631 "debugger/commandy.c"
    break;

  case 40: /* optionalcondition: %empty  */
#line 227 "debugger/commandy.y"
                                   { (yyval.exp) = NULL; }
#line 1637 "debugger/commandy.c"
    break;

  case 41: /* optionalcondition: IF expression  */
#line 228 "debugger/commandy.y"
                                   { (yyval.exp) = (yyvsp[0].exp); }
#line 1643 "debugger/commandy.c"
    break;

  case 42: /* numberorpc: %empty  */
#line 231 "debugger/commandy.y"
                          { (yyval.integer) = PC; }
#line 1649 "debugger/commandy.c"
    break;

  case 43: /* numberorpc: number  */
#line 232 "debugger/commandy.y"
                          { (yyval.integer) = (yyvsp[0].integer); }
#line 1655 "debugger/commandy.c"
    break;

  case 44: /* expressionornull: %empty  */
#line 235 "debugger/commandy.y"
                                { (yyval.exp) = NULL; }
#line 1661 "debugger/commandy.c"
    break;

  case 45: /* expressionornull: expression  */
#line 236 "debugger/commandy.y"
                                { (yyval.exp) = (yyvsp[0].exp); }
#line 1667 "debugger/commandy.c"
    break;

  case 46: /* number: expression  */
#line 239 "debugger/commandy.y"
                     { (yyval.integer) = debugger_expression_evaluate( (yyvsp[0].exp) ); }
#line 1673 "debugger/commandy.c"
    break;

  case 47: /* expression: NUMBER  */
#line 242 "debugger/commandy.y"
                     { (yyval.exp) = debugger_expression_new_number( (yyvsp[0].integer), debugger_memory_pool );
		       if( !(yyval.exp) ) YYABORT;
		     }
#line 1681 "debugger/commandy.c"
    break;

  case 48: /* expression: STRING ':' STRING  */
#line 245 "debugger/commandy.y"
                                { (yyval.exp) = debugger_expression_new_system_variable( (yyvsp[-2].string), (yyvsp[0].string), debugger_memory_pool );
                                  if( !(yyval.exp) ) YYABORT;
                                }
#line 1689 "debugger/commandy.c"
    break;

  case 49: /* expression: VARIABLE  */
#line 248 "debugger/commandy.y"
                       { (yyval.exp) = debugger_expression_new_variable( (yyvsp[0].string), debugger_memory_pool );
			 if( !(yyval.exp) ) YYABORT;
		       }
#line 1697 "debugger/commandy.c"
    break;

  case 50: /* expression: '(' expression ')'  */
#line 251 "debugger/commandy.y"
                                 { (yyval.exp) = (yyvsp[-1].exp); }
#line 1703 "debugger/commandy.c"
    break;

  case 51: /* expression: '[' expression ']'  */
#line 252 "debugger/commandy.y"
                                 {
                (yyval.exp) = debugger_expression_new_unaryop( DEBUGGER_TOKEN_DEREFERENCE, (yyvsp[-1].exp), debugger_memory_pool );
                if( !(yyval.exp) ) YYABORT;
              }
#line 1712 "debugger/commandy.c"
    break;

  case 52: /* expression: '+' expression  */
#line 256 "debugger/commandy.y"
                                          { (yyval.exp) = (yyvsp[0].exp); }
#line 1718 "debugger/commandy.c"
    break;

  case 53: /* expression: '-' expression  */
#line 257 "debugger/commandy.y"
                                          {
	        (yyval.exp) = debugger_expression_new_unaryop( '-', (yyvsp[0].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
#line 1727 "debugger/commandy.c"
    break;

  case 54: /* expression: NEGATE expression  */
#line 261 "debugger/commandy.y"
                                {
	        (yyval.exp) = debugger_expression_new_unaryop( (yyvsp[-1].token), (yyvsp[0].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
#line 1736 "debugger/commandy.c"
    break;

  case 55: /* expression: expression '+' expression  */
#line 265 "debugger/commandy.y"
                                        {
	        (yyval.exp) = debugger_expression_new_binaryop( '+', (yyvsp[-2].exp), (yyvsp[0].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
#line 1745 "debugger/commandy.c"
    break;

  case 56: /* expression: expression '-' expression  */
#line 269 "debugger/commandy.y"
                                        {
	        (yyval.exp) = debugger_expression_new_binaryop( '-', (yyvsp[-2].exp), (yyvsp[0].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
#line 1754 "debugger/commandy.c"
    break;

  case 57: /* expression: expression '*' expression  */
#line 273 "debugger/commandy.y"
                                        {
	        (yyval.exp) = debugger_expression_new_binaryop( '*', (yyvsp[-2].exp), (yyvsp[0].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
#line 1763 "debugger/commandy.c"
    break;

  case 58: /* expression: expression '/' expression  */
#line 277 "debugger/commandy.y"
                                        {
	        (yyval.exp) = debugger_expression_new_binaryop( '/', (yyvsp[-2].exp), (yyvsp[0].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
#line 1772 "debugger/commandy.c"
    break;

  case 59: /* expression: expression '%' expression  */
#line 281 "debugger/commandy.y"
                                        {
	        (yyval.exp) = debugger_expression_new_binaryop( '%', (yyvsp[-2].exp), (yyvsp[0].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
#line 1781 "debugger/commandy.c"
    break;

  case 60: /* expression: expression LSHIFT expression  */
#line 285 "debugger/commandy.y"
                                           {
	        (yyval.exp) = debugger_expression_new_binaryop(
		  DEBUGGER_TOKEN_LEFT_SHIFT, (yyvsp[-2].exp), (yyvsp[0].exp), debugger_memory_pool
		);
		if( !(yyval.exp) ) YYABORT;
	      }
#line 1792 "debugger/commandy.c"
    break;

  case 61: /* expression: expression RSHIFT expression  */
#line 291 "debugger/commandy.y"
                                           {
	        (yyval.exp) = debugger_expression_new_binaryop(
		  DEBUGGER_TOKEN_RIGHT_SHIFT, (yyvsp[-2].exp), (yyvsp[0].exp), debugger_memory_pool
		);
		if( !(yyval.exp) ) YYABORT;
	      }
#line 1803 "debugger/commandy.c"
    break;

  case 62: /* expression: expression EQUALITY expression  */
#line 297 "debugger/commandy.y"
                                             {
	        (yyval.exp) = debugger_expression_new_binaryop( (yyvsp[-1].token), (yyvsp[-2].exp), (yyvsp[0].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
#line 1812 "debugger/commandy.c"
    break;

  case 63: /* expression: expression COMPARISON expression  */
#line 301 "debugger/commandy.y"
                                               {
	        (yyval.exp) = debugger_expression_new_binaryop( (yyvsp[-1].token), (yyvsp[-2].exp), (yyvsp[0].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
#line 1821 "debugger/commandy.c"
    break;

  case 64: /* expression: expression '&' expression  */
#line 305 "debugger/commandy.y"
                                        {
	        (yyval.exp) = debugger_expression_new_binaryop( '&', (yyvsp[-2].exp), (yyvsp[0].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
#line 1830 "debugger/commandy.c"
    break;

  case 65: /* expression: expression '^' expression  */
#line 309 "debugger/commandy.y"
                                        {
	        (yyval.exp) = debugger_expression_new_binaryop( '^', (yyvsp[-2].exp), (yyvsp[0].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
#line 1839 "debugger/commandy.c"
    break;

  case 66: /* expression: expression '|' expression  */
#line 313 "debugger/commandy.y"
                                        {
	        (yyval.exp) = debugger_expression_new_binaryop( '|', (yyvsp[-2].exp), (yyvsp[0].exp), debugger_memory_pool );
		if( !(yyval.exp) ) YYABORT;
	      }
#line 1848 "debugger/commandy.c"
    break;

  case 67: /* expression: expression LOGICAL_AND expression  */
#line 317 "debugger/commandy.y"
                                                {
	        (yyval.exp) = debugger_expression_new_binaryop(
		  DEBUGGER_TOKEN_LOGICAL_AND, (yyvsp[-2].exp), (yyvsp[0].exp), debugger_memory_pool
                );
		if( !(yyval.exp) ) YYABORT;
	      }
#line 1859 "debugger/commandy.c"
    break;

  case 68: /* expression: expression LOGICAL_OR expression  */
#line 323 "debugger/commandy.y"
                                               {
	        (yyval.exp) = debugger_expression_new_binaryop(
		  DEBUGGER_TOKEN_LOGICAL_OR, (yyvsp[-2].exp), (yyvsp[0].exp), debugger_memory_pool
		);
		if( !(yyval.exp) ) YYABORT;
	      }
#line 1870 "debugger/commandy.c"
    break;

  case 69: /* debuggercommands: debuggercommand  */
#line 331 "debugger/commandy.y"
                                    { (yyval.string) = (yyvsp[0].string); }
#line 1876 "debugger/commandy.c"
    break;

  case 70: /* debuggercommands: debuggercommands debuggercommand  */
#line 332 "debugger/commandy.y"
                                                     {
                      (yyval.string) = mempool_new( debugger_memory_pool, char, strlen( (yyvsp[-1].string) ) + strlen( (yyvsp[0].string) ) + 2 );
                      sprintf( (yyval.string), "%s\n%s", (yyvsp[-1].string), (yyvsp[0].string) );
                    }
#line 1885 "debugger/commandy.c"
    break;


#line 1889 "debugger/commandy.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 339 "debugger/commandy.y"

