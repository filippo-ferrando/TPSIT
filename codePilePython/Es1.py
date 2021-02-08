#data una qualunque stringa controllare se le parentesi sono giuste o sbagliate

def controlloStr(stringa):
    pila=[]
    aperte = ["(","[","{"]
    chiuse = [")","]","}"]

    assegnazioni = {"(":")", "[":"]", "{":"}", ")":"(", "]":"[", "}":"{"}
    
    for p in stringa:
        if p in aperte:
            pila.append(p)
        elif p in chiuse:
            if len(pila) != 0:
                if p != assegnazioni[pila.pop()] :
                    return False
            else:
                return False

    if len(pila) > 0:
        return False


    return True  

def main():
    x = input("Inserisci la stringa: ")
    
    ok = controlloStr(x)

    if ok == True:
        print("Stringa corretta")
    else:
        print("Stringa Errata")



if __name__ == "__main__":
    main()