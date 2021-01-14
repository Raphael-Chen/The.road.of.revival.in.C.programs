// 7.10 Exercises
// At the end of Section 7.10, we showed how a function can't return a pointer 
// to an automatic variable. Is the following code correct?

int f1(int val)
{
    int num = 0;
    int *ptr = &num;

    if (val == 0)
    {
        int val;

        val = 5;
        ptr = &val;
    }
    
    return (*ptr + 1);
}
