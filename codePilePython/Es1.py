#data una qualunque stringa controllare se le parentesi sono giuste o sbagliate

def push_ (stack, element):
    stack.append(element)

#wrapper per pop
def pop_ (stack):
    return stack.pop()

def main():
    pila=[]
    x = input("Inserisci la stringa: ")
    ok = True

    dizioPar={")":"(", "]":"[", "}":"{"}

    for p in x:
        if p=="(" or p=="[" or p=="{":
            push_(pila, p)
        if p==")" or p=="]" or p=="}":
            if pop_(pila)!=dizioPar[p] or len(pila)==0:
                ok = True
        ok = False

    if ok:
        print("espressione corretta")
    else:
        print("espressione errata")


if __name__ == "__main__":
    main()