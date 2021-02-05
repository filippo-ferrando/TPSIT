#wrapper per push
def push_ (stack, element):
    stack.append(element)

#wrapper per pop
def pop_(stack):
    return stack.pop()


def main():
    pila = ["a", "b", "c", "d"] #la pila va con le [] -> se metti le {} lo prende come insieme
    push_(pila,"z")
    print(pila)

    x = pop_(pila)
    print(x)
    print(pila)

if __name__ == "__main__":
    main()