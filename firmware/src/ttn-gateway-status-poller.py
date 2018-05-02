import time
import requests
from table_logger import TableLogger
ips = ["192.168.2.32", "192.168.2.81", "192.168.2.31"]


with open('log-ttn-gateway-{}.csv'.format(time.strftime("%Y%m%d-%H%M%S")), 'w') as csvfile:
    tbl = TableLogger(file=csvfile, csv=True, timestamp=True, columns='ip-address,bootloader,firmware,uptime,uplinks,downlinks')

    while True:
        for ip in ips:
            try:
                r = requests.get('http://{}/status.cgi'.format(ip))
                j = r.json()
                tbl(ip, j["blversion"], j["fwversion"], j["uptime"], j["pup"], j["pdown"])
            except:
                tbl(ip, "NA", "NA", "NA", "NA", "NA")
        time.sleep(600)
            