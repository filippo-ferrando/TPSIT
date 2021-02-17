#wrapper per dequeue
def dequeue(queue):
    return queue.pop(0)

#wrapper per enqueue
def enqueue(queue, element):
    queue.append(element)


def main():
    coda = ["a", "b", "c", "d"] #la coda va con le [] -> se metti le {} lo prende come insieme
    enqueue(coda, "y")
    print(coda)

    x = dequeue(coda)
    print(x)
    print(coda)

if __name__ == "__main__":
    main()