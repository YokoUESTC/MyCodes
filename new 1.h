

class juxing():
    def __init__(self,list):
        self.x1=list[0]
        self.y1=list[1]
        self.x2=list[2]
        self.y2=list[3]
        self.List=[]

    def is_over_lap(self,juxing):
        if self.x1 < juxing.x2 and self.x2>juxing.x1 and self.y1<juxing.y2 and self.y2>juxing.y1:
            return True
        return False

    def savetolist(self,juxing):
        if self.is_over_lap(juxing):
            self.List.append(juxing)

def ans(input):
    number=input[0]
    juxings = []
    for i in range(number):
        juxing_list = [input[x+1][i] for x in range(4)]
        j = juxing(juxing_list)
        if len(juxings) ==0:
            juxings.append(j)
            continue
        for x in juxings:
            x.savetolist(j)
        juxings.append(j)
    all_list=[]
    for x in juxings:
        tmpList=x.List
        all_list.extend(tmpList)
    set01=set(all_list)
    max_times=0
    for item in set01:
        count = all_list.count(item)
        max_times = max(count,max_times)
    return max_times+1

if __name__ == '__main__':
    params = [2,[0,90],[0,90],[100,200],[100,200]]
    print ans(params)