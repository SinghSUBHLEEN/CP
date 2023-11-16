This is a purely observation based and mathematical question.

The given grid looks more or less like,

        
            1   2   9   10  25  26
            4   3   8   11  24  27
            5   6   7   12  23  28
            16  15  14  13  22  29
            17  18  19  20  21  30
            36  35  34  33  32  31

    We can see that we can transform this matrix to a sequence of strips that contians the last elements as,

            1
            2   3   4
            5   6   7   8   9
            10  11  12  13  14  15  16
            17  18  19  20  21  22  23  24  25

    So, the point (x, y) will always lay on the strip with square of n = max(x, y).

    Thus, the value of the point will always be between the values [n^2, n^2-(2n-2)].

    If the value of n is x, then the perfect square lay row wise if the row number (x) is even else it will lay column wise and we can do the math to find the required value using the coordinate system.

    if x>=y,

        then if x is even, then look from row and then formulate
        else look from column and then formulate
    
    else

        if x is odd, then look from column and then formulate
        else look from row and then formulate