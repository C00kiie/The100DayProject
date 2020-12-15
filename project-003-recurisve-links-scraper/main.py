#!/usr/bin/env python3

import requests
import re



headers = {
    #"User-Agent": "Mozilla/5.0 AppleWebKit/537.36 (KHTML, like Gecko; compatible; Googlebot/2.1; +http://www.google.com/bot.html) Chrome/W.X.Y.Z‡ Safari/537.36"
    # I am a google bot, bepop
}

main_parsed_links = []


def fetch_content(url):
    req = requests.get(url,headers=headers)
    if req.status_code == 200:
        return req.text
    else:
        return ""
def fetch_recursively(url,depth=1,verbose=False):
    if depth < 0:
        return None
    links = []
    try:
        if verbose:
            print("requesting: {}".format(url))
        req = requests.get(url=url, headers=headers, timeout=10)
        req.encoding = "UTF-8"
        links = get_links(req.text) # first iteration links
    except Exception:# Happens due to malformed urls and dead websites that can be accessed,
        pass          # for a small script, i'll just ignore em
    for i in links:
        if i not in main_parsed_links:
            if verbose:
                print("{} has been added".format(i))
            main_parsed_links.append(i)
            fetch_recursively(i, depth-1)
        else:
            pass
def get_links(content):
    # regex for urls in text
    regex = r"(?i)\b((?:https?://|www\d{0,3}[.]|[a-z0-9.\-]+[.][a-z]{2,4}/)(?:[^\s()<>]+|\(([^\s()<>]+|(\([^\s()<>]+\)))*\))+(?:\(([^\s()<>]+|(\([^\s()<>]+\)))*\)|[^\s`!()\[\]{};:'\".,<>?«»“”‘’]))"
    matches = re.findall(regex, content)
    _matches_group_0 = []
    for i in matches:
        if "http://" in i[0]:
            _matches_group_0.append(i[0])
    return _matches_group_0

if __name__ == '__main__':
    import argparse
    parser = argparse.ArgumentParser(description='Small tool to recursively find links')
    parser.add_argument('URL', metavar='U', type=str,
                        help='Initial url to feed off')
    parser.add_argument('--depth', type=int, default=1,
                        help='max depth')
    parser.add_argument("-v", "--verbose", help="modify output verbosity",
                        action="store_true")
    args = parser.parse_args()

    fetch_recursively(url=args.URL,depth=args.depth,verbose=args.verbose)
    for i in main_parsed_links:
        print ("[*] {}".format(i))
