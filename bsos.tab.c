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
  YYSYMBOL_35_declare_ = 35,               /* "declare"  */
  YYSYMBOL_36_if_ = 36,                    /* "if"  */
  YYSYMBOL_37_then_ = 37,                  /* "then"  */
  YYSYMBOL_38_fi_ = 38,                    /* "fi"  */
  YYSYMBOL_39_for_ = 39,                   /* "for"  */
  YYSYMBOL_40_do_ = 40,                    /* "do"  */
  YYSYMBOL_41_done_ = 41,                  /* "done"  */
  YYSYMBOL_42_in_ = 42,                    /* "in"  */
  YYSYMBOL_43_while_ = 43,                 /* "while"  */
  YYSYMBOL_44_until_ = 44,                 /* "until"  */
  YYSYMBOL_45_case_ = 45,                  /* "case"  */
  YYSYMBOL_46_esac_ = 46,                  /* "esac"  */
  YYSYMBOL_47_echo_ = 47,                  /* "echo"  */
  YYSYMBOL_48_read_ = 48,                  /* "read"  */
  YYSYMBOL_49_return_ = 49,                /* "return"  */
  YYSYMBOL_50_exit_ = 50,                  /* "exit"  */
  YYSYMBOL_51_elif_ = 51,                  /* "elif"  */
  YYSYMBOL_52_else_ = 52,                  /* "else"  */
  YYSYMBOL_53_ = 53,                       /* ')'  */
  YYSYMBOL_54_ = 54,                       /* ";;"  */
  YYSYMBOL_55_ = 55,                       /* '|'  */
  YYSYMBOL_56_ = 56,                       /* "${"  */
  YYSYMBOL_57_ = 57,                       /* "[*]}"  */
  YYSYMBOL_58_test_ = 58,                  /* "test"  */
  YYSYMBOL_59_o_ = 59,                     /* "-o"  */
  YYSYMBOL_60_a_ = 60,                     /* "-a"  */
  YYSYMBOL_61_ = 61,                       /* '('  */
  YYSYMBOL_62_ = 62,                       /* '!'  */
  YYSYMBOL_63_ = 63,                       /* "!="  */
  YYSYMBOL_64_ = 64,                       /* '}'  */
  YYSYMBOL_65_ = 65,                       /* '['  */
  YYSYMBOL_66_ = 66,                       /* "]}"  */
  YYSYMBOL_67_ = 67,                       /* '$'  */
  YYSYMBOL_68_ = 68,                       /* "$*"  */
  YYSYMBOL_69_ = 69,                       /* "$?"  */
  YYSYMBOL_70_ = 70,                       /* "$("  */
  YYSYMBOL_71_expr_ = 71,                  /* "expr"  */
  YYSYMBOL_72_n_ = 72,                     /* "-n"  */
  YYSYMBOL_73_z_ = 73,                     /* "-z"  */
  YYSYMBOL_74_eq_ = 74,                    /* "-eq"  */
  YYSYMBOL_75_ne_ = 75,                    /* "-ne"  */
  YYSYMBOL_76_gt_ = 76,                    /* "-gt"  */
  YYSYMBOL_77_ge_ = 77,                    /* "-ge"  */
  YYSYMBOL_78_lt_ = 78,                    /* "-lt"  */
  YYSYMBOL_79_le_ = 79,                    /* "-le"  */
  YYSYMBOL_80_ = 80,                       /* '%'  */
  YYSYMBOL_81_ = 81,                       /* "() {"  */
  YYSYMBOL_82_local_ = 82,                 /* "local"  */
  YYSYMBOL_YYACCEPT = 83,                  /* $accept  */
  YYSYMBOL_programme = 84,                 /* programme  */
  YYSYMBOL_liste_instructions = 85,        /* liste_instructions  */
  YYSYMBOL_instruction = 86,               /* instruction  */
  YYSYMBOL_else_part = 87,                 /* else_part  */
  YYSYMBOL_liste_cas = 88,                 /* liste_cas  */
  YYSYMBOL_filtre = 89,                    /* filtre  */
  YYSYMBOL_liste_operandes = 90,           /* liste_operandes  */
  YYSYMBOL_concatenation = 91,             /* concatenation  */
  YYSYMBOL_test_bloc = 92,                 /* test_bloc  */
  YYSYMBOL_test_expr = 93,                 /* test_expr  */
  YYSYMBOL_test_expr2 = 94,                /* test_expr2  */
  YYSYMBOL_test_expr3 = 95,                /* test_expr3  */
  YYSYMBOL_test_instruction = 96,          /* test_instruction  */
  YYSYMBOL_operande = 97,                  /* operande  */
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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   248

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   323


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
       2,     2,     2,    62,     2,     2,    67,    80,     2,     2,
      61,    53,    30,    28,     2,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
       2,    34,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    55,    64,     2,     2,     2,     2,
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
      25,    26,    27,    32,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    54,    56,    57,    58,    59,    60,    63,    66,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    81,    82
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
  "UMOINS", "';'", "'='", "\"declare\"", "\"if\"", "\"then\"", "\"fi\"",
  "\"for\"", "\"do\"", "\"done\"", "\"in\"", "\"while\"", "\"until\"",
  "\"case\"", "\"esac\"", "\"echo\"", "\"read\"", "\"return\"", "\"exit\"",
  "\"elif\"", "\"else\"", "')'", "\";;\"", "'|'", "\"${\"", "\"[*]}\"",
  "\"test\"", "\"-o\"", "\"-a\"", "'('", "'!'", "\"!=\"", "'}'", "'['",
  "\"]}\"", "'$'", "\"$*\"", "\"$?\"", "\"$(\"", "\"expr\"", "\"-n\"",
  "\"-z\"", "\"-eq\"", "\"-ne\"", "\"-gt\"", "\"-ge\"", "\"-lt\"",
  "\"-le\"", "'%'", "\"() {\"", "\"local\"", "$accept", "programme",
  "liste_instructions", "instruction", "else_part", "liste_cas", "filtre",
  "liste_operandes", "concatenation", "test_bloc", "test_expr",
  "test_expr2", "test_expr3", "test_instruction", "operande", "operateur1",
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

