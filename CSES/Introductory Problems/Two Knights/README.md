We know that the total number of cells in n*n grid will be n^2. So, the total number of ways to select two distinct positions to place two identical knights will be 

        (n^2)C2 = (n^2*(n^2-1))/2

Now, we know that two knights will eliminate each other if they lie in the opposite locations of a 2*3 or 3*2 matrix. And each matrix has 2 pair of equivalent solutions described as,


        1   0   0       0   0   1
        0   0   1       1   0   0

        and

        1   0       0   1
        0   0       0   0
        0   1       1   0
    
    So, we need to calculate the total number of 2*3 and 3*2 matrices that can be created in n*n matrix.

        Number of 2*3 matrices = (n-1)*(n-2)

        Number of 3*2 matrices = (n-2)*(n-1)

    So, the total number of possibilities is 2 * 2*(n-1)*(n-2)

    Thus, the required value is:

        (n^2*(n^2-1))/2 - 4(n-1)(n-2)
