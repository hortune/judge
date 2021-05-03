def int_to_char(num): 
    charset = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!~@#$%^&*()_-+/,;|{}[] ".=0123456789' 
    ans = [] 
    while num: 
        ans.append(charset[num % len(charset)]) 
        num //= len(charset) 
    return ''.join(ans)

nums =  eval(open('res.py').read())
pre = 0
with open('super_comp', 'w') as fd:
    ans = []
    for num in nums:
        ans.append(int_to_char(num - pre))
        pre = num
    print('|'.join(ans), file=fd)
