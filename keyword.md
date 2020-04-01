
# 6.4.1 Keywords

这是绝对不能出现拼写错误的关键字，编译器就是靠着这些关键字来做语法分析，编码时请务必不要发生拼写错误。


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




