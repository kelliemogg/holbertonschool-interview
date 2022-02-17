class Sol:
    def island_perimeter(self,lol):
        res=0
        lol.append([0]*len(lol[0]))
        for i in range(len(lol)):
            lol[i].append(0)
        for i in range(len(lol)):
            for j in range(len(lol[0])):
                if lol[i][j]==1:
                    res+=4
                    if i+1 and lol[i+1][j]==1:
                        res-=2
                    if lol[i][j+1]==1:
                        res-=2
        return res

if __name__ == '__main__':
    p1=Sol()
    print(p1.island_perimeter([[0,1,0,0],
                               [1,1,1,0],
                               [0,1,0,0],
                               [1,1,0,0]]))
                               