#define YYPACT_NINF (-64)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     180,    92,    12,   -45,    20,   -45,   -45,   138,   144,    25,
      47,    47,    23,     7,   -64,   -64,   -64,   -64,   -64,   138,
      44,    60,   -64,   -64,   -14,   -64,   138,   -64,   -64,    16,
      34,    85,    54,    99,   108,   114,   138,   -64,   -64,   -64,
     -64,   141,    47,   145,   -64,   -22,   -64,   -64,   180,   138,
     -64,    36,   -64,   144,    47,   136,    15,   -64,    16,   110,
     -64,   -64,   118,   131,   133,   -64,   -64,   163,   138,   180,
     180,   144,   180,   180,    73,   121,    93,    -7,   -11,   -64,
     -64,   -64,   177,   175,   -64,   -64,   -64,   -64,    47,    27,
     -64,   179,   -21,   -29,    16,   -64,   138,   138,    16,    16,
     -64,   -64,   -64,   -64,   -64,   -64,   138,   138,    40,    57,
     128,    71,    82,   -64,   -64,   -64,    94,    58,   -64,    47,
     -64,    47,   -64,   -64,   -64,    47,   111,   -64,   143,   -64,
     176,   -64,   -64,   -26,   138,   138,   133,   -64,   -64,   -45,
     180,   182,   -64,   180,   -64,   -64,   -64,    76,   180,   124,
     151,   -11,   -64,   -64,    47,   -64,   138,   -64,   181,     7,
     -64,    89,   180,   -17,   -64,   -64,   -64,   155,   166,   180,
     -64,   -16,   -64,   -64,   -64,    40,   -64,   -64
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    90,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    21,     0,     2,     4,    17,    18,    53,    57,     0,
       0,     0,    55,    56,     0,    88,    89,    34,     7,     0,
       0,     0,     0,     0,     0,     0,    14,    15,    78,    81,
      82,     0,     0,     0,    20,     0,    22,     1,     0,     5,
      37,     0,    54,    90,     0,     0,     0,    33,     0,     0,
      60,    61,     0,    38,    40,    42,    45,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    69,    71,
      74,    79,     0,     0,     3,    36,    35,    51,     0,     0,
      59,     0,     0,     0,     0,    46,     0,     0,     0,     0,
      62,    63,    64,    65,    66,    67,     0,    49,    25,     0,
       0,     0,     0,    28,    29,    32,     0,     0,    72,     0,
      80,     0,    83,    84,    85,     0,     0,    77,     0,    58,
       0,    86,    43,     0,    47,    48,    39,    41,    50,     0,
       0,     0,     9,     0,    11,    12,    13,     0,     0,     0,
       0,    68,    70,    75,     0,    52,     0,    44,     0,    24,
       8,     0,     0,     0,    30,    31,    73,     0,     0,     0,
      10,     0,    27,    76,    87,    25,    26,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -64,   -64,   -41,   178,    56,   -64,   116,    -5,   -15,     3,
     -47,   146,   147,   184,    -1,   -64,   -64,   191,   126,    -9,
     -63,   -64,   -64,   -64,   224
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    12,    13,    14,   141,   116,   117,    26,    62,    30,
      63,    64,    65,    66,    67,    68,   106,    77,    78,    79,
      45,   125,    15,    56,    16
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      27,    44,    46,    36,    49,    81,    35,    27,    32,    33,
      53,    93,    48,    29,   121,    92,    48,    48,    50,   122,
     123,    39,    40,    47,   132,    57,   121,   157,   108,   109,
      98,   111,   112,    98,    82,    57,    28,   172,   176,     1,
      48,    17,    18,   131,    31,    83,   120,   133,    85,    37,
       2,     3,    27,   107,     4,    39,    40,    54,     5,     6,
       7,    85,     8,     9,    10,    11,   110,    50,    51,   124,
      27,    69,    34,    48,    38,    39,    40,    58,    59,   128,
     129,   134,   135,    21,    22,    23,    24,    52,    60,    61,
      48,   139,   140,    86,    72,    50,    50,    91,   142,   159,
      87,    88,   161,    41,    48,   138,    85,   163,    42,    57,
     150,   148,   144,   149,    43,    48,   152,    17,    18,   113,
     114,   171,    48,   145,   115,    70,    19,    71,   175,   162,
     170,   149,    74,    85,    85,    17,    18,    87,    88,    73,
     146,   168,   158,    17,    18,   167,   113,   114,    20,   164,
     165,   115,    96,    17,    18,    50,    75,   118,   119,    21,
      22,    23,    24,    17,    18,    76,    34,    85,   143,    17,
      18,    94,    80,    25,    34,   153,   154,    21,    22,    23,
      24,    97,    60,    61,    34,    21,    22,    23,    24,    90,
      98,    17,    18,    99,    34,    21,    22,    23,    24,   174,
      20,   126,   127,   130,     1,    21,    22,    23,    24,   155,
     156,    21,    22,    23,    24,     2,     3,   166,   169,     4,
     160,   173,    34,     5,     6,     7,    84,     8,     9,    10,
      11,   177,   147,    21,    22,    23,    24,   100,   101,   102,
     103,   104,   105,    95,   136,    89,   137,   151,    55
};

