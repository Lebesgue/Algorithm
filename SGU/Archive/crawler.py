import urllib.request
import os

lk = 'http://acm.sgu.ru/problem.php?contest=0&problem='

for i in range (100, 542):
	url = lk  + str (i);
	filename = str(i) + '.html';
	urllib.request.urlretrieve (url, filename);



	
