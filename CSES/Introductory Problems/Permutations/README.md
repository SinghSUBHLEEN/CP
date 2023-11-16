Here, we just need to observe that we can not keep the elements in sorted order because then the difference b/w elements would be 1.

Now, to get around this, we can arrange elements that has a difference of 2 together.

For n = 7, we can keep the elements like 

        odd:    1, 3, 5, 7
        even:   2, 4, 6

        So, we can just go ahead and keep them in the required order as 

        arr:    1, 3, 5, 7, 2, 4, 6

For n = 4, we can not go ahead with the above arrangement, because

        odd:    1, 3
        even:   2, 4

        arr:    1,3,2,4

    This conflicts the required condition. So, the main goal of the above placement should be to keep the greatest element in the center of the array.

    This can be aceivied, if for even 'n', we keep the even set of numbers first and then odd.

    And do the other way around for odd.