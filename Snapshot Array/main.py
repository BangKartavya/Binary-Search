class SnapshotArray:

    def __init__(self, length: int):
        self.v = [{} for i in range(length)]
        self.snapID = 0
        

    def set(self, index: int, val: int) -> None:
        self.v[index][self.snapID] = val        

    def snap(self) -> int:
        self.snapID+=1
        return self.snapID-1

    def get(self, index: int, snap_id: int) -> int:
        while(snap_id >= 0 and self.v[index].get(snap_id) == None):
            snap_id -= 1
        
        if(snap_id < 0):
            return 0
        
        return self.v[index][snap_id]


# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)