/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Skeleton implementation for Bison GLR parsers in C

   Copyright (C) 2002-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0






/* First part of user declarations.  */



/*

This file must be translated to C and modified to build everywhere.

Run bison like this:

  bison --no-lines -b vtkParse vtkParse.y

Modify vtkParse.tab.c:
  - convert TABs to spaces (eight per tab)
  - replace all instances of "static inline" with "static"
  - replace "#if ! defined lint || defined __GNUC__" with "#if 1"
  - remove YY_ATTRIBUTE_UNUSED from yyfillin, yyfill, and yynormal
  - remove the "break;" after return "return yyreportAmbiguity"
  - replace "(1-yyrhslen)" with "(1-(int)yyrhslen)"
*/

/*
The purpose of this parser is to read C++ header files in order to
generate data structures that describe the C++ interface of a library,
one header file at a time.  As such, it is not a complete C++ parser.
It only parses what is relevant to the interface and skips the rest.

While the parser reads method definitions, type definitions, and
template definitions it generates a "signature" which is a string
that matches (apart from whitespace) the text that was parsed.

While parsing types, the parser creates an unsigned int that describes
the type as well as creating other data structures for arrays, function
pointers, etc.  The parser also creates a typeId string, which is either
a simple id that gives the class name or type name, or is "function" for
function pointer types, or "method" for method pointer types.
*/

/*
Conformance Notes:

This parser was designed empirically and incrementally.  It has been
refactored to make it more similar to the C++ 1998 grammar, but there
are still many very significant differences.

The most significant difference between this parser and a "standard"
parser is that it only parses declarations in detail.  All other
statements and expressions are parsed as arbitrary sequences of symbols,
without any syntactic analysis.

The "unqualified_id" does not directly include "operator_function_id" or
"conversion_function_id" (e.g. ids like "operator=" or "operator int*").
Instead, these two id types are used to allow operator functions to be
handled by their own rules, rather than by the generic function rules.
These ids can only be used in function declarations and using declarations.

Types are handled quite differently from the C++ BNF.  These differences
represent a prolonged (and ultimately successful) attempt to empirically
create a yacc parser without any shift/reduce conflicts.  The rules for
types are organized according to the way that types are usually defined
in working code, rather than strictly according to C++ grammar.

The declaration specifier "typedef" can only appear at the beginning
of a declaration sequence.  There are also restrictions on where class
and enum specifiers can be used: you can declare a new struct within a
variable declaration, but not within a parameter declaration.

The lexer returns each of "(scope::*", "(*", "(a::b::*", etc. as single
tokens.  The C++ BNF, in contrast, would consider these to be a "("
followed by a "ptr_operator".  The lexer concatenates these tokens in
order to eliminate shift/reduce conflicts in the parser.  However, this
means that this parser will only recognize "scope::*" as valid if it is
preceded by "(", e.g. as part of a member function pointer specification.

An odd bit of C++ ambiguity is that y(x); can be interpreted variously
as declaration of variable "x" of type "y", as a function call if "y"
is the name of a function, or as a constructor if "y" is the name of
a class.  This parser always interprets this pattern as a constructor
declaration, because function calls are ignored by the parser, and
variable declarations of the form y(x); are exceedingly rare compared
to the more usual form y x; without parentheses.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define yyerror(a) print_parser_error(a, NULL, 0)
#define yywrap() 1

/* Make sure yacc-generated code knows we have included stdlib.h.  */
#ifndef _STDLIB_H
# define _STDLIB_H
#endif
#define YYINCLUDED_STDLIB_H

/* Borland and MSVC do not define __STDC__ properly. */
#if !defined(__STDC__)
# if defined(_MSC_VER) || defined(__BORLANDC__)
#  define __STDC__ 1
# endif
#endif

/* Disable warnings in generated code. */
#if defined(_MSC_VER)
# pragma warning (disable: 4127) /* conditional expression is constant */
# pragma warning (disable: 4244) /* conversion to smaller integer type */
#endif
#if defined(__BORLANDC__)
# pragma warn -8004 /* assigned a value that is never used */
# pragma warn -8008 /* conditional is always true */
# pragma warn -8066 /* unreachable code */
#endif

/* Map from the type anonymous_enumeration in vtkType.h to the
   VTK wrapping type system number for the type. */

#include "vtkParse.h"
#include "vtkParsePreprocess.h"
#include "vtkParseData.h"
#include "vtkType.h"

static unsigned int vtkParseTypeMap[] =
  {
  VTK_PARSE_VOID,               /* VTK_VOID                0 */
  0,                            /* VTK_BIT                 1 */
  VTK_PARSE_CHAR,               /* VTK_CHAR                2 */
  VTK_PARSE_UNSIGNED_CHAR,      /* VTK_UNSIGNED_CHAR       3 */
  VTK_PARSE_SHORT,              /* VTK_SHORT               4 */
  VTK_PARSE_UNSIGNED_SHORT,     /* VTK_UNSIGNED_SHORT      5 */
  VTK_PARSE_INT,                /* VTK_INT                 6 */
  VTK_PARSE_UNSIGNED_INT,       /* VTK_UNSIGNED_INT        7 */
  VTK_PARSE_LONG,               /* VTK_LONG                8 */
  VTK_PARSE_UNSIGNED_LONG,      /* VTK_UNSIGNED_LONG       9 */
  VTK_PARSE_FLOAT,              /* VTK_FLOAT              10 */
  VTK_PARSE_DOUBLE,             /* VTK_DOUBLE             11 */
  VTK_PARSE_ID_TYPE,            /* VTK_ID_TYPE            12 */
  VTK_PARSE_STRING,             /* VTK_STRING             13 */
  0,                            /* VTK_OPAQUE             14 */
  VTK_PARSE_SIGNED_CHAR,        /* VTK_SIGNED_CHAR        15 */
  VTK_PARSE_LONG_LONG,          /* VTK_LONG_LONG          16 */
  VTK_PARSE_UNSIGNED_LONG_LONG, /* VTK_UNSIGNED_LONG_LONG 17 */
  VTK_PARSE___INT64,            /* VTK___INT64            18 */
  VTK_PARSE_UNSIGNED___INT64,   /* VTK_UNSIGNED___INT64   19 */
  0,                            /* VTK_VARIANT            20 */
  0,                            /* VTK_OBJECT             21 */
  VTK_PARSE_UNICODE_STRING      /* VTK_UNICODE_STRING     22 */
  };

/* Define some constants to simplify references to the table lookup in
   the primitive_type production rule code.  */
#define VTK_PARSE_INT8 vtkParseTypeMap[VTK_TYPE_INT8]
#define VTK_PARSE_UINT8 vtkParseTypeMap[VTK_TYPE_UINT8]
#define VTK_PARSE_INT16 vtkParseTypeMap[VTK_TYPE_INT16]
#define VTK_PARSE_UINT16 vtkParseTypeMap[VTK_TYPE_UINT16]
#define VTK_PARSE_INT32 vtkParseTypeMap[VTK_TYPE_INT32]
#define VTK_PARSE_UINT32 vtkParseTypeMap[VTK_TYPE_UINT32]
#define VTK_PARSE_INT64 vtkParseTypeMap[VTK_TYPE_INT64]
#define VTK_PARSE_UINT64 vtkParseTypeMap[VTK_TYPE_UINT64]
#define VTK_PARSE_FLOAT32 vtkParseTypeMap[VTK_TYPE_FLOAT32]
#define VTK_PARSE_FLOAT64 vtkParseTypeMap[VTK_TYPE_FLOAT64]

#define vtkParseDebug(s1, s2) \
  if ( parseDebug ) { fprintf(stderr, "   %s %s\n", s1, s2); }

/* the tokenizer */
int yylex(void);

/* global variables */
FileInfo      *data = NULL;
int            parseDebug;

/* the "preprocessor" */
PreprocessInfo *preprocessor = NULL;

/* include dirs specified on the command line */
int            NumberOfIncludeDirectories= 0;
const char   **IncludeDirectories;

/* macros specified on the command line */
int            NumberOfDefinitions = 0;
const char   **Definitions;

/* options that can be set by the programs that use the parser */
int            IgnoreBTX = 0;
int            Recursive = 0;
const char    *CommandName = NULL;

/* various state variables */
NamespaceInfo *currentNamespace = NULL;
ClassInfo     *currentClass = NULL;
FunctionInfo  *currentFunction = NULL;
TemplateInfo  *currentTemplate = NULL;
const char    *currentEnumName = NULL;
const char    *currentEnumValue = NULL;
unsigned int   currentEnumType = 0;
parse_access_t access_level = VTK_ACCESS_PUBLIC;

/* functions from vtkParse.l */
void print_parser_error(const char *text, const char *cp, size_t n);

/* helper functions */
const char *type_class(unsigned int type, const char *classname);
void start_class(const char *classname, int is_struct_or_union);
void end_class();
void add_base_class(ClassInfo *cls, const char *name, int access_lev,
                    unsigned int extra);
void output_friend_function(void);
void output_function(void);
void reject_function(void);
void set_return(FunctionInfo *func, unsigned int type,
                const char *typeclass, int count);
void add_parameter(FunctionInfo *func, unsigned int type,
                   const char *classname, int count);
void add_template_parameter(unsigned int datatype,
                            unsigned int extra, const char *funcSig);
void add_using(const char *name, int is_namespace);
void start_enum(const char *name, int is_scoped,
                unsigned int type, const char *basename);
void add_enum(const char *name, const char *value);
void end_enum();
unsigned int guess_constant_type(const char *value);
void add_constant(const char *name, const char *value,
                  unsigned int type, const char *typeclass, int global);
const char *add_const_scope(const char *name);
void prepend_scope(char *cp, const char *arg);
unsigned int guess_id_type(const char *cp);
unsigned int add_indirection(unsigned int tval, unsigned int ptr);
unsigned int add_indirection_to_array(unsigned int ptr);
void handle_complex_type(ValueInfo *val, unsigned int datatype,
                         unsigned int extra, const char *funcSig);
void handle_function_type(ValueInfo *param, const char *name,
                          const char *funcSig);
void add_legacy_parameter(FunctionInfo *func, ValueInfo *param);

void outputSetVectorMacro(const char *var, unsigned int paramType,
                          const char *typeText, int n);
void outputGetVectorMacro(const char *var, unsigned int paramType,
                          const char *typeText, int n);


/*----------------------------------------------------------------
 * String utility methods
 *
 * Strings are centrally allocated and are const, and they are not
 * freed until the program exits.  If they need to be freed before
 * then, vtkParse_FreeStringCache() can be called.
 */

/* duplicate the first n bytes of a string and terminate */
static const char *vtkstrndup(const char *in, size_t n)
{
  return vtkParse_CacheString(data->Strings, in, n);
}

/* duplicate a string */
static const char *vtkstrdup(const char *in)
{
  if (in)
    {
    in = vtkParse_CacheString(data->Strings, in, strlen(in));
    }

  return in;
}

/* helper function for concatenating strings */
static const char *vtkstrncat(size_t n, const char **str)
{
  char *cp;
  size_t i;
  size_t j[8];
  size_t m = 0;

  for (i = 0; i < n; i++)
    {
    j[i] = 0;
    if (str[i])
      {
      j[i] = strlen(str[i]);
      m += j[i];
      }
    }
  cp = vtkParse_NewString(data->Strings, m);
  m = 0;
  for (i = 0; i < n; i++)
    {
    if (j[i])
      {
      strncpy(&cp[m], str[i], j[i]);
      m += j[i];
      }
    }
  cp[m] = '\0';

  return cp;
}

/* concatenate strings */
static const char *vtkstrcat(const char *str1, const char *str2)
{
  const char *cp[2];

  cp[0] = str1;
  cp[1] = str2;
  return vtkstrncat(2, cp);
}

static const char *vtkstrcat3(const char *str1, const char *str2,
                              const char *str3)
{
  const char *cp[3];

  cp[0] = str1;
  cp[1] = str2;
  cp[2] = str3;
  return vtkstrncat(3, cp);
}

static const char *vtkstrcat4(const char *str1, const char *str2,
                              const char *str3, const char *str4)
{
  const char *cp[4];

  cp[0] = str1;
  cp[1] = str2;
  cp[2] = str3;
  cp[3] = str4;
  return vtkstrncat(4, cp);
}

static const char *vtkstrcat5(const char *str1, const char *str2,
                              const char *str3, const char *str4,
                              const char *str5)
{
  const char *cp[5];

  cp[0] = str1;
  cp[1] = str2;
  cp[2] = str3;
  cp[3] = str4;
  cp[4] = str5;
  return vtkstrncat(5, cp);
}

static const char *vtkstrcat7(const char *str1, const char *str2,
                              const char *str3, const char *str4,
                              const char *str5, const char *str6,
                              const char *str7)
{
  const char *cp[7];

  cp[0] = str1;
  cp[1] = str2;
  cp[2] = str3;
  cp[3] = str4;
  cp[4] = str5;
  cp[5] = str6;
  cp[6] = str7;
  return vtkstrncat(7, cp);
}

/*----------------------------------------------------------------
 * Comments
 */

/* "private" variables */
char          *commentText = NULL;
size_t         commentLength = 0;
size_t         commentAllocatedLength = 0;
int            commentState = 0;

const char *getComment()
{
  if (commentState != 0)
    {
    return commentText;
    }
  return NULL;
}

void clearComment()
{
  commentLength = 0;
  if (commentText)
    {
    commentText[commentLength] = '\0';
    }
  commentState = 0;
}

void addCommentLine(const char *line, size_t n)
{
  if (commentState <= 0)
    {
    clearComment();
    return;
    }

  if (commentText == NULL)
    {
    commentAllocatedLength = n+80;
    commentText = (char *)malloc(commentAllocatedLength);
    commentLength = 0;
    commentText[0] = '\0';
    }
  else if (commentLength + n + 2 > commentAllocatedLength)
    {
    commentAllocatedLength = commentAllocatedLength + commentLength + n + 2;
    commentText = (char *)realloc(commentText, commentAllocatedLength);
    if (!commentText)
      {
      fprintf(stderr, "Wrapping: out of memory\n");
      exit(1);
      }
    }

  if (n > 0)
    {
    memcpy(&commentText[commentLength], line, n);
    }
  commentLength += n;
  commentText[commentLength++] = '\n';
  commentText[commentLength] = '\0';
}

void closeComment()
{
  switch (commentState)
    {
    case 1:
      /* Make comment persist until a new comment starts */
      commentState = -1;
      break;
    case 2:
      data->Description = vtkstrdup(getComment());
      clearComment();
      break;
    case 3:
      data->SeeAlso = vtkstrdup(getComment());
      clearComment();
      break;
    case 4:
      data->Caveats = vtkstrdup(getComment());
      clearComment();
      break;
    }
}

void closeOrClearComment()
{
  if (commentState < 0)
    {
    clearComment();
    }
  else
    {
    closeComment();
    }
}

void setCommentState(int state)
{
  switch (state)
    {
    case 0:
      closeComment();
      break;
    default:
      closeComment();
      clearComment();
      break;
    }

  commentState = state;
}


/*----------------------------------------------------------------
 * Macros
 */

/* "private" variables */
const char *macroName = NULL;
int macroUsed = 0;
int macroEnded = 0;

const char *getMacro()
{
  if (macroUsed == 0)
    {
    macroUsed = macroEnded;
    return macroName;
    }
  return NULL;
}


/*----------------------------------------------------------------
 * Namespaces
 *
 * operates on: currentNamespace
 */

/* "private" variables */
NamespaceInfo *namespaceStack[10];
int namespaceDepth = 0;

/* enter a namespace */
void pushNamespace(const char *name)
{
  int i;
  NamespaceInfo *oldNamespace = currentNamespace;

  for (i = 0; i < oldNamespace->NumberOfNamespaces; i++)
    {
    /* see if the namespace already exists */
    if (strcmp(name, oldNamespace->Namespaces[i]->Name) == 0)
      {
      currentNamespace = oldNamespace->Namespaces[i];
      }
    }

  /* create a new namespace */
  if (i == oldNamespace->NumberOfNamespaces)
    {
    currentNamespace = (NamespaceInfo *)malloc(sizeof(NamespaceInfo));
    vtkParse_InitNamespace(currentNamespace);
    currentNamespace->Name = name;
    vtkParse_AddNamespaceToNamespace(oldNamespace, currentNamespace);
    }

  namespaceStack[namespaceDepth++] = oldNamespace;
}

/* leave the namespace */
void popNamespace()
{
  currentNamespace = namespaceStack[--namespaceDepth];
}


/*----------------------------------------------------------------
 * Classes
 *
 * operates on: currentClass, access_level
 */

/* "private" variables */
ClassInfo *classStack[10];
parse_access_t classAccessStack[10];
int classDepth = 0;

/* start an internal class definition */
void pushClass()
{
  classAccessStack[classDepth] = access_level;
  classStack[classDepth++] = currentClass;
}

/* leave the internal class */
void popClass()
{
  currentClass = classStack[--classDepth];
  access_level = classAccessStack[classDepth];
}


/*----------------------------------------------------------------
 * Templates
 *
 * operates on: currentTemplate
 */

/* "private" variables */
TemplateInfo *templateStack[10];
int templateDepth = 0;

/* begin a template */
void startTemplate()
{
  currentTemplate = (TemplateInfo *)malloc(sizeof(TemplateInfo));
  vtkParse_InitTemplate(currentTemplate);
}

/* clear a template, if set */
void clearTemplate()
{
  if (currentTemplate)
    {
    free(currentTemplate);
    }
  currentTemplate = NULL;
}

/* push the template onto the stack, and start a new one */
void pushTemplate()
{
  templateStack[templateDepth++] = currentTemplate;
  startTemplate();
}

/* pop a template off the stack */
void popTemplate()
{
  currentTemplate = templateStack[--templateDepth];
}

/*----------------------------------------------------------------
 * Function signatures
 *
 * operates on: currentFunction
 */

/* "private" variables */
int sigClosed = 0;
size_t sigMark[10];
size_t sigLength = 0;
size_t sigAllocatedLength = 0;
int sigMarkDepth = 0;
char *signature = NULL;

/* start a new signature */
void startSig()
{
  signature = NULL;
  sigLength = 0;
  sigAllocatedLength = 0;
  sigClosed = 0;
  sigMarkDepth = 0;
  sigMark[0] = 0;
}

/* get the signature */
const char *getSig()
{
  return signature;
}

/* get the signature length */
size_t getSigLength()
{
  return sigLength;
}

/* reset the sig to the specified length */
void resetSig(size_t n)
{
  if (n < sigLength)
    {
    sigLength = n;
    }
}

/* reallocate Signature if n chars cannot be appended */
void checkSigSize(size_t n)
{
  const char *ccp;

  if (sigAllocatedLength == 0)
    {
    sigLength = 0;
    sigAllocatedLength = 80 + n;
    signature = vtkParse_NewString(data->Strings, sigAllocatedLength);
    signature[0] = '\0';
    }
  else if (sigLength + n > sigAllocatedLength)
    {
    sigAllocatedLength += sigLength + n;
    ccp = signature;
    signature = vtkParse_NewString(data->Strings, sigAllocatedLength);
    strncpy(signature, ccp, sigLength);
    signature[sigLength] = '\0';
    }
}

/* close the signature, i.e. allow no more additions to it */
void closeSig()
{
  sigClosed = 1;
}

/* re-open the signature */
void openSig()
{
  sigClosed = 0;
}

/* insert text at the beginning of the signature */
void preSig(const char *arg)
{
  if (!sigClosed)
    {
    size_t n = strlen(arg);
    checkSigSize(n);
    if (n > 0)
      {
      memmove(&signature[n], signature, sigLength);
      strncpy(signature, arg, n);
      sigLength += n;
      }
    signature[sigLength] = '\0';
    }
}

/* append text to the end of the signature */
void postSig(const char *arg)
{
  if (!sigClosed)
    {
    size_t n = strlen(arg);
    checkSigSize(n);
    if (n > 0)
      {
      strncpy(&signature[sigLength], arg, n);
      sigLength += n;
      }
    signature[sigLength] = '\0';
    }
}

/* set a mark in the signature for later operations */
void markSig()
{
  sigMark[sigMarkDepth] = 0;
  if (signature)
    {
    sigMark[sigMarkDepth] = sigLength;
    }
  sigMarkDepth++;
}

/* get the contents of the sig from the mark, and clear the mark */
const char *copySig()
{
  const char *cp = NULL;
  if (sigMarkDepth > 0)
    {
    sigMarkDepth--;
    }
  if (signature)
    {
    cp = &signature[sigMark[sigMarkDepth]];
    }
  return vtkstrdup(cp);
}

/* swap the signature text using the mark as the radix */
void swapSig()
{
  if (sigMarkDepth > 0)
    {
    sigMarkDepth--;
    }
  if (signature && sigMark[sigMarkDepth] > 0)
    {
    size_t i, m, n, nn;
    char c;
    char *cp;
    cp = signature;
    n = sigLength;
    m = sigMark[sigMarkDepth];
    nn = m/2;
    for (i = 0; i < nn; i++)
      {
      c = cp[i]; cp[i] = cp[m-i-1]; cp[m-i-1] = c;
      }
    nn = (n-m)/2;
    for (i = 0; i < nn; i++)
      {
      c = cp[i+m]; cp[i+m] = cp[n-i-1]; cp[n-i-1] = c;
      }
    nn = n/2;
    for (i = 0; i < nn; i++)
      {
      c = cp[i]; cp[i] = cp[n-i-1]; cp[n-i-1] = c;
      }
    }
}

/* chop the last space from the signature */
void chopSig(void)
{
  if (signature)
    {
    size_t n = sigLength;
    if (n > 0 && signature[n-1] == ' ')
      {
      signature[n-1] = '\0';
      sigLength--;
      }
    }
}

/*----------------------------------------------------------------
 * Subroutines for building a type
 */

/* "private" variables */
unsigned int storedType;
unsigned int typeStack[10];
int typeDepth = 0;

/* save the type on the stack */
void pushType()
{
  typeStack[typeDepth++] = storedType;
}

/* pop the type stack */
void popType()
{
  storedType = typeStack[--typeDepth];
}

/* clear the storage type */
void clearType()
{
  storedType = 0;
}

/* save the type */
void setTypeBase(unsigned int base)
{
  storedType &= ~(unsigned int)(VTK_PARSE_BASE_TYPE);
  storedType |= base;
}

/* set a type modifier bit */
void setTypeMod(unsigned int mod)
{
  storedType |= mod;
}

/* modify the indirection (pointers, refs) in the storage type */
void setTypePtr(unsigned int ind)
{
  storedType &= ~(unsigned int)(VTK_PARSE_INDIRECT | VTK_PARSE_RVALUE);
  ind &= (VTK_PARSE_INDIRECT | VTK_PARSE_RVALUE);
  storedType |= ind;
}

/* retrieve the storage type */
unsigned int getType()
{
  return storedType;
}

/* combine two primitive type parts, e.g. "long int" */
unsigned int buildTypeBase(unsigned int a, unsigned int b)
{
  unsigned int base = (a & VTK_PARSE_BASE_TYPE);
  unsigned int basemod = (b & VTK_PARSE_BASE_TYPE);

  switch (base)
    {
    case 0:
      base = basemod;
      break;
    case VTK_PARSE_UNSIGNED_INT:
      base = (basemod | VTK_PARSE_UNSIGNED);
      break;
    case VTK_PARSE_INT:
      base = basemod;
      if (base == VTK_PARSE_CHAR)
        {
        base = VTK_PARSE_SIGNED_CHAR;
        }
      break;
    case VTK_PARSE_CHAR:
      if (basemod == VTK_PARSE_INT)
        {
        base = VTK_PARSE_SIGNED_CHAR;
        }
      else if (basemod == VTK_PARSE_UNSIGNED_INT)
        {
        base = VTK_PARSE_UNSIGNED_CHAR;
        }
      break;
    case VTK_PARSE_SHORT:
      if (basemod == VTK_PARSE_UNSIGNED_INT)
        {
        base = VTK_PARSE_UNSIGNED_SHORT;
        }
      break;
    case VTK_PARSE_LONG:
      if (basemod == VTK_PARSE_UNSIGNED_INT)
        {
        base = VTK_PARSE_UNSIGNED_LONG;
        }
      else if (basemod == VTK_PARSE_LONG)
        {
        base = VTK_PARSE_LONG_LONG;
        }
      else if (basemod == VTK_PARSE_DOUBLE)
        {
        base = VTK_PARSE_LONG_DOUBLE;
        }
      break;
    case VTK_PARSE_UNSIGNED_LONG:
      if (basemod == VTK_PARSE_LONG)
        {
        base = VTK_PARSE_UNSIGNED_LONG_LONG;
        }
      break;
    case VTK_PARSE_LONG_LONG:
      if (basemod == VTK_PARSE_UNSIGNED_INT)
        {
        base = VTK_PARSE_UNSIGNED_LONG_LONG;
        }
      break;
    case VTK_PARSE___INT64:
      if (basemod == VTK_PARSE_UNSIGNED_INT)
        {
        base = VTK_PARSE_UNSIGNED___INT64;
        }
      break;
    case VTK_PARSE_DOUBLE:
      if (basemod == VTK_PARSE_LONG)
        {
        base = VTK_PARSE_LONG_DOUBLE;
        }
      break;
    }

  return ((a & ~(unsigned int)(VTK_PARSE_BASE_TYPE)) | base);
}


/*----------------------------------------------------------------
 * Array information
 */

/* "private" variables */
int numberOfDimensions = 0;
const char **arrayDimensions = NULL;

/* clear the array counter */
void clearArray(void)
{
  numberOfDimensions = 0;
  arrayDimensions = NULL;
}

/* add another dimension */
void pushArraySize(const char *size)
{
  vtkParse_AddStringToArray(&arrayDimensions, &numberOfDimensions,
                            size);
}

/* add another dimension to the front */
void pushArrayFront(const char *size)
{
  int i;

  vtkParse_AddStringToArray(&arrayDimensions, &numberOfDimensions, 0);

  for (i = numberOfDimensions-1; i > 0; i--)
    {
    arrayDimensions[i] = arrayDimensions[i-1];
    }

  arrayDimensions[0] = size;
}

/* get the number of dimensions */
int getArrayNDims()
{
  return numberOfDimensions;
}

/* get the whole array */
const char **getArray()
{
  if (numberOfDimensions > 0)
    {
    return arrayDimensions;
    }
  return NULL;
}

/*----------------------------------------------------------------
 * Variables and Parameters
 */

/* "private" variables */
const char *currentVarName = 0;
const char *currentVarValue = 0;
const char *currentId = 0;

/* clear the var Id */
void clearVarName(void)
{
  currentVarName = NULL;
}

/* set the var Id */
void setVarName(const char *text)
{
  currentVarName = text;
}

/* return the var id */
const char *getVarName()
{
  return currentVarName;
}

/* variable value -------------- */

/* clear the var value */
void clearVarValue(void)
{
  currentVarValue = NULL;
}

/* set the var value */
void setVarValue(const char *text)
{
  currentVarValue = text;
}

/* return the var value */
const char *getVarValue()
{
  return currentVarValue;
}

/* variable type -------------- */

/* clear the current Id */
void clearTypeId(void)
{
  currentId = NULL;
}

/* set the current Id, it is sticky until cleared */
void setTypeId(const char *text)
{
  if (currentId == NULL)
    {
    currentId = text;
    }
}

/* set the signature and type together */
void typeSig(const char *text)
{
  postSig(text);
  postSig(" ");

  if (currentId == 0)
    {
    setTypeId(text);
    }
}

/* return the current Id */
const char *getTypeId()
{
  return currentId;
}

/*----------------------------------------------------------------
 * Specifically for function pointers, the scope (i.e. class) that
 * the function is a method of.
 */

const char *pointerScopeStack[10];
int pointerScopeDepth = 0;

/* save the scope for scoped method pointers */
void scopeSig(const char *scope)
{
  if (scope && scope[0] != '\0')
    {
    postSig(scope);
    }
  else
    {
    scope = NULL;
    }
  pointerScopeStack[pointerScopeDepth++] = vtkstrdup(scope);
}

/* get the scope back */
const char *getScope()
{
  return pointerScopeStack[--pointerScopeDepth];
}

/*----------------------------------------------------------------
 * Function stack
 *
 * operates on: currentFunction
 */

