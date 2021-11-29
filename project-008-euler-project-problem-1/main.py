#Problem 1. If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
# The sum of these multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000 . Oct 5, 2001

def get_multiples(n, range_):
    results = [ None for i in range(0,range_+1)] # init array with NULL values
    for i in range(0,range_+1,n):
            results[i] = i
    return results


multi_5 = get_multiples(5,1000)
multi_3 = get_multiples(3,1000)
final_res = [None for i in range(0,1000+1)] # init array with NULL values
c = 0


for i in range(0, 1000+1):
    if multi_5[i] == i or multi_3[i] == i:
        final_res[c] = i
    c+=1

print(final_res)