static const yytype_uint8 yycheck[] =
{
       1,    10,    11,     8,    19,    27,     7,     8,     5,     6,
      24,    58,    33,    58,    77,    56,    33,    33,    19,    30,
      31,    28,    29,     0,    53,    26,    89,    53,    69,    70,
      59,    72,    73,    59,    56,    36,    24,    54,    54,    24,
      33,    25,    26,    64,    24,    67,    53,    94,    49,    24,
      35,    36,    53,    68,    39,    28,    29,    71,    43,    44,
      45,    62,    47,    48,    49,    50,    71,    68,    24,    80,
      71,    37,    56,    33,    27,    28,    29,    61,    62,    88,
      53,    96,    97,    67,    68,    69,    70,    27,    72,    73,
      33,    51,    52,    57,    40,    96,    97,    82,    41,   140,
      64,    65,   143,    56,    33,   106,   107,   148,    61,   110,
     119,    53,    41,    55,    67,    33,   125,    25,    26,    25,
      26,   162,    33,    41,    30,    40,    34,    42,   169,    53,
      41,    55,    24,   134,   135,    25,    26,    64,    65,    40,
      46,   156,   139,    25,    26,   154,    25,    26,    56,    25,
      26,    30,    34,    25,    26,   156,    42,    64,    65,    67,
      68,    69,    70,    25,    26,    24,    56,   168,    40,    25,
      26,    61,    27,    81,    56,    64,    65,    67,    68,    69,
      70,    63,    72,    73,    56,    67,    68,    69,    70,    53,
      59,    25,    26,    60,    56,    67,    68,    69,    70,    33,
      56,    24,    27,    24,    24,    67,    68,    69,    70,    66,
      34,    67,    68,    69,    70,    35,    36,    66,    37,    39,
      38,    66,    56,    43,    44,    45,    48,    47,    48,    49,
      50,   175,   116,    67,    68,    69,    70,    74,    75,    76,
      77,    78,    79,    59,    98,    54,    99,   121,    24
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    24,    35,    36,    39,    43,    44,    45,    47,    48,
      49,    50,    84,    85,    86,   105,   107,    25,    26,    34,
      56,    67,    68,    69,    70,    81,    90,    97,    24,    58,
      92,    24,    92,    92,    56,    97,    90,    24,    27,    28,
      29,    56,    61,    67,   102,   103,   102,     0,    33,    91,
      97,    24,    27,    24,    71,   107,   106,    97,    61,    62,
      72,    73,    91,    93,    94,    95,    96,    97,    98,    37,
      40,    42,    40,    40,    24,    42,    24,   100,   101,   102,
      27,    27,    56,    67,    86,    97,    57,    64,    65,   100,
      53,    82,    85,    93,    61,    96,    34,    63,    59,    60,
      74,    75,    76,    77,    78,    79,    99,    91,    85,    85,
      90,    85,    85,    25,    26,    30,    88,    89,    64,    65,
      53,   103,    30,    31,    80,   104,    24,    27,   102,    53,
      24,    64,    53,    93,    91,    91,    94,    95,    97,    51,
      52,    87,    41,    40,    41,    41,    46,    89,    53,    55,
     102,   101,   102,    64,    65,    66,    34,    53,    92,    85,
      38,    85,    53,    85,    25,    26,    66,   102,    91,    37,
      41,    85,    54,    66,    33,    85,    54,    87
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    83,    84,    85,    85,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    87,    87,    88,    88,    89,    89,
      89,    89,    89,    90,    90,    90,    91,    91,    92,    93,
      93,    94,    94,    95,    95,    95,    95,    96,    96,    96,
      96,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      98,    98,    99,    99,    99,    99,    99,    99,   100,   100,
     101,   101,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   103,   103,   104,   104,   104,   105,   106,   106,   107,
     107
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     3,     3,     2,     6,     5,
       7,     5,     5,     5,     2,     2,     2,     1,     1,     1,
       2,     1,     2,     5,     2,     0,     5,     4,     1,     1,
       3,     3,     1,     2,     1,     3,     2,     1,     2,     3,
       1,     3,     1,     3,     4,     1,     2,     3,     3,     2,
       3,     3,     5,     1,     2,     1,     1,     1,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     5,     2,     4,     6,     3,     1,     2,
       3,     1,     1,     1,     1,     1,     5,     6,     0,     2,
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
#line 1312 "bsos.tab.c"
    break;

  case 3: /* liste_instructions: liste_instructions ';' instruction  */
#line 24 "src/bsos.y"
                                     {}
#line 1318 "bsos.tab.c"
    break;

  case 4: /* liste_instructions: instruction  */
#line 25 "src/bsos.y"
              {}
#line 1324 "bsos.tab.c"
    break;

  case 5: /* instruction: ID '=' concatenation  */
#line 29 "src/bsos.y"
                       {}
#line 1330 "bsos.tab.c"
    break;

  case 6: /* instruction: ID '=' concatenation  */
#line 30 "src/bsos.y"
                                        {}
#line 1336 "bsos.tab.c"
    break;

  case 7: /* instruction: "declare" ID  */
#line 31 "src/bsos.y"
                       {}
#line 1342 "bsos.tab.c"
    break;

  case 8: /* instruction: "if" test_bloc "then" liste_instructions else_part "fi"  */
#line 32 "src/bsos.y"
                                                          {}
#line 1348 "bsos.tab.c"
    break;

  case 9: /* instruction: "for" ID "do" liste_instructions "done"  */
#line 33 "src/bsos.y"
                                          {}
#line 1354 "bsos.tab.c"
    break;

  case 10: /* instruction: "for" ID "in" liste_operandes "do" liste_instructions "done"  */
#line 34 "src/bsos.y"
                                                               {}
#line 1360 "bsos.tab.c"
    break;

  case 11: /* instruction: "while" test_bloc "do" liste_instructions "done"  */
#line 35 "src/bsos.y"
                                                   {}
#line 1366 "bsos.tab.c"
    break;

  case 12: /* instruction: "until" test_bloc "do" liste_instructions "done"  */
#line 36 "src/bsos.y"
                                                   {}
#line 1372 "bsos.tab.c"
    break;

  case 13: /* instruction: "case" operande "in" liste_cas "esac"  */
#line 37 "src/bsos.y"
                                        {}
#line 1378 "bsos.tab.c"
    break;

  case 14: /* instruction: "echo" liste_operandes  */
#line 38 "src/bsos.y"
                         {}
#line 1384 "bsos.tab.c"
    break;

  case 15: /* instruction: "read" ID  */
#line 39 "src/bsos.y"
            {}
#line 1390 "bsos.tab.c"
    break;

  case 16: /* instruction: "read" ID  */
#line 40 "src/bsos.y"
                             {}
#line 1396 "bsos.tab.c"
    break;

  case 17: /* instruction: declaration_de_fonction  */
#line 41 "src/bsos.y"
                          {}
#line 1402 "bsos.tab.c"
    break;

  case 18: /* instruction: appel_de_fonction  */
#line 42 "src/bsos.y"
                    {}
#line 1408 "bsos.tab.c"
    break;

  case 19: /* instruction: "return"  */
#line 43 "src/bsos.y"
           {}
#line 1414 "bsos.tab.c"
    break;

  case 20: /* instruction: "return" operande_entier  */
#line 44 "src/bsos.y"
                           {}
#line 1420 "bsos.tab.c"
    break;

  case 21: /* instruction: "exit"  */
#line 45 "src/bsos.y"
         {}
#line 1426 "bsos.tab.c"
    break;

  case 22: /* instruction: "exit" operande_entier  */
#line 46 "src/bsos.y"
                         {}
#line 1432 "bsos.tab.c"
    break;

  case 23: /* else_part: "elif" test_bloc "then" liste_instructions else_part  */
#line 50 "src/bsos.y"
                                                       {}
#line 1438 "bsos.tab.c"
    break;

  case 24: /* else_part: "else" liste_instructions  */
#line 51 "src/bsos.y"
                            {}
#line 1444 "bsos.tab.c"
    break;

  case 25: /* else_part: %empty  */
#line 52 "src/bsos.y"
         {}
#line 1450 "bsos.tab.c"
    break;

  case 26: /* liste_cas: liste_cas filtre ')' liste_instructions ";;"  */
#line 56 "src/bsos.y"
                                               {}
#line 1456 "bsos.tab.c"
    break;

  case 27: /* liste_cas: filtre ')' liste_instructions ";;"  */
#line 57 "src/bsos.y"
                                     {}
#line 1462 "bsos.tab.c"
    break;

  case 28: /* filtre: MOT  */
#line 61 "src/bsos.y"
      {}
#line 1468 "bsos.tab.c"
    break;

  case 29: /* filtre: CHAINE  */
#line 62 "src/bsos.y"
         {}
#line 1474 "bsos.tab.c"
    break;

  case 30: /* filtre: filtre '|' MOT  */
#line 63 "src/bsos.y"
                 {}
#line 1480 "bsos.tab.c"
    break;

  case 31: /* filtre: filtre '|' CHAINE  */
#line 64 "src/bsos.y"
                    {}
#line 1486 "bsos.tab.c"
    break;

  case 33: /* liste_operandes: liste_operandes operande  */
#line 69 "src/bsos.y"
                           {}
#line 1492 "bsos.tab.c"
    break;

  case 34: /* liste_operandes: operande  */
#line 70 "src/bsos.y"
           {}
#line 1498 "bsos.tab.c"
    break;

  case 35: /* liste_operandes: "${" ID "[*]}"  */
#line 71 "src/bsos.y"
                 {}
#line 1504 "bsos.tab.c"
    break;

  case 36: /* concatenation: concatenation operande  */
#line 75 "src/bsos.y"
                         {}
#line 1510 "bsos.tab.c"
    break;

  case 37: /* concatenation: operande  */
#line 76 "src/bsos.y"
           {}
#line 1516 "bsos.tab.c"
    break;

  case 38: /* test_bloc: "test" test_expr  */
#line 80 "src/bsos.y"
                   {}
#line 1522 "bsos.tab.c"
    break;

  case 39: /* test_expr: test_expr "-o" test_expr2  */
#line 84 "src/bsos.y"
                            {}
#line 1528 "bsos.tab.c"
    break;

  case 40: /* test_expr: test_expr2  */
#line 85 "src/bsos.y"
             {}
#line 1534 "bsos.tab.c"
    break;

  case 41: /* test_expr2: test_expr2 "-a" test_expr3  */
#line 89 "src/bsos.y"
                             {}
#line 1540 "bsos.tab.c"
    break;

  case 42: /* test_expr2: test_expr3  */
#line 90 "src/bsos.y"
             {}
#line 1546 "bsos.tab.c"
    break;

  case 43: /* test_expr3: '(' test_expr ')'  */
#line 94 "src/bsos.y"
                    {}
#line 1552 "bsos.tab.c"
    break;

  case 44: /* test_expr3: '!' '(' test_expr ')'  */
#line 95 "src/bsos.y"
                        {}
#line 1558 "bsos.tab.c"
    break;

  case 45: /* test_expr3: test_instruction  */
#line 96 "src/bsos.y"
                   {}
#line 1564 "bsos.tab.c"
    break;

  case 46: /* test_expr3: '!' test_instruction  */
#line 97 "src/bsos.y"
                       {}
#line 1570 "bsos.tab.c"
    break;

  case 47: /* test_instruction: concatenation '=' concatenation  */
#line 101 "src/bsos.y"
                                  {}
#line 1576 "bsos.tab.c"
    break;

  case 48: /* test_instruction: concatenation "!=" concatenation  */
#line 102 "src/bsos.y"
                                   {}
#line 1582 "bsos.tab.c"
    break;

  case 49: /* test_instruction: operateur1 concatenation  */
#line 103 "src/bsos.y"
                           {}
#line 1588 "bsos.tab.c"
    break;

  case 50: /* test_instruction: operande operateur2 operande  */
#line 104 "src/bsos.y"
                               {}
#line 1594 "bsos.tab.c"
    break;

  case 51: /* operande: "${" ID '}'  */
#line 108 "src/bsos.y"
              {}
#line 1600 "bsos.tab.c"
    break;

  case 52: /* operande: "${" ID '[' operande_entier "]}"  */
#line 109 "src/bsos.y"
                                   {}
#line 1606 "bsos.tab.c"
    break;

  case 53: /* operande: MOT  */
#line 110 "src/bsos.y"
      {}
#line 1612 "bsos.tab.c"
    break;

  case 54: /* operande: '$' ENTIER  */
#line 111 "src/bsos.y"
             {}
#line 1618 "bsos.tab.c"
    break;

  case 55: /* operande: "$*"  */
#line 112 "src/bsos.y"
       {}
#line 1624 "bsos.tab.c"
    break;

  case 56: /* operande: "$?"  */
#line 113 "src/bsos.y"
       {}
#line 1630 "bsos.tab.c"
    break;

  case 57: /* operande: CHAINE  */
#line 114 "src/bsos.y"
         {}
#line 1636 "bsos.tab.c"
    break;

  case 58: /* operande: "$(" "expr" somme_entiere ')'  */
#line 115 "src/bsos.y"
                                {}
#line 1642 "bsos.tab.c"
    break;

  case 59: /* operande: "$(" appel_de_fonction ')'  */
#line 116 "src/bsos.y"
                             {}
#line 1648 "bsos.tab.c"
    break;

  case 60: /* operateur1: "-n"  */
#line 120 "src/bsos.y"
       {}
#line 1654 "bsos.tab.c"
    break;

  case 61: /* operateur1: "-z"  */
#line 121 "src/bsos.y"
       {}
#line 1660 "bsos.tab.c"
    break;

  case 62: /* operateur2: "-eq"  */
#line 125 "src/bsos.y"
        {}
#line 1666 "bsos.tab.c"
    break;

  case 63: /* operateur2: "-ne"  */
#line 126 "src/bsos.y"
        {}
#line 1672 "bsos.tab.c"
    break;

  case 64: /* operateur2: "-gt"  */
#line 127 "src/bsos.y"
        {}
#line 1678 "bsos.tab.c"
    break;

  case 65: /* operateur2: "-ge"  */
#line 128 "src/bsos.y"
        {}
#line 1684 "bsos.tab.c"
    break;

  case 66: /* operateur2: "-lt"  */
#line 129 "src/bsos.y"
        {}
#line 1690 "bsos.tab.c"
    break;

  case 67: /* operateur2: "-le"  */
#line 130 "src/bsos.y"
        {}
#line 1696 "bsos.tab.c"
    break;

  case 68: /* somme_entiere: somme_entiere plus_ou_moins produit_entier  */
#line 134 "src/bsos.y"
                                             {}
#line 1702 "bsos.tab.c"
    break;

  case 69: /* somme_entiere: produit_entier  */
#line 135 "src/bsos.y"
                 {}
#line 1708 "bsos.tab.c"
    break;

  case 70: /* produit_entier: produit_entier fois_div_mod operande_entier  */
#line 139 "src/bsos.y"
                                              {}
#line 1714 "bsos.tab.c"
    break;

  case 71: /* produit_entier: operande_entier  */
#line 140 "src/bsos.y"
                  {}
#line 1720 "bsos.tab.c"
    break;

  case 72: /* operande_entier: "${" ID '}'  */
#line 144 "src/bsos.y"
              {}
#line 1726 "bsos.tab.c"
    break;

  case 73: /* operande_entier: "${" ID '[' operande_entier "]}"  */
#line 145 "src/bsos.y"
                                   {}
#line 1732 "bsos.tab.c"
    break;

  case 74: /* operande_entier: '$' ENTIER  */
#line 146 "src/bsos.y"
             {}
#line 1738 "bsos.tab.c"
    break;

  case 75: /* operande_entier: plus_ou_moins "${" ID '}'  */
#line 147 "src/bsos.y"
                            {}
#line 1744 "bsos.tab.c"
    break;

  case 76: /* operande_entier: plus_ou_moins "${" ID '[' operande_entier "]}"  */
#line 148 "src/bsos.y"
                                                 {}
#line 1750 "bsos.tab.c"
    break;

  case 77: /* operande_entier: plus_ou_moins '$' ENTIER  */
#line 149 "src/bsos.y"
                           {}
#line 1756 "bsos.tab.c"
    break;

  case 78: /* operande_entier: ENTIER  */
#line 150 "src/bsos.y"
         {}
#line 1762 "bsos.tab.c"
    break;

  case 79: /* operande_entier: plus_ou_moins ENTIER  */
#line 151 "src/bsos.y"
                       {}
#line 1768 "bsos.tab.c"
    break;

  case 80: /* operande_entier: '(' somme_entiere ')'  */
#line 152 "src/bsos.y"
                        {}
#line 1774 "bsos.tab.c"
    break;

  case 81: /* plus_ou_moins: '+'  */
#line 156 "src/bsos.y"
      {}
#line 1780 "bsos.tab.c"
    break;

  case 82: /* plus_ou_moins: '-'  */
#line 157 "src/bsos.y"
      {}
#line 1786 "bsos.tab.c"
    break;

  case 83: /* fois_div_mod: '*'  */
#line 161 "src/bsos.y"
      {}
#line 1792 "bsos.tab.c"
    break;

  case 84: /* fois_div_mod: '/'  */
#line 162 "src/bsos.y"
      {}
#line 1798 "bsos.tab.c"
    break;

  case 85: /* fois_div_mod: '%'  */
#line 163 "src/bsos.y"
      {}
#line 1804 "bsos.tab.c"
    break;

  case 86: /* declaration_de_fonction: ID "() {" decl_loc liste_instructions '}'  */
#line 167 "src/bsos.y"
                                            {}
#line 1810 "bsos.tab.c"
    break;

  case 87: /* decl_loc: decl_loc "local" ID '=' concatenation ';'  */
#line 172 "src/bsos.y"
                                            {}
#line 1816 "bsos.tab.c"
    break;

  case 88: /* decl_loc: %empty  */
#line 173 "src/bsos.y"
         {}
#line 1822 "bsos.tab.c"
    break;

  case 89: /* appel_de_fonction: ID liste_operandes  */
#line 177 "src/bsos.y"
                     {}
#line 1828 "bsos.tab.c"
    break;

  case 90: /* appel_de_fonction: ID  */
#line 178 "src/bsos.y"
     {}
#line 1834 "bsos.tab.c"
    break;


#line 1838 "bsos.tab.c"

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
