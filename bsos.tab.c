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
#line 1 "src/bsos.y"

#include stdio.h
#include stdlib.h

extern int yylex();
extern void yyerror(const char *msg);

#line 79 "bsos.tab.c"

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

#include "bsos.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TEST = 3,                       /* TEST  */
  YYSYMBOL_EXPR = 4,                       /* EXPR  */
  YYSYMBOL_LOCAL = 5,                      /* LOCAL  */
  YYSYMBOL_DECLARE = 6,                    /* DECLARE  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_THEN = 8,                       /* THEN  */
  YYSYMBOL_ELIF = 9,                       /* ELIF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_FI = 11,                        /* FI  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_CASE = 14,                      /* CASE  */
  YYSYMBOL_ESAC = 15,                      /* ESAC  */
  YYSYMBOL_IN = 16,                        /* IN  */
  YYSYMBOL_DO = 17,                        /* DO  */
  YYSYMBOL_DONE = 18,                      /* DONE  */
  YYSYMBOL_READ = 19,                      /* READ  */
  YYSYMBOL_ECHO = 20,                      /* ECHO  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_EXIT = 22,                      /* EXIT  */
  YYSYMBOL_COMMENT = 23,                   /* COMMENT  */
  YYSYMBOL_ID = 24,                        /* ID  */
  YYSYMBOL_MOT = 25,                       /* MOT  */
  YYSYMBOL_CHAINE = 26,                    /* CHAINE  */
  YYSYMBOL_ENTIER = 27,                    /* ENTIER  */
  YYSYMBOL_28_ = 28,                       /* '+'  */
  YYSYMBOL_29_ = 29,                       /* '-'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_UMOINS = 32,                    /* UMOINS  */
  YYSYMBOL_33_ = 33,                       /* ';'  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_35_ = 35,                       /* '['  */
  YYSYMBOL_36_ = 36,                       /* ']'  */
  YYSYMBOL_37_declare_ = 37,               /* "declare"  */
  YYSYMBOL_38_then_ = 38,                  /* "then"  */
  YYSYMBOL_39_fi_ = 39,                    /* "fi"  */
  YYSYMBOL_40_for_ = 40,                   /* "for"  */
  YYSYMBOL_41_do_ = 41,                    /* "do"  */
  YYSYMBOL_42_done_ = 42,                  /* "done"  */
  YYSYMBOL_43_in_ = 43,                    /* "in"  */
  YYSYMBOL_44_while_ = 44,                 /* "while"  */
  YYSYMBOL_45_until_ = 45,                 /* "until"  */
  YYSYMBOL_46_case_ = 46,                  /* "case"  */
  YYSYMBOL_47_esac_ = 47,                  /* "esac"  */
  YYSYMBOL_48_echo_ = 48,                  /* "echo"  */
  YYSYMBOL_49_read_ = 49,                  /* "read"  */
  YYSYMBOL_50_return_ = 50,                /* "return"  */
  YYSYMBOL_51_exit_ = 51,                  /* "exit"  */
  YYSYMBOL_52_elif_ = 52,                  /* "elif"  */
  YYSYMBOL_53_else_ = 53,                  /* "else"  */
  YYSYMBOL_54_ = 54,                       /* ')'  */
  YYSYMBOL_55_ = 55,                       /* '|'  */
  YYSYMBOL_56_ = 56,                       /* '$'  */
  YYSYMBOL_57_ = 57,                       /* '{'  */
  YYSYMBOL_58_ = 58,                       /* '}'  */
  YYSYMBOL_59_test_ = 59,                  /* "test"  */
  YYSYMBOL_60_o_ = 60,                     /* "-o"  */
  YYSYMBOL_61_a_ = 61,                     /* "-a"  */
  YYSYMBOL_62_ = 62,                       /* '('  */
  YYSYMBOL_63_ = 63,                       /* '!'  */
  YYSYMBOL_64_ = 64,                       /* "!="  */
  YYSYMBOL_65_ = 65,                       /* '?'  */
  YYSYMBOL_66_expr_ = 66,                  /* "expr"  */
  YYSYMBOL_67_n_ = 67,                     /* "-n"  */
  YYSYMBOL_68_z_ = 68,                     /* "-z"  */
  YYSYMBOL_69_eq_ = 69,                    /* "-eq"  */
  YYSYMBOL_70_ne_ = 70,                    /* "-ne"  */
  YYSYMBOL_71_gt_ = 71,                    /* "-gt"  */
  YYSYMBOL_72_ge_ = 72,                    /* "-ge"  */
  YYSYMBOL_73_lt_ = 73,                    /* "-lt"  */
  YYSYMBOL_74_le_ = 74,                    /* "-le"  */
  YYSYMBOL_75_ = 75,                       /* '%'  */
  YYSYMBOL_76_local_ = 76,                 /* "local"  */
  YYSYMBOL_YYACCEPT = 77,                  /* $accept  */
  YYSYMBOL_programme = 78,                 /* programme  */
  YYSYMBOL_liste_instructions = 79,        /* liste_instructions  */
  YYSYMBOL_instruction = 80,               /* instruction  */
  YYSYMBOL_else_part = 81,                 /* else_part  */
  YYSYMBOL_liste_cas = 82,                 /* liste_cas  */
  YYSYMBOL_filtre = 83,                    /* filtre  */
  YYSYMBOL_liste_operandes = 84,           /* liste_operandes  */
  YYSYMBOL_concatenation = 85,             /* concatenation  */
  YYSYMBOL_test_bloc = 86,                 /* test_bloc  */
  YYSYMBOL_test_expr = 87,                 /* test_expr  */
  YYSYMBOL_test_expr2 = 88,                /* test_expr2  */
  YYSYMBOL_test_expr3 = 89,                /* test_expr3  */
  YYSYMBOL_test_instruction = 90,          /* test_instruction  */
  YYSYMBOL_operande = 91,                  /* operande  */
  YYSYMBOL_operateur1 = 92,                /* operateur1  */
  YYSYMBOL_operateur2 = 93,                /* operateur2  */
  YYSYMBOL_somme_entiere = 94,             /* somme_entiere  */
  YYSYMBOL_produit_entier = 95,            /* produit_entier  */
  YYSYMBOL_operande_entier = 96,           /* operande_entier  */
  YYSYMBOL_plus_ou_moins = 97,             /* plus_ou_moins  */
  YYSYMBOL_fois_div_mod = 98,              /* fois_div_mod  */
  YYSYMBOL_declaration_de_fonction = 99,   /* declaration_de_fonction  */
  YYSYMBOL_decl_loc = 100,                 /* decl_loc  */
  YYSYMBOL_appel_de_fonction = 101         /* appel_de_fonction  */
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
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   276

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,     2,     2,    56,    75,     2,     2,
      62,    54,    30,    28,     2,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
       2,    34,     2,    65,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,    55,    58,     2,     2,     2,     2,
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
      25,    26,    27,    32,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    59,    60,    61,    64,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    76
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    20,    20,    24,    25,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    50,    51,    52,    56,    57,    61,    62,
      63,    64,    65,    69,    70,    71,    75,    76,    80,    84,
      85,    89,    90,    94,    95,    96,    97,   101,   102,   103,
     104,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     120,   121,   125,   126,   127,   128,   129,   130,   134,   135,
     139,   140,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   156,   157,   161,   162,   163,   167,   172,   173,   177,
     178
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
  "\"end of file\"", "error", "\"invalid token\"", "TEST", "EXPR",
  "LOCAL", "DECLARE", "IF", "THEN", "ELIF", "ELSE", "FI", "FOR", "WHILE",
  "CASE", "ESAC", "IN", "DO", "DONE", "READ", "ECHO", "RETURN", "EXIT",
  "COMMENT", "ID", "MOT", "CHAINE", "ENTIER", "'+'", "'-'", "'*'", "'/'",
  "UMOINS", "';'", "'='", "'['", "']'", "\"declare\"", "\"then\"",
  "\"fi\"", "\"for\"", "\"do\"", "\"done\"", "\"in\"", "\"while\"",
  "\"until\"", "\"case\"", "\"esac\"", "\"echo\"", "\"read\"",
  "\"return\"", "\"exit\"", "\"elif\"", "\"else\"", "')'", "'|'", "'$'",
  "'{'", "'}'", "\"test\"", "\"-o\"", "\"-a\"", "'('", "'!'", "\"!=\"",
  "'?'", "\"expr\"", "\"-n\"", "\"-z\"", "\"-eq\"", "\"-ne\"", "\"-gt\"",
  "\"-ge\"", "\"-lt\"", "\"-le\"", "'%'", "\"local\"", "$accept",
  "programme", "liste_instructions", "instruction", "else_part",
  "liste_cas", "filtre", "liste_operandes", "concatenation", "test_bloc",
  "test_expr", "test_expr2", "test_expr3", "test_instruction", "operande",
  "operateur1", "operateur2", "somme_entiere", "produit_entier",
  "operande_entier", "plus_ou_moins", "fois_div_mod",
  "declaration_de_fonction", "decl_loc", "appel_de_fonction", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-69)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     156,   -31,    78,     6,    11,   -31,   -31,    76,   169,    40,
      81,    81,    79,    50,   -69,   -69,   -69,    55,    38,   -69,
     -69,    76,    81,   -16,    87,    76,   -69,    59,   -25,   128,
     136,    63,   139,    76,   144,   -69,   -69,   -69,     9,    81,
     -69,    65,   -69,   -69,   156,    55,    -5,   -69,   -69,    14,
     124,   138,   -69,   -69,   176,    76,   156,    76,   -69,   197,
     -69,   -69,   199,     8,   -69,   173,   -69,   207,   156,   169,
     156,   156,   211,   194,    81,   -69,   212,    98,    -4,   -69,
     -69,    18,   -69,   116,    55,   -69,    76,    76,   -69,    55,
      55,   -69,   -69,   -69,   -69,   -69,   -69,    76,    76,   179,
     204,    -6,   169,    81,   186,   -69,   206,     0,   142,   114,
     129,    56,   -69,   -69,   -69,   192,    43,   215,    72,   -69,
      81,   -69,   -69,   -69,    81,   -69,   228,   -69,   143,    76,
      76,   138,   -69,   -69,   -31,   156,   214,    76,   181,   -69,
     187,   -69,    10,   -69,   -69,   156,   -69,   -69,    81,   -69,
     172,   156,   203,   -69,    81,   -69,    -4,   -69,   103,   -69,
     216,    50,   -69,    76,   219,   220,   -69,   233,   117,   131,
     156,   225,   -69,   -69,   223,    81,   -69,   156,   202,   205,
     227,   -69,   -69,   229,   109,   208,   231,   179,   -69,   -69,
      76,   141,   -69,   -69,   210,   -69,   188,   -69,   -69,   -69
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
      19,    21,     0,     2,     4,    17,    18,     0,     0,    53,
      57,     0,     0,     0,     0,    89,    34,     0,     0,     0,
       0,     0,     0,    14,    15,    78,    81,    82,     0,     0,
      20,     0,    22,     1,     0,     0,     0,    60,    61,     0,
      38,    40,    42,    45,    37,     0,     0,     5,    37,     0,
      54,    55,     0,     0,    56,     0,    33,     0,     0,     0,
       0,     0,     0,     0,     0,    74,     0,     0,    69,    71,
      79,     0,     3,     0,     0,    46,     0,     0,    36,     0,
       0,    62,    63,    64,    65,    66,    67,     0,    49,    25,
       0,     0,    90,     0,     0,    88,     0,     0,     0,     0,
       0,     0,    28,    29,    32,     0,     0,     0,     0,    80,
       0,    83,    84,    85,     0,    77,     0,    43,     0,    47,
      48,    39,    41,    50,     0,     0,     0,     0,     0,    51,
       0,    59,     0,     7,     9,     0,    11,    12,     0,    13,
       0,     0,     0,    16,     0,    72,    68,    70,     0,    44,
       0,    24,     8,     6,     0,     0,    58,     0,     0,     0,
       0,     0,    30,    31,     0,     0,    75,     0,     0,     0,
       0,    86,    10,     0,     0,     0,     0,    25,    35,    52,
       0,     0,    27,    73,     0,    23,     0,    26,    76,    87
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -69,   -69,   -46,   -40,    77,   -69,   150,     4,   -18,     2,
      -7,   180,   182,   224,    -2,   -69,   -69,   168,   153,    -9,
     -68,   -69,   -69,   -69,   213
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    12,    13,    14,   136,   115,   116,    25,    49,    18,
      50,    51,    52,    53,    88,    55,    97,    77,    78,    79,
      41,   124,    15,   142,    16
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      26,    40,    42,    57,    82,    32,    26,    29,    30,   120,
      99,    60,    33,    59,    61,    54,    68,     1,    69,    58,
      19,    20,   107,    66,   109,   110,   121,   122,    17,   138,
      27,    66,   102,    44,     2,    28,    75,    98,    83,    19,
      20,    62,   144,    54,    54,   125,    63,     3,    86,    64,
       4,    31,   139,    58,     5,     6,     7,    84,     8,     9,
      10,    11,    47,    48,    34,   117,    76,    26,   129,   130,
      31,   123,   120,   108,   103,   126,    56,   128,    87,    43,
      19,    20,    54,    44,    58,    58,   167,    54,    54,   161,
      60,   148,    80,    61,    67,   133,   168,   151,   152,   169,
      26,    19,    20,    19,    20,   171,    66,   154,    35,    36,
      37,    31,    21,    22,   139,   157,     1,    45,    46,   163,
      72,    81,    47,    48,   183,    63,    36,    37,    64,   165,
     155,   187,    31,     2,    23,    58,   160,    38,   175,   165,
      24,    65,   192,    39,    82,   174,     3,    44,     1,     4,
      44,    82,   119,     5,     6,     7,   146,     8,     9,    10,
      11,   176,    44,     1,    44,     2,   186,    19,    20,    70,
     127,   147,   196,   182,   197,   181,    89,    71,     3,    74,
       2,     4,    73,   145,    89,     5,     6,     7,    58,     8,
       9,    10,    11,     3,    19,    20,     4,   159,    31,    90,
       5,     6,     7,    89,     8,     9,    10,    11,    35,    36,
      37,   164,    44,    19,    20,    36,    37,   112,   113,   112,
     113,   199,   114,   101,   114,    23,   170,   152,   172,   173,
     105,   134,   135,   100,   106,   111,   118,    38,   137,   149,
     141,   166,   143,    39,    31,    91,    92,    93,    94,    95,
      96,   153,   158,   162,   177,   178,   179,   180,   184,   185,
     188,   190,   191,   189,   195,   150,   193,   194,   198,   131,
      85,   140,   132,   156,     0,     0,   104
};

