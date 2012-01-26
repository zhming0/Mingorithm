import os
import shutil
acmdir = '/Users/M/Documents/Xcode Projects/ACM'
targetdir = '/Users/M/Desktop/Algorithm/ACM'
dirlist = os.listdir(acmdir)
for i in dirlist:
	if i[0]=='.' or i == 'test' or os.path.isdir(acmdir + '/'+ i)!=True:
		continue
	if i[0:8] == 'BJTU-ACM':
		targetname = 'BOJ'+i[8:]
	elif i[0:7] == 'BJT-ACM':
		targetname = 'BOJ' + i[7:];
	else:
		targetname = i;
	tmppath = acmdir+'/'+i
	tmplist = os.listdir(tmppath)
	if tmplist.count('main.cpp') == 1:
		shutil.copy(tmppath+'/main.cpp', targetdir+'/'+targetname+'.cpp')
	elif tmplist.count('main.c')==1:
		shutil.copy(tmppath+'/main.c', targetdir+'/'+targetname+'.cpp')
	elif tmplist.count(i)==1:
		shutil.copy(tmppath+'/'+i+'/main.cpp', targetdir+'/'+targetname+'.cpp')