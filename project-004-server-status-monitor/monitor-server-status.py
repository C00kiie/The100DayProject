#!/usr/bin/env python3

import requests
import colorama
import re
import time
import sys

# suppress SSL warnings if any
requests.packages.urllib3.disable_warnings()

'''
regex section
'''
regex_methods = "(GET|POST|DELETE|PUT|HEAD|PATCH)" # match on these methods
# group 1 => client
# group 2 => vhost/dst IP
# group 3 => request details 
regex_data = "<\/td><td>(.+?)<\/td><td nowrap>(.+?)<\/td><td nowrap>(.+?)<\/td>"

# colors
class bcolors:
    HEADER = '\033[95m '
    OKBLUE = '\033[94m '
    OKCYAN = '\033[96m '
    OKGREEN = '\033[92m '
    WARNING = '\033[93m '
    FAIL = '\033[91m '
    ENDC = '\033[0m '
    BOLD = '\033[1m '
    UNDERLINE = '\033[4m '


def parse_html(lines):
    data = []
    for line in lines:
        if len(re.findall(regex_methods,line)) > 0 and '/server_status' not in line :
            results = re.findall(regex_data,line)[0]
            client = results[0]
            remote_addr = results[1]
            details = results[2]
            request = [client,remote_addr,details]
            data.append(request)
        else:
            pass
    return data

def get_server_status(url):
    req = requests.get(url, verify=False)
    if req.status_code == 200:
        return req.text.split('\n')# split one lines
    else:
        return ''
def periodic_fetch(url,refersh_time=15,output=None):
    if url == '':
        print('[*] invalid url')
        exit(-1)
    if refersh_time <= 0:
        print('[*] invalid refersh period')
        exit(-1)

    while True:
        content = get_server_status(url)
        matches = parse_html(content)
        for i in  matches:
            output_format = bcolors.BOLD + "[*]" + bcolors.OKBLUE + i[0] + bcolors.OKGREEN + i[1] + bcolors.OKCYAN + i[2]
            if output != None:
                output.write(output_format+'\n')
            print(output_format)
        time.sleep(refersh_time)

if __name__ == '__main__':
    import argparse
    parser = argparse.ArgumentParser(description='Small tool to recursively find links')
    parser.add_argument('url', type=str,
                        help='Initial url to feed off')
    parser.add_argument('--interval', type=int, default=15,
                        help='interval between each refersh')
    parser.add_argument("--output", type=argparse.FileType('a'), dest='output',
                        help='Log output to a file',default=None)

    args = parser.parse_args()
    url = args.url
    output = args.output
    interval = args.interval
    periodic_fetch(url, interval, output)
