from base64 import encode
from bs4 import BeautifulSoup
import requests

import os
import shutil
import emoji

# File with cookie in cookie.py (gitignored)
from cookie import *

# import requests


headers = {
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
    'Accept-Language': 'en-GB;q=0.7',
    'Cache-Control': 'max-age=0',
    'Connection': 'keep-alive',
    'Referer': 'https://cses.fi/',
    'Sec-Fetch-Dest': 'document',
    'Sec-Fetch-Mode': 'navigate',
    'Sec-Fetch-Site': 'same-origin',
    'Sec-Fetch-User': '?1',
    'Sec-GPC': '1',
    'Upgrade-Insecure-Requests': '1',
    'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.5060.134 Safari/537.36',
}

r = requests.get('https://cses.fi/problemset/', cookies=cookies, headers=headers)


# site = "https://cses.fi/problemset"

# r = requests.get(site)
soup = BeautifulSoup(r.text,"lxml")

probs = soup.find_all('li',class_ = 'task')

f = open("README.md", "w", encoding="utf-16")

initial = '''# CSES

My attempt at the CSES problem set.

'''

table_text  = '''
| Question &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;        | Status      |
|:-------------------------|:----:|
'''

hs = []

f.write(initial)

tcount = len(probs)
dcount = len(soup.find_all('span',class_ = 'task-score icon full'))
ndcount = len(soup.find_all('span',class_ = 'task-score icon zero'))

f.write(f"Completed: {dcount}/{tcount} \n")
f.write(f"Attempted: {dcount + ndcount}/{tcount} \n")

for prob in probs:
    a = prob.find('a',href = True)['href']
    p = requests.get("https://cses.fi" + a, cookies=cookies, headers=headers)
    ps = BeautifulSoup(p.text,"lxml")
    typ = ps.find('div',class_ = 'nav').find('h4').text
    qname = ps.find('div',class_ = 'title-block').find('h1').text
    status = ps.find('div',class_ = 'nav sidebar').find('a',class_ = 'current').find('span')['class']
    # print('/' + typ + '/' + ttl)
    print(qname)
    
    if not typ in hs:
        hs.append(typ)
        f.write(f"## {typ}")
        f.write(table_text)
        
    
    st = ":green_circle:" if status[-1] == 'full' else ":white_circle:" if status[-1] == 'icon' else ":red_circle:"
    
    f.write(f"|{qname}|{emoji.emojize(st)}|\n")
    
    # typ = ps.find('div',class_ = 'nav').find('h4').text
    
    # ex = ps.find_all('code')
    
    
    # directory = os.path.abspath(os.getcwd()) + '/' + typ + '/' + ttl
    # print(directory)
    # if not os.path.exists(directory):
    #     os.makedirs(directory)
    
    # shutil.copyfile(os.path.abspath(os.getcwd()) + '/code.cpp', directory + '/code.cpp')
    # with open(directory + '/input.txt', 'w') as f:
    #     f.write(ex[0].text)
    # with open(directory + '/correct_out.txt', 'w') as f:
    #     f.write(ex[1].text)
    # with open(directory + '/output.txt', 'w') as f:
    #     pass
    
    # print('/' + typ + '/' + ttl)
    # print(ex)
    
    # break
    # print(a)
# for a in soup.find_all('a', href=True):
#     print "Found the URL:", a['href']

# print(probs[0])