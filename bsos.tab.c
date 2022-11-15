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
  YYSYMBOL_55_ = 55,                       /* ";;"  */
  YYSYMBOL_56_ = 56,                       /* '|'  */
  YYSYMBOL_57_ = 57,                       /* "${"  */
  YYSYMBOL_58_ = 58,                       /* "[*]}"  */
  YYSYMBOL_59_test_ = 59,                  /* "test"  */
  YYSYMBOL_60_o_ = 60,                     /* "-o"  */
  YYSYMBOL_61_a_ = 61,                     /* "-a"  */
  YYSYMBOL_62_ = 62,                       /* '('  */
  YYSYMBOL_63_ = 63,                       /* '!'  */
  YYSYMBOL_64_ = 64,                       /* "!="  */
  YYSYMBOL_65_ = 65,                       /* '$'  */
  YYSYMBOL_66_ = 66,                       /* '{'  */
  YYSYMBOL_67_ = 67,                       /* '}'  */
  YYSYMBOL_68_ = 68,                       /* '?'  */
  YYSYMBOL_69_expr_ = 69,                  /* "expr"  */
  YYSYMBOL_70_n_ = 70,                     /* "-n"  */
  YYSYMBOL_71_z_ = 71,                     /* "-z"  */
  YYSYMBOL_72_eq_ = 72,                    /* "-eq"  */
  YYSYMBOL_73_ne_ = 73,                    /* "-ne"  */
  YYSYMBOL_74_gt_ = 74,                    /* "-gt"  */
  YYSYMBOL_75_ge_ = 75,                    /* "-ge"  */
  YYSYMBOL_76_lt_ = 76,                    /* "-lt"  */
  YYSYMBOL_77_le_ = 77,                    /* "-le"  */
  YYSYMBOL_78_ = 78,                       /* '%'  */
  YYSYMBOL_79_local_ = 79,                 /* "local"  */
  YYSYMBOL_YYACCEPT = 80,                  /* $accept  */
  YYSYMBOL_programme = 81,                 /* programme  */
  YYSYMBOL_liste_instructions = 82,        /* liste_instructions  */
  YYSYMBOL_instruction = 83,               /* instruction  */
  YYSYMBOL_else_part = 84,                 /* else_part  */
  YYSYMBOL_liste_cas = 85,                 /* liste_cas  */
  YYSYMBOL_filtre = 86,                    /* filtre  */
  YYSYMBOL_liste_operandes = 87,           /* liste_operandes  */
  YYSYMBOL_88_1 = 88,                      /* $@1  */
  YYSYMBOL_concatenation = 89,             /* concatenation  */
  YYSYMBOL_test_bloc = 90,                 /* test_bloc  */
  YYSYMBOL_test_expr = 91,                 /* test_expr  */
  YYSYMBOL_test_expr2 = 92,                /* test_expr2  */
  YYSYMBOL_93_2 = 93,                      /* $@2  */
  YYSYMBOL_test_expr3 = 94,                /* test_expr3  */
  YYSYMBOL_test_instruction = 95,          /* test_instruction  */
  YYSYMBOL_operande = 96,                  /* operande  */
  YYSYMBOL_97_3 = 97,                      /* $@3  */
  YYSYMBOL_operateur1 = 98,                /* operateur1  */
  YYSYMBOL_operateur2 = 99,                /* operateur2  */
  YYSYMBOL_somme_entiere = 100,            /* somme_entiere  */
  YYSYMBOL_produit_entier = 101,           /* produit_entier  */
  YYSYMBOL_operande_entier = 102,          /* operande_entier  */
  YYSYMBOL_plus_ou_moins = 103,            /* plus_ou_moins  */
  YYSYMBOL_fois_div_mod = 104,             /* fois_div_mod  */
  YYSYMBOL_declaration_de_fonction = 105,  /* declaration_de_fonction  */
  YYSYMBOL_decl_loc = 106,                 /* decl_loc  */
  YYSYMBOL_appel_de_fonction = 107         /* appel_de_fonction  */
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
#define YYLAST   241

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   317


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
       2,     2,     2,    63,     2,     2,    65,    78,     2,     2,
      62,    54,    30,    28,     2,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
       2,    34,     2,    68,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,    56,    67,     2,     2,     2,     2,
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
      53,    55,    57,    58,    59,    60,    61,    64,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    79
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    20,    20,    24,    25,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    50,    51,    52,    56,    57,    61,    62,
      63,    64,    65,    69,    69,    70,    71,    75,    76,    80,
      84,    85,    89,    90,    90,    94,    95,    96,    97,   101,
     102,   103,   104,   108,   109,   109,   110,   111,   112,   113,
     114,   115,   116,   120,   121,   125,   126,   127,   128,   129,
     130,   134,   135,   139,   140,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   156,   157,   161,   162,   163,   167,
     172,   173,   177,   178
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
  "\"return\"", "\"exit\"", "\"elif\"", "\"else\"", "')'", "\";;\"", "'|'",
  "\"${\"", "\"[*]}\"", "\"test\"", "\"-o\"", "\"-a\"", "'('", "'!'",
  "\"!=\"", "'$'", "'{'", "'}'", "'?'", "\"expr\"", "\"-n\"", "\"-z\"",
  "\"-eq\"", "\"-ne\"", "\"-gt\"", "\"-ge\"", "\"-lt\"", "\"-le\"", "'%'",
  "\"local\"", "$accept", "programme", "liste_instructions", "instruction",
  "else_part", "liste_cas", "filtre", "liste_operandes", "$@1",
  "concatenation", "test_bloc", "test_expr", "test_expr2", "$@2",
  "test_expr3", "test_instruction", "operande", "$@3", "operateur1",
  "operateur2", "somme_entiere", "produit_entier", "operande_entier",
  "plus_ou_moins", "fois_div_mod", "declaration_de_fonction", "decl_loc",
  "appel_de_fonction", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-67)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     108,   -41,   136,    13,    75,   -41,   -41,    14,    55,   100,
     137,   137,   105,    94,   -67,   -67,   -67,    48,    92,   -67,
     -67,    14,   137,   116,    87,    63,    14,   -67,   120,   140,
     122,   145,   147,    14,   161,   -67,   -67,   -67,   137,    35,
     -67,   -16,   -67,   -67,   108,    48,    72,   -67,   -67,     7,
     150,   139,   -67,   -67,   131,    14,   108,    14,   -67,   176,
     156,   151,   -67,   -67,   -12,   173,   -67,   -67,   186,   108,
      55,   108,   108,   159,   137,    93,    -3,   -67,   -67,   191,
     -67,    38,   -67,   -25,    48,   -67,    14,    14,   -67,    48,
      48,   137,   -67,   -67,   -67,   -67,   -67,   -67,    14,    14,
     127,   182,   -67,   -67,    55,   137,   164,   -22,   137,   183,
     102,    26,   134,   135,   -67,   -67,   -67,   148,   138,   184,
     -67,   137,   -67,   -67,   -67,   137,   -19,   -67,   197,   -67,
     -24,    14,    14,   139,   -67,   -67,   -67,   -41,   108,   185,
      14,    10,   121,   -67,   137,   -67,   -67,   -67,   -67,   108,
     -67,   -67,   -67,   155,   108,    -4,   -67,    -3,   -67,   137,
     -67,    11,   -67,   187,    94,   -67,    14,   198,    61,   -67,
     190,   149,   108,   -13,   -67,   -67,   192,   137,   -67,   108,
     189,   -67,   160,   -67,    31,   -67,   162,   194,   127,    14,
     -67,   -67,   -67,   165,   -67,    81,   137,   -67,   -67,   -67
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    93,     0,     0,     0,     0,     0,     0,     0,
      19,    21,     0,     2,     4,    17,    18,     0,     0,    56,
      60,     0,     0,     0,     0,     0,    92,    35,     0,     0,
       0,     0,     0,    14,    15,    81,    84,    85,     0,     0,
      20,     0,    22,     1,     0,     0,     0,    63,    64,     0,
      39,    41,    43,    47,    38,     0,     0,     5,    38,     0,
       0,     0,    57,    58,     0,     0,    59,    33,     0,     0,
       0,     0,     0,     0,     0,     0,    72,    74,    77,     0,
      82,     0,     3,     0,     0,    48,     0,     0,    37,     0,
       0,     0,    65,    66,    67,    68,    69,    70,     0,    51,
      25,     0,    36,    91,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,    29,    32,     0,     0,     0,
      83,     0,    86,    87,    88,     0,     0,    80,     0,    45,
       0,    49,    50,    40,    42,    44,    52,     0,     0,     0,
       0,     0,     0,    62,     0,    53,    34,     7,     9,     0,
      11,    12,    13,     0,     0,     0,    16,    71,    73,     0,
      75,     0,    46,     0,    24,     8,     6,     0,     0,    61,
       0,     0,     0,     0,    30,    31,     0,     0,    78,     0,
       0,    89,     0,    10,     0,    27,     0,     0,    25,     0,
      54,    26,    76,     0,    23,     0,     0,    79,    90,    55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   -46,   193,    43,   -67,   117,    -7,   -67,   -17,
       2,    32,   144,   -67,   146,   195,    -2,   -67,   -67,   -67,
     130,   118,    -8,   -66,   -67,   -67,   -67,   174
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    12,    13,    14,   139,   117,   118,    26,   108,    49,
      18,    50,    51,    91,    52,    53,    88,   196,    55,    98,
      75,    76,    77,    41,   125,    15,   141,    16
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      27,    33,    40,    42,    57,    32,    27,    30,    31,   121,
     100,    80,   104,   144,    59,    54,   159,     1,    17,    58,
      44,   174,   175,   110,    67,   112,   113,   122,   123,   129,
     162,    67,    19,    20,     2,    89,    89,    28,    99,    19,
      20,    86,   185,    54,    54,   145,   177,     3,   160,    81,
       4,    19,    20,    58,     5,     6,     7,   105,     8,     9,
      10,    11,    78,   111,    44,   127,   119,   149,    27,   131,
     132,    87,    25,    19,    20,   124,   121,    83,   178,    25,
      19,    20,    54,   135,    58,    58,   191,    54,    54,   167,
      62,    25,   164,    63,    44,   168,   136,    19,    20,    29,
     146,    79,    27,   171,   128,    43,    19,    20,   173,    67,
      45,    46,    23,    25,   198,     1,   130,   158,    47,    48,
      25,    36,    37,   166,    34,    64,   184,    44,   181,    65,
      56,    66,     2,   188,    84,    44,   170,    25,    58,   163,
      60,    61,    47,    48,   148,     3,    25,   120,     4,    36,
      37,   176,     5,     6,     7,    68,     8,     9,    10,    11,
      44,    19,    20,    71,    35,    36,    37,    44,    44,   187,
      21,    22,   195,   114,   115,   169,   150,   151,   116,   137,
     138,    69,    44,    70,   114,   115,    72,    58,   199,   116,
      73,   183,   154,    23,   155,   152,    74,   107,    24,    38,
      90,    25,    39,    92,    93,    94,    95,    96,    97,   172,
      89,   155,   101,   109,   102,   126,   140,   103,   143,   147,
     156,   161,   180,   189,   165,   179,   182,   190,   186,   192,
     193,   194,   197,   133,   153,   142,   134,    82,   106,   157,
       0,    85
};

