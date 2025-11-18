bool isOneBitCharacter(int* bits, int bitsSize) {
    if (bitsSize == 1) return true;
    if (bits[bitsSize - 1] == 1) return false;
    if (bits[bitsSize - 1] == 0 && bits[bitsSize - 2] == 0) return true;
    for (int i = 0; i < bitsSize; i++)
    {
        //printf("%d \n", i);
        if (bits[i] == 1)
        {
            if (i == bitsSize - 2) return false;
            i++;
        }
        //printf("%d \n", i);
    }
    return true;

}