static const yytype_int16 yycheck[] =
{
       2,    10,    11,    21,    44,     7,     8,     5,     6,    77,
      56,    27,     8,    22,    30,    17,    41,     7,    43,    21,
      25,    26,    68,    25,    70,    71,    30,    31,    59,    35,
      24,    33,    24,    33,    24,    24,    27,    55,    45,    25,
      26,    57,    42,    45,    46,    27,    62,    37,    34,    65,
      40,    56,    58,    55,    44,    45,    46,    62,    48,    49,
      50,    51,    67,    68,    24,    74,    57,    69,    86,    87,
      56,    75,   140,    69,    66,    57,    38,    84,    64,     0,
      25,    26,    84,    33,    86,    87,    76,    89,    90,   135,
      27,    35,    27,    30,    35,    97,   142,    54,    55,   145,
     102,    25,    26,    25,    26,   151,   108,    35,    27,    28,
      29,    56,    34,    35,    58,   124,     7,    62,    63,   137,
      57,    56,    67,    68,   170,    62,    28,    29,    65,   138,
      58,   177,    56,    24,    56,   137,   134,    56,    35,   148,
      62,    54,    33,    62,   184,   154,    37,    33,     7,    40,
      33,   191,    54,    44,    45,    46,    42,    48,    49,    50,
      51,    58,    33,     7,    33,    24,   175,    25,    26,    41,
      54,    42,   190,    42,    33,    58,    60,    41,    37,    35,
      24,    40,    43,    41,    60,    44,    45,    46,   190,    48,
      49,    50,    51,    37,    25,    26,    40,    54,    56,    61,
      44,    45,    46,    60,    48,    49,    50,    51,    27,    28,
      29,    30,    33,    25,    26,    28,    29,    25,    26,    25,
      26,    33,    30,    24,    30,    56,    54,    55,    25,    26,
      57,    52,    53,    36,    27,    24,    24,    56,    34,    47,
      54,    54,    36,    62,    56,    69,    70,    71,    72,    73,
      74,    36,    24,    39,    38,    36,    36,    24,    33,    36,
      58,    34,    33,    58,   187,   115,    58,    36,    58,    89,
      46,   103,    90,   120,    -1,    -1,    63
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    24,    37,    40,    44,    45,    46,    48,    49,
      50,    51,    78,    79,    80,    99,   101,    59,    86,    25,
      26,    34,    35,    56,    62,    84,    91,    24,    24,    86,
      86,    56,    91,    84,    24,    27,    28,    29,    56,    62,
      96,    97,    96,     0,    33,    62,    63,    67,    68,    85,
      87,    88,    89,    90,    91,    92,    38,    85,    91,    96,
      27,    30,    57,    62,    65,    54,    91,    35,    41,    43,
      41,    41,    57,    43,    35,    27,    57,    94,    95,    96,
      27,    56,    80,    87,    62,    90,    34,    64,    91,    60,
      61,    69,    70,    71,    72,    73,    74,    93,    85,    79,
      36,    24,    24,    66,   101,    57,    27,    79,    84,    79,
      79,    24,    25,    26,    30,    82,    83,    96,    24,    54,
      97,    30,    31,    75,    98,    27,    57,    54,    87,    85,
      85,    88,    89,    91,    52,    53,    81,    34,    35,    58,
      94,    54,   100,    36,    42,    41,    42,    42,    35,    47,
      83,    54,    55,    36,    35,    58,    95,    96,    24,    54,
      86,    79,    39,    85,    30,    96,    54,    76,    79,    79,
      54,    79,    25,    26,    96,    35,    58,    38,    36,    36,
      24,    58,    42,    79,    33,    36,    96,    79,    58,    58,
      34,    33,    33,    58,    36,    81,    85,    33,    58,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    77,    78,    79,    79,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    81,    81,    81,    82,    82,    83,    83,
      83,    83,    83,    84,    84,    84,    85,    85,    86,    87,
      87,    88,    88,    89,    89,    89,    89,    90,    90,    90,
      90,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      92,    92,    93,    93,    93,    93,    93,    93,    94,    94,
      95,    95,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    97,    97,    98,    98,    98,    99,   100,   100,   101,
     101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     3,     6,     5,     6,     5,
       7,     5,     5,     5,     2,     2,     5,     1,     1,     1,
       2,     1,     2,     5,     2,     0,     6,     5,     1,     1,
       3,     3,     1,     2,     1,     7,     2,     1,     2,     3,
       1,     3,     1,     3,     4,     1,     2,     3,     3,     2,
       3,     4,     7,     1,     2,     2,     2,     1,     5,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     4,     7,     2,     5,     8,     3,     1,     2,
       3,     1,     1,     1,     1,     1,     7,     6,     0,     2,
       1
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
  case 2: /* programme: liste_instructions  */
#line 20 "src/bsos.y"
                     {}
#line 1316 "bsos.tab.c"
    break;

  case 3: /* liste_instructions: liste_instructions ';' instruction  */
#line 24 "src/bsos.y"
                                     {}
#line 1322 "bsos.tab.c"
    break;

  case 4: /* liste_instructions: instruction  */
#line 25 "src/bsos.y"
              {}
#line 1328 "bsos.tab.c"
    break;

  case 5: /* instruction: ID '=' concatenation  */
#line 29 "src/bsos.y"
                       {}
#line 1334 "bsos.tab.c"
    break;

  case 6: /* instruction: ID '[' operande_entier ']' '=' concatenation  */
#line 30 "src/bsos.y"
                                               {}
#line 1340 "bsos.tab.c"
    break;

  case 7: /* instruction: "declare" ID '[' ENTIER ']'  */
#line 31 "src/bsos.y"
                              {}
#line 1346 "bsos.tab.c"
    break;

  case 8: /* instruction: IF test_bloc "then" liste_instructions else_part "fi"  */
#line 32 "src/bsos.y"
                                                        {}
#line 1352 "bsos.tab.c"
    break;

  case 9: /* instruction: "for" ID "do" liste_instructions "done"  */
#line 33 "src/bsos.y"
                                          {}
#line 1358 "bsos.tab.c"
    break;

  case 10: /* instruction: "for" ID "in" liste_operandes "do" liste_instructions "done"  */
#line 34 "src/bsos.y"
                                                               {}
#line 1364 "bsos.tab.c"
    break;

  case 11: /* instruction: "while" test_bloc "do" liste_instructions "done"  */
#line 35 "src/bsos.y"
                                                   {}
#line 1370 "bsos.tab.c"
    break;

  case 12: /* instruction: "until" test_bloc "do" liste_instructions "done"  */
#line 36 "src/bsos.y"
                                                   {}
#line 1376 "bsos.tab.c"
    break;

  case 13: /* instruction: "case" operande "in" liste_cas "esac"  */
#line 37 "src/bsos.y"
                                        {}
#line 1382 "bsos.tab.c"
    break;

  case 14: /* instruction: "echo" liste_operandes  */
#line 38 "src/bsos.y"
                         {}
#line 1388 "bsos.tab.c"
    break;

  case 15: /* instruction: "read" ID  */
#line 39 "src/bsos.y"
            {}
#line 1394 "bsos.tab.c"
    break;

  case 16: /* instruction: "read" ID '[' operande_entier ']'  */
#line 40 "src/bsos.y"
                                    {}
#line 1400 "bsos.tab.c"
    break;

  case 17: /* instruction: declaration_de_fonction  */
#line 41 "src/bsos.y"
                          {}
#line 1406 "bsos.tab.c"
    break;

  case 18: /* instruction: appel_de_fonction  */
#line 42 "src/bsos.y"
                    {}
#line 1412 "bsos.tab.c"
    break;

  case 19: /* instruction: "return"  */
#line 43 "src/bsos.y"
           {}
#line 1418 "bsos.tab.c"
    break;

  case 20: /* instruction: "return" operande_entier  */
#line 44 "src/bsos.y"
                           {}
#line 1424 "bsos.tab.c"
    break;

  case 21: /* instruction: "exit"  */
#line 45 "src/bsos.y"
         {}
#line 1430 "bsos.tab.c"
    break;

  case 22: /* instruction: "exit" operande_entier  */
#line 46 "src/bsos.y"
                         {}
#line 1436 "bsos.tab.c"
    break;

  case 23: /* else_part: "elif" test_bloc "then" liste_instructions else_part  */
#line 50 "src/bsos.y"
                                                       {}
#line 1442 "bsos.tab.c"
    break;

  case 24: /* else_part: "else" liste_instructions  */
#line 51 "src/bsos.y"
                            {}
#line 1448 "bsos.tab.c"
    break;

  case 25: /* else_part: %empty  */
#line 52 "src/bsos.y"
         {}
#line 1454 "bsos.tab.c"
    break;

  case 26: /* liste_cas: liste_cas filtre ')' liste_instructions ';' ';'  */
#line 56 "src/bsos.y"
                                                 {}
#line 1460 "bsos.tab.c"
    break;

  case 27: /* liste_cas: filtre ')' liste_instructions ';' ';'  */
#line 57 "src/bsos.y"
                                       {}
#line 1466 "bsos.tab.c"
    break;

  case 28: /* filtre: MOT  */
#line 61 "src/bsos.y"
      {}
#line 1472 "bsos.tab.c"
    break;

  case 29: /* filtre: CHAINE  */
#line 62 "src/bsos.y"
         {}
#line 1478 "bsos.tab.c"
    break;

  case 30: /* filtre: filtre '|' MOT  */
#line 63 "src/bsos.y"
                 {}
#line 1484 "bsos.tab.c"
    break;

  case 31: /* filtre: filtre '|' CHAINE  */
#line 64 "src/bsos.y"
                    {}
#line 1490 "bsos.tab.c"
    break;

  case 33: /* liste_operandes: liste_operandes operande  */
#line 69 "src/bsos.y"
                           {}
#line 1496 "bsos.tab.c"
    break;

  case 34: /* liste_operandes: operande  */
#line 70 "src/bsos.y"
           {}
#line 1502 "bsos.tab.c"
    break;

  case 35: /* liste_operandes: '$' '{' ID '[' '*' ']' '}'  */
#line 71 "src/bsos.y"
                         {}
#line 1508 "bsos.tab.c"
    break;

  case 36: /* concatenation: concatenation operande  */
#line 75 "src/bsos.y"
                         {}
#line 1514 "bsos.tab.c"
    break;

  case 37: /* concatenation: operande  */
#line 76 "src/bsos.y"
           {}
#line 1520 "bsos.tab.c"
    break;

  case 38: /* test_bloc: "test" test_expr  */
#line 80 "src/bsos.y"
                   {}
#line 1526 "bsos.tab.c"
    break;

  case 39: /* test_expr: test_expr "-o" test_expr2  */
#line 84 "src/bsos.y"
                            {}
#line 1532 "bsos.tab.c"
    break;

  case 40: /* test_expr: test_expr2  */
#line 85 "src/bsos.y"
             {}
#line 1538 "bsos.tab.c"
    break;

  case 41: /* test_expr2: test_expr2 "-a" test_expr3  */
#line 89 "src/bsos.y"
                             {}
#line 1544 "bsos.tab.c"
    break;

  case 42: /* test_expr2: test_expr3  */
#line 90 "src/bsos.y"
             {}
#line 1550 "bsos.tab.c"
    break;

  case 43: /* test_expr3: '(' test_expr ')'  */
#line 94 "src/bsos.y"
                    {}
#line 1556 "bsos.tab.c"
    break;

  case 44: /* test_expr3: '!' '(' test_expr ')'  */
#line 95 "src/bsos.y"
                        {}
#line 1562 "bsos.tab.c"
    break;

  case 45: /* test_expr3: test_instruction  */
#line 96 "src/bsos.y"
                   {}
#line 1568 "bsos.tab.c"
    break;

  case 46: /* test_expr3: '!' test_instruction  */
#line 97 "src/bsos.y"
                       {}
#line 1574 "bsos.tab.c"
    break;

  case 47: /* test_instruction: concatenation '=' concatenation  */
#line 101 "src/bsos.y"
                                  {}
#line 1580 "bsos.tab.c"
    break;

  case 48: /* test_instruction: concatenation "!=" concatenation  */
#line 102 "src/bsos.y"
                                   {}
#line 1586 "bsos.tab.c"
    break;

  case 49: /* test_instruction: operateur1 concatenation  */
#line 103 "src/bsos.y"
                           {}
#line 1592 "bsos.tab.c"
    break;

  case 50: /* test_instruction: operande operateur2 operande  */
#line 104 "src/bsos.y"
                               {}
#line 1598 "bsos.tab.c"
    break;

  case 51: /* operande: '$' '{' ID '}'  */
#line 108 "src/bsos.y"
                 {}
#line 1604 "bsos.tab.c"
    break;

  case 52: /* operande: '$' '{' ID '[' operande_entier ']' '}'  */
#line 109 "src/bsos.y"
                                        {}
#line 1610 "bsos.tab.c"
    break;

  case 53: /* operande: MOT  */
#line 110 "src/bsos.y"
      {}
#line 1616 "bsos.tab.c"
    break;

  case 54: /* operande: '$' ENTIER  */
#line 111 "src/bsos.y"
             {}
#line 1622 "bsos.tab.c"
    break;

  case 55: /* operande: '$' '*'  */
#line 112 "src/bsos.y"
         {}
#line 1628 "bsos.tab.c"
    break;

  case 56: /* operande: '$' '?'  */
#line 113 "src/bsos.y"
         {}
#line 1634 "bsos.tab.c"
    break;

  case 57: /* operande: CHAINE  */
#line 114 "src/bsos.y"
         {}
#line 1640 "bsos.tab.c"
    break;

  case 58: /* operande: '$' '(' "expr" somme_entiere ')'  */
#line 115 "src/bsos.y"
                                  {}
#line 1646 "bsos.tab.c"
    break;

  case 59: /* operande: '$' '(' appel_de_fonction ')'  */
#line 116 "src/bsos.y"
                               {}
#line 1652 "bsos.tab.c"
    break;

  case 60: /* operateur1: "-n"  */
#line 120 "src/bsos.y"
       {}
#line 1658 "bsos.tab.c"
    break;

  case 61: /* operateur1: "-z"  */
#line 121 "src/bsos.y"
       {}
#line 1664 "bsos.tab.c"
    break;

  case 62: /* operateur2: "-eq"  */
#line 125 "src/bsos.y"
        {}
#line 1670 "bsos.tab.c"
    break;

  case 63: /* operateur2: "-ne"  */
#line 126 "src/bsos.y"
        {}
#line 1676 "bsos.tab.c"
    break;

  case 64: /* operateur2: "-gt"  */
#line 127 "src/bsos.y"
        {}
#line 1682 "bsos.tab.c"
    break;

  case 65: /* operateur2: "-ge"  */
#line 128 "src/bsos.y"
        {}
#line 1688 "bsos.tab.c"
    break;

  case 66: /* operateur2: "-lt"  */
#line 129 "src/bsos.y"
        {}
#line 1694 "bsos.tab.c"
    break;

  case 67: /* operateur2: "-le"  */
#line 130 "src/bsos.y"
        {}
#line 1700 "bsos.tab.c"
    break;

  case 68: /* somme_entiere: somme_entiere plus_ou_moins produit_entier  */
#line 134 "src/bsos.y"
                                             {}
#line 1706 "bsos.tab.c"
    break;

  case 69: /* somme_entiere: produit_entier  */
#line 135 "src/bsos.y"
                 {}
#line 1712 "bsos.tab.c"
    break;

  case 70: /* produit_entier: produit_entier fois_div_mod operande_entier  */
#line 139 "src/bsos.y"
                                              {}
#line 1718 "bsos.tab.c"
    break;

  case 71: /* produit_entier: operande_entier  */
#line 140 "src/bsos.y"
                  {}
#line 1724 "bsos.tab.c"
    break;

  case 72: /* operande_entier: '$' '{' ID '}'  */
#line 144 "src/bsos.y"
                {}
#line 1730 "bsos.tab.c"
    break;

  case 73: /* operande_entier: '$' '{' ID '[' operande_entier ']' '}'  */
#line 145 "src/bsos.y"
                                       {}
#line 1736 "bsos.tab.c"
    break;

  case 74: /* operande_entier: '$' ENTIER  */
#line 146 "src/bsos.y"
             {}
#line 1742 "bsos.tab.c"
    break;

  case 75: /* operande_entier: plus_ou_moins '$' '{' ID '}'  */
#line 147 "src/bsos.y"
                              {}
#line 1748 "bsos.tab.c"
    break;

  case 76: /* operande_entier: plus_ou_moins '$' '{' ID '[' operande_entier ']' '}'  */
#line 148 "src/bsos.y"
                                                     {}
#line 1754 "bsos.tab.c"
    break;

  case 77: /* operande_entier: plus_ou_moins '$' ENTIER  */
#line 149 "src/bsos.y"
                           {}
#line 1760 "bsos.tab.c"
    break;

  case 78: /* operande_entier: ENTIER  */
#line 150 "src/bsos.y"
         {}
#line 1766 "bsos.tab.c"
    break;

  case 79: /* operande_entier: plus_ou_moins ENTIER  */
#line 151 "src/bsos.y"
                       {}
#line 1772 "bsos.tab.c"
    break;

  case 80: /* operande_entier: '(' somme_entiere ')'  */
#line 152 "src/bsos.y"
                        {}
#line 1778 "bsos.tab.c"
    break;

  case 81: /* plus_ou_moins: '+'  */
#line 156 "src/bsos.y"
      {}
#line 1784 "bsos.tab.c"
    break;

  case 82: /* plus_ou_moins: '-'  */
#line 157 "src/bsos.y"
      {}
#line 1790 "bsos.tab.c"
    break;

  case 83: /* fois_div_mod: '*'  */
#line 161 "src/bsos.y"
      {}
#line 1796 "bsos.tab.c"
    break;

  case 84: /* fois_div_mod: '/'  */
#line 162 "src/bsos.y"
      {}
#line 1802 "bsos.tab.c"
    break;

  case 85: /* fois_div_mod: '%'  */
#line 163 "src/bsos.y"
      {}
#line 1808 "bsos.tab.c"
    break;

  case 86: /* declaration_de_fonction: ID '(' ')' '{' decl_loc liste_instructions '}'  */
#line 167 "src/bsos.y"
                                                {}
#line 1814 "bsos.tab.c"
    break;

  case 87: /* decl_loc: decl_loc "local" ID '=' concatenation ';'  */
#line 172 "src/bsos.y"
                                            {}
#line 1820 "bsos.tab.c"
    break;

  case 88: /* decl_loc: %empty  */
#line 173 "src/bsos.y"
         {}
#line 1826 "bsos.tab.c"
    break;

  case 89: /* appel_de_fonction: ID liste_operandes  */
#line 177 "src/bsos.y"
                     {}
#line 1832 "bsos.tab.c"
    break;

  case 90: /* appel_de_fonction: ID  */
#line 178 "src/bsos.y"
     {}
#line 1838 "bsos.tab.c"
    break;


#line 1842 "bsos.tab.c"

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

#line 181 "src/bsos.y"
