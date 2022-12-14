from bs4 import BeautifulSoup
import requests

import os
import shutil



site = "https://cses.fi/problemset"

r = requests.get(site)
soup = BeautifulSoup(r.text,"lxml")

probs = soup.find_all('li',class_ = 'task')


for prob in probs:
    a = prob.find('a',href = True)['href']
    p = requests.get("https://cses.fi" + a)
    ps = BeautifulSoup(p.text,"lxml")
    
    ttl = ps.find('div',class_ = 'title-block').find('h1').text
    
    typ = ps.find('div',class_ = 'nav').find('h4').text
    
    ex = ps.find_all('code')
    
    
    directory = os.path.abspath(os.getcwd()) + '/' + typ + '/' + ttl
    print(directory)
    if not os.path.exists(directory):
        os.makedirs(directory)
    
    shutil.copyfile(os.path.abspath(os.getcwd()) + '/code.cpp', directory + '/code.cpp')
    with open(directory + '/input.txt', 'w') as f:
        f.write(ex[0].text)
    with open(directory + '/correct_out.txt', 'w') as f:
        f.write(ex[1].text)
    with open(directory + '/output.txt', 'w') as f:
        pass
    
    print('/' + typ + '/' + ttl)
    # print(ex)
    
    # break
    # print(a)
# for a in soup.find_all('a', href=True):
#     print "Found the URL:", a['href']

# print(probs[0])