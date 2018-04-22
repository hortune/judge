from functools import cmp_to_key
n, m = list(map(int,input().split()))
nums = list(map(int,input().split()))
nums.sort(key=cmp_to_key(lambda x, y: -1 if x < y else 1))

def recursive(bucket,nums,n,residual):
    if residual == 0:
        print(*bucket)
        return True
    elif len(nums) == n:
        return False
    elif nums[n] <= residual:
        # put it in
        bucket.append(nums[n])
        k = recursive(bucket,nums,n+1,residual - nums[n])
        bucket.pop()
        
        return recursive(bucket,nums,n+1,residual) or k

if not recursive([],nums,0,m):
    print(-1)
