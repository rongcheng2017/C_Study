int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

struct SIMPLE
{
    int a;
    char b;
    float c;
} x;

struct COMPLEX
{
    float f;
    int a[20];
    long *lp;
    struct SIMPLE s;
    struct SIMPLE *sp;
    struct SIMPLE sa[10];
};

union {
    float f;
    int i;
} fi;