/* "private" variables */
FunctionInfo *functionStack[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const char *functionVarNameStack[10];
const char *functionTypeIdStack[10];
int functionDepth = 0;

void pushFunction()
{
  functionStack[functionDepth] = currentFunction;
  currentFunction = (FunctionInfo *)malloc(sizeof(FunctionInfo));
  vtkParse_InitFunction(currentFunction);
  if (!functionStack[functionDepth])
    {
    startSig();
    }
  functionVarNameStack[functionDepth] = getVarName();
  functionTypeIdStack[functionDepth] = getTypeId();
  pushType();
  clearType();
  clearVarName();
  clearTypeId();
  functionDepth++;
  functionStack[functionDepth] = 0;
}

void popFunction()
{
  FunctionInfo *newFunction = currentFunction;

  --functionDepth;
  currentFunction = functionStack[functionDepth];
  clearVarName();
  if (functionVarNameStack[functionDepth])
    {
    setVarName(functionVarNameStack[functionDepth]);
    }
  clearTypeId();
  if (functionTypeIdStack[functionDepth])
    {
    setTypeId(functionTypeIdStack[functionDepth]);
    }
  popType();

  functionStack[functionDepth+1] = newFunction;
}

FunctionInfo *getFunction()
{
  return functionStack[functionDepth+1];
}

/*----------------------------------------------------------------
 * Utility methods
 */

/* prepend a scope:: to a name */
void prepend_scope(char *cp, const char *arg)
{
  size_t i, j, m, n;
  int depth;

  m = strlen(cp);
  n = strlen(arg);
  i = m;
  while (i > 0 &&
         (vtkParse_CharType(cp[i-1], CPRE_IDGIT) ||
          cp[i-1] == ':' || cp[i-1] == '>'))
    {
    i--;
    if (cp[i] == '>')
      {
      depth = 1;
      while (i > 0)
        {
        i--;
        if (cp[i] == '<')
          {
          if (--depth == 0)
            {
            break;
            }
          }
        if (cp[i] == '>')
          {
          depth++;
          }
        }
      }
    }

  for (j = m; j > i; j--)
    {
    cp[j+n+1] = cp[j-1];
    }
  for (j = 0; j < n; j++)
    {
    cp[j+i] = arg[j];
    }
  cp[n+i] = ':'; cp[n+i+1] = ':';
  cp[m+n+2] = '\0';
}

/* expand a type by including pointers from another */
unsigned int add_indirection(unsigned int type1, unsigned int type2)
{
  unsigned int ptr1 = (type1 & VTK_PARSE_POINTER_MASK);
  unsigned int ptr2 = (type2 & VTK_PARSE_POINTER_MASK);
  unsigned int reverse = 0;
  unsigned int result;

  /* one of type1 or type2 will only have VTK_PARSE_INDIRECT, but
   * we don't know which one. */
  result = ((type1 & ~VTK_PARSE_POINTER_MASK) |
            (type2 & ~VTK_PARSE_POINTER_MASK));

  /* if there are two ampersands, it is an rvalue reference */
  if ((type1 & type2 & VTK_PARSE_REF) != 0)
    {
    result |= VTK_PARSE_RVALUE;
    }

  while (ptr2)
    {
    reverse = ((reverse << 2) | (ptr2 & VTK_PARSE_POINTER_LOWMASK));
    ptr2 = ((ptr2 >> 2) & VTK_PARSE_POINTER_MASK);
    }

  while (reverse)
    {
    ptr1 = ((ptr1 << 2) | (reverse & VTK_PARSE_POINTER_LOWMASK));
    reverse = ((reverse >> 2) & VTK_PARSE_POINTER_MASK);

    /* make sure we don't exceed the VTK_PARSE_POINTER bitfield */
    if ((ptr1 & VTK_PARSE_POINTER_MASK) != ptr1)
      {
      ptr1 = VTK_PARSE_BAD_INDIRECT;
      break;
      }
    }

  return (ptr1 | result);
}

/* There is only one array, so add any parenthetical indirection to it */
unsigned int add_indirection_to_array(unsigned int type)
{
  unsigned int ptrs = (type & VTK_PARSE_POINTER_MASK);
  unsigned int result = (type & ~VTK_PARSE_POINTER_MASK);
  unsigned int reverse = 0;

  if ((type & VTK_PARSE_INDIRECT) == VTK_PARSE_BAD_INDIRECT)
    {
    return (result | VTK_PARSE_BAD_INDIRECT);
    }

  while (ptrs)
    {
    reverse = ((reverse << 2) | (ptrs & VTK_PARSE_POINTER_LOWMASK));
    ptrs = ((ptrs >> 2) & VTK_PARSE_POINTER_MASK);
    }

  /* I know the reversal makes no difference, but it is still
   * nice to add the pointers in the correct order, just in
   * case const pointers are thrown into the mix. */
  while (reverse)
    {
    pushArrayFront("");
    reverse = ((reverse >> 2) & VTK_PARSE_POINTER_MASK);
    }

  return result;
}




# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    VTK_ID = 259,
    QT_ID = 260,
    StdString = 261,
    UnicodeString = 262,
    OSTREAM = 263,
    ISTREAM = 264,
    LP = 265,
    LA = 266,
    STRING_LITERAL = 267,
    INT_LITERAL = 268,
    HEX_LITERAL = 269,
    OCT_LITERAL = 270,
    FLOAT_LITERAL = 271,
    CHAR_LITERAL = 272,
    ZERO = 273,
    NULLPTR = 274,
    SSIZE_T = 275,
    SIZE_T = 276,
    NULLPTR_T = 277,
    BEGIN_ATTRIB = 278,
    STRUCT = 279,
    CLASS = 280,
    UNION = 281,
    ENUM = 282,
    PUBLIC = 283,
    PRIVATE = 284,
    PROTECTED = 285,
    CONST = 286,
    VOLATILE = 287,
    MUTABLE = 288,
    STATIC = 289,
    THREAD_LOCAL = 290,
    VIRTUAL = 291,
    EXPLICIT = 292,
    INLINE = 293,
    CONSTEXPR = 294,
    FRIEND = 295,
    EXTERN = 296,
    OPERATOR = 297,
    TEMPLATE = 298,
    THROW = 299,
    TRY = 300,
    CATCH = 301,
    NOEXCEPT = 302,
    DECLTYPE = 303,
    TYPENAME = 304,
    TYPEDEF = 305,
    NAMESPACE = 306,
    USING = 307,
    NEW = 308,
    DELETE = 309,
    DEFAULT = 310,
    STATIC_CAST = 311,
    DYNAMIC_CAST = 312,
    CONST_CAST = 313,
    REINTERPRET_CAST = 314,
    OP_LSHIFT_EQ = 315,
    OP_RSHIFT_EQ = 316,
    OP_LSHIFT = 317,
    OP_RSHIFT_A = 318,
    OP_DOT_POINTER = 319,
    OP_ARROW_POINTER = 320,
    OP_ARROW = 321,
    OP_INCR = 322,
    OP_DECR = 323,
    OP_PLUS_EQ = 324,
    OP_MINUS_EQ = 325,
    OP_TIMES_EQ = 326,
    OP_DIVIDE_EQ = 327,
    OP_REMAINDER_EQ = 328,
    OP_AND_EQ = 329,
    OP_OR_EQ = 330,
    OP_XOR_EQ = 331,
    OP_LOGIC_AND = 332,
    OP_LOGIC_OR = 333,
    OP_LOGIC_EQ = 334,
    OP_LOGIC_NEQ = 335,
    OP_LOGIC_LEQ = 336,
    OP_LOGIC_GEQ = 337,
    ELLIPSIS = 338,
    DOUBLE_COLON = 339,
    OTHER = 340,
    AUTO = 341,
    VOID = 342,
    BOOL = 343,
    FLOAT = 344,
    DOUBLE = 345,
    INT = 346,
    SHORT = 347,
    LONG = 348,
    INT64__ = 349,
    CHAR = 350,
    CHAR16_T = 351,
    CHAR32_T = 352,
    WCHAR_T = 353,
    SIGNED = 354,
    UNSIGNED = 355,
    IdType = 356,
    TypeInt8 = 357,
    TypeUInt8 = 358,
    TypeInt16 = 359,
    TypeUInt16 = 360,
    TypeInt32 = 361,
    TypeUInt32 = 362,
    TypeInt64 = 363,
    TypeUInt64 = 364,
    TypeFloat32 = 365,
    TypeFloat64 = 366,
    SetMacro = 367,
    GetMacro = 368,
    SetStringMacro = 369,
    GetStringMacro = 370,
    SetClampMacro = 371,
    SetObjectMacro = 372,
    GetObjectMacro = 373,
    BooleanMacro = 374,
    SetVector2Macro = 375,
    SetVector3Macro = 376,
    SetVector4Macro = 377,
    SetVector6Macro = 378,
    GetVector2Macro = 379,
    GetVector3Macro = 380,
    GetVector4Macro = 381,
    GetVector6Macro = 382,
    SetVectorMacro = 383,
    GetVectorMacro = 384,
    ViewportCoordinateMacro = 385,
    WorldCoordinateMacro = 386,
    TypeMacro = 387,
    VTK_BYTE_SWAP_DECL = 388
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{


  const char   *str;
  unsigned int  integer;


};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);


/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;

/* Copy the second part of user declarations.  */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#define YYSIZEMAX ((size_t) -1)

#ifdef __cplusplus
   typedef bool yybool;
#else
   typedef unsigned char yybool;
#endif
#define yytrue 1
#define yyfalse 0

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify clang.  */
# define YYLONGJMP(Env, Val) (longjmp (Env, Val), YYASSERT (0))
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__)                                              \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if 1
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#ifndef YYASSERT
# define YYASSERT(Condition) ((void) ((Condition) || (abort (), 0)))
#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   9147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  157
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  276
/* YYNRULES -- Number of rules.  */
#define YYNRULES  701
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1182
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 10
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   388

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   153,     2,     2,     2,   149,   146,     2,
     140,   141,   147,   152,   139,   151,   156,   150,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   138,   134,
     142,   137,   148,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   143,     2,   144,   155,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   135,   154,   136,   145,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,  1475,  1475,  1477,  1479,  1478,  1489,  1490,  1491,  1492,
    1493,  1494,  1495,  1496,  1497,  1498,  1499,  1500,  1501,  1502,
    1503,  1504,  1505,  1506,  1509,  1510,  1511,  1512,  1513,  1516,
    1517,  1524,  1531,  1532,  1532,  1536,  1543,  1544,  1547,  1548,
    1549,  1552,  1553,  1556,  1556,  1571,  1570,  1576,  1582,  1581,
    1586,  1592,  1593,  1594,  1597,  1599,  1601,  1604,  1605,  1608,
    1609,  1611,  1613,  1612,  1621,  1625,  1626,  1627,  1630,  1631,
    1632,  1633,  1634,  1635,  1636,  1637,  1638,  1639,  1640,  1641,
    1642,  1643,  1644,  1645,  1648,  1649,  1650,  1651,  1654,  1655,
    1656,  1657,  1660,  1661,  1664,  1666,  1669,  1674,  1675,  1678,
    1679,  1682,  1683,  1684,  1695,  1696,  1697,  1701,  1702,  1706,
    1706,  1719,  1725,  1733,  1734,  1735,  1738,  1739,  1739,  1743,
    1744,  1746,  1747,  1748,  1748,  1756,  1760,  1761,  1764,  1766,
    1768,  1769,  1772,  1773,  1781,  1782,  1785,  1786,  1788,  1790,
    1792,  1796,  1798,  1799,  1802,  1805,  1806,  1809,  1810,  1809,
    1814,  1848,  1851,  1852,  1853,  1855,  1857,  1859,  1863,  1866,
    1866,  1897,  1900,  1899,  1917,  1919,  1918,  1923,  1925,  1923,
    1927,  1929,  1927,  1931,  1932,  1934,  1931,  1945,  1946,  1949,
    1950,  1952,  1953,  1956,  1956,  1966,  1967,  1975,  1976,  1977,
    1978,  1981,  1984,  1985,  1986,  1989,  1990,  1991,  1994,  1995,
    1996,  2000,  2001,  2002,  2003,  2006,  2007,  2008,  2012,  2017,
    2011,  2029,  2033,  2033,  2045,  2044,  2053,  2057,  2060,  2069,
    2070,  2073,  2073,  2074,  2075,  2081,  2086,  2087,  2088,  2091,
    2094,  2095,  2097,  2098,  2101,  2101,  2109,  2110,  2111,  2114,
    2116,  2117,  2121,  2120,  2133,  2134,  2133,  2153,  2153,  2157,
    2158,  2161,  2162,  2165,  2171,  2172,  2172,  2175,  2176,  2176,
    2178,  2180,  2184,  2186,  2184,  2210,  2211,  2214,  2214,  2216,
    2216,  2224,  2227,  2286,  2287,  2289,  2290,  2290,  2293,  2296,
    2297,  2301,  2312,  2312,  2331,  2333,  2333,  2351,  2351,  2353,
    2357,  2358,  2359,  2358,  2364,  2366,  2367,  2368,  2369,  2370,
    2371,  2374,  2375,  2379,  2380,  2384,  2385,  2388,  2389,  2393,
    2394,  2395,  2398,  2399,  2402,  2402,  2405,  2406,  2409,  2409,
    2413,  2414,  2414,  2421,  2422,  2425,  2426,  2427,  2428,  2429,
    2432,  2434,  2436,  2440,  2442,  2444,  2446,  2448,  2450,  2452,
    2452,  2457,  2460,  2463,  2466,  2466,  2474,  2474,  2483,  2484,
    2485,  2486,  2487,  2488,  2489,  2490,  2491,  2492,  2493,  2494,
    2495,  2496,  2497,  2498,  2499,  2500,  2501,  2502,  2503,  2510,
    2511,  2512,  2513,  2514,  2515,  2516,  2522,  2523,  2526,  2527,
    2529,  2530,  2533,  2534,  2537,  2538,  2539,  2540,  2543,  2544,
    2545,  2546,  2547,  2551,  2552,  2553,  2556,  2557,  2560,  2561,
    2569,  2572,  2572,  2574,  2574,  2578,  2579,  2581,  2585,  2586,
    2588,  2588,  2590,  2592,  2596,  2599,  2599,  2601,  2601,  2605,
    2608,  2608,  2610,  2610,  2614,  2615,  2617,  2619,  2621,  2623,
    2625,  2629,  2630,  2633,  2634,  2635,  2636,  2637,  2638,  2639,
    2640,  2641,  2642,  2643,  2644,  2645,  2646,  2647,  2648,  2649,
    2650,  2651,  2652,  2653,  2656,  2657,  2658,  2659,  2660,  2661,
    2662,  2663,  2664,  2665,  2666,  2667,  2668,  2669,  2670,  2690,
    2691,  2692,  2693,  2696,  2700,  2704,  2704,  2708,  2709,  2724,
    2725,  2741,  2742,  2745,  2745,  2745,  2752,  2752,  2762,  2763,
    2763,  2762,  2772,  2772,  2782,  2782,  2791,  2791,  2791,  2824,
    2823,  2834,  2835,  2835,  2834,  2844,  2862,  2862,  2867,  2867,
    2872,  2872,  2877,  2877,  2882,  2882,  2887,  2887,  2892,  2892,
    2897,  2897,  2902,  2902,  2919,  2919,  2933,  2970,  3008,  3045,
    3046,  3053,  3054,  3055,  3056,  3057,  3058,  3059,  3060,  3061,
    3062,  3063,  3064,  3067,  3068,  3069,  3070,  3071,  3072,  3073,
    3074,  3075,  3076,  3077,  3078,  3079,  3080,  3081,  3082,  3083,
    3084,  3085,  3086,  3087,  3088,  3089,  3090,  3091,  3092,  3093,
    3094,  3095,  3096,  3097,  3098,  3099,  3100,  3103,  3104,  3105,
    3106,  3107,  3108,  3109,  3110,  3111,  3112,  3113,  3114,  3115,
    3116,  3117,  3118,  3119,  3120,  3121,  3122,  3123,  3124,  3125,
    3126,  3127,  3128,  3129,  3130,  3131,  3134,  3135,  3136,  3137,
    3138,  3139,  3140,  3141,  3148,  3149,  3152,  3153,  3154,  3155,
    3155,  3156,  3159,  3160,  3163,  3164,  3165,  3166,  3196,  3196,
    3197,  3198,  3199,  3200,  3223,  3224,  3227,  3228,  3229,  3230,
    3233,  3234,  3235,  3238,  3239,  3241,  3242,  3244,  3245,  3248,
    3249,  3252,  3253,  3254,  3258,  3257,  3271,  3272,  3275,  3275,
    3277,  3277,  3281,  3281,  3283,  3283,  3285,  3285,  3289,  3289,
    3294,  3295,  3297,  3298,  3301,  3302,  3305,  3306,  3309,  3310,
    3311,  3312,  3313,  3314,  3315,  3316,  3316,  3316,  3316,  3316,
    3317,  3318,  3319,  3320,  3321,  3324,  3327,  3328,  3331,  3334,
    3334,  3334
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "VTK_ID", "QT_ID", "StdString",
  "UnicodeString", "OSTREAM", "ISTREAM", "LP", "LA", "STRING_LITERAL",
  "INT_LITERAL", "HEX_LITERAL", "OCT_LITERAL", "FLOAT_LITERAL",
  "CHAR_LITERAL", "ZERO", "NULLPTR", "SSIZE_T", "SIZE_T", "NULLPTR_T",
  "BEGIN_ATTRIB", "STRUCT", "CLASS", "UNION", "ENUM", "PUBLIC", "PRIVATE",
  "PROTECTED", "CONST", "VOLATILE", "MUTABLE", "STATIC", "THREAD_LOCAL",
  "VIRTUAL", "EXPLICIT", "INLINE", "CONSTEXPR", "FRIEND", "EXTERN",
  "OPERATOR", "TEMPLATE", "THROW", "TRY", "CATCH", "NOEXCEPT", "DECLTYPE",
  "TYPENAME", "TYPEDEF", "NAMESPACE", "USING", "NEW", "DELETE", "DEFAULT",
  "STATIC_CAST", "DYNAMIC_CAST", "CONST_CAST", "REINTERPRET_CAST",
  "OP_LSHIFT_EQ", "OP_RSHIFT_EQ", "OP_LSHIFT", "OP_RSHIFT_A",
  "OP_DOT_POINTER", "OP_ARROW_POINTER", "OP_ARROW", "OP_INCR", "OP_DECR",
  "OP_PLUS_EQ", "OP_MINUS_EQ", "OP_TIMES_EQ", "OP_DIVIDE_EQ",
  "OP_REMAINDER_EQ", "OP_AND_EQ", "OP_OR_EQ", "OP_XOR_EQ", "OP_LOGIC_AND",
  "OP_LOGIC_OR", "OP_LOGIC_EQ", "OP_LOGIC_NEQ", "OP_LOGIC_LEQ",
  "OP_LOGIC_GEQ", "ELLIPSIS", "DOUBLE_COLON", "OTHER", "AUTO", "VOID",
  "BOOL", "FLOAT", "DOUBLE", "INT", "SHORT", "LONG", "INT64__", "CHAR",
  "CHAR16_T", "CHAR32_T", "WCHAR_T", "SIGNED", "UNSIGNED", "IdType",
  "TypeInt8", "TypeUInt8", "TypeInt16", "TypeUInt16", "TypeInt32",
  "TypeUInt32", "TypeInt64", "TypeUInt64", "TypeFloat32", "TypeFloat64",
  "SetMacro", "GetMacro", "SetStringMacro", "GetStringMacro",
  "SetClampMacro", "SetObjectMacro", "GetObjectMacro", "BooleanMacro",
  "SetVector2Macro", "SetVector3Macro", "SetVector4Macro",
  "SetVector6Macro", "GetVector2Macro", "GetVector3Macro",
  "GetVector4Macro", "GetVector6Macro", "SetVectorMacro", "GetVectorMacro",
  "ViewportCoordinateMacro", "WorldCoordinateMacro", "TypeMacro",
  "VTK_BYTE_SWAP_DECL", "';'", "'{'", "'}'", "'='", "':'", "','", "'('",
  "')'", "'<'", "'['", "']'", "'~'", "'&'", "'*'", "'>'", "'%'", "'/'",
  "'-'", "'+'", "'!'", "'|'", "'^'", "'.'", "$accept", "translation_unit",
  "opt_declaration_seq", "$@1", "declaration", "template_declaration",
  "explicit_instantiation", "linkage_specification",
  "namespace_definition", "$@2", "namespace_alias_definition",
  "forward_declaration", "simple_forward_declaration", "class_definition",
  "class_specifier", "$@3", "class_head", "$@4", "$@5", "class_key",
  "class_head_name", "class_name", "opt_final", "member_specification",
  "$@6", "member_access_specifier", "member_declaration",
  "template_member_declaration", "friend_declaration",
  "base_specifier_list", "base_specifier", "opt_virtual",
  "opt_access_specifier", "access_specifier", "opaque_enum_declaration",
  "enum_definition", "enum_specifier", "$@7", "enum_head", "enum_key",
  "opt_enum_base", "$@8", "enumerator_list", "enumerator_definition",
  "$@9", "nested_variable_initialization", "ignored_initializer",
  "ignored_class", "ignored_class_body", "typedef_declaration",
  "basic_typedef_declaration", "typedef_declarator_list",
  "typedef_declarator_list_cont", "typedef_declarator",
  "typedef_direct_declarator", "function_direct_declarator", "$@10",
  "$@11", "typedef_declarator_id", "using_declaration", "using_id",
  "using_directive", "alias_declaration", "$@12", "template_head", "$@13",
  "template_parameter_list", "$@14", "template_parameter", "$@15", "$@16",
  "$@17", "$@18", "$@19", "$@20", "$@21", "opt_ellipsis",
  "class_or_typename", "opt_template_parameter_initializer",
  "template_parameter_initializer", "$@22", "template_parameter_value",
  "function_definition", "function_declaration",
  "nested_method_declaration", "nested_operator_declaration",
  "method_definition", "method_declaration", "operator_declaration",
  "conversion_function", "$@23", "$@24", "conversion_function_id",
  "operator_function_nr", "$@25", "operator_function_sig", "$@26",
  "operator_function_id", "operator_sig", "function_nr",
  "function_trailer_clause", "function_trailer", "$@27", "noexcept_sig",
  "function_body_as_trailer", "opt_trailing_return_type",
  "trailing_return_type", "$@28", "function_body", "function_try_block",
  "handler_seq", "function_sig", "$@29", "structor_declaration", "$@30",
  "$@31", "structor_sig", "$@32", "opt_ctor_initializer",
  "mem_initializer_list", "mem_initializer",
  "parameter_declaration_clause", "$@33", "parameter_list", "$@34",
  "parameter_declaration", "$@35", "$@36", "opt_initializer",
  "initializer", "$@37", "$@38", "variable_declaration",
  "init_declarator_id", "opt_declarator_list", "declarator_list_cont",
  "$@39", "init_declarator", "opt_ptr_operator_seq",
  "direct_abstract_declarator", "$@40", "direct_declarator", "$@41",
  "lp_or_la", "$@42", "opt_array_or_parameters", "$@43", "$@44",
  "function_qualifiers", "abstract_declarator", "declarator",
  "opt_declarator_id", "declarator_id", "bitfield_size",
  "opt_array_decorator_seq", "array_decorator_seq", "$@45",
  "array_decorator_seq_impl", "array_decorator", "$@46",
  "array_size_specifier", "$@47", "id_expression", "unqualified_id",
  "qualified_id", "nested_name_specifier", "$@48", "tilde_sig",
  "identifier_sig", "scope_operator_sig", "template_id", "$@49",
  "decltype_specifier", "$@50", "simple_id", "identifier",
  "opt_decl_specifier_seq", "decl_specifier2", "decl_specifier_seq",
  "decl_specifier", "storage_class_specifier", "function_specifier",
  "cv_qualifier", "cv_qualifier_seq", "store_type", "store_type_specifier",
  "$@51", "$@52", "type_specifier", "trailing_type_specifier", "$@53",
  "trailing_type_specifier_seq", "trailing_type_specifier_seq2", "$@54",
  "$@55", "tparam_type", "tparam_type_specifier2", "$@56", "$@57",
  "tparam_type_specifier", "simple_type_specifier", "type_name",
  "primitive_type", "ptr_operator_seq", "reference", "rvalue_reference",
  "pointer", "$@58", "ptr_cv_qualifier_seq", "pointer_seq",
  "attribute_specifier_seq", "attribute_specifier", "$@59", "$@60",
  "declaration_macro", "$@61", "$@62", "$@63", "$@64", "$@65", "$@66",
  "$@67", "$@68", "$@69", "$@70", "$@71", "$@72", "$@73", "$@74", "$@75",
  "$@76", "$@77", "$@78", "$@79", "$@80", "$@81", "$@82", "opt_comma",
  "operator_id", "operator_id_no_delim", "keyword", "literal",
  "constant_expression", "constant_expression_item", "$@83",
  "common_bracket_item", "common_bracket_item_no_scope_operator",
  "any_bracket_contents", "bracket_pitem", "any_bracket_item",
  "braces_item", "angle_bracket_contents", "braces_contents",
  "angle_bracket_pitem", "angle_bracket_item", "angle_brackets_sig",
  "$@84", "right_angle_bracket", "brackets_sig", "$@85", "$@86",
  "parentheses_sig", "$@87", "$@88", "$@89", "braces_sig", "$@90",
  "ignored_items", "ignored_expression", "ignored_item",
  "ignored_item_no_semi", "ignored_item_no_angle", "ignored_braces",
  "ignored_brackets", "ignored_parentheses", "ignored_left_parenthesis", YY_NULLPTR
};
#endif

