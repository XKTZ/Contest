N, M = [int(x) for x in input().split()]
seats = sorted([int(input()) for _ in range(N)])

def suc(a):
    std = 1
    dis = 0
    for i in range(1, N):
        dis += seats[i] - seats[i-1]
        if (dis >= a):
            std += 1
            dis = 0
        if (std >= M):
            return True
    return False

def cal():
    lowest = 0
    heightest = max(seats) - min(seats) + 1
    while heightest != lowest + 1:
        mid = (lowest + heightest) // 2
        if (suc(mid)):
            lowest = mid
        else:
            heightest = mid
    print(lowest)
cal()