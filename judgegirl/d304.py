def dfs(cur,num,tmp,path,o_buf):
    """
    cur : current star num
    num : todo
    tmp : buffer star
    """
    parameters = (cur,num,tmp,path,1)
    
    stack = [parameters]
    min_len_num = 1000000
    while len(stack) != 0:
        (cur,num,tmp,path,len_num) = stack[-1]
        stack.pop()
        if len_num > min_len_num or num < 0:
            path.pop()
            continue
        
        if num == 0:
            if len_num < min_len_num:
                o_buf.clear()
                o_buf.append(path[:])
                min_len_num = len_num
            elif len_num == min_len_num:
                o_buf.append(path[:])
            path.pop()
            continue
        
        if cur != tmp: 
            path.append("C + V")
            stack.append((2*cur,num-cur,cur,path[:],len_num+2))
            path.pop()
        
        path.append("V")
        stack.append((cur+tmp,num-tmp,tmp,path,len_num + 1))
        
try:
    while True:
        num = int(input())
        output = [[]]
        dfs(1,num-1,1,["C"],output)
        print("min :",(len(" + ".join(output[0]))-1)//4 + 1)
        print("way :",len(output))
        for qq in output:
            print("Ctrl"," + ".join(qq))
except EOFError:
    pass