#define YYPACT_NINF -1028
#define YYTABLE_NINF -655

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const short int yypact[] =
{
   -1028,   108,   115, -1028, -1028,  6791,   217,   221,   231,   247,
     250,   288,   291,   -71,   -29,   -12, -1028, -1028, -1028, -1028,
     285, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,
     129, -1028,  4328, -1028, -1028,  8663,   173,  7489, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028,   148,   150,   192,   246,   269,   273,
     292,   300,   304,   329,   342,   -51,   -10,    20,   128,   135,
     143,   185,   209,   214,   218,   222,   230,   254,   284,   289,
     299,   306,   314,   326,   354,   358, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028,   113, -1028, -1028, -1028, -1028, -1028, -1028,
    8336, -1028,   164,   164,   164,   164, -1028,   375,  8663, -1028,
     123, -1028,   341,  1951,  9036,   437,  7756,   166,   196, -1028,
       7,  8445, -1028, -1028, -1028, -1028,   256,   140, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,   383,  4790,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028,    15, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,    55,  7756,
      -7,    -3,     4,    28,   152,   162,   179,   511, -1028, -1028,
   -1028, -1028, -1028,  7778,   437,   437,  8663,   256, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028,   395,    -7,    -3,     4,
      28,   152,   162,   179, -1028, -1028, -1028,  7756,  7756, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,
     400,   406, -1028,  1951,  7756,   437,   437,  6747, -1028, -1028,
   -1028,  6747,  6747, -1028,  6747,  6747,  6747,  6747,  6747,  6747,
    6747,  6747,  6747,  6747,  6747,  6747,  6747,  6747,  8191,   407,
    8001,  8191, -1028,  7424,   403,  7756, -1028, -1028, -1028, -1028,
   -1028, -1028,  8336, -1028,  8554,   463,   409, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028,  8663, -1028, -1028,   525,
   -1028, -1028, -1028, -1028,   410,   437,   437,   437, -1028, -1028,
   -1028, -1028,     7, -1028, -1028, -1028, -1028,   525, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028,  1951, -1028, -1028,   525,
   -1028, -1028, -1028,  7826, -1028,   158,    74, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028,   366, -1028,   525,   525,  5714,
   -1028, -1028,  2172,  2326, -1028, -1028,   228, -1028,  2480,  3558,
    2634, -1028, -1028, -1028, -1028, -1028, -1028,  8219,  8110,  8219,
    7598, -1028, -1028, -1028, -1028, -1028, -1028,  7890, -1028,  2788,
     412,   416, -1028,   428, -1028,    57, -1028, -1028,  6638,  1951,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028,   425,  6747,  6747,
    6747,   426,   427,  6747,   429,   432,   433,   436,   438,   442,
     443,   445,   447,   448,   449,   450,   452,   451, -1028, -1028,
     460, -1028,   256, -1028, -1028, -1028, -1028, -1028, -1028,    54,
   -1028,  9011,   649,   437,   437,   464,  6747, -1028, -1028, -1028,
     206, -1028,  7644,  8554,  7826,  7756,   444,  2942,   461,  8990,
     676,   409, -1028, -1028, -1028, -1028, -1028,  8191,  8110,  8191,
    7598, -1028, -1028,   525, -1028,   499, -1028, -1028, -1028,  1610,
   -1028, -1028,   458, -1028,  1951,   122, -1028, -1028, -1028,   468,
    7890, -1028,   467,   256,   525,   525,   525, -1028, -1028,  1417,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028,   466, -1028, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028,   481,  3712, -1028, -1028,   474, -1028,
   -1028, -1028, -1028,   181, -1028,  8772,    77,   576, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028,   525,   488, -1028,   256,    64,
     489,   189,  8219,  8219,   183,   239, -1028, -1028, -1028, -1028,
     490,   437, -1028, -1028, -1028,   623,   484,   485,    27, -1028,
   -1028,   495, -1028,   486, -1028, -1028, -1028, -1028, -1028, -1028,
     492,   496,   497, -1028, -1028,   501,  8663, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,  7756,
   -1028,   502, -1028,   525,    67,  7378, -1028, -1028,   504,   525,
   -1028,   437,   437,  9011, -1028,   335, -1028,   506,  8663,   510,
     525, -1028, -1028,  1951,   508, -1028,    65, -1028, -1028,   518,
     562, -1028,   437, -1028,   461,  5868,   515,    84,   526,   206,
    1417, -1028,   499, -1028, -1028,    70,   117, -1028, -1028,   519,
     109, -1028, -1028, -1028, -1028,  6176, -1028, -1028, -1028,   499,
   -1028, -1028, -1028,   521, -1028, -1028, -1028, -1028, -1028,  7756,
    7756,  7756, -1028,   437,   437,  8663,   256,   140, -1028, -1028,
   -1028, -1028,   256,   638,  4944,  5098,  5252, -1028,   527, -1028,
   -1028, -1028,   533,   534, -1028,   140, -1028,    78, -1028,   535,
    8663, -1028,   528,   529, -1028, -1028, -1028, -1028,  8663, -1028,
   -1028, -1028,  8663,  8663, -1028,   546,  8663,  8663,  8663,  8663,
    8663,  8663,  8663,  8663,  8663,  8663,   530, -1028, -1028, -1028,
   -1028, -1028,   536, -1028, -1028, -1028,   382,   537, -1028,   653,
     463, -1028,   525, -1028, -1028,  6747, -1028, -1028, -1028,    83,
     324,  7756,   463,  3096, -1028, -1028,   551, -1028,  8663, -1028,
   -1028,   552, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028,   560, -1028,   117, -1028, -1028, -1028, -1028,
   -1028, -1028,    89, -1028,    55, -1028, -1028, -1028, -1028,   519,
   -1028,   514, -1028,   140, -1028,  6022, -1028,  6176, -1028, -1028,
   -1028,   345, -1028,  5406,  4482,  5560, -1028,   228, -1028, -1028,
   -1028, -1028,  7890, -1028, -1028, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028,   461, -1028,   256, -1028, -1028,
     554,  8663, -1028,   555,  8663, -1028,   557,   559,   561,   563,
     564,   565,   566,   567,   570,   571, -1028,   572,  1787, -1028,
    7756, -1028, -1028, -1028,  7756, -1028,  7378,   525, -1028,  6176,
   -1028,   569, -1028, -1028, -1028, -1028,   525,   632,   256,   117,
   -1028, -1028, -1028, -1028,   461,    55,  8881, -1028, -1028, -1028,
   -1028,   574, -1028, -1028, -1028, -1028, -1028,   461, -1028,  6484,
   -1028, -1028, -1028, -1028,   575, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028,   345, -1028,   584,    50,  1417,   584,   256,   581,
     589, -1028, -1028,   585, -1028, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028,   713,   714, -1028,  7038,   226,  7709,
      65, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028,  6923, -1028,   164, -1028, -1028, -1028,   595,
     410,  1951,  7153,   256, -1028,   463,  1981,   463,   537,  6176,
    4636, -1028,   684, -1028, -1028, -1028, -1028, -1028,   525,  5868,
     590, -1028,  8881, -1028, -1028,   140,   588,  6176,   592, -1028,
     461, -1028,  1417, -1028, -1028, -1028, -1028, -1028,   598,   256,
   -1028, -1028, -1028, -1028,   600, -1028,   602,   604,   606, -1028,
   -1028, -1028,   805,   164,   410,  7268,   463, -1028, -1028, -1028,
   -1028,  6923, -1028,  7268, -1028, -1028, -1028, -1028,  1951,  7826,
   -1028, -1028, -1028,    65,   117, -1028,   158, -1028, -1028, -1028,
   -1028, -1028, -1028,  6176, -1028,   607,  6330, -1028, -1028,   584,
   -1028, -1028,  3866, -1028, -1028, -1028,  7936, -1028, -1028,   805,
   -1028, -1028,  7826,  7268,    90, -1028, -1028,   614, -1028, -1028,
     525, -1028,  1417,   525,   525, -1028,  6330, -1028,   345, -1028,
     434, -1028, -1028, -1028,    95, -1028,  7936, -1028,  8072, -1028,
      93, -1028,  1417,   525, -1028, -1028, -1028, -1028,    65,    65,
    3250,  4020,   373,    56,  8072,   107, -1028, -1028,  3404, -1028,
   -1028, -1028, -1028, -1028, -1028,    59,   373, -1028,   434,  4174,
   -1028, -1028
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const unsigned short int yydefact[] =
{
       3,     0,     4,     1,   481,     0,   437,   438,   439,   433,
     434,   435,   436,   441,   442,   440,   483,    52,    51,    53,
     113,   396,   397,   388,   391,   392,   394,   395,   393,   387,
     389,   217,     0,   346,   410,     0,     0,     0,   343,   454,
     455,   456,   457,   458,   463,   464,   465,   466,   459,   460,
     461,   462,   467,   468,   453,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,   341,     5,    19,
      20,    13,    11,    12,     9,    36,    17,   376,    43,   481,
      10,    16,   376,     0,   481,    14,   134,     7,     6,     8,
       0,    18,     0,     0,     0,     0,   205,     0,     0,    15,
       0,   323,   481,     0,     0,     0,     0,   481,   409,   325,
     342,     0,   481,   384,   385,   386,   177,   279,   401,   405,
     408,   481,   481,   482,    21,   634,   115,   114,   390,     0,
     437,   438,   439,   433,   434,   435,   436,   700,   701,   611,
     607,   608,   606,   609,   610,   612,   613,   441,   442,   440,
     670,   580,   579,   581,   599,   583,   585,   584,   586,   587,
     588,   591,   592,   590,   589,   595,   598,   582,   600,   601,
     593,   578,   577,   597,   596,   553,   554,   594,   604,   603,
     602,   605,   555,   556,   557,   684,   558,   559,   560,   566,
     567,   561,   562,   563,   564,   565,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   682,   681,   694,   453,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   670,
     688,   685,   689,   699,   162,   670,   549,   550,   544,   687,
     543,   545,   546,   547,   548,   551,   552,   686,   693,   692,
     683,   690,   691,   672,   678,   680,   679,   670,     0,     0,
     437,   438,   439,   433,   434,   435,   436,   389,   376,   481,
     376,   481,   481,     0,   481,   409,     0,   177,   369,   371,
     370,   374,   375,   373,   372,   670,    33,   350,   348,   349,
     353,   354,   352,   351,   357,   356,   355,     0,     0,   368,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
       0,   481,   324,     0,     0,   326,   327,     0,   488,   492,
     494,     0,     0,   501,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   279,     0,
      50,   279,   109,   116,     0,     0,    27,    37,    24,   481,
      26,    28,     0,    25,     0,   177,   249,   238,   670,   187,
     237,   189,   190,   188,   208,   481,     0,   211,    22,   413,
     339,   195,   193,   244,   330,     0,   326,   327,   328,    58,
     329,    57,     0,   333,   331,   332,   334,   412,   335,   344,
     376,   481,   376,   481,   135,   206,     0,   481,   403,   382,
     287,   289,   178,     0,   275,   265,   177,   481,   481,   481,
     400,   280,   469,   470,   479,   471,   376,   432,   431,   484,
       3,   672,     0,     0,   657,   656,   167,   161,     0,     0,
       0,   664,   666,   662,   347,   481,   390,   279,    50,   279,
     116,   330,   376,   376,   150,   146,   142,     0,   145,     0,
       0,     0,   153,     0,   151,     0,   155,   154,     0,     0,
     350,   348,   349,   353,   354,   352,   351,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   381,   380,
       0,   275,   177,   481,   378,   379,    61,    39,    48,   406,
     481,     0,     0,    58,     0,     0,   121,   105,   117,   112,
     481,   481,     0,     0,     0,     0,     0,     0,   255,     0,
       0,   249,   247,   336,   337,   338,   645,   279,    50,   279,
     116,   196,   194,   383,   376,   477,   207,   212,   481,     0,
     191,   219,   312,   481,     0,     0,   267,   272,   266,     0,
       0,   303,     0,   177,   474,   473,   475,   472,   480,   402,
     660,   639,   623,   668,   641,   628,   642,   637,   658,   638,
     629,   633,   632,     0,   627,   630,   631,   636,   622,   640,
     635,   624,   625,   626,     4,     0,   675,   677,     0,   671,
     674,   676,   695,     0,   164,     0,     0,     0,   696,    30,
     673,   698,   634,   634,   634,   411,     0,   142,   177,   406,
       0,   481,   279,   279,     0,   312,   481,   326,   327,    32,
       0,     0,     3,   158,   159,     0,   553,   554,     0,   538,
     537,     0,   535,     0,   536,   216,   542,   157,   156,   486,
       0,     0,     0,   496,   499,     0,     0,   506,   510,   514,
     518,   508,   512,   516,   520,   522,   524,   526,   527,     0,
      41,   274,   278,   377,    62,     0,    60,    38,    47,    56,
     481,    58,     0,     0,   107,     0,   119,   122,     0,   111,
     407,   481,   481,     0,   250,   251,     0,   670,   236,     0,
     262,   406,     0,   245,   255,     0,     0,   406,     0,   481,
     404,   398,   478,   288,   219,     0,   232,   284,   313,     0,
     307,   197,   192,   271,   276,     0,   270,   285,   304,   477,
     634,   647,   634,     0,    31,    29,   697,   165,   163,     0,
       0,     0,   427,   426,   425,     0,   177,   279,   420,   424,
     179,   180,   177,     0,     0,     0,     0,   137,   141,   144,
     139,   111,     0,     0,   136,   279,   147,   307,    35,     4,
       0,   541,     0,     0,   540,   539,   531,   532,     0,   489,
     493,   495,     0,     0,   502,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   529,    65,    66,    67,
      44,   481,     0,   101,   102,   103,    99,    49,    92,    97,
     177,    45,    54,   481,   110,   121,   123,   118,   104,     0,
     325,     0,   177,     0,   481,   261,   256,   257,     0,   340,
     219,     0,   652,   653,   654,   650,   651,   646,   649,   345,
      42,    40,   108,   111,   399,   232,   214,   225,   223,   221,
     229,   234,     0,   220,   227,   228,   218,   233,   318,   315,
     316,     0,   242,   279,   621,   618,   619,   268,   614,   616,
     617,   290,   476,     0,     0,     0,   485,   167,   428,   429,
     430,   422,   305,   168,   481,   419,   376,   171,   174,   665,
     667,   663,   138,   140,   143,   255,    34,   177,   533,   534,
       0,     0,   497,     0,     0,   505,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   530,     0,     0,    64,
       0,   100,   481,    98,     0,    94,     0,    55,   120,     0,
     672,     0,   127,   252,   253,   240,   209,   258,   177,   232,
     481,   645,   106,   213,   255,     0,     0,   224,   230,   231,
     226,   321,   317,   310,   311,   309,   308,   255,   277,     0,
     615,   291,   286,   294,     0,   644,   669,   643,   648,   659,
     166,   376,   290,   306,   181,   177,   421,   181,   177,     0,
       0,   487,   490,     0,   500,   503,   507,   511,   515,   519,
     509,   513,   517,   521,     0,     0,   528,     0,   389,     0,
       0,    83,    79,    70,    76,    63,    78,    72,    71,    75,
      73,    68,    69,     0,    77,     0,   202,   203,    74,     0,
     323,     0,     0,   177,    80,   177,     0,   177,    46,   124,
     126,   125,   239,   219,   260,   262,   263,   246,   248,     0,
       0,   222,     0,   415,   235,   279,     0,     0,     0,   620,
     255,   661,   423,   281,   183,   169,   182,   301,     0,   177,
     172,   175,   148,   160,     0,   672,     0,     0,     0,    90,
     481,    88,     0,     0,     0,     0,   177,    81,    84,    86,
      87,     0,    85,     0,   198,    82,   481,   204,     0,     0,
      95,    93,    96,     0,   232,   259,   265,   655,   481,   417,
     376,   414,   481,   322,   481,     0,     0,   282,   302,   181,
     295,   491,     0,   504,   523,   525,     0,   481,    89,     0,
      91,   481,     0,     0,     0,   481,   201,     0,   210,   264,
     215,   376,   416,   319,   243,   481,   184,   185,   290,   176,
     149,   498,   670,   672,   406,   130,     0,   481,     0,   199,
       0,   670,   418,   292,   186,   283,   297,   296,     0,   300,
       0,     0,     0,    59,     0,   406,   131,   200,     0,   295,
     298,   299,   672,   133,   128,    59,     0,   241,   293,     0,
     129,   132
};

  /* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
   -1028, -1028,  -401, -1028, -1028,   745,  -167, -1028, -1028, -1028,
   -1028,  -847,   -99,    -2,   -31, -1028, -1028, -1028, -1028,    21,
    -404,  -107,  -828, -1028, -1028, -1028, -1028,  -166, -1028,  -173,
    -272, -1028, -1028,   -49,  -163,  -159,   -27, -1028, -1028,    11,
    -483, -1028, -1028,   -54, -1028, -1028, -1028,  -309,  -771,  -156,
    -119,  -409,   147,     0, -1028, -1028, -1028, -1028,   149,  -152,
   -1028, -1028,    18, -1028,    25, -1028, -1028, -1028,  -109, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028,   405, -1028,  -923, -1028,
   -1028, -1028,   766, -1028, -1028, -1028,  -145,  -218,    26,  -121,
   -1028, -1028,  -268,  -502, -1028, -1028, -1028,  -310,  -296,  -526,
    -690, -1028, -1028, -1028, -1028,  -802, -1028, -1028,   -80, -1028,
   -1028, -1028, -1028,  -117, -1028, -1028, -1028, -1028,   249, -1028,
     -40,  -684, -1028, -1028, -1028,  -253, -1028, -1028,  -313, -1028,
   -1028, -1028,  -131,   287,  -302,   293, -1028,   -73,  -136,  -713,
   -1028,  -251, -1028,  -699, -1028,  -930, -1028, -1028,  -374, -1028,
   -1028, -1028,  -432, -1028, -1028,  -478, -1028, -1028,   -63, -1028,
   -1028, -1028,  1119,  1082,  1110,    14, -1028, -1028,   -32,   700,
      -5, -1028,    45, -1028,   930,   -21,   397, -1028,    94,   998,
   -1028, -1028,  -497, -1028,   943,   110, -1028, -1028,  -124,  -876,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,
     195,    51,   440,  -402,   376, -1028,   377, -1028,    75, -1028,
     493, -1028, -1028, -1028,  -115, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,
   -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028, -1028,     9,
     121,   174,  -835,  -822, -1028,  -633,  -151,  -458, -1028,   -65,
   -1028,  -130, -1028, -1027, -1028,  -683, -1028,  -582, -1028, -1028,
   -1028,  -259, -1028, -1028, -1028,   251, -1028,  -181,  -426, -1028,
    -421,    36,    -8, -1028,  -658, -1028
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const short int yydefgoto[] =
{
      -1,     1,     2,     4,    88,   356,    90,    91,    92,   461,
      93,    94,    95,   358,    97,   349,    98,   926,   675,   375,
     509,   510,   678,   674,   801,   802,  1005,  1079,  1007,   807,
     808,   924,   920,   809,   100,   101,   102,   516,   103,   359,
     519,   688,   685,   686,   929,   360,   931,  1071,  1145,   105,
     106,   616,   624,   617,   454,   455,   895,  1110,   456,   107,
     320,   108,   361,   770,   362,   436,   603,   877,   604,   605,
     974,   606,   977,   607,   978,  1109,   882,   752,  1055,  1056,
    1106,  1136,   363,   112,   113,   114,  1082,  1015,  1016,   116,
     528,  1033,   117,   546,   714,   547,   944,   548,   118,   550,
     716,   853,   945,   854,   855,   856,   857,   946,   369,   370,
    1032,   551,   957,  1017,   531,   830,   383,   704,   526,   694,
     695,   699,   700,   826,  1035,   827,   828,  1096,   557,   558,
     725,   559,   119,   414,   500,   555,   863,   501,   502,   883,
    1138,   415,   871,   416,   545,   962,  1050,  1169,  1140,  1058,
     562,   972,   552,   956,   717,   963,   719,   859,   860,   951,
    1046,  1047,   810,   121,   282,   283,   530,   124,   125,   126,
     284,   536,   285,   268,   129,   130,   348,   503,   376,   132,
     133,   134,   135,   712,  1076,   137,   426,   544,   138,   139,
     269,  1044,  1045,  1100,  1131,   746,   747,   886,   971,   748,
     140,   141,   142,   421,   422,   423,   424,   729,   713,   425,
     690,   143,   145,   583,   144,   778,   478,   901,  1064,   479,
     480,   782,   983,   783,   483,   904,  1066,   786,   790,   787,
     791,   788,   792,   789,   793,   794,   795,   917,   645,   584,
     585,   586,   867,   868,   959,   587,   588,   429,   589,   590,
     968,   705,   874,   836,   837,   870,   941,   437,   591,   732,
     730,   592,   614,   612,   613,   593,   731,   432,   439,   599,
     600,   601,   264,   265,   266,   267
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const short int yytable[] =
{
     127,   420,   381,    96,   278,   595,   382,   408,   280,   444,
     405,   357,   404,   467,   563,   296,   104,   388,   610,   123,
     831,   738,   838,   109,   845,   625,    99,   468,   722,   594,
     110,   115,   325,   371,   372,   373,   458,   689,   822,   887,
     620,   260,  1053,   943,   619,   960,   281,   884,   711,   515,
     128,   323,   721,   884,  1060,   466,   279,   676,   433,   676,
     410,   411,   676,  -357,   438,   441,   442,   676,   263,  -357,
    1043,  1003,   835,    16,   718,   157,   158,  -369,   434,  1137,
      16,  -371,   326,   258,   410,   411,   440,   676,  -370,   327,
     774,   385,   869,    16,  1029,   797,   798,   799,   676,   131,
     400,    16,   750,   392,   402,  -356,    16,   947,     3,  1154,
     676,  -356,  -374,    16,   459,    -2,    16,   549,   386,   389,
     847,   325,  -355,   839,   123,   701,   751,   417,  -355,   286,
     328,    99,    16,   412,   707,  -369,   115,  1037,   761,  -371,
     939,   148,   403,   948,   949,   406,  -370,   718,   848,   399,
    1069,   417,   401,   261,   754,   755,   756,   412,   260,   648,
     329,   849,   408,   435,   850,   561,  1099,   722,   387,   390,
    -374,   326,   149,   468,   610,   775,   288,   289,   290,   291,
     292,   293,   294,   851,   980,   431,  1139,   527,   677,   -59,
     677,   721,   -59,   841,   634,   443,   418,   419,   884,   -59,
     258,   647,   -59,   800,   364,   243,   262,   960,  1155,   366,
     846,   979,  1103,   762,   763,   844,   861,   417,   841,   -59,
     418,   419,   -59,   862,  1149,  1036,   843,  1167,   549,   677,
     -59,   769,   711,   -59,   869,   706,  -375,   708,   446,   884,
     408,   841,   -59,   405,   434,   -59,  -373,   861,   352,   862,
      38,   385,   408,  -170,   852,   452,   723,   378,   549,   453,
    1040,   724,  1057,  -372,   325,  1061,   410,   411,   330,   149,
     261,  -173,   873,  1048,   875,   331,   884,  -170,   386,   884,
      38,   960,  -368,   332,  -358,   541,   418,   419,  -368,   542,
    -358,   385,  1128,  -269,  -375,   556,   869,   281,   367,   368,
    -326,  -369,   325,   325,  -373,  -371,  -326,   279,   295,   146,
     147,   618,   728,   618,   326,  -370,  1162,   764,   386,   325,
     737,  -372,   765,   262,  -116,   333,  -359,   518,   387,   435,
    -327,  -374,  -359,   400,  -375,  1162,  -327,  1176,   469,   412,
    -116,  -116,  1077,  1094,   518,   513,  1108,  1176,   325,   334,
     325,  -350,   326,   326,   335,  -348,   838,  -350,   336,  -369,
     884,  -348,   337,  -371,   511,  -349,  1105,   458,   387,   326,
     338,  -349,  -373,  -370,   385,  -372,   123,  1166,   406,   766,
    -360,  -353,  -314,   279,  -354,   401,  -360,  -353,   115,  -374,
    -354,  1174,  -375,  1166,   339,   514,   869,   549,   326,   408,
     326,   386,   405,  -361,   680,  1180,   835,  -362,   325,  -361,
     803,   804,   805,  -362,   869,   288,   289,   290,   291,   292,
     293,   294,  -352,   838,   340,  -351,  -363,   554,  -352,   341,
    -373,  -351,  -363,  -372,  -364,  1127,   392,   385,  -365,   342,
    -364,   260,   260,   513,  -365,   325,   343,   260,   260,   260,
     973,   387,   627,   838,   344,   631,   523,  1097,   326,   239,
      33,   930,   511,  -366,   386,  1156,   345,  1157,   260,  -366,
     869,   814,   259,   835,   815,  -324,  -367,   646,  1158,   385,
     581,  1159,  -367,   258,   258,   961,   618,   618,  -314,   258,
     258,   258,   400,   514,   346,   326,    38,     5,   347,   351,
    1170,  1171,   628,   835,  1030,   514,   681,   631,  1142,   392,
     258,  1143,   418,   419,   387,   374,   823,   325,   430,   325,
     325,    38,   385,   446,   513,   702,   683,   953,   954,   955,
      21,    22,   460,   513,   464,   325,   260,   406,   693,   392,
    -152,   413,   506,   511,   279,   244,   412,   525,    16,   386,
     532,   632,   511,   261,   261,   627,   682,   514,   646,   261,
     261,   261,   633,  1126,   649,   653,   654,   326,   656,   326,
     326,   657,   658,  1059,   514,   659,   813,   660,   258,   697,
     261,   661,   662,   514,   663,   326,   664,   665,   666,   259,
     669,   667,   350,   668,   670,   950,  1126,   353,   684,   387,
     743,  -314,  -254,   573,   260,   628,   262,   262,   727,   610,
     733,   885,   262,   262,   262,   379,   741,   734,   736,   354,
     397,   881,   757,   760,   768,   409,   771,   772,   773,   618,
     777,   779,   753,   262,   427,   428,   776,   780,   781,  1112,
     784,   724,   811,   816,   818,   825,   258,   821,   261,   840,
     744,   385,   288,   289,   290,   291,   292,   293,   294,   824,
     842,   385,   858,   888,   325,   876,   765,   892,   893,   916,
     325,   896,   898,   899,   919,   447,   922,   449,   681,   288,
     289,   290,   291,   292,   293,   294,  1041,   905,   386,   923,
     937,   610,   457,   940,   942,   981,   984,    33,   986,   745,
     987,   262,   988,  1031,   989,   990,   991,   992,   993,   994,
     995,  1086,  1144,   996,   326,  1034,   261,  1161,  -320,  1051,
     326,  1054,  1062,  1063,  1065,   549,  1067,  1068,   682,  1085,
    1093,  1098,  1102,  1104,   325,   325,   325,   324,   387,  1107,
     610,  1111,  1163,  1113,  1165,  1114,  1179,  1115,  1135,  1151,
      89,  1002,  1006,  1028,  1091,  1008,   581,   921,   610,  1009,
    1175,   928,  1010,  1118,   758,   894,  1011,   759,   970,   262,
     524,   111,   448,  1014,   450,   379,   581,   397,  1125,  1073,
     703,   933,  1095,  1129,   326,   326,   326,  1018,   505,   672,
     958,   505,   549,   549,   671,  1178,   952,   537,   817,   539,
     749,   567,   568,  1024,   872,   581,   581,   581,  1049,   967,
     726,  1039,   932,     0,   465,     0,   325,     0,     0,     0,
       0,   560,     0,   569,     0,   393,   549,   396,   398,    17,
      18,    19,   260,     0,     0,     0,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,   277,     0,     0,   622,
     623,     0,   522,     0,     0,     0,     0,     0,     0,     0,
       0,   392,     0,     0,     0,     0,   326,     0,   529,   582,
       0,     0,   259,   259,   258,     0,     0,   627,   259,   259,
     259,     0,     0,     0,     0,     0,     0,   505,     0,   505,
       0,     0,     0,     0,   538,     0,   540,     0,   408,   259,
     543,   405,     0,   404,     0,  1087,     0,   560,     0,  1101,
     564,   565,   566,   127,   357,   325,  1004,     0,   581,   325,
       0,   325,     0,     0,   581,   581,   581,   628,     0,   104,
       0,     0,  1021,     0,     0,  1084,  1012,     0,   615,    99,
       0,   710,     0,  1013,   261,     0,     0,     0,   136,     0,
       0,   408,     0,     0,   405,     0,     0,     0,  1087,   408,
       0,  1160,   405,   128,     0,   326,  1087,   259,   560,   326,
    1168,   326,     0,   357,     0,     0,     0,   505,   287,   505,
     581,     0,     0,     0,   396,   398,     0,     0,     0,   385,
       0,   400,   127,  1120,   325,   402,   673,   262,     0,   408,
       0,     0,   405,   679,     0,     0,  1087,     0,   127,   505,
     581,  1078,  1022,   323,   465,     0,   386,   127,  1070,     0,
       0,   325,  1072,   457,     0,   396,   398,  1021,     0,     0,
       0,  1080,     0,   403,    99,   259,  1088,     0,  1081,   260,
    1042,   715,   128,   401,   326,     0,   720,     0,     0,     0,
     512,     0,   400,   365,   391,     0,   385,     0,   128,     0,
       0,   377,   505,   505,     0,     0,   387,   128,   392,     0,
     127,   326,     0,     0,     0,     0,   127,     0,   127,  1078,
     581,   258,     0,   386,   627,   533,   534,   535,     0,     0,
     581,  1075,   400,  1117,     0,  1021,  1121,  1088,   581,  1080,
       0,   392,   279,     0,   401,     0,  1081,  1083,     0,     0,
       0,   513,     0,     0,     0,   122,     0,   627,   127,   767,
     128,   260,     0,     0,   120,     0,   128,     0,   128,   407,
     511,     0,     0,   387,   628,     0,     0,  1088,     0,     0,
    1147,   513,     0,   513,   279,   582,     0,   322,   512,     0,
     505,   261,     0,     0,   581,     0,   321,   581,     0,   513,
     511,   514,   511,   258,     0,   582,  1119,   628,   128,   260,
     260,     0,     0,   812,     0,  1123,     0,   260,   511,     0,
       0,     0,     0,     0,     0,   819,     0,   581,   260,     0,
       0,   514,     0,   514,   582,   582,   582,     0,     0,     0,
       0,     0,     0,     0,   262,   384,     0,     0,   394,   514,
       0,   258,   258,   396,   398,   925,     0,     0,     0,   258,
       0,     0,     0,     0,     0,     0,     0,   934,     0,   512,
     258,     0,     0,   261,     0,     0,   395,     0,   512,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   477,     0,     0,
       0,   481,   482,   259,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,     0,     0,
     391,   261,   261,   976,   407,     0,   262,     0,     0,   261,
       0,     0,     0,     0,   918,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,   365,   927,   582,     0,     0,
       0,     0,     0,   582,   582,   582,     0,   936,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   396,     0,     0,   262,   262,     0,     0,     0,     0,
       0,     0,   262,     0,     0,     0,   504,     0,     0,   504,
       0,     0,     0,   262,     0,     0,     0,     0,     0,     0,
       0,     0,   407,     0,     0,   451,     0,     0,  1052,   582,
       0,     0,     0,     0,   407,     0,     0,   975,   391,   322,
       0,   534,   535,     0,     0,     0,     0,     0,   445,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   582,
       0,     0,   829,     0,     0,   451,   394,     0,   650,   651,
     652,   377,     0,   655,     0,  1026,   505,   322,   322,     0,
       0,     0,     0,     0,     0,     0,   462,   463,  1089,     0,
    1090,     0,  1092,  1038,   395,     0,     0,     0,     0,     0,
       0,   391,     0,   396,   398,   504,   687,   504,    21,    22,
      23,    24,    25,    26,    27,    28,    29,   498,   277,   391,
       0,     0,     0,   322,     0,   322,     0,   499,   391,   582,
     259,     0,   520,     0,   521,     0,     0,     0,     0,   582,
       0,  1122,     0,     0,     0,     0,     0,   582,   384,     0,
       0,     0,   505,     0,     0,   553,     0,  1132,     0,     0,
       0,     0,     0,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
       0,   407,     0,     0,     0,     0,     0,     0,  1152,     0,
       0,     0,     0,     0,     0,   504,     0,   504,     0,   626,
       0,     0,     0,   582,     0,     0,   582,     0,     0,     0,
       0,   451,   259,     0,     0,     0,     0,     0,     0,     0,
     322,     0,     0,  1116,     0,     0,     0,   504,     0,   621,
     630,     0,   505,     0,     0,     0,   582,     0,     0,  1124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1130,   505,     0,     0,  1133,     0,  1134,     0,   785,
     259,   259,     0,     0,     0,     0,   692,     0,   259,     0,
    1146,     0,     0,   391,  1148,     0,     0,     0,  1150,   259,
     504,   504,   635,   820,     0,     0,     0,     0,  1153,     0,
       0,     0,   322,     0,     0,   322,   692,     0,     0,     0,
    1164,   691,   626,     0,   696,     0,     0,     0,     0,     0,
     322,     0,     0,     0,     0,     0,     0,     0,     0,   709,
       0,     0,     0,   636,   637,     0,     0,     0,     0,     0,
     202,   203,   204,   638,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,     0,     0,     0,     0,     0,     0,   324,
       0,     0,     0,     0,     0,     0,     0,     0,   504,     0,
       0,     0,     0,   897,     0,   742,     0,     0,     0,     0,
       0,   900,     0,     0,     0,   902,   903,     0,     0,   906,
     907,   908,   909,   910,   911,   912,   913,   914,   915,     0,
       0,     0,     0,   407,     0,   687,     0,   639,     0,   640,
     641,     0,   642,   643,     0,   246,   247,   248,   644,   250,
     251,   252,   253,   254,   255,   256,     0,     0,     0,     0,
       0,   938,     0,     0,     0,   692,     0,     0,     0,   322,
       0,     0,     0,     0,     0,   322,     0,     0,   796,     0,
       6,     7,     8,     9,    10,    11,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,     0,   512,     0,    21,    22,
      23,    24,    25,    26,    27,    28,    29,   997,   998,    31,
      32,     0,     0,     0,     0,    33,    34,    35,     0,   999,
       0,     0,     0,     0,   982,     0,   512,   985,   512,   322,
     322,   322,     0,     0,     0,     0,     0,     0,   878,   879,
     880,  1023,     0,     0,   512,     0,     0,     0,     0,     0,
       0,    38,     0,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    1000,  1001,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   322,    87,     0,     0,     0,     0,     0,     0,     0,
     696,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   297,   298,   299,   300,   301,   302,
     303,     0,     0,     0,   626,     0,     0,     0,     0,     0,
       0,   304,   305,   306,   504,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   297,   298,   299,   300,   301,   302,
     303,     0,     0,    31,   380,     0,     0,     0,     0,    33,
    1020,   304,   305,   306,    16,     0,     0,     0,     0,   803,
     804,   805,     0,     0,     0,     0,     0,   806,     0,     0,
     407,     0,     0,     0,     0,     0,     0,     0,   122,    33,
     322,     0,     0,     0,   322,     0,   322,  1019,     0,  1025,
     407,     0,     0,  1027,     0,     0,   391,     0,     0,     0,
     504,     0,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,    38,     0,     0,     0,     0,
       0,     0,     0,   407,     0,     0,   391,     0,   391,  1074,
       0,   407,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,   391,  1074,    87,     0,     0,     0,
       0,     0,     0,   451,  1074,     0,     0,     0,     0,   322,
       0,     0,     0,     0,     0,     0,     0,   407,   321,     0,
       0,   407,     0,     0,     0,     0,    87,     0,     0,     0,
     504,     0,     0,     0,     0,     0,   322,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     504,     0,     0,     0,     0,     0,     0,  1074,     0,     0,
       0,     0,     0,  1074,     0,  1074,     0,     0,     0,     0,
     451,   553,     0,     0,     0,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   692,  1074,   179,   180,   181,   182,
     183,   184,     0,   185,   186,   187,   188,     0,     0,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   596,   239,     0,   240,
     241,   242,   243,     0,   597,   245,   598,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,     0,     0,
     179,   180,   181,   182,   183,   184,     0,   185,   186,   187,
     188,     0,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     596,   239,   602,   240,   241,   242,   243,     0,   597,   245,
       0,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,     0,     0,   179,   180,   181,   182,   183,   184,
       0,   185,   186,   187,   188,     0,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   596,   239,     0,   240,   241,   242,
     243,     0,   597,   245,   608,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,     0,     0,   179,   180,
     181,   182,   183,   184,     0,   185,   186,   187,   188,     0,
       0,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   596,   239,
       0,   240,   241,   242,   243,   611,   597,   245,     0,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
       0,     0,   179,   180,   181,   182,   183,   184,     0,   185,
     186,   187,   188,     0,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   596,   239,   629,   240,   241,   242,   243,     0,
     597,   245,     0,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,     0,     0,   179,   180,   181,   182,
     183,   184,     0,   185,   186,   187,   188,     0,     0,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   596,   239,   698,   240,
     241,   242,   243,     0,   597,   245,     0,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,     0,     0,
     179,   180,   181,   182,   183,   184,     0,   185,   186,   187,
     188,     0,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     596,   239,   935,   240,   241,   242,   243,     0,   597,   245,
       0,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,     0,     0,   179,   180,   181,   182,   183,   184,
       0,   185,   186,   187,   188,     0,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   596,   239,  1172,   240,   241,   242,
     243,     0,   597,   245,     0,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,     0,     0,   179,   180,
     181,   182,   183,   184,     0,   185,   186,   187,   188,     0,
       0,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   596,   239,
    1177,   240,   241,   242,   243,     0,   597,   245,     0,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
       0,     0,   179,   180,   181,   182,   183,   184,     0,   185,
     186,   187,   188,     0,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   609,   239,     0,   240,   241,   242,   243,     0,
     597,   245,     0,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,     0,     0,   179,   180,   181,   182,
     183,   184,     0,   185,   186,   187,   188,     0,     0,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   735,   239,     0,   240,
     241,   242,   243,     0,   597,   245,     0,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,     0,     0,
     179,   180,   181,   182,   183,   184,     0,   185,   186,   187,
     188,     0,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   239,     0,   240,   241,   242,   243,  1141,   597,   245,
       0,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,     0,     0,   179,   180,   181,   182,   183,   184,
       0,   185,   186,   187,   188,     0,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1173,   239,     0,   240,   241,   242,
     243,     0,   597,   245,     0,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,     0,     0,   179,   180,
     181,   182,   183,   184,     0,   185,   186,   187,   188,     0,
       0,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1181,   239,
       0,   240,   241,   242,   243,     0,   597,   245,     0,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
       0,     0,   179,   180,   181,   182,   183,   184,     0,   185,
     186,   187,   188,     0,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   239,     0,   240,   241,   242,   243,     0,
     244,   245,     0,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   150,   151,   152,   153,   154,
     155,   156,   441,   442,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   570,   171,   172,   173,   174,
     175,   176,   177,   178,     0,     0,   179,   180,   181,   182,
     183,   184,     0,   185,   186,   187,   188,     0,     0,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   571,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,     0,   572,     0,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   965,   573,   966,   574,
     575,   576,   443,     0,   577,   578,     0,   246,   247,   248,
     579,   250,   251,   252,   253,   254,   255,   256,   580,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,     0,     0,
     179,   180,   181,   182,   183,   184,     0,   185,   186,   187,
     188,     0,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   239,     0,   240,   241,   242,   243,     0,   597,   245,
       0,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,     0,     0,   179,   180,   181,   182,   183,   184,
       0,   185,   186,   187,   188,     0,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,     0,   240,   241,   242,
     243,     0,     0,   245,     0,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   150,   151,   152,
     153,   154,   155,   156,   441,   442,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   570,   171,   172,
     173,   174,   175,   176,   177,   178,     0,     0,   179,   180,
     181,   182,   183,   184,     0,   185,   186,   187,   188,     0,
       0,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   571,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,     0,   572,     0,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   573,
       0,   574,   575,   576,   443,   889,   577,   578,     0,   246,
     247,   248,   579,   250,   251,   252,   253,   254,   255,   256,
     580,   150,   151,   152,   153,   154,   155,   156,   441,   442,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   570,   171,   172,   173,   174,   175,   176,   177,   178,
       0,     0,   179,   180,   181,   182,   183,   184,     0,   185,
     186,   187,   188,     0,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   571,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,     0,   572,     0,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   573,     0,   574,   575,   576,   443,   890,
     577,   578,     0,   246,   247,   248,   579,   250,   251,   252,
     253,   254,   255,   256,   580,   150,   151,   152,   153,   154,
     155,   156,   441,   442,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   570,   171,   172,   173,   174,
     175,   176,   177,   178,     0,     0,   179,   180,   181,   182,
     183,   184,     0,   185,   186,   187,   188,     0,     0,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   571,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,     0,   572,     0,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   573,     0,   574,
     575,   576,   443,   891,   577,   578,     0,   246,   247,   248,
     579,   250,   251,   252,   253,   254,   255,   256,   580,   150,
     151,   152,   153,   154,   155,   156,   441,   442,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   570,
     171,   172,   173,   174,   175,   176,   177,   178,     0,     0,
     179,   180,   181,   182,   183,   184,     0,   185,   186,   187,
     188,     0,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   571,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,     0,
     572,     0,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   573,     0,   574,   575,   576,   443,     0,   577,   578,
     964,   246,   247,   248,   579,   250,   251,   252,   253,   254,
     255,   256,   580,   150,   151,   152,   153,   154,   155,   156,
     441,   442,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   570,   171,   172,   173,   174,   175,   176,
     177,   178,     0,     0,   179,   180,   181,   182,   183,   184,
       0,   185,   186,   187,   188,     0,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   571,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,     0,   572,     0,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   573,     0,   574,   575,   576,
     443,     0,   577,   578,   969,   246,   247,   248,   579,   250,
     251,   252,   253,   254,   255,   256,   580,   150,   151,   152,
     153,   154,   155,   156,   441,   442,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   570,   171,   172,
     173,   174,   175,   176,   177,   178,     0,     0,   179,   180,
     181,   182,   183,   184,     0,   185,   186,   187,   188,     0,
       0,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   571,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,     0,   572,     0,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   573,
       0,   574,   575,   576,   443,     0,   577,   578,     0,   246,
     247,   248,   579,   250,   251,   252,   253,   254,   255,   256,
     580,   150,   151,   152,   153,   154,   155,   156,   441,   442,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   570,   171,   172,   173,   174,   175,   176,   177,   178,
       0,     0,   179,   180,   181,   182,   183,   184,     0,   185,
     186,   187,   188,     0,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   434,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,     0,   572,     0,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   573,     0,   832,   575,   833,   443,     0,
     834,   578,     0,   246,   247,   248,   435,   250,   251,   252,
     253,   254,   255,   256,   580,  -618,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,     0,     0,  -618,  -618,  -618,  -618,
    -618,  -618,     0,  -618,  -618,  -618,  -618,     0,     0,  -618,
    -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,     0,  -618,     0,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -618,     0,  -654,
    -618,  -618,  -618,     0,  -618,  -618,     0,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,   150,
     151,   152,   153,   154,   155,   156,   441,   442,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   570,
     171,   172,   173,   174,   175,   176,   177,   178,     0,     0,
     179,   180,   181,   182,   183,   184,     0,   185,   186,   187,
     188,     0,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   864,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,     0,
     572,     0,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   573,     0,     0,   575,     0,   443,     0,   865,   578,
       0,   246,   247,   248,   866,   250,   251,   252,   253,   254,
     255,   256,   580,   150,   151,   152,   153,   154,   155,   156,
     441,   442,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   570,   171,   172,   173,   174,   175,   176,
     177,   178,     0,     0,   179,   180,   181,   182,   183,   184,
       0,   185,   186,   187,   188,     0,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,     0,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,     0,   572,     0,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   573,     0,     0,   575,     0,
     443,     0,   834,   578,     0,   246,   247,   248,     0,   250,
     251,   252,   253,   254,   255,   256,   580,   150,   151,   152,
     153,   154,   155,   156,   441,   442,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   570,   171,   172,
     173,   174,   175,   176,   177,   178,     0,     0,   179,   180,
     181,   182,   183,   184,     0,   185,   186,   187,   188,     0,
       0,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,     0,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,     0,     0,     0,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   573,
       0,     0,   575,     0,   443,     0,     0,   578,     0,   246,
     247,   248,     0,   250,   251,   252,   253,   254,   255,   256,
     580,   270,   271,   272,   273,   274,   275,   276,     0,     0,
     635,     0,     0,     0,     0,     0,     0,     0,   167,   168,
     169,     0,    17,    18,    19,    20,     0,     0,     0,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     0,   277,
       0,     0,     0,     0,     0,     0,    33,    34,     0,     0,
       0,   636,   637,     0,     0,     0,     0,     0,   202,   203,
     204,   638,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,     0,    38,     0,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     470,   471,   472,   473,   474,   475,   476,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   304,   305,   306,
       0,     0,     0,     0,     0,   639,     0,   640,   641,     0,
     642,   643,     0,   246,   247,   248,   644,   250,   251,   252,
     253,   254,   255,   256,     6,     7,     8,     9,    10,    11,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,    15,    16,    17,    18,    19,    20,     0,
       0,     0,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     0,    30,    31,    32,     0,     0,     0,     0,    33,
      34,    35,    36,    37,     0,     0,     0,     0,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     0,    86,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,    87,     0,     0,     0,
       0,     0,     0,    13,    14,    15,     0,    17,    18,    19,
      20,     0,     0,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     0,   277,    31,   354,     0,     0,     0,
       0,    33,    34,     0,     0,   355,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,     0,     0,     0,     0,
       0,     6,     7,     8,     9,    10,    11,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    14,
      15,     0,    17,    18,    19,    20,     0,     0,    87,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     0,   277,
      31,   354,     0,     0,     0,     0,    33,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,    15,     0,    17,    18,    19,
      20,     0,     0,    87,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     0,   277,    31,     0,     0,     0,     0,
       0,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,     0,     0,     0,     0,
       0,     6,     7,     8,     9,    10,    11,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    14,
      15,     0,    17,    18,    19,    20,     0,     0,    87,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     0,   277,
      31,     0,     0,     0,     0,     0,    33,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,   297,   298,   299,   300,   301,   302,   303,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   304,   305,
     306,     0,     0,     0,     0,     0,   803,   804,   805,     0,
       0,     0,     0,    87,   806,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,   297,   298,   299,
     300,   301,   302,   303,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   304,   305,   306,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,     0,     0,     0,     0,     0,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,   297,   298,   299,   300,   301,   302,   303,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,   304,
     305,   306,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,     0,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,    33,   307,     0,
     308,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   517,     0,
       0,     0,   518,     0,     0,     0,     0,     0,     0,    87,
       0,     0,     0,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   297,   298,   299,   300,   301,   302,   303,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   304,   305,
     306,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,   297,   298,   299,
     300,   301,   302,   303,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   304,   305,   306,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,     0,     0,     0,     0,     0,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,   297,   298,   299,   300,   301,   302,   303,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,   304,
     305,   306,     0,     0,     0,     0,   518,     0,     0,     0,
       0,     0,     0,    87,     0,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     0,    33,   307,   297,
     298,   299,   300,   301,   302,   303,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   304,   305,   306,     0,
       0,   297,   298,   299,   300,   301,   302,   303,     0,    87,
       0,     0,     0,    38,     0,     0,     0,     0,   304,   305,
     306,     0,     0,     0,    33,     0,     0,     0,     0,     0,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   380,     0,     0,     0,     0,    33,     0,     0,   297,
     298,   299,   300,   301,   302,   303,     0,     0,     0,     0,
      38,     0,     0,     0,     0,     0,   304,   305,   306,     0,
       0,     0,     0,     0,    87,     0,     0,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,    31,     0,
       0,     0,     0,     0,    33,     0,     0,     0,     0,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
       0,     0,     0,   297,   298,   299,   300,   301,   302,   303,
       0,    87,     0,     0,     0,     0,     0,     0,     0,     0,
     304,   305,   306,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,     0,     0,     0,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,    33,   297,
     298,   299,   300,   301,   302,   303,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   304,   305,   306,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,     0,     0,     0,     0,     0,
       0,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,   297,   298,   299,   300,   301,   302,
     303,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,   304,   305,   306,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,     0,    33,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     507,  1142,     0,     0,  1143,   297,   298,   299,   300,   301,
     302,   303,     0,     0,     0,    38,     0,     0,     0,     0,
       0,     0,   304,   305,   306,    16,     0,     0,     0,     0,
       0,     0,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   297,   298,   299,   300,   301,   302,   303,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     304,   305,   306,    16,     0,   507,     0,     0,     0,   508,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1142,     0,     0,
    1143,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,    21,    22,    23,    24,    25,    26,    27,    28,
      29,   498,   277,     0,     0,     0,     0,     0,     0,     0,
       0,   499,     0,     0,     0,     0,     0,     0,   508,     0,
      21,    22,    23,    24,    25,    26,    27,    28,    29,   498,
     277,     0,     0,     0,     0,     0,     0,     0,   417,   499,
       0,     0,     0,     0,     0,     0,     0,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,     0,     0,   417,     0,     0,     0,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,     0,     0,     0,  -273,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   418,   419,   270,
     271,   272,   273,   274,   275,   276,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   167,   168,   169,     0,
      17,    18,    19,    20,     0,   418,   419,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     0,   277,    31,   354,
       0,     0,     0,     0,    33,    34,     0,     0,   355,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   270,   271,
     272,   273,   274,   275,   276,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   168,   169,     0,    17,
      18,    19,    20,     0,     0,     0,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,   277,    31,     0,     0,
       0,     0,     0,    33,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   270,   271,   272,
     273,   274,   275,   276,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   167,   168,   169,     0,    17,    18,
      19,    20,     0,     0,     0,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,   277,    31,     0,     0,     0,
       0,     0,    33,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   270,   271,   272,   273,
     274,   275,   276,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,   169,     0,    17,    18,    19,
      20,     0,     0,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     0,   277,     0,     0,     0,     0,     0,
       0,    33,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   270,   271,   272,   273,   274,
     275,   276,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   167,   168,   169,     0,   739,     0,   740,    20,
       0,     0,     0,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     0,   277,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   270,   271,   272,   273,   274,   275,
     276,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   168,   169,     0,     0,     0,     0,     0,     0,
       0,     0,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     0,   277,     0,     0,     0,     0,     0,     0,    33,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   297,   298,   299,   300,   301,   302,   303,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     304,   305,   306,    16,   297,   298,   299,   300,   301,   302,
     303,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   304,   305,   306,     0,     0,     0,     0,    33,   297,
     298,   299,   300,   301,   302,   303,     0,     0,     0,     0,
       0,     0,     0,     0,   380,     0,   304,   305,   306,    33,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,     0,     0,     0,     0,     0,
       0,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319
};

static const short int yycheck[] =
{
       5,   137,   123,     5,    35,   431,   123,   131,    35,   268,
     131,   110,   131,   323,   416,    36,     5,   124,   439,     5,
     704,   603,   705,     5,   714,   457,     5,   323,   554,   430,
       5,     5,    37,   113,   114,   115,   287,   520,   696,   752,
     449,    32,   972,   845,   448,   867,    35,   746,   545,   351,
       5,    37,   554,   752,   977,   323,    35,     3,   239,     3,
      10,    11,     3,   134,   245,    10,    11,     3,    32,   140,
     946,   918,   705,    23,   552,    10,    11,    84,    63,  1106,
      23,    84,    37,    32,    10,    11,   267,     3,    84,   140,
      63,   123,   725,    23,   929,    28,    29,    30,     3,     5,
     131,    23,    25,   124,   131,   134,    23,    18,     0,  1136,
       3,   140,    84,    23,   295,     0,    23,   413,   123,   124,
       3,   126,   134,   705,   110,   529,    49,    77,   140,    35,
     140,   110,    23,    83,   538,   142,   110,   939,   621,   142,
     830,    12,   131,    54,    55,   131,   142,   625,    31,   142,
     997,    77,   131,    32,   612,   613,   614,    83,   149,   469,
     140,    44,   286,   148,    47,   416,  1042,   693,   123,   124,
     142,   126,    43,   469,   595,   148,     3,     4,     5,     6,
       7,     8,     9,    66,   897,   149,  1109,   368,   134,   135,
     134,   693,   138,   134,   137,   140,   146,   147,   897,   135,
     149,   469,   138,   136,   110,   140,    32,  1029,  1138,    45,
     140,   895,  1047,   622,   623,   712,   138,    77,   134,   135,
     146,   147,   138,   140,   134,   938,   709,   134,   524,   134,
     135,   632,   729,   138,   867,   537,    84,   539,    12,   938,
     364,   134,   135,   364,    63,   138,    84,   138,   135,   140,
      84,   283,   376,    25,   137,   286,   134,   134,   554,   286,
     944,   139,   975,    84,   269,   978,    10,    11,   140,    43,
     149,    43,   730,   957,   732,   140,   975,    49,   283,   978,
      84,  1103,   134,   140,   134,   406,   146,   147,   140,   406,
     140,   323,  1094,   135,   142,   137,   929,   286,   134,   135,
     134,    84,   307,   308,   142,    84,   140,   286,   135,    24,
      25,   447,   563,   449,   269,    84,  1144,   134,   323,   324,
     139,   142,   139,   149,   135,   140,   134,   138,   283,   148,
     134,    84,   140,   364,    84,  1163,   140,  1165,   324,    83,
     134,   135,  1000,  1033,   138,   350,  1059,  1175,   353,   140,
     355,   134,   307,   308,   140,   134,  1039,   140,   140,   142,
    1059,   140,   140,   142,   350,   134,  1050,   618,   323,   324,
     140,   140,    84,   142,   406,    84,   362,  1148,   364,   140,
     134,   134,   143,   362,   134,   364,   140,   140,   362,   142,
     140,  1162,   142,  1164,   140,   350,  1029,   693,   353,   523,
     355,   406,   523,   134,   511,  1176,  1039,   134,   413,   140,
      28,    29,    30,   140,  1047,     3,     4,     5,     6,     7,
       8,     9,   134,  1106,   140,   134,   134,   413,   140,   140,
     142,   140,   140,   142,   134,  1093,   457,   469,   134,   140,
     140,   432,   433,   448,   140,   450,   140,   438,   439,   440,
     882,   406,   457,  1136,   140,   460,   362,  1039,   413,   135,
      48,   137,   448,   134,   469,    31,   140,    33,   459,   140,
    1103,   136,    32,  1106,   139,   134,   134,   468,    44,   511,
     429,    47,   140,   432,   433,   140,   622,   623,   143,   438,
     439,   440,   523,   448,   140,   450,    84,     4,   140,   102,
    1158,  1159,   457,  1136,   930,   460,   511,   512,   135,   530,
     459,   138,   146,   147,   469,   140,   697,   522,   135,   524,
     525,    84,   554,    12,   529,   530,   512,    13,    14,    15,
      31,    32,   137,   538,   134,   540,   527,   523,   524,   560,
     134,   136,   135,   529,   523,   142,    83,   138,    23,   554,
     140,   135,   538,   432,   433,   560,   511,   512,   549,   438,
     439,   440,   134,  1089,   139,   139,   139,   522,   139,   524,
     525,   139,   139,   975,   529,   139,   683,   139,   527,   135,
     459,   139,   139,   538,   139,   540,   139,   139,   139,   149,
     139,   141,    99,   141,   134,   854,  1122,   104,   134,   554,
     605,   143,   141,   135,   595,   560,   432,   433,   141,  1030,
     144,   747,   438,   439,   440,   122,   605,   136,   144,    43,
     127,   745,   134,   134,   134,   132,     3,   143,   143,   765,
     144,   139,   607,   459,   141,   142,   141,   141,   141,  1065,
     139,   139,   138,   137,   134,    83,   595,   139,   527,   134,
     605,   683,     3,     4,     5,     6,     7,     8,     9,   141,
     134,   693,   143,    25,   669,   144,   139,   134,   134,   139,
     675,   136,   144,   144,   138,   278,   139,   280,   683,     3,
       4,     5,     6,     7,     8,     9,   945,   141,   693,    36,
     139,  1112,   287,   141,   134,   141,   141,    48,   141,   605,
     141,   527,   141,   134,   141,   141,   141,   141,   141,   139,
     139,  1021,  1116,   141,   669,    83,   595,  1143,   144,   144,
     675,   137,   141,   134,   139,  1021,    13,    13,   683,   134,
      46,   141,   144,   141,   739,   740,   741,    37,   693,   141,
    1161,   141,  1146,   141,  1148,   141,  1172,   141,   141,   135,
       5,   918,   918,   926,  1026,   918,   705,   806,  1179,   918,
    1164,   815,   918,  1072,   617,   765,   918,   618,   877,   595,
     365,     5,   279,   918,   281,   282,   725,   284,  1088,   997,
     531,   821,  1035,  1096,   739,   740,   741,   918,   348,   502,
     863,   351,  1088,  1089,   501,  1169,   859,   400,   688,   402,
     605,   425,   425,   918,   729,   754,   755,   756,   959,   874,
     559,   941,   820,    -1,   321,    -1,   821,    -1,    -1,    -1,
      -1,   416,    -1,   426,    -1,   125,  1122,   127,   128,    24,
      25,    26,   823,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,    -1,    -1,   452,
     453,    -1,   359,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   882,    -1,    -1,    -1,    -1,   821,    -1,   375,   429,
      -1,    -1,   432,   433,   823,    -1,    -1,   882,   438,   439,
     440,    -1,    -1,    -1,    -1,    -1,    -1,   447,    -1,   449,
      -1,    -1,    -1,    -1,   401,    -1,   403,    -1,  1022,   459,
     407,  1022,    -1,  1022,    -1,  1022,    -1,   502,    -1,  1045,
     417,   418,   419,   918,  1013,   920,   918,    -1,   867,   924,
      -1,   926,    -1,    -1,   873,   874,   875,   882,    -1,   918,
      -1,    -1,   918,    -1,    -1,  1015,   918,    -1,   445,   918,
      -1,   544,    -1,   918,   823,    -1,    -1,    -1,     5,    -1,
      -1,  1075,    -1,    -1,  1075,    -1,    -1,    -1,  1075,  1083,
      -1,  1142,  1083,   918,    -1,   920,  1083,   527,   563,   924,
    1151,   926,    -1,  1072,    -1,    -1,    -1,   537,    35,   539,
     929,    -1,    -1,    -1,   284,   285,    -1,    -1,    -1,  1021,
      -1,  1022,   997,  1073,   999,  1022,   503,   823,    -1,  1123,
      -1,    -1,  1123,   510,    -1,    -1,  1123,    -1,  1013,   569,
     959,  1013,   918,   999,   521,    -1,  1021,  1022,   997,    -1,
      -1,  1026,   997,   618,    -1,   325,   326,  1013,    -1,    -1,
      -1,  1013,    -1,  1022,  1013,   595,  1022,    -1,  1013,  1030,
     946,   548,   997,  1022,   999,    -1,   553,    -1,    -1,    -1,
     350,    -1,  1083,   110,   124,    -1,  1088,    -1,  1013,    -1,
      -1,   118,   622,   623,    -1,    -1,  1021,  1022,  1089,    -1,
    1075,  1026,    -1,    -1,    -1,    -1,  1081,    -1,  1083,  1081,
    1029,  1030,    -1,  1088,  1089,   385,   386,   387,    -1,    -1,
    1039,   997,  1123,  1072,    -1,  1081,  1075,  1083,  1047,  1081,
      -1,  1122,  1081,    -1,  1083,    -1,  1081,  1013,    -1,    -1,
      -1,  1116,    -1,    -1,    -1,     5,    -1,  1122,  1123,   626,
    1075,  1112,    -1,    -1,     5,    -1,  1081,    -1,  1083,   131,
    1116,    -1,    -1,  1088,  1089,    -1,    -1,  1123,    -1,    -1,
    1119,  1146,    -1,  1148,  1123,   705,    -1,    37,   448,    -1,
     710,  1030,    -1,    -1,  1103,    -1,    37,  1106,    -1,  1164,
    1146,  1116,  1148,  1112,    -1,   725,  1072,  1122,  1123,  1160,
    1161,    -1,    -1,   680,    -1,  1081,    -1,  1168,  1164,    -1,
      -1,    -1,    -1,    -1,    -1,   692,    -1,  1136,  1179,    -1,
      -1,  1146,    -1,  1148,   754,   755,   756,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1030,   123,    -1,    -1,   126,  1164,
      -1,  1160,  1161,   513,   514,   810,    -1,    -1,    -1,  1168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   822,    -1,   529,
    1179,    -1,    -1,  1112,    -1,    -1,   126,    -1,   538,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   327,    -1,    -1,
      -1,   331,   332,   823,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,    -1,    -1,
     350,  1160,  1161,   886,   286,    -1,  1112,    -1,    -1,  1168,
      -1,    -1,    -1,    -1,   801,    -1,    -1,    -1,    -1,    -1,
    1179,    -1,    -1,    -1,    -1,   362,   813,   867,    -1,    -1,
      -1,    -1,    -1,   873,   874,   875,    -1,   824,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   631,    -1,    -1,  1160,  1161,    -1,    -1,    -1,    -1,
      -1,    -1,  1168,    -1,    -1,    -1,   348,    -1,    -1,   351,
      -1,    -1,    -1,  1179,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   364,    -1,    -1,   283,    -1,    -1,   971,   929,
      -1,    -1,    -1,    -1,   376,    -1,    -1,   884,   448,   269,
      -1,   681,   682,    -1,    -1,    -1,    -1,    -1,   269,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   959,
      -1,    -1,   702,    -1,    -1,   323,   324,    -1,   478,   479,
     480,   468,    -1,   483,    -1,   922,   976,   307,   308,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   307,   308,  1023,    -1,
    1025,    -1,  1027,   940,   324,    -1,    -1,    -1,    -1,    -1,
      -1,   511,    -1,   743,   744,   447,   516,   449,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,   529,
      -1,    -1,    -1,   353,    -1,   355,    -1,    50,   538,  1029,
    1030,    -1,   353,    -1,   355,    -1,    -1,    -1,    -1,  1039,
      -1,  1076,    -1,    -1,    -1,    -1,    -1,  1047,   406,    -1,
      -1,    -1,  1052,    -1,    -1,   413,    -1,  1100,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
      -1,   523,    -1,    -1,    -1,    -1,    -1,    -1,  1131,    -1,
      -1,    -1,    -1,    -1,    -1,   537,    -1,   539,    -1,   457,
      -1,    -1,    -1,  1103,    -1,    -1,  1106,    -1,    -1,    -1,
      -1,   469,  1112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     450,    -1,    -1,  1070,    -1,    -1,    -1,   569,    -1,   450,
     460,    -1,  1132,    -1,    -1,    -1,  1136,    -1,    -1,  1086,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1098,  1152,    -1,    -1,  1102,    -1,  1104,    -1,   656,
    1160,  1161,    -1,    -1,    -1,    -1,   524,    -1,  1168,    -1,
    1117,    -1,    -1,   683,  1121,    -1,    -1,    -1,  1125,  1179,
     622,   623,    12,   693,    -1,    -1,    -1,    -1,  1135,    -1,
      -1,    -1,   522,    -1,    -1,   525,   554,    -1,    -1,    -1,
    1147,   522,   560,    -1,   525,    -1,    -1,    -1,    -1,    -1,
     540,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   540,
      -1,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,   999,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   710,    -1,
      -1,    -1,    -1,   770,    -1,   605,    -1,    -1,    -1,    -1,
      -1,   778,    -1,    -1,    -1,   782,   783,    -1,    -1,   786,
     787,   788,   789,   790,   791,   792,   793,   794,   795,    -1,
      -1,    -1,    -1,   745,    -1,   815,    -1,   137,    -1,   139,
     140,    -1,   142,   143,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,
      -1,   828,    -1,    -1,    -1,   693,    -1,    -1,    -1,   669,
      -1,    -1,    -1,    -1,    -1,   675,    -1,    -1,   669,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,  1116,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,    52,
      -1,    -1,    -1,    -1,   901,    -1,  1146,   904,  1148,   739,
     740,   741,    -1,    -1,    -1,    -1,    -1,    -1,   739,   740,
     741,   918,    -1,    -1,  1164,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   821,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     821,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,   882,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,   976,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
     918,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
    1022,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   918,    48,
     920,    -1,    -1,    -1,   924,    -1,   926,   918,    -1,   920,
    1042,    -1,    -1,   924,    -1,    -1,  1116,    -1,    -1,    -1,
    1052,    -1,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1075,    -1,    -1,  1146,    -1,  1148,   997,
      -1,  1083,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,    -1,  1164,  1013,   145,    -1,    -1,    -1,
      -1,    -1,    -1,  1021,  1022,    -1,    -1,    -1,    -1,   999,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1119,   999,    -1,
      -1,  1123,    -1,    -1,    -1,    -1,   145,    -1,    -1,    -1,
    1132,    -1,    -1,    -1,    -1,    -1,  1026,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1152,    -1,    -1,    -1,    -1,    -1,    -1,  1075,    -1,    -1,
      -1,    -1,    -1,  1081,    -1,  1083,    -1,    -1,    -1,    -1,
    1088,  1089,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,  1122,  1123,    34,    35,    36,    37,
      38,    39,    -1,    41,    42,    43,    44,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,    -1,   137,
     138,   139,   140,    -1,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      34,    35,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     134,   135,   136,   137,   138,   139,   140,    -1,   142,   143,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    34,    35,    36,    37,    38,    39,
      -1,    41,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   134,   135,    -1,   137,   138,   139,
     140,    -1,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    34,    35,
      36,    37,    38,    39,    -1,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,
      -1,   137,   138,   139,   140,   141,   142,   143,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    34,    35,    36,    37,    38,    39,    -1,    41,
      42,    43,    44,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   134,   135,   136,   137,   138,   139,   140,    -1,
     142,   143,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    34,    35,    36,    37,
      38,    39,    -1,    41,    42,    43,    44,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,    -1,   142,   143,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      34,    35,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     134,   135,   136,   137,   138,   139,   140,    -1,   142,   143,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    34,    35,    36,    37,    38,    39,
      -1,    41,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,    -1,   142,   143,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    34,    35,
      36,    37,    38,    39,    -1,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,
     136,   137,   138,   139,   140,    -1,   142,   143,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    34,    35,    36,    37,    38,    39,    -1,    41,
      42,    43,    44,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   134,   135,    -1,   137,   138,   139,   140,    -1,
     142,   143,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    34,    35,    36,    37,
      38,    39,    -1,    41,    42,    43,    44,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,    -1,   137,
     138,   139,   140,    -1,   142,   143,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      34,    35,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,    -1,   137,   138,   139,   140,   141,   142,   143,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    34,    35,    36,    37,    38,    39,
      -1,    41,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   134,   135,    -1,   137,   138,   139,
     140,    -1,   142,   143,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    34,    35,
      36,    37,    38,    39,    -1,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,
      -1,   137,   138,   139,   140,    -1,   142,   143,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    34,    35,    36,    37,    38,    39,    -1,    41,
      42,    43,    44,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   135,    -1,   137,   138,   139,   140,    -1,
     142,   143,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    34,    35,    36,    37,
      38,    39,    -1,    41,    42,    43,    44,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    -1,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,    -1,   142,   143,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      34,    35,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,    -1,   137,   138,   139,   140,    -1,   142,   143,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    34,    35,    36,    37,    38,    39,
      -1,    41,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,   139,
     140,    -1,    -1,   143,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    34,    35,
      36,    37,    38,    39,    -1,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    -1,    84,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
      -1,   137,   138,   139,   140,   141,   142,   143,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    34,    35,    36,    37,    38,    39,    -1,    41,
      42,    43,    44,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    -1,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   135,    -1,   137,   138,   139,   140,   141,
     142,   143,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    34,    35,    36,    37,
      38,    39,    -1,    41,    42,    43,    44,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    -1,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      34,    35,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    -1,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,    -1,   137,   138,   139,   140,    -1,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    34,    35,    36,    37,    38,    39,
      -1,    41,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    -1,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,   139,
     140,    -1,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    34,    35,
      36,    37,    38,    39,    -1,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    -1,    84,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
      -1,   137,   138,   139,   140,    -1,   142,   143,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    34,    35,    36,    37,    38,    39,    -1,    41,
      42,    43,    44,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    -1,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   135,    -1,   137,   138,   139,   140,    -1,
     142,   143,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    34,    35,    36,    37,
      38,    39,    -1,    41,    42,    43,    44,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    -1,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,   137,
     138,   139,   140,    -1,   142,   143,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      34,    35,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    -1,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,    -1,    -1,   138,    -1,   140,    -1,   142,   143,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    34,    35,    36,    37,    38,    39,
      -1,    41,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    -1,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,    -1,   138,    -1,
     140,    -1,   142,   143,    -1,   145,   146,   147,    -1,   149,
     150,   151,   152,   153,   154,   155,   156,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    34,    35,
      36,    37,    38,    39,    -1,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    -1,    -1,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
      -1,    -1,   138,    -1,   140,    -1,    -1,   143,    -1,   145,
     146,   147,    -1,   149,   150,   151,   152,   153,   154,   155,
     156,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,
      -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    -1,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,   137,    -1,   139,   140,    -1,
     142,   143,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    42,    43,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,   134,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    41,    42,    43,    -1,    -1,    -1,
      -1,    48,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    -1,    24,    25,    26,    27,    -1,    -1,   145,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    41,
      42,    43,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    -1,    24,    25,    26,
      27,    -1,    -1,   145,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    41,    42,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    -1,    24,    25,    26,    27,    -1,    -1,   145,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    41,
      42,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    -1,
      -1,    -1,    -1,   145,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   145,    -1,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    -1,    48,    49,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
      -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    20,
      21,    22,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,    -1,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    -1,    48,    49,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,   145,
      -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    20,    21,
      22,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,    43,    -1,    -1,    -1,    -1,    48,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,   145,    -1,    -1,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    42,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   145,    -1,    -1,    -1,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    48,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,    -1,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     134,   135,    -1,    -1,   138,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,     3,     4,     5,     6,     7,     8,     9,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    -1,   134,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,    -1,
     138,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    -1,
      24,    25,    26,    27,    -1,   146,   147,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    41,    42,    43,
      -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,    42,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    41,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    -1,    -1,    -1,    -1,    48,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    20,    21,    22,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,   158,   159,     0,   160,   367,     3,     4,     5,     6,
       7,     8,     9,    20,    21,    22,    23,    24,    25,    26,
      27,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      41,    42,    43,    48,    49,    50,    51,    52,    84,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   134,   145,   161,   162,
     163,   164,   165,   167,   168,   169,   170,   171,   173,   176,
     191,   192,   193,   195,   196,   206,   207,   216,   218,   219,
     221,   239,   240,   241,   242,   245,   246,   249,   255,   289,
     319,   320,   321,   322,   324,   325,   326,   327,   329,   331,
     332,   335,   336,   337,   338,   339,   341,   342,   345,   346,
     357,   358,   359,   368,   371,   369,    24,    25,    12,    43,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    34,
      35,    36,    37,    38,    39,    41,    42,    43,    44,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   135,
     137,   138,   139,   140,   142,   143,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   358,   359,
     396,   397,   398,   428,   429,   430,   431,   432,   330,   347,
       3,     4,     5,     6,     7,     8,     9,    41,   171,   176,
     193,   196,   321,   322,   327,   329,   335,   341,     3,     4,
       5,     6,     7,     8,     9,   135,   332,     3,     4,     5,
       6,     7,     8,     9,    20,    21,    22,    49,    51,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     217,   319,   321,   322,   326,   327,   329,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   333,   172,
     367,   333,   135,   367,    43,    52,   162,   169,   170,   196,
     202,   219,   221,   239,   335,   341,    45,   134,   135,   265,
     266,   265,   265,   265,   140,   176,   335,   341,   134,   367,
      43,   246,   270,   273,   320,   325,   327,   329,   178,   327,
     329,   331,   332,   326,   320,   321,   326,   367,   326,   142,
     171,   176,   193,   196,   207,   246,   322,   336,   345,   367,
      10,    11,    83,   233,   290,   298,   300,    77,   146,   147,
     295,   360,   361,   362,   363,   366,   343,   367,   367,   404,
     135,   428,   424,   424,    63,   148,   222,   414,   424,   425,
     424,    10,    11,   140,   418,   319,    12,   333,   367,   333,
     367,   320,   171,   193,   211,   212,   215,   233,   298,   424,
     137,   166,   319,   319,   134,   367,   249,   254,   255,   322,
       3,     4,     5,     6,     7,     8,     9,   331,   373,   376,
     377,   331,   331,   381,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,    40,    50,
     291,   294,   295,   334,   336,   359,   135,   134,   138,   177,
     178,   322,   326,   327,   329,   291,   194,   134,   138,   197,
     319,   319,   367,   335,   233,   138,   275,   424,   247,   367,
     323,   271,   140,   326,   326,   326,   328,   333,   367,   333,
     367,   246,   270,   367,   344,   301,   250,   252,   254,   255,
     256,   268,   309,   320,   322,   292,   137,   285,   286,   288,
     233,   298,   307,   360,   367,   367,   367,   361,   363,   333,
      23,    63,    84,   135,   137,   138,   139,   142,   143,   148,
     156,   358,   359,   370,   396,   397,   398,   402,   403,   405,
     406,   415,   418,   422,   159,   425,   134,   142,   144,   426,
     427,   428,   136,   223,   225,   226,   228,   230,   144,   134,
     427,   141,   420,   421,   419,   367,   208,   210,   295,   177,
     208,   319,   333,   333,   209,   309,   320,   327,   329,   136,
     321,   327,   135,   134,   137,    12,    53,    54,    63,   137,
     139,   140,   142,   143,   148,   395,   396,   249,   254,   139,
     331,   331,   331,   139,   139,   331,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   141,   141,   139,
     134,   292,   290,   367,   180,   175,     3,   134,   179,   367,
     178,   327,   329,   322,   134,   199,   200,   331,   198,   197,
     367,   319,   320,   322,   276,   277,   319,   135,   136,   278,
     279,   177,   327,   275,   274,   408,   291,   177,   291,   319,
     333,   339,   340,   365,   251,   367,   257,   311,   312,   313,
     367,   250,   256,   134,   139,   287,   422,   141,   298,   364,
     417,   423,   416,   144,   136,   134,   144,   139,   414,    24,
      26,   196,   321,   327,   329,   335,   352,   353,   356,   357,
      25,    49,   234,   221,   404,   404,   404,   134,   209,   215,
     134,   197,   208,   208,   134,   139,   140,   367,   134,   159,
     220,     3,   143,   143,    63,   148,   141,   144,   372,   139,
     141,   141,   378,   380,   139,   341,   384,   386,   388,   390,
     385,   387,   389,   391,   392,   393,   319,    28,    29,    30,
     136,   181,   182,    28,    29,    30,    36,   186,   187,   190,
     319,   138,   367,   178,   136,   139,   137,   342,   134,   367,
     331,   139,   431,   424,   141,    83,   280,   282,   283,   326,
     272,   278,   137,   139,   142,   402,   410,   411,   412,   414,
     134,   134,   134,   197,   339,   257,   140,     3,    31,    44,
      47,    66,   137,   258,   260,   261,   262,   263,   143,   314,
     315,   138,   140,   293,    63,   142,   148,   399,   400,   402,
     412,   299,   365,   404,   409,   404,   144,   224,   319,   319,
     319,   345,   233,   296,   300,   295,   354,   296,    25,   141,
     141,   141,   134,   134,   210,   213,   136,   341,   144,   144,
     341,   374,   341,   341,   382,   141,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   139,   394,   367,   138,
     189,   190,   139,    36,   188,   233,   174,   367,   200,   201,
     137,   203,   429,   277,   233,   136,   367,   139,   341,   257,
     141,   413,   134,   262,   253,   259,   264,    18,    54,    55,
     418,   316,   315,    13,    14,    15,   310,   269,   294,   401,
     400,   140,   302,   312,   144,   134,   136,   406,   407,   144,
     225,   355,   308,   309,   227,   367,   333,   229,   231,   278,
     296,   141,   341,   379,   141,   341,   141,   141,   141,   141,
     141,   141,   141,   141,   139,   139,   141,    40,    41,    52,
     133,   134,   163,   168,   170,   183,   184,   185,   191,   192,
     206,   216,   219,   221,   243,   244,   245,   270,   289,   319,
     320,   322,   335,   341,   371,   319,   367,   319,   186,   399,
     425,   134,   267,   248,    83,   281,   296,   262,   367,   408,
     278,   418,   335,   346,   348,   349,   317,   318,   278,   403,
     303,   144,   333,   302,   137,   235,   236,   296,   306,   360,
     235,   296,   141,   134,   375,   139,   383,    13,    13,   168,
     176,   204,   221,   244,   320,   335,   341,   431,   170,   184,
     219,   221,   243,   335,   265,   134,   254,   270,   322,   233,
     233,   187,   233,    46,   257,   282,   284,   414,   141,   346,
     350,   295,   144,   399,   141,   278,   237,   141,   296,   232,
     214,   141,   425,   141,   141,   141,   367,   176,   204,   335,
     265,   176,   233,   335,   367,   254,   256,   431,   262,   285,
     367,   351,   333,   367,   367,   141,   238,   410,   297,   235,
     305,   141,   135,   138,   177,   205,   367,   176,   367,   134,
     367,   135,   333,   367,   410,   302,    31,    33,    44,    47,
     424,   425,   179,   177,   367,   177,   205,   134,   424,   304,
     431,   431,   136,   134,   205,   177,   179,   136,   305,   425,
     205,   134
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] =
{
       0,   157,   158,   159,   160,   159,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   162,   162,   162,   162,   162,   163,
     163,   164,   165,   166,   165,   167,   168,   168,   169,   169,
     169,   170,   170,   172,   171,   174,   173,   173,   175,   173,
     173,   176,   176,   176,   177,   177,   177,   178,   178,   179,
     179,   180,   181,   180,   180,   182,   182,   182,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   184,   184,   184,   184,   185,   185,
     185,   185,   186,   186,   187,   187,   187,   188,   188,   189,
     189,   190,   190,   190,   191,   191,   191,   192,   192,   194,
     193,   195,   195,   196,   196,   196,   197,   198,   197,   199,
     199,   200,   200,   201,   200,   202,   203,   203,   204,   204,
     204,   204,   205,   205,   206,   206,   207,   207,   207,   207,
     207,   208,   209,   209,   210,   211,   211,   213,   214,   212,
     215,   216,   217,   217,   217,   217,   217,   217,   218,   220,
     219,   221,   222,   221,   223,   224,   223,   226,   227,   225,
     228,   229,   225,   230,   231,   232,   225,   233,   233,   234,
     234,   235,   235,   237,   236,   238,   238,   239,   239,   239,
     239,   240,   241,   241,   241,   242,   242,   242,   243,   243,
     243,   244,   244,   244,   244,   245,   245,   245,   247,   248,
     246,   249,   251,   250,   253,   252,   254,   255,   256,   257,
     257,   259,   258,   258,   258,   258,   258,   258,   258,   260,
     261,   261,   262,   262,   264,   263,   265,   265,   265,   266,
     267,   267,   269,   268,   271,   272,   270,   274,   273,   275,
     275,   276,   276,   277,   278,   279,   278,   280,   281,   280,
     280,   280,   283,   284,   282,   285,   285,   287,   286,   288,
     286,   289,   290,   291,   291,   292,   293,   292,   294,   295,
     295,   296,   297,   296,   298,   299,   298,   301,   300,   300,
     302,   303,   304,   302,   302,   305,   305,   305,   305,   305,
     305,   306,   306,   307,   307,   308,   308,   309,   309,   310,
     310,   310,   311,   311,   313,   312,   314,   314,   316,   315,
     317,   318,   317,   319,   319,   320,   320,   320,   320,   320,
     321,   321,   321,   322,   322,   322,   322,   322,   322,   323,
     322,   324,   325,   326,   328,   327,   330,   329,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   332,
     332,   332,   332,   332,   332,   332,   333,   333,   334,   334,
     334,   334,   335,   335,   336,   336,   336,   336,   337,   337,
     337,   337,   337,   338,   338,   338,   339,   339,   340,   340,
     341,   343,   342,   344,   342,   345,   345,   345,   346,   346,
     347,   346,   346,   346,   348,   350,   349,   351,   349,   352,
     354,   353,   355,   353,   356,   356,   356,   356,   356,   356,
     356,   357,   357,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   360,
     360,   360,   360,   361,   362,   364,   363,   365,   365,   366,
     366,   367,   367,   369,   370,   368,   372,   371,   373,   374,
     375,   371,   376,   371,   377,   371,   378,   379,   371,   380,
     371,   381,   382,   383,   371,   371,   384,   371,   385,   371,
     386,   371,   387,   371,   388,   371,   389,   371,   390,   371,
     391,   371,   392,   371,   393,   371,   371,   371,   371,   394,
     394,   395,   395,   395,   395,   395,   395,   395,   395,   395,
     395,   395,   395,   396,   396,   396,   396,   396,   396,   396,
     396,   396,   396,   396,   396,   396,   396,   396,   396,   396,
     396,   396,   396,   396,   396,   396,   396,   396,   396,   396,
     396,   396,   396,   396,   396,   396,   396,   397,   397,   397,
     397,   397,   397,   397,   397,   397,   397,   397,   397,   397,
     397,   397,   397,   397,   397,   397,   397,   397,   397,   397,
     397,   397,   397,   397,   397,   397,   398,   398,   398,   398,
     398,   398,   398,   398,   399,   399,   400,   400,   400,   401,
     400,   400,   402,   402,   403,   403,   403,   403,   403,   403,
     403,   403,   403,   403,   404,   404,   405,   405,   405,   405,
     406,   406,   406,   407,   407,   408,   408,   409,   409,   410,
     410,   411,   411,   411,   413,   412,   414,   414,   416,   415,
     417,   415,   419,   418,   420,   418,   421,   418,   423,   422,
     424,   424,   425,   425,   426,   426,   427,   427,   428,   428,
     428,   428,   428,   428,   428,   428,   428,   428,   428,   428,
     428,   428,   428,   428,   428,   429,   430,   430,   431,   432,
     432,   432
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     0,     0,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     2,     2,     2,     2,     5,
       4,     5,     4,     0,     6,     5,     1,     2,     4,     3,
       5,     4,     5,     0,     5,     0,     7,     4,     0,     5,
       2,     1,     1,     1,     3,     4,     2,     1,     1,     0,
       1,     0,     0,     4,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     2,     2,     2,     2,     2,     3,
       2,     3,     1,     4,     2,     4,     4,     0,     1,     0,
       1,     1,     1,     1,     5,     3,     6,     4,     5,     0,
       5,     4,     3,     1,     2,     2,     0,     0,     3,     1,
       3,     0,     1,     0,     4,     6,     2,     1,     5,     6,
       3,     4,     5,     3,     1,     2,     5,     5,     6,     5,
       6,     2,     0,     3,     2,     1,     1,     0,     0,     8,
       1,     3,     1,     2,     2,     2,     3,     3,     4,     0,
       8,     3,     0,     5,     1,     0,     4,     0,     0,     5,
       0,     0,     5,     0,     0,     0,     7,     0,     1,     1,
       1,     0,     1,     0,     3,     1,     2,     2,     2,     2,
       2,     3,     4,     2,     3,     2,     3,     4,     2,     4,
       5,     3,     1,     1,     2,     1,     2,     3,     0,     0,
       9,     2,     0,     4,     0,     7,     2,     1,     3,     0,
       2,     0,     3,     1,     2,     1,     2,     1,     1,     1,
       2,     2,     0,     1,     0,     3,     3,     1,     1,     6,
       0,     6,     0,     7,     0,     0,     6,     0,     6,     0,
       2,     1,     3,     3,     0,     0,     2,     1,     0,     4,
       3,     1,     0,     0,     5,     0,     1,     0,     3,     0,
       2,     4,     2,     0,     2,     0,     0,     4,     2,     0,
       1,     3,     0,     6,     3,     0,     5,     0,     3,     1,
       0,     0,     0,     7,     1,     0,     2,     2,     3,     3,
       2,     1,     2,     1,     2,     0,     1,     2,     4,     1,
       1,     1,     0,     1,     0,     2,     1,     2,     0,     5,
       0,     0,     2,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     3,     3,     0,
       5,     1,     1,     1,     0,     5,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     3,     1,     1,
       1,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     0,     3,     0,     4,     1,     3,     4,     1,     1,
       0,     4,     2,     2,     2,     0,     3,     0,     4,     2,
       0,     3,     0,     4,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     0,     4,     0,     1,     1,
       2,     0,     2,     0,     0,     6,     0,     7,     0,     0,
       0,     9,     0,     5,     0,     5,     0,     0,    10,     0,
       7,     0,     0,     0,     9,     6,     0,     7,     0,     7,
       0,     7,     0,     7,     0,     7,     0,     7,     0,     7,
       0,     7,     0,     9,     0,     9,     4,     4,     7,     0,
       1,     2,     2,     3,     3,     1,     1,     1,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     0,     2,     1,
       1,     1,     1,     1,     0,     4,     1,     1,     0,     4,
       0,     5,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     4,     3,     1,
       1,     1
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const unsigned char yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const unsigned char yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const unsigned char yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   247,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     9,    11,    13,    15,
      17,    19,    21,    23,    25,    27,    29,    31,    33,    35,
      37,    39,    41,    43,    45,    47,    49,    51,    53,    55,
      57,    59,    61,    63,     0,     0,    65,    67,    69,    71,
      73,    75,     0,    77,    79,    81,    83,     0,     0,    85,
      87,    89,    91,    93,    95,    97,    99,   101,   103,   105,
     107,   109,   111,   113,   115,   117,   119,   121,   123,   125,
     127,   129,   131,   133,   135,   137,   139,   141,   143,   145,
     147,   149,   151,   153,   155,     0,   157,     0,   159,   161,
     163,   165,   167,   169,   171,   173,   175,   177,   179,   181,
     183,   185,   187,   189,   191,   193,   195,   197,   199,   201,
     203,   205,   207,   209,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   211,     0,     0,
     213,   215,   217,     0,   219,   221,     0,   223,   225,   227,
     229,   231,   233,   235,   237,   239,   241,   243,   245,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short int yyconfl[] =
{
       0,   406,     0,   406,     0,   406,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   654,     0,   654,
       0,   654,     0,   654,     0,   654,     0,   406,     0,   406,
       0
};

/* Error token number */
#define YYTERROR 1



YYSTYPE yylval;

int yynerrs;
int yychar;

static const int YYEOF = 0;
static const int YYEMPTY = -2;

typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YYDPRINTF(Args)                        \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
  } while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YYFPRINTF (stderr, "%s ", Title);                               \
        yy_symbol_print (stderr, Type, Value);        \
        YYFPRINTF (stderr, "\n");                                       \
      }                                                                 \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

