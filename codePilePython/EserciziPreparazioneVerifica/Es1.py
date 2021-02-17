#wrapper per dequeue
def dequeue(queue):
    return queue.pop(0)

#wrapper per enqueue
def enqueue(queue, element):
    queue.append(element)

def main():
    val = 0
    coda = []

    while val != -1:
        val = input("Inserisci valore: ")
        enqueue(coda, val)            

    print("\n")

    while coda[-1] != None:
        print(dequeue(coda))
            
        