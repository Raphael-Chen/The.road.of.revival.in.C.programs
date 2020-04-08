
# 6.4.1 Keywords

这些是C语言中绝对不能出现拼写错误的关键字，编译器就是靠着这些关键字来做语法分析，编码时请务必不要发生拼写错误。


Syntax:

auto
break
case
char
const
continue
default
do
double
else
enum
extern
float
for
goto

if
inline
int
long
register
restrict
return
short
signed
sizeof
static
struct
switch
typedef
union

unsigned
void
volatile
while
_Alignas
_Alignof
_Atomic
_Bool
_Complex
_Generic
_Imaginary
_Noreturn
_Static_assert
_Thread_local


Semantics
The above tokens (case sensitive) are reserved (in translation phases 7 and 8) for use as keywords, and shall not be used otherwise. The keyword _Imaginary is reserved for specifying imaginary types.



分类

| 数据类型 | 修饰符   |      |      |      |      |
| -------- | -------- | ---- | ---- | ---- | ---- |
| _Bool    | unsigned |      |      |      |      |
| char     | signed   |      |      |      |      |
|     | auto     |      |      |      |      |
| int      | static   |      |      |      |      |
| float    | extern   |      |      |      |      |
| double   | const |      |      |      |      |
| enum    | long |      |      |      |      |
| union    | short |      |      |      |      |
| struct   |          |      |      |      |      |
| _Complex |          |      |      |      |      |



> 如遇到没有见过的数据类型，基本都是由typedef定义的别名