static const yytype_int16 yycheck[] =
{
       2,     8,    10,    11,    21,     7,     8,     5,     6,    75,
      56,    27,    24,    35,    22,    17,    35,     7,    59,    21,
      33,    25,    26,    69,    26,    71,    72,    30,    31,    54,
      54,    33,    25,    26,    24,    60,    60,    24,    55,    25,
      26,    34,    55,    45,    46,    67,    35,    37,    67,    65,
      40,    25,    26,    55,    44,    45,    46,    69,    48,    49,
      50,    51,    27,    70,    33,    27,    74,    41,    70,    86,
      87,    64,    65,    25,    26,    78,   142,    45,    67,    65,
      25,    26,    84,    91,    86,    87,    55,    89,    90,    79,
      27,    65,   138,    30,    33,   141,    98,    25,    26,    24,
     108,    66,   104,   149,    66,     0,    25,    26,   154,   111,
      62,    63,    57,    65,    33,     7,    84,   125,    70,    71,
      65,    28,    29,   140,    24,    62,   172,    33,    67,    66,
      38,    68,    24,   179,    62,    33,   144,    65,   140,   137,
      24,    54,    70,    71,    42,    37,    65,    54,    40,    28,
      29,   159,    44,    45,    46,    35,    48,    49,    50,    51,
      33,    25,    26,    41,    27,    28,    29,    33,    33,   177,
      34,    35,   189,    25,    26,    54,    42,    42,    30,    52,
      53,    41,    33,    43,    25,    26,    41,   189,   196,    30,
      43,    42,    54,    57,    56,    47,    35,    24,    62,    62,
      61,    65,    65,    72,    73,    74,    75,    76,    77,    54,
      60,    56,    36,    27,    58,    24,    34,    66,    54,    36,
      36,    24,    24,    34,    39,    38,    36,    67,    36,    67,
      36,   188,    67,    89,   117,   105,    90,    44,    64,   121,
      -1,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    24,    37,    40,    44,    45,    46,    48,    49,
      50,    51,    81,    82,    83,   105,   107,    59,    90,    25,
      26,    34,    35,    57,    62,    65,    87,    96,    24,    24,
      90,    90,    96,    87,    24,    27,    28,    29,    62,    65,
     102,   103,   102,     0,    33,    62,    63,    70,    71,    89,
      91,    92,    94,    95,    96,    98,    38,    89,    96,   102,
      24,    54,    27,    30,    62,    66,    68,    96,    35,    41,
      43,    41,    41,    43,    35,   100,   101,   102,    27,    66,
      27,    65,    83,    91,    62,    95,    34,    64,    96,    60,
      61,    93,    72,    73,    74,    75,    76,    77,    99,    89,
      82,    36,    58,    66,    24,    69,   107,    24,    88,    27,
      82,    87,    82,    82,    25,    26,    30,    85,    86,   102,
      54,   103,    30,    31,    78,   104,    24,    27,    66,    54,
      91,    89,    89,    92,    94,   102,    96,    52,    53,    84,
      34,   106,   100,    54,    35,    67,   102,    36,    42,    41,
      42,    42,    47,    86,    54,    56,    36,   101,   102,    35,
      67,    24,    54,    90,    82,    39,    89,    79,    82,    54,
     102,    82,    54,    82,    25,    26,   102,    35,    67,    38,
      24,    67,    36,    42,    82,    55,    36,   102,    82,    34,
      67,    55,    67,    36,    84,    89,    97,    67,    33,   102
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    80,    81,    82,    82,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    84,    84,    84,    85,    85,    86,    86,
      86,    86,    86,    88,    87,    87,    87,    89,    89,    90,
      91,    91,    92,    93,    92,    94,    94,    94,    94,    95,
      95,    95,    95,    96,    97,    96,    96,    96,    96,    96,
      96,    96,    96,    98,    98,    99,    99,    99,    99,    99,
      99,   100,   100,   101,   101,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   103,   103,   104,   104,   104,   105,
     106,   106,   107,   107
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     3,     6,     5,     6,     5,
       7,     5,     5,     5,     2,     2,     5,     1,     1,     1,
       2,     1,     2,     5,     2,     0,     5,     4,     1,     1,
       3,     3,     1,     0,     4,     1,     3,     2,     1,     2,
       3,     1,     3,     0,     3,     3,     4,     1,     2,     3,
       3,     2,     3,     4,     0,     9,     1,     2,     2,     2,
       1,     5,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     4,     7,     2,     5,     8,
       3,     1,     2,     3,     1,     1,     1,     1,     1,     7,
       6,     0,     2,     1
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
#line 1317 "bsos.tab.c"
    break;

  case 3: /* liste_instructions: liste_instructions ';' instruction  */
#line 24 "src/bsos.y"
                                     {}
#line 1323 "bsos.tab.c"
    break;

  case 4: /* liste_instructions: instruction  */
#line 25 "src/bsos.y"
              {}
#line 1329 "bsos.tab.c"
    break;

  case 5: /* instruction: ID '=' concatenation  */
#line 29 "src/bsos.y"
                       {}
#line 1335 "bsos.tab.c"
    break;

  case 6: /* instruction: ID '[' operande_entier ']' '=' concatenation  */
#line 30 "src/bsos.y"
                                               {}
#line 1341 "bsos.tab.c"
    break;

  case 7: /* instruction: "declare" ID '[' ENTIER ']'  */
#line 31 "src/bsos.y"
                              {}
#line 1347 "bsos.tab.c"
    break;

  case 8: /* instruction: IF test_bloc "then" liste_instructions else_part "fi"  */
#line 32 "src/bsos.y"
                                                        {}
#line 1353 "bsos.tab.c"
    break;

  case 9: /* instruction: "for" ID "do" liste_instructions "done"  */
#line 33 "src/bsos.y"
                                          {}
#line 1359 "bsos.tab.c"
    break;

  case 10: /* instruction: "for" ID "in" liste_operandes "do" liste_instructions "done"  */
#line 34 "src/bsos.y"
                                                               {}
#line 1365 "bsos.tab.c"
    break;

  case 11: /* instruction: "while" test_bloc "do" liste_instructions "done"  */
#line 35 "src/bsos.y"
                                                   {}
#line 1371 "bsos.tab.c"
    break;

  case 12: /* instruction: "until" test_bloc "do" liste_instructions "done"  */
#line 36 "src/bsos.y"
                                                   {}
#line 1377 "bsos.tab.c"
    break;

  case 13: /* instruction: "case" operande "in" liste_cas "esac"  */
#line 37 "src/bsos.y"
                                        {}
#line 1383 "bsos.tab.c"
    break;

  case 14: /* instruction: "echo" liste_operandes  */
#line 38 "src/bsos.y"
                         {}
#line 1389 "bsos.tab.c"
    break;

  case 15: /* instruction: "read" ID  */
#line 39 "src/bsos.y"
            {}
#line 1395 "bsos.tab.c"
    break;

  case 16: /* instruction: "read" ID '[' operande_entier ']'  */
#line 40 "src/bsos.y"
                                    {}
#line 1401 "bsos.tab.c"
    break;

  case 17: /* instruction: declaration_de_fonction  */
#line 41 "src/bsos.y"
                          {}
#line 1407 "bsos.tab.c"
    break;

  case 18: /* instruction: appel_de_fonction  */
#line 42 "src/bsos.y"
                    {}
#line 1413 "bsos.tab.c"
    break;

  case 19: /* instruction: "return"  */
#line 43 "src/bsos.y"
           {}
#line 1419 "bsos.tab.c"
    break;

  case 20: /* instruction: "return" operande_entier  */
#line 44 "src/bsos.y"
                           {}
#line 1425 "bsos.tab.c"
    break;

  case 21: /* instruction: "exit"  */
#line 45 "src/bsos.y"
         {}
#line 1431 "bsos.tab.c"
    break;

  case 22: /* instruction: "exit" operande_entier  */
#line 46 "src/bsos.y"
                         {}
#line 1437 "bsos.tab.c"
    break;

  case 23: /* else_part: "elif" test_bloc "then" liste_instructions else_part  */
#line 50 "src/bsos.y"
                                                       {}
#line 1443 "bsos.tab.c"
    break;

  case 24: /* else_part: "else" liste_instructions  */
#line 51 "src/bsos.y"
                            {}
#line 1449 "bsos.tab.c"
    break;

  case 25: /* else_part: %empty  */
#line 52 "src/bsos.y"
         {}
#line 1455 "bsos.tab.c"
    break;

  case 26: /* liste_cas: liste_cas filtre ')' liste_instructions ";;"  */
#line 56 "src/bsos.y"
                                               {}
#line 1461 "bsos.tab.c"
    break;

  case 27: /* liste_cas: filtre ')' liste_instructions ";;"  */
#line 57 "src/bsos.y"
                                     {}
#line 1467 "bsos.tab.c"
    break;

  case 28: /* filtre: MOT  */
#line 61 "src/bsos.y"
      {}
#line 1473 "bsos.tab.c"
    break;

  case 29: /* filtre: CHAINE  */
#line 62 "src/bsos.y"
         {}
#line 1479 "bsos.tab.c"
    break;

  case 30: /* filtre: filtre '|' MOT  */
#line 63 "src/bsos.y"
                 {}
#line 1485 "bsos.tab.c"
    break;

  case 31: /* filtre: filtre '|' CHAINE  */
#line 64 "src/bsos.y"
                    {}
#line 1491 "bsos.tab.c"
    break;

  case 33: /* $@1: %empty  */
#line 69 "src/bsos.y"
                           {}
#line 1497 "bsos.tab.c"
    break;

  case 35: /* liste_operandes: operande  */
#line 70 "src/bsos.y"
           {}
#line 1503 "bsos.tab.c"
    break;

  case 36: /* liste_operandes: "${" ID "[*]}"  */
#line 71 "src/bsos.y"
                 {}
#line 1509 "bsos.tab.c"
    break;

  case 37: /* concatenation: concatenation operande  */
#line 75 "src/bsos.y"
                         {}
#line 1515 "bsos.tab.c"
    break;

  case 38: /* concatenation: operande  */
#line 76 "src/bsos.y"
           {}
#line 1521 "bsos.tab.c"
    break;

  case 39: /* test_bloc: "test" test_expr  */
#line 80 "src/bsos.y"
                   {}
#line 1527 "bsos.tab.c"
    break;

  case 40: /* test_expr: test_expr "-o" test_expr2  */
#line 84 "src/bsos.y"
                            {}
#line 1533 "bsos.tab.c"
    break;

  case 41: /* test_expr: test_expr2  */
#line 85 "src/bsos.y"
             {}
#line 1539 "bsos.tab.c"
    break;

  case 42: /* test_expr2: test_expr2 "-a" test_expr3  */
#line 89 "src/bsos.y"
                             {}
#line 1545 "bsos.tab.c"
    break;

  case 43: /* $@2: %empty  */
#line 90 "src/bsos.y"
             {}
#line 1551 "bsos.tab.c"
    break;

  case 45: /* test_expr3: '(' test_expr ')'  */
#line 94 "src/bsos.y"
                    {}
#line 1557 "bsos.tab.c"
    break;

  case 46: /* test_expr3: '!' '(' test_expr ')'  */
#line 95 "src/bsos.y"
                        {}
#line 1563 "bsos.tab.c"
    break;

  case 47: /* test_expr3: test_instruction  */
#line 96 "src/bsos.y"
                   {}
#line 1569 "bsos.tab.c"
    break;

  case 48: /* test_expr3: '!' test_instruction  */
#line 97 "src/bsos.y"
                       {}
#line 1575 "bsos.tab.c"
    break;

  case 49: /* test_instruction: concatenation '=' concatenation  */
#line 101 "src/bsos.y"
                                  {}
#line 1581 "bsos.tab.c"
    break;

  case 50: /* test_instruction: concatenation "!=" concatenation  */
#line 102 "src/bsos.y"
                                   {}
#line 1587 "bsos.tab.c"
    break;

  case 51: /* test_instruction: operateur1 concatenation  */
#line 103 "src/bsos.y"
                           {}
#line 1593 "bsos.tab.c"
    break;

  case 52: /* test_instruction: operande operateur2 operande  */
#line 104 "src/bsos.y"
                               {}
#line 1599 "bsos.tab.c"
    break;

  case 53: /* operande: '$' '{' ID '}'  */
#line 108 "src/bsos.y"
                 {}
#line 1605 "bsos.tab.c"
    break;

  case 54: /* $@3: %empty  */
#line 109 "src/bsos.y"
                                        {}
#line 1611 "bsos.tab.c"
    break;

  case 56: /* operande: MOT  */
#line 110 "src/bsos.y"
      {}
#line 1617 "bsos.tab.c"
    break;

  case 57: /* operande: '$' ENTIER  */
#line 111 "src/bsos.y"
             {}
#line 1623 "bsos.tab.c"
    break;

  case 58: /* operande: '$' '*'  */
#line 112 "src/bsos.y"
         {}
#line 1629 "bsos.tab.c"
    break;

  case 59: /* operande: '$' '?'  */
#line 113 "src/bsos.y"
         {}
#line 1635 "bsos.tab.c"
    break;

  case 60: /* operande: CHAINE  */
#line 114 "src/bsos.y"
         {}
#line 1641 "bsos.tab.c"
    break;

  case 61: /* operande: '$' '(' "expr" somme_entiere ')'  */
#line 115 "src/bsos.y"
                                  {}
#line 1647 "bsos.tab.c"
    break;

  case 62: /* operande: '$' '(' appel_de_fonction ')'  */
#line 116 "src/bsos.y"
                               {}
#line 1653 "bsos.tab.c"
    break;

  case 63: /* operateur1: "-n"  */
#line 120 "src/bsos.y"
       {}
#line 1659 "bsos.tab.c"
    break;

  case 64: /* operateur1: "-z"  */
#line 121 "src/bsos.y"
       {}
#line 1665 "bsos.tab.c"
    break;

  case 65: /* operateur2: "-eq"  */
#line 125 "src/bsos.y"
        {}
#line 1671 "bsos.tab.c"
    break;

  case 66: /* operateur2: "-ne"  */
#line 126 "src/bsos.y"
        {}
#line 1677 "bsos.tab.c"
    break;

  case 67: /* operateur2: "-gt"  */
#line 127 "src/bsos.y"
        {}
#line 1683 "bsos.tab.c"
    break;

  case 68: /* operateur2: "-ge"  */
#line 128 "src/bsos.y"
        {}
#line 1689 "bsos.tab.c"
    break;

  case 69: /* operateur2: "-lt"  */
#line 129 "src/bsos.y"
        {}
#line 1695 "bsos.tab.c"
    break;

  case 70: /* operateur2: "-le"  */
#line 130 "src/bsos.y"
        {}
#line 1701 "bsos.tab.c"
    break;

  case 71: /* somme_entiere: somme_entiere plus_ou_moins produit_entier  */
#line 134 "src/bsos.y"
                                             {}
#line 1707 "bsos.tab.c"
    break;

  case 72: /* somme_entiere: produit_entier  */
#line 135 "src/bsos.y"
                 {}
#line 1713 "bsos.tab.c"
    break;

  case 73: /* produit_entier: produit_entier fois_div_mod operande_entier  */
#line 139 "src/bsos.y"
                                              {}
#line 1719 "bsos.tab.c"
    break;

  case 74: /* produit_entier: operande_entier  */
#line 140 "src/bsos.y"
                  {}
#line 1725 "bsos.tab.c"
    break;

  case 75: /* operande_entier: '$' '{' ID '}'  */
#line 144 "src/bsos.y"
                {}
#line 1731 "bsos.tab.c"
    break;

  case 76: /* operande_entier: '$' '{' ID '[' operande_entier ']' '}'  */
#line 145 "src/bsos.y"
                                       {}
#line 1737 "bsos.tab.c"
    break;

  case 77: /* operande_entier: '$' ENTIER  */
#line 146 "src/bsos.y"
             {}
#line 1743 "bsos.tab.c"
    break;

  case 78: /* operande_entier: plus_ou_moins '$' '{' ID '}'  */
#line 147 "src/bsos.y"
                              {}
#line 1749 "bsos.tab.c"
    break;

  case 79: /* operande_entier: plus_ou_moins '$' '{' ID '[' operande_entier ']' '}'  */
#line 148 "src/bsos.y"
                                                     {}
#line 1755 "bsos.tab.c"
    break;

  case 80: /* operande_entier: plus_ou_moins '$' ENTIER  */
#line 149 "src/bsos.y"
                           {}
#line 1761 "bsos.tab.c"
    break;

  case 81: /* operande_entier: ENTIER  */
#line 150 "src/bsos.y"
         {}
#line 1767 "bsos.tab.c"
    break;

  case 82: /* operande_entier: plus_ou_moins ENTIER  */
#line 151 "src/bsos.y"
                       {}
#line 1773 "bsos.tab.c"
    break;

  case 83: /* operande_entier: '(' somme_entiere ')'  */
#line 152 "src/bsos.y"
                        {}
#line 1779 "bsos.tab.c"
    break;

  case 84: /* plus_ou_moins: '+'  */
#line 156 "src/bsos.y"
      {}
#line 1785 "bsos.tab.c"
    break;

  case 85: /* plus_ou_moins: '-'  */
#line 157 "src/bsos.y"
      {}
#line 1791 "bsos.tab.c"
    break;

  case 86: /* fois_div_mod: '*'  */
#line 161 "src/bsos.y"
      {}
#line 1797 "bsos.tab.c"
    break;

  case 87: /* fois_div_mod: '/'  */
#line 162 "src/bsos.y"
      {}
#line 1803 "bsos.tab.c"
    break;

  case 88: /* fois_div_mod: '%'  */
#line 163 "src/bsos.y"
      {}
#line 1809 "bsos.tab.c"
    break;

  case 89: /* declaration_de_fonction: ID '(' ')' '{' decl_loc liste_instructions '}'  */
#line 167 "src/bsos.y"
                                                {}
#line 1815 "bsos.tab.c"
    break;

  case 90: /* decl_loc: decl_loc "local" ID '=' concatenation ';'  */
#line 172 "src/bsos.y"
                                            {}
#line 1821 "bsos.tab.c"
    break;

  case 91: /* decl_loc: %empty  */
#line 173 "src/bsos.y"
         {}
#line 1827 "bsos.tab.c"
    break;

  case 92: /* appel_de_fonction: ID liste_operandes  */
#line 177 "src/bsos.y"
                     {}
#line 1833 "bsos.tab.c"
    break;

  case 93: /* appel_de_fonction: ID  */
#line 178 "src/bsos.y"
     {}
#line 1839 "bsos.tab.c"
    break;


#line 1843 "bsos.tab.c"

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