struct yyGLRStack;
static void yypstack (struct yyGLRStack* yystackp, size_t yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (struct yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)

#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif


#if YYERROR_VERBOSE

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static size_t
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return strlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* !YYERROR_VERBOSE */

/** State numbers, as in LALR(1) machine */
typedef int yyStateNum;

/** Rule numbers, as in LALR(1) machine */
typedef int yyRuleNum;

/** Grammar symbol */
typedef int yySymbol;

/** Item references, as in LALR(1) machine */
typedef short int yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState {
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yysval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yyStateNum yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  size_t yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  non-terminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yysval;
  } yysemantics;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  size_t yysize, yycapacity;
};

struct yySemanticOption {
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;


  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  size_t yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

static _Noreturn void
yyFail (yyGLRStack* yystackp, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

static _Noreturn void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

#if YYDEBUG || YYERROR_VERBOSE
/** A printable representation of TOKEN.  */
static const char*
yytokenName (yySymbol yytoken)
{
  if (yytoken == YYEMPTY)
    return "";

  return yytname[yytoken];
}
#endif

/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int);
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
      else
        /* The effect of using yysval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static int yyfill (yyGLRStackItem *, int *, int, yybool);

static int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyn, size_t yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp,
              YYSTYPE* yyvalp)
{
  yybool yynormal = (yystackp->yysplitPoint == YY_NULLPTR);
  int yylow;
  YYUSE (yyvalp);
  YYUSE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, N, yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  yylow = 1;
  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-(int)yyrhslen)].yystate.yysemantics.yysval;
  switch (yyn)
    {
        case 4:

    {
      startSig();
      clearType();
      clearTypeId();
      clearTemplate();
      closeComment();
    }

    break;

  case 33:

    { pushNamespace((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 34:

    { popNamespace(); }

    break;

  case 43:

    { pushType(); }

    break;

  case 44:

    {
      const char *name = (currentClass ? currentClass->Name : NULL);
      popType();
      clearTypeId();
      if (name)
        {
        setTypeId(name);
        setTypeBase(guess_id_type(name));
        }
      end_class();
    }

    break;

  case 45:

    {
      start_class((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.integer));
      currentClass->IsFinal = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.integer);
    }

    break;

  case 47:

    {
      start_class((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.integer));
      currentClass->IsFinal = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer);
    }

    break;

  case 48:

    {
      start_class(NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.integer));
    }

    break;

  case 50:

    {
      start_class(NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.integer));
    }

    break;

  case 51:

    { ((*yyvalp).integer) = 0; }

    break;

  case 52:

    { ((*yyvalp).integer) = 1; }

    break;

  case 53:

    { ((*yyvalp).integer) = 2; }

    break;

  case 54:

    { ((*yyvalp).str) = vtkstrcat((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str)); }

    break;

  case 55:

    { ((*yyvalp).str) = vtkstrcat3("::", (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str)); }

    break;

  case 59:

    { ((*yyvalp).integer) = 0; }

    break;

  case 60:

    { ((*yyvalp).integer) = (strcmp((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str), "final") == 0); }

    break;

  case 62:

    {
      startSig();
      clearType();
      clearTypeId();
      clearTemplate();
      closeComment();
    }

    break;

  case 65:

    { access_level = VTK_ACCESS_PUBLIC; }

    break;

  case 66:

    { access_level = VTK_ACCESS_PRIVATE; }

    break;

  case 67:

    { access_level = VTK_ACCESS_PROTECTED; }

    break;

  case 91:

    { output_friend_function(); }

    break;

  case 94:

    { add_base_class(currentClass, (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), access_level, (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer)); }

    break;

  case 95:

    { add_base_class(currentClass, (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.integer),
                     (VTK_PARSE_VIRTUAL | (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer))); }

    break;

  case 96:

    { add_base_class(currentClass, (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.integer),
                     ((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.integer) | (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer))); }

    break;

  case 97:

    { ((*yyvalp).integer) = 0; }

    break;

  case 98:

    { ((*yyvalp).integer) = VTK_PARSE_VIRTUAL; }

    break;

  case 99:

    { ((*yyvalp).integer) = access_level; }

    break;

  case 101:

    { ((*yyvalp).integer) = VTK_ACCESS_PUBLIC; }

    break;

  case 102:

    { ((*yyvalp).integer) = VTK_ACCESS_PRIVATE; }

    break;

  case 103:

    { ((*yyvalp).integer) = VTK_ACCESS_PROTECTED; }

    break;

  case 109:

    { pushType(); }

    break;

  case 110:

    {
      popType();
      clearTypeId();
      if ((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.str) != NULL)
        {
        setTypeId((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.str));
        setTypeBase(guess_id_type((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.str)));
        }
      end_enum();
    }

    break;

  case 111:

    {
      start_enum((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.integer), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer), getTypeId());
      clearTypeId();
      ((*yyvalp).str) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str);
    }

    break;

  case 112:

    {
      start_enum(NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.integer), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer), getTypeId());
      clearTypeId();
      ((*yyvalp).str) = NULL;
    }

    break;

  case 113:

    { ((*yyvalp).integer) = 0; }

    break;

  case 114:

    { ((*yyvalp).integer) = 1; }

    break;

  case 115:

    { ((*yyvalp).integer) = 1; }

    break;

  case 116:

    { ((*yyvalp).integer) = 0; }

    break;

  case 117:

    { pushType(); }

    break;

  case 118:

    { ((*yyvalp).integer) = getType(); popType(); }

    break;

  case 122:

    { add_enum((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str), NULL); }

    break;

  case 123:

    { postSig("="); markSig(); }

    break;

  case 124:

    { chopSig(); add_enum((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.str), copySig()); }

    break;

  case 147:

    { pushFunction(); postSig("("); }

    break;

  case 148:

    { postSig(")"); }

    break;

  case 149:

    { ((*yyvalp).integer) = (VTK_PARSE_FUNCTION | (((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.integer)); popFunction(); }

    break;

  case 150:

    {
      ValueInfo *item = (ValueInfo *)malloc(sizeof(ValueInfo));
      vtkParse_InitValue(item);
      item->ItemType = VTK_TYPEDEF_INFO;
      item->Access = access_level;

      handle_complex_type(item, getType(), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer), getSig());

      if (getVarName())
        {
        item->Name = getVarName();
        }

      if (item->Class == NULL)
        {
        vtkParse_FreeValue(item);
        }
      else if (currentClass)
        {
        vtkParse_AddTypedefToClass(currentClass, item);
        }
      else
        {
        vtkParse_AddTypedefToNamespace(currentNamespace, item);
        }
    }

    break;

  case 151:

    { add_using((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), 0); }

    break;

  case 153:

    { ((*yyvalp).str) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str); }

    break;

  case 154:

    { ((*yyvalp).str) = vtkstrcat((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 155:

    { ((*yyvalp).str) = vtkstrcat((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 156:

    { ((*yyvalp).str) = vtkstrcat3((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 157:

    { ((*yyvalp).str) = vtkstrcat3((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 158:

    { add_using((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), 1); }

    break;

  case 159:

    { markSig(); }

    break;

  case 160:

    {
      ValueInfo *item = (ValueInfo *)malloc(sizeof(ValueInfo));
      vtkParse_InitValue(item);
      item->ItemType = VTK_TYPEDEF_INFO;
      item->Access = access_level;

      handle_complex_type(item, getType(), (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.integer), copySig());

      item->Name = (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.str);

      if (currentTemplate)
        {
        vtkParse_FreeValue(item);
        }
      else if (currentClass)
        {
        vtkParse_AddTypedefToClass(currentClass, item);
        }
      else
        {
        vtkParse_AddTypedefToNamespace(currentNamespace, item);
        }
    }

    break;

  case 161:

    { postSig("template<> "); clearTypeId(); }

    break;

  case 162:

    {
      postSig("template<");
      pushType();
      clearType();
      clearTypeId();
      startTemplate();
    }

    break;

  case 163:

    {
      chopSig();
      if (getSig()[getSigLength()-1] == '>') { postSig(" "); }
      postSig("> ");
      clearTypeId();
      popType();
    }

    break;

  case 165:

    { chopSig(); postSig(", "); clearType(); clearTypeId(); }

    break;

  case 167:

    { markSig(); }

    break;

  case 168:

    { add_template_parameter(getType(), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer), copySig()); }

    break;

  case 170:

    { markSig(); }

    break;

  case 171:

    { add_template_parameter(0, (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer), copySig()); }

    break;

  case 173:

    { pushTemplate(); markSig(); }

    break;

  case 174:

    { postSig("class "); }

    break;

  case 175:

    {
      int i;
      TemplateInfo *newTemplate = currentTemplate;
      popTemplate();
      add_template_parameter(0, (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer), copySig());
      i = currentTemplate->NumberOfParameters-1;
      currentTemplate->Parameters[i]->Template = newTemplate;
    }

    break;

  case 177:

    { ((*yyvalp).integer) = 0; }

    break;

  case 178:

    { postSig("..."); ((*yyvalp).integer) = VTK_PARSE_PACK; }

    break;

  case 179:

    { postSig("class "); }

    break;

  case 180:

    { postSig("typename "); }

    break;

  case 183:

    { postSig("="); markSig(); }

    break;

  case 184:

    {
      int i = currentTemplate->NumberOfParameters-1;
      ValueInfo *param = currentTemplate->Parameters[i];
      chopSig();
      param->Value = copySig();
    }

    break;

  case 187:

    { output_function(); }

    break;

  case 188:

    { output_function(); }

    break;

  case 189:

    { reject_function(); }

    break;

  case 190:

    { reject_function(); }

    break;

  case 198:

    { output_function(); }

    break;

  case 208:

    {
      postSig("(");
      currentFunction->IsExplicit = ((getType() & VTK_PARSE_EXPLICIT) != 0);
      set_return(currentFunction, getType(), getTypeId(), 0);
    }

    break;

  case 209:

    { postSig(")"); }

    break;

  case 210:

    {
      postSig(";");
      closeSig();
      currentFunction->IsOperator = 1;
      currentFunction->Name = "operator typecast";
      currentFunction->Comment = vtkstrdup(getComment());
      vtkParseDebug("Parsed operator", "operator typecast");
    }

    break;

  case 211:

    { ((*yyvalp).str) = copySig(); }

    break;

  case 212:

    { postSig(")"); }

    break;

  case 213:

    {
      postSig(";");
      closeSig();
      currentFunction->Name = (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.str);
      currentFunction->Comment = vtkstrdup(getComment());
      vtkParseDebug("Parsed operator", currentFunction->Name);
    }

    break;

  case 214:

    {
      postSig("(");
      currentFunction->IsOperator = 1;
      set_return(currentFunction, getType(), getTypeId(), 0);
    }

    break;

  case 216:

    { chopSig(); ((*yyvalp).str) = vtkstrcat(copySig(), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); postSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 217:

    { markSig(); postSig("operator "); }

    break;

  case 218:

    {
      postSig(";");
      closeSig();
      currentFunction->Name = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.str);
      currentFunction->Comment = vtkstrdup(getComment());
      vtkParseDebug("Parsed func", currentFunction->Name);
    }

    break;

  case 221:

    { postSig(" throw "); }

    break;

  case 222:

    { chopSig(); }

    break;

  case 223:

    { postSig(" const"); currentFunction->IsConst = 1; }

    break;

  case 224:

    {
      postSig(" = 0");
      currentFunction->IsPureVirtual = 1;
      if (currentClass) { currentClass->IsAbstract = 1; }
    }

    break;

  case 225:

    {
      postSig(" "); postSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str));
      if (strcmp((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str), "final") == 0) { currentFunction->IsFinal = 1; }
    }

    break;

  case 226:

    { chopSig(); }

    break;

  case 229:

    { postSig(" noexcept"); }

    break;

  case 230:

    { currentFunction->IsDeleted = 1; }

    break;

  case 234:

    { postSig(" -> "); clearType(); clearTypeId(); }

    break;

  case 235:

    {
      chopSig();
      set_return(currentFunction, getType(), getTypeId(), 0);
    }

    break;

  case 242:

    {
      postSig("(");
      set_return(currentFunction, getType(), getTypeId(), 0);
    }

    break;

  case 243:

    { postSig(")"); }

    break;

  case 244:

    { closeSig(); }

    break;

  case 245:

    { openSig(); }

    break;

  case 246:

    {
      postSig(";");
      closeSig();
      if (getType() & VTK_PARSE_VIRTUAL)
        {
        currentFunction->IsVirtual = 1;
        }
      if (getType() & VTK_PARSE_EXPLICIT)
        {
        currentFunction->IsExplicit = 1;
        }
      currentFunction->Name = (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.str);
      currentFunction->Comment = vtkstrdup(getComment());
      vtkParseDebug("Parsed func", currentFunction->Name);
    }

    break;

  case 247:

    { pushType(); postSig("("); }

    break;

  case 248:

    { popType(); postSig(")"); }

    break;

  case 255:

    { clearType(); clearTypeId(); }

    break;

  case 257:

    { clearType(); clearTypeId(); }

    break;

  case 258:

    { clearType(); clearTypeId(); postSig(", "); }

    break;

  case 260:

    { currentFunction->IsVariadic = 1; postSig(", ..."); }

    break;

  case 261:

    { currentFunction->IsVariadic = 1; postSig("..."); }

    break;

  case 262:

    { markSig(); }

    break;

  case 263:

    {
      ValueInfo *param = (ValueInfo *)malloc(sizeof(ValueInfo));
      vtkParse_InitValue(param);

      handle_complex_type(param, getType(), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer), copySig());
      add_legacy_parameter(currentFunction, param);

      if (getVarName())
        {
        param->Name = getVarName();
        }

      vtkParse_AddParameterToFunction(currentFunction, param);
    }

    break;

  case 264:

    {
      int i = currentFunction->NumberOfParameters-1;
      if (getVarValue())
        {
        currentFunction->Parameters[i]->Value = getVarValue();
        }
    }

    break;

  case 265:

    { clearVarValue(); }

    break;

  case 267:

    { postSig("="); clearVarValue(); markSig(); }

    break;

  case 268:

    { chopSig(); setVarValue(copySig()); }

    break;

  case 269:

    { clearVarValue(); markSig(); }

    break;

  case 270:

    { chopSig(); setVarValue(copySig()); }

    break;

  case 272:

    {
      unsigned int type = getType();
      ValueInfo *var = (ValueInfo *)malloc(sizeof(ValueInfo));
      vtkParse_InitValue(var);
      var->ItemType = VTK_VARIABLE_INFO;
      var->Access = access_level;

      handle_complex_type(var, type, (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.integer), getSig());

      var->Name = getVarName();

      if (getVarValue())
        {
        var->Value = getVarValue();
        }

      /* Is this a typedef? */
      if ((type & VTK_PARSE_TYPEDEF) != 0)
        {
        var->ItemType = VTK_TYPEDEF_INFO;
        if (currentClass)
          {
          vtkParse_AddTypedefToClass(currentClass, var);
          }
        else
          {
          vtkParse_AddTypedefToNamespace(currentNamespace, var);
          }
        }
      /* Is this a constant? */
      else if (((type & VTK_PARSE_CONST) != 0) && var->Value != NULL &&
          (((type & VTK_PARSE_INDIRECT) == 0) ||
           ((type & VTK_PARSE_INDIRECT) == VTK_PARSE_ARRAY)))
        {
        var->ItemType = VTK_CONSTANT_INFO;
        if (currentClass)
          {
          vtkParse_AddConstantToClass(currentClass, var);
          }
        else
          {
          vtkParse_AddConstantToNamespace(currentNamespace, var);
          }
        }
      /* This is a true variable i.e. not constant */
      else
        {
        if (currentClass)
          {
          vtkParse_AddVariableToClass(currentClass, var);
          }
        else
          {
          vtkParse_AddVariableToNamespace(currentNamespace, var);
          }
        }
    }

    break;

  case 276:

    { postSig(", "); }

    break;

  case 279:

    { setTypePtr(0); }

    break;

  case 280:

    { setTypePtr((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer)); }

    break;

  case 281:

    {
      if ((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer) == VTK_PARSE_FUNCTION)
        {
        ((*yyvalp).integer) = (VTK_PARSE_FUNCTION_PTR | (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.integer));
        }
      else
        {
        ((*yyvalp).integer) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.integer);
        }
    }

    break;

  case 282:

    { postSig(")"); }

    break;

  case 283:

    {
      const char *scope = getScope();
      unsigned int parens = add_indirection((((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.integer), (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.integer));
      if ((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer) == VTK_PARSE_FUNCTION)
        {
        if (scope) { scope = vtkstrndup(scope, strlen(scope) - 2); }
        getFunction()->Class = scope;
        ((*yyvalp).integer) = (parens | VTK_PARSE_FUNCTION);
        }
      else if ((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer) == VTK_PARSE_ARRAY)
        {
        ((*yyvalp).integer) = add_indirection_to_array(parens);
        }
    }

    break;

  case 284:

    { ((*yyvalp).integer) = (((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.integer); }

    break;

  case 285:

    { postSig(")"); }

    break;

  case 286:

    {
      const char *scope = getScope();
      unsigned int parens = add_indirection((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.integer), (((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.integer));
      if ((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer) == VTK_PARSE_FUNCTION)
        {
        if (scope) { scope = vtkstrndup(scope, strlen(scope) - 2); }
        getFunction()->Class = scope;
        ((*yyvalp).integer) = (parens | VTK_PARSE_FUNCTION);
        }
      else if ((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer) == VTK_PARSE_ARRAY)
        {
        ((*yyvalp).integer) = add_indirection_to_array(parens);
        }
    }

    break;

  case 287:

    { postSig("("); scopeSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); postSig("*"); }

    break;

  case 288:

    { ((*yyvalp).integer) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer); }

    break;

  case 289:

    { postSig("("); scopeSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); postSig("&");
         ((*yyvalp).integer) = VTK_PARSE_REF; }

    break;

  case 290:

    { ((*yyvalp).integer) = 0; }

    break;

  case 291:

    { pushFunction(); postSig("("); }

    break;

  case 292:

    { postSig(")"); }

    break;

  case 293:

    {
      ((*yyvalp).integer) = VTK_PARSE_FUNCTION;
      popFunction();
    }

    break;

  case 294:

    { ((*yyvalp).integer) = VTK_PARSE_ARRAY; }

    break;

  case 297:

    { currentFunction->IsConst = 1; }

    break;

  case 302:

    { ((*yyvalp).integer) = add_indirection((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.integer), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer)); }

    break;

  case 304:

    { ((*yyvalp).integer) = add_indirection((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.integer), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer)); }

    break;

  case 305:

    { clearVarName(); chopSig(); }

    break;

  case 307:

    { setVarName((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str)); }

    break;

  case 308:

    { setVarName((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.str)); }

    break;

  case 312:

    { clearArray(); }

    break;

  case 314:

    { clearArray(); }

    break;

  case 318:

    { postSig("["); }

    break;

  case 319:

    { postSig("]"); }

    break;

  case 320:

    { pushArraySize(""); }

    break;

  case 321:

    { markSig(); }

    break;

  case 322:

    { chopSig(); pushArraySize(copySig()); }

    break;

  case 328:

    { ((*yyvalp).str) = vtkstrcat("~", (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 329:

    { ((*yyvalp).str) = vtkstrcat("~", (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 330:

    { ((*yyvalp).str) = vtkstrcat((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 331:

    { ((*yyvalp).str) = vtkstrcat((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 332:

    { ((*yyvalp).str) = vtkstrcat((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 333:

    { ((*yyvalp).str) = vtkstrcat((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 334:

    { ((*yyvalp).str) = vtkstrcat((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 335:

    { ((*yyvalp).str) = vtkstrcat((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 336:

    { ((*yyvalp).str) = vtkstrcat3((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 337:

    { ((*yyvalp).str) = vtkstrcat3((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 338:

    { ((*yyvalp).str) = vtkstrcat3((((yyGLRStackItem const *)yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 339:

    { postSig("template "); }

    break;

  case 340:

    { ((*yyvalp).str) = vtkstrcat4((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.str), "template ", (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 341:

    { postSig("~"); }

    break;

  case 342:

    { postSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 343:

    { ((*yyvalp).str) = "::"; postSig(((*yyvalp).str)); }

    break;

  case 344:

    { markSig(); postSig((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str)); postSig("<"); }

    break;

  case 345:

    {
      chopSig(); if (getSig()[getSigLength()-1] == '>') { postSig(" "); }
      postSig(">"); ((*yyvalp).str) = copySig(); clearTypeId();
    }

    break;

  case 346:

    { markSig(); postSig("decltype"); }

    break;

  case 347:

    { chopSig(); ((*yyvalp).str) = copySig(); clearTypeId(); }

    break;

  case 348:

    { postSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 349:

    { postSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 350:

    { postSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 351:

    { postSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 352:

    { postSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 353:

    { postSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 354:

    { postSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 355:

    { postSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 356:

    { postSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 357:

    { postSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 358:

    { ((*yyvalp).str) = "vtkTypeInt8"; postSig(((*yyvalp).str)); }

    break;

  case 359:

    { ((*yyvalp).str) = "vtkTypeUInt8"; postSig(((*yyvalp).str)); }

    break;

  case 360:

    { ((*yyvalp).str) = "vtkTypeInt16"; postSig(((*yyvalp).str)); }

    break;

  case 361:

    { ((*yyvalp).str) = "vtkTypeUInt16"; postSig(((*yyvalp).str)); }

    break;

  case 362:

    { ((*yyvalp).str) = "vtkTypeInt32"; postSig(((*yyvalp).str)); }

    break;

  case 363:

    { ((*yyvalp).str) = "vtkTypeUInt32"; postSig(((*yyvalp).str)); }

    break;

  case 364:

    { ((*yyvalp).str) = "vtkTypeInt64"; postSig(((*yyvalp).str)); }

    break;

  case 365:

    { ((*yyvalp).str) = "vtkTypeUInt64"; postSig(((*yyvalp).str)); }

    break;

  case 366:

    { ((*yyvalp).str) = "vtkTypeFloat32"; postSig(((*yyvalp).str)); }

    break;

  case 367:

    { ((*yyvalp).str) = "vtkTypeFloat64"; postSig(((*yyvalp).str)); }

    break;

  case 368:

    { ((*yyvalp).str) = "vtkIdType"; postSig(((*yyvalp).str)); }

    break;

  case 379:

    { setTypeBase(buildTypeBase(getType(), (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer))); }

    break;

  case 380:

    { setTypeMod(VTK_PARSE_TYPEDEF); }

    break;

  case 381:

    { setTypeMod(VTK_PARSE_FRIEND); }

    break;

  case 384:

    { setTypeMod((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer)); }

    break;

  case 385:

    { setTypeMod((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer)); }

    break;

  case 386:

    { setTypeMod((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer)); }

    break;

  case 387:

    { postSig("constexpr "); ((*yyvalp).integer) = 0; }

    break;

  case 388:

    { postSig("mutable "); ((*yyvalp).integer) = VTK_PARSE_MUTABLE; }

    break;

  case 389:

    { ((*yyvalp).integer) = 0; }

    break;

  case 390:

    { ((*yyvalp).integer) = 0; }

    break;

  case 391:

    { postSig("static "); ((*yyvalp).integer) = VTK_PARSE_STATIC; }

    break;

  case 392:

    { postSig("thread_local "); ((*yyvalp).integer) = VTK_PARSE_THREAD_LOCAL; }

    break;

  case 393:

    { ((*yyvalp).integer) = 0; }

    break;

  case 394:

    { postSig("virtual "); ((*yyvalp).integer) = VTK_PARSE_VIRTUAL; }

    break;

  case 395:

    { postSig("explicit "); ((*yyvalp).integer) = VTK_PARSE_EXPLICIT; }

    break;

  case 396:

    { postSig("const "); ((*yyvalp).integer) = VTK_PARSE_CONST; }

    break;

  case 397:

    { postSig("volatile "); ((*yyvalp).integer) = VTK_PARSE_VOLATILE; }

    break;

  case 399:

    { ((*yyvalp).integer) = ((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.integer) | (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer)); }

    break;

  case 401:

    { setTypeBase((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer)); }

    break;

  case 403:

    { setTypeBase((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer)); }

    break;

  case 406:

    { postSig(" "); setTypeId((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = guess_id_type((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 407:

    { postSig(" "); setTypeId((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = guess_id_type((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str)); }

    break;

  case 409:

    { postSig(" "); setTypeId((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = 0; }

    break;

  case 410:

    { postSig("typename "); }

    break;

  case 411:

    { postSig(" "); setTypeId((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = guess_id_type((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str)); }

    break;

  case 412:

    { postSig(" "); setTypeId((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = guess_id_type((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str)); }

    break;

  case 413:

    { postSig(" "); setTypeId((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = guess_id_type((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str)); }

    break;

  case 415:

    { setTypeBase((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer)); }

    break;

  case 417:

    { setTypeBase((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer)); }

    break;

  case 420:

    { setTypeBase((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer)); }

    break;

  case 422:

    { setTypeBase((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer)); }

    break;

  case 425:

    { postSig(" "); setTypeId((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = 0; }

    break;

  case 426:

    { postSig(" "); setTypeId((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = guess_id_type((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 427:

    { postSig(" "); setTypeId((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = guess_id_type((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 428:

    { postSig(" "); setTypeId((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = guess_id_type((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 429:

    { postSig(" "); setTypeId((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = guess_id_type((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 430:

    { postSig(" "); setTypeId((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = guess_id_type((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 431:

    { setTypeId(""); }

    break;

  case 433:

    { typeSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = VTK_PARSE_STRING; }

    break;

  case 434:

    { typeSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = VTK_PARSE_UNICODE_STRING;}

    break;

  case 435:

    { typeSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = VTK_PARSE_OSTREAM; }

    break;

  case 436:

    { typeSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = VTK_PARSE_ISTREAM; }

    break;

  case 437:

    { typeSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = VTK_PARSE_UNKNOWN; }

    break;

  case 438:

    { typeSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = VTK_PARSE_OBJECT; }

    break;

  case 439:

    { typeSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = VTK_PARSE_QOBJECT; }

    break;

  case 440:

    { typeSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = VTK_PARSE_NULLPTR_T; }

    break;

  case 441:

    { typeSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = VTK_PARSE_SSIZE_T; }

    break;

  case 442:

    { typeSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); ((*yyvalp).integer) = VTK_PARSE_SIZE_T; }

    break;

  case 443:

    { typeSig("vtkTypeInt8"); ((*yyvalp).integer) = VTK_PARSE_INT8; }

    break;

  case 444:

    { typeSig("vtkTypeUInt8"); ((*yyvalp).integer) = VTK_PARSE_UINT8; }

    break;

  case 445:

    { typeSig("vtkTypeInt16"); ((*yyvalp).integer) = VTK_PARSE_INT16; }

    break;

  case 446:

    { typeSig("vtkTypeUInt16"); ((*yyvalp).integer) = VTK_PARSE_UINT16; }

    break;

  case 447:

    { typeSig("vtkTypeInt32"); ((*yyvalp).integer) = VTK_PARSE_INT32; }

    break;

  case 448:

    { typeSig("vtkTypeUInt32"); ((*yyvalp).integer) = VTK_PARSE_UINT32; }

    break;

  case 449:

    { typeSig("vtkTypeInt64"); ((*yyvalp).integer) = VTK_PARSE_INT64; }

    break;

  case 450:

    { typeSig("vtkTypeUInt64"); ((*yyvalp).integer) = VTK_PARSE_UINT64; }

    break;

  case 451:

    { typeSig("vtkTypeFloat32"); ((*yyvalp).integer) = VTK_PARSE_FLOAT32; }

    break;

  case 452:

    { typeSig("vtkTypeFloat64"); ((*yyvalp).integer) = VTK_PARSE_FLOAT64; }

    break;

  case 453:

    { typeSig("vtkIdType"); ((*yyvalp).integer) = VTK_PARSE_ID_TYPE; }

    break;

  case 454:

    { postSig("auto "); ((*yyvalp).integer) = 0; }

    break;

  case 455:

    { postSig("void "); ((*yyvalp).integer) = VTK_PARSE_VOID; }

    break;

  case 456:

    { postSig("bool "); ((*yyvalp).integer) = VTK_PARSE_BOOL; }

    break;

  case 457:

    { postSig("float "); ((*yyvalp).integer) = VTK_PARSE_FLOAT; }

    break;

  case 458:

    { postSig("double "); ((*yyvalp).integer) = VTK_PARSE_DOUBLE; }

    break;

  case 459:

    { postSig("char "); ((*yyvalp).integer) = VTK_PARSE_CHAR; }

    break;

  case 460:

    { postSig("char16_t "); ((*yyvalp).integer) = VTK_PARSE_CHAR16_T; }

    break;

  case 461:

    { postSig("char32_t "); ((*yyvalp).integer) = VTK_PARSE_CHAR32_T; }

    break;

  case 462:

    { postSig("wchar_t "); ((*yyvalp).integer) = VTK_PARSE_WCHAR_T; }

    break;

  case 463:

    { postSig("int "); ((*yyvalp).integer) = VTK_PARSE_INT; }

    break;

  case 464:

    { postSig("short "); ((*yyvalp).integer) = VTK_PARSE_SHORT; }

    break;

  case 465:

    { postSig("long "); ((*yyvalp).integer) = VTK_PARSE_LONG; }

    break;

  case 466:

    { postSig("__int64 "); ((*yyvalp).integer) = VTK_PARSE___INT64; }

    break;

  case 467:

    { postSig("signed "); ((*yyvalp).integer) = VTK_PARSE_INT; }

    break;

  case 468:

    { postSig("unsigned "); ((*yyvalp).integer) = VTK_PARSE_UNSIGNED_INT; }

    break;

  case 472:

    { ((*yyvalp).integer) = ((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.integer) | (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer)); }

    break;

  case 473:

    { postSig("&"); ((*yyvalp).integer) = VTK_PARSE_REF; }

    break;

  case 474:

    { postSig("&&"); ((*yyvalp).integer) = (VTK_PARSE_RVALUE | VTK_PARSE_REF); }

    break;

  case 475:

    { postSig("*"); }

    break;

  case 476:

    { ((*yyvalp).integer) = (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer); }

    break;

  case 477:

    { ((*yyvalp).integer) = VTK_PARSE_POINTER; }

    break;

  case 478:

    {
      if (((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer) & VTK_PARSE_CONST) != 0)
        {
        ((*yyvalp).integer) = VTK_PARSE_CONST_POINTER;
        }
      if (((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer) & VTK_PARSE_VOLATILE) != 0)
        {
        ((*yyvalp).integer) = VTK_PARSE_BAD_INDIRECT;
        }
    }

    break;

  case 480:

    {
      unsigned int n;
      n = (((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.integer) << 2) | (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.integer));
      if ((n & VTK_PARSE_INDIRECT) != n)
        {
        n = VTK_PARSE_BAD_INDIRECT;
        }
      ((*yyvalp).integer) = n;
    }

    break;

  case 483:

    { closeSig(); }

    break;

  case 484:

    { openSig(); }

    break;

  case 486:

    {preSig("void Set"); postSig("(");}

    break;

  case 487:

    {
   postSig("a);");
   currentFunction->Macro = "vtkSetMacro";
   currentFunction->Name = vtkstrcat("Set", (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.str));
   currentFunction->Comment = vtkstrdup(getComment());
   add_parameter(currentFunction, getType(), getTypeId(), 0);
   set_return(currentFunction, VTK_PARSE_VOID, "void", 0);
   output_function();
   }

    break;

  case 488:

    {postSig("Get");}

    break;

  case 489:

    {markSig();}

    break;

  case 490:

    {swapSig();}

    break;

  case 491:

    {
   postSig("();");
   currentFunction->Macro = "vtkGetMacro";
   currentFunction->Name = vtkstrcat("Get", (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.str));
   currentFunction->Comment = vtkstrdup(getComment());
   set_return(currentFunction, getType(), getTypeId(), 0);
   output_function();
   }

    break;

  case 492:

    {preSig("void Set");}

    break;

  case 493:

    {
   postSig("(char *);");
   currentFunction->Macro = "vtkSetStringMacro";
   currentFunction->Name = vtkstrcat("Set", (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str));
   currentFunction->Comment = vtkstrdup(getComment());
   add_parameter(currentFunction, VTK_PARSE_CHAR_PTR, "char", 0);
   set_return(currentFunction, VTK_PARSE_VOID, "void", 0);
   output_function();
   }

    break;

  case 494:

    {preSig("char *Get");}

    break;

  case 495:

    {
   postSig("();");
   currentFunction->Macro = "vtkGetStringMacro";
   currentFunction->Name = vtkstrcat("Get", (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str));
   currentFunction->Comment = vtkstrdup(getComment());
   set_return(currentFunction, VTK_PARSE_CHAR_PTR, "char", 0);
   output_function();
   }

    break;

  case 496:

    {startSig(); markSig();}

    break;

  case 497:

    {closeSig();}

    break;

  case 498:

    {
   const char *typeText;
   chopSig();
   typeText = copySig();

   currentFunction->Macro = "vtkSetClampMacro";
   currentFunction->Name = vtkstrcat("Set", (((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.str));
   currentFunction->Signature =
     vtkstrcat5("void ", currentFunction->Name, "(", typeText, ");");
   currentFunction->Comment = vtkstrdup(getComment());
   add_parameter(currentFunction, getType(), getTypeId(), 0);
   set_return(currentFunction, VTK_PARSE_VOID, "void", 0);
   output_function();

   currentFunction->Macro = "vtkSetClampMacro";
   currentFunction->Name = vtkstrcat3("Get", (((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.str), "MinValue");
   currentFunction->Signature =
     vtkstrcat4(typeText, " ", currentFunction->Name, "();");
   currentFunction->Comment = vtkstrdup(getComment());
   set_return(currentFunction, getType(), getTypeId(), 0);
   output_function();

   currentFunction->Macro = "vtkSetClampMacro";
   currentFunction->Name = vtkstrcat3("Get", (((yyGLRStackItem const *)yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.str), "MaxValue");
   currentFunction->Signature =
     vtkstrcat4(typeText, " ", currentFunction->Name, "();");
   currentFunction->Comment = vtkstrdup(getComment());
   set_return(currentFunction, getType(), getTypeId(), 0);
   output_function();
   }

    break;

  case 499:

    {preSig("void Set"); postSig("("); }

    break;

  case 500:

    {
   postSig("*);");
   currentFunction->Macro = "vtkSetObjectMacro";
   currentFunction->Name = vtkstrcat("Set", (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.str));
   currentFunction->Comment = vtkstrdup(getComment());
   add_parameter(currentFunction, VTK_PARSE_OBJECT_PTR, getTypeId(), 0);
   set_return(currentFunction, VTK_PARSE_VOID, "void", 0);
   output_function();
   }

    break;

  case 501:

    {postSig("*Get");}

    break;

  case 502:

    {markSig();}

    break;

  case 503:

    {swapSig();}

    break;

  case 504:

    {
   postSig("();");
   currentFunction->Macro = "vtkGetObjectMacro";
   currentFunction->Name = vtkstrcat("Get", (((yyGLRStackItem const *)yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.str));
   currentFunction->Comment = vtkstrdup(getComment());
   set_return(currentFunction, VTK_PARSE_OBJECT_PTR, getTypeId(), 0);
   output_function();
   }

    break;

  case 505:

    {
   currentFunction->Macro = "vtkBooleanMacro";
   currentFunction->Name = vtkstrcat((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.str), "On");
   currentFunction->Comment = vtkstrdup(getComment());
   currentFunction->Signature =
     vtkstrcat3("void ", currentFunction->Name, "();");
   set_return(currentFunction, VTK_PARSE_VOID, "void", 0);
   output_function();

   currentFunction->Macro = "vtkBooleanMacro";
   currentFunction->Name = vtkstrcat((((yyGLRStackItem const *)yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.str), "Off");
   currentFunction->Comment = vtkstrdup(getComment());
   currentFunction->Signature =
     vtkstrcat3("void ", currentFunction->Name, "();");
   set_return(currentFunction, VTK_PARSE_VOID, "void", 0);
   output_function();
   }

    break;

  case 506:

    {startSig(); markSig();}

    break;

  case 507:

    {
   chopSig();
   outputSetVectorMacro((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.str), getType(), copySig(), 2);
   }

    break;

  case 508:

    {startSig(); markSig();}

    break;

  case 509:

    {
   chopSig();
   outputGetVectorMacro((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.str), getType(), copySig(), 2);
   }

    break;

  case 510:

    {startSig(); markSig();}

    break;

  case 511:

    {
   chopSig();
   outputSetVectorMacro((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.str), getType(), copySig(), 3);
   }

    break;

  case 512:

    {startSig(); markSig();}

    break;

  case 513:

    {
   chopSig();
   outputGetVectorMacro((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.str), getType(), copySig(), 3);
   }

    break;

  case 514:

    {startSig(); markSig();}

    break;

  case 515:

    {
   chopSig();
   outputSetVectorMacro((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.str), getType(), copySig(), 4);
   }

    break;

  case 516:

    {startSig(); markSig();}

    break;

  case 517:

    {
   chopSig();
   outputGetVectorMacro((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.str), getType(), copySig(), 4);
   }

    break;

  case 518:

    {startSig(); markSig();}

    break;

  case 519:

    {
   chopSig();
   outputSetVectorMacro((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.str), getType(), copySig(), 6);
   }

    break;

  case 520:

    {startSig(); markSig();}

    break;

  case 521:

    {
   chopSig();
   outputGetVectorMacro((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.str), getType(), copySig(), 6);
   }

    break;

  case 522:

    {startSig(); markSig();}

    break;

  case 523:

    {
   const char *typeText;
   chopSig();
   typeText = copySig();
   currentFunction->Macro = "vtkSetVectorMacro";
   currentFunction->Name = vtkstrcat("Set", (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.str));
   currentFunction->Signature =
     vtkstrcat7("void ", currentFunction->Name, "(", typeText,
                " a[", (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), "]);");
   currentFunction->Comment = vtkstrdup(getComment());
   add_parameter(currentFunction, (VTK_PARSE_POINTER | getType()),
                 getTypeId(), (int)strtol((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), NULL, 0));
   set_return(currentFunction, VTK_PARSE_VOID, "void", 0);
   output_function();
   }

    break;

  case 524:

    {startSig();}

    break;

  case 525:

    {
   chopSig();
   currentFunction->Macro = "vtkGetVectorMacro";
   currentFunction->Name = vtkstrcat("Get", (((yyGLRStackItem const *)yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.str));
   postSig(" *");
   postSig(currentFunction->Name);
   postSig("();");
   currentFunction->Comment = vtkstrdup(getComment());
   set_return(currentFunction, (VTK_PARSE_POINTER | getType()),
              getTypeId(), (int)strtol((((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), NULL, 0));
   output_function();
   }

    break;

  case 526:

    {
     currentFunction->Macro = "vtkViewportCoordinateMacro";
     currentFunction->Name = vtkstrcat3("Get", (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), "Coordinate");
     currentFunction->Signature =
       vtkstrcat3("vtkCoordinate *", currentFunction->Name, "();");
     currentFunction->Comment = vtkstrdup(getComment());
     set_return(currentFunction, VTK_PARSE_OBJECT_PTR, "vtkCoordinate", 0);
     output_function();

     currentFunction->Macro = "vtkViewportCoordinateMacro";
     currentFunction->Name = vtkstrcat("Set", (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str));
     currentFunction->Signature =
       vtkstrcat3("void ", currentFunction->Name, "(double, double);");
     currentFunction->Comment = vtkstrdup(getComment());
     add_parameter(currentFunction, VTK_PARSE_DOUBLE, "double", 0);
     add_parameter(currentFunction, VTK_PARSE_DOUBLE, "double", 0);
     set_return(currentFunction, VTK_PARSE_VOID, "void", 0);
     output_function();

     currentFunction->Macro = "vtkViewportCoordinateMacro";
     currentFunction->Name = vtkstrcat("Set", (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str));
     currentFunction->Signature =
       vtkstrcat3("void ", currentFunction->Name, "(double a[2]);");
     currentFunction->Comment = vtkstrdup(getComment());
     add_parameter(currentFunction, VTK_PARSE_DOUBLE_PTR, "double", 2);
     set_return(currentFunction, VTK_PARSE_VOID, "void", 0);
     output_function();

     currentFunction->Macro = "vtkViewportCoordinateMacro";
     currentFunction->Name = vtkstrcat("Get", (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str));
     currentFunction->Signature =
       vtkstrcat3("double *", currentFunction->Name, "();");
     currentFunction->Comment = vtkstrdup(getComment());
     set_return(currentFunction, VTK_PARSE_DOUBLE_PTR, "double", 2);
     output_function();
   }

    break;

  case 527:

    {
     currentFunction->Macro = "vtkWorldCoordinateMacro";
     currentFunction->Name = vtkstrcat3("Get", (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str), "Coordinate");
     currentFunction->Signature =
       vtkstrcat3("vtkCoordinate *", currentFunction->Name, "();");
     currentFunction->Comment = vtkstrdup(getComment());
     set_return(currentFunction, VTK_PARSE_OBJECT_PTR, "vtkCoordinate", 0);
     output_function();

     currentFunction->Macro = "vtkWorldCoordinateMacro";
     currentFunction->Name = vtkstrcat("Set", (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str));
     currentFunction->Signature =
       vtkstrcat3("void ", currentFunction->Name, "(double, double, double);");
     currentFunction->Comment = vtkstrdup(getComment());
     add_parameter(currentFunction, VTK_PARSE_DOUBLE, "double", 0);
     add_parameter(currentFunction, VTK_PARSE_DOUBLE, "double", 0);
     add_parameter(currentFunction, VTK_PARSE_DOUBLE, "double", 0);
     set_return(currentFunction, VTK_PARSE_VOID, "void", 0);
     output_function();

     currentFunction->Macro = "vtkWorldCoordinateMacro";
     currentFunction->Name = vtkstrcat("Set", (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str));
     currentFunction->Signature =
       vtkstrcat3("void ", currentFunction->Name, "(double a[3]);");
     currentFunction->Comment = vtkstrdup(getComment());
     add_parameter(currentFunction, VTK_PARSE_DOUBLE_PTR, "double", 3);
     set_return(currentFunction, VTK_PARSE_VOID, "void", 0);
     output_function();

     currentFunction->Macro = "vtkWorldCoordinateMacro";
     currentFunction->Name = vtkstrcat("Get", (((yyGLRStackItem const *)yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.str));
     currentFunction->Signature =
       vtkstrcat3("double *", currentFunction->Name, "();");
     currentFunction->Comment = vtkstrdup(getComment());
     set_return(currentFunction, VTK_PARSE_DOUBLE_PTR, "double", 3);
     output_function();
   }

    break;

  case 528:

    {
   currentFunction->Macro = "vtkTypeMacro";
   currentFunction->Name = "GetClassName";
   currentFunction->Signature = "const char *GetClassName();";
   currentFunction->Comment = vtkstrdup(getComment());
   set_return(currentFunction, (VTK_PARSE_CONST | VTK_PARSE_CHAR_PTR),
              "char", 0);
   output_function();

   currentFunction->Macro = "vtkTypeMacro";
   currentFunction->Name = "IsA";
   currentFunction->Signature = "int IsA(const char *name);";
   currentFunction->Comment = vtkstrdup(getComment());
   add_parameter(currentFunction, (VTK_PARSE_CONST | VTK_PARSE_CHAR_PTR),
                "char", 0);
   set_return(currentFunction, VTK_PARSE_INT, "int", 0);
   output_function();

   currentFunction->Macro = "vtkTypeMacro";
   currentFunction->Name = "NewInstance";
   currentFunction->Signature = vtkstrcat((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.str), " *NewInstance();");
   currentFunction->Comment = vtkstrdup(getComment());
   set_return(currentFunction, VTK_PARSE_OBJECT_PTR, (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.str), 0);
   output_function();

   currentFunction->Macro = "vtkTypeMacro";
   currentFunction->Name = "SafeDownCast";
   currentFunction->Signature =
     vtkstrcat((((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.str), " *SafeDownCast(vtkObject* o);");
   currentFunction->Comment = vtkstrdup(getComment());
   add_parameter(currentFunction, VTK_PARSE_OBJECT_PTR, "vtkObject", 0);
   set_return(currentFunction, (VTK_PARSE_STATIC | VTK_PARSE_OBJECT_PTR),
              (((yyGLRStackItem const *)yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.str), 0);
   output_function();
   }

    break;

  case 531:

    { ((*yyvalp).str) = "()"; }

    break;

  case 532:

    { ((*yyvalp).str) = "[]"; }

    break;

  case 533:

    { ((*yyvalp).str) = " new[]"; }

    break;

  case 534:

    { ((*yyvalp).str) = " delete[]"; }

    break;

  case 535:

    { ((*yyvalp).str) = "<"; }

    break;

  case 536:

    { ((*yyvalp).str) = ">"; }

    break;

  case 537:

    { ((*yyvalp).str) = ","; }

    break;

  case 538:

    { ((*yyvalp).str) = "="; }

    break;

  case 539:

    { ((*yyvalp).str) = ">>"; }

    break;

  case 540:

    { ((*yyvalp).str) = ">>"; }

    break;

  case 541:

    { ((*yyvalp).str) = vtkstrcat("\"\" ", (((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); }

    break;

  case 543:

    { ((*yyvalp).str) = "%"; }

    break;

  case 544:

    { ((*yyvalp).str) = "*"; }

    break;

  case 545:

    { ((*yyvalp).str) = "/"; }

    break;

  case 546:

    { ((*yyvalp).str) = "-"; }

    break;

  case 547:

    { ((*yyvalp).str) = "+"; }

    break;

  case 548:

    { ((*yyvalp).str) = "!"; }

    break;

  case 549:

    { ((*yyvalp).str) = "~"; }

    break;

  case 550:

    { ((*yyvalp).str) = "&"; }

    break;

  case 551:

    { ((*yyvalp).str) = "|"; }

    break;

  case 552:

    { ((*yyvalp).str) = "^"; }

    break;

  case 553:

    { ((*yyvalp).str) = " new"; }

    break;

  case 554:

    { ((*yyvalp).str) = " delete"; }

    break;

  case 555:

    { ((*yyvalp).str) = "<<="; }

    break;

  case 556:

    { ((*yyvalp).str) = ">>="; }

    break;

  case 557:

    { ((*yyvalp).str) = "<<"; }

    break;

  case 558:

    { ((*yyvalp).str) = ".*"; }

    break;

  case 559:

    { ((*yyvalp).str) = "->*"; }

    break;

  case 560:

    { ((*yyvalp).str) = "->"; }

    break;

  case 561:

    { ((*yyvalp).str) = "+="; }

    break;

  case 562:

    { ((*yyvalp).str) = "-="; }

    break;

  case 563:

    { ((*yyvalp).str) = "*="; }

    break;

  case 564:

    { ((*yyvalp).str) = "/="; }

    break;

  case 565:

    { ((*yyvalp).str) = "%="; }

    break;

  case 566:

    { ((*yyvalp).str) = "++"; }

    break;

  case 567:

    { ((*yyvalp).str) = "--"; }

    break;

  case 568:

    { ((*yyvalp).str) = "&="; }

    break;

  case 569:

    { ((*yyvalp).str) = "|="; }

    break;

  case 570:

    { ((*yyvalp).str) = "^="; }

    break;

  case 571:

    { ((*yyvalp).str) = "&&"; }

    break;

  case 572:

    { ((*yyvalp).str) = "||"; }

    break;

  case 573:

    { ((*yyvalp).str) = "=="; }

    break;

  case 574:

    { ((*yyvalp).str) = "!="; }

    break;

  case 575:

    { ((*yyvalp).str) = "<="; }

    break;

  case 576:

    { ((*yyvalp).str) = ">="; }

    break;

  case 577:

    { ((*yyvalp).str) = "typedef"; }

    break;

  case 578:

    { ((*yyvalp).str) = "typename"; }

    break;

  case 579:

    { ((*yyvalp).str) = "class"; }

    break;

  case 580:

    { ((*yyvalp).str) = "struct"; }

    break;

  case 581:

    { ((*yyvalp).str) = "union"; }

    break;

  case 582:

    { ((*yyvalp).str) = "template"; }

    break;

  case 583:

    { ((*yyvalp).str) = "public"; }

    break;

  case 584:

    { ((*yyvalp).str) = "protected"; }

    break;

  case 585:

    { ((*yyvalp).str) = "private"; }

    break;

  case 586:

    { ((*yyvalp).str) = "const"; }

    break;

  case 587:

    { ((*yyvalp).str) = "static"; }

    break;

  case 588:

    { ((*yyvalp).str) = "thread_local"; }

    break;

  case 589:

    { ((*yyvalp).str) = "constexpr"; }

    break;

  case 590:

    { ((*yyvalp).str) = "inline"; }

    break;

  case 591:

    { ((*yyvalp).str) = "virtual"; }

    break;

  case 592:

    { ((*yyvalp).str) = "explicit"; }

    break;

  case 593:

    { ((*yyvalp).str) = "decltype"; }

    break;

  case 594:

    { ((*yyvalp).str) = "default"; }

    break;

  case 595:

    { ((*yyvalp).str) = "extern"; }

    break;

  case 596:

    { ((*yyvalp).str) = "using"; }

    break;

  case 597:

    { ((*yyvalp).str) = "namespace"; }

    break;

  case 598:

    { ((*yyvalp).str) = "operator"; }

    break;

  case 599:

    { ((*yyvalp).str) = "enum"; }

    break;

  case 600:

    { ((*yyvalp).str) = "throw"; }

    break;

  case 601:

    { ((*yyvalp).str) = "noexcept"; }

    break;

  case 602:

    { ((*yyvalp).str) = "const_cast"; }

    break;

  case 603:

    { ((*yyvalp).str) = "dynamic_cast"; }

    break;

  case 604:

    { ((*yyvalp).str) = "static_cast"; }

    break;

  case 605:

    { ((*yyvalp).str) = "reinterpret_cast"; }

    break;

  case 618:

    { postSig("< "); }

    break;

  case 619:

    { postSig("> "); }

    break;

  case 621:

    { postSig(">"); }

    break;

  case 623:

    { chopSig(); postSig("::"); }

    break;

  case 627:

    {
      if ((((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str))[0] == '+' || ((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str))[0] == '-' ||
           ((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str))[0] == '*' || ((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str))[0] == '&') &&
          ((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str))[1] == '\0')
        {
        int c1 = 0;
        size_t l;
        const char *cp;
        chopSig();
        cp = getSig();
        l = getSigLength();
        if (l != 0) { c1 = cp[l-1]; }
        if (c1 != 0 && c1 != '(' && c1 != '[' && c1 != '=')
          {
          postSig(" ");
          }
        postSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str));
        if (vtkParse_CharType(c1, (CPRE_IDGIT|CPRE_QUOTE)) ||
            c1 == ')' || c1 == ']')
          {
          postSig(" ");
          }
        }
       else
        {
        postSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str));
        postSig(" ");
        }
    }

    break;

  case 628:

    { postSig(":"); postSig(" "); }

    break;

  case 629:

    { postSig("."); }

    break;

  case 630:

    { postSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); postSig(" "); }

    break;

  case 631:

    { postSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); postSig(" "); }

    break;

  case 633:

    {
      int c1 = 0;
      size_t l;
      const char *cp;
      chopSig();
      cp = getSig();
      l = getSigLength();
      if (l != 0) { c1 = cp[l-1]; }
      while (vtkParse_CharType(c1, CPRE_IDGIT) && l != 0)
        {
        --l;
        c1 = cp[l-1];
        }
      if (l < 2 || cp[l-1] != ':' || cp[l-2] != ':')
        {
        cp = add_const_scope(&cp[l]);
        resetSig(l);
        postSig(cp);
        }
      postSig(" ");
    }

    break;

  case 637:

    { postSig("< "); }

    break;

  case 638:

    { postSig("> "); }

    break;

  case 639:

    { postSig(">"); }

    break;

  case 641:

    { postSig("= "); }

    break;

  case 642:

    { chopSig(); postSig(", "); }

    break;

  case 644:

    { chopSig(); postSig(";"); }

    break;

  case 652:

    { postSig("= "); }

    break;

  case 653:

    { chopSig(); postSig(", "); }

    break;

  case 654:

    {
      chopSig();
      if (getSig()[getSigLength()-1] == '<') { postSig(" "); }
      postSig("<");
    }

    break;

  case 655:

    {
      chopSig();
      if (getSig()[getSigLength()-1] == '>') { postSig(" "); }
      postSig("> ");
    }

    break;

  case 658:

    { postSig("["); }

    break;

  case 659:

    { chopSig(); postSig("] "); }

    break;

  case 660:

    { postSig("[["); }

    break;

  case 661:

    { chopSig(); postSig("]] "); }

    break;

  case 662:

    { postSig("("); }

    break;

  case 663:

    { chopSig(); postSig(") "); }

    break;

  case 664:

    { postSig("("); postSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); postSig("*"); }

    break;

  case 665:

    { chopSig(); postSig(") "); }

    break;

  case 666:

    { postSig("("); postSig((((yyGLRStackItem const *)yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.str)); postSig("&"); }

    break;

  case 667:

    { chopSig(); postSig(") "); }

    break;

  case 668:

    { postSig("{ "); }

    break;

  case 669:

    { postSig("} "); }

    break;



      default: break;
    }

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YYUSE (yy0);
  YYUSE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yystos[yys->yylrState],
                &yys->yysemantics.yysval);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YYFPRINTF (stderr, "%s unresolved", yymsg);
          else
            YYFPRINTF (stderr, "%s incomplete", yymsg);
          YY_SYMBOL_PRINT ("", yystos[yys->yylrState], YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh);
        }
    }
}

/** Left-hand-side symbol for rule #YYRULE.  */
static yySymbol
yylhsNonterm (yyRuleNum yyrule)
{
  return yyr1[yyrule];
}

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1028)))

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static yybool
yyisDefaultedState (yyStateNum yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static yyRuleNum
yydefaultAction (yyStateNum yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yytable_value) \
  0

/** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static void
yygetLRActions (yyStateNum yystate, int yytoken,
                int* yyaction, const short int** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yypact_value_is_default (yypact[yystate])
      || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyaction = -yydefact[yystate];
      *yyconflicts = yyconfl;
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyaction = yytable[yyindex];
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
  else
    {
      *yyaction = 0;
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static yyStateNum
yyLRgotoState (yyStateNum yystate, yySymbol yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YYASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates = (yyGLRState**) YYMALLOC (16 * sizeof yyset->yystates[0]);
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds =
    (yybool*) YYMALLOC (16 * sizeof yyset->yylookaheadNeeds[0]);
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, size_t yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems =
    (yyGLRStackItem*) YYMALLOC (yysize * sizeof yystackp->yynextFree[0]);
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS,YYTOITEMS,YYX,YYTYPE) \
  &((YYTOITEMS) - ((YYFROMITEMS) - (yyGLRStackItem*) (YYX)))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  size_t yynewSize;
  size_t yyn;
  size_t yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems = (yyGLRStackItem*) YYMALLOC (yynewSize * sizeof yynewItems[0]);
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*(yybool *) yyp0)
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static void
yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YYDPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static void
yyremoveDeletes (yyGLRStack* yystackp)
{
  size_t yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            {
              YYDPRINTF ((stderr, "Removing dead stacks.\n"));
            }
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            {
              YYDPRINTF ((stderr, "Rename stack %lu -> %lu.\n",
                          (unsigned long int) yyi, (unsigned long int) yyj));
            }
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static void
yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
            size_t yyposn,
            YYSTYPE* yyvalp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yysval = *yyvalp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static void
yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
                 size_t yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YYASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if !YYDEBUG
# define YY_REDUCE_PRINT(Args)
#else
# define YY_REDUCE_PRINT(Args)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print Args;               \
} while (0)

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static void
yy_reduce_print (int yynormal, yyGLRStackItem* yyvsp, size_t yyk,
                 yyRuleNum yyrule)
{
  int yynrhs = yyrhsLength (yyrule);
  int yyi;
  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
             (unsigned long int) yyk, yyrule - 1,
             (unsigned long int) yyrline[yyrule]);
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyvsp[yyi - yynrhs + 1].yystate.yylrState],
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yysval
                                              );
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YYFPRINTF (stderr, " (unresolved)");
      YYFPRINTF (stderr, "\n");
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static YYRESULTTAG
yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
      YYASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      YY_REDUCE_PRINT ((1, yyrhs, yyk, yyrule));
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp,
                           yyvalp);
    }
  else
    {
      int yyi;
      yyGLRState* yys;
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YYASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      YY_REDUCE_PRINT ((0, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1, yyk, yyrule));
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
             yybool yyforceEval)
{
  size_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yysval;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yysval);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        {
          YYDPRINTF ((stderr, "Parse on stack %lu rejected by rule #%d.\n",
                     (unsigned long int) yyk, yyrule - 1));
        }
      if (yyflag != yyok)
        return yyflag;
      YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yysval);
    }
  else
    {
      size_t yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yyStateNum yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YYASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YYDPRINTF ((stderr,
                  "Reduced stack %lu by rule #%d; action deferred.  "
                  "Now in state %d.\n",
                  (unsigned long int) yyk, yyrule - 1, yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
                                (unsigned long int) yyk,
                                (unsigned long int) yyi));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static size_t
yysplitStack (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yysize >= yystackp->yytops.yycapacity)
    {
      yyGLRState** yynewStates;
      yybool* yynewLookaheadNeeds;

      yynewStates = YY_NULLPTR;

      if (yystackp->yytops.yycapacity
          > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      yynewStates =
        (yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
                                  (yystackp->yytops.yycapacity
                                   * sizeof yynewStates[0]));
      if (yynewStates == YY_NULLPTR)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yystates = yynewStates;

      yynewLookaheadNeeds =
        (yybool*) YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                             (yystackp->yytops.yycapacity
                              * sizeof yynewLookaheadNeeds[0]));
      if (yynewLookaheadNeeds == YY_NULLPTR)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize-1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       yyn > 0;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yysval = yys0->yysemantics.yysval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yysval = yys1->yysemantics.yysval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG yyresolveValue (yyGLRState* yys,
                                   yyGLRStack* yystackp);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp)
{
  if (0 < yyn)
    {
      YYASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp);
    yychar = yychar_current;
    yylval = yylval_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, empty>\n",
               yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
               yyx->yyrule - 1);
  else
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %lu .. %lu>\n",
               yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
               yyx->yyrule - 1, (unsigned long int) (yys->yyposn + 1),
               (unsigned long int) yyx->yystate->yyposn);
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YYFPRINTF (stderr, "%*s%s <empty>\n", yyindent+2, "",
                       yytokenName (yystos[yystates[yyi]->yylrState]));
          else
            YYFPRINTF (stderr, "%*s%s <tokens %lu .. %lu>\n", yyindent+2, "",
                       yytokenName (yystos[yystates[yyi]->yylrState]),
                       (unsigned long int) (yystates[yyi-1]->yyposn + 1),
                       (unsigned long int) yystates[yyi]->yyposn);
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1)
{
  YYUSE (yyx0);
  YYUSE (yyx1);

#if YYDEBUG
  YYFPRINTF (stderr, "Ambiguity detected.\n");
  YYFPRINTF (stderr, "Option 1,\n");
  yyreportTree (yyx0, 2);
  YYFPRINTF (stderr, "\nOption 2,\n");
  yyreportTree (yyx1, 2);
  YYFPRINTF (stderr, "\n");
#endif

  yyerror (YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yysval;
  YYRESULTTAG yyflag;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              return yyreportAmbiguity (yybest, yyp);
              /* break; */
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YYASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yysval);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yysval_other;
                yyflag = yyresolveAction (yyp, yystackp, &yysval_other);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yystos[yys->yylrState],
                                &yysval);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yysval);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yysval = yysval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             ));
    }
  return yyok;
}

static void
yycompressStack (yyGLRStack* yystackp)
{
  yyGLRState* yyp, *yyq, *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
       yyp != yystackp->yysplitPoint;
       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = ((yyGLRStackItem*) yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
                   size_t yyposn)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YYDPRINTF ((stderr, "Stack %lu Entering state %d\n",
                  (unsigned long int) yyk, yystate));

      YYASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, "Stack %lu dies.\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule]);
          if (yyflag == yyerr)
            {
              YYDPRINTF ((stderr,
                          "Stack %lu dies "
                          "(predicate failure or explicit user error).\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yySymbol yytoken;
          int yyaction;
          const short int* yyconflicts;

          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
          if (yychar == YYEMPTY)
            {
              YYDPRINTF ((stderr, "Reading a token: "));
              yychar = yylex ();
            }

          if (yychar <= YYEOF)
            {
              yychar = yytoken = YYEOF;
              YYDPRINTF ((stderr, "Now at end of input.\n"));
            }
          else
            {
              yytoken = YYTRANSLATE (yychar);
              YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
            }

          yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);

          while (*yyconflicts != 0)
            {
              YYRESULTTAG yyflag;
              size_t yynewStack = yysplitStack (yystackp, yyk);
              YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
                          (unsigned long int) yynewStack,
                          (unsigned long int) yyk));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts]);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn));
              else if (yyflag == yyerr)
                {
                  YYDPRINTF ((stderr, "Stack %lu dies.\n",
                              (unsigned long int) yynewStack));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
              yyconflicts += 1;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YYDPRINTF ((stderr, "Stack %lu dies.\n",
                          (unsigned long int) yyk));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction]);
              if (yyflag == yyerr)
                {
                  YYDPRINTF ((stderr,
                              "Stack %lu dies "
                              "(predicate failure or explicit user error).\n",
                              (unsigned long int) yyk));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}

static void
yyreportSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState != 0)
    return;
#if ! YYERROR_VERBOSE
  yyerror (YY_("syntax error"));
#else
  {
  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
  size_t yysize0 = yytnamerr (YY_NULLPTR, yytokenName (yytoken));
  size_t yysize = yysize0;
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULLPTR;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected").  */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
      yyarg[yycount++] = yytokenName (yytoken);
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for this
             state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;
          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytokenName (yyx);
                {
                  size_t yysz = yysize + yytnamerr (YY_NULLPTR, yytokenName (yyx));
                  yysize_overflow |= yysz < yysize;
                  yysize = yysz;
                }
              }
        }
    }

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  {
    size_t yysz = yysize + strlen (yyformat);
    yysize_overflow |= yysz < yysize;
    yysize = yysz;
  }

  if (!yysize_overflow)
    yymsg = (char *) YYMALLOC (yysize);

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
              yyp += yytnamerr (yyp, yyarg[yyi++]);
              yyformat += 2;
            }
          else
            {
              yyp++;
              yyformat++;
            }
        }
      yyerror (yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
  }
#endif /* YYERROR_VERBOSE */
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp)
{
  size_t yyk;
  int yyj;

  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yySymbol yytoken;
        if (yychar == YYEOF)
          yyFail (yystackp, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval);
          }
        YYDPRINTF ((stderr, "Reading a token: "));
        yychar = yylex ();
        if (yychar <= YYEOF)
          {
            yychar = yytoken = YYEOF;
            YYDPRINTF ((stderr, "Now at end of input.\n"));
          }
        else
          {
            yytoken = YYTRANSLATE (yychar);
            YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
          }
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
    if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
      break;
  if (yyk >= yystackp->yytops.yysize)
    yyFail (yystackp, YY_NULLPTR);
  for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
    yymarkStackDeleted (yystackp, yyk);
  yyremoveDeletes (yystackp);
  yycompressStack (yystackp);

  /* Now pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYTERROR;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yytable[yyj],
                          yys->yyposn, &yylval);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, YY_NULLPTR);
}

#define YYCHK1(YYE)                                                          \
  do {                                                                       \
    switch (YYE) {                                                           \
    case yyok:                                                               \
      break;                                                                 \
    case yyabort:                                                            \
      goto yyabortlab;                                                       \
    case yyaccept:                                                           \
      goto yyacceptlab;                                                      \
    case yyerr:                                                              \
      goto yyuser_error;                                                     \
    default:                                                                 \
      goto yybuglab;                                                         \
    }                                                                        \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  size_t yyposn;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode */
      while (yytrue)
        {
          yyRuleNum yyrule;
          int yyaction;
          const short int* yyconflicts;

          yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
          YYDPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {

                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
            }
          else
            {
              yySymbol yytoken;
              if (yychar == YYEMPTY)
                {
                  YYDPRINTF ((stderr, "Reading a token: "));
                  yychar = yylex ();
                }

              if (yychar <= YYEOF)
                {
                  yychar = yytoken = YYEOF;
                  YYDPRINTF ((stderr, "Now at end of input.\n"));
                }
              else
                {
                  yytoken = YYTRANSLATE (yychar);
                  YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
                }

              yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
              if (*yyconflicts != 0)
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {

                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
            }
        }

      while (yytrue)
        {
          yySymbol yytoken_to_shift;
          size_t yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack));
              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));

              yyreportSyntaxError (&yystack);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              int yyaction;
              const short int* yyconflicts;
              yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
              yygetLRActions (yystate, yytoken_to_shift, &yyaction,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yys));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval);
              YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
                          (unsigned long int) yys,
                          yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack));
              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturn;

 yybuglab:
  YYASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturn;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

 yyreturn:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          size_t yysize = yystack.yytops.yysize;
          size_t yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                  if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YYFPRINTF (stderr, " -> ");
    }
  YYFPRINTF (stderr, "%d@%lu", yys->yylrState,
             (unsigned long int) yys->yyposn);
}

static void
yypstates (yyGLRState* yyst)
{
  if (yyst == YY_NULLPTR)
    YYFPRINTF (stderr, "<null>");
  else
    yy_yypstack (yyst);
  YYFPRINTF (stderr, "\n");
}

static void
yypstack (yyGLRStack* yystackp, size_t yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

#define YYINDEX(YYX)                                                         \
    ((YYX) == YY_NULLPTR ? -1 : (yyGLRStackItem*) (YYX) - yystackp->yyitems)


static void
yypdumpstack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yyp;
  size_t yyi;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YYFPRINTF (stderr, "%3lu. ",
                 (unsigned long int) (yyp - yystackp->yyitems));
      if (*(yybool *) yyp)
        {
          YYASSERT (yyp->yystate.yyisState);
          YYASSERT (yyp->yyoption.yyisState);
          YYFPRINTF (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
                     yyp->yystate.yyresolved, yyp->yystate.yylrState,
                     (unsigned long int) yyp->yystate.yyposn,
                     (long int) YYINDEX (yyp->yystate.yypred));
          if (! yyp->yystate.yyresolved)
            YYFPRINTF (stderr, ", firstVal: %ld",
                       (long int) YYINDEX (yyp->yystate
                                             .yysemantics.yyfirstVal));
        }
      else
        {
          YYASSERT (!yyp->yystate.yyisState);
          YYASSERT (!yyp->yyoption.yyisState);
          YYFPRINTF (stderr, "Option. rule: %d, state: %ld, next: %ld",
                     yyp->yyoption.yyrule - 1,
                     (long int) YYINDEX (yyp->yyoption.yystate),
                     (long int) YYINDEX (yyp->yyoption.yynext));
        }
      YYFPRINTF (stderr, "\n");
    }
  YYFPRINTF (stderr, "Tops:");
  for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
    YYFPRINTF (stderr, "%lu: %ld; ", (unsigned long int) yyi,
               (long int) YYINDEX (yystackp->yytops.yystates[yyi]));
  YYFPRINTF (stderr, "\n");
}
#endif

#undef yylval
#undef yychar
#undef yynerrs





#include <string.h>
#include "lex.yy.c"

/* fill in the type name if none given */
const char *type_class(unsigned int type, const char *classname)
{
  if (classname)
    {
    if (classname[0] == '\0')
      {
      switch ((type & VTK_PARSE_BASE_TYPE))
        {
        case 0:
          classname = "auto";
          break;
        case VTK_PARSE_VOID:
          classname = "void";
          break;
        case VTK_PARSE_BOOL:
          classname = "bool";
          break;
        case VTK_PARSE_FLOAT:
          classname = "float";
          break;
        case VTK_PARSE_DOUBLE:
          classname = "double";
          break;
        case VTK_PARSE_LONG_DOUBLE:
          classname = "long double";
          break;
        case VTK_PARSE_CHAR:
          classname = "char";
          break;
        case VTK_PARSE_CHAR16_T:
          classname = "char16_t";
          break;
        case VTK_PARSE_CHAR32_T:
          classname = "char32_t";
          break;
        case VTK_PARSE_WCHAR_T:
          classname = "wchar_t";
          break;
        case VTK_PARSE_UNSIGNED_CHAR:
          classname = "unsigned char";
          break;
        case VTK_PARSE_SIGNED_CHAR:
          classname = "signed char";
          break;
        case VTK_PARSE_SHORT:
          classname = "short";
          break;
        case VTK_PARSE_UNSIGNED_SHORT:
          classname = "unsigned short";
          break;
        case VTK_PARSE_INT:
          classname = "int";
          break;
        case VTK_PARSE_UNSIGNED_INT:
          classname = "unsigned int";
          break;
        case VTK_PARSE_LONG:
          classname = "long";
          break;
        case VTK_PARSE_UNSIGNED_LONG:
          classname = "unsigned long";
          break;
        case VTK_PARSE_LONG_LONG:
          classname = "long long";
          break;
        case VTK_PARSE_UNSIGNED_LONG_LONG:
          classname = "unsigned long long";
          break;
        case VTK_PARSE___INT64:
          classname = "__int64";
          break;
        case VTK_PARSE_UNSIGNED___INT64:
          classname = "unsigned __int64";
          break;
        }
      }
    }

  return classname;
}

/* check whether this is the class we are looking for */
void start_class(const char *classname, int is_struct_or_union)
{
  ClassInfo *outerClass = currentClass;
  pushClass();
  currentClass = (ClassInfo *)malloc(sizeof(ClassInfo));
  vtkParse_InitClass(currentClass);
  currentClass->Name = classname;
  if (is_struct_or_union == 1)
    {
    currentClass->ItemType = VTK_STRUCT_INFO;
    }
  if (is_struct_or_union == 2)
    {
    currentClass->ItemType = VTK_UNION_INFO;
    }

  if (classname && classname[0] != '\0')
    {
    /* if name of class being defined contains "::" or "<..>", then skip it */
    const char *cp = classname;
    while (*cp != '\0' && *cp != ':' && *cp != '>')
      {
      cp++;
      }
    if (*cp == '\0')
      {
      if (outerClass)
        {
        vtkParse_AddClassToClass(outerClass, currentClass);
        }
      else
        {
        vtkParse_AddClassToNamespace(currentNamespace, currentClass);
        }
      }
    }

  /* template information */
  if (currentTemplate)
    {
    currentClass->Template = currentTemplate;
    currentTemplate = NULL;
    }

  /* comment, if any */
  currentClass->Comment = vtkstrdup(getComment());

  access_level = VTK_ACCESS_PRIVATE;
  if (is_struct_or_union)
    {
    access_level = VTK_ACCESS_PUBLIC;
    }

  vtkParse_InitFunction(currentFunction);
  startSig();
  clearComment();
}

/* reached the end of a class definition */
void end_class()
{
  /* add default constructors */
  vtkParse_AddDefaultConstructors(currentClass, data->Strings);

  popClass();
}

/* add a base class to the specified class */
void add_base_class(ClassInfo *cls, const char *name, int al,
  unsigned int extra)
{
  /* "extra" can contain VTK_PARSE_VIRTUAL and VTK_PARSE_PACK */
  if (cls && al == VTK_ACCESS_PUBLIC &&
      (extra & VTK_PARSE_VIRTUAL) == 0 &&
      (extra & VTK_PARSE_PACK) == 0)
    {
    vtkParse_AddStringToArray(&cls->SuperClasses,
                              &cls->NumberOfSuperClasses,
                              name);
    }
}

/* add a using declaration or directive */
void add_using(const char *name, int is_namespace)
{
  size_t i;
  UsingInfo *item;

  item = (UsingInfo *)malloc(sizeof(UsingInfo));
  vtkParse_InitUsing(item);
  if (is_namespace)
    {
    item->Name = NULL;
    item->Scope = name;
    }
  else
    {
    i = strlen(name);
    while (i > 0 && name[i-1] != ':') { i--; }
    item->Name = vtkstrdup(&name[i]);
    while (i > 0 && name[i-1] == ':') { i--; }
    item->Scope = vtkstrndup(name, i);
    }

  if (currentClass)
    {
    vtkParse_AddUsingToClass(currentClass, item);
    }
  else
    {
    vtkParse_AddUsingToNamespace(currentNamespace, item);
    }
}

/* start a new enum */
void start_enum(const char *name, int is_scoped,
                unsigned int type, const char *basename)
{
  EnumInfo *item;

  currentEnumType = (type ? type : VTK_PARSE_INT);
  currentEnumName = "int";
  currentEnumValue = NULL;

  if (type == 0 && is_scoped)
    {
    type = VTK_PARSE_INT;
    }

  if (name)
    {
    currentEnumName = name;
    item = (EnumInfo *)malloc(sizeof(EnumInfo));
    vtkParse_InitEnum(item);
    item->Name = name;
    item->Access = access_level;

    if (currentClass)
      {
      vtkParse_AddEnumToClass(currentClass, item);
      }
    else
      {
      vtkParse_AddEnumToNamespace(currentNamespace, item);
      }

    if (type)
      {
      vtkParse_AddStringToArray(&item->SuperClasses,
                                &item->NumberOfSuperClasses,
                                type_class(type, basename));
      }

    if (is_scoped)
      {
      pushClass();
      currentClass = item;
      }
    }
}

/* finish the enum */
void end_enum()
{
  if (currentClass && currentClass->ItemType == VTK_ENUM_INFO)
    {
    popClass();
    }

  currentEnumName = NULL;
  currentEnumValue = NULL;
}

/* add a constant to the enum */
void add_enum(const char *name, const char *value)
{
  static char text[2048];
  int i;
  long j;

  if (value)
    {
    strcpy(text, value);
    currentEnumValue = value;
    }
  else if (currentEnumValue)
    {
    i = strlen(text);
    while (i > 0 && text[i-1] >= '0' &&
           text[i-1] <= '9') { i--; }

    if (i == 0 || text[i-1] == ' ' ||
        (i > 1 && text[i-2] == ' ' &&
         (text[i-1] == '-' || text[i-1] == '+')))
      {
      if (i > 0 && text[i-1] != ' ')
        {
        i--;
        }
      j = (int)strtol(&text[i], NULL, 10);
      sprintf(&text[i], "%li", j+1);
      }
    else
      {
      i = strlen(text);
      strcpy(&text[i], " + 1");
      }
    currentEnumValue = vtkstrdup(text);
    }
  else
    {
    strcpy(text, "0");
    currentEnumValue = "0";
    }

  add_constant(name, currentEnumValue, currentEnumType, currentEnumName, 2);
}

/* for a macro constant, guess the constant type, doesn't do any math */
unsigned int guess_constant_type(const char *valstring)
{
  unsigned int valtype = 0;
  size_t k;
  int i;
  int is_name = 0;

  if (valstring == NULL || valstring[0] == '\0')
    {
    return 0;
    }

  k = vtkParse_SkipId(valstring);
  if (valstring[k] == '\0')
    {
    is_name = 1;
    }

  if (strcmp(valstring, "true") == 0 || strcmp(valstring, "false") == 0)
    {
    return VTK_PARSE_BOOL;
    }

  if (strcmp(valstring, "nullptr") == 0)
    {
    return VTK_PARSE_NULLPTR_T;
    }

  if (valstring[0] == '\'')
    {
    return VTK_PARSE_CHAR;
    }

  if (strncmp(valstring, "VTK_TYPE_CAST(", 14) == 0 ||
      strncmp(valstring, "static_cast<", 12) == 0 ||
      strncmp(valstring, "const_cast<", 11) == 0 ||
      strncmp(valstring, "(", 1) == 0)
    {
    const char *cp;
    size_t n;
    int is_unsigned = 0;

    cp = &valstring[1];
    if (valstring[0] == 'c')
      {
      cp = &valstring[11];
      }
    else if (valstring[0] == 's')
      {
      cp = &valstring[12];
      }
    else if (valstring[0] == 'V')
      {
      cp = &valstring[14];
      }

    if (strncmp(cp, "unsigned ", 9) == 0)
      {
      is_unsigned = 1;
      cp += 9;
      }

    n = strlen(cp);
    for (k = 0; k < n && cp[k] != ',' &&
         cp[k] != '>' && cp[k] != ')'; k++) { ; };

    if (strncmp(cp, "long long", k) == 0)
      { valtype = VTK_PARSE_LONG_LONG; }
    else if (strncmp(cp, "__int64", k) == 0)
      { valtype = VTK_PARSE___INT64; }
    else if (strncmp(cp, "long", k) == 0)
      { valtype = VTK_PARSE_LONG; }
    else if (strncmp(cp, "short", k) == 0)
      { valtype = VTK_PARSE_SHORT; }
    else if (strncmp(cp, "signed char", k) == 0)
      { valtype = VTK_PARSE_SIGNED_CHAR; }
    else if (strncmp(cp, "char", k) == 0)
      { valtype = VTK_PARSE_CHAR; }
    else if (strncmp(cp, "int", k) == 0 ||
             strncmp(cp, "signed", k) == 0)
      { valtype = VTK_PARSE_INT; }
    else if (strncmp(cp, "float", k) == 0)
      { valtype = VTK_PARSE_FLOAT; }
    else if (strncmp(cp, "double", k) == 0)
      { valtype = VTK_PARSE_DOUBLE; }
    else if (strncmp(cp, "char *", k) == 0)
      { valtype = VTK_PARSE_CHAR_PTR; }

    if (is_unsigned)
      {
      if (valtype == 0) { valtype = VTK_PARSE_INT; }
      valtype = (valtype | VTK_PARSE_UNSIGNED);
      }

    if (valtype != 0)
      {
      return valtype;
      }
    }

  /* check the current scope */
  if (is_name)
    {
    NamespaceInfo *scope = currentNamespace;
    if (namespaceDepth > 0)
      {
      scope = namespaceStack[0];
      }

    for (i = 0; i < scope->NumberOfConstants; i++)
      {
      if (strcmp(scope->Constants[i]->Name, valstring) == 0)
        {
        return scope->Constants[i]->Type;
        }
      }
    }

  /* check for preprocessor macros */
  if (is_name)
    {
    MacroInfo *macro = vtkParsePreprocess_GetMacro(
      preprocessor, valstring);

    if (macro && !macro->IsFunction)
      {
      return guess_constant_type(macro->Definition);
      }
    }

  /* fall back to the preprocessor to evaluate the constant */
    {
    preproc_int_t val;
    int is_unsigned;
    int result = vtkParsePreprocess_EvaluateExpression(
      preprocessor, valstring, &val, &is_unsigned);

    if (result == VTK_PARSE_PREPROC_DOUBLE)
      {
      return VTK_PARSE_DOUBLE;
      }
    else if (result == VTK_PARSE_PREPROC_FLOAT)
      {
      return VTK_PARSE_FLOAT;
      }
    else if (result == VTK_PARSE_PREPROC_STRING)
      {
      return VTK_PARSE_CHAR_PTR;
      }
    else if (result == VTK_PARSE_OK)
      {
      if (is_unsigned)
        {
        if ((preproc_uint_t)val <= VTK_UNSIGNED_INT_MAX)
          {
          return VTK_PARSE_UNSIGNED_INT;
          }
        else
          {
#if defined(VTK_TYPE_USE_LONG_LONG)
          return VTK_PARSE_UNSIGNED_LONG_LONG;
#elif defined(VTK_TYPE_USE___INT64)
          return VTK_PARSE_UNSIGNED___INT64;
#else
          return VTK_PARSE_UNSIGNED_LONG;
#endif
          }
        }
      else
        {
        if (val >= VTK_INT_MIN && val <= VTK_INT_MAX)
          {
          return VTK_PARSE_INT;
          }
        else
          {
#if defined(VTK_TYPE_USE_LONG_LONG)
          return VTK_PARSE_LONG_LONG;
#elif defined(VTK_TYPE_USE___INT64)
          return VTK_PARSE___INT64;
#else
          return VTK_PARSE_LONG;
#endif
          }
        }
      }
    }

  return 0;
}

/* add a constant to the current class or namespace */
void add_constant(const char *name, const char *value,
                  unsigned int type, const char *typeclass, int flag)
{
  ValueInfo *con = (ValueInfo *)malloc(sizeof(ValueInfo));
  vtkParse_InitValue(con);
  con->ItemType = VTK_CONSTANT_INFO;
  con->Name = name;
  con->Value = value;
  con->Type = type;
  con->Class = type_class(type, typeclass);

  if (flag == 2)
    {
    con->IsEnum = 1;
    }

  if (flag == 1)
    {
    /* actually a macro, need to guess the type */
    ValueInfo **cptr = data->Contents->Constants;
    int n = data->Contents->NumberOfConstants;
    int i;

    con->Access = VTK_ACCESS_PUBLIC;
    if (con->Type == 0)
      {
      con->Type = guess_constant_type(con->Value);
      }

    for (i = 0; i < n; i++)
      {
      if (strcmp(cptr[i]->Name, con->Name) == 0)
        {
        break;
        }
      }

    if (i == n)
      {
      vtkParse_AddConstantToNamespace(data->Contents, con);
      }
    else
      {
      vtkParse_FreeValue(con);
      }
    }
  else if (currentClass)
    {
    con->Access = access_level;
    vtkParse_AddConstantToClass(currentClass, con);
    }
  else
    {
    con->Access = VTK_ACCESS_PUBLIC;
    vtkParse_AddConstantToNamespace(currentNamespace, con);
    }
}

/* if the name is a const in this namespace, the scope it */
const char *add_const_scope(const char *name)
{
  static char text[256];
  NamespaceInfo *scope = currentNamespace;
  int i, j;
  int addscope = 0;

  strcpy(text, name);

  if (currentClass)
    {
    for (j = 0; j < currentClass->NumberOfConstants; j++)
      {
      if (strcmp(currentClass->Constants[j]->Name, text) == 0)
        {
        prepend_scope(text, currentClass->Name);
        addscope = 1;
        }
      }
    }
  i = namespaceDepth;
  while (scope && scope->Name)
    {
    if (addscope)
      {
      prepend_scope(text, scope->Name);
      }
    else
      {
      for (j = 0; j < scope->NumberOfConstants; j++)
        {
        if (strcmp(scope->Constants[j]->Name, text) == 0)
          {
          prepend_scope(text, scope->Name);
          addscope = 1;
          }
        }
      }

    scope = 0;
    if (i > 0)
      {
      scope = namespaceStack[--i];
      }
    }

  return text;
}

/* guess the type from the ID */
unsigned int guess_id_type(const char *cp)
{
  unsigned int t = 0;

  if (cp)
    {
    size_t i;
    const char *dp;

    i = strlen(cp);
    while (i > 0 && cp[i-1] != ':') { i--; }
    dp = &cp[i];

    if (strcmp(dp, "vtkStdString") == 0 ||
        strcmp(cp, "std::string") == 0)
      {
      t = VTK_PARSE_STRING;
      }
    else if (strcmp(dp, "vtkUnicodeString") == 0)
      {
      t = VTK_PARSE_UNICODE_STRING;
      }
    else if (strncmp(dp, "vtk", 3) == 0)
      {
      t = VTK_PARSE_OBJECT;
      }
    else if (strncmp(dp, "Q", 1) == 0 ||
             strncmp(cp, "Qt::", 4) == 0)
      {
      t = VTK_PARSE_QOBJECT;
      }
    else
      {
      t = VTK_PARSE_UNKNOWN;
      }
    }

  return t;
}

/* add a template parameter to the current template */
void add_template_parameter(
  unsigned int datatype, unsigned int extra, const char *funcSig)
{
  ValueInfo *param = (ValueInfo *)malloc(sizeof(ValueInfo));
  vtkParse_InitValue(param);
  handle_complex_type(param, datatype, extra, funcSig);
  param->Name = getVarName();
  vtkParse_AddParameterToTemplate(currentTemplate, param);
}

/* add a parameter to a function */
void add_parameter(FunctionInfo *func, unsigned int type,
                   const char *typeclass, int count)
{
  char text[64];
  ValueInfo *param = (ValueInfo *)malloc(sizeof(ValueInfo));
  vtkParse_InitValue(param);

  param->Type = type;
  param->Class = type_class(type, typeclass);

  if (count)
    {
    param->Count = count;
    sprintf(text, "%i", count);
    vtkParse_AddStringToArray(&param->Dimensions, &param->NumberOfDimensions,
                              vtkstrdup(text));
    }

  add_legacy_parameter(func, param);

  vtkParse_AddParameterToFunction(func, param);
}

/* set the return type for the current function */
void set_return(FunctionInfo *func, unsigned int type,
                const char *typeclass, int count)
{
  char text[64];
  ValueInfo *val = (ValueInfo *)malloc(sizeof(ValueInfo));

  vtkParse_InitValue(val);
  val->Type = type;
  val->Class = type_class(type, typeclass);

  if (count)
    {
    val->Count = count;
    sprintf(text, "%i", count);
    vtkParse_AddStringToArray(&val->Dimensions, &val->NumberOfDimensions,
                              vtkstrdup(text));
    }

  func->ReturnValue = val;

#ifndef VTK_PARSE_LEGACY_REMOVE
  func->ReturnType = val->Type;
  func->ReturnClass = val->Class;
  func->HaveHint = (count > 0);
  func->HintSize = count;
#endif
}

int count_from_dimensions(ValueInfo *val)
{
  int count, i, n;
  const char *cp;

  /* count is the product of the dimensions */
  count = 0;
  if (val->NumberOfDimensions)
    {
    count = 1;
    for (i = 0; i < val->NumberOfDimensions; i++)
      {
      n = 0;
      cp = val->Dimensions[i];
      if (cp[0] != '\0')
        {
        while (*cp != '\0' && *cp >= '0' && *cp <= '9') { cp++; }
        while (*cp != '\0' && (*cp == 'u' || *cp == 'l' ||
                               *cp == 'U' || *cp == 'L')) { cp++; }
        if (*cp == '\0')
          {
          n = (int)strtol(val->Dimensions[i], NULL, 0);
          }
        }
      count *= n;
      }
    }

  return count;
}

/* deal with types that include function pointers or arrays */
void handle_complex_type(
  ValueInfo *val, unsigned int datatype, unsigned int extra,
  const char *funcSig)
{
  FunctionInfo *func = 0;

  /* remove specifiers like "friend" and "typedef" */
  datatype &= VTK_PARSE_QUALIFIED_TYPE;

  /* remove the pack specifier caused by "..." */
  if ((extra & VTK_PARSE_PACK) != 0)
    {
    val->IsPack = 1;
    extra ^= VTK_PARSE_PACK;
    }

  /* if "extra" was set, parentheses were involved */
  if ((extra & VTK_PARSE_BASE_TYPE) == VTK_PARSE_FUNCTION)
    {
    /* the current type becomes the function return type */
    func = getFunction();
    func->ReturnValue = (ValueInfo *)malloc(sizeof(ValueInfo));
    vtkParse_InitValue(func->ReturnValue);
    func->ReturnValue->Type = datatype;
    func->ReturnValue->Class = type_class(datatype, getTypeId());
    if (funcSig) { func->Signature = vtkstrdup(funcSig); }
    val->Function = func;

#ifndef VTK_PARSE_LEGACY_REMOVE
    func->ReturnType = func->ReturnValue->Type;
    func->ReturnClass = func->ReturnValue->Class;
#endif

    /* the val type is whatever was inside the parentheses */
    clearTypeId();
    setTypeId(func->Class ? "method" : "function");
    datatype = (extra & (VTK_PARSE_UNQUALIFIED_TYPE | VTK_PARSE_RVALUE));
    }
  else if ((extra & VTK_PARSE_INDIRECT) == VTK_PARSE_BAD_INDIRECT)
    {
    datatype = (datatype | VTK_PARSE_BAD_INDIRECT);
    }
  else if ((extra & VTK_PARSE_INDIRECT) != 0)
    {
    extra = (extra & (VTK_PARSE_INDIRECT | VTK_PARSE_RVALUE));

    if ((extra & VTK_PARSE_REF) != 0)
      {
      datatype = (datatype | (extra & (VTK_PARSE_REF | VTK_PARSE_RVALUE)));
      extra = (extra & ~(VTK_PARSE_REF | VTK_PARSE_RVALUE));
      }

    if (extra != 0 && getArrayNDims() > 0)
      {
      /* pointer represents an unsized array bracket */
      datatype = add_indirection(datatype, VTK_PARSE_ARRAY);
      extra = ((extra >> 2) & VTK_PARSE_POINTER_MASK);
      }

    datatype = add_indirection(datatype, extra);
    }

  if (getArrayNDims() == 1)
    {
    if ((datatype & VTK_PARSE_POINTER_LOWMASK) != VTK_PARSE_ARRAY)
      {
      /* turn the first set of brackets into a pointer */
      datatype = add_indirection(datatype, VTK_PARSE_POINTER);
      }
    else
      {
      pushArrayFront("");
      }
    }
  else if (getArrayNDims() > 1)
    {
    if ((datatype & VTK_PARSE_POINTER_LOWMASK) != VTK_PARSE_ARRAY)
      {
      /* turn the first set of brackets into a pointer */
      datatype = add_indirection(datatype, VTK_PARSE_ARRAY);
      }
    else
      {
      pushArrayFront("");
      }
    }

  /* get the data type */
  val->Type = datatype;
  val->Class = type_class(datatype, getTypeId());

  /* copy contents of all brackets to the ArgDimensions */
  val->NumberOfDimensions = getArrayNDims();
  val->Dimensions = getArray();
  clearArray();

  /* count is the product of the dimensions */
  val->Count = count_from_dimensions(val);
}

/* add a parameter to the legacy part of the FunctionInfo struct */
void add_legacy_parameter(FunctionInfo *func, ValueInfo *param)
{
#ifndef VTK_PARSE_LEGACY_REMOVE
  int i = func->NumberOfArguments;

  if (i < MAX_ARGS)
    {
    func->NumberOfArguments = i + 1;
    func->ArgTypes[i] = param->Type;
    func->ArgClasses[i] = param->Class;
    func->ArgCounts[i] = param->Count;

    /* legacy wrappers need VTK_PARSE_FUNCTION without POINTER */
    if (param->Type == VTK_PARSE_FUNCTION_PTR)
      {
      /* check for signature "void (*func)(void *)" */
      if (param->Function->NumberOfParameters == 1 &&
          param->Function->Parameters[0]->Type == VTK_PARSE_VOID_PTR &&
          param->Function->Parameters[0]->NumberOfDimensions == 0 &&
          param->Function->ReturnValue->Type == VTK_PARSE_VOID)
        {
        func->ArgTypes[i] = VTK_PARSE_FUNCTION;
        }
      }
    }
  else
    {
    func->ArrayFailure = 1;
    }
#endif
}


/* reject the function, do not output it */
void reject_function()
{
  vtkParse_InitFunction(currentFunction);
  startSig();
  getMacro();
}

/* a simple routine that updates a few variables */
void output_function()
{
  const char *macro = getMacro();
  size_t n;
  int i, j;
  int match;

  /* reject template specializations */
  n = strlen(currentFunction->Name);
  if (currentFunction->Name[n-1] == '>')
    {
    /* make sure there is a matching angle bracket */
    while (n > 0 && currentFunction->Name[n-1] != '<') { n--; }
    if (n > 0)
      {
      reject_function();
      return;
      }
    }

  /* friend */
  if (currentFunction->ReturnValue &&
      currentFunction->ReturnValue->Type & VTK_PARSE_FRIEND)
    {
    currentFunction->ReturnValue->Type ^= VTK_PARSE_FRIEND;
    output_friend_function();
    return;
    }

  /* typedef */
  if (currentFunction->ReturnValue &&
      currentFunction->ReturnValue->Type & VTK_PARSE_TYPEDEF)
    {
    /* for now, reject it instead of turning a method into a typedef */
    currentFunction->ReturnValue->Type ^= VTK_PARSE_TYPEDEF;
    reject_function();
    return;
    }

  /* static */
  if (currentFunction->ReturnValue &&
      currentFunction->ReturnValue->Type & VTK_PARSE_STATIC)
    {
    currentFunction->IsStatic = 1;
    }

  /* virtual */
  if (currentFunction->ReturnValue &&
      currentFunction->ReturnValue->Type & VTK_PARSE_VIRTUAL)
    {
    currentFunction->IsVirtual = 1;
    }

  /* the signature */
  if (!currentFunction->Signature)
    {
    currentFunction->Signature = getSig();
    }

  /* template information */
  if (currentTemplate)
    {
    currentFunction->Template = currentTemplate;
    currentTemplate = NULL;
    }

  /* a void argument is the same as no parameters */
  if (currentFunction->NumberOfParameters == 1 &&
      (currentFunction->Parameters[0]->Type & VTK_PARSE_UNQUALIFIED_TYPE) ==
      VTK_PARSE_VOID)
    {
    currentFunction->NumberOfParameters = 0;
    }

  /* is it defined in a legacy macro? */
  if (macro && strcmp(macro, "VTK_LEGACY") == 0)
    {
    currentFunction->IsLegacy = 1;
    }

  /* set public, protected */
  if (currentClass)
    {
    currentFunction->Access = access_level;
    }
  else
    {
    currentFunction->Access = VTK_ACCESS_PUBLIC;
    }

#ifndef VTK_PARSE_LEGACY_REMOVE
  /* a void argument is the same as no parameters */
  if (currentFunction->NumberOfArguments == 1 &&
      (currentFunction->ArgTypes[0] & VTK_PARSE_UNQUALIFIED_TYPE) ==
      VTK_PARSE_VOID)
    {
    currentFunction->NumberOfArguments = 0;
    }

  /* if return type is void, set return class to void */
  if (currentFunction->ReturnClass == NULL &&
      (currentFunction->ReturnType & VTK_PARSE_UNQUALIFIED_TYPE) ==
       VTK_PARSE_VOID)
    {
    currentFunction->ReturnClass = "void";
    }

  /* set legacy flags */
  if (currentClass)
    {
    currentFunction->IsPublic = (access_level == VTK_ACCESS_PUBLIC);
    currentFunction->IsProtected = (access_level == VTK_ACCESS_PROTECTED);
    }
  else
    {
    currentFunction->IsPublic = 1;
    currentFunction->IsProtected = 0;
    }

  /* check for too many parameters */
  if (currentFunction->NumberOfParameters > MAX_ARGS)
    {
    currentFunction->ArrayFailure = 1;
    }

  for (i = 0; i < currentFunction->NumberOfParameters; i++)
    {
    ValueInfo *param = currentFunction->Parameters[i];
    /* tell old wrappers that multi-dimensional arrays are bad */
    if ((param->Type & VTK_PARSE_POINTER_MASK) != 0)
      {
      if (((param->Type & VTK_PARSE_INDIRECT) == VTK_PARSE_BAD_INDIRECT) ||
          ((param->Type & VTK_PARSE_POINTER_LOWMASK) != VTK_PARSE_POINTER))
        {
        currentFunction->ArrayFailure = 1;
        }
      }

    /* allow only "void (*func)(void *)" as a valid function pointer */
    if ((param->Type & VTK_PARSE_BASE_TYPE) == VTK_PARSE_FUNCTION)
      {
      if (i != 0 || param->Type != VTK_PARSE_FUNCTION_PTR ||
          currentFunction->NumberOfParameters != 2 ||
          currentFunction->Parameters[1]->Type != VTK_PARSE_VOID_PTR ||
          param->Function->NumberOfParameters != 1 ||
          param->Function->Parameters[0]->Type != VTK_PARSE_VOID_PTR ||
          param->Function->Parameters[0]->NumberOfDimensions != 0 ||
          param->Function->ReturnValue->Type != VTK_PARSE_VOID)
        {
        currentFunction->ArrayFailure = 1;
        }
      }
    }
#endif /* VTK_PARSE_LEGACY_REMOVE */

  if (currentClass)
    {
    /* is it a delete function */
    if (currentFunction->Name && !strcmp("Delete",currentFunction->Name))
      {
      currentClass->HasDelete = 1;
      }

    currentFunction->Class = currentClass->Name;
    vtkParse_AddFunctionToClass(currentClass, currentFunction);

    currentFunction = (FunctionInfo *)malloc(sizeof(FunctionInfo));
    }
  else
    {
    /* make sure this function isn't a repeat */
    match = 0;
    for (i = 0; i < currentNamespace->NumberOfFunctions; i++)
      {
      if (currentNamespace->Functions[i]->Name &&
          strcmp(currentNamespace->Functions[i]->Name,
                 currentFunction->Name) == 0)
        {
        if (currentNamespace->Functions[i]->NumberOfParameters ==
            currentFunction->NumberOfParameters)
          {
          for (j = 0; j < currentFunction->NumberOfParameters; j++)
            {
            if (currentNamespace->Functions[i]->Parameters[j]->Type ==
                currentFunction->Parameters[j]->Type)
              {
              if (currentFunction->Parameters[j]->Type == VTK_PARSE_OBJECT &&
                  strcmp(currentNamespace->Functions[i]->Parameters[j]->Class,
                         currentFunction->Parameters[j]->Class) == 0)
                {
                break;
                }
              }
            }
          if (j == currentFunction->NumberOfParameters)
            {
            match = 1;
            break;
            }
          }
        }
      }

    if (!match)
      {
      vtkParse_AddFunctionToNamespace(currentNamespace, currentFunction);

      currentFunction = (FunctionInfo *)malloc(sizeof(FunctionInfo));
      }
    }

  vtkParse_InitFunction(currentFunction);
  startSig();
}

/* output a function that is not a method of the current class */
void output_friend_function()
{
  ClassInfo *tmpc = currentClass;
  currentClass = NULL;
  output_function();
  currentClass = tmpc;
}

void outputSetVectorMacro(const char *var, unsigned int paramType,
                          const char *typeText, int n)
{
  static const char *mnames[] = {
    NULL, NULL,
    "vtkSetVector2Macro", "vtkSetVector3Macro", "vtkSetVector4Macro",
    NULL,
    "vtkSetVector6Macro",
    NULL };
  char ntext[32];
  int i, m;
  m = (n > 7 ? 0 : n);

  sprintf(ntext, "%i", n);

  currentFunction->Macro = mnames[m];
  currentFunction->Name = vtkstrcat("Set", var);
  startSig();
  postSig("void ");
  postSig(currentFunction->Name);
  postSig("(");
  postSig(typeText);
  for (i = 1; i < n; i++)
    {
    postSig(", ");
    postSig(typeText);
    }
  postSig(");");
  for (i = 0; i < n; i++)
    {
    add_parameter(currentFunction, paramType, getTypeId(), 0);
    }
  set_return(currentFunction, VTK_PARSE_VOID, "void", 0);
  output_function();

  currentFunction->Macro = mnames[m];
  currentFunction->Name = vtkstrcat("Set", var);
  currentFunction->Signature =
    vtkstrcat7("void ", currentFunction->Name, "(", typeText,
               " a[", ntext, "]);");
  add_parameter(currentFunction, (VTK_PARSE_POINTER | paramType),
                getTypeId(), n);
  set_return(currentFunction, VTK_PARSE_VOID, "void", 0);
  output_function();
}

void outputGetVectorMacro(const char *var, unsigned int paramType,
                          const char *typeText, int n)
{
  static const char *mnames[] = {
    NULL, NULL,
    "vtkGetVector2Macro", "vtkGetVector3Macro", "vtkGetVector4Macro",
    NULL,
    "vtkGetVector6Macro",
    NULL };
  int m;
  m = (n > 7 ? 0 : n);

  currentFunction->Macro = mnames[m];
  currentFunction->Name = vtkstrcat("Get", var);
  currentFunction->Signature =
    vtkstrcat4(typeText, " *", currentFunction->Name, "();");
  set_return(currentFunction, (VTK_PARSE_POINTER | paramType), getTypeId(), n);
  output_function();
}

/* Set a flag to ignore BTX/ETX markers in the files */
void vtkParse_SetIgnoreBTX(int option)
{
  if (option)
    {
    IgnoreBTX = 1;
    }
  else
    {
    IgnoreBTX = 0;
    }
}

/* Set a flag to recurse into included files */
void vtkParse_SetRecursive(int option)
{
  if (option)
    {
    Recursive = 1;
    }
  else
    {
    Recursive = 0;
    }
}

/* Set the global variable that stores the current executable */
void vtkParse_SetCommandName(const char *name)
{
  CommandName = name;
}

/* Parse a header file and return a FileInfo struct */
FileInfo *vtkParse_ParseFile(
  const char *filename, FILE *ifile, FILE *errfile)
{
  int i, j;
  int ret;
  FileInfo *file_info;
  char *main_class;

  /* "data" is a global variable used by the parser */
  data = (FileInfo *)malloc(sizeof(FileInfo));
  vtkParse_InitFile(data);
  data->Strings = (StringCache *)malloc(sizeof(StringCache));
  vtkParse_InitStringCache(data->Strings);

  /* "preprocessor" is a global struct used by the parser */
  preprocessor = (PreprocessInfo *)malloc(sizeof(PreprocessInfo));
  vtkParsePreprocess_Init(preprocessor, filename);
  preprocessor->Strings = data->Strings;
  vtkParsePreprocess_AddStandardMacros(preprocessor, VTK_PARSE_NATIVE);

  /* add include files specified on the command line */
  for (i = 0; i < NumberOfIncludeDirectories; i++)
    {
    vtkParsePreprocess_IncludeDirectory(preprocessor, IncludeDirectories[i]);
    }

  /* add macros specified on the command line */
  for (i = 0; i < NumberOfDefinitions; i++)
    {
    const char *cp = Definitions[i];

    if (*cp == 'U')
      {
      vtkParsePreprocess_RemoveMacro(preprocessor, &cp[1]);
      }
    else if (*cp == 'D')
      {
      const char *definition = &cp[1];
      while (*definition != '=' && *definition != '\0')
        {
        definition++;
        }
      if (*definition == '=')
        {
        definition++;
        }
      else
        {
        definition = NULL;
        }
      vtkParsePreprocess_AddMacro(preprocessor, &cp[1], definition);
      }
    }

  /* should explicitly check for vtkConfigure.h, or even explicitly load it */
#ifdef VTK_USE_64BIT_IDS
  vtkParsePreprocess_AddMacro(preprocessor, "VTK_USE_64BIT_IDS", NULL);
#endif

  data->FileName = vtkstrdup(filename);

  clearComment();

  namespaceDepth = 0;
  currentNamespace = (NamespaceInfo *)malloc(sizeof(NamespaceInfo));
  vtkParse_InitNamespace(currentNamespace);
  data->Contents = currentNamespace;

  templateDepth = 0;
  currentTemplate = NULL;

  currentFunction = (FunctionInfo *)malloc(sizeof(FunctionInfo));
  vtkParse_InitFunction(currentFunction);
  startSig();

  parseDebug = 0;
  if (getenv("DEBUG") != NULL)
    {
    parseDebug = 1;
    }

  yyset_in(ifile);
  yyset_out(errfile);
  ret = yyparse();

  if (ret)
    {
    return NULL;
    }

  free(currentFunction);
  yylex_destroy();

  /* The main class name should match the file name */
  i = strlen(filename);
  j = i;
  while (i > 0)
    {
    --i;
    if (filename[i] == '.')
      {
      j = i;
      }
    if (filename[i] == '/' || filename[i] == '\\')
      {
      i++;
      break;
      }
    }
  main_class = (char *)malloc(j-i+1);
  strncpy(main_class, &filename[i], j-i);
  main_class[j-i] = '\0';

  /* special treatment of the main class in the file */
  for (i = 0; i < currentNamespace->NumberOfClasses; i++)
    {
    if (strcmp(currentNamespace->Classes[i]->Name, main_class) == 0)
      {
      data->MainClass = currentNamespace->Classes[i];
      break;
      }
    }
  free(main_class);

  vtkParsePreprocess_Free(preprocessor);
  preprocessor = NULL;
  macroName = NULL;

  file_info = data;
  data = NULL;

  return file_info;
}

/* Read a hints file and update the FileInfo */
int vtkParse_ReadHints(FileInfo *file_info, FILE *hfile, FILE *errfile)
{
  char h_cls[512];
  char h_func[512];
  unsigned int h_type, type;
  int h_value;
  FunctionInfo *func_info;
  ClassInfo *class_info;
  NamespaceInfo *contents;
  int i, j;
  int lineno = 0;
  int n;

  contents = file_info->Contents;

  /* read each hint line in succession */
  while ((n = fscanf(hfile,"%s %s %x %i", h_cls, h_func, &h_type, &h_value))
         != EOF)
    {
    lineno++;
    if (n < 4)
      {
      fprintf(errfile, "Wrapping: error parsing hints file line %i\n", lineno);
      exit(1);
      }

    /* erase "ref" and qualifiers from hint type */
    type = ((h_type & VTK_PARSE_BASE_TYPE) |
            (h_type & VTK_PARSE_POINTER_LOWMASK));

    /* find the matching class */
    for (i = 0; i < contents->NumberOfClasses; i++)
      {
      class_info = contents->Classes[i];

      if (strcmp(h_cls, class_info->Name) == 0)
        {
        /* find the matching function */
        for (j = 0; j < class_info->NumberOfFunctions; j++)
          {
          func_info = class_info->Functions[j];

          if ((strcmp(h_func, func_info->Name) == 0) &&
              func_info->ReturnValue &&
              (type == ((func_info->ReturnValue->Type & ~VTK_PARSE_REF) &
                        VTK_PARSE_UNQUALIFIED_TYPE)))
            {
            /* types that hints are accepted for */
            switch (func_info->ReturnValue->Type & VTK_PARSE_UNQUALIFIED_TYPE)
              {
              case VTK_PARSE_FLOAT_PTR:
              case VTK_PARSE_VOID_PTR:
              case VTK_PARSE_DOUBLE_PTR:
              case VTK_PARSE_ID_TYPE_PTR:
              case VTK_PARSE_LONG_LONG_PTR:
              case VTK_PARSE_UNSIGNED_LONG_LONG_PTR:
              case VTK_PARSE___INT64_PTR:
              case VTK_PARSE_UNSIGNED___INT64_PTR:
              case VTK_PARSE_INT_PTR:
              case VTK_PARSE_UNSIGNED_INT_PTR:
              case VTK_PARSE_SHORT_PTR:
              case VTK_PARSE_UNSIGNED_SHORT_PTR:
              case VTK_PARSE_LONG_PTR:
              case VTK_PARSE_UNSIGNED_LONG_PTR:
              case VTK_PARSE_SIGNED_CHAR_PTR:
              case VTK_PARSE_UNSIGNED_CHAR_PTR:
              case VTK_PARSE_CHAR_PTR:
                {
                if (func_info->ReturnValue->NumberOfDimensions == 0)
                  {
                  char text[64];
                  sprintf(text, "%i", h_value);
                  func_info->ReturnValue->Count = h_value;
                  vtkParse_AddStringToArray(
                    &func_info->ReturnValue->Dimensions,
                    &func_info->ReturnValue->NumberOfDimensions,
                    vtkParse_CacheString(
                      file_info->Strings, text, strlen(text)));
#ifndef VTK_PARSE_LEGACY_REMOVE
                  func_info->HaveHint = 1;
                  func_info->HintSize = h_value;
#endif
                  }
                break;
                }
              default:
                {
                fprintf(errfile,
                        "Wrapping: unhandled hint type %#x\n", h_type);
                }
              }
            }
          }
        }
      }
    }

  return 1;
}

/* Free the FileInfo struct returned by vtkParse_ParseFile() */
void vtkParse_Free(FileInfo *file_info)
{
  vtkParse_FreeFile(file_info);
  vtkParse_FreeStringCache(file_info->Strings);
  free(file_info->Strings);
  free(file_info);
}

/** Define a preprocessor macro. Function macros are not supported.  */
void vtkParse_DefineMacro(const char *name, const char *definition)
{
  size_t n = vtkParse_SkipId(name);
  size_t l;
  char *cp;

  if (definition == NULL)
    {
    definition = "";
    }

  l = n + strlen(definition) + 3;
  cp = (char *)malloc(l);
  cp[0] = 'D';
  strncpy(&cp[1], name, n);
  cp[n+1] = '\0';
  if (definition[0] != '\0')
    {
    cp[n+1] = '=';
    strcpy(&cp[n+2], definition);
    }
  cp[l] = '\0';

  vtkParse_AddStringToArray(&Definitions, &NumberOfDefinitions, cp);
}

/** Undefine a preprocessor macro.  */
void vtkParse_UndefineMacro(const char *name)
{
  size_t n = vtkParse_SkipId(name);
  char *cp;

  cp = (char *)malloc(n+2);
  cp[0] = 'U';
  strncpy(&cp[1], name, n);
  cp[n+1] = '\0';

  vtkParse_AddStringToArray(&Definitions, &NumberOfDefinitions, cp);
}

/** Add an include directory, for use with the "-I" option.  */
void vtkParse_IncludeDirectory(const char *dirname)
{
  size_t n = strlen(dirname);
  char *cp;
  int i;

  for (i = 0; i < NumberOfIncludeDirectories; i++)
    {
    if (strncmp(IncludeDirectories[i], dirname, n) == 0 &&
        IncludeDirectories[i][n] == '\0')
      {
      return;
      }
    }

  cp = (char *)malloc(n+1);
  strcpy(cp, dirname);

  vtkParse_AddStringToArray(
    &IncludeDirectories, &NumberOfIncludeDirectories, cp);
}

/** Return the full path to a header file.  */
const char *vtkParse_FindIncludeFile(const char *filename)
{
  static StringCache cache = {0, 0, 0, 0};
  static PreprocessInfo info = {0, 0, 0, 0, 0, 0, &cache, 0, 0, 0};
  int val;
  int i;

  /* add include files specified on the command line */
  for (i = 0; i < NumberOfIncludeDirectories; i++)
    {
    vtkParsePreprocess_IncludeDirectory(&info, IncludeDirectories[i]);
    }

  return vtkParsePreprocess_FindIncludeFile(&info, filename, 0, &val);
}
