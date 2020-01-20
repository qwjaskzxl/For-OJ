l = [1,2,3]
def perm(l, k, m):
    if(k == m):
        print(l)
    else:
        for i in range(k,m):
            print(k,i)
            t = l[i]
            l[i] = l[k]
            l[k] = t
            perm(l,k+1,m)
            t = l[i]
            l[i] = l[k]
            l[k] = t
perm(l,0,3)