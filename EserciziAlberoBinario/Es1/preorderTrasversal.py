class Node:
    def __init__(self,data):
        self.left = None
        self.right = None
        self.data = data

    def insert(self, data):
        if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)
            elif data > self.data:
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.right.insert(data)
        else:
            self.data = data

            

    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print( self.data),
        if self.right:
            self.right.PrintTree()

    # attraversamento left->root->right
    def preorderTrasversal(self, root):
        res = []
        if root:
            res.append(root.data)
            res = res + self.preorderTrasversal(root.left)
            res = res + self.preorderTrasversal(root.right)
        return res

root = Node(10)
root.insert(23)
root.insert(2)
root.insert(8)
root.insert(21)
root.insert(1)
root.insert(77)
root.insert(100)


root.PrintTree()
print("\n")
print(root.preorderTrasversal(root))