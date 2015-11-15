#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int64_t BitBinSearch (uint64_t DWord)
{
    uint64_t Count = 0;
    uint64_t Start, Mid, End, Filter;
    
    if (DWord == 0)
        return -1;

    Start = 0;
    End = 63;
#if 0
    for (; Start < End;)
    {
        Count++;

        Mid = (Start + End) / 2;
        Filter = (1ULL << (Mid + 1)) - 1ULL;
        
        if (DWord & Filter)
        {
            End = Mid;
        }
        else
        {
            Start = Mid + 1;
        }
        //printf("Start: %d, End: %d, Mid: %d\n", Start, End, Mid);
    }
#else
    for (; Start < End;)
    {
        Count++;
        Mid = (Start + End) / 2;
        Filter = 1ULL << Mid;
        
        if (Filter == DWord)
        {
            Start = Mid;
            break;
        }
        else if (Filter > DWord)
        {
            End = Mid - 1;
        }
        else
        {
            Start = Mid + 1;
        }
    }
#endif
    printf("Count: %d, ", Count);
    return Start;
}

int main (int argc, char * argv[])
{
    int64_t Pos;
    uint64_t i; 
    
    for(i = 0; i < 64; i++)
    {
        //Pos = BitBinSearch(1 << atoi(argv[1]));
        Pos = BitBinSearch(1ULL << i);
        printf("%llX->%llX\n", 1ULL << i, 1ULL << Pos);
    }
    return 0;
}