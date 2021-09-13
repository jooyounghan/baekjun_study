def preorder(v_in):
    global trees
    print(chr(v_in + 64), end="")
    if trees[v_in][0] > 0:
        preorder(trees[v_in][0])
    if trees[v_in][1] > 0:
        preorder(trees[v_in][1])

def inorder(v_in):
    global trees
    if trees[v_in][0] > 0:
        inorder(trees[v_in][0])
    print(chr(v_in + 64), end="")
    if trees[v_in][1] > 0:
        inorder(trees[v_in][1])

def postorder(v_in):
    global trees
    if trees[v_in][0] > 0:
        postorder(trees[v_in][0])
    if trees[v_in][1] > 0:
        postorder(trees[v_in][1])
    print(chr(v_in + 64), end="")


N = int(input())
trees = [[] for _ in range(N + 1)]
for i in range(N):
    parent, child1, child2 = map(lambda x : ord(x) - 64, input().split())
    trees[parent].extend([child1, child2])
preorder(1)
print()
inorder(1)
print()
postorder(1)
print()