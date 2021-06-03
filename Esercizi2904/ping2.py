import threading
import ipaddress
import time
import subprocess
import os
from queue import Queue
from colorama import init

init()

print_lock = threading.Lock()
net_addr = input("Accadere alla rete es(192.168.1.0/24): ")
startTime = time.time()
ip_net = ipaddress.ip_network(net_addr)
all_hosts = list(ip_net.hosts())

try:
    info=subprocess.STARTUPINFO()
    info.dwFlags |= subprocess.STARTF_USESHOWWINDOW
    info.wShowWindow = subprocess.SW_HIDE
except Exception:
    pass

print('indirizzo di rete che vuoi pingare:',net_addr)

def pingsweep(ip):
    if os.name == "nt":
        output = subprocess.Popen(["ping","-n","1","-w","150",str(all_hosts[ip])],stdout = subprocess.PIPE, startupinfo=info).communicate()[0]
    with print_lock:
        print('\033[93m',end='')
    if "Risposta" in output.decode("utf-8"):
        print(str(all_hosts[ip]),"\033[90m"+"is online")
    elif "host di destinazione non raggiungibile" in output.decode('utf-8'):
        pass
    elif "tempo per la richiesta scaduto" in output.decode('utf-8'):
        pass
    else:
        print("UNKNOW",end='')


def threader():
    while True:
        worker = q.get()
        pingsweep(worker)
        q.task_done()

q=Queue()

for x in range(100):
    t = threading.Thread(target=threader)
    t.daemon = True
    t.start()

for worker in range(len(all_hosts)):
    q.put(worker)

q.join()
runtime = float("%0.2f"% (time.time()-startTime))
print("Runtime: ",runtime,"seconds")